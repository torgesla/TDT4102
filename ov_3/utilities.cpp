#include <cstdlib>
#include "std_lib_facilities.h"
#include "cannonball.h"
int randomWithLimits(int lower_limit, int upper_limit)
{
    return rand() % upper_limit + lower_limit;
}
void playTargetPractice()
{
    double distanceToTarget = (double)randomWithLimits(100, 1000);
    cout << distanceToTarget << endl;
    double theta, absVelocity;

    for (int i = 2; i >= 0; i--)
    {
        double theta = getUserInputTheta();
        double absVelocity = getUserInputAbsVelocity();

        vector<double> velocityVector = getVelocityVector(theta, absVelocity);
        double distanceFromTarget = targetPractice(distanceToTarget, velocityVector[0], velocityVector[1]);

        if (abs(distanceFromTarget) < 5)
        {
            cout << "Gratulerer, du vant med " << i << " forsøk igjen." << endl;
            break;
        }
        else
        {
            cout << "Feil, du skjøt " << distanceFromTarget << " meter for kort\nDu har " << i << " forsøk igjen." << endl;
        }
        if (i == 0)
        {
            cout << "BEKLAGER, DU ER TOM FOR FORSØK!".toupper() << endl;
        }
    }
}