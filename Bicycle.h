//
// Created by Евгения on 02.11.2026.
//

#ifndef INC_02_11_2026_BICYCLE_H
#define INC_02_11_2026_BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle {
private:
    std::string m_bikeType;

public:
    Bicycle(double price, int maxSpeed, int year, const std::string& color, const std::string& bikeType);

    std::string bikeType() const { return m_bikeType; }
    void setBikeType(const std::string& type) { m_bikeType = type; }

    std::string getType() const override { return "Bicycle"; }
    void printInfo() const override;
    std::string serialize() const override;
};


#endif //INC_02_11_2026_BICYCLE_H
