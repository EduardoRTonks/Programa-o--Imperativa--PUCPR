a=int(input("Digite o valor de a"))
b=int(input("Digite o valor de b"))
c=int(input("Digite o valor de c"))

if a!=0:
    delt=(b**2)-4*a*c
    if delt>0:
        x1=(-b+(delt**(1/2)))/(2*a)
        x2=(-b-(delt**(1/2)))/(2*a)
        print("x1 = ", x1)
        print("x2 = ", x2)
    elif delt==0:
        x1=-b/2*a
        print("X1 = X2 = ", x1)
    else: 
        print("Não ha solução real")
else: 
    print("Não é uma equação de segundo grau")


 