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
	Par<T1,T2>(string tipo1,  string tipo2){
        if(((tipo1=="int")==0)&&((tipo2=="int")==0)){
            llave=0;
            dato=0;
        }else if(((tipo1=="int")==0)&&((tipo2=="char")==0)){
            llave=0;
            dato='\0';
        } else if(((tipo1=="int")==0)&&((tipo2=="double")==0)){
            llave=0;
            dato=0.0;
        }else if(((tipo1=="int")==0)&&((tipo2=="string")==0)){
            llave=0;
            dato="\0";
        } else if(((tipo1=="double")==0)&&((tipo2=="int")==0)){
            llave=0.0;
            dato=0;
        }else if(((tipo1=="double")==0)&&((tipo2=="char")==0)){
            llave=0.0;
            dato='\0';
        } else if(((tipo1=="double")==0)&&((tipo2=="double")==0)){
            llave=0.0;
            dato=0.0;
        }else if(((tipo1=="double")==0)&&((tipo2=="string")==0)){
            llave=0.0;
            dato="\0";
        }else if(((tipo1=="char")==0)&&((tipo2=="int")==0)){
            llave='\0';
            dato=0;
        }else if(((tipo1=="char")==0)&&((tipo2=="char")==0)){
            llave='\0';
            dato='\0';
        } else if(((tipo1=="char")==0)&&((tipo2=="double")==0)){
            llave='\0';
            dato=0.0;
        }else if(((tipo1=="char")==0)&&((tipo2=="string")==0)){
            llave='\0';
            dato="\0";
        }else if(((tipo1=="string")==0)&&((tipo2=="int")==0)){
            llave="\0";
            dato=0;
        }else if(((tipo1=="string")==0)&&((tipo2=="char")==0)){
            llave="\0";
            dato='\0';
        } else if(((tipo1=="string")==0)&&((tipo2=="double")==0)){
            llave="\0";
            dato=0.0;
        }else if(((tipo1=="string")==0)&&((tipo2=="string")==0)){
            llave="\0";
            dato="\0";
        }

		}
        
	
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
		
		/**Metodo set que le asigna de a la llave del par lo que recibe de parametro
		*/
		void setLlave(T1 llave){
			this->llave=llave;
			
		}	  
	  
};

#endif
