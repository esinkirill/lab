#ifndef INTER_HPP
#define INTER_HPP

#include <iostream>
#include "soldier.hpp"
using namespace std;
class Inter{
    public:
        void searchname(Soldier *a,int n);
        Soldier* read(string name);
        int getcount(string name);
        void print(Soldier *a, int n);
        void input(Soldier *a, string name,int c);
        Soldier* add(Soldier *a,int n);
        Soldier* del(Soldier *a,int n);
        Soldier* learn(Soldier *a,int n);


};
#endif