'''
Write python program to store 10th class percentage of students in array.
Write function for sorting array of floating point numbers in ascending order
using radix sort and display top five scores
'''

print("Radix sort Implementation : ")
num2=[]
d1=0
x=0
def countingsort(num,k):
    n=len(num)
    res=[0]*10
    c=[0]*10
    for i in range(0,n):
        temp=num[i]//k
        c[temp%10]+=1
    for i in range(1,10):
        c[i]=c[i]+c[i-1]
    i=n-1
    while i>=0:
        temp=num[i]//k
        res[c[temp%10]-1]=num[i]
        c[temp%10]-=1
        i=i-1
    for i in range(0,n):
        num[i]=res[i]
    print(num)
    print(k)
    d1= len(num)
    for i in range(d1):
        x=num[i]
        x=x/10
        print("x:=",x)
        num2[i]=format(x, ".1f")
    print(num2)
    
def radixsort(num):
    print(num)
    maximum=max(num)
    print(maximum)
    n=1

    while maximum//n > 0:
        countingsort(num,n)
        n=n*10
num=[]
num1=[]
M=int(input("Enter the number of students : "))
for i in range(M):
    num2.append(0)
    per=float(input("Enter the percentage marks : "))
    num.append(per)
l1=len(num)
num1=[0]*l1
for i in range(0,l1):
    num1[i]=int(num[i]*10)
#Main
print(num1)
print("Before sorting : ")
print(num)
print("After sorting : ")
radixsort(num1)
num3=num2[::-1]
print("Top 5 scores are : ")
for i in range(0,5):
	print(num3[i])
