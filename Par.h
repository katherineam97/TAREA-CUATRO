#ifndef PAR_EMPLANTILLADO
#define PAR_EMPLANTILLADO
#include<iostream>
#include <string>
using namespace std;
template< class T1, class T2 >
/**Clase  de plantilla*/
class Par {
	
/** Metodo que imprime el par, se sobrecarga el operator <<
 @param ostream&,Par<T1,T2>
 @return ostream&
*/
	friend ostream& operator<<(ostream& salida, Par<T1,T2>  par){
		salida << "("<< par.llave << "," << par.dato<< ")"<< endl;
		return salida;
	}
	
	
/** Metodo que carga un par, se sobrecarga el operator >>
 @param istream&,Par<T1,T2>
 @return istream&
*/	
	friend istream& operator>>(istream& entrada, Par<T1,T2> * par){
		par->cargar(entrada);
		return entrada;
	}
	
	private:
	//Atributos 
  	  T1 llave;
	  T2 dato;
	  
	public:
	
	/**Metodo constructor con parametros
	@param T1,T2
	*/
	  Par(T1 llave, T2 dato){
		this->llave = llave;
        this->dato = dato;		  
	  }
	  
	  /**Metodo contructor por copia
	  @param Par*
	  */
	  Par(Par* par){
		  this->llave= par->llave;
		  this->dato = par->dato;
		  
	  }
	  
	  /** Metodo que carga un par
		@param istream&
		@return istream&
	  */	
	  istream& cargar(istream& entrada){
		  entrada>>llave;
		  entrada>>dato;
		  return entrada;
	  }
	  
	  /** metodo sobrecargado que me dice si un par es mayor a otro
	  @param par&
	  */
	 int operator > (const Par<T1,T2> & par){		 
		  
		  if(this->llave >= par.llave){
			  return 1;
			  
		  }
		  else{
			  return 0;
		  }
	  }

		/**Metodo get que devuelve el dato del par
		@return dato
		*/
        T2 getDato(){
			return dato;
			
		}

		/**Metodo get que devuelve la llave del par
		@return llave
		*/
		T1 getLlave(){
			return llave;
			
		}
		
		/**Metodo set que le asigna de al dato del par lo que recibe de parametro
		*/
		void setDato(T2 dato){
			this->dato=dato;
		}
		
	  
};

#endif
