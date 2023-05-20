#include "fnes_listas.c" //funcion para incluir los codigos/funciones de "fnes_listas", "fnes_insertar", "stdio.h", "string.h" y "stdlib.h"

void main(){
	struct usuarios *Lusuario=NULL;
	struct medxusuario *Lmedx=NULL;
	
	printf("\tPRUEBA\n");
	
	Lusuario = lista_usuario();
	
	recorrer_usu(Lusuario);

	
	Lmedx = lista_medxusuario();
	
	recorrer_medx(Lmedx);
	
}
