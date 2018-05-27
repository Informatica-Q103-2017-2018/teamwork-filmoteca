#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula;


void registrapeli( );
void mostrarpeli( );
int devuelveN( );
void ordenayear( );
void ordenanota( );
void ordenatitulo( );
void buscapeli( );

int main()
{
	FILE *pvideoteca;
	int a,b;
	printf("\n*****BIENVENIDO A SU FILMOTECA*****\n");
	do
	{	devuelveN( );
		printf("\nQue desea hacer: 1:Registrar, 2:Mostrar pelis, 3:Buscar, 4:Ordenar, 5:Salir\n");
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
				buscapeli( );
			break;		
				
			case 4:
				do
				{
					printf("\n1:Por fecha, 2:Por nota, 3:Por titulo, 4:Volver\n");
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
							ordenatitulo( );
						break;
							
						case 4:
							printf("\nVolviendo.\n");
						break;
					}	
				} while(b!=4);
			break;
					
			case 5:
				printf("\nHas salido del programa.");
			break;		
			
			default:
				printf("\nOpcion no disponible.\n");
			break;
		}
	} while(a!=5);
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
		fprintf(pfilmoteca, "\n%s;\t\t\t", peli.titulo);
		
		printf("A%co en el que se estreno la peli:\n", 164);
		scanf("%d",&peli.year);
		fprintf(pfilmoteca, "%d;\t", peli.year);
		
		printf("Nota de la pelicula:\n");
		scanf("%f",&peli.nota);
		fprintf(pfilmoteca, "%.2f;", peli.nota);
		
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
	printf("\nHay %d peliculas.\n",N);
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
	
	
	printf("\nPeliculas ordenadas por nota: \n");
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
	pelicula aux;
	int i=0, j=0;
	
	//Primero leemos los datos
		while (feof(pfilmoteca) == 0)
	{
		fscanf(pfilmoteca, "%[^;]; %i; %f;", peli[i].titulo, &peli[i].year, &peli[i].nota);
		i++;
	}
	
	
	printf("\nPeliculas ordenadas por a%co: \n",164);
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
				printf("%-40s %i\t\t%.2f",peli[i].titulo, peli[i].year, peli[i].nota);
		}	
		printf("\n");
	fclose(pfilmoteca); 
	
}



void ordenatitulo()
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
	printf("\nPeliculas ordenadas por titulo: \n");
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
				printf("%-40s %i\t\t%.2f",peli[i].titulo, peli[i].year, peli[i].nota);
		}	
		printf("\n");
	fclose(pfilmoteca); 
}


void buscapeli( )
{
	FILE *pfilmoteca;
	char titulo[30],texto[80];
	int i,tmp1,tmp2;
	fflush(stdin); 	
    printf("Introduzca el titulo de la pelicula: \n");
	gets(titulo);

    pfilmoteca=fopen("Videoteca.txt","r");
    if (pfilmoteca==NULL)
		printf("Error abriendo el fichero.");

	while (feof(pfilmoteca)==0)
	{
    	fgets(texto,80,pfilmoteca);
		for(i=0;i<strlen(texto);i++)
		{
			if (titulo[0]==texto[i])
			{
				tmp1=0;
				tmp2=i;
				while ((titulo[tmp1]==texto[tmp2])&&(tmp2<strlen(texto))&&(tmp1!=strlen(titulo)))
				{
                	tmp1++;
					tmp2++;
					if (tmp1==strlen(titulo))
                    {
						printf("\nTitulo;\t A%co;\tNota;\n\n",164);
						printf("%s",texto);
                  	}
              	}
            }
        }
    }
}

