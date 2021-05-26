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


void print(Soldier *a, int n){
  int c=0,c1=0,c2=0,c3=0;

  for (int i=0;i<n;i++)
    if (a[i].gettype()==0)
      c++;
    else if (a[i].gettype()==1)
      c1++;
    else if (a[i].gettype()==2)
      c2++;
    else
      c3++;
  cout<<"Total: "<<endl;
  cout<<"New: "<<c<<endl;
  cout<<"Grond forces: "<<c1<<endl;
  cout<<"Air forces: "<<c2<<endl;
  cout<<"Naval forces: "<<c3<<endl;

  cout<<"Get everyone out, 1 - yes, 0 -no"<<endl;
  cin>>c;
  if (c==1){
    cout<<"Soldiers"<<endl;
    for (int i = 0; i<n; i++)
      cout<<a[i]<<endl;
    
  }

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

int getcount(string name){
  int n=0;
  ifstream f(name, ios::binary);
  f.read((char*)&n,sizeof(n));
  f.close();
  return n;
}


Soldier* read(string name){
  Soldier*a;
  ifstream f(name, ios::binary);
  int w=0,c=0,g=0;
  f.read((char*)&c,sizeof(c));
  a=new Soldier[c];
  for (int j=0;j<c;j++){
    string::size_type n = 0;
    f.read((char*)&n, sizeof(string::size_type));
    string s(n,0);
    for (int i = 0; i < n; ++i)
      f.read(&s[i], sizeof(s[0]));
    

    f.read((char *)&w, sizeof(w));
    f.read((char*)&g, sizeof(g));
    a[j].set(s,w,g);
  }
  return a;
}


void input(Soldier *a,string name,int c){
  ofstream f(name, ios::binary);
  f.write((char*)&c,sizeof(c));
  for (int i=0;i<c;i++){
    Soldier b=a[i];
    string name=b.getname();
    int age=b.getage();
    int type=b.gettype();
    string::size_type n = name.size(); 
    f.write((char*)&n, sizeof(string::size_type));
    f.write(name.c_str(), name.size());
    f.write((char*)&age,sizeof(age));
    f.write((char*)&type,sizeof(type));
    
  }
  f.close();

}

Soldier* add(Soldier *a,int n){
  Soldier *b=new Soldier[n+1];
  string name;
  int age;
  for (int i=0;i<n;i++)
    b[i]=a[i];
  cout<<"Name:  ";
  cin>>name;
  cout<<"Age: ";
  cin>>age;
  b[n].set(name,age, 0);
  return b;
}


Soldier* learn(Soldier *a,int n){
  string name;
  int age,type;
  cout<<"Name:  ";
  cin>>name;
  cout<<"Age: ";
  cin>>age;
  cout<<"Part (1 - ground forces, 2 - air forces, 3 - naval forces ): ";
  cin>>type;
  for (int i=0;i<n;i++)
    if ((a[i].getname()==name) and (a[i].getage()==age))
      a[i].set(name,age,type);
  
  return a;
}









istream & operator >>(istream & in, Soldier &s) {
  in >> s.name;
  in >> s.age;
  in >> s.type;
  return in;
}

Soldier* del(Soldier *a,int n){
  string name;
  int age,type, j=0;
  cout<<"Name:  ";
  cin>>name;
  cout<<"Age: ";
  cin>>age;
  cout<<"Part (1 - ground forces, 2 - air forces, 3 - naval forces ): ";
  cin>>type;
  Soldier *b=new Soldier[n-1];
  for (int i=0;i<n;i++)
    if ((a[i].getname()!=name) and (a[i].getage()!=age) and (a[i].gettype()!=type)){
      //cout<<a[i].getName()<<endl;
      b[j]=a[i];
      j++;
    }
  return b;
}

void searchname(Soldier *a,int n){
  string s;
  cout<<"Name: ";
  cin>>s;
  for (int i=0;i<n;i++)
    if (a[i].getname()==s){
      cout<<"Soldier"<<endl;
	    cout<<a[i];
    }
  
}

