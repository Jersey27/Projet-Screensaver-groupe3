#include <stdio.h>
#inc#include <stdio.h>
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

void afficherpbm(char *str[b])
{
			char *chaine = malloc(TAILLE_MAX * sizeof(char));
			char *chaine2 = malloc(TAILLE_MAX * sizeof(char));
			FILE* fichier = NULL; //Initialisation de la variable de fichier
			.pbm++[0] = b;
			fichier = fopen(b,"r");
			if(i==0)
			{
				for(j=0;j!=3;j++)
				{
					fgets(chaine,TAILLE_MAX, fichier);b
				}
			}
			fgets(chaine, TAILLE_MAX, fichier);
			chaine = my_strcat(chaine, chaine2);
			fclose(fichier);
}

int main(int argc, char *argv[])
{
	int g = 0;
	char *temps =  malloc(30 * sizeof(char));
	char *chaine = malloc(TAILLE_MAX * sizeof(char));
	char *str = malloc(strlen(temps) * sizeof(char) + 1);
	while (g != strlen(temps))
	{
 		if (g + 12 == 12 || g + 12 == 13 || g + 12 == 15 || g + 12 == 16  || g + 12 == 18 || g + 12 == 19)
		{
			str[g] = temps[g + 12];
		}
	}
	time_t t = time(NULL); //Récupération du temps courent
	while(t!='0') //Boucle infinie
	{
		strcpy(temps,ctime(&t)); //Transfert du temps courant dans le char "temps"
		str[0] = temps[12]; //Récupération des données du char "temps"
		str[1] = temps[13];
		str[2] = temps[15];
		str[3] = temps[16];
		str[4] = temps[18];
		str[5] = temps[19];
		for(i=0;i!=8;i++) //Boucle d'affichage
		{
			c = 0;
			while (str[c])
			{
				afficherpbm(str[c]);
				c++;
				str[c] = '\0';
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
}lude <stdlib.h>
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

void afficherpbm(a[b])
{
			.pbm++[0] = b;
			fichier = fopen(b,"r");
			if(i==0)
			{
				for(j=0;j!=3;j++)
				{
					fgets(chaine,TAILLE_MAX, fichier);b
				}
			}
			fgets(chaine, TAILLE_MAX, fichier);
			fclose(fichier);
}

int main(int argc, char *argv[])
{
	char *temps;	//Initiatlisation des chaînes de caractères et des variables
	temps = malloc(30 * sizeof(char));
	char *chaine;
	chaine = malloc(TAILLE_MAX * sizeof(char));
	char *chaine2;
	chaine2 = malloc(TAILLE_MAX * sizeof(char));
	int c = 0;
	char *a = malloc(strlen(temps) * sizeof(char) + 1);
	while (c != strlen(temps))
	{
 		if (c + 12 == 12 || c + 12 == 13 || c + 12 == 15 || c + 12 == 16  || c + 12 == 18 || c + 12 == 19)
		{
			str[c] = temps[c + 12];
		}
	}
	int i;
	int j;
	int k;
	int l;
	time_t t = time(NULL); //Récupération du temps courent
	FILE* fichier = NULL; //Initialisation de la variable de fichier
	while(t!='0') //Boucle infinie
	{
		strcpy(temps,ctime(&t)); //Transfert du temps courant dans le char "temps"
		a[0] = temps[12]; //Récupération des données du char "temps"
		a[1] = temps[13];
		a[2] = temps[15];
		a[3] = temps[16];
		a[4] = temps[18];
		a[5] = temps[19];
		for(i=0;i!=8;i++) //Boucle d'affichage
		{
			while (str[c])
			{
 				afficherpbm(str[c]);
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
//			fichhier = fopen(c,"r");
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
