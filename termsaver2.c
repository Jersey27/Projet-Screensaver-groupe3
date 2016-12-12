#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAILLE_MAX 1000

int i;
int j;
int c;
int k;
int l;
char b;

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

void afficherpbm(char *str, int b)
{
	char *str2 = malloc(2 * sizeof(char));
	str2[0] = str[b];
	str[1] = '\0';
	char *name = my_strcat(str2, ".pbm");
	char *chaine = malloc(TAILLE_MAX * sizeof(char));
	char *chaine2 = malloc(TAILLE_MAX * sizeof(char));
	FILE* fichier = NULL; //Initialisation de la variable de fichier
	fichier = fopen(name,"r");
	if(l==0)
	{
		for(j=0;j!=3;j++)
		{
			fgets(chaine,TAILLE_MAX, fichier);
		}
	}
	fgets(chaine, TAILLE_MAX, fichier);
	chaine = my_strcat(chaine, chaine2);
	fclose(fichier);
	printf("%s\n",fichier);
}

int main(int argc, char *argv[])
{
	int c = 0;
	char *temps =  malloc(30 * sizeof(char));
	char *chaine = malloc(TAILLE_MAX * sizeof(char));
	char *str = malloc(strlen(temps) * sizeof(char) + 1);
	time_t t = time(NULL); //Récupération du temps courent
	strcpy(temps,ctime(&t)); //Transfert du temps courant dans le char "temps"
	while (c != strlen(temps))
	{
 		if (c + 12 == 12 || c + 12 == 13 || c + 12 == 15 || c + 12 == 16  || c + 12 == 18 || c + 12 == 19)
		{
			str[c] = temps[c + 12];
		}
	}
	str[c] = '\0';
	while(t!=0) //Boucle infinie
	{
		for(l=0;l!=8;l++) //Boucle d'affichage
		{
			c = 0;
			while (str[c])
			{
				afficherpbm(str, c);
				c++;
			}
//			.pbm++[0] = a;
//			fichier = fopen(a,"r");
//			if(i==0)
//			{
//				for(j=0;j!=3;j++)
//				{
//					fgets(chaine,TAILLE_MAX, fichier);
//				}
//			}
//			fgets(chaine, TAILLE_MAX, fichier);
//			fclose(fichier);
//			.pbm++[0] = b;
//			fichier = fopen(b,"r");
//			if(i==0)
//			{
//				for(j=0;j!=3;j++)
//				{
//					fgets(chaine,TAILLE_MAX, fichier);
//				}
//			}
//			fgets(chaine2, TAILLE_MAX, fichier);
//			chaine = my_strcat(chaine, chaine2);
//			fclose(fichier);
//			.pbm++[0] = c;
//			fichier = fopen(c,"r");
//			if(i==0)
//			{
//				for(j=0;j!=3;j++)
//				{
//					fgets(chaine,TAILLE_MAX, fichier);
//				}
//			}
//			fgets(chaine2, TAILLE_MAX, fichier);
//			chaine = my_strcat(chaine, chaine2);
//			fclose(fichier);
//			.pbm++[0] = d
//			fichier = fopen(d,"r");
//			if(i==0)
//			{
//				for(j=0;j!=3;j++)
//				{
//					fgets(chaine,TAILLE_MAX, fichier);
//				}
//			}
//			fgets(chaine2, TAILLE_MAX, fichier);
//			chaine = my_strcat(chaine, chaine2);
//			fclose(fichier);
//			.pbm++[0] = e
//			fichier = fopen(e,"r");
//			if(i==0)
//			{
//				for(j=0;j!=3;j++)
//				{
//					fgets(chaine,TAILLE_MAX, fichier);
//				}
//			}
//			fgets(chaine2, TAILLE_MAX, fichier);
//			chaine = my_strcat(chaine, chaine2);
//			fclose(fichier);
//			.pbm++[0] = f
//			fichier = fopen(f,"r");
//			if(i==0)
//			{
//				for(j=0;j!=3;j++)
//				{
//					fgets(chaine,TAILLE_MAX, fichier);
//				}
//			}
//			fgets(chaine2, TAILLE_MAX, fichier);
//			chaine = my_strcat(chaine, chaine2);
//			fclose(fichier);

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
