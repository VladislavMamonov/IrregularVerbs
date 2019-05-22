#include "IrregularVerbs.h"
#include <stdio.h>

int main()
{
    struct IrregularVerbs infinitive, PastSimple, PastParticiple;

    welcome();

    input(&infinitive, &PastSimple, &PastParticiple);

    char str[100];
    CheckData(str);
    printf("%s", str);

    return 0;
}