
#include "std_lib_facilities.h"
/* #include <cstdlib>
#include <stdlib.h> */

#include "cannonball.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name)
{
    cout << name << endl;
    double difference = abs(compareOperand - toOperand);
    if (difference <= maxError)
    {
        cout << "The numbers are the same" << endl;
    }
    else
    {
        cout << "The numbers are not the same" << endl;
    }
}

int main()
{
    srand(time(NULL));
    playTargetPractice();
    keep_window_open();
}