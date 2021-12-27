//
//  Car.hpp
//  ObjectsAndClasses
//
//  Created by Cyan on 2021/12/16.
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
//Car::Car();
//Car::Car(float amount);
//void Car::FillFuel(float amount);
//void Car::Accelerate();
//void Car::Brake();
//void Car::AddPassengers(int count);
//void Car::Dashboard();
//Car::~Car();

struct Car {
private:
    float fuel{ 0 };
    float speed{ 0 };
    int passengers{ 0 };
    int arr[5] = { 1,2,3 };
    char *p{}; // null pointer
    static int totalCount;  //static member: declared inside, defined outside the class
public:
    Car();
    Car(float amount);
    Car(float amount, int pass);
    void FillFuel(float amount);
    void Accelerate();
    void Brake();
    void AddPassengers(int count);
    void Dashboard() const;
    static void ShowCount();
    ~Car();
};

#endif /* Car_hpp */
