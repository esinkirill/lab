#ifndef SOLDIER_HPP
#define SOLDIER_HPP
#include <iostream>
using namespace std;

class Soldier{
  string name;
  int type; // 0 - new, 1 - ground forces, 2 - air forces, 3 - naval forces 
  int age;
  public:
    Soldier();
    ~Soldier();
    string getname(); 
    int gettype(); 
    int getage();
    void set(string n, int a, int t);
    friend ostream & operator <<(ostream & out, const Soldier &s);
    friend istream & operator >>(istream & out, Soldier &s);
    
};


#endif