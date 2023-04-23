/*
Ingreso de valores numericos en dos Listas 
-- el programa genera los un listado de los numeros de las dos Listas
-- El programa genera un reporte de los numeros que han quedado en cada lista 
   despues de ser comparadas
-- el programa maneja dos apuntador por cada lista de numeros
*/

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct lista
{ 
	int numero;
	lista *ap_der; // apuntador Lista
	lista *ap_izq; // apuntador Lista
} *cola, *cab, *nuevo, *cab2, *cola2, *aux_nuevo,    	// punteros lista1
  *cola3, *cab3, *nuevo2, *cab4, *cola4, *aux_nuevo2;	// punteros lista2

void menu(void);
void ingresar1(void);  // se captura numeros en la lista 1
void ingresar2(void);  // se captura numeros en la lista 2
void mostrar1(void);   // se muestra el contenido de las dos (2) Listas
void mostrar_compara(void); // compara el contenido y muestra las Listas Resultado
void limpiar_lista(void);
void espera();

main()
{
	menu();
}

void menu(void)
{
	int y, opc;
	opc = 9;
	while ( opc != 0)
	{
		system("cls");
		cout<<"\n 1 Ingresar numero en Lista 1";
		cout<<"\n 2 Ingresar numero en Lista 2";
		cout<<"\n 3 Listar numeros Digitados "; 
		cout<<"\n 4 Compara y Lista los Numeros Resultados  "; 
		cout<<"\n ................          "; 
		cout<<"\n 5 Limpiar <Borrar> Lista  "; 
		cout<<"\n 0 Terminar";
		cout<<"\n Ingrese Opcion";
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				ingresar1();
				break;
			case 2:
				ingresar2();
				break;
			case 3:
				mostrar1();	  
				break;
			case 4:
				mostrar_compara();
				break;
			case 5:
				limpiar_lista();
				break;
			default:
				cout <<"\n Opcion no Valida !! ";
				break;
		}
	}
}

void ingresar1(void)
{
	// Ingresa los numeros en la lista 1
	// y los ordena en forma de "cola" utiliza dos apuntadores 
	
	int sw;
    
	// PRIMERA PARTE	
	nuevo = new(lista); // creamos nuevo Nodo
	fflush(stdin); // funsion para liberar la memoria 
	
	cout<<"\n"<<"Digite el numero  : ";
	cin >> nuevo->numero;
	nuevo->ap_der = NULL;
	nuevo->ap_izq = NULL;
	// las variable apuntador se inicia en NULL ... 
	fflush(stdin);
	
	//VERIFICAR SI HAY UNA LISTA CREADA
	if (!cab)
	{   // si la lista no esta creada ... la creamos
		// y asignamos los punteros a nuevo Nodo
		
		cab   = new(lista);		cola  = new(lista);
		cab2  = new(lista);		cola2  = new(lista);
		cab   = nuevo;  		cola = nuevo;
		cab2  = nuevo;  		cola2 = nuevo;

		cout <<"\n"<<"se creo la lista";
	}
    else
	{ 
	//  insertamos al final de la lista en forma de "COLA"	
  		cola->ap_der  = nuevo;
  		nuevo->ap_izq = cola;
   		cola          = nuevo;
   		cab2          = cola;
   		
	}
	espera(); //funcio para dar <Enter>	
}

void ingresar2(void)
{
	// Ingresa los numeros en la lista 2
	// y los ordena en forma de "cola" utiliza dos apuntadores 
	
	int sw;
    
	// PRIMERA PARTE	
	nuevo2 = new(lista); // creamos nuevo Nodo
	fflush(stdin); // funsion para liberar la memoria 
	
	cout<<"\n"<<"Digite el numero  : ";
	cin >> nuevo2->numero;
	nuevo2->ap_der = NULL;
	nuevo2->ap_izq = NULL;
	// las variable apuntador se inicia en NULL ... 
	fflush(stdin);
	
	//VERIFICAR SI HAY UNA LISTA CREADA
	if (!cab3)
	{   // si la lista no esta creada ... la creamos
		// y asignamos los punteros a nuevo Nodo
		cab3  = new(lista);		cola3  = new(lista);
		cab4  = new(lista);		cola4  = new(lista);
		cab3  = nuevo2;  		cola3  = nuevo2;
		cab4  = nuevo2;  		cola4  = nuevo2; 

		cout <<"\n"<<"se creo la lista";
	}
    else
	{ 
	//  insertamos al final de la lista en forma de "COLA"	
  		cola3->ap_der  = nuevo2;
  		nuevo2->ap_izq = cola3;
   		cola3          = nuevo2;
   		cab4           = cola3;
	}
	espera(); //funcio para dar <Enter>	
}

