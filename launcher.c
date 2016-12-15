#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "fonctions.h" 
/* InscriptData
permet d'inscrire des données dans historique.txt . 
*/
int main(int argc, char *argv[], char** emvp)
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
				InscriptData( veille, alea, axeX, axeY);
				arguments[2] = "%c.pbm",alea;
				if (execv("./termsaver1",arguments) ==-1){
				perror("execv");
					return EXIT_FAILURE;}
				break;
			case 2:
				printf("dynamique\n");
				InscriptData( veille, alea, axeX, axeY);
				if (execv("./termsaver2",arguments) ==-1){
				perror("execv");
					return EXIT_FAILURE;}
				break;
			case 3:
				printf("interractif\n");
				InscriptData( veille, alea, axeX, axeY);
				if (execv("./termsaver3",arguments)==-1){
				perror("execv");
					return EXIT_FAILURE;}
				break;
			}
		}
	return 0;
}
