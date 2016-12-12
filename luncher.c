#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void InscriptData( int);
/* InscriptData
permet d'inscrire des données dans historique.txt .

*/
int main(int argc, char *argv[])
{
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
				printf("statique \n");
				if (execv("./repondant",arguments) ==-1){
				perror("execv");
					return EXIT_FAILURE;}
				InscriptData( veille);
				break;
			case 2:
				printf("dynamique\n");
				if (execv("./repondant",arguments) ==-1){
				perror("execv");
					return EXIT_FAILURE;}
				InscriptData( veille);
				break;
			case 3:
				printf("interractif\n");
				if (execv("./repondant",arguments)==-1){
				perror("execv");
					return EXIT_FAILURE;}
				InscriptData( veille);
				break;

			}
		}
	return 0;
}

void InscriptData( veille)
{
    FILE *fichier;
    fichier = fopen("historique.txt","a");

    time_t timer;
    struct tm instant;

    time(&timer);
    instant=*localtime(&timer);
    fprintf(fichier,"%d/%d/%d ; %d:%d:%d;%d;\n", instant.tm_mday, instant.tm_mon+1, instant.tm_year+1900, instant.tm_hour, instant.tm_min, instant.tm_sec);
    fclose(fichier);
}
