#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Function Prototypes

// This function displays the Gym Membership menu choices
void display_menu();

// This function reads the user's selection, validates it, and
// returns the user's menu choice
int get_choice();

// This function computes and displays the total charges for a
// membership type for a number of months using rate parameter
void show_fees(string membership_type, double rate, int months);

// This function implements the gym membership application
void gym_membership_app();

int main()
{
    // call the gym membership app
    gym_membership_app();

    return 0;
}


// This function displays the Gym Membership menu choices
void display_menu()
{
    cout << "------------------------" << endl;
    cout << "Gym Club Membership Menu" << endl;
    cout << "------------------------" << endl;
    cout << "1. Standard Adult Membership" << endl;
    cout << "2. Child Membership" << endl;
    cout << "3. Senior Citizen Membership" << endl;
    cout << "4. Student Membership" << endl;
    cout << "5. Quit the Program" << endl;
}

// This function reads the user's selection, validates it, and
// returns the user's menu choice
int get_choice()
{
    int choice;

    cout << "Enter your choice: ";
    cin >> choice;

    // validate menu selection
    while(( choice < 1 || choice > 5) && (!cin.fail()))
    {
            cout << "\nTry again. Enter 1, 2, 3, 4 or 5: ";
            cin >> choice;
    }
    if (cin.fail())
        exit(1);
    return choice;
}

// This function computes and displays the total charges for a
// membership type for a number of months using rate parameter
void show_fees(string membership_type, double rate, int months)
{
    cout << fixed  << showpoint << setprecision(2);
    cout << endl;
    cout << "Membership Type: " << membership_type << endl;
    cout << "Monthly Rate: $" << rate << endl;
    cout << "Total Number of Months: " << months << endl;
    cout << "Total Charges: $" << (rate * months) << endl << endl;
}

void gym_membership_app()
{
    // define constants for monthly club membership rates
    const double ADULT_RATE = 50.00;
    const double CHILD_RATE = 20.00;
    const double SENIOR_RATE = 30.00;
    const double STUDENT_RATE = 35.00;

    int choice; // Menu choice
    int months; // Number of months

    // display menu and get a valid selection
    do
    {
        display_menu();
        choice = get_choice();

        // process the user's selection
        if (choice != 5)
        {
            do
            {
                cout << "How many months would you like? " ;
                cin >> months;
            } while (months < 0);

            // compute charges
            switch (choice)
            {
                case 1: show_fees("ADULT", ADULT_RATE, months);
                        break;
                case 2: show_fees("CHILD", CHILD_RATE, months);
                        break;
                case 3: show_fees("SENIOR", SENIOR_RATE, months);
                        break;
                case 4: show_fees("STUDENT", STUDENT_RATE, months);
                        break;
                default:;
            }
        }
    } while (choice != 5); // loop again if the user did not select 4 to quit
}
