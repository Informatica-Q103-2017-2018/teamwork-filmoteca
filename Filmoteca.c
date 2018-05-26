#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula;


//Faltan las funciones para ordenar por titulo
//Tenemos las funciones para registrar, mostrar, contar pelis y ordenar por año y año
void registrapeli( );
void mostrarpeli( );
int devuelveN( );
void ordenayear( );
void ordenanota( );
void ordenarportitulo();

int main()
{
	FILE *pvideoteca;
	int a,b;

	do
	{	devuelveN( );
		printf("Que desea hacer: 1:Registar, 2:Mostrar ultimas registradas, 3:Mostrar por orden, 4:Salir,\n");
		scanf("%i",&a);
		
		switch (a)
			{
			case 1:
				registrapeli( );
			break;
				
			case 2:
				mostrarpeli( );
			break;
			
			case 3:
				printf("\nPor orden de...\n");
				printf("\n 1:...fecha, 2:...nota, 3:...titulo, 4:Volver\n");
				scanf("%i",&b);
				switch(b)
				{
					case 1:
						ordenayear( );
					break;
					
					case 2:
						ordenanota( );
					break;
					
					case 3:
						ordenarportitulo();
						break;
						
					case 4:
						printf("Volviendo");
					break;
					}	
			break;
			
			case 4:
				printf("\nSaliendo");
			break;		
			
			default:
				printf("\nOpcion no disponible\n");
			break;
			}
	}while(a!=4);
	return 0;
}




void registrapeli( ) 
{
	FILE *pfilmoteca;
	pelicula peli;
	pfilmoteca=fopen("Videoteca.txt","a");
	fflush(stdin);
			
		printf("Titulo de la pelicula:\n");
		scanf("%[^\n]", peli.titulo);
		fprintf(pfilmoteca, "%s;\t\t\t", peli.titulo);
		
		printf("A%co en el que se estreno la peli:\n", 164);
		scanf("%d",&peli.year);
		fprintf(pfilmoteca, "%d;\t", peli.year);
		
		printf("Nota de la pelicula:\n");
		scanf("%f",&peli.nota);
		fprintf(pfilmoteca, "%.2f;\n", peli.nota);
		
	fclose(pfilmoteca);
	printf("\nPelicula registrada correctamente.\n");
}




void mostrarpeli( )
{
	FILE *pfilmoteca;
	pelicula peli;
	int i, c;
	
	pfilmoteca=fopen("videoteca.txt", "r");
	printf("\nTitulo\t\t\t\t\t A%co\t\tNota\n\n",164);
	
	
	while (feof(pfilmoteca) == 0)
		// Leemos el fichero línea a línea
		{  
		fscanf(pfilmoteca, "%[^;]; %i; %f; ", peli.titulo, &peli.year, &peli.nota);
		printf("%-40s %i\t\t%.2f\n",peli.titulo, peli.year, peli.nota);
		}
	fclose(pfilmoteca); 
}
	
	
int devuelveN( )
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
	printf("\nHay %d peliculas\n",N);
	return N;
}  
	
	



void ordenanota( )
{
	int N=devuelveN( );
	FILE *pfilmoteca;
	pfilmoteca = fopen("videoteca.txt", "r");
	pelicula peli[N];
	pelicula aux;
	int i=0, j=0;
	
	//Primero leemos los datos
		while (feof(pfilmoteca) == 0)
	{
		fscanf(pfilmoteca, "%[^;]; %i; %f;", peli[i].titulo, &peli[i].year, &peli[i].nota);
		i++;
	}
	
	
	printf("Peliculas ordenadas por año: \n");
	printf("\nTitulo\t\t\t\t\t A%co\t\tNota\n\n",164);
	//Ahora lo ordenamos
		for(i=0; i<=N-1; i++)
		{
			// Comparamos cada elemento con el siguiente
			for(j=i+1; j<=N-1 ; j++)
			{
				if (peli[i].nota > peli[j].nota)
				{
				//Si es mayor intercambiamos el contenido de los dos elementos
				aux = peli[i]; //Necesitamos una variable auxiliar de almacenamiento temporal
				peli[i] = peli[j];
				peli[j] = aux;
				}
			}
				printf("%-40s %i\t\t%.2f\n",peli[i].titulo, peli[i].year, peli[i].nota);
		}	
	fclose(pfilmoteca); 
	
}


void ordenayear( )
{
	int N=devuelveN( );
	FILE *pfilmoteca;
	pfilmoteca = fopen("videoteca.txt", "r");
	pelicula peli[N];
	pelicula aux;
	int i=0, j=0;
	
	//Primero leemos los datos
		while (feof(pfilmoteca) == 0)
	{
		fscanf(pfilmoteca, "%[^;]; %i; %f;", peli[i].titulo, &peli[i].year, &peli[i].nota);
		i++;
	}
	
	
	printf("Peliculas ordenadas por año: \n");
	printf("\nTitulo\t\t\t\t\t A%co\t\tNota\n\n",164);
	//Ahora lo ordenamos
		for(i=0; i<=N-1; i++)
		{
			// Comparamos cada elemento con el siguiente
			for(j=i+1; j<=N-1 ; j++)
			{
				if (peli[i].year > peli[j].year)
				{
				//Si es mayor intercambiamos el contenido de los dos elementos
				aux = peli[i]; //Necesitamos una variable auxiliar de almacenamiento temporal
				peli[i] = peli[j];
				peli[j] = aux;
				}
			}
				printf("%-40s %i\t\t%.2f\n",peli[i].titulo, peli[i].year, peli[i].nota);
		}	
	fclose(pfilmoteca); 
	
}

void ordenarportitulo()
{
		int N=devuelveN( );
	FILE *pfilmoteca;
	pfilmoteca = fopen("videoteca.txt", "r");
	pelicula peli[N];
	pelicula aux;
	int i=0, j=0;
	
	//Primero leemos los datos
		while (feof(pfilmoteca) == 0)
	{
		fscanf(pfilmoteca, "%[^;]; %i; %f;", peli[i].titulo, &peli[i].year, &peli[i].nota);
		i++;
	}
	printf("Peliculas ordenadas por año: \n");
	printf("\nTitulo\t\t\t\t\t A%co\t\tNota\n\n",164);
	//Ahora lo ordenamos
		for(i=0; i<=N-1; i++)
		{
			// Comparamos cada elemento con el siguiente
			for(j=i+1; j<=N-1 ; j++)
			{
				if (strcmp(peli[i].titulo,peli[j].titulo)>0)
				{
				aux = peli[i]; //Necesitamos una variable auxiliar de almacenamiento temporal
				peli[i] = peli[j];
				peli[j] = aux;
				}
			}
				printf("%-40s %i\t\t%.2f\n",peli[i].titulo, peli[i].year, peli[i].nota);
		}	
	fclose(pfilmoteca); 
}

