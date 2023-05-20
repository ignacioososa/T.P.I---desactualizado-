#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"

/**********************************FUNCION PARA INSERTAR NODOS A LAS LISTAS*******************************************/

/*Funcion para insertar nodos en la LES "usuarios"*/
struct usuarios* insertar_usuario(struct usuarios *p,struct usuarios *l){
	if(l != NULL){
		l->sgte = insertar_usuario(p,l->sgte);
	}
	else
		l = p;
	return l;
}

/*Funcion para insertar nodos en la LES "medxusuario"*/
struct medxusuario* insertar_medxusuario(struct medxusuario *p,struct medxusuario *l){
	if(l != NULL){
		l->sgte = insertar_medxusuario(p,l->sgte);
	}
	else
		l = p;
	return l;
}
