#include<stdio.h>
#include<math.h>

typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula;

int ordenarPorYear( int *pfilmoteca);
//Funci?n ordenar por titulo
//Funci?n ordenar por nota
//Funci?n ordenar por g?nero
void registrapeli(pelicula peli);

int main()
{
	FILE *pvideoteca;
	char a; // a para el switch
	int error;
	pelicula vcatalogo[100];
	do
	{
		printf("Que desea hacer: R:Registar, B:Buscar\n");
		scanf("%c",&a);
		fflush(stdin);
		switch (a)
			{
				case 'R':
				case 'r':	
					registrapeli(vcatalogo[0]);
					error=1;
					break;
					
				case 'b':
				case 'B':	
					//tatata
					error=1;
					break;
					
				default:
					printf("Opcion no disponible\n");
					error=-1;
					break;
			}
	}while(error<0);
}


void registrapeli(pelicula peli)
{FILE *pfilmoteca;
			pfilmoteca=fopen("Videoteca.txt","a");
			
				printf("Titulo de la pelicula:\n");
				scanf("%[^\n]", peli.titulo);
				fprintf(pfilmoteca, "-Titulo: %s\n", peli.titulo);
				
				printf("Year en el que se estreno la peli:\n");
				scanf("%d",&peli.year);
				fprintf(pfilmoteca, "Year: %d \n", peli.year);
				
				printf("Nota de la pelicula:\n");
				scanf("%f",&peli.nota);
				fprintf(pfilmoteca, "Nota: %.2f \n", peli.nota);
				fprintf(pfilmoteca, "\n");
				
			fclose(pfilmoteca);
			printf("\n Pelicula registrada correctamente.");
}



int ordenarPorYear(int *pfilmoteca)
{
	int i;
	int j;
	long tam_struct;
	long num_struct;
	pfilmoteca=fopen("Videoteca.txt","r");
	pelicula peli_i;
	pelicula peli_j;
	fseek(pfilmoteca,0,SEEK_END);
	file_bytes = ftell(pfilmoteca); //Para saber el numero de bytes del fichero
	tam_struct = sizeof(pelicula); //Para saber el numero de bytes que ocupa la pel?cula
	num_struct = file_bytes / tam_struct; // Para saber el n?mero de pel?culas 
	for (i=0;i<num_struct-1;i++)
	{
		for (j=i+1;j<num_struct;j++)
		{
			int mov_pos1 = tam_struct*i;
			fseek(pfilmoteca,mov_pos1,SEEK_SET);
			fread(&peli_i,tam_struct,1,pfilmoteca);
			int mov_pos2 = tam_struct*j; 
			fseek(pfilmoteca,mov_pos2,SEEK_SET);
			fread(&peli_j,tam_struct,1,pfilmoteca);
			if (peli_i.year>peli_j.year)
			{
				fseek(pfilmoteca,mov_pos1,SEEK_SET);
				fwrite(&peli_j,tam_struct,1,pfilmoteca);
				fflush(pfilmoteca);
				fseek(pfilmoteca,mov_pos2,SEEK_SET);
				fwrite(&peli_i,tam_struct,1,pfilmoteca);
				fflush(pfilmoteca);
			}

		}

	}
	fclose(pfilmoteca);
}



