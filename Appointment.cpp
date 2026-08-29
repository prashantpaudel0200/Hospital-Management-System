#include "Appointment.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

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

Appointment::Appointment(int aid, int pid, string pname, int did, string dname, string dt, string tm, string st)
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

void Appointment::displayAppointment()
{
    cout << "\nAppointment ID: " << appointmentID << endl;
    cout << "Patient ID: " << patientID << endl;
    cout << "Patient Name: " << patientName << endl;
    cout << "Doctor ID: " << doctorID << endl;
    cout << "Doctor Name: " << doctorName << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Status: " << status << endl;
}

int Appointment::getAppointmentID()
{
    return appointmentID;
}

int Appointment::getPatientID()
{
    return patientID;
}

string Appointment::getPatientName()
{
    return patientName;
}

int Appointment::getDoctorID()
{
    return doctorID;
}

string Appointment::getDoctorName()
{
    return doctorName;
}

string Appointment::getDate()
{
    return date;
}

string Appointment::getTime()
{
    return time;
}

string Appointment::getStatus()
{
    return status;
}

void Appointment::setStatus(string st)
{
    status = st;
}

void Appointment::saveToFile()
{
    ofstream file("data/appointments.txt", ios::app);
    if (!file)
    {
        cout << "Error: Unable to open appointments.txt" << endl;
        return;
    }

    file << appointmentID << "|" << patientID << "|" << patientName << "|" << doctorID << "|" << doctorName << "|" << date << "|" << time << "|" << status << endl;

    file.close();
    cout << "Appointment scheduled successfully." << endl;
}

void Appointment::loadFromFile()
{
    ifstream file("data/appointments.txt");
    if (!file)
    {
        cout << "Error: Unable to open appointments.txt" << endl;
        return;
    }

    string line;
    cout << "\nAppointment Records:\n";
    while (getline(file, line))
    {
        if (line == "")
            continue;
        cout << line << endl;
    }
    file.close();
}

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
        if (line == "")
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
            line = idStr + "|" + pid + "|" + pname + "|" + did + "|" + dname + "|" + dt + "|" + tm + "|Cancelled";
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
    for (int i = 0; i < lines.size(); i++)
    {
        outFile << lines[i] << endl;
    }
    outFile.close();

    cout << "Appointment cancelled successfully." << endl;
}

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
    cout << "\nAppointments for Patient ID " << targetPID << ":\n";

    while (getline(file, line))
    {
        if (line == "")
            continue;

        stringstream ss(line);
        string idStr, pidStr;
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
        cout << "No appointments found for this Patient ID." << endl;
}
