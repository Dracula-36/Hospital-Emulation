#ifndef GENERATEDIALOG_H
#define GENERATEDIALOG_H

#include <QDialog>

namespace Ui {
class GenerateDialog;
}

class GenerateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GenerateDialog(QWidget *parent = 0);
    ~GenerateDialog();
    int get_amount();

private:
    Ui::GenerateDialog *ui;
};

#endif // GENERATEDIALOG_H
