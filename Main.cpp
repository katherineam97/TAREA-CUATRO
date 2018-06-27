#include"Par.h"
#include<iostream>
using namespace std;

int main(){

   Par<int,int> par(3,5);
   Par<int,char> par2(3,'L');
   
   cout << par << endl;
   cout << par2 << endl;
   
   return 0;	
}