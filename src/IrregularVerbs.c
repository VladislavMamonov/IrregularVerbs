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

void input(struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple)
{
    printf("Present simple form: %s\n", infinitive->expected);

    printf("Enter the second form: ");
    scanf("%s", PastSimple->user);

    printf("Enter the third form: ");
    scanf("%s", PastParticiple->user);
}


int input_check(struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple)
{
    char reject[50] = "0123456789!@#$%^&*()_+-<>,.?:;{}|/*[]"; //Запрещённые символы
    
    int checking = strcspn(PastSimple->user, reject); //Длина начального сегмента не содержащая reject
    int length = strlen(PastSimple->user); //Длина строки

    if (length != checking) {
        printf("!------------------------------------------------------------------------------------------!");
        printf("\n");
        printf("An invalid character was entered. Continue to be careful. We suggest you take the test again.\n");
        printf("!------------------------------------------------------------------------------------------!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        PastSimple->user[i] = tolower(PastSimple->user[i]); //Перевод введённых данных в нижний регистр

    checking = strcspn(PastParticiple->user, reject);
    length = strlen(PastParticiple->user);

    if (length != checking) {
        printf("!------------------------------------------------------------------------------------------!");
        printf("\n");
        printf("An invalid character was entered. Continue to be careful. We suggest you take the test again.\n");
        printf("!------------------------------------------------------------------------------------------!\n");
        return 1;
    }

    return 0;
}

int randomize(int lines)
{
    srand(time(NULL));
    int rand_val = 1 + rand() % lines;
    return rand_val;
}

void clean_array(struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple)
{
    int i;
    for (i = 0; i < 100; i++) {
        infinitive->expected[i] = 0;
        PastSimple->expected[i] = 0;
        PastParticiple->expected[i] = 0;
        PastSimple->user[i] = 0;
        PastParticiple->user[i] = 0;
    }
}

int check_data(char* str, struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple)
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
    int j;
    int k;
    int s;
    int current_line;
    int random_value;
    int right_answers = 0;
    for (i = 0; i < 10; i++) {
        printf("\n");
        clean_array(infinitive, PastSimple, PastParticiple);
        fseek(data, 0, SEEK_SET);
        current_line = 0;
        random_value = randomize(lines);
        while (current_line < random_value) {
            fgets(str, 100, data);
            current_line++;
        }
        s = 0;
        k = 0;
        for (j = 0; str[j] != ' '; j++) {
            infinitive->expected[j] = str[j];
        }
        for (j = j + 1; str[j] != ' '; j++) {
            PastSimple->expected[s] = str[j];
            s++;
        }
        for (j = j + 1; str[j] != '\n'; j++) {
            PastParticiple->expected[k] = str[j];
            k++;
        }

        input(infinitive, PastSimple, PastParticiple);
        input_check(infinitive, PastSimple, PastParticiple);

        if (strcmp(PastSimple->expected, PastSimple->user) == 0) {
            right_answers++;
        }
        if (strcmp(PastParticiple->expected, PastParticiple->user) == 0) {
            right_answers++;
        }
    }
    fclose(data);
    return 0;
}