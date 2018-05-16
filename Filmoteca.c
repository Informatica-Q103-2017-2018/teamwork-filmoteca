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
int cuentapeli(pelicula peli);




int main()
{
	FILE *pvideoteca;
	int a; // para el switch
	int error, N;//N para el numero de pelis
	pelicula vcatalogo[N];
	cuentapeli(vcatalogo[N]);
	
	do{
		printf("\n");
		do
		{
			printf("Que desea hacer: 1:Registar, 2:Mostrar, 3:Salir\n");
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
						printf("Ha salido del programa con exito");
						break;
					
					default:
						printf("Opcion no disponible \n");
						
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
			fprintf(pfilmoteca, "%s \n", peli.titulo);
			
			printf("Year en el que se estreno la peli:\n");
			scanf("%d",&peli.year);
			fprintf(pfilmoteca, "%d \t\t", peli.year);
			
			printf("Nota de la pelicula:\n");
			scanf("%f",&peli.nota);
			fprintf(pfilmoteca, "%.2f ", peli.nota);
			fprintf(pfilmoteca,"\n");
		
		fclose(pfilmoteca);
		printf("\n Pelicula registrada correctamente.");
}





void mostrarpeli(pelicula peli, int N)
{
	FILE *pfilmoteca;
	int i;
	
	pfilmoteca = fopen("videoteca.txt", "r");
	printf("\nTitulo \nYear\t\tNota \n\n");
	
		for (i = 0; i<=N ; i++) // Leemos el fichero línea a línea
		{  
		fscanf(pfilmoteca, "%[^\n] ", &peli.titulo, &peli.year, &peli.nota);
		printf("%s",peli.titulo, peli.year, peli.nota);
		printf("\n");
		}
	fclose(pfilmoteca); 
	}
	
	
	
	
	
int cuentapeli(pelicula peli)
{
	FILE *pfilmoteca;
	int N;//variable en la que almacenará el número de películas que va contando
	int tampeli;// variable que dirá el tamaño de la estructura que almacena las películas
	int tamfiche;//variable que dirá el tamaño de la película
	
		pfilmoteca = fopen("videoteca.txt", "r");
		fseek(pfilmoteca,0,SEEK_END);
		tamfiche=ftell(pfilmoteca);
		fseek(pfilmoteca,0,SEEK_SET);
		tampeli=sizeof(peli);
		N=tamfiche/tampeli;
		fclose(pfilmoteca);
		
	printf("\n%d: numero de pelis\n",N);
	printf("%d: size de la peli\n",tampeli);
	printf("%d: size del fichero\n ",tamfiche);
	return N;
}

