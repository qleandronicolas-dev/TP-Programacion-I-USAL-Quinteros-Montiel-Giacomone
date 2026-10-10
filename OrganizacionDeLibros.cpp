#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_NOMBRE 100
typedef struct{
	char nombre[MAX_NOMBRE];
	char autor[MAX_NOMBRE];
	float precioReposicion;
	int numeroEstante;
	bool estadoPrestamo;
}libro;
//    -PROTOTIPOS-
libro cargarLibroValidado(void);

void menu();

int main(){
	menu();   //creo que el main no nesecita nada mas
	return 0;
}

int presentacion(int o){
	printf("===========================\n");
	printf("===GESTION DE BIBLEOTECA===\n");
	printf("===========================\n");
	printf("\n");
	printf("ELIJA ALGUNA DE LAS SIGUIENTES OPCIONES:\n");
	printf("\n");
	printf("1. Llenar datos de los libros.\n");
	printf("2. Listar datos registrados.");
	printf("3. Mostrar todos los libros de Borges.\n");
	printf("4. Separar libros disponibles de no disponibles.\n");
	printf("0. Finalizar programa.\n");
	printf("\n");
	printf("TU RESPUESTA: ");
	scanf("%d", o);                         //no estoy del todo seguro si esto esta bien, tengo q crear una variable nueva? creo que puedo usar punteros
	return o;
}
libro cargarLibroValidado(void) {
    libro l;
    int prestamoRespuesta;
 
    do {
        printf("Ingrese el nombre del libro: ");
        fgets(l.nombre, MAX_NOMBRE, stdin);
        l.nombre[strcspn(l.nombre, "\n")] = '\0';
    } while (strlen(l.nombre) == 0);
 
    do {
        printf("ingrese el autor del libro: ");
        fgets(l.autor, MAX_NOMBRE, stdin);
        l.autor[strcspn(l.autor, "\n")] = '\0';
    } while (strlen(l.autor) == 0);
 
    do {
        printf("  ingrese un precio de reposicion (mayor a 0): ");
        scanf("%f", &l.precioReposicion);
    } while (l.precioReposicion <= 0);
 //NO ENTENDÍ LO DE ESTANTE
	
    do {
        printf("  Esta disponible? (1 = si / 0 = no): ");
        scanf("%d", &prestamoRespuesta);
    } while (prestamoRespuesta != 0 && prestamoRespuesta != 1);
 
    l.estadoPrestamo = (prestamoRespuesta == 1);
 
    getchar(); 
 
    return l;
}
void menu(){
	int opcion = -1;                //no se si esto es nesesario
	//aca hacemos un switch         //
	opcion = presentacion(opcion);  //teniendo esto
	while(opcion!=0){
		switch(opcion){
			case 1:{
				
				//ocpion de llenar archivo con los libros de los estantes con tooooodos sus datos(validados)
				break;
			}
			case 2:{
				//opcion para listar todo lo del archivo
				break;
			}
			case 3:{
				//opcion para mostrar los libros de "BORGES"(validar) y sus datos
				break;
			}
			case 4:{
				//opcion para separar en dos archivos los libros disponibles(estadoPrestamo==true) y no disponibles(estadoPrestamo==false)
				break;
			}
			case 0:{
				//opcion para salir
				break;
			}
			default:{
				printf("OPCION NO VALIDA.\n\n");
				break;
			}
		}
 }
	return;
}
