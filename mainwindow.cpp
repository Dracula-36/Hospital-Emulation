#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Hospital System  (PriorityQueue Based on Heap)");

    QImage *img = new QImage;
    img->load("/home/dracula/Documents/IT_Study/data\ structure/final/Hospital/hospital.jpg");
    ui->picture->setPixmap(QPixmap::fromImage(* img));

    table = new QStandardItemModel(100, 4);
    ui->tableView->setVisible(0);

    connect(ui->actionRandom_Generate, SIGNAL(triggered()), this,  SLOT(random()));
    connect(ui->actionInput, SIGNAL(triggered()), this,  SLOT(input()));
    connect(ui->actionDelete, SIGNAL(triggered()), this,  SLOT(delete_min()));
    connect(ui->actionClear, SIGNAL(triggered()), this,  SLOT(clear()));
    connect(ui->actionIs_Full, SIGNAL(triggered()), this,  SLOT(full()));
    connect(ui->actionIs_Empty, SIGNAL(triggered()), this,  SLOT(empty()));
    connect(ui->actionOne_Wait_Time, SIGNAL(triggered()), this,  SLOT(one_wt()));
    connect(ui->actionAverage_Wait_Time, SIGNAL(triggered()), this,  SLOT(average_wt()));
    connect(ui->actionLongest_Wait_Time, SIGNAL(triggered()), this,  SLOT(longest_wt()));
    connect(ui->actionAbout_Program, SIGNAL(triggered()), this,  SLOT(about_program()));
    connect(ui->actionAbout_me, SIGNAL(triggered()), this,  SLOT(about_me()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generate()
{
    Patient data;
    data.generate_data();
    data.id = patients.size() + 1;
    patients.insert(data);
}

void MainWindow::random()
{
    GenerateDialog dialog;
    if (dialog.exec() == GenerateDialog::Accepted) {
        int amount;
        amount = dialog.get_amount();
        for (int i = 0; i < amount; i++)
        {
            generate();
        }
        display_table();
    }
}

void MainWindow::input()
{
    InputDialog dialog;
    if (dialog.exec() == InputDialog::Accepted) {
        Patient data = dialog.get_input();
        patients.insert(data);
        display_table();
    }
}

void MainWindow::delete_min()
{
    msgBox = new QMessageBox();
    if (patients.size() > 0)
    {
        patients.delete_elem();
        display_table();
        msgBox->setWindowTitle("Successful");
        msgBox->setText("    The first patient's record is deleted successfully ! ");
    }
    else
    {
        msgBox->setWindowTitle("Failed");
        msgBox->setText("    There are no records for patients ! ");
    }
    QFont font;
    font.setPointSize(18);
    msgBox->setFont(font);
    msgBox->exec();
}

void MainWindow::clear()
{
    msgBox = new QMessageBox();
    if (patients.size() > 0)
    {
        patients.list_clear();
        display_table();
        msgBox->setWindowTitle("Successful");
        msgBox->setText("    All patients' record are deleted successfully ! ");
    }
    else
    {
        msgBox->setWindowTitle("Failed");
        msgBox->setText("    There are no records for patients ! ");
    }
    QFont font;
    font.setPointSize(18);
    msgBox->setFont(font);
    msgBox->exec();
}

void MainWindow::full()
{
    msgBox = new QMessageBox();
    msgBox->setWindowTitle("Inquire Result");
    if (patients.full())
        msgBox->setText("    The PriorityQueue used to store patients' records is full ! ");
    else
        msgBox->setText("    The PriorityQueue used to store patients' records is not full ! ");
    QFont font;
    font.setPointSize(18);
    msgBox->setFont(font);
    msgBox->exec();
}

void MainWindow::empty()
{
    msgBox = new QMessageBox();
    msgBox->setWindowTitle("Inquire Result");
    if (patients.empty())
        msgBox->setText("    The PriorityQueue used to store patients' records is empty ! ");
    else
        msgBox->setText("    The PriorityQueue used to store patients' records is not empty ! ");
    QFont font;
    font.setPointSize(18);
    msgBox->setFont(font);
    msgBox->exec();
}

void MainWindow::one_wt()
{
    int id;
    WTDialog dialog;
    if (dialog.exec() == WTDialog::Accepted)
        id = dialog.get_id();
    msgBox = new QMessageBox();
    msgBox->setWindowTitle("Statistics Result");

    Patient data;
    PriorityQueue<Patient> temp = PriorityQueue<Patient>(patients);
    QTime cur_time = temp.top().arrive;
    msgBox->setText(QString("    No patients whose id is %0 ! ").arg(id));
    for (int i = 0; i < patients.size(); i++)
    {
        data = temp.top();
        if (data.id == id)
            msgBox->setText(QString("    The patient whose id is %0 ").arg(id)
                          + QString("waits for %0 minutes ! ").arg(data.arrive.secsTo(cur_time) / 60));
        temp.delete_elem();
        if (cur_time.addSecs(data.expense * 60) > temp.top().arrive)
            cur_time = cur_time.addSecs(data.expense * 60);
        else
            cur_time = temp.top().arrive;
    }
    QFont font;
    font.setPointSize(18);
    msgBox->setFont(font);
    msgBox->exec();
}

void MainWindow::average_wt()
{
    msgBox = new QMessageBox();
    msgBox->setWindowTitle("Statistics Result");

    Patient data;
    PriorityQueue<Patient> temp = PriorityQueue<Patient>(patients);
    QTime cur_time = temp.top().arrive;
    int wait_time = 0;
    int degree_wt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int degree_size[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    QString output;
    for (int i = 0; i < patients.size(); i++)
    {
        data = temp.top();
        wait_time += data.arrive.secsTo(cur_time) / 60;
        degree_wt[data.degree - 1] += data.arrive.secsTo(cur_time) / 60;
        degree_size[data.degree - 1] += 1;
        temp.delete_elem();
        if (cur_time.addSecs(data.expense * 60) > temp.top().arrive)
            cur_time = cur_time.addSecs(data.expense * 60);
        else
            cur_time = temp.top().arrive;
    }
    if (patients.size() == 0)
        output = QString("    There are no patients' records now !\n");
    else
        output = QString("    There are %0 patients totally, they wait for %1 minutes for average !\n")
                .arg(patients.size()).arg((float)wait_time / patients.size());
    for (int i = 0; i < 10; i++)
    {
        if (degree_size[i] == 0)
            output += QString("    There are no Degree %0 patients' records now !\n").arg(i + 1);
        else
            output += QString("    There are %0 Degree %1's patients , they wait for %2 minutes for average !\n")
                    .arg(degree_size[i]).arg(i + 1).arg((float)degree_wt[i] / degree_size[i]);
    }
    msgBox->setText(output);
    QFont font;
    font.setPointSize(18);
    msgBox->setFont(font);
    msgBox->exec();
}

void MainWindow::longest_wt()
{
    msgBox = new QMessageBox();
    msgBox->setWindowTitle("Statistics Result");

    Patient data;
    PriorityQueue<Patient> temp = PriorityQueue<Patient>(patients);
    QTime cur_time = temp.top().arrive;
    int wait_time = 0;
    int id = 1;
    for (int i = 0; i < patients.size(); i++)
    {
        data = temp.top();
        if (wait_time < data.arrive.secsTo(cur_time) / 60)
        {
            wait_time = data.arrive.secsTo(cur_time) / 60;
            id = data.id;
        }
        temp.delete_elem();
        if (cur_time.addSecs(data.expense * 60) > temp.top().arrive)
            cur_time = cur_time.addSecs(data.expense * 60);
        else
            cur_time = temp.top().arrive;
    }
    if (patients.size() != 0)
        msgBox->setText(QString("    The patient whose id is %0 ").arg(id) +
                        QString("waits for the longest time: %0 minutes ! ").arg(wait_time));
    else
        msgBox->setText("    There are no records for patients ! ");
    QFont font;
    font.setPointSize(18);
    msgBox->setFont(font);
    msgBox->exec();
}

void MainWindow::about_program()
{
    msgBox = new QMessageBox();
    msgBox->setWindowTitle("About Program");
    msgBox->setText(QString("    The program is for my data structure curriculum design.\n"
                            "    It's an application of Priority Queue based on Heap realized by sequence list.\n"
                            "    This one which is named as Hospital System is used to simulate registering in hospital.\n"
                            "    It's really easy to oprerate it just by click the option in the menu bar.\n"
                            "    There may be still some errors herer, and it won't be used in any commercial purpose!"));
    QFont font;
    font.setPointSize(18);
    msgBox->setFont(font);
    msgBox->exec();
}

void MainWindow::about_me()
{
    msgBox = new QMessageBox();
    msgBox->setWindowTitle("About Me");
    msgBox->setText(QString("    Author:  Guanyu Li\n"
                            "     Email :  lcliguanyu@163.com\n"
                            "    Phone :  15827463286\n"
                            "     Addr  : HUST, Wuhan, Hubei Province\n"
                            "    Github:  https://github.com/Dracula-36"));
    QFont font;
    font.setPointSize(18);
    msgBox->setFont(font);
    msgBox->exec();
}

void MainWindow::display_table()
{
    table->clear();

    table->setRowCount(patients.size());
    table->setColumnCount(4);
    ui->tableView->setVisible(1);

    table->setHeaderData(0, Qt::Horizontal, "ID");
    table->setHeaderData(1, Qt::Horizontal, "Degree");
    table->setHeaderData(2, Qt::Horizontal, "ArriveTime");
    table->setHeaderData(3, Qt::Horizontal, "Expense");
    ui->tableView->setModel(table);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnWidth(0, 90);
    ui->tableView->setColumnWidth(1, 90);
    ui->tableView->setColumnWidth(2, 230);
    ui->tableView->setColumnWidth(3, 160);

    PriorityQueue<Patient> displays = PriorityQueue<Patient>(patients);
    Patient data;
    QStandardItem *item;
    for (int i = 0; i < patients.size(); i++)
    {
        data = displays.top();
        displays.delete_elem();
        item = new QStandardItem(QString("%0").arg(data.id));
        item->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 0, item);
        item = new QStandardItem(QString("%0").arg(data.degree));
        item->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 1, item);
        item = new QStandardItem(QString("%0").arg(data.arrive.toString()));
        item->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 2, item);
        item = new QStandardItem(QString("%0 minutes").arg(data.expense));
        item->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 3, item);
    }

}
