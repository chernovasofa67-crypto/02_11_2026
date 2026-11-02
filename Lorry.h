//
// Created by Евгения on 02.11.2026.
//

#ifndef INC_02_11_2026_LORRY_H
#define INC_02_11_2026_LORRY_H



#include "Vehicle.h"

class Lorry : public Vehicle {
private:
    double m_loadCapacity;

public:
    Lorry(double price, int maxSpeed, int year, const std::string& color, double loadCapacity);

    double loadCapacity() const { return m_loadCapacity; }
    void setLoadCapacity(double capacity) { m_loadCapacity = capacity; }

    std::string getType() const override { return "Lorry"; }
    void printInfo() const override;
    std::string serialize() const override;
};




#endif //INC_02_11_2026_LORRY_H
