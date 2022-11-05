//P05.cpp: P05 Employee Weekly Pay Calculator with Call-By-Value - Thane Reynolds

/*
    This program will help employees determine weekly net pay based on hourly rate and hours worked. This will validate that their pay rate and hours are within the allowable ranges.
*/

#include <iostream>

double inputRate(); // takes in rate and validates between min and max ranges
double inputHours(); // takes in hours and validates between min and max ranges
double calcGross(double rate, double hours); // determines gross rate, looks at overtime
double calcTax(double gross, double taxRate); // determines what the specific tax amount is for the rate input
const double OVERTIME_RATE = 1.5;

int main()
{
    using namespace std;
    //Declare constants
    const double UNION_DUES = 10.00, FICA_RATE = 0.06, FEDERAL_RATE = 0.15, STATE_RATE = 0.05;

    //declare variables, initialize input with 0 to avoid undefined values
    double hourlyRate = 0.00, fica, federal, state, netPay, netHourly, grossPay;
    double hours = 0.00;

    //set decimal precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Take input from employee for pay using inputRate()
    hourlyRate = inputRate();

    //Take input from employee for hours using inputHours()
    hours = inputHours();

    //Calculate gross pay using calcGross()
    grossPay = calcGross(hourlyRate, hours);

    //Calculate taxes using calcTax()
    fica = calcGross(grossPay, FICA_RATE);
    federal = calcGross(grossPay, FEDERAL_RATE);
    state = calcGross(grossPay, STATE_RATE);
    //Calculate net pay
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
double inputRate()
{
    using namespace std;
    const double MIN_PAY = 10.00, MAX_PAY = 15.00;
    double hourlyRate = 0.00;
    //Take input from employee for pay
    do
    {
        cout << "Please enter your hourly rate between $10.00 and $15.00: $";
        cin >> hourlyRate;
        cout << endl;
    } while (hourlyRate < MIN_PAY || hourlyRate > MAX_PAY);
    
    //end inputRate
    return hourlyRate;
}
double inputHours()
{
    using namespace std;
    const int MIN_HOURS= 1, MAX_TOTAL_HOURS = 50;
    double hours = 0.00;

    //Take input from employee for hours and validate that the hours are within ranges
    while (hours < MIN_HOURS || hours > MAX_TOTAL_HOURS)
    {
        cout << "Please enter your hours worked between 1 and 50: ";
        cin >> hours;
        cout << endl;
    }

    //end inputHours
    return hours;
}
double calcGross(double rate, double hours)
{
    using namespace std;
    const int MAX_NORMAL_HOURS = 40;
    double grossPay = 0.00;

    //calculate gross pay, determine if overtime rate applies or not
    if (hours > MAX_NORMAL_HOURS)
    {
        grossPay = (MAX_NORMAL_HOURS * rate) + ((hours - MAX_NORMAL_HOURS) * rate * OVERTIME_RATE);
    }
    else
    {
        grossPay = hours * rate;
    }

    //end calcGross
    return grossPay;
}
double calcTax(double gross, double taxRate)
{
    using namespace std;
    double taxesDue = 0.00;
    //calculate taxes, generic name so that no confusion, any tax can be put in this
    taxesDue = gross * taxRate;
    
    //end caclTax
    return taxesDue;
}
