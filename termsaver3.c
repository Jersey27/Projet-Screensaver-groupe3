#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#define TAILLE_MAX 1000
struct winsize win;
int col, lig;
int a;
int b;
int c;
	
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
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


void create_lab(char **tab, char *name, int x, int y)
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
	n = my_strcat(name, ".pbm\0");
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
              		chaine[h] = '#';
             	if (chaine[h] == '0')
              		chaine[h] = ' ';
            	tab[x+i][y+h]=chaine[h];
            }
            h++;
      	}
 		i++;
	}
    for(i = 1; i != lig-1; i++)
    	printf("%s\n", tab[i]);
}

void main()
{
	int i;
    int j;
	int h;
    char frappe;
	ioctl(0,TIOCGWINSZ,&win);
    col = win.ws_col;
    lig = win.ws_row;
    char* direction = "right";
    char **tab = malloc(sizeof(char*) * lig + 2);
    for(i = 0; i != lig; i++)
    {
        tab[i] = malloc (sizeof(char) * col + 2);
        for(h = 0; h != col; h++)
        {
            tab[i][h] = ' ';
        }
    }
    int x = 10;
    int y = 10;   
    create_lab(tab,direction,x,y);
    int z;
    while(1)
    {
        /*if (x<lig-6 && y<col-3 && x>0 && y>0)
        if (x==lin-6 && direction = "bottom")*/


        frappe=getch();
        if (frappe =='g')
            z=1;
        if (frappe =='h')
            z=2;
        if (frappe =='d')
            z=3;
        if (frappe =='b')
            z=4;
        if (z=1)
        {
            y = y-1;
            direction = "left";
            create_lab(tab,direction,x,y);
            for(i=0;i!=lig;i++)
                for(i=0;i!=col;i++)
                    tab[i][j-1] = tab[i][j];
            if (y=0)
            {
                y=col-1;
                for(i=0;i!=lig;i++)
                    tab[i][0] = ' ';
            }
        }
        if (z=2)
        {
            x = x-1;
            direction = "top";
            create_lab(tab,direction,x,y);
            for(i=0;i!=lig;i++)
                for(i=0;i!=col;i++)
                    tab[i-1][j] = tab[i][j];
            if (x=0)
            {
                x=lig-1;
                for(i=0;i!=lig;i++)
                    tab[0][i] = ' ';
            }
        }
        if (z=3)
        {
            y = y+1;
            direction = "right";
            create_lab(tab,direction,x,y);
            for(i=0;i!=lig;i++)
                for(i=0;i!=col;i++)
                    tab[i][j+1] = tab[i][j];
            if (y=col)
            {
                y=1;
                for(i=0;i!=lig;i++)
                    tab[i][col] = ' ';
            }
        }
        if (z=4)
        {
            x = x+1;
            direction = "bottom";
            create_lab(tab,direction,x,y);
            for(i=0;i!=lig;i++)
                for(i=0;i!=col;i++)
                    tab[i+1][j] = tab[i][j];
            if (x=lig)
            {
                x=1;
                for(i=0;i!=lig;i++)
                    tab[lig][i] = ' ';
            }
        }
    }
}
