//P03.cpp: P03 Employee Weekly Pay Calculator with Data Validation - Thane Reynolds

/*
    This program will help employees determine weekly net pay based on hourly rate and hours worked. This will validate that their pay rate and hours are within the allowable ranges.
*/

#include <iostream>
using namespace std;

int main()
{
    //Declare constants
    const double UNION_DUES = 10.00, FICA_RATE = 0.06, OVERTIME_RATE = 1.5, FEDERAL_RATE = 0.15, STATE_RATE = 0.05, MIN_PAY = 10.00, MAX_PAY = 15.00;
    const int MAX_NORMAL_HOURS = 40;

    //declare variables, initialize input with 0 to avoid undefined values
    double hourlyRate = 0.00, fica, federal, state, netPay, netHourly, grossPay;
    int hours = 0;

    //set decimal precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Take input from employee for pay
    do
    {
        cout << "Please enter your hourly rate between $10.00 and $15.00: $";
        cin >> hourlyRate;
        cout << endl;
    } while (hourlyRate < MIN_PAY || hourlyRate > MAX_PAY);

    //Take input from employee for hours
    while (hours < 1 || hours >50)
    {
        cout << "Please enter your hours worked between 1 and 50: ";
        cin >> hours;
        cout << endl;
    }

    //Calculate gross pay
    if (hours > MAX_NORMAL_HOURS)
    {
        grossPay = (MAX_NORMAL_HOURS * hourlyRate) + ((hours - MAX_NORMAL_HOURS) * hourlyRate * OVERTIME_RATE);
    }
    else
    {
        grossPay = hours * hourlyRate;
    }

    //Calculate Fees and net pay
    fica = grossPay * FICA_RATE;
    federal = grossPay * FEDERAL_RATE;
    state = grossPay * STATE_RATE;
    netPay = grossPay - fica - federal - state - UNION_DUES;
    netHourly = netPay / hours;

    //display output for the employee
    cout << endl
        << "Hourly Rate: \t" << hourlyRate << endl
        << "Hours Worked: \t" << hours << endl
        << "Gross Pay: \t" << grossPay << endl
        << "FICA Tax: \t" << fica << " at " << FICA_RATE << endl
        << "Federal Tax: \t" << federal << " at " << FEDERAL_RATE << endl
        << "State Tax: \t" << state << " at " << STATE_RATE << endl
        << "Union Dues: \t" << UNION_DUES << endl
        << "Net Pay: \t" << netPay << endl
        << "Net Hourly: \t" << netHourly << endl
        << endl
        << "Thank you!" << endl;

    //end main
    return 0;
}


