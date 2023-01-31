#include "check-in_check-out.h"
#include "guest.h"
#include "hotel_suite.h"

Check_info AddCheckInfo() {
    Check_info check_data;
    FillCheckinData(&check_data);
    return check_data;
}

void FillCheckinData(Check_info* check_data) {
    check_data->id = CheckId();
    check_data->suite_number = CheckSuiteNumber();
    check_data->checkin_date = EnterCheckinDate();
    check_data->checkout_date = "0";
}

void FillCheckoutData(Check_info* check_data) {
    
}

std::string CheckId() {
    std::string id = EnterId();
    return id;
}

std::string CheckSuiteNumber()
{
    std::string suite_num = EnterSuiteNumber();
    return suite_num;
}

std::string EnterCheckinDate()
{
    std::string input;
    while (true) {
        std::cout << "Ââåäèòå äàòó çàñåëåíèÿ (ÄÄ.ÌÌ.ÃÃÃÃ)\n";
        std::getline(std::cin, input);
        
        if (input.size() == 10) {

            std::string s_day = input.substr(0, 2);
            int day = std::stoi(s_day);
            std::string s_month = input.substr(3, 2);
            int month = std::stoi(s_month);
            std::string s_year = input.substr(6, 4);
            int year = std::stoi(s_year);

            if (input[2] == '.' && input[5] == '.')
                return input;
        }
    }
}

std::string EnterCheckoutDate() {
    std::string input;
    while (true) {
        std::cout << "Ââåäèòå äàòó âûñåëåíèÿ (ÄÄ.ÌÌ.ÃÃÃÃ)\n";
        std::getline(std::cin, input);

        if (input.size() == 10) {

            std::string s_day = input.substr(0, 2);
            int day = std::stoi(s_day);
            std::string s_month = input.substr(3, 2);
            int month = std::stoi(s_month);
            std::string s_year = input.substr(6, 4);
            int year = std::stoi(s_year);

            if (input[2] == '.' && input[5] == '.')
                return input;
        }
    }
}