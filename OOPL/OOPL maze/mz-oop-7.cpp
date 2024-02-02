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
 typedef map<string,int>mapType;
 mapType populationMap;   //create empty map
 
 //insert element in map
 populationMap.insert(pair<string,int>("Maharashtra",123456789));
 populationMap.insert(pair<string,int>("Rajastan",654987321));
 populationMap.insert(pair<string,int>("Karnataka",651489632));
 populationMap.insert(pair<string,int>("Tamilnadu",65451753));
 
 //iterator
 mapType::iterator iter;
 
 //size of map
 cout<<"\nSize of map"<<populationMap.size()<<endl;
 
 string state_name;
 cout<<"\nEnter name of state : ";
 cin>>state_name;
 
 //find record
 iter=populationMap.find(state_name);
 if(iter !=populationMap.end())
     cout<<state_name<<"'s population is "<<iter->second<<endl;
 else
     cout<<"Key is not in populationMap. "<<endl;
  
  //clear entries 
   populationMap.clear(); 
} 
