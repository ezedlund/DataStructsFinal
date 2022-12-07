/***************************************************************
 * Name        : mainwindow
 * Author      : Elijah Edlund
 * Created     : 12/05/2022
 ***************************************************************/

/*
 *  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 *  @             MAINWINDOW CLASS                 @
 *  @       IN-DEPTH DOCUMENTATION IN HEADER       @
 *  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 */

// ############################################################################################# //
// ### Almost all of this code was tested but I could not figure a way to do the traditional ### //
// ### testing in another file as I only ever used QT or QTGUI breafily. However, the basic  ### //
// ### functions and most calls were tested as well as any QT specific calls or anytime      ### //
// ### ui-> was called.                                                                      ### //
// ############################################################################################# //

#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 *  !!! Global Variables !!!
 */
PatientQueue pQueue;
Patient pat;
Room room("Dr. Tue Busi", "MD2", false, 1);
Room room3("Dr. James Gordan", "MD1", true, 3);
Room room2("Dr. Seymar Patients", "MD2", false, 2);
Room room4("Dr. Mariah Key", "MD8", false, 4);
list<Room> rooms = { room2, room, room4, room3 };
Room activeRoom;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui; // ### This was tested ### //
}

/*
 * !!! Okay button !!!
 *
 * init and verify info
 * create patient and patient queue
 */
void MainWindow::on_pushButton_clicked()
{
    /*
     * Init
     */
    int id = 0;
    QString error;
    bool errorRaise;
    string name = "";
    string DOB = "";
    int severityLvl = -999;

    // ### This was all tested ### //
    // sort rooms list by room id
    rooms.sort([](Room r1, Room r2) {return r1.getRoomId() < r2.getRoomId(); });
    // get first available room
    for (auto r : rooms) {
        if (r.getStatus()) {
            activeRoom = r;
            break;
        }
    }
    if (activeRoom.getDocName() == "") {
        // No valid rooms
        // Would normally trigger a wait
        // here we are going to shut down for the sim
        close();
    }

    /*
     * Start loop
     */
    while (true) {
        /*
         * Set / Reset values
         */
        errorRaise = false;
        error = "Error: ";
        ui->labelError->clear();

        /*
         * !!! Validate name !!!
         */
        if (ui->lineEditName->text().toStdString() != "") {
            /*
             * !!! Name is valid !!!
             * Assign name
             */
            name = ui->lineEditName->text().toStdString();
        }
        else {
            /*
             * !!! Name is invalid !!!
             * append to error message, set errorRaise to true and break loop
             */
            error += "Please enter a valid name.";
            errorRaise = true;
            break;
        }

        /*
         * !!! Validate date of birth / dob !!!
         */
        if (regex_match(ui->lineEditDOB->text().toStdString(), regex("[0-9][0-9]/[0-9][0-9]/[0-9][0-9][0-9][0-9]"))) {
            /*
             * !!! dob is valid !!!
             * Assign dob
             */
            DOB = ui->lineEditDOB->text().toStdString();
        }
        else {
            /*
             * !!! Date of birth is invalid !!!
             * append to error message, set errorRaise to true and break loop
             */
            error += "Please enter a valid date of birth.";
            errorRaise = true;
            break;
        }

        /*
         * !!! Validate severity / priority !!!
         */
        if (ui->comboBox->currentText() == "Please select a severity") {
            /*
             * !!! Severity is invalid !!!
             * append to error message, set errorRaise to true and break loop
             */
            error += "Please select a severity.";
            errorRaise = true;
            break;
        }
        else {
            /*
             * !!! Severity is valid !!!
             * check severity level and assign severity
             */
            if (ui->comboBox->currentText().contains("1.")) {
                severityLvl = 1;
            } else if (ui->comboBox->currentText().contains("2.")) {
                severityLvl = 2;
            } else if  (ui->comboBox->currentText().contains("3.")) {
                severityLvl = 3;
            }
        }

        /*
         * Break while loop
         */
        break;
    }

    /*
     * !!! Check if an error was raised with errorRaise value !!!
     */
    if (errorRaise)
        /*
         * !!! Error was raised !!!
         * Print error messgae
         */
        ui->labelError->setText(error);
    else {
        /*
         * !!! Error was not raised !!!
         * Assign values to patient
         * Add patient to global patient queue
         * Print saved message and next hint
         * Unlock / Enable next button
         */
        pat.setDateOfBirth(DOB);
        pat.setName(name);
        pat.setPriority(severityLvl);
        pat.setId(id++);
        pQueue.pushPatient(pat);

        // Simulate other patients
        // ### This was all tested ### //
        Patient pat2 = Patient(id++, "James Smith", 3, "11/05/1998");
        Patient pat3 = Patient(id++, "Joran Koi", 2, "08/23/1999");
        Patient pat4 = Patient(id++, "Kaylie Martin", 1, "02/05/2003");
        Patient pat5 = Patient(id++, "Bortar Geebs", 2, "02/01/2014");
        pQueue.pushPatient(pat2);
        pQueue.pushPatient(pat3);
        pQueue.pushPatient(pat4);
        pQueue.pushPatient(pat5);

        ui->labelError->setText("Information saved!\nClick the Next button to wait your turn");
        ui->pushButton_2->setEnabled(true); // ### This was tested ### //
    }
}

