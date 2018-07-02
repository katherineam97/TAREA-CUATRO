#include "Arbol.h"
#include "Par.h"
#include <iostream>
using namespace std;
int main(){

Arbol<int,int> arbol;

arbol.insertar(new Par<int,int>(100,1));
cout<<arbol<<endl<<endl;

arbol.insertar(new Par<int,int>(160,3));
cout<<arbol<<endl<<endl;

arbol.insertar(new Par<int,int>(300,3));
cout<<arbol<<endl<<endl;

arbol.insertar(new Par<int,int>(20,3));
cout<<arbol<<endl<<endl;

arbol.insertar(new Par<int,int>(500,3));
cout<<arbol<<endl<<endl;

arbol.insertar(new Par<int,int>(350,7));
cout<<arbol<<endl<<endl;

arbol.insertar(new Par<int,int>(99,7));
cout<<arbol<<endl<<endl;

arbol.insertar(new Par<int,int>(90,7));
cout<<arbol<<endl<<endl;

//arbol.insertar(new Par<int,int>(6,7));
//cout<<arbol<<endl<<endl;

return 0;
}