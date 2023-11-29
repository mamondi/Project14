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
    cout << "�������: " << car.length << " �" << endl;
    cout << "������: " << car.groundClearance << " �" << endl;
    cout << "��'�� �������: " << car.engineVolume << " �" << endl;
    cout << "��������� �������: " << car.enginePower << " �.�." << endl;
    cout << "ĳ����� ����: " << car.wheelDiameter << " �����" << endl;
    cout << "����: " << car.color << endl;
    cout << "��� ������� �������: " << car.transmission << endl;
}

void searchCars(const Car cars[], int size, double minEnginePower, double maxWheelDiameter) {
    cout << "���������� ������:" << endl;
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
        cout << "�� �������� ��������� �� ��������� �����������." << endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Car cars[MAX_CARS];

    setCarValues(cars[0], 4.5, 0.15, 2.0, 150, 17.0, "��������", "�����������");
    setCarValues(cars[1], 4.2, 0.12, 1.5, 120, 16.0, "����", "��������");
    setCarValues(cars[2], 5.0, 0.20, 2.5, 200, 18.0, "������", "�����������");

    for (int i = 0; i < MAX_CARS; ++i) {
        displayCar(cars[i]);
        cout << "-----------------------------" << endl;
    }

    double minPower = 130.0;
    double maxWheel = 17.5;
    searchCars(cars, MAX_CARS, minPower, maxWheel);

    return 0;
}