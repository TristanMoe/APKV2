#include <iostream>
#include "boost/signals2.hpp"
#include "boost/bind.hpp"
#include "boost/ref.hpp"
#include "headers/SensorPrinter.h"
#include "headers/MedianCombiner.h"

#pragma region Boost::signal Exercise
void printOutSensor(std::string& sensorName, double sensorValue)
{
    std::cout << "Sensorname: " << sensorName << std::endl;
    std::cout << "Sensorvalue: " << sensorValue << std::endl;
}

double getAdditionOfValues(double value1, double value2, double value3)
{
    return value1 + value2 + value3;
}

double getSubtractionOfValues(double value1, double value2, double value3)
{
    return value1 - value2 - value3;
}

double getMultiplicationOfValues(double value1, double value2, double value3)
{
    return value1 * value2 * value3;
}
#pragma endregion

int main() {
#pragma region Exercise 1 Boost::signal
    std::cout << "===============================================" << std::endl;
    std::cout << "Boost Signal Demo, Exercise 1" << std::endl;

    void(*printFunctor)(std::string&, double) = &printOutSensor;
    auto sP = new SensorPrinter();

    boost::signals2::signal<void(std::string&, double)> sig1;
    sig1.connect(&printOutSensor); //Free function
    sig1.connect(*printFunctor); // Functor
    sig1.connect([](std::string& sensorName, double sensorValue){std::cout << "Sensorname: " << sensorName << std::endl;
        std::cout << "Sensorvalue: " << sensorValue << std::endl;}); // Lambda
    sig1.connect(boost::bind(&SensorPrinter::printSensorData, boost::ref(sP), _1, _2));

    std::string * sPtr = new std::string("Sp542E450");
    sig1(*sPtr, 200);

    delete sPtr;
    delete sP;
#pragma endregion

#pragma region Exercise 2 Boost::signal
    std::cout << "===============================================" << std::endl;
    std::cout << "Boost Signal Demo, Exercise 2" << std::endl;

    boost::signals2::signal<double (double, double, double), MedianCombiner<double>> sig2;
    sig2.connect(&getAdditionOfValues);
    sig2.connect(&getSubtractionOfValues);
    sig2.connect(&getMultiplicationOfValues);
    std::cout << "Median value: " << sig2(3, 3, 3) << std::endl;

#pragma endregion

    std::cout << "===============================================" << std::endl;
    return 0;
}
