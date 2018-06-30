#ifndef PAR_EMPLANTILLADO
#define PAR_EMPLANTILLADO
#include<iostream>
#include <string>
using namespace std;
template< class T1, class T2 >
class Par {
	friend ostream& operator<<(ostream& salida, Par<T1,T2> par){
		salida << "("<< par.llave << "," << par.dato<< ")"<< endl;
		return salida;
	}
	
	friend istream& operator<<(istream& entrada, Par<T1,T2> * par){
		par->cargar(entrada);
		return entrada;
	}
	
	private:
  	  T1 llave;
	  T2 dato;
	public:
	  Par(T1 llave, T2 dato){
		this->llave = llave;
        this->dato = dato;		  
	  }
	  
	  Par(Par* par){
		  this->llave= par->llave;
		  this->dato = par->dato;
		  
	  }
	  
	  istream& cargar(istream& entrada){
		  entrada>>llave;
		  entrada>>dato;
		  return entrada;
	  }
	  
	  int operator> (const Par<T1,T2> * par){		 
		  if(this->llave >= par->llave){
			  return 1;
			  
		  }
		  else{
			  return 0;
		  }
	  }

		T1 getLlave(){
			return llave;
			
		}
		
		void setDato(T2 dato){
			this->dato=dato;
		}
		
		void setLlave(T1 llave){
			this->llave=llave;
			
		}
	  
	
	  
	  
	  
	  
};

//comparar cons copia destructor cargar sobrecargado




#endif