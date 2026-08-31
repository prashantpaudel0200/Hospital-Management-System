#include "Appointment.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Default constructor
Appointment::Appointment()
{
    appointmentID = 0;
    patientID = 0;
    patientName = "";
    doctorID = 0;
    doctorName = "";
    date = "";
    time = "";
    status = "Scheduled";
}

// Parameterized constructor
Appointment::Appointment(int aid, int pid, string pname,
                         int did, string dname,
                         string dt, string tm, string st)
{
    appointmentID = aid;
    patientID = pid;
    patientName = pname;
    doctorID = did;
    doctorName = dname;
    date = dt;
    time = tm;
    status = st;
}

// Set appointment details
void Appointment::setAppointmentDetails()
{
    cout << "\nEnter Appointment ID: ";
    cin >> appointmentID;
    cin.ignore();

    cout << "Enter Patient ID: ";
    cin >> patientID;
    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, patientName);

    cout << "Enter Doctor ID: ";
    cin >> doctorID;
    cin.ignore();

    cout << "Enter Doctor Name: ";
    getline(cin, doctorName);

    cout << "Enter Appointment Date (DD-MM-YYYY): ";
    getline(cin, date);

    cout << "Enter Appointment Time (HH:MM): ";
    getline(cin, time);

    status = "Scheduled";
}

// Display appointment
void Appointment::displayAppointment()
{
    cout << "\n========================================" << endl;
    cout << "       APPOINTMENT DETAILS" << endl;
    cout << "========================================" << endl;

    cout << "Appointment ID : " << appointmentID << endl;
    cout << "Patient ID     : " << patientID << endl;
    cout << "Patient Name   : " << patientName << endl;
    cout << "Doctor ID      : " << doctorID << endl;
    cout << "Doctor Name    : " << doctorName << endl;
    cout << "Date           : " << date << endl;
    cout << "Time           : " << time << endl;
    cout << "Status         : " << status << endl;

    cout << "========================================" << endl;
}

// Get Appointment ID
int Appointment::getAppointmentID()
{
    return appointmentID;
}

// Get Patient ID
int Appointment::getPatientID()
{
    return patientID;
}

// Get Patient Name
string Appointment::getPatientName()
{
    return patientName;
}

// Get Doctor ID
int Appointment::getDoctorID()
{
    return doctorID;
}

// Get Doctor Name
string Appointment::getDoctorName()
{
    return doctorName;
}

// Get Appointment Date
string Appointment::getDate()
{
    return date;
}

// Get Appointment Time
string Appointment::getTime()
{
    return time;
}

// Get Appointment Status
string Appointment::getStatus()
{
    return status;
}

// Set Appointment Status
void Appointment::setStatus(string st)
{
    status = st;
}

// Save appointment
void Appointment::saveToFile()
{
    ofstream file("data/appointments.txt", ios::app);

    if (!file)
    {
        cout << "Error: Unable to open appointments.txt" << endl;
        return;
    }

    file << appointmentID << "|"
         << patientID << "|"
         << patientName << "|"
         << doctorID << "|"
         << doctorName << "|"
         << date << "|"
         << time << "|"
         << status << endl;

    file.close();

    cout << "Appointment scheduled successfully." << endl;
}

// Load appointments
void Appointment::loadFromFile()
{
    ifstream file("data/appointments.txt");

    if (!file)
    {
        cout << "Error: Unable to open appointments.txt" << endl;
        return;
    }

    string line;

    cout << "\n========== APPOINTMENT RECORDS ==========\n";

    while (getline(file, line))
    {
        if (!line.empty())
        {
            cout << line << endl;
        }
    }

    file.close();
}

// Cancel appointment
void Appointment::cancelAppointment()
{
    int targetID;

    cout << "\nEnter Appointment ID to cancel: ";
    cin >> targetID;

    ifstream inFile("data/appointments.txt");

    if (!inFile)
    {
        cout << "Error: Unable to open appointments.txt" << endl;
        return;
    }

    vector<string> lines;
    string line;
    bool found = false;

    while (getline(inFile, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);

        string idStr, pid, pname, did, dname, dt, tm, st;

        getline(ss, idStr, '|');
        getline(ss, pid, '|');
        getline(ss, pname, '|');
        getline(ss, did, '|');
        getline(ss, dname, '|');
        getline(ss, dt, '|');
        getline(ss, tm, '|');
        getline(ss, st, '|');

        if (stoi(idStr) == targetID)
        {
            line = idStr + "|" + pid + "|" + pname + "|" +
                   did + "|" + dname + "|" + dt + "|" +
                   tm + "|Cancelled";

            found = true;
        }

        lines.push_back(line);
    }

    inFile.close();

    if (!found)
    {
        cout << "Appointment ID not found." << endl;
        return;
    }

    ofstream outFile("data/appointments.txt", ios::trunc);

    if (!outFile)
    {
        cout << "Error: Unable to update appointments.txt" << endl;
        return;
    }

    for (int i = 0; i < lines.size(); i++)
    {
        outFile << lines[i] << endl;
    }

    outFile.close();

    cout << "Appointment cancelled successfully." << endl;
}

// Search appointment by Patient ID
void Appointment::searchByPatientID()
{
    int targetPID;

    cout << "\nEnter Patient ID to search: ";
    cin >> targetPID;

    ifstream file("data/appointments.txt");

    if (!file)
    {
        cout << "Error: Unable to open appointments.txt" << endl;
        return;
    }

    string line;
    bool found = false;

    cout << "\nAppointments for Patient ID "
         << targetPID << ":\n";

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);

        string idStr;
        string pidStr;

        getline(ss, idStr, '|');
        getline(ss, pidStr, '|');

        if (stoi(pidStr) == targetPID)
        {
            cout << line << endl;
            found = true;
        }
    }

    file.close();

    if (!found)
    {
        cout << "No appointments found for this Patient ID." << endl;
    }
}