/*
Write a function template for selection sort that inputs, sorts and
outputs an integer array and a float array.
*/

#include <iostream>
using namespace std;
int n;
#define size 10
template <class Sort>
void sel_sort(Sort A[size])
{
	Sort temp;
	int min;
	for (int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if (A[j]<A[min])
			{
				min=j;
			}
		}
		temp=A[i];
		A[i]=A[min];
		A[min]=temp;
	}
	cout<<"Sorted array:\n";
	for (int i=0;i<n;i++)
	{
		cout<<"\t"<<A[i];
	}
}
int main()
{
	int ch;
	cout<<"Welcome to Selection Sort\n";
	while(true)
	{
		cout<<"\nPlease Enter Your Choice\n1.Integer\t2.Float\n3.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				int A[size];
				cout<<"Enter number of array elements ";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"Enter integer element ";
					cin>>A[i];
				}
				sel_sort(A);
				break;
			}
			case 2:
			{
				float B[size];
				cout<<"Enter number of array elements ";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"Enter float element ";
					cin>>B[i];
				}
				sel_sort(B);
				break;
			}
			case 3:
			{
				exit(0);
			}
			default:
			{
				cout<<"Invalid choice";
			}
		}
	}
	return 0;
}
