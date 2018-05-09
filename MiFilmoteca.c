#include<stdio.h>
#include<math.h>
#include<string.h>

typedef struct{
	char titulo[50];
	int year;
	float nota;
}pelicula;

short int ordenarPorYear(const char *pvideoteca);
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
		printf("Que desea hacer: b:Registar, c:Buscar\n");
		scanf("%c",&a);
		switch (a)
			{
				case 'b':
					registrapeli(vcatalogo[0]);
					error=1;
					break;
				case 'c':
					//tatata
					error=1;
					break;
				default:
					printf("Opcion no disponible\n");
					error=-1;
					break;
			}
	}while(error<0);
return 0;
}


void registrapeli(pelicula peli)
{
	FILE *pfilmoteca;
	pfilmoteca=fopen("Videoteca.txt","a");
	printf("Titulo de la pelicula:\n");
	//scanf("%[\^n]",peli.titulo);
	//Preguntar función fgets
	fprintf(pfilmoteca, "Titulo: %s \n", peli.titulo);
	printf("Year en el que se estreno la peli:\n");
	scanf("%d",&peli.year);
	fprintf(pfilmoteca, "year: %d \n", peli.year);
	printf("Nota de la pelicula:\n");
	scanf("%f",&peli.nota);
	fprintf(pfilmoteca, "Nota: %.2f \n", peli.nota);
	fclose(pfilmoteca);
}

short int ordenarPorYear(const char *pvideoteca)
{
	int i;
	int j;
	long tam_struct;
	long num_struct;
	FILE *videoteca;
	pvideoteca=fopen("Videoteca.txt","r");
	pelicula peli_i;
	pelicula peli_j;
	fseek(pvideoteca,0,SEEK_END);
	file_bytes = ftell(pvideoteca);//Para saber el numero de bytes del fichero
	tam_struct = sizeof(pelicula);//Para saber el numero de bytes que ocupa la película
	num_struct = file_bytes / tam_struct;// Para saber el número de películas 
	for (i=0;i<num_struct-1;i++)
	{
		for (j=i+1;j<num_struct;j++)
		{
			int mov_pos1 = tam_struct*i;
			fseek(pvideoteca,mov_pos1,SEEK_SET);
			fread(&peli_i,tam_struct,1,pvideoteca);
			int mov_pos2 = tam_struct*j; 
			fseek(pvideoteca,mov_pos2,SEEK_SET);
			fread(&peli_j,tam_struct,1,pvideoteca);
			if (peli_i.year>peli_j.year)
			{
				fseek(pvideoteca,mov_pos1,SEEK_SET);
				fwrite(&peli_j,tam_struct,1,pvideoteca);
				fflush(pvideoteca);
				fseek(pvideoteca,mov_pos2,SEEK_SET);
				fwrite(&peli_i,tam_struct,1,pvideoteca);
				fflush(pvideoteca);
			}

		}

	}
	fclose(pvideoteca);
}

