#include "hotel_suite.h"

Suite_data AddSuite() {
    Suite_data new_suite;
    FillSuiteData(&new_suite);
    return new_suite;
}

void FillSuiteData(Suite_data* suite) {
    suite->suite_number = EnterSuiteNumber();
    suite->number_of_beds = EnterNumOfBeds();
    suite->number_of_rooms = EnterNumOfRooms();
    suite->bathroom = EnterBathroom();
    suite->equipment = EnterEquipment();
}

std::string EnterSuiteNumber() {
    std::string input;
    bool input_if_fine = false;
    std::cout << "Введите номер гостиничного номера в формате ANNN,\n"
        << "где A – буква, обозначающая тип номера(Л – люкс, П – полулюкс, О – одноместный, М – многоместный);\n"
        << "NNN – порядковый номер(цифры)\n";
    while (true) {
        std::cout << "Введите номер гостиничного номера\n";
        std::getline(std::cin, input);

        if (input.size() > 4) {
            std::cout << "Неверный ввод. Повторите снова.\n";
        }

        for (int i = 1; i < 4; ++i) {
            if (!isdigit(input[i])) {
                std::cout << "Неверный ввод. Повторите снова.\n";
                break;
            }
        }

        if (input[0] != 'Л' && input[0] != 'П' && input[0] != 'О' && input[0] != 'М') {
            std::cout << "Неверный ввод. Повторите снова.\n";
        }
        else
            return input;
    }
}

int EnterNumOfBeds() {
    std::string input;
    while (true) {
        std::cout << "Введите количество мест в номере\n";
        std::getline(std::cin, input);
        for (int i = 0; i < input.size(); ++i) {
            if (!std::isdigit(input[i])) {
                std::cout << "Только цифры.\n";
                break;
            }
            else {
                return std::stoi(input);
            }
        }
    }
}

int EnterNumOfRooms()
{
    std::string input;
    while (true) {
        std::cout << "Введите количество комнат в номере\n";
        std::getline(std::cin, input);
        for (int i = 0; i < input.size(); ++i) {
            if (!std::isdigit(input[i])) {
                std::cout << "Только цифры.\n";
                break;
            }
            else {
                return std::stoi(input);
            }
        }
    }
}

bool EnterBathroom() {
    std::string input;
    while (true) {
        std::cout << "Есть ли в номере санузел?   Да/Нет\n";
        std::getline(std::cin, input);
        if (input == "Да" || input == "да") {
            return true;
        }
        else if (input == "Нет" || input == "нет") {
            return false;
        }
        else {
            std::cout << "Неверный ввод. Повторите снова.\n";
        }
    }
}

std::string EnterEquipment()
{
    std::string input;
    while (true) {
        std::cout << "Введите оборудование в номере\n";
        std::getline(std::cin, input);
        return input;
    }
}

void PrintSuiteData(Suite_data* suite)
{
    std::cout << "Номер: " << suite->suite_number << "\n"
        << "Количество мест: " << suite->number_of_beds << "\n"
        << "Количество комнат: " << suite->number_of_rooms << "\n"
        << "Есть ли санузел: " << suite->bathroom << "\n"
        << "Оборудование: " << suite->equipment << "\n";
}
