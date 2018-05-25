#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct //estructura de la pelicula
{
	char titulo[50];
	int year;
	float nota;
}pelicula; 


void registrapeli( );//función para añadir peliculas al fichero
void mostrarpeli( ); //función para mostrar las peliculas que hay registradas
int devuelveN( ); //función para contar las peliculas que hay registradas
void ordenayear( ); //función para ordenar las peliculas por año
void ordenanota( ); //función para ordenar las peliculas por nota
void ordenatitulo( ); //función para ordenar las peliculas por titulo

int main()
{
	FILE *pvideoteca;
	int a,b; //opciones para los switch-case

	do
	{	
		devuelveN( );
		printf("Que desea hacer: 1:Registar, 2:Mostrar, 3:Ordenar, 4:Salir,\n");
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
				do
				{	
					printf("\n1: Por titulo, 2: Por a%co, 3: Por nota, 4:regresar \n", 164);
					scanf("%i",&b);
				
					switch(b)
					{	case 1:
							ordenatitulo( );
						break;
						
						case 2:
							ordenayear( );
						break;
					
						case 3:
							ordenanota( );
						break;
					
						case 4:
						printf("\nHas vuelto \n");
						break;

						default:
							printf("\nOpcion no disponible \n");
						break;
					}	
				}while(b=!4);
			break;
			
			case 4:
				printf("\nHa salido del programa con exito");
			break;		
			
			default:
				printf("\nOpcion no disponible \n");
			break;
		}
	}while(a!=4);
	return 0;
}



void registrapeli( ) 
{
	FILE *pfilmoteca;
	pelicula peli; //estructura de la pelicula
	pfilmoteca=fopen("Videoteca.txt","a"); //abrimos el fichero para añadir peliculas
	fflush(stdin); //limpiamos la entrada de texto
			
		printf("Titulo de la pelicula:\n");
		scanf("%[^\n]", peli.titulo);
		fprintf(pfilmoteca, "%s;\t\t\t", peli.titulo);
		
		printf("A%co en el que se estreno la pelicula:\n", 164);
		scanf("%d",&peli.year);
		fprintf(pfilmoteca, "%d;\t", peli.year);
		
		printf("Nota de la pelicula:\n");
		scanf("%f",&peli.nota);
		fprintf(pfilmoteca, "%.2f;\n", peli.nota);
		
	fclose(pfilmoteca); //cerramos el fichero
	printf("\nPelicula registrada correctamente.\n");
}



void mostrarpeli( )
{
	
	FILE *pfilmoteca;
	pelicula peli; //estructura de la pelicula
	
	pfilmoteca=fopen("videoteca.txt", "r"); //abrimos el fichero en modo lectura
	printf("\nTitulo\t\t\t\t\t A%co\t\tNota\n\n",164);
	
	
	while (feof(pfilmoteca) == 0) // Leemos el fichero hasta el final
	{  
		fscanf(pfilmoteca, "%[^;]; %i; %f; ", peli.titulo, &peli.year, &peli.nota);
		printf("%-40s %i\t\t%.2f\n",peli.titulo, peli.year, peli.nota);
	}
	fclose(pfilmoteca); //cerramos el fichero
}



int devuelveN( )
{
	FILE *pfilmoteca;
	int N=-1; //Al inicio: 1 linea vacia para leer bien el fichero
	char c; //para contar las lineas
	pfilmoteca = fopen("videoteca.txt", "r"); //abrimos el fichero en modo lectura
	while (fscanf(pfilmoteca, "%c", &c) != EOF) // Leemos el fichero hasta el final
	{
		if (c == '\n')
			N++; //Cada vez que encuentra un salto de linea suma 1 al numero de pelis
	}
	fclose(pfilmoteca); //cerramos el fichero
	printf("\nHay %d peliculas\n",N);
	return N;
}



