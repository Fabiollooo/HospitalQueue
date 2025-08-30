#pragma once
#include <string>
#include <iostream>


using namespace std;



class Patient {
public:
    Patient() : name(""), priority(0), admissionTime(0) {} //default constructor (Error: Line 46 'PriorityHeap'
    Patient(string n, int p, int t) : name(n), priority(p), admissionTime(t) {}


    string GetName() const { return name; }
    int GetPriority() const { return priority; }
    int GetAdmission() const { return admissionTime; }

private:
    string name;
    int priority;
    int admissionTime;
};
