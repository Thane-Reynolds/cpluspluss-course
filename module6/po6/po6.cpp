//P06.cpp: P06 Employee Weekly Pay Calculator with Call-By-Reference and Pointers - Thane Reynolds

/*
    This program will help employees determine weekly net pay based on hourly rate and hours worked. This will validate that their pay rate and hours are within the allowable ranges.
*/

#include <iostream>

void inputRate(double& rate); // takes in rate and validates between min and max ranges
void inputHours(int& hours); // takes in hours and validates between min and max ranges
void calcGross(double rate, int hours, double& gross); // determines gross rate, looks at overtime
void calcTax(double gross, double taxRate, double *taxAmount); // determines what the specific tax amount is for the rate input
const double OVERTIME_RATE = 1.5;

int main()
{
    using namespace std;
    //Declare constants
    const double UNION_DUES = 10.00, FICA_RATE = 0.06, FEDERAL_RATE = 0.15, STATE_RATE = 0.05;

    //declare variables, initialize input with 0 to avoid undefined values
    double hourlyRate = 0.00, fica, federal, state, netPay, netHourly, grossPay;
    int hoursWorked = 0;

    //set decimal precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Take input from employee for pay using inputRate()
    inputRate(hourlyRate);

    //Take input from employee for hours using inputHours()
    inputHours(hoursWorked);

    //Calculate gross pay using calcGross()
    calcGross(hourlyRate, hoursWorked, grossPay);

    //Calculate taxes using calcTax()
    calcTax(grossPay, FICA_RATE, &fica);
    calcTax(grossPay, FEDERAL_RATE, &federal);
    calcTax(grossPay, STATE_RATE, &state);
    //Calculate net pay
    netPay = grossPay - fica - federal - state - UNION_DUES;
    netHourly = netPay / hoursWorked;

    //display output for the employee
    cout << endl
        << "Hourly Rate: \t" << hourlyRate << endl
        << "Hours Worked: \t" << hoursWorked << endl
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
void inputRate(double& rate)
{
    using namespace std;
    const double MIN_PAY = 10.00, MAX_PAY = 15.00;
    //Take input from employee for pay
    do
    {
        cout << "Please enter your hourly rate between $10.00 and $15.00: $";
        cin >> rate;
        cout << endl;
    } while (rate < MIN_PAY || rate > MAX_PAY);
}
void inputHours(int& hours)
{
    using namespace std;
    const int MIN_HOURS = 1, MAX_TOTAL_HOURS = 50;

    //Take input from employee for hours and validate that the hours are within ranges
    while (hours < MIN_HOURS || hours > MAX_TOTAL_HOURS)
    {
        cout << "Please enter your hours worked between 1 and 50: ";
        cin >> hours;
        cout << endl;
    }
}
void calcGross(double rate, int hours, double& gross)
{
    using namespace std;
    const int MAX_NORMAL_HOURS = 40;

    //calculate gross pay, determine if overtime rate applies or not
    if (hours > MAX_NORMAL_HOURS)
    {
        gross = (MAX_NORMAL_HOURS * rate) + ((hours - MAX_NORMAL_HOURS) * rate * OVERTIME_RATE);
    }
    else
    {
        gross = hours * rate;
    }
}
void calcTax(double gross, double taxRate, double *taxAmount)
{
    using namespace std;
    //calculate taxes, generic name so that no confusion, any tax can be put in this
    *taxAmount = gross * taxRate;
}

