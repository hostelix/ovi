#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int valor;
	struct nodo *siguiente;
};

typedef struct nodo _nodo;

_nodo *crear_Lista(_nodo *apuntador);
_nodo *insertar(int valor, _nodo *apuntador);
_nodo *eliminar_elemento(int valor, _nodo *apuntador);
void imprimir_lista(_nodo *apuntador);
void borrar_ocurrencia(_nodo *apuntador, int valor);



int main(int argc, char *argv[]) {
	int op, numero;
	_nodo *inicioLista = NULL;

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

			borrar_ocurrencia(inicioLista,numero);
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


void borrar_ocurrencia(_nodo *apuntador, int valor){
	_nodo *apuntador_auxiliar;
	
	apuntador_auxiliar = apuntador;
	
	while(apuntador_auxiliar != NULL){
		if(apuntador_auxiliar->valor == valor){
			eliminar_elemento(valor,apuntador_auxiliar);
		}
		apuntador_auxiliar = apuntador_auxiliar->siguiente;
	}
}

/*aqui esta es la funcion que el ejercicio pide.*/
/*funcion para eliminar elementos de la lista*/
_nodo *eliminar_elemento(int valor, _nodo *apuntador){
	
		_nodo *indice,*cabeza;
		
		cabeza=apuntador;
		
		for(indice=cabeza; indice!=NULL; indice=indice->siguiente)
			
		{
			
			if(indice->valor==valor)
				
			{
				
				cabeza=cabeza->siguiente;
				
				
				
				if(apuntador==NULL || apuntador->siguiente==NULL){
					
					printf("ERROR, ya no hay m s datos\n");
				}
				
				else
					
					{
						
						cabeza->siguiente=indice->siguiente;
						
						free(indice);
						
					}
				
			}
			
		}
	
}
/*fin de la funcion eliminar nodo*/
