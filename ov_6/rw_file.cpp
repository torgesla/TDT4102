#include "std_lib_facilities.h"
#include "rw_file.h"
void write_input_to_file()
{
    std::string input_string;
    std::string word;
    ofstream myfile;

    cout << "Write a string" << endl;
    do
    {
        cin >> word;
        if (word == "quit")
        {
            break;
        }
        input_string += " " + word;
    } while (true);
    myfile.open("task1.txt");
    myfile << input_string << endl;
    myfile.close();
}
void linjenummer()
{
    ifstream myReadFile;
    ofstream myWritefile;

    try
    {
        myReadFile.open("task2_in.txt");
        myWritefile.open("task2.txt");

        string line;
        string out_string = "";
        int i = 0;
        while (getline(myReadFile, line))
        {
            out_string += std::to_string(i) + ": " + line + "\n";
            i++;
        }
        myWritefile << out_string;
        myReadFile.close();
        myWritefile.close();
    }
    catch (const std::exception &e)
    {
        cout << "File doesn't exist" << endl;
    }
}
void countSymbols() // Funker
{
    ifstream readfile;
    char ch;
    int index;
    vector<int> counts(('z' + 1 - 'a'), 0);
    try
    {
        readfile.open("grunnlov.txt");
        while (!readfile.eof())
        {
            readfile >> ch;
            ch = tolower(ch);
            if (ch >= 'a' && ch <= 'z')
            {
                index = ch - 'a'; // a -> 0, b -> 1,...., z -> 25
                counts[index]++;
            }
        }
        for (int i = 0; i < counts.size(); i++)
        {
            cout << static_cast<char>(i + 'a') << ": " << counts[i] << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "File don't exist" << endl;
    }
}
