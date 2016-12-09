#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAILLE_MAX 1000
int main(int argc, char *argv[])
{
	int i;
	int l;
	char chaine[TAILLE_MAX];
	FILE* fichier = NULL;
	fichier = fopen("1.pbm", "r");
	if (fichier != NULL)
	{
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
			printf("%s", chaine);
		}
		fclose(fichier);
	}
	return 0;
}
