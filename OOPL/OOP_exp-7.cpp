/*
Write a program in C++ to use map associative container. The keys will be the
names of states and the values will be the populations of the states. When the
program runs, the user is prompted to type the name of a state. The program
then looks in the map, using the state name as an index and returns the
population of the state.
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	int ch;
	typedef map<string,int> mapType;
	mapType populationMap;
	string states[28]={"UttarPradesh","Maharashtra","Bihar","WestBengal","MadhyaPradesh",
	"TamilNadu","Rajasthan","Karnataka","Gujarat","AndhraPradesh"};
	int population[28]={199812341,112372972,103804637,91347736,72597565,72138958,68621012,
	61130704,60383628,49386799};
	while(true)
	{
		cout<<"Population of Top 10 States in India";
		for (int i=0;i<10;i++)
		{
			populationMap.insert(pair<string, int>(states[i],population[i]));
		}
	mapType::iterator iter;
	cout<<"\nSize of populationMap "<<populationMap.size()<<endl;
	string state_name;
	cout<<"Enter name of the state to know it's population\n(Note:Enter Name Without Spaces)"<<endl;
	cin>>state_name;
	iter=populationMap.find(state_name);
	if( iter!= populationMap.end() )
	{
		cout<<state_name<<"'s population is "<<iter->second<<endl;
	}
	else
	{
		cout<<"Key is not populationMap"<<endl;
		populationMap.clear();
	}
	cout<<"Do you want to check another state?\n(Type 1 for Yes, 2 for No) ";
	cin>>ch;
	switch(ch)
	{
		case 1:
		{
			continue;
		}
		case 2:
		{
			exit(0);
			break;
		}
		default:
		{
			cout<<"Invalid Choice";
		}
	}
	}
	return 0;
}
