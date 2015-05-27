#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include "funciones_colas.h"

typedef struct{
	TCola cola;
}Tparametros;

int salir = 0;


void atender_cola(void* parametro){
	Tparametros *tmp = (Tparametros*)parametro;
	
	while(!salir){
		
		if(cola_vacia(&tmp->cola)){
			int x = del_cola(&tmp->cola);
		
			printf("Cliente atendido [%d]\n",x);
			usleep(x);
			fflush(stdout);
		}
		else{
			printf("No hay clientes en la cola\n");
			fflush(stdout);
		}
	}
	/*raise(SIGINT);*/
}

void llenar_cola(void* parametro){
	Tparametros *tmp = (Tparametros*)parametro;
	
	while(!salir){
		
		printf("Cliente nuevo en la cola \n");
		app_cola(&tmp->cola);
		fflush(stdout);
		sleep(10);
	}
	
	
}

int main() {

	int i;
	Tparametros *p = (Tparametros*)malloc(sizeof(Tparametros));
	
	pthread_t hilo_cajero,hilo_llegada;
	
	srand(time(NULL));
	
	p->cola=(TCola)malloc(sizeof(TCola));
	p->cola->primero = NULL;
	p->cola->ultimo = NULL;
	
	pthread_create(&hilo_cajero , NULL , atender_cola,(void *)p);
	pthread_create(&hilo_llegada , NULL , llenar_cola,(void *)p ) ;
	
	pthread_join(hilo_cajero,NULL);
	pthread_join(hilo_llegada,NULL);
	
	return 0;
}

