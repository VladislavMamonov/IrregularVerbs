#define CTEST_MAIN
#define CTEST_COLOR_OK

#include <ctest.h>
#include <IrregularVerbs.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(input_check_test, Input_Error_PastSimple_test)
{
    // Given
    struct IrregularVerbs infinitive;
    struct IrregularVerbs PastSimple;
    struct IrregularVerbs PastParticiple;

    char INF[n] = "give";
    char PS[n] = "2,.%#@&*!$^&*()_-+=./3абвгДЁ~`";
    char PP[n] = "given";

    strcpy(infinitive.expected, INF);
    strcpy(PastSimple.user, PS);
    strcpy(PastParticiple.user, PP);


    //When
    const int result = input_check(&infinitive, &PastSimple, &PastParticiple);

     //Then
    ASSERT_EQUAL(1, result); 
}

CTEST(input_check_test, Input_Error_PastParticiple_test)
{
    //Given
    struct IrregularVerbs infinitive;
    struct IrregularVerbs PastSimple;
    struct IrregularVerbs PastParticiple;

    char INF[n] = "give";
    char PS[n] = "gave";
    char PP[n] = "GenaBukin3000";

    strcpy(infinitive.expected, INF);
    strcpy(PastSimple.user, PS);
    strcpy(PastParticiple.user, PP);

    //When
    const int result = input_check(&infinitive, &PastSimple, &PastParticiple);

    //Then
    ASSERT_EQUAL(1, result);
}

CTEST(input_check_test, Correct_Input_test)
{
    //Given
    struct IrregularVerbs infinitive;
    struct IrregularVerbs PastSimple;
    struct IrregularVerbs PastParticiple;

    char INF[n] = "give";
    char PS[n] = "gave";
    char PP[n] = "given";

    strcpy(infinitive.expected, INF);
    strcpy(PastSimple.user, PS);
    strcpy(PastParticiple.user, PP);

    //When
    const int result = input_check(&infinitive, &PastSimple, &PastParticiple);

    //Then
    ASSERT_EQUAL(0, result); 
}

CTEST(repeat_check_test, comparison_test)
{
    //Given
    int arr[10];
    int line = 1;
    arr[5] = 1;

    //When
    const int result = repeat_check(&arr[10], line);

    //Then
    ASSERT_EQUAL(1, result);
}



