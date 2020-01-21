#include "std_lib_facilities.h"
#include <cctype>
#include "tests.h"
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
void printStudent(Student student)
{
    cout << "Name: " << student.name << "\nStudy program: " << student.studyProgram << "\nAge: " << student.age << endl;
}
string randomizeString(int number_of_chars, char lower_limit, char upper_limit)
{
    string outputString;
    for (int i = 0; i < number_of_chars; i++)
    {
        char character = rand() % (1 + upper_limit - lower_limit) + lower_limit;
        outputString.push_back(character);
    }
    return outputString;
}
bool validateInput(char C, int lower_limit, int upper_limit)
{
    if ((toupper(C) > lower_limit - 1 && toupper(C) < upper_limit + 1) || (tolower(C) > lower_limit && tolower(C) < upper_limit))
    {
        return true; // Return true if input_char is contained in interval.
    }
    else
    {
        return false;
    }
}
string readInputToString(int n, char lower_limit, char upper_limit)
{
    string outputString = "";
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            char input_char;
            cout << "Write a char:\t";
            cin >> input_char;
            if (validateInput(input_char, lower_limit, upper_limit))
            {
                outputString += input_char;
                break;
            }
            else
            {
                cout << "Invalid char" << endl;
            }
        }
    }
    return outputString;
}
int countChar(string input_string, char input_char)
{
    int counter = 0;
    for (int i = 0; i < input_string.size(); i++)
    {
        if ((char)input_string[i] == input_char)
        {
            counter++;
        }
    }
    return counter;
}
