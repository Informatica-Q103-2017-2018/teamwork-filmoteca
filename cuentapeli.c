#include<stdio.h>
#include<math.h>
#define N 8

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
int cuentapeli(pelicula peli);

int main()
{
	FILE *pvideoteca;
	char a; // a para el switch
	int error,P;
	pelicula vcatalogo[N];
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
					P=cuentapeli(vcatalogo[N]);
					//printf("\n\n%d\n\n",P);
					mostrarpeli(vcatalogo[P]);
					error=1;
					break;
					
				default:
					printf("Opcion no disponible\n");
					error=-1;
					break;
			}
	}while(error<0);
	return 0;
}

void registrapeli(pelicula peli)
{
	FILE *pfilmoteca;
		pfilmoteca=fopen("Videoteca.txt","a");
		
			printf("Titulo de la pelicula:\n");
			scanf("%[^\n]", peli.titulo);
			fprintf(pfilmoteca, "%s ", peli.titulo);
			
			printf("Year en el que se estreno la peli:\n");
			scanf("%d",&peli.year);
			fprintf(pfilmoteca, "%d ", peli.year);
			
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
	printf("Titulo\t\t Year\t\t Nota\n");
		for (i = 0; i <=N ; i++) // Leemos el fichero línea a línea de cosas separadas por espacios
		{  
		fscanf(pfilmoteca, "%s %i %f", &peli.titulo, &peli.year, &peli.nota);
		printf("%s\t\t %i\t\t %.2f \n",peli.titulo, peli.year, peli.nota);
		}
	fclose(pfilmoteca);// Cerramos el fichero 
}

int cuentapeli(pelicula peli)
{
	FILE *pfilmoteca;
	int numpeli;//variable en la que almacenará el número de películas que va contando
	int tampeli;// variable que dirá el tamaño de la estructura que almacena las películas
	int tamfiche;//variable que dirá el tamaño de la película
	pfilmoteca = fopen("videoteca.txt", "r");
	fseek(pfilmoteca,0,SEEK_END);
	tamfiche=ftell(pfilmoteca);
	fseek(pfilmoteca,0,SEEK_SET);
	tampeli=sizeof(peli);
	numpeli=tamfiche/tampeli;
	fclose(pfilmoteca);
	printf("\n%d numero de pelis\n",numpeli);
	printf("%d size de la peli\n ",tampeli);
	printf("%d size del fichero ",tamfiche);
}
