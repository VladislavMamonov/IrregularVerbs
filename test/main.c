#define CTEST_MAIN
#define CTEST_COLOR_OK

#include <ctest.h>
#include <IrregularVerbs.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(input_test, input_Error_PastSimple_test)
{
    // Given
    struct IrregularVerbs infinitive;
    struct IrregularVerbs PastSimple;
    struct IrregularVerbs PastParticiple;


    //When
    const int result = input(&infinitive, &PastSimple, &PastParticiple);

    //Then
    ASSERT_EQUAL(1, result); //FALSE
}
    
CTEST(input_test, True_PastSimple_test)
{
    //Given
    struct IrregularVerbs infinitive;
    struct IrregularVerbs PastSimple;
    struct IrregularVerbs PastParticiple;

    //When
    const int result = input(&infinitive, &PastSimple, &PastParticiple);

    //Then
    ASSERT_EQUAL(0, result); //TRUE
}

