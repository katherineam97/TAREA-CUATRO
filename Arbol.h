#ifndef _ARBOL
#define _ARBOL
#include "Par.h"
#include <vector> // para el iterador

template< class T1, class T2 >
class Arbol{
	private:
	 class Nodo{
		public:
		Nodo * izq;
		Nodo * der;
		char color;
		Par<T1,T2> * par;
	    Nodo(Par<T1,T2> *);
		~Nodo();
	    void insertar(Par<T1,T2> *);
		
	 };
	 Nodo * padre;
	 Nodo * raiz;
	public:
	
	
	
     Arbol();
	~Arbol();
    int tipoRotacion(Nodo *, int); // recibe el nodo padre,2 si es simple 1 si es doble (aqui se calcula el lado)
    Nodo* esRN(Nodo *); // recibe el lado donde empieza(nodoizq o nodoDer) 
	void buscarPadre(Nodo * );
	int negroRojos(Nodo *);
    bool hayCFlip(Nodo *); // es color flip
	void rotacionSimple(Nodo *, int);//nodo * va a ser el padre de donde esta el problema y el int especifica el lado del hijo problema
	void rotacionDoble(Nodo *, int);//nodo * va a ser el padre de donde esta el problema y el int especifica el lado del hijo problema
	void recoloreo(Nodo *); //lo llama cada rotacion
	void cambioRaiz();
	void colorFlip(Nodo *);
	void insertar(const char *);
	int esHoja(Nodo &);//sirve para cuando se quiere imprimir
	
		
		
	
	
}; 
#endif