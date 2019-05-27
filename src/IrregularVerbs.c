#include "IrregularVerbs.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void input(struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple)
{
    printf("Present simple form: %s\n", infinitive->expected);

    printf("Enter the second form: ");
    scanf("%s", &PastSimple->user[n]);

    printf("Enter the third form: ");
    scanf("%s", &PastParticiple->user[n]);
}


int input_check(struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple)
{
    if (isalpha(PastSimple->user[n]) == 0) { //Если введённые данные не являются словом, то возвращаем ошибку
        printf("invalid character\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++)
        PastSimple->user[i] = tolower(PastSimple->user[i]); //Перевод введённых данных в нижний регистр

    if (isalpha(PastParticiple->user[n]) == 0) {
        printf("invalid character\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        PastParticiple->user[i] = tolower(PastParticiple->user[i]);

    return 0;
}