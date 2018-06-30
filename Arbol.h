#ifndef _ARBOL
#define _ARBOL
#include "Par.h"
#include <vector> // para el iterador
#include <iostream>
using namespace std;

template< class T1, class T2 >
class Arbol{
	private:
	 class Nodo{
		public:
		Nodo * izq;
		Nodo * der;
		char color;
		Par<T1,T2> * par;
 Nodo(Par<T1,T2> * par){
	 this->par=par;
	 izq=0;
	 der=0;
	 color='\0';
 }
 
 
~Nodo(){	
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
void insertar(Par<T1,T2> * par){
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
		 this->par = new Par<T1,T2>(par->getLlave(),0);
		 this->color='R';//el padre pasa a ser rojo
		 
	 }else if(lado==1 && der){
		 der->insertar(par);
		 
	 }else if(!der){//insertar en lado der
		  der=new Nodo(par);//inserta de hijo der el nuevo par
		  der->color='N';
		  izq=new Nodo(this->par);//de hijo derecho va a tener una copia de si mismo (el padre)
		  izq->color='N';
		  this->color='R';
		  this->par->setDato(0);
		  //el padre va a quedar igual porque este va a ser el caso en el que el haya tenido el menor
		 
	 }
	 
	 
	 
 }
 
 // Metodo que imprime el nodo Pre ORDEN
ostream& imprimir(ostream& salida){
	salida << (*(this->par)) << " ";
	if(this->izq)		// Chequea si existe el hijo izquierdo
	{
		this->izq->imprimir(salida);
	}
	if(this->der)		// Chequea si existe el hijo derecho
	{
		this->der->imprimir(salida);
	}
	return salida;
}
		
	 };
	 
	 Nodo * padre;
	 Nodo * raiz;
	
