#include "patient.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Default constructor
Patient::Patient()
{
    patientID = 0;
    name = "";
    age = 0;
    gender = "";
    contact = "";
    disease = "";
}

// Parameterized constructor
Patient::Patient(int id, string n, int a, string g, string c, string d)
{
    patientID = id;
    name = n;
    age = a;
    gender = g;
    contact = c;
    disease = d;
}

// Set patient details
void Patient::setPatientDetails()
{
    cout << "\nEnter Patient ID: ";
    cin >> patientID;
    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Gender: ";
    getline(cin, gender);

    cout << "Enter Contact Number: ";
    getline(cin, contact);

    cout << "Enter Disease/Problem: ";
    getline(cin, disease);
}

// Display patient details
void Patient::displayPatient()
{
    cout << "\n-----------------------------" << endl;
    cout << "       PATIENT DETAILS       " << endl;
    cout << "-----------------------------" << endl;

    cout << "Patient ID : " << patientID << endl;
    cout << "Name       : " << name << endl;
    cout << "Age        : " << age << endl;
    cout << "Gender     : " << gender << endl;
    cout << "Contact    : " << contact << endl;
    cout << "Disease    : " << disease << endl;

    cout << "-----------------------------" << endl;
}

// Get Patient ID
int Patient::getPatientID()
{
    return patientID;
}

// Get Patient Name
string Patient::getName()
{
    return name;
}

// Get Patient Age
int Patient::getAge()
{
    return age;
}

// Get Patient Gender
string Patient::getGender()
{
    return gender;
}

// Get Patient Contact
string Patient::getContact()
{
    return contact;
}

// Get Patient Disease
string Patient::getDisease()
{
    return disease;
}

// Save patient information to file
void Patient::saveToFile()
{
    ofstream file("data/patients.txt", ios::app);

    if (!file)
    {
        cout << "Error: Unable to open patients.txt" << endl;
        return;
    }

    file << patientID << "|"
         << name << "|"
         << age << "|"
         << gender << "|"
         << contact << "|"
         << disease << endl;

    file.close();

    cout << "Patient information saved successfully." << endl;
}

// Load patient information from file
void Patient::loadFromFile()
{
    ifstream file("data/patients.txt");

    if (!file)
    {
        cout << "Error: Unable to open patients.txt" << endl;
        return;
    }

    string line;

    cout << "\n========== PATIENT RECORDS ==========\n";

    while (getline(file, line))
    {
        if (!line.empty())
        {
            cout << line << endl;
        }
    }

    file.close();
}