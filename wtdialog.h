#ifndef WTDIALOG_H
#define WTDIALOG_H

#include <QDialog>

namespace Ui {
class WTDialog;
}

class WTDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WTDialog(QWidget *parent = 0);
    ~WTDialog();
    int get_id();

private:
    Ui::WTDialog *ui;
};

#endif // WTDIALOG_H
