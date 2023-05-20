#ifndef _ESTRUCTURAS	//funciones para crear la libreria
#define _ESTRUCTURAS

/*								FORMATO DE LOS ARCHIVOS CSV												*/

/*	Los archivos son archivos de texto (".txt") en bloc de notas. El formato es (ejemplo del archivo Usuarios.txt):
											" 1,Perez Juan,20230512, "
		Los valores estan separados por coma, (IMPORTANTE) termina con una "," al final para evitar problemas varios
*/




/*								DEFINICION DE ESTRUCTURAS												*/

// Formato fecha: aaaa/mm/dd (Ejemplo: 20230513)	-	Formato periodo: aaaa/mm (Ejemplo: 202305)

struct usuarios{
	long idusuario,fechaalta;
	char apellidonombre[30];
	struct usuarios *sgte;
};

struct medxusuario{ //un usuario puede tener varios medidores, la estructura define a que usuario, y cuenta, le pertenece cada medidor
	long idusuario,idmedidor,idcuenta,fechaalta,fechabaja; //fechabaja puede ser: "0" si sigue en uso, o "mayor a 0" si el medidor esta dado de baja
	struct medxusuario *sgte;
};

struct medidores{ //Lista Enlazda Circular
	long idmedidor,numero;
	char modelo[20];
	struct medidores *sgte;
};

struct mediciones{
	long idcuenta,periodo,fechalectura;
	float lectura; //lectura: cantidad de metros cubicos que marca el medidor de esa cuenta
	struct mediciones *ant,*sgte; //Lista Doblemente Enlazada
};

struct facturas{
	long idcuenta,periodo,fechaemision; //fechaemision: tiene que ser la fecha del sistema cuando se ejecute el programa
	float consumo,totalapagar; //consumo: es el resultado de la resta entre la lectura actual menos la anterior, de esa cuenta - totalapagar: se debe crear la tabla de valores como explico el profe
	struct facturas *sgte;
};


/*									PROTOTIPOS DE PARA CREAR LAS LISTAS								*/

struct usuarios* lista_usuario();
struct medxusuario* lista_medxusuario();


/*									PROTOTIPOS PARA LAS FUNCIONES INSERTAR								*/

struct usuarios* insertar_usuario(struct usuarios*,struct usuarios*);
struct medxusuario* insertar_medxusuario(struct medxusuario*,struct medxusuario*);


void recorrer_usu(struct usuarios*);
void recorrer_medx(struct medxusuario*);

#endif

