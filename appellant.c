#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *arguments[] = {"repondant", NULL};

	if (execv("./repondant", arguments) == -1)
	{
	perror("execv");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
