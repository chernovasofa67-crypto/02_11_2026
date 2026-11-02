//
// Created by Евгения on 02.11.2026.
//

#include "Bicycle.h"
#include "Bicycle.h"


Bicycle::Bicycle(double price, int maxSpeed, int year, const std::string& color, const std::string& bikeType)
    : Vehicle(price, maxSpeed, year, color), m_bikeType(bikeType) {}

void Bicycle::printInfo() const {
    Vehicle::printInfo();
    std::cout << " | Тип рами/велосипеда: " << m_bikeType << std::endl;
}

std::string Bicycle::serialize() const {
    return Vehicle::serialize() + " " + m_bikeType;
}
