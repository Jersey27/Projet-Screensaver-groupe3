#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	system("clear");


	time_t t;
	srand((unsigned) time(&t));
	int veille = (rand() %3);

if (argc>1 && strcmp(argv[1],"-stats")==0){
	printf("Historique\n");}
else{

switch (veille){
case 0:
	printf("Statique\n");
	break;
case 1:
	printf("Dynamique\n");
	break;
case 2:
	printf("Interractif\n");
	break;
}
}
	return 0;
}
