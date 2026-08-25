#include "doctor.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Default constructor
Doctor::Doctor()
{
    doctorID = 0;
    name = "";
    age = 0;
    gender = "";
    contact = "";
    specialization = "";
    department = "";
    availability = "";
}

// Parameterized constructor
Doctor::Doctor(int id, string n, int a, string g, string c,
               string s, string d, string av)
{
    doctorID = id;
    name = n;
    age = a;
    gender = g;
    contact = c;
    specialization = s;
    department = d;
    availability = av;
}

// Enter doctor details
void Doctor::setDoctorDetails()
{
    cout << "\nEnter Doctor ID: ";
    cin >> doctorID;

    cin.ignore();

    cout << "Enter Doctor Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter Gender: ";
    getline(cin, gender);

    cout << "Enter Contact Number: ";
    getline(cin, contact);

    cout << "Enter Specialization: ";
    getline(cin, specialization);

    cout << "Enter Department: ";
    getline(cin, department);

    cout << "Enter Availability: ";
    getline(cin, availability);
}

// Display one doctor's information
void Doctor::displayDoctor()
{
    cout << left
         << setw(12) << doctorID
         << setw(20) << name
         << setw(8) << age
         << setw(12) << gender
         << setw(15) << contact
         << setw(20) << specialization
         << setw(15) << department
         << setw(20) << availability
         << endl;
}

// Get Doctor ID
int Doctor::getDoctorID()
{
    return doctorID;
}

// Get Doctor Name
string Doctor::getName()
{
    return name;
}

// Get Doctor Age
int Doctor::getAge()
{
    return age;
}

// Get Doctor Gender
string Doctor::getGender()
{
    return gender;
}

// Get Doctor Contact
string Doctor::getContact()
{
    return contact;
}

// Get Doctor Specialization
string Doctor::getSpecialization()
{
    return specialization;
}

// Get Doctor Department
string Doctor::getDepartment()
{
    return department;
}

// Get Doctor Availability
string Doctor::getAvailability()
{
    return availability;
}

// Save doctor information to file
void Doctor::saveToFile()
{
    ofstream file("data/doctors.txt", ios::app);

    if (!file)
    {
        cout << "Error: Unable to open doctors.txt" << endl;
        return;
    }

    file << doctorID << "|"
         << name << "|"
         << age << "|"
         << gender << "|"
         << contact << "|"
         << specialization << "|"
         << department << "|"
         << availability << endl;

    file.close();

    cout << "Doctor information saved successfully." << endl;
}

// Load doctor information from file
void Doctor::loadFromFile()
{
    ifstream file("data/doctors.txt");

    if (!file)
    {
        cout << "Error: Unable to open doctors.txt" << endl;
        return;
    }

    string id;
    string fileName;
    string fileAge;
    string fileGender;
    string fileContact;
    string fileSpecialization;
    string fileDepartment;
    string fileAvailability;

    int doctorCount = 0;

    // Table heading
    cout << "\n" << string(122, '=') << endl;
    cout << setw(70) << "DOCTOR INFORMATION" << endl;
    cout << string(122, '=') << endl;

    cout << left
         << setw(12) << "Doctor ID"
         << setw(20) << "Name"
         << setw(8) << "Age"
         << setw(12) << "Gender"
         << setw(15) << "Contact"
         << setw(20) << "Specialization"
         << setw(15) << "Department"
         << setw(20) << "Availability"
         << endl;

    cout << string(122, '-') << endl;

    // Read and display each doctor
    while (getline(file, id, '|'))
    {
        getline(file, fileName, '|');
        getline(file, fileAge, '|');
        getline(file, fileGender, '|');
        getline(file, fileContact, '|');
        getline(file, fileSpecialization, '|');
        getline(file, fileDepartment, '|');
        getline(file, fileAvailability);

        cout << left
             << setw(12) << id
             << setw(20) << fileName
             << setw(8) << fileAge
             << setw(12) << fileGender
             << setw(15) << fileContact
             << setw(20) << fileSpecialization
             << setw(15) << fileDepartment
             << setw(20) << fileAvailability
             << endl;

        doctorCount++;
    }

    cout << string(122, '-') << endl;
    cout << "Total Number of Doctors: " << doctorCount << endl;
    cout << string(122, '=') << endl;

    file.close();
}


// Main function
int main()
{
    Doctor doctor;

    int choice;
    int detailsEntered = 0;

    do
    {
        cout << "\n====================================\n";
        cout << "     DOCTOR MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add Doctor Details\n";
        cout << "2. Update Doctor Details\n";
        cout << "3. Save Doctor Details\n";
        cout << "4. Display Doctor Records\n";
        cout << "5. Exit\n";

        cout << "====================================\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\n========== ADD DOCTOR DETAILS ==========\n";

                doctor.setDoctorDetails();

                detailsEntered = 1;

                cout << "\nDoctor details added successfully.\n";
                break;


            case 2:
                if (detailsEntered == 1)
                {
                    cout << "\n========== UPDATE DOCTOR DETAILS ==========\n";
                    cout << "Enter the updated doctor details:\n";

                    doctor.setDoctorDetails();

                    cout << "\nDoctor details updated successfully.\n";
                }
                else
                {
                    cout << "\nNo doctor details found to update.\n";
                    cout << "Please add doctor details first.\n";
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
                    cout << "\nNo doctor details available to save.\n";
                    cout << "Please add doctor details first.\n";
                }

                break;


            case 4:
                doctor.loadFromFile();
                break;


            case 5:
                cout << "\nExiting Doctor Management System...\n";
                break;


            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
