#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pa2m.h"

#define ERROR -1
#define OK 0

void probar_lista_crear(){
	lista_t* lista=lista_crear();
	pa2m_afirmar(lista!=NULL, "Se pudo crear la lista.");
	pa2m_afirmar(lista->cantidad==0, "La lista se crea vacia.");
	lista_destruir(lista);
}

void imprimir_lista(lista_t* lista){
	printf("\nLISTA:\n\n(Posicion):(elemento)\n");
	for(size_t i=0;i<lista->cantidad;i++){
		printf("\n%ld:%d\n",i,*(int*)lista_elemento_en_posicion(lista,i));
	}
}

void pruebas_insercion(){
	lista_t* lista=lista_crear();
	int e[]={0,1,2,3,4,5,6},i;
	bool insertar=true;
	for(i=0;i<7;i++)
		if (lista_insertar(lista,&e[i])==ERROR) insertar=false;
	pa2m_afirmar(insertar,"Se pudo insertar 7 elementos (del 0 al 6).");
	bool es_igual=true;
	for(i=0;i<lista->cantidad;i++)
		if(lista_elemento_en_posicion(lista,i)!=&e[i]) es_igual=false;

	pa2m_afirmar(es_igual,"Todos los elementos insertados son los correctos.");
	int un_elemento=4;
	pa2m_afirmar(lista_insertar_en_posicion(lista,&un_elemento,0)==OK,"Inserto un elemento (4) en la posicion inicial.");
	pa2m_afirmar(lista_elemento_en_posicion(lista,0)==&un_elemento,"El elemento inicial es el correcto.");
	int elemento2=10;
	pa2m_afirmar(lista_insertar_en_posicion(lista,&elemento2,lista->cantidad)==OK,"Inserto un elemento (10) en la posicion final.");
	pa2m_afirmar(lista_elemento_en_posicion(lista,lista->cantidad)==&elemento2,"El elemento final es el correcto.");
	int elemento=7;
	pa2m_afirmar(lista_insertar_en_posicion(lista,&elemento,100)==OK,"Puedo insertar un elemento (7) en una posicion que no existe.");
	pa2m_afirmar(lista_elemento_en_posicion(lista,lista->cantidad)==&elemento,"Si la posicion a insertar no existe inserta al final.");
	int otro_elemento=8;

	pa2m_afirmar(lista_insertar_en_posicion(lista,&otro_elemento,4)==OK,"Puedo insertar un elemento (8) en cualquier posicion (posicion 4).");
	pa2m_afirmar(lista_elemento_en_posicion(lista,4)==&otro_elemento,"El elemento insertado en la posicion indicada (4) es el correcto.");
	pa2m_afirmar(lista_elementos(lista)==11,"Se pudieron insertar 11 elementos.");
	pa2m_afirmar(lista->cantidad==11,"La lista tiene la cantidad de elementos correcta.");
	printf("Verifico los elementos insertados.\n");
	imprimir_lista(lista);
	
	lista_destruir(lista);
}

void probar_borrar_elemento(){
	lista_t* lista=lista_crear();
	int elemento=1;
	pa2m_afirmar(lista_insertar(lista,&elemento)==OK,"Inserto un elemento");
	pa2m_afirmar(lista_borrar(lista)==OK,"Se pudo borrar el elemento final.");
	pa2m_afirmar(lista_vacia(lista)==true,"La lista se queda vacia.");
	pa2m_afirmar(lista->cantidad==0,"La lista tiene la cantidad de elementos correcta.");
	pa2m_afirmar(lista_borrar(lista)==ERROR,"No puedo borrar en una lista vacia.");
	int e[]={0,1,2,3,4,5,6,7,8,9},i;
	bool insertar=true,borrar=true;
	for(i=0;i<10;i++)
		if (lista_insertar(lista,&e[i])==ERROR) insertar=false;
	pa2m_afirmar(insertar,"Se pudo insertar 10 elementos (del 0 al 9) en una lista vacia.");
	for(i=0;i<4;i++){
		if(lista_borrar(lista)==ERROR) borrar=false;
	}
	pa2m_afirmar(borrar,"Se pudo borrar al final correctamente 4 veces.");
	pa2m_afirmar(lista->cantidad==6,"La lista tiene la cantidad de elementos correcta.");
	lista_destruir(lista);
}

