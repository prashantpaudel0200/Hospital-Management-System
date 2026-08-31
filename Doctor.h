#pragma once

#include <string>

using namespace std;

class Doctor
{
private:
    int doctorID;
    string name;
    int age;
    string gender;
    string contact;
    string specialization;
    string department;
    string availability;

public:
    // Constructors
    Doctor();

    Doctor(int id, string n, int a, string g, string c,
           string s, string d, string av);

    // Input and display
    void setDoctorDetails();
    void displayDoctor();

    // Getter functions
    int getDoctorID();
    string getName();
    int getAge();
    string getGender();
    string getContact();
    string getSpecialization();
    string getDepartment();
    string getAvailability();

    // File handling
    void saveToFile();
    void loadFromFile();
};