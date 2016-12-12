#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAILLE_MAX 1000

void sleep(int seconds) //Fonction faisant une pause de x secondes
{
	time_t start_time = 0;
	time_t current_time = 0;
	start_time = time(NULL);
	while(current_time - start_time + 1 <= seconds)
	{
		current_time = time(NULL);
	}
}

int my_strlen(char *str) //Fonction remplaçant strlen pour ce programme
{
	int i;
	i = 0;
	while (str[i]!='\0')
		i++;
	return(i);
}

char *my_strcat(char *dest, char *src) //Fonction remplaçant strcat pour ce programme
{
	char *result;
	int len;
	int i;
	i = 0;
	len = 0;
	result = malloc(my_strlen(dest) + my_strlen(src) + 1);
	while (dest[i])
	{
		result[i] = dest[i];
		i++;
	}
	while (src[len])
	{
		result[len + i] = src[len];
		len++;
	}
	result[len + i] = '\0';
	return (result);
}

int main(int argc, char *argv[])
{
	char *temps;	//Initiatlisation des chaînes de caractères et des variables
	temps = malloc(30 * sizeof(char));
	char *chaine;
	chaine = malloc(TAILLE_MAX * sizeof(char));
	char *chaine2;
	chaine2 = malloc(TAILLE_MAX * sizeof(char));
	char *a;
	a = malloc(1 * sizeof(char));
	char *b;
	b = malloc(1 * sizeof(char));
	char *c;
	c = malloc(1 * sizeof(char));
	char *d;
	d = malloc(1 * sizeof(char));
	char *e;
	e = malloc(1 * sizeof(char));
	char *f;
	f = malloc(1 * sizeof(char));
	int i;
	int j;
	int k;
	int l;
	time_t t = time(NULL); //Récupération du temps courent
	FILE* fichier = NULL; //Initialisation de la variable de fichier
	while(t!='0') //Boucle infinie
	{
		strcpy(temps,ctime(&t)); //Transfert du temps courant dans le char "temps"
		a[strlen(a)] = temps[12]; //Récupération des données du char "temps"
		b[strlen(b)] = temps[13];
		c[strlen(c)] = temps[15];
		d[strlen(d)] = temps[16];
		e[strlen(e)] = temps[18];
		f[strlen(f)] = temps[19];
		for(i=0;i!=8;i++) //Boucle d'affichage
		{
			strcat(a,".pbm");
			fichier = fopen(a,"r");
			if(i==0)
			{
				for(j=0;j!=3;j++)
				{
					fgets(chaine,TAILLE_MAX, fichier);
				}
			}
			fgets(chaine, TAILLE_MAX, fichier);
			fclose(fichier);
			strcat(b,".pbm");
			fichier = fopen(b,"r");
			if(i==0)
			{
				for(j=0;j!=3;j++)
				{
					fgets(chaine,TAILLE_MAX, fichier);
				}
			}
			fgets(chaine2, TAILLE_MAX, fichier);
			chaine = my_strcat(chaine, chaine2);
			fclose(fichier);
			strcat(c,".pbm");
			fichier = fopen(c,"r");
			if(i==0)
			{
				for(j=0;j!=3;j++)
				{
					fgets(chaine,TAILLE_MAX, fichier);
				}
			}
			fgets(chaine2, TAILLE_MAX, fichier);
			chaine = my_strcat(chaine, chaine2);
			fclose(fichier);
			strcat(d,".pbm");
			fichier = fopen(d,"r");
			if(i==0)
			{
				for(j=0;j!=3;j++)
				{
					fgets(chaine,TAILLE_MAX, fichier);
				}
			}
			fgets(chaine2, TAILLE_MAX, fichier);
			chaine = my_strcat(chaine, chaine2);
			fclose(fichier);
			strcat(e,".pbm");
			fichier = fopen(e,"r");
			if(i==0)
			{
				for(j=0;j!=3;j++)
				{
					fgets(chaine,TAILLE_MAX, fichier);
				}
			}
			fgets(chaine2, TAILLE_MAX, fichier);
			chaine = my_strcat(chaine, chaine2);
			fclose(fichier);
			strcat(f,".pbm");
			fichier = fopen(f,"r");
			if(i==0)
			{
				for(j=0;j!=3;j++)
				{
					fgets(chaine,TAILLE_MAX, fichier);
				}
			}
			fgets(chaine2, TAILLE_MAX, fichier);
			chaine = my_strcat(chaine, chaine2);
			fclose(fichier);
			printf("%s", chaine);

		}
		for(k=0;k!=10;k++)
		{
			sleep(1);
			printf(".");
		}
		t = time(NULL);
	}
	return 0;
}
