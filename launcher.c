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
		int axeX, axeY;							//
		FILE *fichier;							//
		char ligne[100];						//
		char *arguments[] = {"repondant",NULL}; /* Modifier repondant par le nom du programme*/
	
		system("clear");						//
		time_t t;								//récupérations de la variable de temps pour 
		srand((unsigned) time(&t));				//génération d'un nombre aléatoire
		int veille = (rand() %3) + 1;			//affectation de la variable aléatoire

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

			switch(veille){									//choix du fond de veille (aléatoire)
			case 1:											//le cas du fond de veille statique
			srand((unsigned) time(&t));						//la variable aléatoire alea permet de choisir la
			int alea=(rand() %5)+1;							
				InscriptData( veille, alea, axeX, axeY);	//inscrit cet entrée dans l'historique
				arguments[2] = "%c.pbm",alea;				//on affecte comme arguments le fichier aléatoire choisi
				if (execv("./termsaver1",arguments) ==-1){	//lancement du sreensaver1. Un message d'erreur sera émis si le
				perror("execv");							//lancement n'a pas eu lieu
					return EXIT_FAILURE;}
				break;
			case 2:											//le cas du fond de veille dynamique
				printf("dynamique\n");						
				InscriptData( veille, alea, axeX, axeY);	//inscrit cet entrée dans l'historique
				if (execv("./termsaver2",arguments) ==-1){	//lancement
				perror("execv");
					return EXIT_FAILURE;}
				break;
			case 3:											//le cas du fond de veille interractif
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
