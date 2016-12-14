#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

#define TAILLE_MAX 1000

char chaine[TAILLE_MAX];

int afficher()
{
int a;
int b;
int c;
int d;
int i;
struct winsize win;
int col, lig;

ioctl(0,TIOCGWINSZ, &win);

col = win.ws_col;
lig = win.ws_row;

a = col/2;
b = lig/2;
c = a-strlen(chaine)/2;
//d = b-
for(i=0;i!=c;i++)
{
	printf(" ");
}
printf("%s",chaine);
return 0;
}

int main(int argc, char *argv[])
{
	char *arguments[] = {"fichier2", NULL};
	pid_t pid = getppid();
	pid = fork(); //pid = 100
if(pid == 0){

int i;
	int l;
	char k;
	FILE* fichier = NULL;
	fichier = fopen("1.pbm", "r");
	if (fichier != NULL)
	{
		for(i=0;i!=2;i++)
		{
			fgets(chaine, TAILLE_MAX, fichier);
		}
		fgets(chaine, TAILLE_MAX, fichier);
		l=strlen(chaine);
//		for(i=0;i!=l;i++)
//		{
//			if (chaine[i]==' ')
//			{
//				k=chaine[i+1]
//			}
//		}
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
		fclose(fichier);
	}	
}
else{
	printf("alors");
	wait(NULL);
}
return 0;
}