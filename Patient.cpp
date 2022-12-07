/***************************************************************
 * Name        : Patient
 * Author      : Elijah Edlund
 * Created     : 12/05/2022
 ***************************************************************/

#include "Patient.h"

/*
 *  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *  @                PATIENT CLASS                 @
 *  @       IN-DEPTH DOCUMENTATION IN HEADER       @
 *  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 */

/* Empty constructor
 * sets id to 0,name to empty, and priority to -1
 */
Patient::Patient() {
    this->id = 0;
    this->name = "";
    this->priority = -1;
}
/* Constructor
 * sets id, name, and priority
 */
Patient::Patient(int id, string name, int priority, string dob) {
    this->id = id;
    this->name = name;
    this->priority = priority;
    this->dateOfBirth = dob;
}
/* set id
 * sets the id
 */
void Patient::setId(int id) {
    this->id = id;
}
/* set name
 * sets the name
 */
void Patient::setName(string name) {
    this->name = name;
}
/* set priority
 * sets the priority
 */
void Patient::setPriority(int priority) {
    this->priority = priority;
}

/* set dateofbirth
 * sets date of birth
 */
void Patient::setDateOfBirth(string dob) {
    this->dateOfBirth = dob;
}
/* get id
 * returns the id
 */
int Patient::getId() {
    return this->id;
}
/* get name
 * returns the name
 */
string Patient::getName() {
    return this->name;
}
/* get priority
 * returns the priority
 */
int Patient::getPriority() {
    return this->priority;
}

/* get dateofbirth
 * returns the date of birth
 */
string Patient::getDateOfBirth()
{
    return this->dateOfBirth;
}
/* info
 * returns info about patient
 */
string Patient::info() {
    string toPrint = ("[ID: " + to_string(this->id) + ", Name: " + this->name + ", Priority: " + to_string(this->priority) + ", Date of Birth: " + this->dateOfBirth + "]");
    return toPrint;
}
