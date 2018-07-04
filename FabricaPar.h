#ifndef _FABRICAPAR
#define _FABRICAPAR
#include"ParMayor.h"
#include"Par.h"
#include<iostream>
#include<cstring>
using namespace std;

class FabricaPar
{
	public:
		ParMayor * getPar(const char * tipo1, const char * tipo2)
		{
			// TIPO1 ES INT
			if (strcmp(tipo1,"int") == 0)
			{
				if (strcmp(tipo2,"int") == 0)
				{
					Par<int,int> * parcito = new Par<int,int>;
					return parcito;
				}
				if (strcmp(tipo2,"double") == 0)
				{
					Par<int,double> * parcito = new Par<int,double>;
					return parcito;
				}
				if (strcmp(tipo2,"char") == 0)
				{
					Par<int,char> * parcito = new Par<int,char>;
					return parcito;
				}
				if (strcmp(tipo2,"string") == 0)
				{
					Par<int,string> * parcito = new Par<int,string>;
					return parcito;
				}
			}
			// TIPO 1 ES DOUBLE
			if (strcmp(tipo1,"double") == 0)
			{
				if (strcmp(tipo2,"int") == 0)
				{
					Par<double,int> * parcito = new Par<double,int>;
					return parcito;
				}
				if (strcmp(tipo2,"double") == 0)
				{
					Par<double,double> * parcito = new Par<double,double>;
					return parcito;
				}
				if (strcmp(tipo2,"char") == 0)
				{
					Par<double,char> * parcito = new Par<double,char>;
					return parcito;
				}
				if (strcmp(tipo2,"string") == 0)
				{
					Par<double,string> * parcito = new Par<double,string>;
					return parcito;
				}
			}
			// TIPO 1 ES CHAR
			if (strcmp(tipo1,"char") == 0)
			{
				if (strcmp(tipo2,"int") == 0)
				{
					Par<char,int> * parcito = new Par<char,int>;
					return parcito;
				}
				if (strcmp(tipo2,"double") == 0)
				{
					Par<char,double> * parcito = new Par<char,double>;
					return parcito;
				}
				if (strcmp(tipo2,"char") == 0)
				{
					Par<char,char> * parcito = new Par<char,char>;
					return parcito;
				}
				if (strcmp(tipo2,"string") == 0)
				{
					Par<char,string> * parcito = new Par<char,string>;
					return parcito;
				}
			}
			// TIPO 1 ES STRING
			if (strcmp(tipo1,"string") == 0)
			{
				if (strcmp(tipo2,"int") == 0)
				{
					Par<string,int> * parcito = new Par<string,int>;
					return parcito;
				}
				if (strcmp(tipo2,"double") == 0)
				{
					Par<string,double> * parcito = new Par<string,double>;
					return parcito;
				}
				if (strcmp(tipo2,"char") == 0)
				{
					Par<string,char> * parcito = new Par<string,char>;
					return parcito;
				}
				if (strcmp(tipo2,"string") == 0)
				{
					Par<string,string> * parcito = new Par<string,string>;
					return parcito;
				}
			}
		}
		
};
#endif