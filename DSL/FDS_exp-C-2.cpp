/*
Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set
B of students like butterscotch ice-cream. Write C++ program to store two sets using
linked list. compute and display-
a) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch
*/

#include<iostream>
using namespace std;
struct node
{
	int roll;
	struct node *next;
};
class info
{
	node *head1=NULL,*temp1=NULL,*head2=NULL,*temp2=NULL,*head=NULL,*temp=NULL,*h1=NULL,*head3=NULL,*temp3=NULL;
	int c,i,f,j,k;
	public:
		node* create();
		void insert();
		void allstud();
		void vanilla();
		void butters();
		void uice();
		void nice();
		void notice();
		void ovanilla();
		void obutters();
		void display();
};
node *info::create()
{
	node *p=new(struct node);
	cout<<"Enter Student Roll Number ";
	cin>>c;
	p->roll=c;
	p->next=NULL;
	return p;
}
void info::insert()
{
	node *p=create();
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=p;
	}
}
void info::display()
{
	temp=head;
	while(temp->next!=NULL)
	{
		cout<<"\n"<<temp->roll;
		temp=temp->next;
	}
	cout<<"\n"<<temp->roll;
}
void info::allstud()
{
	cout<<"Enter number of Students ";
	cin>>k;
	head=NULL;
	for(i=0;i<k;i++)
	{
		insert();
		h1=head;
	}
	display();
	head=NULL;
}
void info::vanilla()
{
	cout<<"Enter number of  students who like Vanilla ";
	cin>>k;
	head=NULL;
	for(i=0;i<k;i++)
	{
		insert();
		head1=head;
	}
	display();
	head=NULL;
}
void info::butters()
{
	cout<<"Enter number of Students who like Butterscotch ";
	cin>>j;
	for(i=0;i<j;i++)
	{
		insert();
		head2=head;
	}
	display();
	head=NULL;
}
void info::uice()
{
	cout<<"Students who like Vanilla or Butterscotch\n";
	temp1=head1;
	while(temp1!=NULL)
	{
		node *p=new(struct node);
		p->roll=temp1->roll;
		p->next=NULL;
		if(head3==NULL)
		{
			head3=p;
		}
		else
		{
			temp3=head3;
			while(temp3->next!=NULL)
			{
				temp3=temp3->next;
			}
			temp3->next=p;
			}
		temp1=temp1->next;
	}
	temp2=head2;
	while(temp2!=NULL)
	{
		f=0;
		temp1=head1;
		while(temp1!=NULL)
		{
			if(temp2->roll==temp1->roll)
			{
				f=1;
			}
			temp1=temp1->next;
		}
		if(f==0)
		{
			node *p=new(struct node);
			p->roll=temp2->roll;
			p->next=NULL;
			if(head3==NULL)
			{
				head3=p;
			}
		else
		{
			temp3=head3;
			while(temp3->next!=NULL)
			{
				temp3=temp3->next;
			}
			temp3->next=p;
		}
		}
			temp2=temp2->next;
	}
	temp3=head3;
	while(temp3->next!=NULL)
	{
		cout<<"\n"<<temp3->roll;
		temp3=temp3->next;
	}
	cout<<"\n"<<temp3->roll;
}
void info::ovanilla()
{
	cout<<"\nStudents who only like Vanilla\n";
	temp1=head1;
	while(temp1!=NULL)
	{
		temp2=head2;
		f=0;
		while(temp2!=NULL)
		{
			if(temp1->roll==temp2->roll)
			{
				f=1;
			}
			temp2=temp2->next;
		}
		if(f==0)
		{
			cout<<"\n"<<temp1->roll;
		}
		temp1=temp1->next;
	}
}
void info::obutters()
{
	cout<<"\nStudents who only like Butterscotch\n";
	temp2=head2;
	while(temp2!=NULL)
	{
		temp1=head1;
		f=0;
		while(temp1!=NULL)
		{
			if(temp2->roll==temp1->roll)
			{
				f=1;
			}
			temp1=temp1->next;
		}
		if(f==0)
		{
			cout<<"\n"<<temp2->roll;
		}
		temp2=temp2->next;
	}
}
void info::nice()
{
	cout<<"\nStudents who like both Vanilla and Butterscotch";
	temp1=head1;
	while(temp1!=NULL)
	{
		temp2=head2;
		while(temp2!=NULL)
		{
			if(temp1->roll==temp2->roll)
			{
				cout<<"\n"<<temp1->roll;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
}
void info::notice()
{
	cout<<"\nStudents who like neither Vanilla nor Butterscotch\n";
	temp=h1;
	while(temp!=NULL)
	{
		temp3=head3;
		f=0;
		while(temp3!=NULL)
		{
			if(temp->roll==temp3->roll)
			{
				f=1;
			}
			temp3=temp3->next;
		}
		if(f==0)
		{
			cout<<"\n"<<temp->roll;
		}
		temp=temp->next;
	}
}
int main()
{
	info s;
	int i;
	char ch;
	do
	{
		cout<<"\nWelcome. Please enter your choice:";
		cout<<"\n1.Enter Student Roll Numbers";
		cout<<"\n2.Roll Numbers of Students who like Vanilla";
		cout<<"\n3.Roll Numbers of Students who like Butterscotch";
		cout<<"\n4.Students who like Vanilla or Butterscotch";
		cout<<"\n5.Students who only like Vanilla";
		cout<<"\n6.Students who only like Butterscotch";
		cout<<"\n7.Students who like both Vanilla & Butterscotch";
		cout<<"\n8.Students who neither like Vanilla nor Butterscotch";
		cout<<"\n9.Exit"<<endl;
		cin>>i;
		switch(i)
		{
			case 1:
			{
				s.allstud();
				break;
			}
			case 2:
			{
				s.vanilla();
				break;
			}
			case 3:
			{
				s.butters();
				break;
			}
			case 4:
			{
				s.uice();
				break;
			}
			case 5:
			{
				s.ovanilla();
				break;
			}
			case 6:
			{
				s. obutters();
				break;
			}
			case 7:
			{
				s.nice();
				break;
			}
			case 8:
			{
				s.notice();
				break;
			}
			case 9:
			{
				exit(0);
			}
			default:
			{
				cout<<"\nInvalid choice";
			}
		}
	}
	while(true);
	return 0;
}
