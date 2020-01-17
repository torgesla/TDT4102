//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include <iomanip>
#include "Graph.h"
#include "Simple_window.h"

void inputAndPrintInteger()
{
	cout << "Write a number: ";
	int number;
	cin >> number;
	cout << "Your number is: " << number << "\n";
}
int inputInteger()
{
	cout << "Write a number: ";
	int number;
	cin >> number;
	return number;
}
void inputIntegersAndPrintSum()
{
	int a = inputInteger();
	int b = inputInteger();
	cout << "Sum av " << a << " og " << b << " er " << a + b;
}
/*Fordi inputInteger lar deg bruke input-verdien videre ved å returnere*/
bool isOdd(int n)
{
	return n % 2 != 0;
}
void printHumanReadableTime(int sek)
{
	int h = sek / 3600;
	int m = sek % 3600 / 60;
	int s = sek - h * 3600 - m * 60;
	cout << h << ":" << m << ":" << s;
}
int sumNumbers(int n)
{
	int number;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "Skriv tall: ";
		cin >> number;
		total += number;
	}
	cout << total << "\n";
	keep_window_open();
}
int sumUntilZero()
{
	int number;
	int total = 0;
	while (number != 0)
	{
		cout << "Skriv tall: ";
		cin >> number;
		total += number;
	}
	cout << total << "\n";
	keep_window_open();
}
double inputDouble()
{
	double number;
	cout << "Write a number: ";
	cin >> number;
	return number;
}
double convert_NOK_to_EUR()
{
	double ex_rate = 9.75;
	double nok = -1;
	while (nok < 0)
	{
		nok = inputDouble();
	}
	return nok / ex_rate;
}

double discriminant(double a, double b, double c) { return pow(b, 2) - 4 * a * c; }
void printRealRoots(double a, double b, double c)
{
	double disc = discriminant(a, b, c);
	cout << disc << endl;
	if (disc > 0)
	{
		cout << (-b + pow(discriminant(a, b, c), 1 / 2)) / (2 * a) << endl;
		cout << (-b - pow(discriminant(a, b, c), 1 / 2)) / (2 * a) << endl;
	}
	else if (disc == 0)
	{
		cout << -b / (2 * a) << endl;
	}
	else
	{
		cout << "No real solution" << endl;
	}
}
void solveQuadraticEquation()
{
	double a;
	double b;
	double c;
	cout << "Skriv inn a, b og c adskilt av *enter*:" << endl;

	cin >> a;
	cin >> b;
	cin >> c;

	printRealRoots(a, b, c);
} /*Til første oppgave egner for-loop seg fordi vi vet hvor mange iterasjoner den skal ha,
på andre oppgave kan den potesielt ha uendelig antall iterasjoner, derfor while-loop */

void menu()
{
	int choice;
	cout << "Velg funksjon:\n\
	0) Avslutt\n\
	1) Summer to tall\n\
	2) Summer flere tall\n\
	3) Konverter NOK til EURO.\n\
	4) QuadaticEq\n";
	while (true)
	{
		cout << "Angi valg (0-4):\n";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		else if (choice == 1)
		{
			sumNumbers(2);
		}
		else if (choice == 2)
		{
			sumUntilZero();
		}
		else if (choice == 3)
		{
			convert_NOK_to_EUR();
		}
		else if (choice == 4)
		{
			solveQuadraticEquation();
		}
		else
		{
			cout << "Invalid input";
		}
	}
}
void pythagoras()
{
	Simple_window win{Point{10, 10}, 1000, 1000, "Pythagoras"};

	Polygon rightTriangle;
	// Triangle
	rightTriangle.add(Point{400, 200}); // top left edge
	rightTriangle.add(Point{400, 400}); // bottom left edge
	rightTriangle.add(Point{700, 400}); // right most edge
	rightTriangle.set_fill_color(Color::red);
	win.attach(rightTriangle);

	// Left most square
	Polygon square1;
	square1.add(Point{400, 200});
	square1.add(Point{400, 400});
	square1.add(Point{200, 400});
	square1.add(Point{200, 200});
	square1.set_fill_color(Color::blue);
	win.attach(square1);

	// Bottom square
	Polygon square2;
	square2.add(Point{400, 400});
	square2.add(Point{700, 400});
	square2.add(Point{700, 700});
	square2.add(Point{400, 700});
	square2.set_fill_color(Color::green);
	win.attach(square2);

	// Hypothenous square
	Polygon square3;
	square3.add(Point{400, 200});
	square3.add(Point{700, 400}); // Lengde = 360.56
	square3.add(Point{900, 100});
	square3.add(Point{600, -100});
	square3.set_fill_color(Color::yellow);
	win.attach(square3);

	win.wait_for_button();
}
vector<double> calculateSeries(double totalt_lan, double rente, int antall_ar) // rente er et desimaltall f.eks 0.03 = 3%
{
	vector<double> innbetalings_vector;
	double gjenstaende_lan = totalt_lan;

	int antall_avdrag = antall_ar;

	double avdrag = totalt_lan / antall_avdrag;

	for (int i = 0; i < antall_ar; i++)
	{
		innbetalings_vector[i] = avdrag + rente * gjenstaende_lan; // Fra formel for serielån
		gjenstaende_lan -= avdrag;
	}
	return innbetalings_vector;
}
vector<double> calculateAnnuity(double totalt_lan, double rente, int antall_ar)
{
	vector<double> innbetalings_vector;

	for (int i = 0; i < antall_ar; i++)
	{
		innbetalings_vector[0] = totalt_lan * rente / (1 - pow(1 + rente, -antall_ar));
	}
	return innbetalings_vector;
}
void printLan(double totalt_lan, double rente, int antall_ar)
{
	double serie_total = 0;
	double annuitet_total = 0;
	vector<double> serielan_innbetalinger = calculateSeries(totalt_lan, rente, antall_ar);
	vector<double> annuitetslan_innbetalinger = calculateAnnuity(totalt_lan, rente, antall_ar);
	cout << "År"
		 << "Annuitet"
		 << "Serie"
		 << "Differanse" << endl;
	for (int i = 0; i < serielan_innbetalinger.size(); i++)
	{
		double serie = serielan_innbetalinger[i];
		double annuitet = annuitetslan_innbetalinger[i];
		serie_total += serie;
		annuitet_total += annuitet;
		cout << i + 1 << annuitet << serie << annuitet - serie << endl;
	}
	cout << "Totalt" << annuitet_total << serie_total << annuitet_total - serie_total << endl;
}
int main()
{
	//inputAndPrintInteger();
	//cout << inputInteger();
	//cout << isOdd(7) << "\n";
	//printHumanReadableTime(10000);
	//sumNumbers(5);
	//sumUntilZero();
	//cout << inputDouble() << "\n";
	// pythagoras();
	// calculateSeries(10000, 5, 10);
	// calculateAnnuity(10000, 5, 10);
	//menu();
}