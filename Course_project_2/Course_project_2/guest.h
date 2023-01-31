#pragma once

#include <iostream>
#include <string>


struct Guest_data {
    std::string id;
    std::string fio;
    int         year_of_birth;
    std::string address;
    std::string purpose_of_arrival;
};

Guest_data AddGuest();
void FillGuestData(Guest_data* guest);
std::string EnterId();
std::string EnterFio();
int EnterYearOfBirth();
std::string EnterAddress();
std::string EnterPurposeOfArrival();
void PrintGuestData(Guest_data* guest);
void PrintFioAndId(Guest_data* guest);