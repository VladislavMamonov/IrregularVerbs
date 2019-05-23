#ifndef IRREGULAR_VERBS_H
#define IRREGULAR_VERBS_H

#define n 30

struct IrregularVerbs {
    char user[n], expected[n];
};

void welcome();
int input(struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple);
int randomize(int lines);
int CheckData(char *str, struct IrregularVerbs* infinitive, struct IrregularVerbs* PastSimple, struct IrregularVerbs* PastParticiple);
#endif