#include<stdio.h>
#include<math.h>
#define N 2

typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula;


//Faltan las funciones para ordenar por titulo, año y nota
//Tenemos las funciones para registrar, mostrar y contar pelis
void registrapeli(pelicula peli);
void mostrarpeli(pelicula peli);




int main()
{
	FILE *pvideoteca;
	int a; // para el switch
	int error;
	pelicula vcatalogo[N];
	
	do
	{
		do
		{
			printf("\nQue desea hacer: 1:Registar, 2:Mostrar, 3:Salir\n");
			scanf("%i",&a);
			fflush(stdin);
			
			switch (a)
				{
					case 1:
						
						registrapeli(vcatalogo[N]);
					break;
						
					case 2:
						
						mostrarpeli(vcatalogo[N]);
					break;
					
					case 3:
						printf("\nHa salido del programa con exito");
					break;
					
					default:
						printf("\nOpcion no disponible\n");
					break;
				}
			fflush(stdin);
		}while(a!=3);
	}while(a!=3);
	return 0;
}




void registrapeli(pelicula peli) 
{
	FILE *pfilmoteca;
		pfilmoteca=fopen("Videoteca.txt","a");
			
			printf("Titulo de la pelicula:\n");
			scanf("%[^\n]", peli.titulo);
			fprintf(pfilmoteca, "%s;\t", peli.titulo);
			
			printf("Year en el que se estreno la peli:\n");
			scanf("%d",&peli.year);
			fprintf(pfilmoteca, "%d;\t", peli.year);
			
			printf("Nota de la pelicula:\n");
			scanf("%f",&peli.nota);
			fprintf(pfilmoteca, "%.2f;\n", peli.nota);
		
		fclose(pfilmoteca);
		printf("\nPelicula registrada correctamente.\n");
}




void mostrarpeli(pelicula peli)
{
	FILE *pfilmoteca;
	int i;
	
	pfilmoteca = fopen("videoteca.txt", "r");
	printf("\nTitulo\t\tYear\tNota\n\n");
	
		for (i = 0; i<=N ; i++) // Leemos el fichero línea a línea
		{  
		fscanf(pfilmoteca, "%[^\n] %i %f ", &peli.titulo, &peli.year, &peli.nota);
		printf("%s\t %i %.2f\n",peli.titulo, peli.year, peli.nota);
		}
	fclose(pfilmoteca); 
	}
	
	
	
