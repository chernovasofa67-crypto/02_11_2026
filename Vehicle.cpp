//
// Created by Евгения on 02.11.2026.
//

#include "Vehicle.h"

Vehicle::Vehicle(double price, int maxSpeed, int year, const std::string& color)
    : m_price(price), m_maxSpeed(maxSpeed), m_year(year), m_color(color) {}

void Vehicle::printInfo() const {
    std::cout << "Тип: " << getType()
              << " | Ціна: $" << m_price
              << " | Макс. швидкість: " << m_maxSpeed << " км/год"
              << " | Рік: " << m_year
              << " | Колір: " << m_color;
}

std::string Vehicle::serialize() const {
    return getType() + " " + std::to_string(m_price) + " " +
           std::to_string(m_maxSpeed) + " " + std::to_string(m_year) + " " + m_color;
}
