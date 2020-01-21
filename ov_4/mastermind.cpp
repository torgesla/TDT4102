#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"
int checkCharacterAndPosition(string code, string guess)
{
    int counter = 0;
    for (int i = 0; i < code.size(); i++)
    {
        if (code[i] == guess[i])
        {
            counter++;
        }
    }
    return counter;
}
int checkCharacters(string code, string guess)
{
    int counter = 0;
    for (int i = 0; i < code.size(); i++)
    {
        for (int j = 0; j < guess.size(); j++)
        {
            if (code[i] == guess[j])
            {
                counter++;
                break;
            }
        }
    }
    return counter;
}
void playMastermind()
{
    // Hvorfor bruker vi constexpr, og ikke const?
    constexpr int size = 4;
    constexpr int letters = 6;
    string code;
    string guess;
    int num_of_tries = 0;
    int max_num_tries = 2; // Max number of tries,
    int correct = -1;
    int correctLetters = -1;

    code = randomizeString(size, 'A', 'A' + letters - 1);

    while (correct < size && num_of_tries < max_num_tries)
    {

        guess = readInputToString(size, 'A', 'A' + letters - 1);
        cout << guess << endl;
        correct = checkCharacterAndPosition(code, guess);
        correctLetters = checkCharacters(code, guess);

        cout << "You had " << correct << " correct letter(s) at the correct spot, and in addition " << correctLetters - correct << " correct letter(s)." << endl;
        cout << " What's your next guess?" << endl;
        num_of_tries++;
    }
    if (num_of_tries < max_num_tries)
    {
        cout << "Congrats, everything was correct, you used " << num_of_tries << " tries" << endl;
    }
    else
    {
        cout << "\nSorry, you used too many tries. GAME OVER!" << endl;
    }
    keep_window_open();
}
