
/*                Experiment No.2
Develop a program in C++ to create a database of student’s information system containing the 
following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact
address, Telephone number, Driving license no. and other.Construct the database with suitable 
member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic
memory allocation operators-new and delete as well as exception handling.
*/

#include<iostream>
#include<string>
using namespace std;

class studentdata
{
  private:
     string name;
     int *roll_no;       //declare the pointer ,this is int pointer for which will memory allocate dynamically
     string class_name;
     string division;
     string dob;
     string blood_group;
     string address;
     string phone_no;
     string license_no;
     static int student_count;
  public:
     studentdata()
     { roll_no=new int;      //allocate single int space for roll no. 
       *roll_no=0;
     }
     ~studentdata()
     {delete roll_no;}
     friend class ABC;
};
int studentdata::student_count;  //declare static variable and initialized to 0

class ABC:public studentdata
{
 public:
     void getdata()
     {
       cout<<"\n----------Enter Student Information----------"<<endl;
       cout<<"Enter name of student : ";
       cin>>name;
       //getline(cin,name);
       cout<<"Enter Roll no.: ";
       cin>>*roll_no;
       cout<<"Enter Class Name : ";
       cin>>class_name;
       cout<<"Enter Division : ";
       cin>>division;
       cout<<"Enter DOB : ";
       cin>>dob;
       cout<<"Enter Blood Group : ";
       cin>>blood_group;
       cout<<"Enter Address : ";
       cin>>address;
       //getline(cin,address);
       cout<<"Enter Phone no. : ";
       cin>>phone_no; 
       cout<<"Enter license no : ";
       cin>>license_no;
       student_count++;
     }
     inline void display()
     { cout<<"\n-----------------------------------------------------"<<endl;
       cout<<"Name of student : "<<name<<endl;
       cout<<"Roll no.: "<<*roll_no<<endl;
       cout<<"Class : "<<class_name<<endl;
       cout<<"Division : "<<division<<endl;
       cout<<"DOB : "<<dob<<endl;
       cout<<"Blood Group : "<<blood_group<<endl;
       cout<<"Enter Address : "<<address<<endl;
       cout<<"Enter Phone no. : "<<phone_no<<endl; 
       cout<<"Enter license no : "<<license_no<<endl;
       cout<<"Student Count : "<<student_count<<endl;
       cout<<"\n-----------------------------------------------------"<<endl;
     }
     static void head()
     {cout<<"\n----------STUDENT DATABASE----------"<<endl;}

};

int main()
{
  ABC obj[5];
  int ch,i;
  int count=0;
  
  do
  {
    cout<<"\n---------------------Menu---------------------"<<endl;
    cout<<"\n1.Add Student Info. : "<<endl;
    cout<<"2.Display Student Info. : "<<endl;
    cout<<"3.Exit."<<endl;
    
    cout<<"\nEnter your choice : ";
    cin>>ch;
    
    switch(ch)
    {
       case 1 :
          obj[count].getdata();
          count++;
         break;
         
       case 2 :
         for(i=0;i<count;i++)
         { ABC::head();
           obj[i].display();
         } 
        break;
        
       case 3 :
        cout<<"Exit."<<endl;
        return 0;
       break;
    }
  }while(ch != 3);
  return 0;
}




/*int main()
{ int n;
  int student_count=0;
  cout<<"Enter number of students : ";
  cin>>n;
  
  ABC obj[5];
  char ch;
  for(int i=0;i<n;i++)
  {//do{
   obj[i].getdata();
   student_count++; 
//   cout<<"Do you want to Add another Student data (y/n) : ";
//   cin>>ch;
//  }while(ch=='y'||ch=='Y');
  }for(int j = 0; j <student_count; j++) {

        obj[j].display();
        }
  return 0;
}
*/


