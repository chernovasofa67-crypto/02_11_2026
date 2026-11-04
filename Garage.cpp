//
// Created by Евгения on 04.11.2026.
//

#include "Garage.h"
#include "Car.h"
#include "Bicycle.h"
#include "Lorry.h"
#include <fstream>
#include <algorithm>

void Garage::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл " << filename << std::endl;
        return;
    }

    m_vehicles.clear();
    std::string type, color;
    double price;
    int maxSpeed, year;

    while (file >> type >> price >> maxSpeed >> year >> color) {
        if (type == "Car") {
            int doors;
            file >> doors;
            m_vehicles.push_back(std::make_unique<Car>(price, maxSpeed, year, color, doors));
        } else if (type == "Bicycle") {
            std::string bType;
            file >> bType;
            m_vehicles.push_back(std::make_unique<Bicycle>(price, maxSpeed, year, color, bType));
        } else if (type == "Lorry") {
            double capacity;
            file >> capacity;
            m_vehicles.push_back(std::make_unique<Lorry>(price, maxSpeed, year, color, capacity));
        }
    }
    file.close();
}

void Garage::addVehicle(std::unique_ptr<Vehicle> vehicle) {
    m_vehicles.push_back(std::move(vehicle));
}

bool Garage::removeVehicle(size_t index) {
    if (index >= m_vehicles.size()) return false;
    m_vehicles.erase(m_vehicles.begin() + index);
    return true;
}

void Garage::findByType(const std::string& type) const {
    bool found = false;
    for (size_t i = 0; i < m_vehicles.size(); ++i) {
        if (m_vehicles[i]->getType() == type) {
            std::cout << "[" << i << "] ";
            m_vehicles[i]->printInfo();
            found = true;
        }
    }
    if (!found) std::cout << "Транспорт типу " << type << " не знайдено.\n";
}

void Garage::findByIndex(size_t index) const {
    if (index < m_vehicles.size()) {
        std::cout << "[" << index << "] ";
        m_vehicles[index]->printInfo();
    } else {
        std::cout << "Транспорту за номером " << index << " не існує.\n";
    }
}


void Garage::findByTypeAndSpeed(const std::string& type, int speed) const {
    bool found = false;
    for (size_t i = 0; i < m_vehicles.size(); ++i) {
        if (m_vehicles[i]->getType() == type && m_vehicles[i]->maxSpeed() == speed) {
            std::cout << "[" << i << "] ";
            m_vehicles[i]->printInfo();
            found = true;
        }
    }
    if (!found) std::cout << "Транспорт із такими параметрами не знайдено.\n";
}

bool Garage::editVehicle(size_t index, double newPrice, const std::string& newColor) {
    if (index >= m_vehicles.size()) return false;
    m_vehicles[index]->setPrice(newPrice);
    m_vehicles[index]->setColor(newColor);
    return true;
}

void Garage::sortBySpeed() {
    std::sort(m_vehicles.begin(), m_vehicles.end(), [](const auto& a, const auto& b) {
        return a->maxSpeed() < b->maxSpeed();
    });
}

void Garage::showAll() const {
    if (m_vehicles.empty()) {
        std::cout << "Гараж порожній.\n";
        return;
    }
    for (size_t i = 0; i < m_vehicles.size(); ++i) {
        std::cout << "[" << i << "] ";
        m_vehicles[i]->printInfo();
    }
}
