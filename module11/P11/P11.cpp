//P11 SalesPerson - Thane Reynolds 
/*
   This program is a driver to test the SalesPerson class.
   It is used to create 2 objects, which test the constructors and accessors.
   The objects created are saved to p11.txt.
*/
#include <fstream>  // file processing
#include <iostream> // cin and cout
#include <iomanip>  // setw
#include <string>   // string class
using namespace std;


//Copy-and-paste your class definition from P10.cpp.

//Class definition -  the interface for the class

class SalesPerson
{
private:
    //Paste from P10.cpp
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


//Application Starts here (prototypes, main(), and definitions for application)

//saves info to a file and displays to screen
void outputSalesInfo(ostream& target, SalesPerson& salesPersonObj);

//main driver to test SalesPerson class
int main()
{
    cout << "P11 - Thane Reynolds\n\n";
    //Open the file for output; if there are any errors, we need to 
    //display an error message.

    ofstream outFile;
    outFile.open("P11.txt");
    if (outFile.fail())
    {
        cout << "Error opening output file for sales information.\n"
            << "Exiting program \n\n";
        return 0;
    }

    cout << "\nP11     Thane Reynolds  \n\n";


    //1001 Joe Smith - use default constructor and input functions
    SalesPerson salesPersonObj;
    salesPersonObj.inputSalesPersonId();
    salesPersonObj.inputFirstName();
    salesPersonObj.inputLastName();

    //Save the sales data to the file and display on the screen
    outputSalesInfo(outFile, salesPersonObj);



    //1002  Larry Jones - use set functions to change values.
    salesPersonObj.setSalesPersonId(1002);
    salesPersonObj.setFirstName("Larry");
    salesPersonObj.setLastName("Jones");

    //Save the sales data to the file and display on the screen
    outputSalesInfo(outFile, salesPersonObj);


    //1003 Paul Sailor - use overloaded constructor 
    SalesPerson salesPersonObj2(1003, "Paul", "Sailor");

    //Save the sales data to the file and display on the screen.
    outputSalesInfo(outFile, salesPersonObj2);



    // Close the output file and exit program
    outFile.close();
    return 0;
}//end of main


//save the order information to a file or display to screen.
//target can be either cout or outFile because ofstream inherits ostream.
//ofstream objects are also ostream objects.
//also, must be ostream because cout is already declared as an ostream.

void outputSalesInfo(ostream& target, SalesPerson& salesPersonObj)
{
    //declare local variables
    int    salesPersonId;
    string lastName, firstName;

    //Have the class return the private values to the local variables.
    //Then store them in the file.
    salesPersonId = salesPersonObj.getSalesPersonId();
    firstName = salesPersonObj.getFirstName();
    lastName = salesPersonObj.getLastName();

    cout << "\n\nSales Person's Information Saved! \n";
    cout << salesPersonId
        << "\t" << firstName
        << "\t" << lastName
        << endl;

    target.setf(ios::left);
    target << setw(6) << salesPersonId
        << setw(18) << firstName
        << setw(18) << lastName
        << endl;
    target.unsetf(ios::left);

    return;
}



//Student must complete the 2 constructors, 3 set and 3 get accessors,
//and 3 input function definitions.  A total of 11 functions.

//default constructor
//The default constructor should call the 3 input definitions.
SalesPerson::SalesPerson()
{
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
//end of P11