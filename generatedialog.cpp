#include "generatedialog.h"
#include "ui_generatedialog.h"

GenerateDialog::GenerateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GenerateDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Random Generate");

    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(999);

    connect(ui->okButton, SIGNAL(released()), this, SLOT(accept()));
    connect(ui->cancelButton, SIGNAL(released()), this, SLOT(reject()));
}

GenerateDialog::~GenerateDialog()
{
    delete ui;
}

int GenerateDialog::get_amount()
{
    return ui->spinBox->value();
}
