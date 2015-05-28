#include <stdio.h>
#include <stdlib.h>


struct nodo{
	int valor;
	struct nodo *siguiente;
};

/*declaramos una variable _nodo de tipo de dato nodo que es la estructura*/
typedef struct nodo _nodo;

/*declaracion de las funciones para el manejo de la lista*/
_nodo *crear_Lista(_nodo *apuntador);
_nodo *insertar(int valor, _nodo *apuntador);
void imprimir_lista(_nodo *apuntador);
void ordenar_lista(_nodo *lista);
_nodo *mezcla2(_nodo *lista1, _nodo *lista2);

/*fin de la declaracion de las funcines*/
int main(int argc, char *argv[]) {
	int op, numero;
	_nodo *lista1, *lista2;

	lista1 = NULL;
	lista2 = NULL;

	do{
		printf("1- insertar en lista 1\n");
		printf("2- insertar en lista 2\n");
		printf("3- ordenar las listas\n");
		printf("4- mezclar listas\n");
		printf("5- Salir\n");
		scanf("%d", &op);

		switch(op){
			case 1:{
				do{
					printf("Introduce un numero.. Presione 0 para salir "); scanf("%d",&numero);
					if(numero != 0) lista1 = insertar(numero, lista1);
				}while(numero!=0);
				break;
			}
			case 2:{
				do{
					printf("Introduce un numero.. Presione 0 para salir "); scanf("%d",&numero);
					if(numero != 0) lista2 = insertar(numero, lista2);
				}while(numero!=0);
				break;
			}
			case 3:
				ordenar_lista(lista1);
				ordenar_lista(lista2);
				printf("Lista 1\n");
				imprimir_lista(lista1);
				printf("Lista 2\n");
				imprimir_lista(lista2);
			break;
			
			case 4:
				printf("Lista mezclada:\n");
				imprimir_lista(mezcla2(lista1, lista2));
		}
	}while(op != 5);

	return EXIT_SUCCESS;
}


/*funcion para insertar elementos en la lista*/
_nodo *insertar(int valor, _nodo *apuntador){

	_nodo *nuevo_apuntador, *apuntador_auxiliar;

	 nuevo_apuntador = (_nodo*)malloc(sizeof(_nodo));

	 if(nuevo_apuntador != NULL){

	 	nuevo_apuntador->valor = valor;
	 	nuevo_apuntador->siguiente = NULL;
	 
	 	if(apuntador == NULL){
	 		apuntador = nuevo_apuntador;
	 	}
	 	else{
	 		apuntador_auxiliar = apuntador;

	 		while(apuntador_auxiliar->siguiente != NULL){
	 			apuntador_auxiliar = apuntador_auxiliar->siguiente;
	 		}
	 		apuntador_auxiliar->siguiente = nuevo_apuntador;
	 	}
	 }

	 return apuntador;
}
/*fin de la funcion insertar*/


void imprimir_lista(_nodo *apuntador){
	_nodo *apuntador_auxiliar;

	apuntador_auxiliar = apuntador;

	
	while(apuntador_auxiliar != NULL){
		printf("[%d]", apuntador_auxiliar->valor);
		apuntador_auxiliar = apuntador_auxiliar->siguiente;
	}
	printf("\n");
}

void ordenar_lista(_nodo *lista)
{
	_nodo *actual , *siguiente;
	int t;
	
	actual = lista;
	while(actual->siguiente != NULL)
	{
		siguiente = actual->siguiente;
		
		while(siguiente!=NULL)
		{
			if(actual->valor > siguiente->valor)
			{
				t = siguiente->valor;
				siguiente->valor = actual->valor;
				actual->valor = t;          
			}
			siguiente = siguiente->siguiente;                    
		}    
		actual = actual->siguiente;
		siguiente = actual->siguiente;
	}
}


_nodo *mezcla2(_nodo *lista1, _nodo *lista2){
	_nodo *lista_final = NULL, *tmp = NULL;

	tmp = lista1;
	while(tmp != NULL){
		lista_final = insertar(tmp->valor,lista_final);
		tmp  = tmp->siguiente;
	}
	
	tmp = lista2;
	while(tmp != NULL){
		lista_final = insertar(tmp->valor,lista_final);
		tmp  = tmp->siguiente;
	}
	
	return lista_final;
}
