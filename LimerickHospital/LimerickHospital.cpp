

#include <iostream>
#include <string>
#include "PriorityHeap.h"
#include "Patient.h"



using namespace std;



void AddPatient(PQType<Patient>& pq, int timestamp)
{
    string name;
    int priority;

    cout << "Enter Patient's Name: ";
    cin >> name;

    cout << "Enter the Patient's Condition (1-5): ";
    cin >> priority;

    Patient newPatient(name, priority, timestamp);
    pq.Enqueue(newPatient);
    timestamp++;
}

void CallNextPatient(PQType<Patient>& pq)
{
    if (pq.IsEmpty()) cout << "No patients.\n";
    else {
        Patient p("", 0, 0);
        pq.Dequeue(p);
        cout << "Next: " << p.GetName() << endl;
    }
}


void DisplayPatients(PQType<Patient>& pq)
{
    if (pq.IsEmpty())
    {
        cout << "No patients in the queue." << endl;
        return;
    }

    cout << "Current Queue of Patients:" << endl;

    for (int i = 0; i < pq.numItems; ++i)  
    {
        Patient currentPatient = pq.items.elements[i];
        cout << "Name: " << currentPatient.GetName() << ", Condition: " << currentPatient.GetPriority() << endl;
    }
}









int main()
{
    
    int timestamp = 0;
    PQType<Patient> patientQueue(100);
    int choice;
    
    while (true)
    {
        cout << "\n--Menu--" << endl;
        cout << "1. Add a new patient" << endl;
        cout << "2. Call the next patient (Delete)" << endl;
        cout << "3. Print the current Queue of Patients" << endl;
        cout << "4. Search for a patient" << endl;
        cout << "5. Display Patients" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice:\n " << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                //Add the patients
                AddPatient(patientQueue, timestamp);
                break;

            case 2: 
                //Call next patient
                CallNextPatient(patientQueue);
                break;

            case 3: 
                //Print current queue
                break; 

            case 4:
                //Search Patient
                break;

            case 5: 
                //Display Patients
                DisplayPatients(patientQueue);
                break;

            case 6: 
                //Exit
                cout << "Exiting Program" << endl;
                break;


            default: 
                cout << "Invalid Input" << endl;

        }
    }


}

