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
    int i;
    int lenght_simple = strlen(PastSimple->user);
    int lenght_participle = strlen(PastParticiple->user);

    for (i = 0; i < lenght_simple; i++) {
        if ((PastSimple->user[i] >= 'A' && PastSimple->user[i] <= 'Z') || (PastSimple->user[i] >= 'a' && PastSimple->user[i] <= 'z')) {
            PastSimple->user[i] = tolower(PastSimple->user[i]); //Перевод введённых данных в нижний регистр
        } else {
            printf("!------------------------------------------------------------------------------------------!");
            printf("\n");
            printf("An invalid character was entered. Continue to be careful. We suggest you take the test again.\n");
            printf("!------------------------------------------------------------------------------------------!\n");
            return 1;
        }
    }

    for (i = 0; i < lenght_participle; i++) {
        if ((PastParticiple->user[i] >= 'A' && PastParticiple->user[i] <= 'Z')
            || (PastParticiple->user[i] >= 'a' && PastParticiple->user[i] <= 'z')) {
            PastParticiple->user[i] = tolower(PastParticiple->user[i]);
        } else {
            printf("!------------------------------------------------------------------------------------------!");
            printf("\n");
            printf("An invalid character was entered. Continue to be careful. We suggest you take the test again.\n");
            printf("!------------------------------------------------------------------------------------------!\n");
            return 1;
        }
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

int repeat_check(int arr[10], int line)
{
    for (int i = 0; i < 10; i++) {
        if (arr[i] == line)
            return 1;
    }
    return 0;
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
    int percentage = 0;
    float right_answers;
    int used[10]; //Массив, в который помещаются использованные строки

    memset(used, 0, 40); //заполняем массив нулями;

    for (i = 0; i < 10; i++) {
        printf("\n");
        clean_array(infinitive, PastSimple, PastParticiple);
        fseek(data, 0, SEEK_SET);

        current_line = 0;
        random_value = randomize(lines);

        if (repeat_check(used, random_value) == 1) {
            sleep(1);
            random_value = randomize(lines);
        }

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

        if (input_check(infinitive, PastSimple, PastParticiple) == 1)
            return 1;

        if (strcmp(PastSimple->expected, PastSimple->user) == 0) {
            right_answers++;
        }

        if (strcmp(PastParticiple->expected, PastParticiple->user) == 0) {
            right_answers++;
        }
        used[i] = random_value;
    }
    fclose(data);

    percentage_calculation(&percentage, right_answers);
    mark(&percentage);
    output(right_answers);

    return 0;
}

void percentage_calculation(int* percentage, float right_answers)
{
    float questions = 10;
    float one_percent;

    one_percent = (questions * 2) / 100;
    *percentage = right_answers / one_percent;
}

int mark(int* percentage)
{
    int mark = 0;

    printf("\n");
    printf("******************************************");
    printf("\n");
    printf("percentage of correct answers: %d", *percentage);
    printf("\n");

    if (*percentage < 50) {
        mark = 2;
        printf("very bad, your mark: %d\n", mark);
        printf("do not worry, next time you will");
    }

    if (*percentage > 49 && *percentage < 75) {
        mark = 3;
        printf("your mark: %d\n", mark);
        printf("not bad, but i'm sure you can do better");
    }

    if (*percentage > 74 && *percentage < 85) {
        mark = 4;
        printf("your mark: %d\n", mark);
        printf("your knowledge is high enough");
    }

    if (*percentage > 84) {
        mark = 5;
        printf("your mark: %d\n", mark);
        printf("excellent, well-known linguists could envy your knowledge");
    }

    printf("\n");
    printf("******************************************\n");

    return mark;
}

void output(float right_answers)
{
    printf("_______________________________________\n");
    printf("\n");
    printf("The number of correct answers: %0.f\n", right_answers);
    printf("_______________________________________\n");
}