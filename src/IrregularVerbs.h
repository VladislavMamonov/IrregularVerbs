#ifndef IRREGULAR_VERBS_H
#define IRREGULAR_VERBS_H

#define n 100

struct IrregularVerbs {
    char user[n], expected[n];
};

void welcome();
void input(struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple);
int input_check(struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple);
int randomize(int lines);
void clean_array(struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple);
int repeat_check(int arr[10], int line);
int check_data(char* str, struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple);
void percentage_calculation(int *percentage, float right_answers);
int mark(int *percentage);
void output(float right_answers);

#endif