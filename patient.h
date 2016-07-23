#ifndef PATIENT_H
#define PATIENT_H

#include <queue>
#include <QTime>
#include <random>
#include <stdlib.h>

class Patient
{
public:
    Patient();
    Patient(int id, int degree, QTime arrive, int expense);

    void generate_data();

    static bool greater(Patient const p1, Patient const p2)
    {
        if(p1.arrive.secsTo(p2.arrive) > p1.expense * 60)
            return true;
        else
            return (p1.expense - p2.expense) * 60 * 0.7 > p2.arrive.secsTo(p1.arrive) * 0.3;
    }

    static bool later(Patient const p1, Patient const p2)
    {
        return p1.arrive.secsTo(p2.arrive) > 0;
    }

    int id;         //病人的序号
    int degree;     //病人的病急程度
    QTime arrive;   //病人的到达时间
    int expense;    //病人需要的就诊时间
};

#endif // PATIENT_H
