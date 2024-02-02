'''
Write a python program to store first year percentage of students in array. 
Write function for sorting array of floating point numbers in ascending order using 
a) Selection Sort 
b) Bubble sort and display top five scores.
'''

def bubbleSort(arr): 
    n = len(arr) 
    for i in range(n-1): 
        for j in range(0, n-i-1): 
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j] 
arr=[]
Num=int(input("Enter the number of students : "))
for i in range (Num):
    per=float(input("Enter the percentage marks : "))
    arr.append(per)
bubbleSort(arr)
print ("Sorted array is : ") 
for i in range(len(arr)): 
    print ("%f" %arr[i])  

def selectionSort(arr1):
    for i in range(len(arr1)): 
        min_idx = i 
        for j in range(i+1, len(arr1)): 
            if arr1[min_idx] > arr1[j]: 
                min_idx = j            
        arr1[i], arr1[min_idx] = arr1[min_idx], arr1[i] 
arr1=[]
Num=int(input("\nEnter the number of students : "))
for i in range (Num):
    per=float(input("Enter the percentage marks : "))
    arr1.append(per)
selectionSort(arr1)
#Main
print ("Sorted array : ") 
for i in range(len(arr1)): 
    print("%f" %arr1[i])
print("Top 5 scores are : \n")
arr2=arr1[::-1]
for i in range(0,5):
	print("%f" %arr2[i])
