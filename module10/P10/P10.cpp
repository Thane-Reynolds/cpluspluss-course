//P10 SalesPerson class - Thane Reynolds 

#include <string>   // string class
#include <iostream>
using namespace std;


//Class definition -  the interface for the class

class SalesPerson
{
private:
    //Add the variables and functions
    int salesPersonId;
    string firstName;
    string lastName;

public:
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



//Need empty main so program will compile 
int main()
{
    cout << "P10 - Thane Reynolds\n\n";
    return 0;
}

SalesPerson::SalesPerson()
{
    //Nothing to see here, I'm empty!
}

SalesPerson::SalesPerson(int id, string fn, string ln)
{
    salesPersonId = id;
    firstName = fn;
    lastName = ln;
}

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

void SalesPerson::inputSalesPersonId()
{
    cout << "Please input the sales person ID: ";
    cin >> salesPersonId;
    cout << endl;
}

void SalesPerson::inputFirstName()
{
    cout << "Please input the sales person first name: ";
    cin >> firstName;
    cout << endl;
}

void SalesPerson::inputLastName()
{
    cout << "Please input the sales person last name: ";
    cin >> lastName;
    cout << endl;
}

SalesPerson::~SalesPerson()
{

}

//End of P10

