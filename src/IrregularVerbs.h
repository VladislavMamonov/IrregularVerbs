#ifndef IRREGULAR_VERBS_H
#define IRREGULAR_VERBS_H

#define n 30

struct IrregularVerbs {
	char user[n], expected[n];
}; 

void welcome();
int input(struct IrregularVerbs* present, struct IrregularVerbs* past, struct IrregularVerbs* future);

#endif