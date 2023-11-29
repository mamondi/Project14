#include <iostream>
#include <Windows.h>

using namespace std;

const int MAX_CARS = 3;

struct Car {
    double length;
    double groundClearance;
    double engineVolume;
    int enginePower;
    double wheelDiameter;
    string color;
    string transmission;
};

void setCarValues(Car& car, double length, double groundClearance, double engineVolume,
    int enginePower, double wheelDiameter, const string& color, const string& transmission) {
    car.length = length;
    car.groundClearance = groundClearance;
    car.engineVolume = engineVolume;
    car.enginePower = enginePower;
    car.wheelDiameter = wheelDiameter;
    car.color = color;
    car.transmission = transmission;
}

void displayCar(const Car& car) {
    cout << "Довжина: " << car.length << " м" << endl;
    cout << "Кліренс: " << car.groundClearance << " м" << endl;
    cout << "Об'єм двигуна: " << car.engineVolume << " л" << endl;
    cout << "Потужність двигуна: " << car.enginePower << " к.с." << endl;
    cout << "Діаметр коліс: " << car.wheelDiameter << " дюймів" << endl;
    cout << "Колір: " << car.color << endl;
    cout << "Тип коробки передач: " << car.transmission << endl;
}

void searchCars(const Car cars[], int size, double minEnginePower, double maxWheelDiameter) {
    cout << "Результати пошуку:" << endl;
    bool found = false;
    for (int i = 0; i < size; ++i) {
        const Car& car = cars[i];
        if (car.enginePower >= minEnginePower && car.wheelDiameter <= maxWheelDiameter) {
            displayCar(car);
            cout << "-----------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Не знайдено автомобілів за вказаними параметрами." << endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Car cars[MAX_CARS];

    setCarValues(cars[0], 4.5, 0.15, 2.0, 150, 17.0, "Червоний", "Автоматична");
    setCarValues(cars[1], 4.2, 0.12, 1.5, 120, 16.0, "Синій", "Механічна");
    setCarValues(cars[2], 5.0, 0.20, 2.5, 200, 18.0, "Чорний", "Автоматична");

    for (int i = 0; i < MAX_CARS; ++i) {
        displayCar(cars[i]);
        cout << "-----------------------------" << endl;
    }

    double minPower = 130.0;
    double maxWheel = 17.5;
    searchCars(cars, MAX_CARS, minPower, maxWheel);

    return 0;
}