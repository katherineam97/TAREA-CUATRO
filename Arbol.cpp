#include "Arbol.h"
 /** constructor con parametros de nodo
    @param par
 */
 Arbol::Nodo::Nodo(Par * par){
	 this->par=par;
 }
 
 
Arbol::Nodo::~Nodo(){	
	if(izq){
		delete izq;
		izq=0;		
	}
	if(der){
		delete der;
		der=0;
	}
}
 
 /**metodo insertar de nodo, crea una llave e inserta el nodo donde corresponde
    @param par
 */
 void Arbol::Nodo::insertar(Par * par){
		int lado=0;
	 if(this->par > par){//si el par es mayor entonces va a el lado derecho que se representa con un 1
		lado=1;	 
	 }
	 
	 if(lado==0 && izq){
		 izq->insertar(par);//en caso de que el para sea menor llama recursivamente hasta encontrar un campo nulo (donde le corresponda) 
	 }else if(!izq){//insertar en lado izquierdo		
		 izq=new Nodo(par);//inserta de hijo izq el nuevo par 
		 izq->color='N';//es una hoja por lo que es negra
		 der=new Nodo(this->par);//de hijo derecho va a tener una copia de si mismo
		 der->color='N';//es una hoja por lo que es negra
		 delete this->par;//el par del padre ahora va a ser el menor que en este caso fue le que recibio de param
		 this->par=0;
		 this->par = par;
		 this->color='R';//el padre pasa a ser rojo
		 
	 }else if(lado==1 && der){
		 der->insertar(par);
		 
	 }else if(!der){//insertar en lado der
		  der=new Nodo(par);//inserta de hijo der el nuevo par
		  der->color='N';
		  izq=new Nodo(this->par);//de hijo derecho va a tener una copia de si mismo (el padre)
		  izq->color='N';
		  this->color='R';
		  //el padre va a quedar igual porque este va a ser el caso en el que el haya tenido el menor
		 
	 }
	 
	 
	 
 }
 
 
Arbol::Arbol(){
	raiz=0;
	
}


Arbol::~Arbol(){
	if(raiz){
	  delete raiz;
	}
}
/** 
 */
int Arbol::tipoRotacion(){
	
	
}

/**
*/
bool Arbol::esRN(){
	
	
}
/**
*/
void Arbol::hayCFlip(Nodo * nodo){//se de puntero que indica que indica el lado a revisar
//llama a colorFlip() en caso de que necesite y le pasa el puntero a nodo de donde esta el problema
	
	
}

/**
*/
void Arbol::rotacionSimple(){
	
	
}

/**
*/
void Arbol::rotacionDoble(){
	
	
}

/** este metodo se realiza despues de finalizar cualquier rotacion, el que paso a ser el padre y antes era el hijo se vuelve negro y sus hijos rojos
*/
void Arbol::recoloreo(Nodo * padre){
	
	
}
/** metodo que cambia la raiz si esta es roja
*/
void Arbol::cambioRaiz(){
	if(raiz->color=='R'){
	raiz->color='N';
	}
}

/** metodo el cual si encuentra un nodo negro con dos hijos rojos, el nodo negro pasa a ser rojo y sus hijos negros
*/
void Arbol::colorFlip(Nodo * nodo){
	nodo->color='R';
	nodo->izq->color='N';
	nodo->der->color='N';
	
}
/** <<Revisar la raiz siempre y ver de que lado va el elemento a insertar>>
Metodo que primeramente revisa si se debe realizar un cambio de raiz o color flip (si la raiz es diferente de null)
posteriormente crea un par con los datos que recibe del archivo 
llama al insertar de nodo con el mismo, y finaliza revisando si el arbol quedo de tipo rojo negro para relizar las siguientes modificaciones al no serlo
@param archivo  
*/
void Arbol::insertar( const char * Archivo){
	
	
	
}