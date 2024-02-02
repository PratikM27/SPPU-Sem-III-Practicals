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
 	fstream file("sample1.txt",ios::out);                         //create & open file & writes data out to a data file 
 	/*OR 
 	fstream file;
 	file.open("sample1.txt",ios::out);
        */
 	if(!file)                                          //check file is open successfully or not
 	{cout<<"Error-File is not open"<<endl;
 	return 0;
 	}
 	cout<<"File is open"<<endl;               
 	cout<<"Write data to file : ";   
 	cin.getline(data,100);
 	file<<data<<endl;
 	file.close();                                       //file close
 
 	cout<<"Reading file data : "<<endl;                            
 	fstream file1;                    
 	file1.open("sample1.txt");                         //opening file for reading 
 	if(!file)                                          //check file is open successfully or not
 	{cout<<"Error-File is not open"<<endl;
 	return 0;
 	}
 	while(!file1.eof())                                     //read data until End Of File
 	{
   		cout<<"\nData : "<<data<<endl;
   		break;
 	}
 	file1.close();                                          //file close
 	return 0;
}
