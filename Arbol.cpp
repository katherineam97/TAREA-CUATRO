#include "Arbol.h"
 /** constructor con parametros de nodo
    @param par
 */
 Arbol::Nodo::Nodo(Par * par){
	 
 }
 
 /**metodo insertar de nodo, crea una llave e inserta el nodo donde corresponde
    @param par
 */
 void Arbol::Nodo::insertar(Par * par){
	 
	 
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
bool Arbol::hayCFlip(){
	
	
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
	
	
}

/** metodo el cual si encuentra un nodo negro con dos hijos rojos, el nodo negro pasa a ser rojo y sus hijos negros
*/
void Arbol::colorFlip(){
	
	
}
/** metodo que primeramente revisa si se debe realizar un cambio de raiz o color flip (si la raiz es diferente de null)
posteriormente crea un par con los datos que recibe del archivo 
llama al insertar de nodo con el mismo, y finaliza revisando si el arbol quedo de tipo rojo negro para relizar las siguientes modificaciones al no serlo
@param archivo  
*/
void Arbol::insertar( const char * Archivo){
	
	
	
}