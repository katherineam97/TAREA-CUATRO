#ifndef _ARBOL
#define _ARBOL
#include "Par.h"
#include <vector> // para el iterador
#include <iostream>
using namespace std;

template< class T1, class T2 >
class Arbol{
	private:
	//Atributos privados de Arbol
	 class Nodo{
		public:
		//Atributos publicos de nodo (clase interna de arbol)
		Nodo * izq;
		Nodo * der;
		char color;
		Par<T1,T2> * par;
		
/**Metodo constructor con paramentros de la clase nodo (clase interna de arbol)
 @param Par<T1,T2> *
*/		
 Nodo(Par<T1,T2> * par){
	 this->par=new Par<T1, T2>(par);
	 izq=0;
	 der=0;
	 color='\0';
 }
 
/**Metodo desconstructor de la clase nodo (clase interna de arbol)
*/
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
 
 /**Metodo que comprueba si el nodo que recibe de parametro es hoja (tiene una llave y un dato) o si es un nodo intermedio(tiene solo una llave)
    @param Nodo &
	@return 1 si es hoja , 0 si no lo es
 */
int esHoja(Nodo & nodo){
	if(nodo.der != 0 && nodo.izq != 0){
		return 0;//no es hoja
	}else{		
		return 1;
	}
	
}


 /**Metodo insertar de nodo: comprueba si el par a insertar es mayor o menor y dependiendo a eso va recorriendo el arbol hasta "encontrar un lugar"
Cuando encuentra un lugar, si la llave del par a insertar es menor entonces la llave de dicho par reemplazara el nodo que estaba
Ese nuevo nodo tendra de hijo izquierdo a el mismo y de hijo derecho la hoja que sen encontraba antes en la posicion que ocupo la llave del nuevo par
En caso de ser mayor, la hoja que se encontraba ahi se convertira en nodo intermedio(tendra solo llave) y de hijo izquierdo se tendra a el mismo(con dato y llave)
y de hijo derecho se tendra una hoja con el par que recibio de parametro
 @param Par<T1,T2> *
 */
void insertar(Par<T1,T2> * par){
   
	 if(!(*par > *(this->par)) && izq){ 
		 izq->insertar(par);//en caso de que el para sea menor llama recursivamente hasta encontrar un campo nulo (donde le corresponda) 
	 }else if(!izq && !(par->getLlave() > this->par->getLlave())){//insertar en lado izquierdo	
		
		 izq=new Nodo(par);//inserta de hijo izq el nuevo par
			
		 izq->color='N';//es una hoja por lo que es negra
		 der=new Nodo(this->par);//de hijo derecho va a tener una copia de si mismo
		
		 der->color='N';//es una hoja por lo que es negra
		 delete this->par;//el par del padre ahora va a ser el menor que en este caso fue le que recibio de param
		 this->par=0;
		 this->par = new Par<T1,T2>(par->getLlave(),0);
		
		 this->color='R';//el padre pasa a ser rojo
		 
	 }else if(par->getLlave() > this->par->getLlave() && der){
		 der->insertar(par);
		 
	 }else if(!der && par->getLlave() > this->par->getLlave()){//insertar en lado der

		  der=new Nodo(par);//inserta de hijo der el nuevo par
		  der->color='N';
		  izq=new Nodo(this->par);//de hijo derecho va a tener una copia de si mismo (el padre)
		  izq->color='N';
		  this->color='R';
		  this->par->setDato(0);
		  //el padre va a quedar igual porque este va a ser el caso en el que el haya tenido el menor
		 
	 }
	  
	 
 }
 
