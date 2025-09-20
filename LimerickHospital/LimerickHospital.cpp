

#include <iostream>
#include <string>
#include "PriorityHeap.h"
#include "Patient.h"


//Colours
//#include <windows.h> 


using namespace std;


//Add so that you cannot have a condition higher than 5.


void AddPatient(PQType<Patient>& pq, int& timestamp) //#1
{
    string name;
    int priority;

    cout << "Enter Patient's Name: ";
    cin >> name;

    do {
        cout << "Enter the Patient's Condition (1-5): ";
        cin >> priority;
    } while (priority < 1 || priority > 5);

    Patient newPatient(name, priority, timestamp);
    pq.Enqueue(newPatient);
    timestamp++; 
}




void CallNextPatient(PQType<Patient>& pq)//#2
{
    if (pq.IsEmpty())
    {
        cout << "No patients.\n";
    }
    else 
    {
        Patient p("", 0, 0);
        pq.Dequeue(p);
        cout << "Next Patient: " << p.GetName() << endl;
    }
}


void DisplayCurrentQueue(PQType<Patient>& pq) // #3
{
    if (pq.IsEmpty())
    {
        cout << "No patients.\n";
        return;
    }

    cout << "Current Queue of Patients:\n";

    PQType<Patient> tempQueue = pq;
    Patient currentPatient;

    while (!tempQueue.IsEmpty())
    {
        tempQueue.Dequeue(currentPatient);
        cout << "Name: " << currentPatient.GetName()
            << " Priority: " << currentPatient.GetPriority() << endl;
    }
}

void SearchPatient(PQType<Patient>& pq) // #4
{
    if (pq.IsEmpty())
    {
        cout << "No patients.\n";
        return;
    }

    string searchName;
    cout << "Enter Patient's Name to search: ";
    cin >> searchName;

    bool found = false;
    for (int i = 0; i < pq.numItems; i++)
    {
        Patient currentPatient = pq.items.elements[i];
        if (currentPatient.GetName() == searchName)
        {
            cout << "Patient Found -> Name: " << currentPatient.GetName()
                << ", Condition: " << currentPatient.GetPriority() << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Patient not found.\n";
    }
}





void DisplayPatients(PQType<Patient>& pq)//#5
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
    PQType<Patient> patientQueue(10); //max no of patients = 100
    //PQType<Patient> tempQueue(10);
    int choice;

    //Patient currentPatient;
        
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
                DisplayCurrentQueue(patientQueue);
                
                break; 

            case 4:
                //Search Patient
                SearchPatient(patientQueue);
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

