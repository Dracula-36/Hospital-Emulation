#include "wtdialog.h"
#include "ui_wtdialog.h"

WTDialog::WTDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WTDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("One WaitTime");

    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(999);

    connect(ui->okButton, SIGNAL(released()), this, SLOT(accept()));
    connect(ui->cancelButton, SIGNAL(released()), this, SLOT(reject()));
}

WTDialog::~WTDialog()
{
    delete ui;
}

int WTDialog::get_id()
{
    return ui->spinBox->value();
}
