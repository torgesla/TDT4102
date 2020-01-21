int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int &startvalue, int increment, int numTimes);
void swapNumbers(int &a, int &b);
void randomizeVector(vector<int> &vector, int n);
void sortVector(vector<int> &A);
double medianOfVector(vector<int> vektor);
struct Student
{
    string name;
    int age;
    string studyProgram;
};
void printStudent(Student student);
string randomizeString(int number_of_chars, char lower_limit, char upper_limit);
bool validateInput(char C, int lower_limit, int upper_limit);
string readInputToString(int n, char lower_limit, char upper_limit);
int countChar(string input_string, char input_char);