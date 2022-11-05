///P07 File Processing  - Thane Reynolds 
/*
   This program allows users to enter and save payroll information to a file.
   The file can then be read so that the information entered can be displayed.
   Payroll clerks can choose from the following menu options:

     A: Create a new file for Payroll Information
     B: Enter Payroll Information
     C: Display Payroll Information

     X: Exit the Payroll Information Module

   The following items for each employee are saved in the file p07.txt:
     Employee ID
     Rate
     Hours W1,W2,W3,W4

*/
#include <fstream>  // file processing
#include <iostream> // cin and cout
#include <cctype>   // toupper
#include <iomanip>  // setw

using namespace std;

//menu options
//Opt A: 
void createNewFile();

//Opt B: 
void enterInfo();

//Opt C:    
void listInfo();

//Supporting functions
void displayContinuePrompt();


//Program starts here   
int main()
{
    cout << "P07 - your name\n\n";
    //Declare local variable to store menu option selected
    char   choice;

    //Check to see what the user wants to do
    do  //while (choice != 'X')
    {
        cout << "P07   Main Menu   \n\n";

        cout << "Enter the letter of the desired menu option. \n"
            << "Press the Enter key after entering the letter. \n\n"

            << "  A: Create a new file for Payroll Information  \n"
            << "  B: Enter Payroll Information  \n"
            << "  C: List Payroll Information   \n\n"

            << "  X: Exit the Payroll Information Module \n\n"

            << "Choice: ";

        cin >> choice;
        cout << "\n\n";

        choice = toupper(choice); //convert to uppercase

        switch (choice)
        {
        case 'A':
            createNewFile();
            break;
        case 'B':
            enterInfo();
            break;
        case 'C':
            listInfo();
            break;

        case 'X':
            cout << "Now exiting Payroll Information...please wait.\n\n";
            break;
        default:
            cout << "\a"; //alert
            cout << "Invalid Option Entered - Please try again. \n\n";

        }//end of switch

    } while (choice != 'X');

    return 0;
}//end of main


//Function Definitions
void createNewFile()
{
    //Declare local variables
    char answer;

    cout << "P07     Create new file for Payroll Information \n\n";

    //Student must code the rest of the function. The example assignment has a lot of helpful information. 

    //Prompt the user if they want to create a new file
    cout << "Would you like to create a new file? (Y/N)\n";
    cin >> answer;
    //If Yes, try to create a new file using open function
    answer = toupper(answer);
    if (answer == 'Y')
    {
        ofstream outputFile;
    //  Open the file for output 
        outputFile.open("P07.txt");
    //  If there are any errors when attempting to create a new file, display an error message and return.
        if (outputFile.fail())
        {
            cout << "Error: Output file creation failed. Returning to choice selection.\n";
            return;
        }
    //  else 
    //     display message that a file was created successfully
        else
        {
            cout << "File created successfully.\n";
        }
    //   Close the file
        outputFile.close();
    }
    //else 
    //  display a message that a new file was NOT created
    else
    {
        cout << "New file not created.\n";
    }
    //Call displayContinue to pause
    displayContinuePrompt();
    return;
}


void enterInfo()
{
    //Declare local variables
    int employeeId;
    double rate;
    int w1Hours, w2Hours, w3Hours, w4Hours;
    char answer;

    cout << "P07     Enter Payroll Information \n\n";

    //Student must code the rest of the function. 

    //Open the file for output (append) 
    ofstream outputFile;
    outputFile.open("P07.txt", ios::app);
    //If there are any errors, 
    //  display an error message and return.
    if (outputFile.fail())
    {
        cout << "Error opening file. Returning to choice selection.";
        return;
    }
    //Set output to 2 decimal positions for file
    outputFile.setf(ios::fixed);
    outputFile.setf(ios::showpoint);
    outputFile.precision(2);
    //Use a do-while loop to get input
    do
    {
        //  Display prompt and get the data
        cout << "\nPlease enter the employee ID, rate, w1, w2, w3, w4: (all seperated by a space) \n";
        cin >> employeeId >> rate >> w1Hours >> w2Hours >> w3Hours >> w4Hours;
        //  Write data to file and format using setw manipulators
        outputFile << setw(6) << employeeId;
        outputFile << setw(9) << rate;
        outputFile << setw(6) << w1Hours;
        outputFile << setw(6) << w2Hours;
        outputFile << setw(6) << w3Hours;
        outputFile << setw(6) << w4Hours;
        outputFile << endl;
        //  Prompt user if they want to add another employee
        cout << "\nWould you like to enter another employee? (Y/N) N to quit \n";
        cin >> answer;
        //  Do loop again if they don't enter N
        //end do-while loop
    } while (toupper(answer) != 'N');
    //Close the file
    outputFile.close();
    //Call displayContinue to pause
    displayContinuePrompt();
    return;
}


void listInfo()
{
    //Declare local variables
    int employeeId;
    double rate;
    int w1Hours, w2Hours, w3Hours, w4Hours;

    cout << "P07      List Payroll Information \n\n";

    //Student must code the rest of the function. 

    //Open the file for input
    ifstream inputFile;
    inputFile.open("P07.txt");
    //If there are any errors, 
    //  display an error message and return.
    if (inputFile.fail())
    {
        cout << "Error: File not opened correctly. Returning to choice selection.";
        return;
    }
    //Set output to 2 decimal positions for cout
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Display headings
    cout << "Employee   Rate   Wk1   Wk2   Wk3   Wk4 \n\n";

    //Read the first record. 
    inputFile >>  employeeId >> rate >> w1Hours >> w2Hours >> w3Hours >> w4Hours;

    //Use while loop to process file, because 
    //  while loops handle empty files.
    while (!inputFile.eof())
    {
    //  Display record read and format using setw manipulators
        cout << setw(6) << employeeId << setw(9) << rate << setw(6) << w1Hours
            << setw(6) << w2Hours << setw(6) << w3Hours << setw(6) << w4Hours << endl;
    //  Read next record
        inputFile >> employeeId >> rate >> w1Hours >> w2Hours >> w3Hours >> w4Hours;
    //end while loop
    }
    //Close the file
    inputFile.close();
    //Call displayContinue to pause
    displayContinuePrompt();
    return;
}

void displayContinuePrompt()
{
    //Declare local variables
    char prompt;

    cout << "\n\nProcedure completed. Press Enter to continue: ";
    cin.ignore();
    prompt = cin.get();

    system("cls");   //clear screen - DOS

    return;
}
//End of program