#include<stdio.h>

	int menu(int opcion){
	printf("\n ¿Que operacion quieres realizar?");
	printf("\n---------------------------------------MENU--------------------------------\n");
	printf("\n 1.-Dar de alta a los empleados  "); 
         printf ("\n 2.Eliminar a los empleados");
         printf("\n 3.Buscar a los empleados. ");
         printf("\n 4.-Modficar a los empleados. ");
        printf("\n 5.-Salir.");
        
        return opcion;
		}
		
int main(){	
		int opcion,n;
		int n1,i;
	char indise;
	struct empleados{
		char indice;
		char nombre[100];
		int edad;
		float sueldo;
		
	} empleados[10];
	
	do{
		menu(n);
      
        do{
        	printf("\n Introduce tu opcion:  ");
        	 scanf("%d",&opcion);
		}while(opcion<1||opcion>5);

switch(opcion){

     case 1:
	printf("Cuantos empleados deseas registrar:  ");
	scanf("%d",&n1);  fflush(stdin);
	
	for( i=0; i<n1;i++){
		printf("\n indice: "); scanf("%c",&empleados[i].indice); fflush(stdin);
		printf("Nombre del empleado: "); scanf("%s",&empleados[i].nombre);
		printf(" Edad: "); scanf("%d",&empleados[i].edad);
		printf("Sueldo:   "); scanf("%f",&empleados[i].sueldo);  fflush(stdin);
	}
	    printf("Tus empleados son: ");
		for( i=0; i<n1;i++){
		printf("\n indice: %c",empleados[i].indice); 
		printf("\n Nombre del empleado: %s",empleados[i].nombre); 
		printf("\n Edad: %d",empleados[i].edad); 
		printf("\n Sueldo: %f   ",empleados[i].sueldo); 
}
	
	
break;
}
	}while(opcion!=5);
	
	
	return 0;
}