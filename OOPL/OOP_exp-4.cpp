/*
Write a C++ program that creates an output file, writes information to it, closes the file, open
it again as an input file and read the information from the file.
*/

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char data[100];
	fstream f1("Test.txt",fstream::out);
	if(!f1)
	{
		cout<<"File cannot be accessed";
	}
	else 
	{
		cout<<"File created"<<endl;
		cout<<"Writing to file\nEnter data ";
		cin.getline(data,100);
		f1<<data<<endl;
		f1.close();
		cout<<"Reading file";
		fstream f2;
		f2.open("Test.txt");
		while(!f2.eof())
		{
			cout<<"\nData= "<<data<<endl;
			break;
		}
		f2.close();
	}
	return 0;
}
