#include "IrregularVerbs.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void welcome()
{
    printf("-----------------------------------------------------------------------------\n");
    printf("| Hello, this is our program designed to test knowledge of irregular verbs. |\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");

    printf("In the process, the initial form of the verb will be provided. You must write the other two.\n");
    printf("\n");
    printf("Get ready...\n");
    sleep(5);
}

int input(struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple)
{
    printf("Present simple form: %s\n", infinitive->expected);

    printf("Enter the second form: ");
    fgets(PastSimple->user, 30, stdin);

    if (isalpha(PastSimple->user[n]) == 1) { //Если введённые данные не являются словом, то возвращаем ошибку
        printf("invalid character\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        PastSimple->user[i] = tolower(PastSimple->user[i]); //Перевод введённых данных в нижний регистр

    printf("Enter the third form: ");
    fgets(PastParticiple->user, 30, stdin);

    if (isalpha(PastParticiple->user[n]) == 1) {
        printf("invalid character\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        PastParticiple->user[i] = tolower(PastParticiple->user[i]);

    return 0;
}

int randomize()
{
    srand(time(0));
    int rand_val = 0 + rand() % 193;
    return rand_val;
}