#include "BillingModule.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Default constructor
Billing::Billing()
{
    billID = 0;

    patientID = 0;
    patientName = "";

    doctorID = 0;
    doctorName = "";

    consultationFee = 0;
    medicineCharges = 0;
    roomCharges = 0;
    otherCharges = 0;

    subtotal = 0;
    vatCharge = 0;
    overallCharge = 0;
}

// Parameterized constructor
Billing::Billing(int bID, int pID, string pName,
                 int dID, string dName,
                 float consultation, float medicine,
                 float room, float other)
{
    billID = bID;

    patientID = pID;
    patientName = pName;

    doctorID = dID;
    doctorName = dName;

    consultationFee = consultation;
    medicineCharges = medicine;
    roomCharges = room;
    otherCharges = other;

    calculateBill();
}

// Enter bill details
void Billing::setBillDetails()
{
    cout << "\nEnter Bill ID: ";
    cin >> billID;

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

    cout << "Enter Consultation Fee: Rs. ";
    cin >> consultationFee;

    cout << "Enter Medicine Charges: Rs. ";
    cin >> medicineCharges;

    cout << "Enter Room Charges: Rs. ";
    cin >> roomCharges;

    cout << "Enter Other Charges: Rs. ";
    cin >> otherCharges;

    calculateBill();
}

// Calculate bill
void Billing::calculateBill()
{
    subtotal = consultationFee
             + medicineCharges
             + roomCharges
             + otherCharges;

    vatCharge = subtotal * 13 / 100;

    overallCharge = subtotal + vatCharge;
}

// Display bill details
void Billing::displayBill()
{
    cout << "\n============================================================\n";
    cout << "                       HOSPITAL BILL\n";
    cout << "============================================================\n";

    cout << "Bill ID             : " << billID << endl;

    cout << "Patient ID          : " << patientID << endl;
    cout << "Patient Name        : " << patientName << endl;

    cout << "Doctor ID           : " << doctorID << endl;
    cout << "Doctor Name         : " << doctorName << endl;

    cout << "------------------------------------------------------------\n";

    cout << fixed << setprecision(2);

    cout << "Consultation Fee    : Rs. " << consultationFee << endl;
    cout << "Medicine Charges    : Rs. " << medicineCharges << endl;
    cout << "Room Charges        : Rs. " << roomCharges << endl;
    cout << "Other Charges       : Rs. " << otherCharges << endl;

    cout << "------------------------------------------------------------\n";

    cout << "Subtotal            : Rs. " << subtotal << endl;
    cout << "VAT (13%)           : Rs. " << vatCharge << endl;

    cout << "============================================================\n";
    cout << "Overall Charge      : Rs. " << overallCharge << endl;
    cout << "============================================================\n";
}

// Get Bill ID
int Billing::getBillID()
{
    return billID;
}

// Get Patient ID
int Billing::getPatientID()
{
    return patientID;
}

// Get Patient Name
string Billing::getPatientName()
{
    return patientName;
}

// Get Doctor ID
int Billing::getDoctorID()
{
    return doctorID;
}

// Get Doctor Name
string Billing::getDoctorName()
{
    return doctorName;
}

// Get Consultation Fee
float Billing::getConsultationFee()
{
    return consultationFee;
}

// Get Medicine Charges
float Billing::getMedicineCharges()
{
    return medicineCharges;
}

// Get Room Charges
float Billing::getRoomCharges()
{
    return roomCharges;
}

// Get Other Charges
float Billing::getOtherCharges()
{
    return otherCharges;
}

// Get Subtotal
float Billing::getSubtotal()
{
    return subtotal;
}

// Get VAT Charge
float Billing::getVatCharge()
{
    return vatCharge;
}

// Get Overall Charge
float Billing::getOverallCharge()
{
    return overallCharge;
}

// Save bill information to file
void Billing::saveToFile()
{
    ofstream file("data/bills.txt", ios::app);

    if (!file)
    {
        cout << "Error: Unable to open bills.txt" << endl;
        return;
    }

    file << billID << "|"
         << patientID << "|"
         << patientName << "|"
         << doctorID << "|"
         << doctorName << "|"
         << consultationFee << "|"
         << medicineCharges << "|"
         << roomCharges << "|"
         << otherCharges << "|"
         << subtotal << "|"
         << vatCharge << "|"
         << overallCharge << endl;

    file.close();

    cout << "Bill information saved successfully." << endl;
}

// Load bill information from file
void Billing::loadFromFile()
{
    ifstream file("data/bills.txt");

    if (!file)
    {
        cout << "Error: Unable to open bills.txt" << endl;
        return;
    }

    string line;

    cout << "\n========== BILL RECORDS ==========\n";

    while (getline(file, line))
    {
        if (!line.empty())
        {
            cout << line << endl;
        }
    }

    file.close();
}