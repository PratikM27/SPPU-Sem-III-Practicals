/*
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

class publication
{public:
 string title;
 float price;
 public:
  void getdata()
  {
   cout<<"Enter Title : ";
   cin>>title;
   cout<<"Enter Price(Rs.) : ";
   cin>>price;
  }
  void display()
  {
   cout<<"\nTitle : "<<title<<endl;
   cout<<"\nPrice : "<<price<<endl;
  }
};

class Book:public publication        //Derived class book from Base class
{
 private:
   int pagecount;
 public:
   void getdata()
   {
    publication::getdata();      //call overriding function of base class
    cout<<"Enter Page count : ";
    cin>>pagecount;   
   }
   void display()
   {try
    { if (pagecount>1000)
      throw pagecount;
      if (price>500)  
      throw price;
     publication::display();        //call overriding function of base class
     cout<<"\nPage count : "<<pagecount<<endl;
    }
   /*catch(int pagecount)
   catch(float price)*/
   catch(...)    //special catch that catches all exceptions declare as catch(...)
    {title='0';
     price=0;
     pagecount=0;
     cout<<"\nTitle : "<<title<<endl;
     cout<<"\nPrice : "<<price<<endl;
     cout<<"\nPage Count : "<<pagecount<<endl;
    }
   }
};

class Tape:public publication           //Derived class tape from Base class
{
 private:
   float time;
 public:
   void getdata()
   {
    publication::getdata();          //call overriding function of base class
    cout<<"Enter PlaybackTime(min.) : ";
    cin>>time;   
   }
   void display()
   {try
      { if (time>50)
        throw time;
        if (price>500)  
        throw price;
       publication::display();       //call overriding function of base class
       cout<<"\nPlaybackTime : "<<time<<endl;
      }
   /*catch(float time)
     catch(float price)*/
   catch(...)       //special catch that catches all exceptions declare as catch(...)
     {  title='0';
        price=0;
        time=0;
        cout<<"\nTitle : "<<title<<endl;
        cout<<"\nPrice : "<<price<<endl;
        cout<<"\nPlaybackTime : "<<time<<endl;
     } 
   }
};

int main()
{
 Book b;
 Tape t;
 cout<<"\n-----------------------Publication-----------------------"<<endl;
 cout<<"\nEnter Book Information : "<<endl;
 b.getdata();
 cout<<"\nEnter Tape Information : "<<endl;
 t.getdata();
 
 cout<<"\n-----------------------Book Publication Info.-----------------------"<<endl;
 b.display();
 cout<<"\n-----------------------Tape Publication Info.-----------------------"<<endl;
 t.display();
 return 0;
}




