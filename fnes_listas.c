#include "fnes_insertar.c"

/*******************************FUNCION PARA CREAR LA LISTAS**********************************************/

/*Funcion para crear la lista de Usuarios a partir del Archivo Usuarios.txt*/
struct usuarios* lista_usuario(){
	FILE *usu;
	struct usuarios *nv=NULL,*L=NULL; //nv: nuevo nodo que se crea e inserta en la lista - L: puntero inicial de la lista
	char linea[1000],aux[100]; //linea: cadena que guarda los valores de cada linea del block de notas - aux: cadena que sirve para pasar los valores de "linea" a las variables de mi estructura
	int i,j;
	
	if((usu=fopen("Usuarios.txt","r"))!=NULL){
		while(!feof(usu)){
			nv = (struct usuarios *) malloc(sizeof(struct usuarios));
			i=0;
			j=0;
			
			fgets(linea,sizeof(linea),usu); //funcion para guardar una linea entera del bloc de notas
			
			memset(aux,0,100); //funcion para vaciar mi cadena "aux", (lo que hace es asignar el valor "\0" a todas las celdas de la cadena)
			while(linea[i]!=','){
				aux[j] = linea[i];
				j++; i++;
			}
			nv->idusuario = atol(aux); //atol: trasnforma una cadena en un numero "long" - asigna el primer valor de la linea de texto a la variable idusuario
			
			i++; j=0;
			memset(aux,0,100);
			while(linea[i]!=','){ //recorre la cadena "linea" hasta que encuentra una "," para así quedarme con el valor, en este caso "apellido y nombre"
				aux[j] = linea[i];
				j++; i++;
			}
			strcpy(nv->apellidonombre,aux);
			
			i++;j=0;
			memset(aux,0,100);
			while(linea[i]!=','){
				aux[j] = linea[i];
				j++; i++;
			}

			nv->fechaalta = atol(aux);
			
			nv->sgte = NULL;
			
			
			L = insertar_usuario(nv,L); //Inserta nv en la lista L
			nv = NULL;
		}
		
	}
	
	else
	printf("Error");
	
	fclose(usu); //cierra el archivo "Usuario.txt"
	
	return L; //retorna el puntero inicial al main
}


/*Funcion para crear la lista de medxusuario a partir del Archivo MedXUsuario.txt*/
struct medxusuario* lista_medxusuario(){
	FILE *medx; //puntero para el archivo "MedXUsuario.txt"
	struct medxusuario *nv=NULL,*L=NULL;
	char linea[1000],aux[100];
	int i,j;
	
	if((medx=fopen("MedXUsuario.txt","r"))!=NULL){
		while(!feof(medx)){
			nv = (struct medxusuario *) malloc(sizeof(struct medxusuario));
			i=0;
			j=0;
			
			fgets(linea,sizeof(linea),medx);
			
			memset(aux,0,100);
			while(linea[i]!=','){
				aux[j] = linea[i];
				j++; i++;
			}
			nv->idusuario = atol(aux);
			
			i++; j=0;
			memset(aux,0,100);
			while(linea[i]!=','){
				aux[j] = linea[i];
				j++; i++;
			}
			nv->idmedidor = atol(aux);
			
			i++;j=0;
			memset(aux,0,100);
			while(linea[i]!=','){
				aux[j] = linea[i];
				j++; i++;
			}
			nv->idcuenta = atol(aux);
			
			i++;j=0;
			memset(aux,0,100);
			while(linea[i]!=','){
				aux[j] = linea[i];
				j++; i++;
			}
			nv->fechaalta = atol(aux);
			
			i++;j=0;
			memset(aux,0,100);
			while(linea[i]!=','){
				aux[j] = linea[i];
				j++; i++;
			}
			nv->fechabaja = atol(aux);
			
			nv->sgte = NULL;
			
			L = insertar_medxusuario(nv,L);
			nv = NULL;
		}
	}
	else
		printf("Error");
	
	fclose(medx);
	
	return L;
}





/******************FUNCIONES PARA COMPROBAR SI FUNCIONA (esto no va estar dentro del codigo que presentemos)***************************/
void recorrer_usu(struct usuarios *r){
	if(r!=NULL){
		printf("%d\n",r->idusuario);
		printf("%s\n",r->apellidonombre);
		printf("%ld\n",r->fechaalta);
		recorrer_usu(r->sgte);
	}
}

void recorrer_medx(struct medxusuario *r){
	if(r!=NULL){
		printf("%d\n",r->idusuario);
		printf("%d\n",r->idmedidor);
		printf("%d\n",r->idcuenta);
		printf("%d\n",r->fechaalta);
		printf("%d\n",r->fechabaja);
		recorrer_medx(r->sgte);
	}
}
