#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_NOMBRE 100
typedef struct{
	char nombre[MAX_NOMBRE];
	char autor[];
	float precioReposicion;
	int numeroEstante;
	bool estadoPrestamo;
}libro;

libro cargarLibroValidado(void) {
    libro l;
    int prestamoRespuesta;
 
    do {
        printf("  Nombre del libro: ");
        fgets(l.nombre, MAX_NOMBRE, stdin);
        l.nombre[strcspn(l.nombre, "\n")] = '\0';
    } while (strlen(l.nombre) == 0);
 
    do {
        printf("  Autor: ");
        fgets(l.autor, MAX_NOMBRE, stdin);
        l.autor[strcspn(l.autor, "\n")] = '\0';
    } while (strlen(l.autor) == 0);

	//no entendi lo de estante
    do {
        printf("  Precio de reposicion (mayor a 0): ");
        scanf("%f", &l.precioReposicion);
    } while (l.precioReposicion <= 0);
 
    do {
        printf("  Esta disponible? (1 = si / 0 = no): ");
        scanf("%d", &prestamoRespuesta);
    } while (prestamoRespuesta != 0 && prestamoRespuesta != 1);
 
    l.estadoPrestamo = (prestamoRespuesta == 1);
 
    getchar(); 
 
    return l;
}
void menu();

int main(){
	menu();   //creo que el main no nesecita nada mas
	return 0;
}

void menu(){
	//aca hacemos un switch
	//ocpion de llenar archivo con los libros de los estantes con tooooodos sus datos(validados)
	//opcion para listar todo lo del archivo
	//opcion para mostrar los libros de "BORGES"(validar) y sus datos
	//opcion para separar en dos archivos los libros disponibles(estadoPrestamo==true) y no disponibles(estadoPrestamo==false)
	//opcion para salir
	return;
}
