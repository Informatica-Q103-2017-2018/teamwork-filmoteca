#include<stdio.h>
#include<math.h>

typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula;

//Función ordenar por año
//Función ordenar por titulo
//Función ordenar por nota
//Función ordenar por género
void registrapeli(pelicula peli);

int main()
{
	FILE *pvideoteca;
	char a; // a para el switch
	int error;
	pelicula vcatalogo[100];
	do
	{
		printf("Que desea hacer: b:Registar, c:Buscar\n");
		scanf("%c",&a);
		switch (a)
			{
				case 'b':
					registrapeli(vcatalogo[0]);
					error=1;
					break;
				case 'c':
					//tatata
					error=1;
					break;
				default:
					printf("Opcion no disponible\n");
					error=-1;
					break;
			}
	}while(error<0);
}

void registrapeli(pelicula peli)
{FILE *pfilmoteca;
			pfilmoteca=fopen("Videoteca.txt","a");
				printf("Titulo de la pelicula:\n");
				scanf("%s", &peli.titulo);
				fprintf(pfilmoteca, " Titulo: %s \n", peli.titulo);
				printf("Year en el que se estreno la peli:\n");
				scanf("%d",&peli.year);
				fprintf(pfilmoteca, "Año: %d \n", peli.year);
				printf("Nota de la pelicula:\n");
				scanf("%f",&peli.nota);
				fprintf(pfilmoteca, "Nota: %.2f \n", peli.nota);
			fclose(pfilmoteca);
}	
//123
//sadfgh
