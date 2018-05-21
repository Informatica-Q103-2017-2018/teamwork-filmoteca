#include<stdio.h>


typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula;


//Faltan las funciones para ordenar por titulo, año y nota
//Tenemos las funciones para registrar, mostrar y contar pelis
void registrapeli( );
void mostrarpeli( );




int main()
{
	FILE *pvideoteca;
	int a;
	

	do
	{
		printf("Que desea hacer: 1:Registar, 2:Mostrar, 3:Salir\n");
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
			
			default:
				printf("\nOpcion no disponible\n");
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
	

	

	
	
