#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void InscriptData( veille, alea, axeX, axeY)
{
	FILE *fichier; //declare le fichier
	fichier = fopen("historique.txt","a"); //definit le fichier et ne
					       //l'autorise qu'a ajouter
	time_t timer; //definit une variable le temps actuel (en secondes)
	struct tm instant; //definit la structure de definition de date/heure

	time(&timer); //
	instant=*localtime(&timer); //adaptee timer de facon a obtenir la date de maniere correcte
	fprintf(fichier,"%d/%d/%d  %d:%d:%d;%d;", instant.tm_mday, instant.tm_mon+1, instant.tm_year+1900, instant.tm_hour, instant.tm_min, instant.tm_sec, veille);
	/*ajoute dans l'historique une entree incluant:
	date, heure et fond d'ecran.*/
	switch (veille) //rajoute les paramètres complémentaires en fonctions de l'écran de veille
	{
	case 1:
	fprintf(fichier,"ex%d.pbm\n", alea);
	break;
	case 2:
	fprintf(fichier,"0x0\n"/*%s,getenv(EXIASAVER2_TAILLE)*/);
	break;
	case 3:
	fprintf(fichier,"%dx%d\n", axeX, axeY);
	break;
	}
	fclose(fichier);
return;
}
