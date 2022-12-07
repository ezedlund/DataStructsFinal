/***************************************************************
 * Name        : PatientQueue
 * Author      : Elijah Edlund
 * Created     : 12/05/2022
 ***************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include "Patient.h"
using namespace std;
#pragma once

class PatientQueue
{
protected:
    /**************************************************************
     * Name: lessThanPriority
     * Description: used to compare patients via their priority value
     ***************************************************************/
    struct lessThanPriority {
        bool operator()(const Patient& pat1, const Patient& pat2) const {
            return pat1.priority < pat2.priority;
        }
    };

    priority_queue<Patient, vector<Patient>, lessThanPriority> patientQ;
public:
    /**************************************************************
     * Constructors
     ***************************************************************/
    /**************************************************************
     * Name: PatientQueue
     * Description: Default no-arg constructor
     * Input parameters: none
     ***************************************************************/
    PatientQueue() {};

    /***************************************************************
     * Class Functions
     ***************************************************************/
    /**************************************************************
    * Name: pushPatient
    * Description: pushes patient into queue
    * Input: Patient p
    ***************************************************************/
    void pushPatient(Patient p);

    /**************************************************************
    * Name: checkNext
    * Description: returns next patient in queue
    * Output: Patient
    ***************************************************************/
    Patient checkNext();

    /**************************************************************
     * Name: getPatient
     * Description: returns next patient in queue and pops them
     * Output: Patient
     ***************************************************************/
    Patient getPatient();

    /**************************************************************
     * Name: empty
     * Description: returns true if queue is empty
     * Output: bool
     ***************************************************************/
    bool empty();
};
