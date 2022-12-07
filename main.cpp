/**************************************************************
 * Name        : DataStructs_Patient_Project
 * Author      : Elijah Edlund
 * Created     : 12/05/2022
 * Course      : CIS 161 – C++
 * Version     : 1.0
 * OS          : Windows 11
 * Copyright   : This is my own original work based on
 *               specifications issued by our instructor
 * Description : This is a mock-up of a patient check in program.
 *               You enter your patient info and are set into a priority
 *               queue based of severity of visit. In the real world implementation
 *               of this program the data would be handled on a server. This is
 *               not possible given the circumstances so other patient data is provided
 *               during runtime as well as a simulated waiting stage.
 * Academic Honesty: I attest that this is my original work.
 * I have not used unauthorized source code, either modified or
 * unmodified. I have not given other fellow student(s) access to
 * my program.
 ***************************************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
