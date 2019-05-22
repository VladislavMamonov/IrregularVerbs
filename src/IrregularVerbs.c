#include "IrregularVerbs.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
    sleep(1);
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

int randomize(int lines)
{
    srand(time(0));
    int rand_val = 1 + rand() % lines;
    return rand_val;
}

int CheckData(char *str)
{
    FILE* data;
    data = fopen("IrregularVerbs.txt", "r");
    if (data == NULL) {
        printf("Error, file not found\n");
        return 1;
    }
    int lines = 0;
    while (!feof(data)) {
        if (fgetc(data) == '\n') {
            lines++;
        }
    }
    lines++;

    int i;
    int j=0;
    int random_value;
    for (i = 0; i < 1; i++) {
        random_value = randomize(lines);
        printf("random=%d\n", random_value);
        while(j < random_value) {
            fgets(str,sizeof(str),data);
            j++;
            printf("%s\n", str);

        }  
        printf("j=%d\n", j);
    }
    fclose(data);
    return 0;
}