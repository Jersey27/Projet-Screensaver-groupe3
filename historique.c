#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
 
		FILE* fichier = NULL;
		char historique[4000][40];

void statistique()
{
			
		char chaine[400];
		int choix=0;
		int i;
		int j=0;
		int n=0;

		fichier = fopen("historique.txt","r");
		if (fichier==NULL){
			printf("Erreur a l'ouverture du fichier");
		}
		while (strcmp(chaine," ")!=0){

			fgets(chaine, 40, fichier);
		if (strcmp(chaine," ")!=0)
		{
			strcat(historique[i] , chaine);
		}
		i++;
		}
		fclose(fichier);
		i=i-1;
		while (choix!=1 && choix!=2 && choix!=3)
		{
		printf("veuiller choisir une options \n 1-date \n 2-fond d'écran \n 3-nom du fichier exploitée (statique)\n");
		scanf("%d",&choix);
		}
		system("clear");
		switch (choix)
		{
		case 1:
		printf("tri par date\n");
		for (j=0;j<i;j++){
			printf("utilisation N°%d",j+1);
			printf("%s\n",historique[j]);		}
		break;
		case 2:
		printf("tri par fond d'écran\n");
		break;
		case 3:
		printf("tri par date inversé\n");
		for (j=i;j>=0;j--){
			printf("utilisation N°%d: \n",j+1);
			printf("%s\n",chaine[j]);
		}
		break;
		printf("\n\nexiaserver lancée:%d fois\n",i); 
		}
		
}

int main(int argc, char const *argv[])
{
	statistique();
	return 0;
}