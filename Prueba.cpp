#include "Arbol.h"
#include "Par.h"
#include <iostream>
using namespace std;
int main(){

Arbol<int,int> arbol;

arbol.insertar(new Par<int,int>(10,1));
arbol.insertar(new Par<int,int>(22,3));

cout<<arbol;
return 0;
}