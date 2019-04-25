#include "IrregularVerbs.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void welcome()
{
	printf("-----------------------------------------------------------------------------\n");
	printf("| Hello, this is our program designed to test knowledge of irregular verbs. |\n");
    printf("-----------------------------------------------------------------------------\n");
	printf("\n");

	printf("In the process, the initial form of the verb will be provided. You must write the other two.\n");
}

int input(struct IrregularVerbs* present, struct IrregularVerbs* past, struct IrregularVerbs* future)
{
	printf("Present simple form: %s", present->expected);
	
	printf("Enter the past simple form: ");
	scanf("%s\n", &past->user[n]);

	printf("Enter the future simple form: ");
	scanf("%s\n", &future->user[n]);

	return 0;
}