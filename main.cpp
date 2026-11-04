#include "Garage.h"
#include "Car.h"
#include "Bicycle.h"
#include "Lorry.h"
#include <iostream>

void printMenu() {
    std::cout << "\n===== МЕНЮ ГАРАЖА =====\n"
              << "1. Завантажити автопарк з файлу\n"
              << "2. Додати новий транспорт вручну\n"
              << "3. Видалити транспорт за номером (індексом)\n"
              << "4. Пошук транспорту\n"
              << "5. Редагувати параметри (ціна, колір)\n"
              << "6. Сортувати весь гараж за швидкістю\n"
              << "7. Вивести весь список\n"
              << "0. Вихід\n"
              << "Ваш вибір: ";
}

int main() {
    Garage myGarage;
    int choice = -1;

    while (choice != 0) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                myGarage.loadFromFile("vehicles.txt");
                std::cout << "Дані успішно зчитано! Поточний гараж:\n";
                myGarage.showAll();
                break;
            }
            case 2: {
                int typeChoice;
                std::cout << "Виберіть тип (1 - Car, 2 - Bicycle, 3 - Lorry): ";
                std::cin >> typeChoice;

                double price; int speed; int year; std::string color;
                std::cout << "Введіть через пробіл (Ціна Швидкість Рік Колір): ";
                std::cin >> price >> speed >> year >> color;

                if (typeChoice == 1) {
                    int doors;
                    std::cout << "Кількість дверей: "; std::cin >> doors;
                    myGarage.addVehicle(std::make_unique<Car>(price, speed, year, color, doors));
                } else if (typeChoice == 2) {
                    std::string bType;
                    std::cout << "Тип велосипеда (напр. Спортивний): "; std::cin >> bType;
                    myGarage.addVehicle(std::make_unique<Bicycle>(price, speed, year, color, bType));
                } else if (typeChoice == 3) {
                    double cap;
                    std::cout << "Вантажопідйомність (тонн): "; std::cin >> cap;
                    myGarage.addVehicle(std::make_unique<Lorry>(price, speed, year, color, cap));
                }
                std::cout << "Транспорт додано!\n";
                break;
            }
            case 3: {
                size_t idx;
                std::cout << "Введіть номер для видалення: ";
                std::cin >> idx;
                if (myGarage.removeVehicle(idx)) {
                    std::cout << "Успішно видалено!\n";
                } else {
                    std::cout << "Помилка: невірний номер.\n";
                }
                break;
            }
            case 4: {
                int searchChoice;
                std::cout << "Шукати за: 1-Типом, 2-Номером, 3-Типом та Швидкістю: ";
                std::cin >> searchChoice;
                if (searchChoice == 1) {
                    std::string t; std::cout << "Введіть тип (Car/Bicycle/Lorry): "; std::cin >> t;
                    myGarage.findByType(t);
                } else if (searchChoice == 2) {
                    size_t idx; std::cout << "Введіть номер: "; std::cin >> idx;
                    myGarage.findByIndex(idx);
                } else if (searchChoice == 3) {
                    std::string t; int s;
                    std::cout << "Введіть тип: "; std::cin >> t;
                    std::cout << "Введіть швидкість: "; std::cin >> s;
                    myGarage.findByTypeAndSpeed(t, s);
                }
                break;
            }
            case 5: {
                size_t idx; double p; std::string c;
                std::cout << "Введіть номер об'єкта для редагування: "; std::cin >> idx;
                std::cout << "Нова ціна: "; std::cin >> p;
                std::cout << "Новий колір: "; std::cin >> c;
                if (myGarage.editVehicle(idx, p, c)) {
                    std::cout << "Дані оновлено!\n";
                } else {
                    std::cout << "Помилка: об'єкт не знайдено.\n";
                }
                break;
            }
            case 6: {
                myGarage.sortBySpeed();
                std::cout << "Гараж відсортовано за швидкістю (від найменшої)!\n";
                myGarage.showAll();
                break;
            }
            case 7: {
                myGarage.showAll();
                break;
            }
            case 0:
                std::cout << "Завершення роботи програми.\n";
                break;
            default:
                std::cout << "Неправильний вибір, спробуйте ще раз.\n";
        }
    }
    return 0;
}



