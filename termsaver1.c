#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#define TAILLE_MAX 1000

struct winsize win;
int col, lig;

int afficher()
{
int a;
int b;
int c;
ioctl(0,TIOCGWINSZ,&win);
col = win.ws_col;
a = col/2;
c = a-strlen(chaine)/2;
for(i=0;i!=c;i++)
{
	print(" ");
}
printf("%s",chaine);
}

int main(int argc, char *argv[])
{
	int i;
	int k;
	int l;
	int j = 0;
	char chaine[TAILLE_MAX];
	char test[TAILLE_MAX];
	FILE* fichier = NULL;
	fichier = fopen("2.pbm", "r");
	if (fichier != NULL)
	{
		while (fgets(test, TAILLE_MAX, fichier) != NULL);
		{
			j++
		}
		ioctl(0,TIOCGWINSZ,&win);
		lig = win.ws_row;
		j = lig/2-j/2
		for(i=0;i!=j;i++)
		{
			printf("\n")
		}
		fseek(fichier,0,SEEK_SET);
		for(i=0;i!=3;i++)
		{
			fgets(chaine, TAILLE_MAX, fichier);
		}
		while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
		{
			l=strlen(chaine);
			for(i=0;i!=l;i++)
			{
				if (chaine[i]=='1')
				{
					chaine[i]=' ';
				}
				if (chaine[i]=='0')
				{
					chaine[i]=("%c",k != 219);
				}
			}
			afficher();
		}
		fclose(fichier);
	}
	return 0;
}
