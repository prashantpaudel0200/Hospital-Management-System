#include "Doctor.h"
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
    cout << "\n" << string(122, '=') << endl;
    cout << "                         DOCTOR INFORMATION" << endl;
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

    cout << string(122, '=') << endl;
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

    cout << "\n" << string(122, '=') << endl;
    cout << "                         DOCTOR INFORMATION" << endl;
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