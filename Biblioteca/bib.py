from math import *

def fat(n):
    f=1
    print("-----------------------------")
    print("| n   |", end='')
    # alinha a direita com espaços em branco
    s="n! |"
    print("{0:>20}".format(s))
    print("-----------------------------")

    while n>1:
        f=f*n
        print("| ", n," |")
        print("{0:>24}".format(f)," |")
        n=n-1
    print("-----------------------------")

    return f


def maior(a,b):
    if a>b:
        return a
    else:
        return b
    
def circ(r):
    return 2*pi*r,pi*r**2

def menor(a,b,c):
    if a<b and a<c:
        return a
    elif b<a and b<c:
        return b
    else:
        return c

def somatorios(n):
    s=0
    while n>0:
        s=s+(n/((2*n)-1))
        n=n-1
    return s

def fats(n):
    f=1

    while n>1:
        f=f*n
        n=n-f
    return f

def somatorioc(x,n):
    s=0
    while n>0:
        s=s+((-1)**(n-1))*(x**((2*(n-1))/fats(2*n-2)))
        n=n-1
    return s


def somares(n):

    if n<=0:
        return 0
    else:
        return n+somares(n-1)

def qp(n):
    if n<=0:
        return 0
    else:
        return 3+qp(n-1)
    
def potrec(n):

    if n<=0:
        return 0
    else:
        return pow(n,3)+potrec(n-1)
    
def text(s,n):
    if n>1:
        return s[n-1]+text(s,n-1)
    return s[0]

def impares(a,c):
    if not(c>a):
        if c%2==1:
            print(c,end=' ')
            impares(a,c+2)
        else:
            impares(a,c+1)
    else:
        return 

def pares(a):
    if a>0:
        if a%2==1:  
            pares(a-2)
            print(a,end=' ')
        else:
            pares(a-1)
    else:
        return print("a")


pares(8)
        










     
    