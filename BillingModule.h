#pragma once

#include <string>

using namespace std;

class Billing
{
private:
    int billID;

    int patientID;
    string patientName;

    int doctorID;
    string doctorName;

    float consultationFee;
    float medicineCharges;
    float roomCharges;
    float otherCharges;

    float subtotal;
    float vatCharge;
    float overallCharge;

public:
    
    Billing();

    Billing(int bID, int pID, string pName,
            int dID, string dName,
            float consultation, float medicine,
            float room, float other);

   
    void setBillDetails();

    void calculateBill();

    void displayBill();

    int getBillID();

    int getPatientID();
    string getPatientName();

    int getDoctorID();
    string getDoctorName();

    float getConsultationFee();
    float getMedicineCharges();
    float getRoomCharges();
    float getOtherCharges();

    float getSubtotal();
    float getVatCharge();
    float getOverallCharge();


    void saveToFile();
    void loadFromFile();
};