void mostrar1(void)  
{
   // mostramos el contenido de la Lista1
   if (!cab)
   {
      cout<<"no hay datos o la lista 1 no esta creada";
	  getch();	
   }	
   else
   {
   	  nuevo = new(lista);
   	  nuevo = cab;
   	  cout <<"\n"<<" Reporte de los numeros de la Lista 1"<<endl;
   	  while (nuevo != NULL)
   	  {
		 cout <<nuevo->numero<<"  ";
		 nuevo = nuevo->ap_der; 	
	  }
   }

   // mostramos el contenido de la Lista2
   if (!cab3)
   {
      cout<<endl<<endl<<"no hay datos o la lista 2 no esta creada";
	  getch();	
   }	
   else
   {
   	  nuevo2 = new(lista);
   	  nuevo2 = cab3;
   	  cout <<"\n"<<" Reporte de los numeros de la Lista 2"<<endl;
   	  while (nuevo2 != NULL)
   	  {
		 cout <<nuevo2->numero<<"  ";
		 nuevo2 = nuevo2->ap_der; 	
	  }
   }
   espera();   
}

void mostrar_compara(void)
{
   int encontro, dias;
   encontro = 0;
   if ((!cab) || (!cab3))
   {
      if (!cab)
	  {
	  	cout<<"no hay datos o la lista1 no esta creada";
	  	getch();
		}
	  if (!cab3)
	  {
	  	cout<<"no hay datos o la lista2 no esta creada";
	  	getch();
		}
   }	
   else
   {
	  nuevo = new(lista);   //Lista1
   	  nuevo = cab;
   	  
   	  nuevo2 = new(lista);  //Lista2
   	  nuevo2 = cab4;
   	  //recorremos la lista 1 en forma ascendente para ser comparada
   	  // y recorremos la List2 en forma descendente para ser comparada
   	  while ( nuevo != NULL && nuevo2 != NULL )
	  {
	  	 // si los # de las dos Lista son iguales
         if ( nuevo->numero == nuevo2->numero ) 
         {
         	if( nuevo == cab ) // si el numero a borrar es el primero de la lista
         	{
         	    cab  = cab->ap_der;   cola2 = cab;  //se mueven los punteros de la Lista1
         	    cab->ap_izq = NULL;
         	    
				cab4 = cab4->ap_izq;   //se mueven los punteros de la Lista2
				cab4->ap_der = NULL;
				cola3 = cab4;
				
				delete (nuevo);   // retiramos un nodo Lista1
				delete (nuevo2);  // retiramos un nodo Lista2
				nuevo  = cab; 	  //avanzamos el la Lista1 --- ascendente
				nuevo2 = cab4;    //avanzamos el la Lista2 --- descendente
			}
			else
			{ aux_nuevo  = new(lista);
			  aux_nuevo2 = new(lista);
			  // creamos dos(2) nodos para borrar en las listas
              // cuando no es, el primer nodo de estas
			  aux_nuevo  = nuevo;	aux_nuevo2 = nuevo2;
			  
			  nuevo      = nuevo->ap_der; // avanzo en la Lista1
			  nuevo2     = nuevo2->ap_izq; // avanzo en la Lista2
			  
			  // enlazamos la lista 1 dejando aislado en nodo a borrar
			  aux_nuevo->ap_izq->ap_der = nuevo;
			  nuevo->ap_izq = aux_nuevo->ap_izq;
			  delete(aux_nuevo); // retiramos el nodo de la Lista1
			  
			  // enlazamos la lista 2 dejando aislado en nodo a borrar
			  aux_nuevo2->ap_der->ap_izq = nuevo2;
			  nuevo2->ap_der = aux_nuevo2->ap_der;
			  delete(aux_nuevo2); // retiramos el nodo de la Lista2
			   				
			}
		 }
		 else
		 // si los # de las dos Lista NO son iguales avanzamos en las listas
		 {
			nuevo	= nuevo->ap_der;  // avanzamos en la lista1
			nuevo2  = nuevo2->ap_izq; // avanzamos en la Lista2
		 }
	  }
   }
   
   cout<<endl<<endl<<" mostramos los numeros resultados en lista1"<<endl;
   if (cab)
	{
		nuevo = new(lista);
   	  	nuevo = cab;
   	  	while (nuevo != NULL)
   	  	{
			cout <<nuevo->numero<<"  ";
		 	nuevo = nuevo->ap_der; 	
	  	}
	  	cout<<endl;
	}
	
	cout<<endl<<endl<<" mostramos los numeros resultados en lista2"<<endl;
   	if (cab3)
	{
		nuevo2 = new(lista);
   	  	nuevo2 = cab3;
   	  	while (nuevo2 != NULL)
   	  	{
			cout <<nuevo2->numero<<"  ";
		 	nuevo2 = nuevo2->ap_der; 	
	  	}
	  	cout<<endl<<endl;
	}
	espera();
}

void limpiar_lista(void)
{   //inicializamos los nodos de Inicio y Fin de la Lista
 	cab   = NULL;  	cola  = NULL;	
	cab2  = NULL;   cola2 = NULL;
		
	cab3  = NULL;   cola3 = NULL;
	cab4  = NULL;   cola4 = NULL;
}

void espera(void)
{
    cout <<"\n"<<"<Enter";
    getch();	
}
