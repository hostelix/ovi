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
_nodo *eliminar_elemento(int valor, _nodo *apuntador);
void imprimir_lista(_nodo *apuntador);
/*fin de la declaracion de las funcines*/
int main(int argc, char *argv[]) {
	int op, numero;
	_nodo *inicioLista;

	inicioLista = crear_Lista(inicioLista);

	do{
		printf("1- insertar en lista\n");
		printf("2- mostrar elementos de la lista\n");
		printf("3- eliminar elemento de la lista\n");
		printf("4- Salir\n");
		scanf("%d", &op);

		if(op == 1){
			
			inicioLista = insertar(2, inicioLista);
			inicioLista = insertar(5, inicioLista);
			inicioLista = insertar(22, inicioLista);
			inicioLista = insertar(23, inicioLista);
			inicioLista = insertar(255, inicioLista);
		}	

		else if(op == 2){
			imprimir_lista(inicioLista);
		}

		else if(op == 3){
			printf("Ingrese un numero a eliminar\n");
			scanf("%d", &numero);

			eliminar_elemento(numero, inicioLista);
		}
	}while(op != 4);

	return EXIT_SUCCESS;
}

/*funcion para crear una lista*/
_nodo *crear_Lista(_nodo *apuntador){
	apuntador = NULL;
	
	return apuntador;
}
/*fin de la funcion crear*/


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

/*funcion que muestra los elementos de la lista*/
void imprimir_lista(_nodo *apuntador){
	_nodo *apuntador_auxiliar;

	apuntador_auxiliar = apuntador;

	printf("\n");
	printf("los valores de la lista son:\n\n");
	
	while(apuntador_auxiliar != NULL){
		printf("%d\n", apuntador_auxiliar->valor);
		apuntador_auxiliar = apuntador_auxiliar->siguiente;
	}
}
/*fin de la funcion imprimir*/


/*aqui esta es la funcion que el ejercicio pide.*/
/*funcion para eliminar elementos de la lista*/
_nodo *eliminar_elemento(int valor, _nodo *apuntador){
	/*variables puntero de tipo _nodo que me permitiran la manipulacion 
	de la lista*/
	_nodo *puntero_auxiliar, *nodo_anterior;

	/*posicionamos en el incio al puntero_auxiliar*/
	puntero_auxiliar = apuntador;
	/*nodo_anterior lo igualamos a NULL*/
	nodo_anterior = NULL;

	if(puntero_auxiliar->valor == valor){
		nodo_anterior = puntero_auxiliar;
		puntero_auxiliar = puntero_auxiliar->siguiente;
		nodo_anterior->siguiente = puntero_auxiliar->siguiente;
	
		free(puntero_auxiliar);
		return NULL;
	}
	
	/*ciclo que permite iterar la lista*/
	while(puntero_auxiliar != NULL && puntero_auxiliar->valor != valor){
		nodo_anterior = puntero_auxiliar;
		puntero_auxiliar= puntero_auxiliar->siguiente;
	}
	nodo_anterior->siguiente = puntero_auxiliar->siguiente;

	free(puntero_auxiliar);
}
/*fin de la funcion eliminar nodo*/