 /** Metodo que imprime el nodo Pre orden
 @param ostream&
  @return ostream&
 */
ostream& imprimir(ostream& salida){
    if(esHoja(*this)){
       salida <<this->color<<" "<<(*(this->par));
    }else{
    salida << this->color<<" "<<"("<<(this->par->getLlave())<<")"<<endl;

    }

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
	 
	//Atributos privados de arbol 
	 Nodo * padre;
	 Nodo * raiz;
	
public:

/**Metodo constructor por omision de Arbol
*/
Arbol(){
	raiz=0;
	padre=0;
	
}

/**Metodo desconstructor de Arbol 
llama al destructor de nodo, invocandolo con la raiz
*/
~Arbol(){
	if(raiz){
	  delete raiz;
	}
}
/** Metodo que indica el tipo de rotacion (en caso de haber)
En caso de que el hijo izquierdo del nodo 'problema' es rojo y el nodo 'problema' se encuentre a la izquierda sera una rotacion simple
Si no es rotacion simple se deduce es rotacion doble (debido a que se sabe, gracias al nodo que recibe de parametro, que en ese nodo hay algun problema/se necsita rotar)
 @param Nodo * , int
 @return tipo (tipo ==1 si es rotacion simple, tipo ==2 si es rotacion doble)

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

/**Metodo que recorre el arbol verificando si se encuentran dos rojos seguidos 
En caso de encontrar dos rojos seguidos, se retorna el primero de los dos nodos rojos seguidos, este sera considerado como el "nodo problema" 
Tambien en caso de encontrar dos rojos, se llamara al metodo de buscar padre que se encargue de buscar el padre del nodo problema y asi poder realizar la rotacion correspondiente
 @param Nodo* 
  @return Nodo *
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

 /**Metodo que verifica si hay dos rojos seguidos, si el nodo que recibe y alguno de sus hijos es rojo entonces indicara que si hay dos rojos seguidos
  @return 1 si hay dos rojos seguidos, 0 si no los hay 
 */
int rojosSeguidos(Nodo* nodo){
	if((nodo->color =='R' && nodo->izq->color=='R')|| (nodo->color =='R' && nodo->der->color=='R') ){
		return 1;
	}else{
		return 0;
	}
	
}


/**Metodo que busca el padre del nodo que recibe de parametro
Cuando se llama este metodo ya se sabe que hay un problema que necesita de algun tipo de rotacion por lo que este llama al metodo tipoRotacion() que 
dependiendo a lo que retorne se invocara al metodo de rotacionSimple o al metodo de rotacionDoble
 @param Nodo&

*/
void buscarPadre(Nodo & hijo){
	Nodo * aux=raiz;
	padre= aux;
	int donde=-1;
	
	while(aux->par->getLlave() !=  hijo.par->getLlave()){
		
            if(hijo.par->getLlave() > aux->par->getLlave()){
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
	if(tipoRotacion(aux, donde)== 1){
		
		rotacionSimple(padre, donde);
		
	}else{
		
		rotacionDoble(padre, donde);
		
		
	}
	
}

/**MEtodo que recorre el arbol revisando se se necesita hacer colorFlip, en caso de necesitarlo llama al metodo de ColorFlip
 @param Nodo*
*/

void hayCFlip(Nodo * nodo){//se de puntero que indica que indica el lado a revisar
//llama a colorFlip() en caso de que necesite y le pasa el puntero a nodo de donde esta el problema
	if (nodo->izq){
			colorFlip(nodo);
			hayCFlip(nodo->izq);
	}

	if (nodo->der){
		colorFlip(nodo);
		hayCFlip(nodo->der);
	}
	 
}



/**Metodo que dependiendo al numero que recibe identificara si se debe realizar una rotacion simple izquierda o una rotacion simple derecha
A partir del Nodo * padre que recibe (es apartir de aqui en donde se realizaran los cambios) se haran los cambios necesarios en los nodos (se reacomodara) para equilibrar el arbol
El Padre "adoptara" el hijo negro de su primer hijo rojo y despues el padre se convertira entonces en el hijo del primer rojo (tomara el lado del hijo que se le dio)
 @param Nodo* , int
 
*/
void rotacionSimple(Nodo * padre, int lado){
	if(lado==1){//rotacion izquierda
      cout<<"Rotacion izquierda"<<endl;
	//IZQUIERDA
		padre->izq->der= new Nodo(padre->der->izq->par);
        padre->izq->der->color='N';
		padre->izq->izq=new Nodo(padre->izq->par);
        padre->izq->izq->color='N';
		padre->izq->par->setDato(0);//borra el dato de un nodo para que sea una llave
		padre->par->setLlave(padre->der->par->getLlave());//asigna la llave del hijo al padre
		Nodo * ptr= (padre->der->der);
		padre->der->der=0;
		delete padre->der;//  
		padre->der= ptr;

		recoloreo(padre);
	
		
	}else{
		cout<<"Rotacion derecha"<<endl;
		padre->der->izq= new Nodo(padre->izq->der->par);
		padre->der->izq->color='N';
		padre->der->der = new Nodo(padre->der->par);
		padre->der->der->color='N';
		padre->der->par->setDato(0);
		padre->der->par->setLlave(padre->der->izq->par->getLlave());
		
		padre->par->setLlave(padre->izq->par->getLlave());
		
		Nodo * ptr = (padre->izq->izq);
		padre->izq->izq=0;
		delete padre->izq;
		padre->izq= ptr;

		recoloreo(padre);
			
	}
	
}

/**Metodo que se llama despues de reconocer que hay dos rojos seguidos en zig-zag 
Empezara a realizar los cambios a partir del nodo padre que recibe de parametro 
El segundo rojo encontrado (de los rojos seguidos) le cedera uno de sus hijos al padre (padre del primer rojo) y el otro al primer nodo rojo
despues el papa tomara el valor del segundo rojo 
 @param Nodo *,int
 
*/
void rotacionDoble(Nodo * padre, int lado){//yo izquierdo y mi hijo derecho rojo
	
	if(lado==0 && padre->izq->color=='R' && padre->izq->der->color=='R'){
		cout<<"Rotacion Doble Derecha"<<endl;
		padre->der->izq=new Nodo(padre->izq->der->der->par);
		padre->der->izq->color='N';
		padre->der->der=new Nodo(padre->der->par);
		padre->der->der->color='N';
		padre->der->par->setLlave(padre->par->getLlave());
		padre->der->color='N';
		padre->der->par->setDato(0);
		
		Nodo * ptr=padre->izq->der;
		padre->par->setLlave(padre->izq->der->par->getLlave());
		padre->color='R';
		
		padre->izq->der=0;
		padre->izq->der=new Nodo(ptr->izq->par);
		padre->izq->der->color='N';
		
		delete ptr;
		ptr=0;
		
		recoloreo(padre);
		
	}else if(lado==1 && padre->der->color=='R' && padre->der->izq->color=='R' ){
		cout<<"Rotacion Doble Izquierda"<<endl;
		padre->izq->der=new Nodo(padre->der->izq->izq->par);
		padre->izq->der->color='N';
		padre->izq->izq=new Nodo(padre->izq->par);
		padre->izq->izq->color='N';
		padre->izq->par->setDato(0);
		
		padre->izq->color='N'; //aqui
		padre->color='R'; //aqui
		
		padre->par->setLlave(padre->der->izq->par->getLlave());
		Nodo * nuevo=new Nodo(padre->der->izq->der->par);
		nuevo->color='N';
		Nodo * ptr= padre->der->izq;
		padre->der->izq=nuevo;
		delete ptr;
		ptr=0;
		
		recoloreo(padre); //aqui
	}
	
}

/** Este metodo se realiza despues de finalizar cualquier rotacion, el que paso a ser el padre y antes era el hijo se vuelve negro y sus hijos rojos
 @param Nodo *
*/
void recoloreo(Nodo * padre){
	padre->color='N';
	padre->izq->color='R';
	padre->der->color='R';
	
}
/** Metodo que cambia la raiz si esta es roja
*/
void cambioRaiz(){
	if(raiz->color=='R'){
		cout<<"Cambio Raiz"<<endl;
	raiz->color='N';
	}
}

/** metodo el cual si encuentra un nodo negro con dos hijos rojos, el nodo negro pasa a ser rojo y sus hijos negros
*/
void colorFlip(Nodo * nodo){
	if(nodo->izq && nodo->der){
		if(nodo->color=='N' && nodo->izq->color=='R' && nodo->der->color=='R'){
		  cout<<"hice color flip"<<endl;
	     	nodo->color='R';
			nodo->izq->color='N';
			nodo->der->color='N'; 
	}
	
	}

}


/**
Metodo que primeramente revisa si se debe realizar un cambio de raiz o color flip (si la raiz es diferente de null)
posteriormente llama al insertar de nodo con el mismo, y finaliza revisando si el arbol quedo de tipo rojo negro para relizar las siguientes modificaciones al no serlo (rotaciones)
 @param par 
*/

void insertar(Par<T1,T2> * par){
	int lado=0;
	
	
	if(raiz){
		cambioRaiz();
		if(raiz->der && raiz->izq){
			colorFlip(raiz);
			if(raiz->par->getLlave() > par->getLlave()){
			hayCFlip(raiz->izq);
			lado=1;
		}else{
			hayCFlip(raiz->der);
			lado=2;
		}

		}
	
		
		raiz->insertar(par);
		cout<<"Insertar Hoja "<<*par<<endl;
		if(lado==1){
			esRN(raiz->izq);
		}else if(lado==2){
			esRN(raiz->der);
		}
		
		
		
	}else{
		cout<<"insertar hoja"<<*par<<endl;
		raiz=new Nodo(par);
		raiz->color='N';
	}
	
}


/** Metodo que imprime el arbol, se sobrecarga el operator <<
 @param ostream&,Arbol<T1,T2>&
 @return ostream&
*/
friend ostream& operator<<(ostream& salida, Arbol<T1,T2>& arbol){
	if(arbol.raiz){
		arbol.raiz->imprimir(salida);  // Imprimir recursivamente a todo el arbol
	}
	return salida;
}
	
	
}; 
#endif
