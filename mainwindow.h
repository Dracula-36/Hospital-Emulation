#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <priority_queue.h>
#include <patient.h>
#include <QMessageBox>
#include <QImage>
#include <QStandardItemModel>

#include "inputdialog.h"
#include "generatedialog.h"
#include "wtdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void generate();
    void random();
    void input();
    void delete_min();
    void clear();
    void full();
    void empty();
    void one_wt();
    void average_wt();
    void longest_wt();
    void about_program();
    void about_me();
    void display_table();

private:
    Ui::MainWindow *ui;
    QMessageBox* msgBox;
    QStandardItemModel* table;
    PriorityQueue<Patient> patients = PriorityQueue<Patient>(Patient::greater);
};

#endif // MAINWINDOW_H
