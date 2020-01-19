#include "std_lib_facilities.h"
#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
    return startValue;
}
void incrementByValueNumTimesRef(int &startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
}
void swapNumbers(int &a, int &b) // Denne funksjonen bruker references, fordi vi ønsker å "returnere" flere verdier.
{
    int temp = a; // Temporary storage of a's old value

    a = b;
    b = temp;
}
void randomizeVector(vector<int> &vector, int n)
{
    for (int i = 0; i < n; i++)
    {
        vector.push_back(rand() % 100); // Adds a number [0,100]
    }
}
void sortVector(vector<int> &A)
{
    int i = 1;
    while (i < A.size())
    {
        int j = i;
        while (j > 0 && A[j - 1] > A[j])
        {
            swapNumbers(A[j], A[j - 1]);
            j -= 1;
        }
        i += 1;
    }
}
double medianOfVector(vector<int> vektor)
{
    int i = vektor.size() / 2; // int / int = int
    if (vektor.size() == 0)
    {
        return NULL;
    }
    else if (vektor.size() % 2 == 1)
    {
        return vektor[i];
    }
    else
    {
        return (vektor[i - 1] + vektor[i]) / 2;
    }
}
struct Student
{
    string name;
    string studyProgram;
    int age;
};
void printStudent(Student student)
{
    cout << "Name: " << student.name << "\nStudy program: " << student.studyProgram << "\nAge: " << student.age << endl;
}