void probar_borrar_elemento_pos(){
	lista_t* lista=lista_crear();
	int e[]={0,1,2,3,4,5,6,7,8,9},i;
	bool insertar=true;
	for(i=0;i<10;i++)
		if (lista_insertar(lista,&e[i])==ERROR) insertar=false;
	pa2m_afirmar(insertar,"Inserto 10 elementos (del 0 al 9).");
	pa2m_afirmar(lista_borrar_de_posicion(lista,0)==OK,"Se pudo borrar el elemento en la posicion inicial.");
	pa2m_afirmar(lista_elemento_en_posicion(lista,0)==&e[1],"El elemento inicial es el correcto luego de borrar.");
	pa2m_afirmar(lista_borrar_de_posicion(lista,9)==OK,"Se pudo borrar el elemento en la posicion final.");
	pa2m_afirmar(lista_elemento_en_posicion(lista,lista->cantidad)==&e[8],"El elemento final es el correcto luego de borrar.");
	pa2m_afirmar(lista_borrar_de_posicion(lista,100)==OK,"Si la posicion no existe, borra en la posicion final.");
	pa2m_afirmar(lista_elemento_en_posicion(lista,lista->cantidad)==&e[7],"El elemento final es el correcto luego de borrar.");
	pa2m_afirmar(lista_borrar_de_posicion(lista,4)==OK,"Se pudo borrar en la posicion 4.");
	pa2m_afirmar(lista_elemento_en_posicion(lista,4)==&e[6],"El elemento en la posicion 4 es el correcto luego de borrar.");
	pa2m_afirmar(lista->cantidad==6,"La lista tiene la cantidad de elementos correcta.");
	lista_destruir(lista);
}


void probar_pila(){
	lista_t* lista=lista_crear();
	int e[]={0,1,2,3,4,5,6},i;
	bool apilar=true;
	for(i=0;i<7;i++)
		if (lista_apilar(lista,&e[i])==ERROR) apilar=false;
	pa2m_afirmar(apilar,"Apilo 7 elementos (del 0 al 6).");
	pa2m_afirmar(lista_tope(lista)==&e[6],"El tope es el correcto.");
	pa2m_afirmar(lista_desapilar(lista)==OK,"Desapilo un elemento de la pila.");
	pa2m_afirmar(lista_tope(lista)==&e[5],"El tope es el correcto.");
	pa2m_afirmar(lista_desapilar(lista)==OK,"Desapilo un elemento de la pila.");
	pa2m_afirmar(lista_tope(lista)==&e[4],"El tope es el correcto.");
	pa2m_afirmar(lista_desapilar(lista)==OK,"Desapilo un elemento de la pila.");
	pa2m_afirmar(lista_tope(lista)==&e[3],"El tope es el correcto.");
	pa2m_afirmar(lista_desapilar(lista)==OK,"Desapilo un elemento de la pila.");
	pa2m_afirmar(lista_tope(lista)==&e[2],"El tope es el correcto.");
	pa2m_afirmar(lista_desapilar(lista)==OK,"Desapilo un elemento de la pila.");
	pa2m_afirmar(lista_tope(lista)==&e[1],"El tope es el correcto.");
	pa2m_afirmar(lista_desapilar(lista)==OK,"Desapilo un elemento de la pila.");
	pa2m_afirmar(lista_tope(lista)==&e[0],"El tope es el correcto.");
	pa2m_afirmar(lista_desapilar(lista)==OK,"Desapilo el ultimo elemento de la pila.");
	pa2m_afirmar(lista_desapilar(lista)==ERROR,"No puedo desapilar de una pila vacia.");

	lista_destruir(lista);

}

void probar_cola(){
	lista_t* lista=lista_crear();
	int e[]={0,1,2,3,4,5,6},i;
	bool encolar=true;
	for(i=0;i<7;i++)
		if (lista_encolar(lista,&e[i])==ERROR) encolar=false;
	pa2m_afirmar(encolar,"Encolo 7 elementos (del 0 al 6).");
	pa2m_afirmar(lista_primero(lista)==&e[0],"El primer elemento es el correcto.");
	pa2m_afirmar(lista_desencolar(lista)==OK,"Desencolo un elemento de la cola.");
	pa2m_afirmar(lista_primero(lista)==&e[1],"El primer elemento es el correcto.");
	pa2m_afirmar(lista_desencolar(lista)==OK,"Desencolo un elemento de la cola.");
	pa2m_afirmar(lista_primero(lista)==&e[2],"El primer elemento es el correcto.");
	pa2m_afirmar(lista_desencolar(lista)==OK,"Desencolo un elemento de la cola.");
	pa2m_afirmar(lista_primero(lista)==&e[3],"El primer elemento es el correcto.");
	pa2m_afirmar(lista_desencolar(lista)==OK,"Desencolo un elemento de la cola.");
	pa2m_afirmar(lista_primero(lista)==&e[4],"El primer elemento es el correcto.");
	pa2m_afirmar(lista_desencolar(lista)==OK,"Desencolo un elemento de la cola.");
	pa2m_afirmar(lista_primero(lista)==&e[5],"El primer elemento es el correcto.");
	pa2m_afirmar(lista_desencolar(lista)==OK,"Desencolo un elemento de la cola.");
	pa2m_afirmar(lista_primero(lista)==&e[6],"El primer elemento es el correcto.");
	pa2m_afirmar(lista_desencolar(lista)==OK,"Desencolo un elemento de la cola.");
	pa2m_afirmar(lista_desencolar(lista)==ERROR,"No puedo desencolar de una cola vacia.");
	lista_destruir(lista);

}

