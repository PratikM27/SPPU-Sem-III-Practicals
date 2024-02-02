/*                    Experiment No.3
Imagine a publishing company which does marketing for book and audio cassette Versions. 
Create a class publication that stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count (type int) and 
tape which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data
and displays the data members. If an exception is caught, replace all the data member
values With zero values.
*/

#include<iostream>
#include<string>
using namespace std;

class publication                 //Base class
{ protected:
    string title;
     float price;
  public:
     publication(){}              //constructor of Base class
     
     virtual void getdata()
     {
       cout<<"Enter title : ";
       cin>>title;
       cout<<"Enter price(Rs.) : ";
       cin>>price;
     }
     virtual void display()
     {
       cout<<"Title : "<<title<<endl<<"Price (Rs.) : "<<price<<endl;
     }
};
class book:public publication            //Derived class book from Base class
{
  private:
    int pagecount;
  public:
    book(){}                            //constructor of Derived class book
    
    void getdata()
     { 
       publication::getdata();                        //call overriding function of base class
       cout<<"Enter Page count of book : ";
       cin>>pagecount;
     }
    void display()
    {  publication::display();                        //call overriding function of base class
       cout<<"Page count of book : "<<pagecount<<endl;
    }
  
};
class tape:public publication                //Derived class tape from Base class
{
  private:
   float time;
  public:
   tape(){}                               //constructor of Derived class tape
  
   void getdata()
     {
       publication::getdata();                             //call overriding function of base class
       cout<<"Enter Time of tape (hrs.) : ";
       cin>>time;
     }
    void display()
    {  publication::display();                              //call overriding function of base class
       cout<<"Time of tape (hrs.) : "<<time<<endl;
    }
};
int main()
{
  book o1;              //object of derived class book
  tape o2;              //object of derived class tape
  
  cout<<"--------------------Publication--------------------"<<endl;
  cout<<"\nEnter Book information :-"<<endl;
  o1.getdata();
  cout<<"\nEnter Tape information :-"<<endl;
  o2.getdata();
  
  cout<<"\n\n----------Book Publication Information----------"<<endl;
  cout<<"\nDisplay Book information :-"<<endl;
  o1.display();
  cout<<"\n----------Tape Publication Information----------"<<endl;
  cout<<"\nDisplay Tape information :-"<<endl;
  o2.display();
  
  return 0;
}





