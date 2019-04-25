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

int input(struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple)
{
	printf("Present simple form: %s", infinitive->expected);
	
	printf("Enter the second form: ");
	scanf("%s\n", &PastSimple->user[n]);
	
	for (int i = 0; i < n; i++)
		PastSimple->user[i] = tolower(PastSimple->user[i]);

	printf("Enter the third form: ");
	scanf("%s\n", &PastParticiple->user[n]);

	for (int i = 0; i < n; i++)
		PastParticiple->user[i] = tolower(PastParticiple->user[i]);

	return 0;
}