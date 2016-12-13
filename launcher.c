#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "fonctions.h" 
/* InscriptData
permet d'inscrire des données dans historique.txt .
 
*/
int main(int argc, char *argv[])
{
		int axeX, axeY;
		FILE *fichier;
		char ligne[100];

		char *arguments[] = {"repondant",NULL}; /* Modifier repondant par le nom du programme*/
	
		system("clear");
		time_t t;
		srand((unsigned) time(&t));
		int veille = (rand() %3) + 1;

		if (argc>1 && strcmp(argv[1], "-stats")==0)
		{
			fichier = fopen("historique.txt","r");
			if(fichier == NULL) return 1;
			while(fgets(ligne,100,fichier) != NULL) printf("%s",ligne);
			fclose(fichier);
			return 0;
		}
		else
		{

			switch(veille){
			case 1:
			srand((unsigned) time(&t));
			int alea=(rand() %5)+1;
				printf("statique \n");
				if (execv("./termsaver/termsaver1",arguments) ==-1){
				perror("execv");
					return EXIT_FAILURE;}
				InscriptData( veille, alea, axeX, axeY);
				break;
			case 2:
				printf("dynamique\n");
				if (execv("./termsaver/termsaver2",arguments) ==-1){
				perror("execv");
					return EXIT_FAILURE;}
				InscriptData( veille, alea, axeX, axeY);
				break;
			case 3:
				printf("interractif\n");
				if (execv("./termsaver/termsaver3",arguments)==-1){
				perror("execv");
					return EXIT_FAILURE;}
				InscriptData( veille, alea, axeX, axeY);
				break;

			}
		}
	return 0;
}
