#include <iostream>

#include "patient.h"
#include "Doctor.h"
#include "Appointment.h"
#include "BillingModule.h"

using namespace std;


// ============================================================
// PATIENT MENU
// ============================================================

void patientMenu()
{
    Patient patient;

    int choice;
    int detailsEntered = 0;

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

            detailsEntered = 1;

            cout << "\nPatient details added successfully." << endl;

            break;


        case 2:

            if (detailsEntered == 1)
            {
                patient.displayPatient();
            }
            else
            {
                cout << "\nNo patient details entered." << endl;
                cout << "Please add patient details first." << endl;
            }

            break;


        case 3:

            if (detailsEntered == 1)
            {
                patient.saveToFile();

                detailsEntered = 0;
            }
            else
            {
                cout << "\nNo patient details available to save." << endl;
            }

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


// ============================================================
// DOCTOR MENU
// ============================================================

void doctorMenu()
{
    Doctor doctor;

    int choice;
    int detailsEntered = 0;

    do
    {
        cout << "\n====================================" << endl;
        cout << "        DOCTOR MANAGEMENT" << endl;
        cout << "====================================" << endl;

        cout << "1. Add Doctor" << endl;
        cout << "2. Display Doctor" << endl;
        cout << "3. Save Doctor" << endl;
        cout << "4. View Saved Doctors" << endl;
        cout << "5. Back to Main Menu" << endl;

        cout << "====================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            doctor.setDoctorDetails();

            detailsEntered = 1;

            cout << "\nDoctor details added successfully." << endl;

            break;


        case 2:

            if (detailsEntered == 1)
            {
                doctor.displayDoctor();
            }
            else
            {
                cout << "\nNo doctor details entered." << endl;
                cout << "Please add doctor details first." << endl;
            }

            break;


        case 3:

            if (detailsEntered == 1)
            {
                doctor.saveToFile();

                detailsEntered = 0;
            }
            else
            {
                cout << "\nNo doctor details available to save." << endl;
            }

            break;


        case 4:

            doctor.loadFromFile();

            break;


        case 5:

            cout << "\nReturning to Main Menu..." << endl;

            break;


        default:

            cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != 5);
}


// ============================================================
// APPOINTMENT MENU
// ============================================================

void appointmentMenu()
{
    Appointment appointment;

    int choice;
    int detailsEntered = 0;

    do
    {
        cout << "\n====================================" << endl;
        cout << "      APPOINTMENT MANAGEMENT" << endl;
        cout << "====================================" << endl;

        cout << "1. Schedule Appointment" << endl;
        cout << "2. Display Appointment" << endl;
        cout << "3. Save Appointment" << endl;
        cout << "4. View Saved Appointments" << endl;
        cout << "5. Cancel Appointment" << endl;
        cout << "6. Search by Patient ID" << endl;
        cout << "7. Back to Main Menu" << endl;

        cout << "====================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            appointment.setAppointmentDetails();

            detailsEntered = 1;

            cout << "\nAppointment details added successfully." << endl;

            break;


        case 2:

            if (detailsEntered == 1)
            {
                appointment.displayAppointment();
            }
            else
            {
                cout << "\nNo appointment details entered." << endl;
                cout << "Please schedule an appointment first." << endl;
            }

            break;


        case 3:

            if (detailsEntered == 1)
            {
                appointment.saveToFile();

                detailsEntered = 0;
            }
            else
            {
                cout << "\nNo appointment details available to save." << endl;
            }

            break;


        case 4:

            appointment.loadFromFile();

            break;


        case 5:

            appointment.cancelAppointment();

            break;


        case 6:

            appointment.searchByPatientID();

            break;


        case 7:

            cout << "\nReturning to Main Menu..." << endl;

            break;


        default:

            cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != 7);
}


// ============================================================
// BILLING MENU
// ============================================================

void billingMenu()
{
    Billing bill;

    int choice;
    int detailsEntered = 0;

    do
    {
        cout << "\n====================================" << endl;
        cout << "        BILLING MANAGEMENT" << endl;
        cout << "====================================" << endl;

        cout << "1. Create New Bill" << endl;
        cout << "2. Display Bill" << endl;
        cout << "3. Save Bill" << endl;
        cout << "4. View Saved Bills" << endl;
        cout << "5. Back to Main Menu" << endl;

        cout << "====================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            bill.setBillDetails();

            detailsEntered = 1;

            cout << "\nBill details added successfully." << endl;

            break;


        case 2:

            if (detailsEntered == 1)
            {
                bill.displayBill();
            }
            else
            {
                cout << "\nNo bill details entered." << endl;
                cout << "Please create a bill first." << endl;
            }

            break;


        case 3:

            if (detailsEntered == 1)
            {
                bill.saveToFile();

                detailsEntered = 0;
            }
            else
            {
                cout << "\nNo bill details available to save." << endl;
            }

            break;


        case 4:

            bill.loadFromFile();

            break;


        case 5:

            cout << "\nReturning to Main Menu..." << endl;

            break;


        default:

            cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != 5);
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    int choice;

    cout << "\n========================================" << endl;
    cout << "       HOSPITAL MANAGEMENT SYSTEM" << endl;
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

            doctorMenu();

            break;


        case 3:

            appointmentMenu();

            break;


        case 4:

            billingMenu();

            break;


        case 5:

            cout << "\n========================================" << endl;
            cout << " Thank you for using Hospital Management" << endl;
            cout << "               System!" << endl;
            cout << "========================================" << endl;

            break;


        default:

            cout << "\nInvalid choice." << endl;
            cout << "Please enter a number from 1 to 5." << endl;
        }

    } while (choice != 5);

    return 0;
}