#include "patient.h"

#include <QDebug>
Patient::Patient()
{

}

Patient::Patient(int id, int degree, QTime arrive, int expense)
    :id(id), degree(degree), arrive(arrive), expense(expense)
{

}

void Patient::generate_data()
{
    std::default_random_engine e(rand() * time(NULL));
    // 按照均值为12，方差为4的正太分布模拟小时（用数字模拟时间）
    std::normal_distribution<double> hour_distribution(12, 4);
    // 按照均值为30，方差为100的正太分布模拟分和秒（用数字模拟时间）
    std::normal_distribution<double> min_sec_distribution(30, 100);
    // 按照均值为1，方差为1的正太分布模拟严重程度
    std::normal_distribution<double> degree_distribution(4, 4);
    std::normal_distribution<double> expense_distribution(2, 1);

    int hour, min, sec, degree, expense;
    do{
        hour = std::lround(hour_distribution(e));
    } while(hour > 18 || hour < 6);
    do{
        min = std::lround(min_sec_distribution(e));
    } while(min >= 60 || min < 0);
    do{
        sec = std::lround(min_sec_distribution(e));
    } while(sec >= 60 || sec < 0);
    do{
        degree = std::lround(degree_distribution(e));
    } while(degree > 10 || degree < 1);
    do{
        expense = std::lround(expense_distribution(e));
    } while(expense > 3 || expense < 0);


    // 将时、分、秒拼接成字符串
    std::string time = std::to_string(hour) + std::string(":")
                        + std::to_string(min) + std::string(":")
                        + std::to_string(sec);
    this->arrive = QTime::fromString(QString::fromStdString(time), QString("h:m:s"));
    this->degree = degree;
    this->expense = (degree - 1) * 3 + expense;
}
