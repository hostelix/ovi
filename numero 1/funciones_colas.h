#include <stdio.h>


typedef struct _nodo{
	int numero;
	struct _nodo *siguiente;
}Nodo;

typedef struct {
	Nodo *primero;
	Nodo *ultimo;
}Cola;

typedef Nodo *TNodo;
typedef Cola *TCola;

void app_cola(TCola *cola){
	TNodo nuevo;
	nuevo = (TNodo)malloc(sizeof(TNodo));
	nuevo->numero = rand()%10000000;
	nuevo->siguiente = NULL;
	
	if((*cola)->ultimo){
		(*cola)->ultimo->siguiente = nuevo;
	}
	
	(*cola)->ultimo = nuevo;
	
	if((*cola)->primero == NULL) (*cola)->primero = nuevo;
	
}

int del_cola(TCola *cola){
	TNodo nuevo;
	int tmp;
	
	nuevo = (*cola)->primero;
	
	if(nuevo == NULL){
		return 0;
	}
	
	(*cola)->primero = nuevo->siguiente;
	tmp = nuevo->numero;
	
	free(nuevo);
	if((*cola)->primero == NULL){
		(*cola)->ultimo = NULL;
	}
	return tmp;
	
}

void imprime(TCola *cola){
	TNodo tmp;
	int i=0;
	tmp = (*cola)->primero;
	while(tmp){
		printf("[%d]",tmp->numero);
		tmp = tmp->siguiente;
		i++;
	}
	printf("\n");
}

int cola_vacia(TCola *cola){
	TNodo tmp;
	int i=0;
	tmp = (*cola)->primero;
	while(tmp){
		tmp = tmp->siguiente;
		i++;
	}
	return i;
}

