#include "IrregularVerbs.h"
#include <stdio.h>

int main()
{
    struct IrregularVerbs infinitive, PastSimple, PastParticiple;

    welcome();

    char str[100] = {'\0'};

    check_data(str, &infinitive, &PastSimple, &PastParticiple);

    return 0;
}