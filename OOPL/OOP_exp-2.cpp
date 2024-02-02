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
     int roll_no;
     string class_name;
     string division;
     string dob;
     string blood_group;
     string address;
     string phone_no;
     string license_no;
     static int student_count;
  public:
     studentdata(){}
     ~studentdata(){}
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
       cout<<"Enter Roll no.: ";
       cin>>roll_no;
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
       cout<<"Enter Phone no. : ";
       cin>>phone_no; 
       cout<<"Enter license no : ";
       cin>>license_no;
       student_count++;
     }
     inline void display()
     {
       cout<<"\n----------STUDENT DATABASE----------"<<endl;
       cout<<"Name of student : "<<name<<endl;
       cout<<"Roll no.: "<<roll_no<<endl;
       cout<<"Class : "<<class_name<<endl;
       cout<<"Division : "<<division<<endl;
       cout<<"DOB : "<<dob<<endl;
       cout<<"Blood Group : "<<blood_group<<endl;
       cout<<"Enter Address : "<<address<<endl;
       cout<<"Enter Phone no. : "<<phone_no<<endl; 
       cout<<"Enter license no : "<<license_no<<endl;
       cout<<"Student Count : "<<student_count<<endl;
     }

};

int main()
{
  ABC obj;
  obj.getdata();
  obj.display();
  return 0;
}
