#include "Arbol.h"
#include "Par.h"
#include <iostream>

using namespace std;

int main(){

  Arbol<char,char> arbol;

arbol.insertar(new Par<char,char> ('c','t'));
cout<<arbol<<endl<<endl;

arbol.insertar(new Par<char,char> ('d','t'));
cout<<arbol<<endl<<endl;

arbol.insertar(new Par<char,char> ('a','y'));
cout<<arbol<<endl<<endl;

arbol.insertar(new Par<char,char> ('b','y'));
cout<<arbol<<endl<<endl;


   
   return 0;	
}