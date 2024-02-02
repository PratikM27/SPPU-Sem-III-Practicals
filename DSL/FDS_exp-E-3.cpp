/*
Pizza parlor accepting maximum M orders. Orders are served in first come first served
basis. Order once placed cannot be cancelled. Write C++ program to simulate the system
using circular queue using array.
*/

#include<iostream>
using namespace std;
const int MAX=5;
class Pizzeria
{
	int front,rear;
	int orders[MAX];
public:
	Pizzeria()
	{
		front=rear=-1;
	}
	bool addOrder(int data);
	void serveOrder();
	void display();
};
bool Pizzeria::addOrder(int id){
 	if(rear==-1)
 	{
 		front=rear=0;
 		orders[rear]=id;
 		return true;
	 }
	 else
	 {
	 	int pos=(rear+1)%MAX;
	 	if(pos==front)
	 	{
	 		cout<<"\nPizzeria is currently full, please wait for a while.\n";
	 		return false;
		 }
		 else
		 {
		 	rear=pos;
		 	orders[rear]=id;
		 	return true;
		 }
	 }
 }
 
 void Pizzeria::serveOrder()
 {
 	if(front==-1)
 	{
 		cout<<"\nNo Orders in Pizzeria.(Pizzeria is Empty)\n";
 		return;
	 }
	 else
	 {
	 	cout<<"\nOrder No. "<<orders[front]<<" is processed.\n";
	 	if(front==rear)
	 	{
	 		front=rear=-1;
		 }
		 else
		 {
		 	front=(front+1)%MAX;
		 }
	 }
 }
 
 void Pizzeria::display()
 {
 	int i=0;
 	if(front==-1)
 	{
 		cout<<"\nPizzeria is Empty.No orders.\n";
 		return;
	 }
	 else
	 {
	 	cout<<"Order IDs: \n";
	 	for(i=front;i!=rear;i=((i+1)%MAX))
	 	{
	 		cout<<orders[i]<<"  ";
		 }
		 cout<<orders[rear];
	 }
 }
int main()
{
	int ch,id=0;
	Pizzeria m;
	do
	{
		cout<<"\nWelcome To EveryDay Pizza\nPlease enter your choice:\n1.Place Order\t\t2.Pickup Order\n3.Display Orders\t4.Exit ";
		cin>>ch;
		switch(ch)
		{
			case 1: 
			{
				id++;
				if(m.addOrder(id))
				{
					cout<<"Thank You!\nYour Order ID is : "<<id;
				}
				else
				{
					id--;
				}
				break;
			}
			case 2:
			{
				m.serveOrder();
				break;
			}
			case 3:
			{
				m.display();
				break;
			}
			case 4:
			{
				cout<<"Thank You!\nPlease Visit Again."<<endl;
				exit(0);
			}
			default:
			{
				cout<<"Invalid choice";
			}
		}
	}
	while(true);
 }
