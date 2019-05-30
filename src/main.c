#include "IrregularVerbs.h"
#include <stdio.h>

int main()
{
    struct IrregularVerbs infinitive, PastSimple, PastParticiple;

    welcome();

    check_data(&infinitive, &PastSimple, &PastParticiple);

    return 0;
}