#include <iostream>
#include "patient.h"


using namespace std;

// Patient menu
void patientMenu()
{
    Patient patient;

    int choice;

    do
    {
        cout << "\n====================================" << endl;
        cout << "        PATIENT MANAGEMENT" << endl;
        cout << "====================================" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Display Patient" << endl;
        cout << "3. Save Patient" << endl;
        cout << "4. View Saved Patients" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "====================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            patient.setPatientDetails();
            break;

        case 2:
            patient.displayPatient();
            break;

        case 3:
            patient.saveToFile();
            break;

        case 4:
            patient.loadFromFile();
            break;

        case 5:
            cout << "\nReturning to Main Menu..." << endl;
            break;

        default:
            cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != 5);
}


// Main function
int main()
{
    int choice;

    cout << "========================================" << endl;
    cout << "      HOSPITAL MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;

    do
    {
        cout << "\n============== MAIN MENU ==============" << endl;
        cout << "1. Patient Management" << endl;
        cout << "2. Doctor Management" << endl;
        cout << "3. Appointment Management" << endl;
        cout << "4. Billing Management" << endl;
        cout << "5. Exit" << endl;
        cout << "========================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            patientMenu();
            break;

        case 2:
            cout << "\nDoctor Management will be implemented soon." << endl;
            break;

        case 3:
            cout << "\nAppointment Management will be implemented soon." << endl;
            break;

        case 4:
            cout << "\nBilling Management will be implemented soon." << endl;
            break;

        case 5:
            cout << "\nThank you for using Hospital Management System." << endl;
            break;

        default:
            cout << "\nInvalid choice. Please enter a number from 1 to 5." << endl;
        }

    } while (choice != 5);

    return 0;
}