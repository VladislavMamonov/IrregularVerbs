#include "IrregularVerbs.h"
#include <stdio.h>

int main()
{
    struct IrregularVerbs infinitive, PastSimple, PastParticiple;

    welcome();

    input(&infinitive, &PastSimple, &PastParticiple);

    char str[100] = "hello";
    CheckData(str);

    return 0;
}