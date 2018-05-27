#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula;


int registrapeli( );
int mostrarpeli( );
int devuelveN( );
int ordenayear( );
int ordenanota( );
int ordenatitulo( );
int buscapeli( );

int main()
{	
	int a,b;
	printf("\n*****BIENVENIDO A SU FILMOTECA*****\n");
	do
	{	
		devuelveN( );
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



int registrapeli( ) 
{
	pelicula peli;
	FILE *pfilmoteca;
	pfilmoteca=fopen("Videoteca.txt","a");
	
	if (pfilmoteca == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	
	else
	{	
		fflush(stdin);	
		
		printf("\nTitulo de la pelicula:\n");
		scanf("%[^\n]", peli.titulo);
		fprintf(pfilmoteca, "\n%s;\t\t\t", peli.titulo);
		
		printf("\nA%co de la pelicula:\n", 164);
		scanf("%d",&peli.year);
		if(peli.nota<0)
		{
		printf("\nA%co no valido\n",164);
		return -1;
		}
		else
		fprintf(pfilmoteca, "%d;\t", peli.year);
		
		printf("\nNota de la pelicula:\n");
		scanf("%f",&peli.nota);
		if(peli.nota<0)
		{
		printf("\nNota no valida\n");
		return -1;
		}
		else
		fprintf(pfilmoteca, "%.2f;", peli.nota);
		
		printf("\nPelicula registrada correctamente.\n");
	}
	fclose(pfilmoteca);
}



int mostrarpeli( )
{
	FILE *pfilmoteca;
	pelicula peli;
	pfilmoteca=fopen("videoteca.txt", "r");
	
	if (pfilmoteca == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		printf("\nTitulo\t\t\t\t\t A%co\t\tNota\n\n",164);
		while (feof(pfilmoteca) == 0) // Leemos el fichero
		{  
			fscanf(pfilmoteca, "%[^;]; %i; %f; ", peli.titulo, &peli.year, &peli.nota);
			printf("%-40s %i\t\t%.2f\n",peli.titulo, peli.year, peli.nota);
		}
	}
	fclose(pfilmoteca); 
}
	
	
	
int devuelveN( )
{
	FILE *pfilmoteca;
	int N=-1;
	char c;
	pfilmoteca = fopen("videoteca.txt", "r");
	
	if (pfilmoteca == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		while (fscanf(pfilmoteca, "%c", &c) != EOF)
		{
			if (c == '\n')
				N++;
		}
		printf("\nHay %d peliculas.\n",N);
	}
	fclose(pfilmoteca); 
	return N;
}  
	


int ordenanota( )
{
	int N=devuelveN( );
	pelicula peli[N];
	pelicula aux; //Necesitamos una estructura auxiliar de almacenamiento temporal
	int i=0, j=0;
	FILE *pfilmoteca;
	pfilmoteca = fopen("videoteca.txt", "r");
	
	if (pfilmoteca == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		while (feof(pfilmoteca) == 0) //Primero leemos los datos
		{
			fscanf(pfilmoteca, "%[^;]; %i; %f;", peli[i].titulo, &peli[i].year, &peli[i].nota);
			i++;
		}
		printf("\nPeliculas ordenadas por nota: \n");
		printf("\nTitulo\t\t\t\t\t A%co\t\tNota\n\n",164);

		for(i=0; i<=N-1; i++) //Ahora lo ordenamos
		{
			for(j=i+1; j<=N-1 ; j++) // Comparamos cada elemento con el siguiente
			{
				if (peli[i].nota > peli[j].nota) //Si es mayor intercambiamos el contenido de los dos elementos
				{
				aux = peli[i];
				peli[i] = peli[j];
				peli[j] = aux;
				}
			}
			printf("%-40s %i\t\t%.2f",peli[i].titulo, peli[i].year, peli[i].nota);
		}
		printf("\n");
		
	}
	fclose(pfilmoteca); 
}



int ordenayear( )
{
	int N=devuelveN( );
	FILE *pfilmoteca;
	pfilmoteca = fopen("videoteca.txt", "r");
	pelicula peli[N];
	pelicula aux; //Necesitamos una estructura auxiliar de almacenamiento temporal
	int i=0, j=0;
	
	if (pfilmoteca == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	
	else
	{
		while (feof(pfilmoteca) == 0) //Primero leemos los datos
		{
			fscanf(pfilmoteca, "%[^;]; %i; %f;", peli[i].titulo, &peli[i].year, &peli[i].nota);
			i++;
		}
	
		printf("\nPeliculas ordenadas por a%co: \n",164);
		printf("\nTitulo\t\t\t\t\t A%co\t\tNota\n\n",164);

		for(i=0; i<=N-1; i++) //Ahora lo ordenamos
		{
			for(j=i+1; j<=N-1 ; j++) //Comparamos cada elemento con el siguiente
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
	}
	fclose(pfilmoteca); 
}



int ordenatitulo()
{
	int N=devuelveN( );
	FILE *pfilmoteca;
	pfilmoteca = fopen("videoteca.txt", "r");
	pelicula peli[N];
	pelicula aux; //Necesitamos una variable auxiliar de almacenamiento temporal
	int i=0, j=0;
	
	if (pfilmoteca == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		while (feof(pfilmoteca) == 0) //Primero leemos los datos
		{
			fscanf(pfilmoteca, "%[^;]; %i; %f;", peli[i].titulo, &peli[i].year, &peli[i].nota);
			i++;
		}
		printf("\nPeliculas ordenadas por titulo: \n");
		printf("\nTitulo\t\t\t\t\t A%co\t\tNota\n\n",164);
	
		for(i=0; i<=N-1; i++) //Ahora lo ordenamos
		{
			for(j=i+1; j<=N-1 ; j++) // Comparamos cada elemento con el siguiente
			{
				if (strcmp(peli[i].titulo,peli[j].titulo)>0)//Si es mayor(alfabeticamente) intercambiamos el contenido de los dos elementos
				{
				aux = peli[i]; 
				peli[i] = peli[j];
				peli[j] = aux;
				}
			}
			printf("%-40s %i\t\t%.2f",peli[i].titulo, peli[i].year, peli[i].nota);
		}	
		printf("\n");
	}
	fclose(pfilmoteca); 
}



int buscapeli( )
{
	FILE *pfilmoteca;
    pfilmoteca=fopen("Videoteca.txt","r");	
	char titulo[30],texto[80];
	int i,tmp1,tmp2;
	
	if (pfilmoteca == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		fflush(stdin); 	
    	printf("Introduzca el titulo de la pelicula: \n");
		gets(titulo);

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
}


