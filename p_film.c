#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula;


//Faltan las funciones para ordenar por titulo, año y nota
//Tenemos las funciones para registrar, mostrar y contar pelis
void registrapeli( );
void mostrarpeli( );
int devuelveN( );
void ordenayear( );


int main()
{
	FILE *pvideoteca;
	int a;
	

	do
	{	devuelveN( );
		printf("Que desea hacer: 1:Registar, 2:Mostrar, 3:Salir, 4:Ordenar\n");
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
				printf("\nHa salido del programa con exito");
			break;
			
			case 4:
			ordenayear( );
			break;		
			
			default:
				printf("\nOpcion no disponible \n");
			break;
			}
	}while(a!=3);
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
		
		printf("Year en el que se estreno la peli:\n");
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
	printf("\nTitulo\t\t\t\tYear\tNota\n\n");
	
	
	while (feof(pfilmoteca) == 0)
		// Leemos el fichero línea a línea
		{  
		fscanf(pfilmoteca, "%[^\n] %i %f ", &peli.titulo, &peli.year, &peli.nota);
		printf("%s\n",peli.titulo, peli.year, peli.nota);
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
				printf("%s %i %.2f\n",peli[i].titulo, peli[i].year, peli[i].nota);
		}	
	fclose(pfilmoteca); 
	
}


