'''
Name:Nada Nasser Al-Said Al-Azab
ID: 20170369   G.14
Game#9_Python
Ai_version
'''
import random
x=[]
size=random.randint(11,16)
for i in range(1,size+1):
    x.append(i)
print(x)
while True:
#player1:    
    while True:
        z=int(input(" How many tokens you want? "))
        if(z==1):
            num=int(input("Write the number : "))
            if(num in x):
                in_num1 = x.index(num)
                x[in_num1]="_"
                break
            else:
                print("the token not found")

        if(z==2):
            num1=int(input("Write the first number : "))
            num2=int(input("Write the secound number : "))
            if(num1-num2==1 or num2-num1==1)and(num1 in x)and(num2 in x):
                in_num1=x.index(num1)
                in_num2=x.index(num2)
                x[in_num1]="_"
                x[in_num2]="_"
                break
            else:
                print("The tow tokens not found")
#Is Player 1 win:
    print(" ")
    #print(x)
    i=0
    nT=0
    while i<=(len(x)-1):
        if(x[i] != "_"):
            nT=nT+1
        i=i+1
    if(nT<1):
        print("You win :D ")
        break
    
#The Computer playing:
    print("Computer is playing ")
    computer=[]
    c=0
    valid_nums=0
    i=0
    for i in range(len(x)):
        if(x[i]!="_"):
            c=c+1
        if((x[i]=="_")and(c<2)):
            c=0     
        if(i==len(x)-1 and c>=2):
            while(c>0):
                computer.append(x[i])
                i=i-1
                c=c-1
            if(len(computer)%2!=0):
                mid=int((len(computer)/2)-(len(computer)%2))
                in_num1=x.index(computer[mid])
                x[in_num1-1]="_"
                break
            elif(len(computer)%2==0)and(len(computer)!=2):
                mid=int((len(computer)/2)-(len(computer)%2))
                in_num1=x.index(computer[mid])
                in_num2=x.index(computer[mid-1])
                x[in_num1]="_"
                x[in_num2]="_"
                break
            elif(len(computer)==2):
                mid=int((len(computer)/2)-(len(computer)%2))
                in_num1=x.index(computer[mid])
                x[in_num1]="_"
                break
        if( (x[i]=="_")and(c>=2)): 
            while(c>0):
                computer.append(x[i-1])
                i=i-1
                c=c-1
            if(len(computer)%2!=0):
                mid=int((len(computer)/2)-(len(computer)%2))
                in_num1=x.index(computer[mid])
                x[in_num1-1]="_"
                break
            elif(len(computer)%2==0)and(len(computer)!=2):
                mid=int((len(computer)/2)-(len(computer)%2))
                in_num1=x.index(computer[mid])
                in_num2=x.index(computer[mid-1])
                x[in_num1]="_"
                x[in_num2]="_"
                break
            elif(len(computer)==2):
                mid=int((len(computer)/2)-(len(computer)%2))
                in_num1=x.index(computer[mid])
                x[in_num1]="_"
                break
        i=i+1
        if((i)>=(len(x))):
            for com in range(len(x)):
                if(x[com]!="_"):
                    x[com]="_"
                    break
    
    print(" ")
    print(x)
#if The computer win:
    i=0
    nT=0
    while i<=(len(x)-1):
        if(x[i] != "_"):
            nT=nT+1
        i=i+1
    if(nT<1):
        print("You lost ): !!")
        break
    
