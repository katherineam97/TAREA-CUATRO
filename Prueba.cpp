#include "Arbol.h"
#include "Par.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv){

Arbol<int,int> arbol;
arbol.insertar(argv[1]);
cout<<arbol<<endl<<endl;

return 0;
}