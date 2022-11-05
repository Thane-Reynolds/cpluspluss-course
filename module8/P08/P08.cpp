//P08 Array and File Processing - Thane Reynolds
/*
   This program uses a simple array and a data file.

   Loads, sorts and searches a partially filled array of Employee ID (integers)

*/
#include <fstream>  // file processing
#include <iostream> // cin and cout

using namespace std;


//Global Constants
//When using to declare arrays, must be defined with const modifier
const int  ARRAY_SIZE = 20;

//Declare arrays as global so we don't have to pass the arrays to each function.
//Normally we wouldn't declare variables that change values a global.
int  employeeId[ARRAY_SIZE];
int  numberOfEmps;    //count of how many employees were loaded into arrays

void loadArray();

void sortArrayAscending();

void sortArrayDescending();

void displayArray();

void searchArray();

void displayContinuePrompt();


//Program starts here   
int main()
{
    cout << "P08 - your name\n\n";
    //Declare and initialize local main variables
    char   choice;            //menu option

    //Load the arrays with data
    loadArray();

    //check to see what the user wants to do
    do  // while (choice != 'X')
    {
        cout << "P08   Your Name Here   \n\n";

        cout << "Enter the letter of the desired menu option. \n"
            << "Press the Enter key after entering the letter. \n \n"

            << "  A: Display Employee Id (current order) \n"
            << "  B: Display Employee Id Ascending Order \n"
            << "  C: Display Employee Id Descending Order \n"
            << "  D: Search Employee Id List \n"

            << "  X: Exit the program \n \n"

            << "Choice: ";

        cin >> choice;

        choice = toupper(choice);

        switch (choice)
        {
        case 'A':
            cout << "Current order of Employee Ids:\n";
            displayArray();
            displayContinuePrompt();
            break;
        case 'B':
            cout << "Employee Ids sorted ascending:\n";
            sortArrayAscending();
            displayArray();
            displayContinuePrompt();
            break;
        case 'C':
            cout << "Employee Ids sorted descending:\n";
            sortArrayDescending();
            displayArray();
            displayContinuePrompt();
            break;
        case 'D':
            searchArray();
            displayContinuePrompt();
            break;
        case 'X':
            cout << "Now exiting. Please wait...\n\n";
            break;
        default:
            cout << "\a \n\n Invalid Option Entered - Please try again. \n\n";

        } // end of switch

    } while (choice != 'X');

    return 0;
} // end of main


//Function Definitions
void loadArray()
{

    //Students must code the rest of this function

    //Open the file for input  
    //If there are any errors, 
    //  display an error message and return.
    ifstream inputFile;
    inputFile.open("P08.txt");
    if (inputFile.fail())
    {
        cout << "File opening failed";
    }
    //Declare index and initialize to zero for first array element
    int  i = 0;

    //Read the first record into array 
    inputFile >> employeeId[i];
    //Use while loop to process file, because 
    //  while loops handle empty files.
    while (!inputFile.eof())
    {
    //  increment counter, i++;
        i++;
    //  Check if array size exceeded
        if (i < ARRAY_SIZE)
        {
            //  Read next Id into array
            inputFile >> employeeId[i];
        }
        else
            break;
    //end while loop

    //Close the file
        inputFile.close();
    //Save the number of records loaded
    numberOfEmps = i + 1;

    return;
    }
}


void sortArrayAscending()
{
    int minIndex, minValue, holdValue;

    //Students need to code for-loop to sort employeeId in ascending order
    for (int i = 0; i < numberOfEmps; i++) 
    {
        
    }

    return;
}


void sortArrayDescending()
{
    //For a descending sort we still walk through the array, but this
    //time we are searching for the highest values.
    int maxIndex, maxValue, holdValue;

    //Students need to code for-loop to sort employeeId in descending order 

    return;
}


void displayArray()
{
    cout << endl;
    cout.setf(ios::right);  //already on by default for numbers

    for (int i = 0; i < numberOfEmps; i++)
    {
        cout << "position =";
        cout << setw(3) << (i + 1);

        cout << "  index =";
        cout << setw(3) << i;

        cout << "  value = ";
        cout << setw(4) << employeeId[i]
            << endl;
    }
    return;
}

//Early exit - an early exit from a search can occur when we know that
//the value we are looking for will not be found in the array.  To
//implement an early exit, the array must be sorted in ascending order.
//If  we can determine that a value will not be found, we should
//not search the remainder of the array.

void searchArray()
{
    //array must be sorted ascending for early exit logic to work  
    sortArrayAscending();

    int  searchId;
    bool numberFound = false;

    cout << "Enter Employee Id to search for: ";
    cin >> searchId;

    //Students need to code for-loop to search employeeId 
    //  include early exit logic

    return;
}


void displayContinuePrompt()
{
    char prompt;

    cout << "\n\nProcedure completed. Press Enter to continue: ";
    cin.ignore();
    prompt = cin.get();

    system("cls");

    return;
}
//End of program
