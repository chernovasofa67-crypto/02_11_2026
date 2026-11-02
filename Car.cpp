//
// Created by Евгения on 02.11.2026.
//

#include "Car.h"

Car::Car(double price, int maxSpeed, int year, const std::string& color, int doorsCount)
    : Vehicle(price, maxSpeed, year, color), m_doorsCount(doorsCount) {}

void Car::printInfo() const {
    Vehicle::printInfo();
    std::cout << " | К-сть дверей: " << m_doorsCount << std::endl;
}

std::string Car::serialize() const {
    return Vehicle::serialize() + " " + std::to_string(m_doorsCount);
}
