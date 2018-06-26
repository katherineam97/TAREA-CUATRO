#ifndef _ARBOL
#define _ARBOL
#include "Par.h"
#include <vector> // para el iterador

class Arbol{
	private:
	 class Nodo{
		public:
		Nodo * izq;
		Nodo * der;
		char color;
		Par * par;
	    Nodo(Par *);
	    void insertar(Par *);
		
	 };
	 Nodo * bisabuelo;
	 Nodo * abuelo;
	 Nodo * raiz;
	public:
	
	class Iterador{
		 
		
	}
	
    Arbol();
    int tipoRotacion(); // 2 si es simple 1 si es doble
    bool esRN(); // si es rojo negro no necesita rotar modifique punteros a padre y abuelo
    bool hayCFlip(); // es color flip
	void rotacionSimple();
	void rotacionDoble();
	void recoloreo(); //lo llama cada rotacion
	void cambioRaiz();
	void colorFlip();
	void insertar( const char *);
	
	
}