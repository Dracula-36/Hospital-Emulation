#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <patient.h>

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = 0);
    ~InputDialog();
    Patient get_input();

private:
    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
