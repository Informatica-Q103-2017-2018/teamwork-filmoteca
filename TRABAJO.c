#include<stdio.h>
#include<math.h>

typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula;

//Funci?n ordenar por a?o
//Funci?n ordenar por titulo
//Funci?n ordenar por nota
//Funci?n ordenar por g?nero
void registrapeli(pelicula peli);

int main()
{
	FILE *pvideoteca;
	char a; // a para el switch
	int error;
	pelicula vcatalogo[100];
	do
	{
		printf("Que desea hacer: R:Registar, B:Buscar\n");
		scanf("%c",&a);
		switch (a)
			{
				case 'r':
				case 'R':
					registrapeli(vcatalogo[0]);
					error=1;
					break;
				case 'b':
				case 'B':	
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
				fprintf(pfilmoteca, "A?o: %d \n", peli.year);
				printf("Nota de la pelicula:\n");
				scanf("%f",&peli.nota);
				fprintf(pfilmoteca, "Nota: %.2f \n", peli.nota);
			fclose(pfilmoteca);
}	
