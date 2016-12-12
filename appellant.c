#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *arguments[] = {"teste3", NULL};

	if (execv("./repondant", arguments) == -1)
	{
	perror("execv");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