void probar_null(){
	lista_t* lista=NULL;
	int e[]={0,1,2,3,4,5,6};
	pa2m_afirmar(lista_insertar(lista,&e[0])==ERROR,"No puedo insertar al final en una lista nula.");
	pa2m_afirmar(lista_insertar_en_posicion(lista,&e[1],4)==ERROR,"No puedo insertar en cualquier posicion en una lista nula.");
	pa2m_afirmar(lista_insertar_en_posicion(lista,&e[2],0)==ERROR,"No puedo insertar al inicio en una lista nula.");
	pa2m_afirmar(lista_apilar(lista,&e[3])==ERROR,"No puedo apilar en una lista nula.");
	pa2m_afirmar(lista_encolar(lista,&e[4])==ERROR,"No puedo encolar en una lista nula.");
}

void probar_it_externo(){
	lista_t* lista=NULL;
	lista_iterador_t* it=lista_iterador_crear(lista);
	pa2m_afirmar(it==NULL,"No puedo crear un iterador con una lista nula.");
	lista=lista_crear();
	it=lista_iterador_crear(lista);
	pa2m_afirmar(it!=NULL,"Puedo crear un iterador con una lista vacia.");
	pa2m_afirmar(lista_iterador_tiene_siguiente(it)==false,"Tiene siguiente devuelve false si la lista esta vacia.");
	pa2m_afirmar(lista_iterador_elemento_actual(it)==NULL,"El elemento actual de un iterador nulo cuando la lista esta vacia");
	lista_iterador_destruir(it);
	int e[]={0,1,2,3},i;
	size_t contador=0;
	bool insertar=true;
	for(i=0;i<4;i++)
		lista_insertar(lista,&e[i]); 
	it=lista_iterador_crear(lista);
	pa2m_afirmar(it!=NULL,"Puedo crear un iterador con una lista no vacia.");
	 for(it;
        lista_iterador_tiene_siguiente(it);
        lista_iterador_avanzar(it)){
	 	pa2m_afirmar(lista_iterador_tiene_siguiente(it),"Tiene siguiente devuelve true si hay un siguiente elemento.");
	 	pa2m_afirmar(lista_iterador_elemento_actual(it)!=lista->nodo_fin,"Iterador avanzar devuelve true si el elemento actual no es el ultimo.");
	 	contador++;
	 }
    pa2m_afirmar(lista->cantidad==contador,"Se iteran la misma cantidad de veces que la lista.");
	lista_iterador_destruir(it);
	lista_destruir(lista);

}
bool contar_impares(void* numero, void* contador){
	if(numero==NULL || contador==NULL) return false;
	int* un_numero=numero;
	int* un_contador=contador;
	if(*un_numero%2!=0){
		(*un_contador)++;
	}
	else return false;
	return true;
}

void probar_it_interno(){
	lista_t* lista=NULL;
	size_t contador=0;
	pa2m_afirmar(lista_con_cada_elemento(lista,contar_impares,(void*)&contador)==0,"El iterador devuelve error con una lista nula.");
	lista=lista_crear();
	pa2m_afirmar(lista_con_cada_elemento(lista,contar_impares,(void*)&contador)==0,"El iterador devuelve error con una lista vacia.");
	int e[]={1,2,3,4,5},i;
	bool insertar=true;
	for(i=0;i<5;i++)
		lista_insertar(lista,&e[i]);
	pa2m_afirmar(lista_con_cada_elemento(lista,false,(void*)&contador)==0,"El iterador devuelve error sin funcion de iteracion.");
	size_t elementos=0;
	elementos=lista_con_cada_elemento(lista,contar_impares,(void*)&contador);
	pa2m_afirmar(elementos=1,"El iterador devuelve la cantidad correcta.");

	lista_destruir(lista);
}



void main(){
	pa2m_nuevo_grupo("CREACION DE LISTA");
	probar_lista_crear();
	pa2m_nuevo_grupo("PRUEBAS DE INSERCION");
	pruebas_insercion();
	pa2m_nuevo_grupo("PRUEBAS DE BORRADO AL FINAL\n");
	probar_borrar_elemento();
	pa2m_nuevo_grupo("PRUEBAS DE BORRADO EN POSICION\n");
	probar_borrar_elemento_pos();
	pa2m_nuevo_grupo("PROBAR FUNCIONES DE PILA\n");
	probar_pila();
	pa2m_nuevo_grupo("PROBAR FUNCIONES DE COLA\n");
	probar_cola();
	pa2m_nuevo_grupo("PROBAR FUNCIONES DE COLA\n");
	probar_cola();
	pa2m_nuevo_grupo("PROBAR CON NULL\n");
	probar_null();
	pa2m_nuevo_grupo("PROBAR ITERADOR EXTERNO\n");
	probar_it_externo();
	pa2m_nuevo_grupo("PROBAR ITERADOR INTERNO\n");
	probar_it_interno();
}