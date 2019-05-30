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

CTEST(mark_test, intersection_check_test1)
{
    //Given
    int percentage1 = 49;
    int percentage2 = 50;
    int percentage3 = 74;
    int percentage4 = 75;
    int percentage5 = 84;
    int percentage6 = 85;

    //When
    const int result1 = mark(&percentage1);
    const int result2 = mark(&percentage2);
    const int result3 = mark(&percentage3);
    const int result4 = mark(&percentage4);
    const int result5 = mark(&percentage5);
    const int result6 = mark(&percentage6);
    //Then
    ASSERT_EQUAL(2, result1);
    ASSERT_EQUAL(3, result2);
    ASSERT_EQUAL(3, result3);
    ASSERT_EQUAL(4, result4);
    ASSERT_EQUAL(4, result5);
    ASSERT_EQUAL(5, result6);
}




