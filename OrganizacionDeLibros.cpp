#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NOMBRE 100
typedef struct{
	char nombre[MAX_NOMBRE];
	char autor[];
	double precioReposicion;
	int numeroEstante;
	bool estadoPrestamo;
}libro;

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
