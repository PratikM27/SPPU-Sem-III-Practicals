/* 
Implement a class Complex which represents the Complex Number data type. Implement the following
1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overload operator+ to add two complex numbers.
3.	Overload operator* to multiply two complex numbers.
4.	Overload operators << and >> to print and read Complex Numbers
*/


#include<iostream>
using namespace std;

class complex
{
 private:
  int real,img;
  
 public:
  complex()          //default constructor
   {   real = 0;
       img = 0;
   }
   
  complex operator + (complex &c)          // + operator overloading
  {
   complex res;
   res.real=real+c.real;
   res.img=img+c.img;
   return res;
  }
  
  complex operator * (complex &c)          // * operator overloading
  {
   complex res;
   res.real= real * c.real - img * c.img;
   res.img= real * c.img + img * c.real;
   return res;
  }
  
  friend ostream & operator << (ostream & out,const complex &c);
  friend istream & operator >> (istream & in,complex &c);
};

ostream & operator << (ostream & out,const complex & c)
{
 out<<c.real<<"+"<<c.img<<"i"<<endl;
 return out;
}
istream & operator >> (istream & in,complex & c)
{
 cout<<"\nEnter real part :"<<endl;
 in>>c.real;
 cout<<"\nEnter imginary part :"<<endl;
 in>>c.img;
 return in;
}

int main()
{
  complex c1,c2,c3,c4;
 
  cout<<"\nEnter the first no. : ";
  cin>>c1;
  cout<<"\nThe first no. is : ";
  cout<<c1;
  
  cout<<"\nEnter the second no. : ";
  cin>>c2;
  cout<<"\nThe second no. is : ";
  cout<<c2;
  
  c3=c1+c2;
  cout<<"\n The addition of complex no. is : ";
  cout<<c3;
  
  c4=c1*c2;
  cout<<"\n The multiplication of complex no. is : ";
  cout<<c4;
return 0;
}
