#include <iostream>
#include <fstream>
#include "soldier.hpp"
using namespace std;
int main(int argc, char *argv[]){  
  if (argc<=1){
    cout<<"Name not specified"<<endl;
    return 0;
  }
  
  Soldier* a=read(argv[1]);
  int n=getcount(argv[1]);
  int k=1;
  while (k!=0){
    cout<<"1.Add soldier"<<endl;
    cout<<"2.Print military unit"<<endl;
    cout<<"3.Send to task"<<endl;
    cout<<"4.Find soldier"<<endl;
    cout<<"5.Learn soldier"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"------------------"<<endl;
    
    cin>>k;
    switch (k){
      case 1:
        a=add(a,n);
        n++;
        break;
      case 2:
        print(a,n);
        break;
      case 3:
        a=del(a,n);
        n--;
        break;
      case 4:
        searchname(a, n);
        break;
      case 5:
        a=learn(a, n);
        break;
      default:
        input(a, argv[1], n);
        n=0;
        break;

    }
  }
  delete []a;
  return 0;
}
