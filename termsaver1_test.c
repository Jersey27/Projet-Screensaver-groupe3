#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#define TAILLE_MAX 1000

struct winsize win;
int col, lig;
int i;
char chaine[TAILLE_MAX];

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
	printf(" ");
}
printf("%s",chaine);
}

int main(int argc, char *argv[])
{
	system("clear");
	char c;
	int i = 1;
	int k;
	int l;
	int j = 0;
	char test[TAILLE_MAX];
	FILE* fichier = NULL;
	fichier = fopen("2.pbm", "r");
	if (fichier != NULL)
	{
		while (fgets(test, TAILLE_MAX, fichier) != NULL);
		{
			j++;
		}
		ioctl(0,TIOCGWINSZ,&win);
		lig = win.ws_row;
		k = lig/2-j/2;
		for(i=0;i!=k;i++)
		{
			printf("\n");
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
					chaine[i]='#';
				}
			}
			afficher();
		}
		k = lig-k-j-1;
		for(i=0;i!=k;i++)
		{
			printf("\n");
		}
		fclose(fichier);
	}
<<<<<<< HEAD
	//getch();
	
}
if (c=getchar()) return 0;
}
=======
	getch();
	return 0;
}
>>>>>>> origin/master
