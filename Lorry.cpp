//
// Created by Евгения on 02.11.2026.
//

#include "Lorry.h"


Lorry::Lorry(double price, int maxSpeed, int year, const std::string& color, double loadCapacity)
    : Vehicle(price, maxSpeed, year, color), m_loadCapacity(loadCapacity) {}

void Lorry::printInfo() const {
    Vehicle::printInfo();
    std::cout << " | Вантажопідйомність: " << m_loadCapacity << " т." << std::endl;
}

std::string Lorry::serialize() const {
    return Vehicle::serialize() + " " + std::to_string(m_loadCapacity);
}
