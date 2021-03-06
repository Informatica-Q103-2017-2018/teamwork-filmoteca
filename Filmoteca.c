#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula; // estructura de cada pelicula


//Todas las funciones que vamos a necesitar
int registrapeli( );
int mostrarpeli( );
int devuelveN( );//Funcion que devuelve un valor N que es el n�mero de pel�culas
int ordenayear( );
int ordenanota( );
int ordenatitulo( );
int buscapeli( );
int buscayear( );

int main()
{	
	int a,b,c; //para los switch-case
	printf("\n*****BIENVENIDO A SU FILMOTECA*****\n");
	do
	{	
		devuelveN( );//para saber el numero de peliculas
		printf("\nQue desea hacer: \n1:Registrar \n2:Mostrar pelis \n3:Buscar \n4:Ordenar \n5:Salir\n",164);
		scanf("%i",&a);
		
		switch (a)
		{
			case 1:
				registrapeli( );
			break;
				
			case 2:
				mostrarpeli( );
			break;
		
			case 3:// para las funciones de buscar
				do
				{
					printf("\n1:Por fecha \n2:Por titulo \n3:Volver\n");
					scanf("%i",&b);
					switch(b)
					{
						case 1:
							buscayear( );	
						break;
						
						case 2:
							buscapeli( );
						break;
						
						case 3:
							printf("\nHas vuelto al inicio.\n");
						break;
					}	
				} while(b!=3);
			break;
			
			case 4:// para las funciones de ordenar
				do
				{
					printf("\n1:Por fecha \n2:Por nota \n3:Por titulo \n4:Volver\n");
					scanf("%i",&c);
					switch(c)
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
							printf("\nHas vuelto al inicio.\n");
						break;
					}	
				} while(c!=4);
			break;
			
			case 5:
				printf("\nHas salido del programa.\n");
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
		if(peli.year<0) //control errores
		{
		printf("\nA%co no valido\n",164);
		return -1;
		}
		else
		fprintf(pfilmoteca, "%d;\t", peli.year);
		
		printf("\nNota de la pelicula:\n");
		scanf("%f",&peli.nota);
		if(peli.nota<0) //control errores
		{
		printf("\nNota no valida\n");
		return -1;
		}
		else
		fprintf(pfilmoteca, "%.2f;", peli.nota);
		
		printf("\nPelicula registrada correctamente.\n");
	}
	fclose(pfilmoteca);
	return 0;
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
		printf("\nTitulo\t\t\t\t\tA%co\t\tNota\n\n",164);
		while (feof(pfilmoteca) == 0) // Leemos el fichero y mostramos las peliculas
		{  
			fscanf(pfilmoteca, "%[^;]; %i; %f; ", peli.titulo, &peli.year, &peli.nota);
			printf("%-40s %i\t\t%.2f\n",peli.titulo, peli.year, peli.nota);
		}
	}
	fclose(pfilmoteca); 
	return 0;
}
	
	
	
int devuelveN( )
{
	FILE *pfilmoteca;
	int N=0;// numero de lineas
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
			if (c == '\n') // va aumentando el numero de lineas
				N++;
		}
		printf("\nHay %d peliculas.\n",N);
	}
	fclose(pfilmoteca); 
	return N;//Devuelve un valor que es el n�mero de saltos de l�nea contados
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
		while (feof(pfilmoteca) == 0) //Primero leemos las pelis
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
	return 0;
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
	return 0; 
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
	return 0; 
}



int buscapeli( )
{
	int i=0,j=0,k=0,tmp1,tmp2;// para el bucle y para comparar
	int N=devuelveN( );//para saber el numero de peliculas
	char titulo[50];
	pelicula peli[N];
	pelicula aux;
	FILE *pfilmoteca;
    pfilmoteca=fopen("Videoteca.txt","r");	

	
	if (pfilmoteca == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		fflush(stdin); 	
    	printf("\nIntroduzca el titulo de la pelicula: \n");
		scanf("%[^\n]",titulo);
		
		while (feof(pfilmoteca) == 0) //Primero leemos los datos
		{
			fscanf(pfilmoteca, "%[^;]; %i; %f;", peli[i].titulo, &peli[i].year, &peli[i].nota);
			i++;
		}
		
		printf("\nTitulo\t\t\t\t\tA%co\tNota\n\n",164);
	
		for(i=0; i<=N-1; i++) //Lo ordenamos
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
			
			for(k=0; k<=strlen(peli[i].titulo); k++)//bucle para recorrer cada pelicula
			{
				if (titulo[0]==peli[i].titulo[k])//comprobamos que coincidan el titulo introducido y el titulo de la pelicula registrada
				{
					tmp1=0;
					tmp2=k;
					
					while ((titulo[tmp1]==peli[i].titulo[tmp2]) && (tmp2<strlen(peli[i].titulo)) && (tmp1!=strlen(titulo)))
					{
                		tmp1++;
						tmp2++;
						if (tmp1==strlen(titulo))
                    	{
						printf("%-40s %i\t%.2f",peli[i].titulo, peli[i].year, peli[i].nota);//mostramos las peliculas alfabeticamente 
                  		}
	              	}
    	        } 
        	}
			
		}	
		printf("\n");
	}
	return 0;
}



int buscayear( )
{
	int i=0,existe=0;// para el bucle y para usar en el if y saber si hay pelis con el a�o dado
	int N=devuelveN( );//para saber el numero de peliculas
	int yeardado;// a�o que dara el usuario por teclado
	pelicula peli[N];
	pelicula aux;
	FILE *pfilmoteca;
	
    pfilmoteca=fopen("Videoteca.txt","r");	
	if (pfilmoteca == NULL)
	{
		printf("Error al abrir el fichero.\n");
		return -1;
	}
	else
	{
		fflush(stdin); 	
    	printf("\nIntroduzca el a%co del que quiere mostrar peliculas: \n",164);
		scanf("%d",&yeardado);
		printf("\nTitulo\t\t\t\t\tA%co\tNota\n\n",164);
		while (feof(pfilmoteca) == 0) //Primero leemos los datos
		{
			fscanf(pfilmoteca, "%[^;]; %i; %f;", peli[i].titulo, &peli[i].year, &peli[i].nota);
			i++;
		}
		for(i=0;i<N;i++)//Recorremos el vector de las peliculas 
		{
			if (yeardado==peli[i].year)
			{
				printf("%-40s %i\t%.2f",peli[i].titulo, peli[i].year, peli[i].nota);//mostramos las peliculas por a�o   
				existe=1;     	
		    }
		}
		 if(existe<1)
		    {
		    	printf("No hay pelis registradas en ese a%co\n",164);
			}
		printf("\n");
	}
	return 0;
}		


