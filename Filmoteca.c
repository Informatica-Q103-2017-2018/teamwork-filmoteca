#include<stdio.h>
#include<math.h>
#define N 6

typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula;


//Funci?n ordenar por titulo
//Funci?n ordenar por nota
//Funci?n ordenar por g?nero
void registrapeli(pelicula peli);
void mostrarpeli(pelicula peli);


int main()
{
	FILE *pvideoteca;
	char a; // para el switch
	int error;
	pelicula vcatalogo[N];
	do{
		printf("\n");
	do
	{
		printf("Que desea hacer: R:Registar, M:Mostrar \n");
		scanf("%c",&a);
		fflush(stdin);
		switch (a)
			{
				case 'R':
				case 'r':	
					registrapeli(vcatalogo[N]);
					error=1;
				break;
					
				case 'm':
				case 'M':	
					mostrarpeli(vcatalogo[N]);
					error=1;
				break;
					
				default:
					printf("Opcion no disponible \n");
					error=-1;
				break;
			}
			fflush(stdin);
	}while(error<0);
	}while(error>0);
	return 0;
}



void registrapeli(pelicula peli)
{FILE *pfilmoteca;
			pfilmoteca=fopen("Videoteca.txt","a");
				
				printf("Titulo de la pelicula:\n");
				scanf("%[^\n]", peli.titulo);
				fprintf(pfilmoteca, "%s \n", peli.titulo);
				
				printf("Year en el que se estreno la peli:\n");
				scanf("%d",&peli.year);
				fprintf(pfilmoteca, "%d \t", peli.year);
				
				printf("Nota de la pelicula:\n");
				scanf("%f",&peli.nota);
				fprintf(pfilmoteca, "%.2f ", peli.nota);
				fprintf(pfilmoteca,"\n");
			
			fclose(pfilmoteca);
			printf("\n Pelicula registrada correctamente.");
}




void mostrarpeli(pelicula peli)
{
	FILE *pfilmoteca;
	int i;
	
	pfilmoteca = fopen("videoteca.txt", "r");
	printf("Titulo\n Year\t\t Nota \n\n");
	
		for (i = 0; i <=N ; i++) // Leemos el fichero línea a línea de cosas separadas por espacios
		{  
		fscanf(pfilmoteca, "%[^\n] ", &peli.titulo, &peli.year, &peli.nota);
		printf("%s",peli.titulo, peli.year, peli.nota);
		printf("\n");
		}
	fclose(pfilmoteca); 
	}


