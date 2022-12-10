//P12 Inheritance -  Thane Reynolds
/*
   This program is a driver to test SalesInfo class, which inherits SalesPerson.
   It is used to create 2 objects, which test the constructors and accessors.
   The objects created are saved to P12.txt
*/
#include <fstream>    // file processing
#include <iostream>   // cout and cin
#include <iomanip>    // setw
#include <string>     // string class

using namespace std;

class SalesPerson
{
protected:
    //Add the variables and functions
    int salesPersonId;
    string firstName;
    string lastName;
public:
    //Paste from P10.cpp
    //Add the variables and functions
    SalesPerson(); //default Constructor
    SalesPerson(int id, string fn, string ln);
    ~SalesPerson();

    // Setters
    void setSalesPersonId(int id);
    void setFirstName(string fn);
    void setLastName(string ln);

    // Getters(Accessors)
    int getSalesPersonId();
    string getFirstName();
    string getLastName();

    // input accessors(mutate and set)
    void inputSalesPersonId();
    void inputFirstName();
    void inputLastName();
};

class SalesInfo : public SalesPerson
{
private:
    double rate;
    int qty;
public:
    SalesInfo(); // default contstructor
    SalesInfo(int id, string fn, string ln, double rt, int qt); // overloaded constructor
    ~SalesInfo(); //destructor
    
    //mutators
    void setRate(double rt);
    void setQty(int qt);
    
    //accessors
    double getRate();
    int getQty();
    
    //input
    void inputRate();
    void inputQty();
};

//This function saves sales info to a file or displays to screen (cout)
void outputSalesInfo(ostream& target, SalesInfo& salesInfoObj);


int main()
{
    cout << "P12 - Thane Reynolds\n\n";

    //Open the file for output

    ofstream outFile;
    outFile.open("P12.txt");
    if (outFile.fail())
    {
        cout << "Error opening output file for sales information.\n"
            << "Exiting program \n\n";
        return 0;
    }

    cout << "\nP12 Thane Reynolds \n\n";


    //1001 Joe Smith 5.00, 25 - use default constructors and input functions
    SalesInfo salesInfoObj;

    //Save the sales data as a record to the file and display on the screen.
    outputSalesInfo(outFile, salesInfoObj);



    //1002 Larry Jones - use set methods to change values.
    salesInfoObj.setSalesPersonId(1002);
    salesInfoObj.setFirstName("Larry");
    salesInfoObj.setLastName("Jones");
    salesInfoObj.setRate(10.00);
    salesInfoObj.setQty(50);

    //Save the sales data as a record to the file and display on the screen..
    outputSalesInfo(outFile, salesInfoObj);


    //1003 Paul Sailor - use overloaded constructors 
    SalesInfo salesInfoObj2(1003, "Paul", "Sailor", 15.00, 150);

    //Save the sales data as a record to the file and display on the screen..
    outputSalesInfo(outFile, salesInfoObj2);


    // Close the output file and exit program
    outFile.close();
    return 0;
}//end of main


//save the order information to a file or display on screen
void outputSalesInfo(ostream& target, SalesInfo& salesInfoObj)
{
    //declare local variables
    int salesPersonId;
    string lastName, firstName;
    double rate;
    int qty;

    //set the precision for rate
    target.setf(ios::fixed);
    target.setf(ios::showpoint);
    target.precision(2);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Have the class return the private values to the local variables.
    //Then store them in the file.
    salesPersonId = salesInfoObj.getSalesPersonId();
    firstName = salesInfoObj.getFirstName();
    lastName = salesInfoObj.getLastName();
    rate = salesInfoObj.getRate();
    qty = salesInfoObj.getQty();


    cout << "\n\nSalesPerson's Information Saved! \n";
    cout.setf(ios::left);
    cout << setw(6) << salesPersonId
        << setw(18) << firstName
        << setw(18) << lastName;
    cout.unsetf(ios::left);

    cout << setw(6) << rate;
    cout << setw(4) << qty;
    cout << endl;

    target.setf(ios::left);
    target << setw(6) << salesPersonId
        << setw(18) << firstName
        << setw(18) << lastName;
    target.unsetf(ios::left);

    target << setw(6) << rate;
    target << setw(4) << qty;
    target << endl;

    return;
}

