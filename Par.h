#ifndef PAR_EMPLANTILLADO
#define PAR_EMPLANTILLADO
#include<iostream>
using namespace std;
template< class T1, class T2 >
class Par {
	friend ostream& operator<<(ostream& salida, Par<T1,T2> par){
		salida << "("<< par.x << "," << par.y << ")"<< endl;
		return salida;
	}
	
	private:
  	  T1 x;
	  T2 y;
	public:
	  Par(T1 x, T2 y){
		this->x = x;
        this->y = y;		  
	  }
};






#endif