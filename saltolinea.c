#include <stdio.h>
#include <stdlib.h>

#define NOM_ARCHIVO "Videoteca.txt"

int main(void)
{
   FILE *p;
   int ch, num_peliculas;
   
   if ((p = fopen(NOM_ARCHIVO, "r")) == NULL){
      perror(NOM_ARCHIVO);
      return EXIT_FAILURE;
   }
   
   num_peliculas = 0;
   while ((ch = fgetc(p)) != EOF)
      if (ch == '\n')
         num_peliculas++;
   
   fclose(p);
   printf("Numero de peliculas: %d\n", num_peliculas);
   
   return EXIT_SUCCESS;
}

