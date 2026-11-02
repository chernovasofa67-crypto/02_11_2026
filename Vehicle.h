//
// Created by Евгения on 02.11.2026.
//

#ifndef INC_02_11_2026_VEHICLE_H
#define INC_02_11_2026_VEHICLE_H


#include <string>
#include <iostream>

class Vehicle {
protected:
    double m_price;
    int m_maxSpeed;
    int m_year;
    std::string m_color;

public:
    Vehicle(double price, int maxSpeed, int year, const std::string& color);
    virtual ~Vehicle() = default;


    double price() const { return m_price; }
    void setPrice(double price) { m_price = price; }

    int maxSpeed() const { return m_maxSpeed; }
    void setMaxSpeed(int speed) { m_maxSpeed = speed; }

    int year() const { return m_year; }
    std::string color() const { return m_color; }
    void setColor(const std::string& color) { m_color = color; }

    virtual std::string getType() const = 0;
    virtual void printInfo() const;
    virtual std::string serialize() const;
};


#endif //INC_02_11_2026_VEHICLE_H
