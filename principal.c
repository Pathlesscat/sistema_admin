#include<stdio.h>
#include<string.h>

int a=0, i, aux, aux1, aux2;
int cad_bus[10];
struct empleados{
	char indice;
	char nombre[100];
	int edad;
	float sueldo;
	int estado; //Saber si esta trabajando actualmente (1) o no (2)
}empleados[20];

void menu();
void imprimir();
void buscar();
void coincidencias(int coincid,int opcion);

int main(){	
	int opcion,n, n1;
	
	do{
		system("cls");
		menu();
        do{
        	printf("\n Operacion a realizar:  ");
        	scanf("%d",&opcion);
		}while(opcion<1||opcion>5);

		switch(opcion){

			case 1:
			printf("\nDetermine el numero de empleados que desea registrar:  ");
			scanf("%d",&n1);  fflush(stdin);
			n1=n1+a;
			
			for( i=a; i<n1;i++){
				printf("\nIndice: "); scanf("%c",&empleados[i].indice); fflush(stdin);
				printf("Nombre del empleado: "); gets(empleados[i].nombre);
				printf("Edad: "); scanf("%d",&empleados[i].edad);
				printf("Sueldo: "); scanf("%f",&empleados[i].sueldo);  fflush(stdin);
				empleados[i].estado=1;
				++a;
			}
			system("cls");
			printf("Listo");
			getchar();
				break;
			case 2:
				buscar(opcion);
				break;
			case 3:
				buscar(opcion);
				break;
			case 4:
				buscar(opcion);
				break;
			case 5:
				system("cls");
				printf("\nHasta pronto");
				getchar();
				break;
		}
	}while(opcion!=5);
	
	return 0;
}

void menu(){
	printf("\n--------------------------------MENU--------------------------------\n");
	printf("\n 1.- Dar de alta a los empleados  "); 
    printf("\n 2.- Eliminar empleados de la nomina");
    printf("\n 3.- Buscar empleados. ");
    printf("\n 4.- Modificar informacion de los empleados. ");
	printf("\n 5.- Salir.");
}

void imprimir(int i){
		printf("Indice: %c\n", empleados[i].indice);
		printf("Nombre: %s\n", empleados[i].nombre);
		printf("Edad: %d\n", empleados[i].edad);
		printf("Sueldo: %.2f\n\n", empleados[i].sueldo);
}

void buscar(int opcion){
	int bus,eda,eda1,eda2,est,sul,coincid=0;
	float sul1,sul2;
	do{
	system("cls");
	printf("Define la categoria de busqueda: \n");
	printf("1.- Indice \n");
	printf("2.- Nombre \n");
	printf("3.- Edad \n");
	printf("4.- Sueldo \n");
	if (opcion==3){
		printf("5.- Estado laboral \n");
	}
	scanf("%d",&bus); fflush(stdin);
	}while(bus>5||bus<1);

	switch (bus){
	case 1:
		system("cls");
		char ind;
		printf("Introduce el indice: ");
		scanf("%c",&ind); fflush(stdin);
		for ( i = 0; i < a; i++){
			if ((ind==empleados[i].indice)&&(empleados[i].estado==1)){
				printf("%d.-\n",coincid+1);
				imprimir(i);
				cad_bus[coincid]=i;
				++coincid;
			}
		}
		fflush(stdin);
		getchar();
		coincidencias(coincid,opcion);
		break;
	case 2:
		system("cls");
		char nom[100];
		printf("Introduce el nombre: ");
		gets(nom);
		for ( i = 0; i < a; i++){
			if ((strcmp(empleados[i].nombre, nom) == 0)&&(empleados[i].estado==1)){
				printf("%d.-\n",coincid+1);
				imprimir(i);
				cad_bus[coincid]=i;
				++coincid;
			}
		}
		fflush(stdin);
		getchar();
		coincidencias(coincid,opcion);
		break;
	case 3:
		do{		
			system("cls");
			printf("1.- Buscar por edad especifica \n");
			printf("2.- Buscar por rango de edad \n");
			scanf("%d",&eda);
			if (eda==1){
				printf("Determina la edad: ");
				scanf("%d",&eda1);
				for ( i = 0; i < a; i++){
					if ((eda1==empleados[i].edad)&&(empleados[i].estado==1)){
					printf("%d.-\n",coincid+1);
					imprimir(i);
					cad_bus[coincid]=i;
					++coincid;
					}
				}
				fflush(stdin);
				getchar();
				coincidencias(coincid,opcion);
			}
			else if(eda==2){
				printf("Edad minima: ");scanf("%d",&eda1);
				printf("Edad maxima: ");scanf("%d",&eda2);
				for ( i = 0; i < a; i++){
					if ((eda1<=empleados[i].edad)&&(eda2>=empleados[i].edad)&&(empleados[i].estado==1)){
					printf("%d.-\n",coincid+1);
					imprimir(i);
					cad_bus[coincid]=i;
					++coincid;
					}
				}
				fflush(stdin);
				getchar();
				coincidencias(coincid,opcion);
			}
		}while(eda>2||eda<1);
		
		break;
	case 4:
		do{		
			system("cls");
			printf("1.- Buscar por sueldo especifico \n");
			printf("2.- Buscar por rango de sueldo \n");
			scanf("%d",&sul);
			if (sul==1){
				printf("Determina el sueldo: ");
				scanf("%f",&sul1);
				for ( i = 0; i < a; i++){
					if ((sul1==empleados[i].sueldo)&&(empleados[i].estado==1)){
					printf("%d.-\n",coincid+1);
					imprimir(i);
					cad_bus[coincid]=i;
					++coincid;
					}
				}
				fflush(stdin);
				getchar();
				coincidencias(coincid,opcion);
			}
			else if(sul==2){
				printf("Sueldo minimo: ");scanf("%f",&sul1);
				printf("Sueldo maximo: ");scanf("%f",&sul2);
				for ( i = 0; i < a; i++){
					if ((sul1<=empleados[i].sueldo)&&(sul2>=empleados[i].sueldo)&&(empleados[i].estado==1)){
					printf("%d.-\n",coincid+1);
					imprimir(i);
					cad_bus[coincid]=i;
					++coincid;
					}
				}
				fflush(stdin);
				getchar();
				coincidencias(coincid,opcion);
			}
		}while(sul>2||sul<1);
		break;
	case 5:
		if (opcion!=3){
			buscar(opcion);
		}
		else{
			do{
			system("cls");
			printf("1.- Empleados actuales\n");
			printf("2.- Empleados pasados \n");
			scanf("%d",&est);
			switch (est){
			case 1:
				for ( i = 0; i < a; i++){
					if (empleados[i].estado==1){
					printf("%d.-\n",coincid+1);
					imprimir(i);
					cad_bus[coincid]=i;
					++coincid;
					}
				}
				fflush(stdin);
				getchar();
				coincidencias(coincid,opcion);
				break;
			case 2:
				for ( i = 0; i < a; i++){
					if (empleados[i].estado==2){
					printf("%d.-\n",coincid+1);
					imprimir(i);
					cad_bus[coincid]=i;
					++coincid;
					}
				}
				fflush(stdin);
				getchar();
				coincidencias(coincid,opcion);
				break;
			}
			} while (est>2||est<1);
		}
		break;
	}
}

