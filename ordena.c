#include<stdio.h>
#include<math.h>

typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula;


//Faltan las funciones para ordenar por titulo, año y nota
//Tenemos las funciones para registrar, mostrar y contar pelis
void registrapeli(pelicula peli);
void mostrarpeli(pelicula peli, int N);
int devuelveN(pelicula peli);//Función que cuenta pelis devolviendo el valor N
void ordenarporyear(pelicula peli,int N);

int main()
{
	FILE *pvideoteca;
	int a, N=0, error;
	pelicula vcatalogo[N];
	do
	{
		do
		{
			N=devuelveN(vcatalogo[N]);
			printf("\nNumero de peliculas: %d\n",N);
			printf("Que desea hacer: 1:Registar, 2:Mostrar, 3:Salir,4:Ordenar\n");
			scanf("%i",&a);
			fflush(stdin);
			
			switch (a)
				{
					case 1:
						
						registrapeli(vcatalogo[N]);
					break;
						
					case 2:
						
						mostrarpeli(vcatalogo[N], N);
					break;
					
					case 3:
						printf("\nHa salido del programa con exito");
						break;
					case 4:
						printf("\nLas películas ordenadas por year:\n");
						ordenarporyear(vcatalogo[N],N);
						mostrarpeli(vcatalogo[N], N);
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
			fprintf(pfilmoteca, "%s;\t\t", peli.titulo);
			
			printf("Year en el que se estreno la peli:\n");
			scanf("%d",&peli.year);
			fprintf(pfilmoteca, "%d;\t", peli.year);
			
			printf("Nota de la pelicula:\n");
			scanf("%f",&peli.nota);
			fprintf(pfilmoteca, "%.2f;\n", peli.nota);
		
		fclose(pfilmoteca);
		printf("\nPelicula registrada correctamente.\n");
}

void mostrarpeli(pelicula peli, int N)
{
	FILE *pfilmoteca;
	int i;
	
	pfilmoteca = fopen("videoteca.txt", "r");
	printf("\nTitulo\t\t\tYear\tNota\n\n");
	
		for (i = 0; i<N ; i++) // Leemos el fichero línea a línea
		{  
		fscanf(pfilmoteca, "%[^\n] %i %f ", &peli.titulo, &peli.year, &peli.nota);
		printf("%s\n",peli.titulo, peli.year, peli.nota);
		}
	fclose(pfilmoteca); 
	}
	
int devuelveN(pelicula peli)
{
	FILE *pfilmoteca;
	int N=0;
	char c;
	pfilmoteca = fopen("videoteca.txt", "r");
	while (fscanf(pfilmoteca, "%c", &c) != EOF)
	{
		if (c == '\n')
			N++;
	}
	fclose(pfilmoteca); 
	return N;
}  
	
void ordenarporyear(pelicula peli,int N)
{
	FILE *pfilmoteca;
	pfilmoteca = fopen("videoteca.txt", "r");
	int i=0,j=0;
	pelicula peli_i[N],peli_j[N];
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if (peli_i[N].year<peli_j[N].year)
				peli_j[N].year=peli_i[N].year;		
		}
	}
	fclose(pfilmoteca); 
}
