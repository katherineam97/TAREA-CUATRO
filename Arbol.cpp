#include "Arbol.h"
 /** constructor con parametros de nodo
    @param par
 */
 Arbol<T1,T2>::Nodo::Nodo(Par<T1,T2> * par){
	 this->par=par;
 }
 
 
Arbol<T1,T2>::Nodo::~Nodo(){	
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
 void Arbol<T1,T2>::Nodo::insertar(Par<T1,T2> * par){
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
		 this->par = new Par(par->getLlave,0);
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
 
 
Arbol<T1,T2>::Arbol(){
	raiz=0;
	
}


Arbol<T1,T2>::~Arbol(){
	if(raiz){
	  delete raiz;
	}
}
/** 
 */
int Arbol<T1,T2>::tipoRotacion(Nodo * nodo, int lado){ //yo y mi lado   
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
Nodo* Arbol<T1,T2>::esRN(Nodo* nodo){
		
	if (nodo->izq!= 0){
		
		if(rojosSeguidos(nodo)){
			return nodo;
		}else{
			esRN(nodo->izq);
		}
		
		
	}
	
	if (nodo->der!=0){
		if(rojosSeguidos(nodo)){
			return nodo;
		}else{ 
		esRN(nodo->der);
	}
	}
	
	return 0;
 }

int Arbol<T1,T2>::rojosSeguidos(Nodo* nodo){
	if((nodo->color =='R' && nodo->izq->color=='R')|| (nodo->color =='R' && nodo->der->color=='R') ){
		return 1;
	}else{
		return 0;
	}
	
}

void Arbol<T1,T2>::buscarPadre(Nodo & hijo){
	Nodo * aux=raiz;
	padre= aux;
	int donde=-1;
	while(aux->par->getLlave() !=  hijo.par.getLlave()){
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
		rotacionSimple();
		
	}else{
		rotacionDoble();
		
	}
	
}

/**
*/

void Arbol<T1,T2>::hayCFlip(Nodo * nodo){//se de puntero que indica que indica el lado a revisar
//llama a colorFlip() en caso de que necesite y le pasa el puntero a nodo de donde esta el problema
   
	if (nodo->izq!= 0){
			colorFlip(nodo);
			hayCFlip(nodo->izq);

	}

	if (nodo->der!=0){
		colorFlip(nodo);
		hayCFlip(nodo->der);

	}
	
}



/**
*/
void Arbol<T1,T2>::rotacionSimple(Nodo * padre, int lado){
	if(lado==0){//rotacion izquierda

		padre->der->izq= *(padre->izq->der);
		padre->izq->izq = new Nodo(padre->izq->par);
		padre->izq->par->setDato(0);
		padre->par->setLlave(padre->der->par->getLlave());
		Nodo * ptr = *(padre->der->der);
		padre->der->der=0;
		delete padre->der;
		padre->der= *ptr;
		//cout "Rotacion Simple Izquierda" : arbol
		recoloreo(padre);
		//cout "Recoloreo" :arbol
		
		
	}else{
		padre->izq->der= *(padre->der->izq);
		padre->der->der=new Nodo(padre->der->par);
		padre->der->par->setDato(0);
		padre->der->par->setLlave(padre->der->der->par->getLlave());
		Nodo * ptr= *(padre->izq->izq);
		padre->izq->izq=0;
		delete padre->izq;
		padre->izq= *ptr;
		//cout "Rotacion Simple Derecha" : arbol
		recoloreo(padre);
		//cout "Recoloreo" :arbol
		
		
	}
	
}

/**
*/
void Arbol<T1,T2>::rotacionDoble(Nodo * padre, int lado){
	if(lado==0 && padre->der->color=='R'){
		rotacionSimple(padre,1);
		roatcionSimple(padre,0);
		
	}else{
		rotacionSimple(padre,0);
		roatcionSimple(padre,1);
		
	}
	
}

/** este metodo se realiza despues de finalizar cualquier rotacion, el que paso a ser el padre y antes era el hijo se vuelve negro y sus hijos rojos
*/
void Arbol<T1,T2>::recoloreo(Nodo * padre){
	padre->color='N';
	padre->izq->color='R';
	padre->der->color='R';
	
}
/** metodo que cambia la raiz si esta es roja
*/
void Arbol<T1,T2>::cambioRaiz(){
	if(raiz->color=='R'){
	raiz->color='N';
	}
}

/** metodo el cual si encuentra un nodo negro con dos hijos rojos, el nodo negro pasa a ser rojo y sus hijos negros
*/
void Arbol<T1,T2>::colorFlip(Nodo * nodo){
	if(nodo->color=='N' && nodo->izq->color=='R' && nodo->der->color=='R'){
		 	nodo->color='R';
			nodo->izq->color='N';
			nodo->der->color='N'; 
	}
	
}

int Arbol<T1,T2>::esHoja(Nodo & nodo){
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
void Arbol<T1,T2>::insertar( const char * Archivo){
	
	
	
}