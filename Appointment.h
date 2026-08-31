#pragma once

#include <string>

using namespace std;

class Appointment
{
private:
    int appointmentID;

    int patientID;
    string patientName;

    int doctorID;
    string doctorName;

    string date;
    string time;
    string status;

public:
    // Constructors
    Appointment();

    Appointment(int aid, int pid, string pname,
                int did, string dname,
                string dt, string tm, string st);

    // Appointment functions
    void setAppointmentDetails();
    void displayAppointment();

    // Getter functions
    int getAppointmentID();
    int getPatientID();
    string getPatientName();

    int getDoctorID();
    string getDoctorName();

    string getDate();
    string getTime();
    string getStatus();

    // Appointment management
    void setStatus(string st);
    void cancelAppointment();
    void searchByPatientID();

    // File handling
    void saveToFile();
    void loadFromFile();
};