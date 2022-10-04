// P04 - Monthend Payroll Loop - Thane Reynolds
//This program calculates gross pay for the month by taking in weekly hours worked and hourly pay per employee.

#include <iostream>
using namespace std;

int main()
{
    //declare variables
    double totalGrossBase = 0.00, totalGrossOverTime = 0.00, totalGrossDoubleTime = 0.00, totalGrossPaid = 0.00, averageGross =0.00;
    int numberEmployees = 0, totalHoursWorked =0;
    // current pay ranges
    const double MIN_RATE = 5.25, MAX_RATE = 30.00;
    //current time branches
    const int MAX_NORMAL_TIME = 40, MAX_OVERTIME = 50, MAX_DOUBLETIME = 60;
    //rates for overtime
    const double OVERTIME_RATE = 1.5, DOUBLETIME_RATE = 2.0;

    //set decimal precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);


    //prompt for number of employees
    cout << "Please enter the number of employees to calculate gross pay." << endl
        << "Enter 0 (zero) to exit: ";
    cin >> numberEmployees;
    //If statement to check for valid number
    if (numberEmployees < 0)
    {
        cout << "ERROR: Invalid number of employees entered";
    }
    else
    {
        //while loop to calculate all employee's gross pay
        int count = 1;
        while (count <= numberEmployees)
        {
            double hourlyRate = 0.00,
                weekOneRegPay = 0.00, weekOneOverPay = 0.00, weekOneDoublePay = 0.00, weekOneTotal,
                weekTwoRegPay = 0.00, weekTwoOverPay = 0.00, weekTwoDoublePay = 0.00, weekTwoTotal,
                weekThreeRegPay = 0.00, weekThreeOverPay = 0.00, weekThreeDoublePay = 0.00, weekThreeTotal,
                weekFourRegPay = 0.00, weekFourOverPay = 0.00, weekFourDoublePay = 0.00, weekFourTotal,
                totalRegPay = 0.00, totalOverPay = 0.00, totalDoublePay = 0.00, empTotal = 0.00;
            int weekOneHours = 0, weekTwoHours = 0, weekThreeHours = 0, weekFourHours = 0, totalHours = 0, numWeeks = 4;
            bool validRate = false, validHours = false;
            //prompt for hourly rate
            while (validRate == false)
            {
                cout << endl 
                    << "P04 - Thane Reynolds \t\t" << "Employee:" << count << endl << endl
                    << "Please provide the hourly rate for Employee #" << count << endl;
                cin >> hourlyRate;
                //determine if rate is valid, valid ranges are currently $5.25 - $30.00
                if (hourlyRate >= MIN_RATE && hourlyRate <= MAX_RATE)
                {
                    validRate = true;
                }
                else
                {
                    cout << "ERROR: Hourly rate must be between $" << MIN_RATE << " and $" << MAX_RATE << endl;
                    validRate = false;
                }

            }
            //prompt for hours worked per week, using 4 weeks
            cout << "Enter hours worked by week for 4 weeks, seperated by a space (0-60): ";
            cin >> weekOneHours
                >> weekTwoHours
                >> weekThreeHours
                >> weekFourHours;
            while (validHours == false)
            {
                if (weekOneHours < 0 || weekTwoHours < 0 || weekThreeHours < 0 || weekFourHours < 0)
                {
                cout << "You have entered less than 0 hours, this is invaild input" << endl
                     << "Enter hours worked by week for 4 weeks, seperated by a space (0-60): ";
                cin >> weekOneHours
                    >> weekTwoHours
                    >> weekThreeHours
                    >> weekFourHours;
                }
                else if (weekOneHours > 60 || weekTwoHours > 60 || weekThreeHours > 60 || weekFourHours > 60)
                {
                    cout << "You have entered more than 60 hours, this is invailid input" << endl
                        << "Enter hours worked by week for 4 weeks, seperated by a space (0-60): ";
                    cin >> weekOneHours
                       >> weekTwoHours
                       >> weekThreeHours
                       >> weekFourHours;
                }
                else
                    validHours = true;
                }
             //total hours for later
             totalHours = weekOneHours + weekTwoHours + weekThreeHours + weekFourHours;
             //check for overtime and pay overtime rates
             //week 1
             if (weekOneHours <= MAX_NORMAL_TIME)
             {
                 weekOneRegPay = weekOneHours * hourlyRate;
             }
             else if (weekOneHours <= MAX_OVERTIME)
             {
                 weekOneRegPay = MAX_NORMAL_TIME * hourlyRate;
                 weekOneOverPay = (weekOneHours - MAX_NORMAL_TIME) * hourlyRate * OVERTIME_RATE;
             }
             else
             {
                 weekOneRegPay = MAX_NORMAL_TIME * hourlyRate;
                 weekOneOverPay = (MAX_OVERTIME - MAX_NORMAL_TIME) * hourlyRate * OVERTIME_RATE;
                 weekOneDoublePay = (weekOneHours - MAX_OVERTIME) * hourlyRate * DOUBLETIME_RATE;
             }
             //week 2
             if (weekTwoHours <= MAX_NORMAL_TIME)
             {
                 weekTwoRegPay = weekTwoHours * hourlyRate;
             }
             else if (weekTwoHours <= MAX_OVERTIME)
             {
                 weekTwoRegPay = MAX_NORMAL_TIME * hourlyRate;
                 weekTwoOverPay = (weekTwoHours - MAX_NORMAL_TIME) * hourlyRate * OVERTIME_RATE;
             }
             else
             {
                 weekTwoRegPay = MAX_NORMAL_TIME * hourlyRate;
                 weekTwoOverPay = (MAX_OVERTIME - MAX_NORMAL_TIME) * hourlyRate * OVERTIME_RATE;
                 weekTwoDoublePay = (weekTwoHours - MAX_OVERTIME) * hourlyRate * DOUBLETIME_RATE;
             }
             //week 3
             if (weekThreeHours <= MAX_NORMAL_TIME)
             {
                 weekThreeRegPay = weekThreeHours * hourlyRate;
             }
             else if (weekThreeHours <= MAX_OVERTIME)
             {
                 weekThreeRegPay = MAX_NORMAL_TIME * hourlyRate;
                 weekThreeOverPay = (weekThreeHours - MAX_NORMAL_TIME) * hourlyRate * OVERTIME_RATE;
             }
             else
             {
                 weekThreeRegPay = MAX_NORMAL_TIME * hourlyRate;
                 weekThreeOverPay = (MAX_OVERTIME - MAX_NORMAL_TIME) * hourlyRate * OVERTIME_RATE;
                 weekThreeDoublePay = (weekThreeHours - MAX_OVERTIME) * hourlyRate * DOUBLETIME_RATE;
             }
             //week 4
             if (weekFourHours <= MAX_NORMAL_TIME)
             {
                 weekFourRegPay = weekFourHours * hourlyRate;
             }
             else if (weekFourHours <= MAX_OVERTIME)
             {
                 weekFourRegPay = MAX_NORMAL_TIME * hourlyRate;
                 weekFourOverPay = (weekFourHours - MAX_NORMAL_TIME) * hourlyRate * OVERTIME_RATE;
             }
             else
             {
                 weekFourRegPay = MAX_NORMAL_TIME * hourlyRate;
                 weekFourOverPay = (MAX_OVERTIME - MAX_NORMAL_TIME) * hourlyRate * OVERTIME_RATE;
                 weekFourDoublePay = (weekFourHours - MAX_OVERTIME) * hourlyRate * DOUBLETIME_RATE;
             }
             //total up each week
             weekOneTotal = weekOneRegPay + weekOneOverPay + weekOneDoublePay;
             weekTwoTotal = weekTwoRegPay + weekTwoOverPay + weekTwoDoublePay;
             weekThreeTotal = weekThreeRegPay + weekThreeOverPay + weekThreeDoublePay;
             weekFourTotal = weekFourRegPay + weekFourOverPay + weekFourDoublePay;
             // total each type of pay
             totalRegPay = weekOneRegPay + weekTwoRegPay + weekThreeRegPay + weekFourRegPay;
             totalOverPay = weekOneOverPay + weekTwoOverPay + weekThreeOverPay + weekFourOverPay;
             totalDoublePay = weekOneDoublePay + weekTwoDoublePay + weekThreeDoublePay + weekFourDoublePay;
             empTotal = totalRegPay + totalOverPay + totalDoublePay;
             //display employees week, rate, hours, total and total for the employee
             cout << "Week\t" << "Rate\t" << "Hours\t" << "1.0\t" << "1.5\t" << "2.0\t" << "Total" << endl
                 << "Week 1\t" << hourlyRate << "\t" << weekOneHours << "\t" << weekOneRegPay << "\t" << weekOneOverPay << "\t" << weekOneDoublePay << "\t" << weekOneTotal << endl
                 << "Week 2\t" << hourlyRate << "\t" << weekTwoHours << "\t" << weekTwoRegPay << "\t" << weekTwoOverPay << "\t" << weekTwoDoublePay << "\t" << weekTwoTotal << endl
                 << "Week 3\t" << hourlyRate << "\t" << weekThreeHours << "\t" << weekThreeRegPay << "\t" << weekThreeOverPay << "\t" << weekThreeDoublePay << "\t" << weekThreeTotal << endl
                 << "Week 4\t" << hourlyRate << "\t" << weekFourHours << "\t" << weekFourRegPay << "\t" << weekFourOverPay << "\t" << weekFourDoublePay << "\t" << weekFourTotal << endl << endl
                 << "Employee totals\t" << totalHours << "\t" << totalRegPay << "\t" << totalOverPay << "\t" << totalDoublePay << "\t" << empTotal << endl << endl << endl;
             //add employee totals to overall totals
            totalHoursWorked = totalHoursWorked + totalHours;
            totalGrossBase = totalGrossBase + weekOneRegPay + weekTwoRegPay + weekThreeRegPay + weekFourRegPay;
            totalGrossOverTime = totalGrossOverTime + weekOneOverPay + weekTwoOverPay + weekThreeOverPay + weekFourOverPay;
            totalGrossDoubleTime = totalGrossDoubleTime + weekOneDoublePay + weekTwoDoublePay + weekThreeDoublePay + weekFourDoublePay;
            totalGrossPaid = totalGrossBase + totalGrossOverTime + totalGrossDoubleTime;
            //iterate loop
            count++;
        }
        //calculate average gross
        if (numberEmployees > 0)
        {
            averageGross = totalGrossPaid / numberEmployees;
        }
        else
            averageGross = 0.00;
        //display totals and average gross
        cout << endl
            << "Report Totals:\t" << "Hours\t" << "1.0\t" << "1.5\t" << "2.0\t" << "Total" << endl
            << "\t\t" << totalHoursWorked << "\t" << totalGrossBase << "\t" << totalGrossOverTime << "\t" << totalGrossDoubleTime << "\t" << totalGrossPaid << endl << endl
            << "Number of Employees: " << numberEmployees << "\t Average Gross: " << averageGross << endl;
    }
    //end main
    return 0;
}
