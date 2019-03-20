#include <stdio.h>

int main (void)
{
   FILE *fichier = fopen ("file.txt", "w");
 
	if (fichier != NULL)
	{
 
    	fprintf (fichier, " \n");
	}
   	else
   	{
  		printf ("Impossible d'ecrire dans le fichier");
   	}
	fclose (fichier);
   	return 0;
}