/***************************************************************
 * Name        : Room
 * Author      : Elijah Edlund
 * Created     : 12/05/2022
 ***************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include "Patient.h"
using namespace std;
#pragma once

class Room {
protected:
    string doctorName;
    string doctorId;
    int roomId;
    Patient pat;
    bool open;
public:
    /**************************************************************
     * Constructors
     ***************************************************************/
    /**************************************************************
     * Name: Room
     * Description: Default no-arg constructor
     * Input parameters: none
     ***************************************************************/
    Room();

    /**************************************************************
     * Name: Room
     * Description: assign doctors name and ID aswell as room status
     * Input parameters: string docName, string docID, bool open
     ***************************************************************/
    Room(string docName, string docID, bool open, int id);

    /**************************************************************
     * Name: Room
     * Description: assign doctors name and ID aswell as room status and a patient
     * Input parameters: string docName, string docID, bool open, Patient pat
     ***************************************************************/
    Room(string docName, string docID, bool open, Patient pat, int id);

    /***************************************************************
     * Class Functions
     ***************************************************************/
    /**************************************************************
     * Name: releasePatient
     * Description: releasesPatient
     ***************************************************************/
    void releasePatient();
    /**************************************************************
     * Name: receivePatient
     * Description: receives a Patient
     ***************************************************************/
    void receivePatient(Patient patient);
    /**************************************************************
     * Name: setDocName
     * Description: sets doctors name
     * Input: string docName
     **************************************************************/
    void setDocName(string docName);
    /**************************************************************
     * Name: getDocName
     * Description: gets doctors name
     * output: string docName
     **************************************************************/
    string getDocName();
    /**************************************************************
     * Name: setDocID
     * Description: sets doctors ID
     * Input: string docId
     **************************************************************/
    void setDocId(string docId);
    /**************************************************************
     * Name: getDocID
     * Description: gets doctors ID
     * output: string docId
     **************************************************************/
    string getDocId();
    /**************************************************************
     * Name: setRoomID
     * Description: sets room ID
     **************************************************************/
    void setRoomId(int roomId);
    /**************************************************************
     * Name: getRoomID
     * Description: gets room ID
     * output: int roomId
     **************************************************************/
    int getRoomId();
    /**************************************************************
     * Name: getStatus
     * Description: gets status
     * output: bool open
     **************************************************************/
    bool getStatus();
};
