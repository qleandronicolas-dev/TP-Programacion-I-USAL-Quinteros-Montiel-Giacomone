#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_NOMBRE 100
#define ESTANTE_MIN 1
#define ESTANTE_MAX 50
// --------- ESTRUCTURA ---------
typedef struct{
	char nombre[MAX_NOMBRE];
	char autor[MAX_NOMBRE];
	float precioReposicion;
	int numeroEstante;
	bool estadoPrestamo;
}libro;
// --------- DECLARACIONES ---------
libro cargarLibroValidado(void);
void agregarLibroArchivo(void);
void listarLibros (void);
void librosBorges(void);
void dividirLibrosDisponibles(void);
void menu(void);
// --------- MAIN ---------
int main(){
	menu();
	return 0;
}
// --------- FUNCIONES ---------
int presentacion(void){
    int o;
    printf("===========================\n");
    printf("=== GESTION DE BIBLIOTECA ===\n");
    printf("===========================\n\n");
    printf("1. Llenar datos de los libros.\n");
    printf("2. Listar datos registrados.\n");
    printf("3. Mostrar todos los libros de Borges.\n");
    printf("4. Separar libros disponibles de no disponibles.\n");
    printf("0. Finalizar programa.\n\n");
    printf("TU RESPUESTA: ");
    scanf("%d", &o);
    getchar();
    return o;
}

libro cargarLibroValidado(void){
    libro l;
    int prestamoRespuesta;

    do{
        printf("Ingrese el nombre del libro: ");
        fgets(l.nombre, MAX_NOMBRE, stdin);
        l.nombre[strcspn(l.nombre, "\n")] = '\0';
    } while (strlen(l.nombre) == 0);

    do{
        printf("Ingrese el autor del libro: ");
        fgets(l.autor, MAX_NOMBRE, stdin);
        l.autor[strcspn(l.autor, "\n")] = '\0';
    } while (strlen(l.autor) == 0);

    do{
        printf("Ingrese el numero de estante (%d a %d): ", ESTANTE_MIN, ESTANTE_MAX);
        scanf("%d", &l.numeroEstante);
    } while (l.numeroEstante < ESTANTE_MIN || l.numeroEstante > ESTANTE_MAX);

    do{
        printf("Ingrese un precio de reposicion (mayor a 0): ");
        scanf("%f", &l.precioReposicion);
    } while (l.precioReposicion <= 0);

    do{
        printf("Esta disponible? (1 = si / 0 = no): ");
        scanf("%d", &prestamoRespuesta);
    } while (prestamoRespuesta != 0 && prestamoRespuesta != 1);

    l.estadoPrestamo = (prestamoRespuesta == 1);
    getchar();
    return l;
}

void menu(void){
    int opcion;
    do{
        opcion = presentacion();
        switch (opcion){
            case 1:
                agregarLibroArchivo();
                break;
            case 2:
                listarLibros();
                break;
            case 3:
                librosBorges();
                break;
            case 4:
                dividirLibrosDisponibles();
                break;
            case 0:
                printf("El programa finalizo.\n");
                break;
            default:
                printf("OPCION NO VALIDA.\n\n");
                break;
        }
    } while (opcion != 0);
    return;
}
	
void agregarLibroArchivo(void){
	FILE *archivo;
	libro l;
	archivo = fopen("libros.txt", "a");
	if(archivo == NULL){
		printf("Error al abrir el archivo\n");
	}else{
		l =	cargarLibroValidado();
		fprintf(archivo, "%s;%s;%.2f;%d;%d\n", l.nombre,l.autor,l.precioReposicion,l.numeroEstante,l.estadoPrestamo);
		fclose(archivo);
		printf("libro guardado correctamente\n");
	}
}

void listarLibros(void){
	FILE *archivo;
	libro l;
	int estado;
	int cantidad=0;
	archivo = fopen("libros.txt","r");
	if(archivo==NULL){
		printf("No se pudo abrir el archivo");
	}else{
		while(fscanf(archivo," %99[^;];%99[^;];%f;%d;%d",  l.nombre,l.autor,&l.precioReposicion,&l.numeroEstante,&estado) == 5){
			l.estadoPrestamo=estado;
			printf("\nNombre: %s\n", l.nombre);
			printf("Autor: %s\n", l.autor);
			printf("Precio de reposicion: %.2f\n", l.precioReposicion);
			printf("Numero de estante: %d\n", l.numeroEstante);
			printf("Disponible: %s\n", l.estadoPrestamo?"SI" : "NO");
			cantidad++;
		}
		if(cantidad==0){
			printf("No hay libros guardados\n");
		}
		fclose(archivo);
	}
}

void dividirLibrosDisponibles(void){
    FILE *archivo = fopen("libros.txt", "r");
    FILE *disp = fopen("disponibles.txt", "w");
    FILE *nodisp = fopen("nodisponibles.txt", "w");
    libro l;
    int estado;

    if(archivo != NULL && disp != NULL && nodisp != NULL){
        while (fscanf(archivo," %99[^;];%99[^;];%f;%d;%d", l.nombre, l.autor, &l.precioReposicion, &l.numeroEstante, &estado) == 5){
            l.estadoPrestamo = estado;
            FILE *destino = l.estadoPrestamo ? disp : nodisp;
            fprintf(destino,"%s;%s;%.2f;%d;%d\n", l.nombre, l.autor, l.precioReposicion, l.numeroEstante, l.estadoPrestamo);
        }
        fclose(archivo);
        fclose(disp);
        fclose(nodisp);
        printf("Archivos separados correctamente.\n");
    }else{
        printf("Error al abrir archivos\n");
    }
    return;
}
void librosBorges(void){
	FILE *archivo = fopen("libros.txt", "r");
	libro l;
	int estado;
	if(archivo==NULL){
		printf("No se pudo abrir el archivo");
	}else{
		printf("\nLibros Borges\n");
		while(fscanf(archivo," %99[^;];%99[^;];%f;%d;%d", l.nombre, l.autor, &l.precioReposicion, &l.numeroEstante, &estado) == 5){
			l.estadoPrestamo = estado;
			if(strcmp(l.autor, "Borges") == 0){
				printf("\nNombre: %s\n", l.nombre);
				printf("Precio de reposicion: %.2f\n", l.precioReposicion);
				printf("Numero de estante: %d\n", l.numeroEstante);
				printf("Disponible: %s\n", l.estadoPrestamo?"SI" : "NO");
			}
		}
		fclose(archivo);
	}
}
