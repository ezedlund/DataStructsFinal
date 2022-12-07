#include "Room.h"

/*
 *  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *  @                 ROOM CLASS                   @
 *  @       IN-DEPTH DOCUMENTATION IN HEADER       @
 *  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 */

   // default no args
Room::Room()
{
    this->open = false;
}

// doc info
Room::Room(string docName, string docID, bool open, int roomId)
{
    this->doctorName = docName;
    this->doctorId = docID;
    this->open = open;
    this->roomId = roomId;
}

// doc info and patient
Room::Room(string docName, string docID, bool open, Patient pat, int roomId)
{
    this->doctorName = docName;
    this->doctorId = docID;
    this->open = open;
    this->pat = pat;
    this->roomId = roomId;
}

// release patient
void Room::releasePatient() {
    // check if room has patient
    if (this->open == false) {
        // remove patient
        this->pat = Patient();
        this->open = true;
    }
    else {
        throw invalid_argument("Room is empty.");
    }
}

// receive patient
void Room::receivePatient(Patient patient) {
    // check if room is empty
    if (this->open == true) {
        this->pat = patient;
        this->open = false;
    }
    else {
        throw invalid_argument("Room is full.");
    }
}

void Room::setDocName(string docName) {
    this->doctorName = docName;
}

string Room::getDocName() {
    return this->doctorName;
}

void Room::setDocId(string docId) {
    this->doctorId = docId;
}

void Room::setRoomId(int roomId)
{
    this->roomId = roomId;
}

int Room::getRoomId()
{
    return this->roomId;
}

string Room::getDocId() {
    return this->doctorId;
}

bool Room::getStatus() {
    return this->open;
}