	public:
	
	
	
Arbol(){
	raiz=0;
	padre=0;
	
}


~Arbol(){
	if(raiz){
	  delete raiz;
	}
}
/** 
 */
int tipoRotacion(Nodo * nodo, int lado){ //yo y mi lado   
    int tipo;
	if((nodo->izq->color=='R' && lado==0) || (nodo->der->color=='R' && lado==1)){// si mi hijo izquierdo es rojo y yo estoy a la izquierda
		tipo=1;//1 representa rotacion simple
		
	}else{
		tipo=2;
	}
	return tipo;
	
}

/**
*/
Nodo* esRN(Nodo* nodo){
		
	if (nodo->izq!= 0){
		
		if(rojosSeguidos(nodo)){
			buscarPadre(*nodo);
			return nodo;
		}else{
			esRN(nodo->izq);

		}
		
		
	}
	
	if (nodo->der!=0){
		if(rojosSeguidos(nodo)){
			buscarPadre(*nodo);
			return nodo;
		}else{ 
		esRN(nodo->der);
	}
	}
	
	return 0;
 }

int rojosSeguidos(Nodo* nodo){
	if((nodo->color =='R' && nodo->izq->color=='R')|| (nodo->color =='R' && nodo->der->color=='R') ){
		return 1;
	}else{
		return 0;
	}
	
}

void buscarPadre(Nodo & hijo){
	Nodo * aux=raiz;
	padre= aux;
	int donde=-1;
	while(aux->par->getLlave() !=  hijo.par->getLlave()){
            if(hijo.par > aux->par){
                padre=aux;
                aux= aux->der;
				donde=1;
            } else{
                padre=aux;
                aux=aux->izq;
                donde=0;
            }
    }
     //ya se cual es mi padre 
	if(tipoRotacion(aux, donde)==1){
		rotacionSimple(padre, donde);
		
	}else{
		rotacionDoble(padre, donde);
		
	}
	
}

/**
*/

void hayCFlip(Nodo * nodo){//se de puntero que indica que indica el lado a revisar
//llama a colorFlip() en caso de que necesite y le pasa el puntero a nodo de donde esta el problema
   cout<<"vere si hay Cflip"<<endl;
	if (nodo->izq){
			colorFlip(nodo);
			hayCFlip(nodo->izq);
	}

	if (nodo->der){
		colorFlip(nodo);
		hayCFlip(nodo->der);
	}
	 
	cout<<"salii Cflip"<<endl; 
}



/**
*/
void rotacionSimple(Nodo * padre, int lado){
	if(lado==0){//rotacion izquierda

	//IZQUIERDA
		padre->izq->der= new Nodo(padre->der->izq->par);
		padre->izq->izq=new Nodo(padre->izq->par);
		padre->izq->par->setDato(0);//borra el dato de un nodo para que sea una llave
		padre->par->setLlave(padre->der->par->getLlave());//asigna la llave del hijo al padre
		Nodo * ptr= (padre->der->der);
		padre->der->der=0;
		delete padre->der;//  
		padre->der= ptr;
		//cout "Rotacion Simple iZQUIERDA" : arbol
		recoloreo(padre);
		//cout "Recoloreo" :arbol
		
		
	}else{
		padre->der->izq= new Nodo(padre->izq->der->par);
		padre->der->der = new Nodo(padre->der->par);
		
		padre->der->par->setDato(0);
		padre->der->par->setLlave(padre->der->izq->par->getLlave());
		
		padre->par->setLlave(padre->izq->par->getLlave());
		
		Nodo * ptr = (padre->izq->izq);
		padre->izq->izq=0;
		delete padre->izq;
		padre->izq= ptr;
		//cout "Rotacion Simple DERECHA" : arbol
		recoloreo(padre);
		//cout "Recoloreo" :arbol
		
		
	}
	
}

/**
*/
void rotacionDoble(Nodo * padre, int lado){//yo izquierdo y mi hijo derecho rojo
	
	if(lado==0 && padre->der->color=='R'){
		rotacionSimple(padre,1);
		rotacionSimple(padre,0);
		
	}else if(lado==1 && padre->izq->color=='R'){
		rotacionSimple(padre,0);
		rotacionSimple(padre,1);
		
	}
	
}

/** este metodo se realiza despues de finalizar cualquier rotacion, el que paso a ser el padre y antes era el hijo se vuelve negro y sus hijos rojos
*/
void recoloreo(Nodo * padre){
	padre->color='N';
	padre->izq->color='R';
	padre->der->color='R';
	
}
/** metodo que cambia la raiz si esta es roja
*/
void cambioRaiz(){
	cout<<"cambiaree raiz"<<endl;
	if(raiz->color=='R'){
	raiz->color='N';
	}
}

/** metodo el cual si encuentra un nodo negro con dos hijos rojos, el nodo negro pasa a ser rojo y sus hijos negros
*/
void colorFlip(Nodo * nodo){
	cout<<"comprovaree Colorflip"<<endl; 
	if(nodo->izq && nodo->der){
		if(nodo->color=='N' && nodo->izq->color=='R' && nodo->der->color=='R'){
		 
	     	nodo->color='R';
			nodo->izq->color='N';
			nodo->der->color='N'; 
	}
	
	}
	cout<<"salii Colorflip"<<endl; 

}

int esHoja(Nodo & nodo){
	if(nodo.der != 0 && nodo.izq != 0){
		return 0;//no es hoja
	}else{		
		return 1;
	}
	
}

/** <<Revisar la raiz siempre y ver de que lado va el elemento a insertar>>
Metodo que primeramente revisa si se debe realizar un cambio de raiz o color flip (si la raiz es diferente de null)
posteriormente crea un par con los datos que recibe del archivo 
llama al insertar de nodo con el mismo, y finaliza revisando si el arbol quedo de tipo rojo negro para relizar las siguientes modificaciones al no serlo
@param archivo  
*/
//void insertar( const char * Archivo){
	
	
	
//}

void insertar(Par<T1,T2> * par){
	int lado=0;
	if(raiz){
		cambioRaiz();
		if(raiz->der && raiz->izq){
			if(raiz->par->getLlave() > par->getLlave()){
			hayCFlip(raiz->der);
			lado=1;
		}else{
			hayCFlip(raiz->izq);
			lado=2;
		}

		}
	
		
		raiz->insertar(par);
		if(lado==1){
			esRN(raiz->der);
		}else if(lado==2){
			esRN(raiz->izq);
		}
		
		
		
	}else{
		raiz=new Nodo(par);	
	}
	
}


// Metodo que imprime el arbol por medio de un operator
friend ostream& operator<<(ostream& salida, Arbol<T1,T2>& arbol){
	if(arbol.raiz){
		arbol.raiz->imprimir(salida);  // Imprimir recursivamente a todo el arbol
	}
	return salida;
}


	
		
		
	
	
}; 
#endif