//end of application code

//Sales person functions

SalesPerson::SalesPerson()
{
    //deliberately emptyc
}

//overloaded constructor
SalesPerson::SalesPerson(int id, string fn, string ln)
{
    salesPersonId = id;
    firstName = fn;
    lastName = ln;
}

//Destructor function definition is provided below
SalesPerson::~SalesPerson()
{
    cout << "\nSalesPerson Object going out of scope. Id = "
        << salesPersonId << endl;
    return;
}

//set accessors
void SalesPerson::setSalesPersonId(int id)
{
    salesPersonId = id;
}
void SalesPerson::setFirstName(string fn)
{
    firstName = fn;
}
void SalesPerson::setLastName(string ln)
{
    lastName = ln;
}

//get accessors
int SalesPerson::getSalesPersonId()
{
    return salesPersonId;
}
string SalesPerson::getFirstName()
{
    return firstName;
}
string SalesPerson::getLastName()
{
    return lastName;
}

//input accessors
//The input accessors should prompt the user to input information
void SalesPerson::inputSalesPersonId()
{
    bool isValid = false;
    while (!isValid)
    {
        cout << "Enter Sales Person ID (1000-9999): ";
        cin >> salesPersonId;
        if (salesPersonId < 1000 || salesPersonId > 9999)
        {
            cout << "Invalid Sales Person ID" << endl;
            isValid = false;
        }
        else
        {
            isValid = true;
        }
    }
    cout << endl;
}
void SalesPerson::inputFirstName()
{
    cout << "Enter First Name without spaces: ";
    cin >> firstName;
    cout << endl;
}
void SalesPerson::inputLastName()
{
    cout << "Enter Last Name without spaces: ";
    cin >> lastName;
    cout << endl;
}

//end SalesPerson functions

//begin SalesInfo functions
// default constructor - the input functions should be called from here
SalesInfo::SalesInfo()
    : SalesPerson()        //call constructor in base class 
{
    inputSalesPersonId();
    inputFirstName();
    inputLastName();
    inputRate();
    inputQty();
}

//overloaded constructor - arguments assigned to members
//use base initialize list to call constructor in base class
SalesInfo::SalesInfo(int id, string fn, string ln,
    double rt, int qt)
    : SalesPerson(id, fn, ln)
{
    rate = rt;
    qty = qt;
}

//destructor
SalesInfo::~SalesInfo()
{
    cout << endl << "SalesInfo   Object going out of scope. Id = "
        << salesPersonId;
}


//Student needs to complete the next 4 functions.
//Accessors to set values in private variables
void SalesInfo::setRate(double rt)
{
    rate = rt;
    return;
}


void SalesInfo::setQty(int qt)
{
    qty = qt;
    return;
}


//Accessors to return values in private variables
double SalesInfo::getRate()
{
    return rate;
}

int SalesInfo::getQty()
{
    return qty;
}


void SalesInfo::inputRate()
{//Normally set and input functions would include validation and would throw an exception if an error was found.
    do
    {
        cout << "Enter a bonus rate between $5.00 and $10: ";
        cin >> rate;

        if (rate < 5.0 || rate > 10.00)
            cout << "Error: The rate must be between $5.00 and $10.00. "
            << "Try again...\n\n";

    } while (rate < 5.0 || rate > 10.00);
    return;
}


void SalesInfo::inputQty()
{
    do
    {
        cout << "Enter a quantity between 0 and 200:       ";

        cin >> qty;

        if (qty < 0 || qty > 200)
            cout << "Error: The quantity must be between 0 and 200. "
            << "  Try again...\n\n";

    } while (qty < 0 || qty > 200);
    return;
}
