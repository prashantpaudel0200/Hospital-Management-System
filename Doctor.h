#pragma once
#include <iostream>
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
    Doctor();
    Doctor(int id, string n, int a, string g, string c,
           string s, string d, string av);

    void setDoctorDetails();
    void displayDoctor();

    int getDoctorID();
    string getName();
    int getAge();
    string getGender();
    string getContact();
    string getSpecialization();
    string getDepartment();
    string getAvailability();

    void saveToFile();
    void loadFromFile();
};