/*
Write a function template selection Sort. Write a program that inputs, sorts and outputs an integer array and a float array.
*/
/*selection sort - find minimum element in unsorted array & swap it with element at begining*/


#include<iostream>
using namespace std;
int n,i,j;
#define size 10
template<class T>
void sel(T arr[size])
{
 for(i=0;i<n;i++)
 {
   for(j=i+1;j<n;j++)
   {  if(arr[j]<arr[i])
        {
          T temp=arr[j];
          arr[j]=arr[i];
          arr[i]=temp;
        }
   }
 }
 cout<<"\nSorted Array :"<<endl;
 for(i=0;i<n;i++)
 {cout<<arr[i]<<" ";}
 cout<<endl;
}

int main()
{
  cout<<"Enter no. of elements : ";
  cin>>n;
 
  int arr[size];
  for(i=0;i<n;i++)
  {cout<<"\nEnter Elements (integer no.): ";
   cin>>arr[i];}
  sel(arr);
  
  float arr1[size];
  for(i=0;i<n;i++)
  {cout<<"\nEnter Elements (float no.): ";
   cin>>arr1[i];}
  sel(arr1);
}


