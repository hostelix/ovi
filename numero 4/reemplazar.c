#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
	int valor;
	struct _nodo *siguiente;
}Nodo;


typedef Nodo *TNodo;
typedef Nodo *Pila;

void app_pila(Pila *pila, int v){
	
	TNodo nuevo;

	nuevo = (TNodo)malloc(sizeof(Nodo));
	nuevo->valor = v;
	
	nuevo->siguiente = *pila;
	
	*pila = nuevo;	
}


int del_pila(Pila *pila){
	TNodo nodo; 
	int valor;      
	
	nodo = *pila;
	
	if(!nodo){ 
		return 0;
	}
	
	*pila = nodo->siguiente;
	
	valor = nodo->valor; 
	
	free(nodo);
	return valor;
}


void remplazar(Pila *pila, int viejo, int nuevo){
	TNodo nodo;
	
	nodo = *pila;
	
	while(nodo){
		if(nodo->valor == viejo){
			nodo->valor = nuevo;
		}
		nodo = nodo->siguiente;
	}
}

void mostrar(Pila *pila){
	TNodo nodo;
	
	nodo = *pila;
	
	while(nodo){
		printf("[%d]",nodo->valor);
		nodo = nodo->siguiente;
	}
	printf("\n");
}


int main(int argc, char *argv[]) {
	
	int op, num, num2;
	Pila nueva_pila = NULL;
	
	
	do{
		printf("============== remplazar =============\n");
		printf("1)Ingresar elementos a la pila\n");
		printf("2)Remplazar elementos\n");
		printf("3)Mostrar pila\n");
		printf("4)Salir\n");
		
		scanf("%d",&op);
		
		switch(op){
			case 1:
				do{
					printf("Introduce un numero.. Presione 0 para salir "); scanf("%d",&num);
					if(num != 0) app_pila(&nueva_pila,num);
				}while(num!=0);
			break;
			
			case 2:
				printf("Introduce el numero que buscara >");
				scanf("%d",&num);
				
				printf("Introduce el numero que remplazara>");
				scanf("%d",&num2);
				
				remplazar(&nueva_pila,num,num2);
			break;
			
			case 3:	
				mostrar(&nueva_pila);
			break;
			
			case 4:	
				exit(EXIT_SUCCESS);
			break;
		}
	}while(1);
	
	return 0;
}

