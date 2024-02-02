#to display word with with longest length

print("\nTo display word with with longest length :-")
str1=input("Enter the string: ")
list1=str1.split()
m=0
word=0
print(list1)
for i in range(len(list1)):
	len(list1[i])
	if m<len(list1[i]):
	   m=len(list1[i])
	   word=i

print("Thn word with longest length : ",list1[word])

#<------------------------------------------------------------------------------------------>

#to determines the frequency of occurrence of particulart character in the string

print("\nTo determines the frequency of occurrence of particulart character in the string :-")
str1=input("Enter the string: ")
char=input("Enter character : ")

counter=0
for i in range(len(str1)):
	if char==str1[i]:
	    counter+=1
	    
print("Character",char,"is present in string",str1,"count",counter)

#<------------------------------------------------------------------------------------------>

#to count the occurrences of each word in a give string

print("\nTo count the occurrences of each word in a give string :-")
str1=input("Enter input :")
list1=str1.split()
list2=set(list1)
list3=list(list2)
print(list1)
print(list3)
list4=[]
list5=[]
counter=0
for i in range(len(list3)):
     counter=0
     for j in range(len(list1)):
     	if list3[i]==list1[j]:
           counter+=1
     list4=list3[i],counter
     list5.append(list4)

print("\n",list5)

#<------------------------------------------------------------------------------------------>


#to check wether the given string is Palindrome or not 

print("\nTo check wether the given string is Palindrome or not :-")
str2=input("Enter string : ")
lenstr2=len(str2)
j=lenstr2-1
print(lenstr2)
flag=0
for i in range(int(lenstr2/2+1)):
   if (str2[i]==str2[j]):
      flag=1
   else:
      break
   j=-1
        
if(flag==1):
	print("\n It is Palindrome")
else:
	print("\n It is not Palindrome")

#<------------------------------------------------------------------------------------------>

#to display the index of first appearance of the substring

print("\nTo display the index of first appearance of the substring :-")
str1=input("Enter string : ")
sub1=input("Enter substring : ")
sublen=len(sub1)
index1=0
j=0

for i in range(len(str1)):
	if sub1[j]==str1[i]:
	      flag=1
	      print(sub1[j],i,j)
	      j=j+1
	      
	      if j==sublen:
	             index1=i-(sublen-1)
	             break;
	else:
	     flag=0
	     j=0
	     
print("substring index :",index1)

