/*1- Ler arquivo ((arquivo aberto, lido e fechado) colocados em uma matriz alocada dinamicamente 12x10
2-salvar ao final
3-Liberar a memoria no final 
4- Se a plateia não existir, preencher as posições com "-"
5- sempre que alterar a matriz plateia, salvar no arquivo// tem que ser a ultima. 

6- todas as entradas devem ser validadas 
7- (sempre com "flush(stdin);" // ler como caractere*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define L 10
#define C 12
#define FILENAME "matriz.txt"

void Tela(){
    printf("\n------------------------------");
    printf("\n             Menu             ");
    printf("\n------------------------------");
    printf("\n0-Sair do programa\n1-Mostrar plateia\n2-Mostrar ocupacao\n3-Vender ingresso\n4-Cancelar ingresso (devolucao)");
    printf("\n------------------------------");
    printf("\nEscolha uma opcao:\t");
}
int valida(char *str){
    int len = strlen(str);

    // Verifica se a string está vazia
    if (len == 0) return 0;
    //Verifica se a string tem mais de 10 posições
    if (len>=10) return 0;
    // Verifica se o primeiro caractere é um sinal (opcional)
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
        if (len == 1) return 0; // Apenas um sinal não é válido
        start = 1;
    }

    // Verifica os demais caracteres
    for (int i = start; i < len; i++) {
        if (!isdigit(str[i])) return 0;
    }

    return 1;
}
int lerOp(){
    char input[100];
    scanf("%s", input);
    fflush(stdin); 

    if (valida(input)) {
            return atoi(input);
        } else {
            return -1;
        }
    
}

void Cria() {
     FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Erro ao criar o arquivo");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            fputc('-', file);
            if (j < C - 1) {
                fputc(' ', file); // Adiciona um espaço entre os elementos
            }
        }
        fputc('\n', file); // Adiciona uma nova linha após cada linha da matriz
    }

    fclose(file);
    }

void lerArquivo(char **mx){
     FILE *file = fopen(FILENAME, "r");
    // Se o arquivo não existir, cria o arquivo
    if (file == NULL) {
        Cria();
        file = fopen(FILENAME, "r");
        if (file == NULL) {
            perror("Erro ao abrir o arquivo");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            fscanf(file, " %c", &mx[i][j]);
        }
    }

    fclose(file);
}

void liberar(char **mx){
    for (int i = 0; i < L; i++) {
        free(mx[i]);
    }
    free(mx);
}
void Salvar(char **mx){
     FILE *file = fopen(FILENAME, "w");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            fprintf(file, "%c ", mx[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file); // Fecha o arquivo
}
void mostrarPlateia(char **mx){
    printf("\n-----------------------------------------------");
    printf("\n                   Plateia                     ");
    printf("\n-----------------------------------------------\n");
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (mx[i][j] == '-') {
                printf("%3d ", (i * 12) + (j + 1));
            } else {
                printf("    "); // Mantém o espaço para assentos ocupados
            }
        }
        printf("\n");
    }
    printf("\n-----------------------------------------------");
}

void mostrarOcupacao(char **mx){
    int m=0,in=0,v=0;
    printf("\n------------------------------");
    printf("\n           Ocupação           ");
    printf("\n------------------------------\n");
    for(int i=0;i<L;i++){
        for(int j=0;j<C;j++){
            printf("%c ",mx[i][j]);
            if (mx[i][j] == 'i') in++;
            else if (mx[i][j] == 'm') m++;
            else v++;            
        }
        printf("\n");
    }
    printf("\n------------------------------");
    printf("\nCadeiras vazias.........:%3.d\nCadeiras meia vendida...:%3.d\nCadeiras inteira vendida:%3.d",v,m,in);
    printf("\n------------------------------");

}
int outro(char c[10]){
    printf("\n%s outro ingresso (0:sim; 1:não)?\t",c);
    int o=lerOp();
    //while(!(lerOp()==1||lerOp()==0))printf("\nVALOR INVALIDO!ESCOLHA NOVAMENTE!\nVender outro ingresso (0:nao; 1:sim)?");
    while(!(o==1||o==0))printf("\nVALOR INVALIDO!ESCOLHA NOVAMENTE!\n%s outro ingresso (0:nao; 1:sim)?",c);
    return o;
}
int Vender(char **mx,int i, int j){
    char c;
    printf("\nDigite se a entrada é (m)eia ou (i)nteira:\t");
    if (scanf(" %c", &c) != 1) {
        printf("\nValor invalido!");
        return 0; // Adicionamos espaço antes de %c para ignorar espaços em branco
    }
    if (c == 'i' || c == 'I') {
        mx[i][j] = 'i'; // Use = para atribuição
        Salvar(mx);
        printf("\nPoltrona vendida: %3.d (inteira)",(i*12)+(j+1));
        return outro("Vender"); // Adicionamos o ponto e vírgula
    } else if (c == 'm' || c == 'M') {
        mx[i][j] = 'm'; // Correção para atribuir 'm'
        Salvar(mx);
        printf("\nPoltrona vendida: %3.d (meia)",(i*12)+(j+1));
        return outro("Vender"); // Adicionamos o ponto e vírgula
    }
    printf("\nValor invalido!");
    return 0;
    }

int venderIngresso(char **mx){
    fflush(stdin); 

    printf("\nDigite o numero da poltrona <1..120> (zero encerra):\t");
    int op = lerOp();

    if (op == -1) {
        printf("\nValor Invalido!\n"); // sair
        return 0;
    }else if (op==0) { // Escolheu sair
        printf("\nVoltando ao menu\n"); // sair
        return 1;
    } else if (!(op >= 1 && op <= 120)) { // Ajustando a faixa para 1 a 120
        printf("\nValor Invalido!\n"); // sair
        return 0;
    }

    op--; // Ajustar para índice base 0
    int j = op % 12;
    int i = op / 12;

    if (mx[i][j] == '-') {
        return Vender(mx, i, j);
    } else {
        printf("\nCadeira Ocupada!\n"); // sair
        return 0;
}
}

int cancelarIngresso(char **mx){

    printf("\nDigite 0 para voltar ao Menu!\nDigite um numero do assento para o cancelamento:\t");
    int op = lerOp();
    if (op == -1) {
        printf("\nValor Invalido!\n"); // sair
        return 0;
    } else if (op==0) { // Escolheu sair
        printf("\nVoltando ao menu\n"); // sair
        return 1;
    }else if (!(op >= 1 && op <= 120)) { // Ajustando a faixa para 1 a 120
        printf("\nValor Invalido!\n"); // sair
        return 0;
    }

    op--; // Ajustar para índice base 0
    int j = op % 12;
    int i = op / 12;
    if (mx[i][j] == '-') {
        printf("\nCadeira Vazia!Não houve compra para cancelar!\n"); // sair
        return 0;
        
    } else {
        if (mx[i][j] == 'm') printf("Poltrona com venda cancelada: %d (meia).",op+1);
        else printf("Poltrona com venda cancelada: %d (inteira).", op+1);
        mx[i][j] = '-';
        Salvar(mx);
        printf("\nCompra Cancelada!");
        return outro("Cancelar");
}

}


int main()
{
    int op = -1; 
    //alocando dinamicamente a matriz
    char **plateia = (char **)malloc(L * sizeof(char *));
    for (int i = 0; i < L; i++) {
        plateia[i] = (char *)malloc(C * sizeof(char));
    }

    lerArquivo(plateia);

    while (op!=0){
        Tela();
        op=lerOp();
        //valida
        switch (op){
            case 0:
                printf("Você optou for encerrar o programa, adeus :c");
                break;
            case 1: 
                mostrarPlateia(plateia);
                break;
            case 2:
                mostrarOcupacao(plateia);
                break;
            case 3:
                mostrarPlateia(plateia);
                while(venderIngresso(plateia)!=1);
                break;
            case 4:
                mostrarPlateia(plateia);
                while(cancelarIngresso(plateia)!=1);
                break;
            default:
                system("clear");
                printf("Valor inválido!\nEscolha um novo valor.\nValor deve estar entre 0 e 4.");
        }
    }
    

    liberar(plateia);

    return 0;
}