void ordenatitulo( )
{
	int N=devuelveN( ); //Para saber el número de peliculas para el vector
	FILE *pfilmoteca;
	pfilmoteca = fopen("videoteca.txt", "r"); 
	pelicula peli[N]; //creamos un vector de peliculas
	pelicula aux; //Necesitamos una variable auxiliar de almacenamiento temporal
	int i=0, j=0;
	
	
	while (feof(pfilmoteca) == 0) //Primero leemos los datos
	{
		fscanf(pfilmoteca, "%[^;]; %i; %f;", peli[i].titulo, &peli[i].year, &peli[i].nota);
		i++;
	}
	
	printf("Peliculas ordenadas por titulo: \n",164);
	printf("\nTitulo\t\t\t\t\t A%co\t\tNota\n\n",164);
	
	for(i=0; i<=N-1; i++) //Ahora lo ordenamos
	{
		for(j=i+1; j<=N-1 ; j++) // Comparamos cada elemento con el siguiente
		{
			if (strcmp(peli[i].titulo, peli[j].titulo) > 0)
			{
			aux = peli[i];
			peli[i] = peli[j];
			peli[j] = aux;
			}
		}
		printf("%-40s %i\t\t%.2f",peli[i].titulo, peli[i].year, peli[i].nota);
	}	
	printf("\n");
	fclose(pfilmoteca); 
}



void ordenayear( )
{
	int N=devuelveN( ); 
	FILE *pfilmoteca;
	pfilmoteca = fopen("videoteca.txt", "r"); 
	pelicula peli[N];
	pelicula aux; //Necesitamos una variable auxiliar de almacenamiento temporal
	int i=0, j=0;
	
	while (feof(pfilmoteca) == 0) //Primero leemos los datos
	{
		fscanf(pfilmoteca, "%[^;]; %i; %f;", peli[i].titulo, &peli[i].year, &peli[i].nota);
		i++;
	}
	
	printf("Peliculas ordenadas por a%co: \n",164);
	printf("\nTitulo\t\t\t\t\t A%co\t\tNota\n\n",164);
	
	for(i=0; i<=N-1; i++) //Ahora lo ordenamos
	{
		for(j=i+1; j<=N-1 ; j++) // Comparamos cada elemento con el siguiente
		{
			if (peli[i].year > peli[j].year) //Si es mayor intercambiamos el contenido de los dos elementos
			{
				aux = peli[i]; 
				peli[i] = peli[j];
				peli[j] = aux;
			}
		}
		printf("%-40s %i\t\t%.2f",peli[i].titulo, peli[i].year, peli[i].nota);
	}
	printf("\n");
	fclose(pfilmoteca); 
}




void ordenanota( )
{
	int N=devuelveN( ); //Para saber el número de peliculas para el vector
	FILE *pfilmoteca;
	pfilmoteca = fopen("videoteca.txt", "r"); 
	pelicula peli[N]; //creamos un vector de peliculas
	pelicula aux; //Necesitamos una variable auxiliar de almacenamiento temporal
	int i=0, j=0;
	
	
	while (feof(pfilmoteca) == 0) //Primero leemos los datos
	{
		fscanf(pfilmoteca, "%[^;]; %i; %f;", peli[i].titulo, &peli[i].year, &peli[i].nota);
		i++;
	}
	
	printf("Peliculas ordenadas por nota: \n");
	printf("\nTitulo\t\t\t\t\t A%co\t\tNota\n\n",164);
	
	for(i=0; i<=N-1; i++) //Ahora lo ordenamos
	{
		for(j=i+1; j<=N-1 ; j++) // Comparamos cada elemento con el siguiente
		{
			if (peli[i].nota > peli[j].nota)//Si es mayor intercambiamos el contenido de los dos elementos
			{
			aux = peli[i];
			peli[i] = peli[j];
			peli[j] = aux;
			}
		}
		printf("%-40s %i\t\t%.2f",peli[i].titulo, peli[i].year, peli[i].nota);
	}
	printf("\n");
	fclose(pfilmoteca); 
}


