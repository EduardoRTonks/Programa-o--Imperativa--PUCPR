#PJBL 
#Alunos: Eduardo Rodrigues Araujo de OLiveira, Guilherme Velo Lopes, Ricardo Hey
#OS: Ubunto 22.04
#IDE: Virtual Studio Code 1.88
import os

#validação das entradas que o usuario faz para escolher o assento
def valida(n):
    
    #a função recebe um parametro n que é o numero assento escolhido n=48
    #conforme passado em aula
    for k in range(1, 141):
        #esse parametro é comparado com as strings correspondentes aos ints validos
        if n==str(k):
            #se for valido retorna verdadeiro validando a entrada
            return True
    #se for falso retorna falso não validando a entrada
    return False

#repetição da validação da entrada
def chack(n):
    global plateia_numerica
    os.system('clear') or None
    #chama a função valida ate que o valor seja valido
    while valida(n) == False: 
        print("\n------- Venda de Ingressos Cinema 'Ciber' ------- \n")
        print("Ocupação da sala:\n")
        imprimi(plateia_numerica)
        n=input(f"\n\nO valor {n} é inválido! Digite um número entre 1-140 que esteja vago: ")
    return n

#faz a impressão da matriz 
def imprimi(matrix):
    for j in range(0,14):
        for a in range(0,10):
            #faz a impressão dos assentos de forma formatado
            print(f"{matrix[j][a]:4}", end=" ")
        print("\n")  
#função principal de venda de ingressos
def vender_ingresso():
    #limpa a tela
    os.system('clear') or None
    #chama as variaveis globais 
    global plateia_numerica
    global plateia_ocupação
    print("\n------- Venda de Ingressos Cinema 'Ciber' ------- \n")
    print("Ocupação da sala:\n")
    
    imprimi(plateia_numerica)
    
    assento = input("\nInforme um número de um assento vago (1-140): ")
    
    assento = chack(assento)
    
    #converte o valor do assento string para int e subtrai 1 
    # para corresponder a sua posição na matriz
    
    assento= int(assento)-1
    #repetição para checar se o assento esta ocupado ou vazio 
    while (plateia_numerica[(assento)//10][(assento)%10] == " "): 
        #se o assento estiver ocupado ou seja vazio ele pede um novo valor
        # ate que seja escolhido um assento que não tenha sido vendido ou seja tenha 
        # algum valor na posição  
        print("\n------- Venda de Ingressos Cinema 'Ciber' ------- \n")
        print("Ocupação da sala:\n")
        imprimi(plateia_numerica)
        print("\n\nEste assento já está ocupado, escolha um dos que estejam aparecendo acima:")
        assento = input("\n\nInforme um número do assento vago (1-140): ")
        assento = chack(assento)
        assento = int(assento)-1
    #le a o tipo de compra
    tipo = input("Qual o tipo, <m>eia ou <i>nteira: ")
    #se a entrada for invalida ele entra em loop ate a entrada ser valida
    while (tipo != "m" and tipo != "i"):
        tipo = input("Digite apenas 'm' para meia ou 'i' para inteira!")
    #atualiza os assentos venidos e o tipo de compra
    plateia_numerica[((assento)//10)][((assento)%10)]= " "
    plateia_ocupação[((assento)//10)][((assento)%10)] =  f" {tipo}"
    print("Ingresso vendido com sucesso!")
            
def mostrar_ocupacao():
    os.system('clear') or None
    global plateia_ocupação
    #imprimi a ocpação
    print("\n------- Mostrar Ocupação Cinema 'Ciber' ------- \n")
    print("Ocupação: \n")
    imprimi(plateia_ocupação)
    
    #transforma a matriz em uma lista iterada, forma de ler os dados, para aplicar o count
    plateia_ocupação_vet = [item for sublist in plateia_ocupação for item in sublist]
    #conta as vendidas como meia e as vendidas como inteira
    total_ocupadosmeia = plateia_ocupação_vet.count(' m')
    total_ocupadosint = plateia_ocupação_vet.count(' i')
    #imprime os valores
    print(f"\nA plateia possui 140 lugares")
    print(f"\nForam vendidos: {total_ocupadosint + total_ocupadosmeia}, sendo:")
    print(f"\n  {total_ocupadosmeia} - meias\n\n  {total_ocupadosint} - inteiras")

#cria as matrizes
plateia_numerica=[]
plateia_ocupação=[]
#preenche as matrizes
for j in range(0, 14):
    linha_numerica=[]
    linha_ocupação=[]
    for a in range(0,10):
        #ocupa toda a matriz ocupação com um underline para formatação correta no print
        #ocupa toda a matriz numerica com o valor correspondente ao assento
        linha_ocupação.append(" _")
        linha_numerica.append(j*10+a+1)
    plateia_numerica.append(linha_numerica)
    plateia_ocupação.append(linha_ocupação)
    
#imprimi o menu 
while True:
    print("\n--- Cinema 'Ciber' ---")
    print("\nMenu de opções:")
    print("0 – Sair")
    print("1 – Vender ingresso")
    print("2 – Mostrar plateia")
    print("3 – Mostrar ocupação")
    opcao = input("\nEscolha uma opção: ")
#faz a ação correspondente a opção escolhida
    if opcao == '0':
        print("Saindo do programa...")
        break
    elif opcao == '1':
        vender_ingresso()
    elif opcao == '2':
        os.system('clear') or None
        print("\n--------- Mostrar Plateia Cinema 'Ciber' --------- \n")
        print("Plateia: \n")
        imprimi(plateia_numerica)
    elif opcao == '3':
        mostrar_ocupacao()
    else:
        print("Opção inválida. Tente novamente.")