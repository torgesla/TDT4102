#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"

void testCallByValue()
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}
void testCallByReference()
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << v0 << endl;
}
void testSwap()
{
    int a = 3;
    int b = 4;
    swapNumbers(a, b);
    cout << "a:" << a << "\nb:" << b << endl;
}
void testVectorSorting()
{
    vector<int> percentages;
    int n = 9; // Kan endres

    randomizeVector(percentages, n);

    sortVector(percentages); // Sort by reference

    for (int i = 0; i < percentages.size(); i++)
    {
        cout << percentages[i] << ", ";
    }
    cout << "Median element is: " << medianOfVector(percentages) << endl;
    //swapNumbers(percentages[0], percentages[1]);
}
void testString()
{
    string grades;
    vector<int> gradeCount;
    grades = randomizeString(80, 'A', 'F');

    for (char grade = 'F'; grade >= 'A'; grade--)
        gradeCount.push_back(countChar(grades, grade));
    int sum = 0;
    for (int i = 0; i < gradeCount.size(); i++)
    {
        sum += i * gradeCount[i];
    }
    cout << sum / grades.size() << endl;
}
