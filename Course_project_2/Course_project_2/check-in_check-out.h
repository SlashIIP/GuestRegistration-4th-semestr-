#pragma once

#include <iostream>

struct Check_info {
    std::string id;
    std::string suite_number;
    std::string checkin_date;
    std::string checkout_date;
};


Check_info AddCheckInfo();
void FillCheckinData(Check_info* check_data);
void FillCheckoutData(Check_info* check_data);
std::string CheckId();
std::string CheckSuiteNumber();
std::string EnterCheckinDate();
std::string EnterCheckoutDate();
