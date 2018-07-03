#include "Arbol.h"
#include "Par.h"
#include <iostream>

using namespace std;

int main(){

  Arbol<int,char> arbol;
  
for(int i=1; i<10; ++i){
	arbol.insertar(new Par<int,char> (i,'c'));
	cout<<arbol<<endl<<endl;	
}


   
   return 0;	
}