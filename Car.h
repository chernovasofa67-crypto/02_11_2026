//
// Created by Евгения on 02.11.2026.
//

#ifndef INC_02_11_2026_CAR_H
#define INC_02_11_2026_CAR_H


#include "Vehicle.h"

class Car : public Vehicle {
protected:
    int m_doorsCount;

public:
    Car(double price, int maxSpeed, int year, const std::string& color, int doorsCount);

    int doorsCount() const { return m_doorsCount; }
    void setDoorsCount(int count) { m_doorsCount = count; }

    std::string getType() const override { return "Car"; }
    void printInfo() const override;
    std::string serialize() const override;
};

#endif //INC_02_11_2026_CAR_H
