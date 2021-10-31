#include <stdio.h>
void registro();

struct empleados{
		char ident;
		char nombre[100];
		int edad;
		float sueldo;
		
	} empleados[100];

int a=0;

int main (){
    int opcion;

    printf("Este programa administra los datos de los empleados de una empresa\n");

    do{
        printf("\n\n1.- Registrar nuevo empleado.\n");
        printf("2.- Eliminar empleado.\n");
        printf("3.- Buscar empleado.\n");
        printf("4.- Modificar datos de empleado.\n");
        printf("5.- Imprimir todos los registros.\n");
        printf("6.- Salir del menu.\n");
        printf("Seleccione la opcion deseada: ");
        scanf("%d", &opcion);
        switch (opcion){
        case 1:
            system("cls");
            registro();
            break;
        case 2:
            system("cls");
            /* code */
            break;
        case 3:
            system("cls");
            /* code */
            break;
        case 4:
            system("cls");
            /* code */
            break;
        case 5:
            system("cls");
            /* code */
            break;
        default:
            printf("\n\nOpcion no disponible\n\n");
            break;
        }
    } while (opcion!=6);

    system("cls");
    printf("\n\n        Hasta pronto");

    return 0;
}

void registro(){
    int n_registro, b=0;
    printf("Ingresa el numero de empleados a registrar:  ");
	scanf("%d",&n_registro);
    b = b + a;
    do{
        printf("\nIdenficador: ");
        scanf("%s",&empleados[b].ident);
		printf("Nombre: ");
        scanf("%s",&empleados[b].nombre);
		printf("Edad:   ");
        scanf("%d",&empleados[b].edad);
		printf("Sueldo: ");
        scanf("%.3f",&empleados[b].sueldo);
        fflush(stdin);
        b++;
        a++;
    } while (b<n_registro);
}

