// P02 Weekly Pay Calculator - Thane Reynolds
/*
This program is used by employees to determine what their weekly net pay would be based on their hourly rate and number of hours worked
*/
#include <iostream>
using namespace std;

int main()
{
    //Declare constants using the const modifier
    //Constants are named using all capital letters
    //There are two ways of assigning values: using an equal sign = or using parenthesis ()
    const double UNION_DUES = 10.00, FICA_RATE = 0.06,
        FEDERAL_RATE (0.15), STATE_RATE = (0.05);

    //Define Variables
    //Variables that change value are in lowercase
    int hours;
    double rate, gross, fica, federal, state, netPay, netHourly;

    //Set decimal point to 2 positions
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Display name and the input prompt
    cout << "P02 - Thane Reynolds \n\n"
        << "Enter the hourly rate and the number of hours \n"
        << "worked on the same line, but seperated by a space. \n"
        << "Preess the enter key after entering both values."
        << endl << endl
        << "Enter the hourlyrate and hours worked: ";

    //get the input values
    cin >> rate >> hours;

    // Calculate gross, taxes, netPay, and netHourly
    gross = rate * hours;
    fica = gross * FICA_RATE;
    federal = gross * FEDERAL_RATE;
    state = gross * STATE_RATE;
    netPay = gross - (fica + federal + state + UNION_DUES);
    netHourly = netPay / hours;

    //Display the results and echo the input (rate and hours)
    //Display the values stored in constants
    //Use the space bar between : and\t in labels instead of the tab key for accurate alignment
    cout << endl
        << "Hourly Rate: \t" << rate << endl
        << "Hours Worked: \t" << hours << endl
        << "Gross Pay: \t" << gross << endl
        << "FICA Tax: \t" << fica << " at " << FICA_RATE << endl
        << "Federal Tax: \t" << federal << " at " << FEDERAL_RATE << endl
        << "State Tax: \t" << state << " at " << STATE_RATE << endl
        << "Union Dues: \t" << UNION_DUES << endl
        << "Net Pay: \t" << netPay << endl
        << "Net Hourly: \t" << netHourly << endl;

    cout << "\nThank you!\n\n";
    return 0;
}
//end of main


