//
// Created by Евгения on 04.11.2026.
//

#ifndef INC_02_11_2026_GARAGE_H
#define INC_02_11_2026_GARAGE_H


#include "Vehicle.h"
#include <vector>
#include <memory>

class Garage {
private:

    std::vector<std::unique_ptr<Vehicle>> m_vehicles;

public:
    Garage() = default;


    void loadFromFile(const std::string& filename);
    void addVehicle(std::unique_ptr<Vehicle> vehicle);
    bool removeVehicle(size_t index);


    void findByType(const std::string& type) const;
    void findByIndex(size_t index) const;
    void findByTypeAndSpeed(const std::string& type, int speed) const;

    bool editVehicle(size_t index, double newPrice, const std::string& newColor);
    void sortBySpeed();

    void showAll() const;
    size_t size() const { return m_vehicles.size(); }
};



#endif //INC_02_11_2026_GARAGE_H
