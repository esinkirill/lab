#include "soldier.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Soldier::Soldier(){
  
}
Soldier::~Soldier(){
  
}
ostream& operator<<(ostream &stream,const Soldier &s){
  stream<<"Name: "<<s.name<<endl;
  stream<<"Age: "<<s.age<<endl;
  
  stream<<"Part: ";
  switch (s.type){
    case 0:
      stream<<"new"<<endl;
      break;
    case 1:
      stream<<"ground forces"<<endl;
      break;
    case 2:
      stream<<"air forces"<<endl;
      break;
    case 3:
      stream<<"naval forces"<<endl;
      break;
    default:
      break;   
  }
  return stream;
}




void Soldier::set(string n, int a,int t){
  name=n;
  age=a;
  type=t;
}

string Soldier:: getname(){
  return name;
}

int Soldier:: getage(){
  return age;
}

int Soldier:: gettype(){
  return type;
}

istream & operator >>(istream & in, Soldier &s) {
  in >> s.name;
  in >> s.age;
  in >> s.type;
  return in;
}



