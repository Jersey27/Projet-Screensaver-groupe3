#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/ioctl.h>
#define TAILLE_MAX 1000
struct winsize win;
int col, lig;
int a;
int b;
int c;
	
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


void create_lab(char **tab, char name, int x, int y)
{
    char *test = malloc(sizeof(char*)*TAILLE_MAX);
    char *chaine = malloc(sizeof(char*)*TAILLE_MAX);
    int i;
    int h;
    int colonnes;
    int lignes = 0;
    ioctl(0,TIOCGWINSZ,&win);
    col = win.ws_col;
    lig = win.ws_row;
    FILE* fichier = NULL;
    char *n = malloc(100 * sizeof(char));
	n[0]=name;
	n[1]='\0';
	n = my_strcat(n, ".pbm\0");
    fichier = fopen(n, "r");
    while (fgets(test, TAILLE_MAX, fichier) != NULL);
    {
        lignes++;
    }
    fseek(fichier,0,SEEK_SET);
    for(i=0;i!=3;i++)
    {
        fgets(chaine, TAILLE_MAX, fichier);
    }
    fgets(chaine, TAILLE_MAX, fichier);
    fseek(fichier,8,SEEK_SET);
    colonnes = strlen(chaine);
    lignes = lignes - 3;
    i = 0;
    while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
	{
  		h = 0;
     	while (chaine[h])
     	{
     		if (chaine[h] != '\n')
            {
             	if (chaine[h] == '1')
              		chaine[h] = ' ';
             	if (chaine[h] == '0')
              		chaine[h] = '#';
            	tab[x+i][y+h]=chaine[h];
            }
            h++;
      	}
 		i++;
	}
    for(i = 0; i != lig; i++)
    	printf("%s\n", tab[i]);
}

void main()
	{   
	int r;
	int i;
	int h;
	ioctl(0,TIOCGWINSZ,&win);
    col = win.ws_col;
    lig = win.ws_row;
    char **tab = malloc(sizeof(char*) * lig +1);
    for(i = 0; i != lig; i++)
    {
        tab[i] = malloc (sizeof(char) * col + 1);
        for(h = 0; h != col; h++)
        {
            tab[i][h] = ' ';
        }
    }
    while(1)
    {
    	c = 0;
    	r = 0;
    	char *temps =  malloc(30 * sizeof(char));
		time_t t = time(NULL); //Récupération du temps courant
		strcpy(temps,ctime(&t)); //Transfert du temps courant dans le char "temps"
		char *str = malloc(strlen(temps) * sizeof(char) + 1);//Initialisation et allocation de la chaine récupérant le temps courant
		while (c != strlen(temps))//Boucle stockant les valeurs interessant de "temps" dans "str"
		{
	 		if (c + 11 == 11 || c + 11 == 12 || c + 11 == 14 || c + 11 == 15  || c + 11 == 17 || c + 11 == 18)//Vérification
			{
				str[r] = temps[c + 11];//Stockage
				r++;
			}
			c++;
		};
	    create_lab(tab,str[0],lig/2-4,col/2-17);
	    create_lab(tab,str[1],lig/2-4,col/2-11);
	    create_lab(tab,str[2],lig/2-4,col/2-3);
	    create_lab(tab,str[3],lig/2-4,col/2+3);
	    create_lab(tab,str[4],lig/2-4,col/2+11);
	    create_lab(tab,str[5],lig/2-4,col/2+17);
	    free(str);
	    free(temps);
	    sleep(1);
	}
}
