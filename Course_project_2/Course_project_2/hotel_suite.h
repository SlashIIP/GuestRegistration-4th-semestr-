#pragma once

#include <iostream>
#include <string>

struct Suite_data {
    std::string suite_number;
    int number_of_beds;
    int number_of_rooms;
    bool bathroom;
    std::string equipment;
};


Suite_data AddSuite();
void FillSuiteData(Suite_data* suite);
std::string EnterSuiteNumber();
int EnterNumOfBeds();
int EnterNumOfRooms();
bool EnterBathroom();
std::string EnterEquipment();
void PrintSuiteData(Suite_data* suite);