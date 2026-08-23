#pragma once

#include <string>

using namespace std;

class Patient
{
private:
    // Patient information
    int patientID;
    string name;
    int age;
    string gender;
    string contact;
    string disease;

public:
    // Constructors
    Patient();
    Patient(int id, string n, int a, string g, string c, string d);

    // Input patient details
    void setPatientDetails();

    // Display patient details
    void displayPatient();

    // Getter functions
    int getPatientID();
    string getName();
    int getAge();
    string getGender();
    string getContact();
    string getDisease();

    // File handling functions
    void saveToFile();
    void loadFromFile();
};