#include "PatientQueue.h"

/*
 *  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *  @             PATIENT QUEUE CLASS              @
 *  @       IN-DEPTH DOCUMENTATION IN HEADER       @
 *  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 */

/* push patient
 * adds patient to priority queue if that patient has an acceptable priority
 */
void PatientQueue::pushPatient(Patient p) {
    if (p.getPriority() != -1) {
        patientQ.push(p);
    }
    else {
        cout << "ERROR: No acceptable priority available! Patient not added." << endl;
    }
}
/* check next
 * return the next up patient but dont remove it
 */
Patient PatientQueue::checkNext() {
    Patient temp = patientQ.top();
    cout << "DEBUG: returning top patient" << endl;
    return temp;
}

/* getPatient
 * return the next up patient and remove it
 */
Patient PatientQueue::getPatient() {
    //Patient temp = patientQ.top().second;
    Patient temp = patientQ.top();
    patientQ.pop();
    cout << "DEBUG: returning and popping top patient" << endl;
    return temp;
}

bool PatientQueue::empty() {
    return patientQ.empty();
}
