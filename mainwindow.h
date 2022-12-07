/***************************************************************
 * Name        : mainwindow
 * Author      : Elijah Edlund
 * Created     : 12/05/2022
 ***************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <regex>
#include <chrono>
#include <thread>
#include <cctype>
#include "Patient.h"
#include "PatientQueue.h"
#include "Room.h"
using namespace std;

QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
QT_END_NAMESPACE

    class MainWindow : public QMainWindow
{
    Q_OBJECT

        public:
                 MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    /**************************************************************
     * Name: on_pushButton_clicked
     * Description: Okay button is clicked
     ***************************************************************/
    void on_pushButton_clicked();

    /**************************************************************
     * Name: on_pushButton_2_clicked
     * Description: Next button is clicked
     ***************************************************************/
    void on_pushButton_2_clicked();

    /**************************************************************
     * Name: on_pushButton_3_clicked
     * Description: Wait for you turn button is clicked
     ***************************************************************/
    void on_pushButton_3_clicked();

    /**************************************************************
     * Name: on_pushButton_4_clicked
     * Description: Final exit and check in button is clicked
     ***************************************************************/
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
