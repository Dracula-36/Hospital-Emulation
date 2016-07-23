#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Patient Data Input");

    ui->spinBox_ID->setMinimum(1);
    ui->spinBox_ID->setMaximum(999);

    ui->spinBox_Degree->setMinimum(1);
    ui->spinBox_Degree->setMaximum(10);

    ui->spinBox_Expense->setMinimum(0);
    ui->spinBox_Expense->setMaximum(300);
    ui->spinBox_Expense->setSuffix(" minutes");

    connect(ui->okButton, SIGNAL(released()), this, SLOT(accept()));
    connect(ui->cancelButton, SIGNAL(released()), this, SLOT(reject()));

}

InputDialog::~InputDialog()
{
    delete ui;
}

Patient InputDialog::get_input()
{
    Patient data(ui->spinBox_ID->value(), ui->spinBox_Degree->value(),
                 ui->timeEdit->time(), ui->spinBox_Expense->value());
    return data;
}