/*
 * !!! Next button !!!
 * setup
 */
void MainWindow::on_pushButton_2_clicked() {
    /*
     * !!! Delete labels that wont be used !!!
     */
    // ### This was all tested ### //
    ui->labelDOB->setGeometry(QRect(0, 0, 0, 0));
    ui->labelName->setGeometry(QRect(0, 0, 0, 0));
    ui->labelSevere->setGeometry(QRect(0, 0, 0, 0));
    ui->lineEditDOB->deleteLater();
    ui->lineEditName->deleteLater();
    ui->comboBox->deleteLater();
    ui->pushButton->deleteLater();
    ui->pushButton_2->deleteLater();

    /*
     * !!! Rename and re-use !!!
     */
    ui->labelMain->setText(QString::fromStdString("Waiting Room: " + to_string(activeRoom.getRoomId())));
    ui->labelError->setText("You will be notified when it is your turn.");

    /*
     * Show rooms info utilizing old labels
     */
    // ### This was all tested ### //
    // Doctors ID
    ui->labelDOB->setGeometry(QRect(100, 180, 400, 31));
    ui->labelDOB->setText(QString::fromStdString("Room Doctor's ID: " + activeRoom.getDocId()));
    // Doctors Name
    ui->labelName->setGeometry(QRect(100, 130, 400, 31));
    ui->labelName->setText(QString::fromStdString("Room Doctor: " + activeRoom.getDocName()));
    // Rooms status
    ui->labelSevere->setGeometry(QRect(100, 230, 400, 31));
    ui->labelSevere->setText(QString::fromStdString("Room Status: Occupied"));

    // Enable check in button
    ui->pushButton_3->setDisabled(false);
    ui->pushButton_3->setGeometry((QRect(170, 360, 201, 41)));

}


/*
 * !!! Wait for your turn button !!!
 */
void MainWindow::on_pushButton_3_clicked() {
    /*
     * SIMULATE WAITING FOR OTHER PATIENTS TURNS
     */
    while(!pQueue.empty()) {
        // ### This was thouroughly tested but tests could not be included in the code and still function ### //
        if (!activeRoom.getStatus()) {
            // release last patient
            activeRoom.releasePatient();
        }
        // Simlulate a small wait
        this_thread::sleep_for(chrono::seconds{1}); // ### This was thouroughly tested but tests could not be included in the code and still function ### //
        // check if next patient is current
        if(pQueue.checkNext().getName() == pat.getName()) {
            break;
        }
        // accept patient
        activeRoom.receivePatient(pQueue.getPatient());
    }


    ui->labelError->setText("It is your turn. Please proceed to the office.");
    QString sever = QString::fromStdString("Status: Open");
    ui->labelSevere->setText(sever);
    /*
     * Disable button and enable exit button
     */
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setGeometry((QRect(170, 420, 201, 41)));  // ### This was tested ### //
}


void MainWindow::on_pushButton_4_clicked()
{
    // allow patient into room
    activeRoom.receivePatient(pQueue.getPatient());
    close();// ### This was tested ### //
}

