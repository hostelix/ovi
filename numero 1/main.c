#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include "funciones_colas.h"
#include "funciones.h"


#define TIME_MAX 360
#define TIME_DADO 40

typedef struct{
	TCola cola;
}Tparametros;


int salir = 0;
int num_clientes = 0, sum_tiempo_atender = 0;
int num_clientes_tiempo_dado = 0;
time_t inicio, fin;
double tiempo_total = 0;
int pase = 0;


int verficar_tiempo(double tiempo){
	if(tiempo>=TIME_MAX){
		return 0;
	}
	return 1;
}


void *atender_cola(void* parametro){
	Tparametros *tmp = (Tparametros*)parametro;
	
	while(!salir && verficar_tiempo(tiempo_total)){
		
		if((tiempo_total >= TIME_DADO) && !pase){
			num_clientes_tiempo_dado = cola_vacia(&tmp->cola);
			pase = 1;
		}
		
		inicio = time(NULL);
		
		if(cola_vacia(&tmp->cola)){
			int x = del_cola(&tmp->cola);
			int tiempo = generar_tiempo();
		
			clear();
			gotoxy(10,10);
			
			printf("Nro [%d] - {Cliente atendido} -> Tiempo de atencion [%d]\n",x,tiempo);
			
			num_clientes++ ;
			sum_tiempo_atender+=tiempo;
			
			sleep(tiempo);
			
		}
		else{
			clear();
			gotoxy(10,20);
			printf("No hay clientes en la cola\n");
			sleep(1);
		}
		
		fin = time(NULL);
		
		tiempo_total+=difftime(fin,inicio);
	}
	
	return NULL;
}

void *llenar_cola(void* parametro){
	Tparametros *tmp = (Tparametros*)parametro;
	
	
	
	while(!salir && verficar_tiempo(tiempo_total)){
		inicio = time(NULL);
		
		sleep(generar_tiempo());
		
		gotoxy(10,30);
		printf("Ha llegado un cliente en la cola\n");
		app_cola(&tmp->cola);
		
		fflush(stdout);

		fin = time(NULL);
		
		tiempo_total+=difftime(fin,inicio);
	}
	
	printf("\n***************************************\n");
	printf("Tiempo de la simulacion: %d seg\n",(int)tiempo_total);
	printf("Numero de clientes antendidos: %d clientes \n",num_clientes);
	printf("Clientes que quedaron en la cola: %d clientes\n",cola_vacia(&tmp->cola));
	printf("Promedio de tiempo en atender 1 cliente: %d seg\n",(sum_tiempo_atender/num_clientes));
	printf("Numero de clientes en cola en determinado tiempo (%d seg) : %d clientes\n",TIME_DADO,num_clientes_tiempo_dado);
	printf("\n***************************************\n");
	
	return NULL;
}

int main() {

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

