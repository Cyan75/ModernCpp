//
//  Car.cpp
//  ObjectsAndClasses
//
//  Created by Cyan on 2021/12/16.
//

#include "Car.hpp"
#include <iostream>

int Car::totalCount = 0;// static member must be defined outside the class

Car::Car() {
    ++totalCount;
    //no initialisation occurs ⟶ see data member initialisations in the header file
    fuel = 0;
    speed = 0;
    passengers = 0;
}
Car::Car(float amount) {
    fuel = amount;
    ++totalCount;
}
void Car::FillFuel(float amount) {
    fuel = amount;
}

void Car::Accelerate() {
    this->speed++;
    this->fuel -= 0.5f;
}

void Car::Brake() {
    speed = 0;
}

void Car::AddPassengers(int passengers) {
    this->passengers = passengers;
}

void Car::Dashboard() const{
//    fuel++; a const member function cannot modify member variable
    std::cout << "Fuel level : " << fuel << std::endl;
    std::cout << "Speed : " << speed << std::endl;
    std::cout << "Passengers : " << passengers << std::endl;
}
void Car::ShowCount(){
    std::cout << "Total Cars : " << totalCount << std::endl;
}

Car::~Car() {
    --totalCount;
}
