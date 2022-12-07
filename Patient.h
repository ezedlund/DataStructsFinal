/***************************************************************
 * Name        : Patient
 * Author      : Elijah Edlund
 * Created     : 12/05/2022
 ***************************************************************/

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Patient
{
protected:
    int id;
    string name;
    string dateOfBirth;
public:
    int priority;

    /**************************************************************
     * Constructors
     ***************************************************************/
    /**************************************************************
     * Name: Classname
     * Description: Default no-arg constructor
     * Input parameters: none
     ***************************************************************/
    Patient();

    /**************************************************************
     * Name: ClassName
     * Description: Constructor that accepts id, name, priority, and dob.
     * Input: int id, string name, int priority, string dob
     ***************************************************************/
    Patient(int id, string name, int priority, string dob);

    /***************************************************************
     * Class Functions
     ***************************************************************/

    /**************************************************************
     * Name: setId
     * Description: sets ID
     * Input: int id
     ***************************************************************/
    void setId(int id);

    /**************************************************************
     * Name: setName
     * Description: sets name
     * Input: string name
     ***************************************************************/
    void setName(string name);

    /**************************************************************
     * Name: setPriority
     * Description: sets priority
     * Input: int priority
     ***************************************************************/
    void setPriority(int priority);

    /**************************************************************
     * Name: setDateOfBirth
     * Description: sets dob
     * Input: string dob
     ***************************************************************/
    void setDateOfBirth(string dob);

    /**************************************************************
     * Name: getId
     * Description: gets ID
     * Output: int ID
     ***************************************************************/
    int getId();

    /**************************************************************
     * Name: getName
     * Description: gets name
     * Output: string name
     ***************************************************************/
    string getName();

    /**************************************************************
     * Name: getPriority
     * Description: gets priority
     * Output: int priority
     ***************************************************************/
    int getPriority();

    /**************************************************************
     * Name: getDateOfBirth
     * Description: gets dob
     * Output: string dob
     ***************************************************************/
    string getDateOfBirth();

    /**************************************************************
     * Name: info
     * Description: gets patient
     * Output: string
     ***************************************************************/
    string info();
};