void coincidencias(int coincid,int opcion){
	if (coincid==0){
		printf("No se encontraron coincidencias.");
		getchar();
		buscar(opcion);
	}

	else{
		if (opcion==2){
			printf("Seleccione el empleado que desea eliminar de la nomina: ");
			scanf ("%d", &aux);
			printf("Esta seguro de eliminar de la nomina a:\n");
			imprimir(cad_bus[aux-1]);
			printf("\nSi (1) No(2) Salir al menu principal(3): ");
			scanf("%d",&aux1);

			if (aux1==1){
				aux2=cad_bus[aux-1];
				empleados[aux2].estado=2;
				system("cls");
				printf("Listo");
				fflush(stdin);
				getchar();
			}
			else if(aux1==3){
				a=a;
			}
			else{
				coincidencias(coincid, opcion);
			}
		}
		else if (opcion==4){
			printf("Seleccione el empleado del que desea modificar datos: ");
			scanf ("%d", &aux);
			printf("Esta seguro de modificar los datos de:\n");
			imprimir(cad_bus[aux-1]);
			printf("\nSi (1) No(2)");
			scanf("%d",&aux1);

			if (aux1==1){
				printf("Determine el elemento que desea modificar:\n");
				printf("1.- Indice \n");
				printf("2.- Nombre \n");
				printf("3.- Edad \n");
				printf("4.- Sueldo \n");
				printf("5.- Salir al menu principal\n");
				scanf("%d", &aux);
		
				switch (aux)
				{
				case 1:
					fflush(stdin);
					printf("Indice actual: %c\n",empleados[cad_bus[aux-1]].indice);
					printf("Indice nuevo: ");
					scanf("%c",&empleados[cad_bus[aux-1]].indice); fflush(stdin);
					break;
				case 2:
					fflush(stdin);
					printf("Nombre actual: %s\n",empleados[cad_bus[aux-1]].nombre);
					printf("Nombre nuevo: ");
					gets(empleados[cad_bus[aux-1]].nombre);
					break;
				case 3:
					fflush(stdin);
					printf("Edad actual: %d\n",empleados[cad_bus[aux-1]].edad);
					printf("Edad nueva: ");
					scanf("%d",&empleados[cad_bus[aux-1]].edad);
					break;
				case 4:
					fflush(stdin);
					printf("Sueldo actual: %f\n",empleados[cad_bus[aux-1]].sueldo);
					printf("Sueldo nuevo: ");
					scanf("%f",&empleados[cad_bus[aux-1]].sueldo);
					break;
				case 5:
					main();
					break;
				default:
					coincidencias(coincid,opcion);
					break;
				}
			}
			else{
				main();
			}
		}
	}
	fflush(stdin);
	main();
}
