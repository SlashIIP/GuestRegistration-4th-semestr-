#include "guest.h"

Guest_data AddGuest()
{
    Guest_data new_guest;
    FillGuestData(&new_guest);
    return new_guest;
}

void FillGuestData(Guest_data* guest) {
    guest->id = EnterId();
    guest->fio = EnterFio();
    guest->year_of_birth = EnterYearOfBirth();
    guest->address = EnterAddress();
    guest->purpose_of_arrival = EnterPurposeOfArrival();
}

std::string EnterId() {
    std::string input;
    bool input_is_fine = false;
    while (!input_is_fine) {
        std::cout << "Введите серию паспорта:\n";
        std::getline(std::cin, input);

        if (input.size() == 4) {
            int nums_count = 0;
            for (int i = 0; i < input.size(); ++i) {
                if (std::isdigit(input[i]))
                    ++nums_count;
                else {
                    std::cout << "Только цифры\n";
                    break;
                }

                if (nums_count == input.size())
                    input_is_fine = true;
            }
        }
        else {
            std::cout << "Допустимо только 4 символа. Повторите ввод.\n";
        }
    }

    std::string id;
    id = input + "-";

    std::string number;
    input_is_fine = false;
    while (!input_is_fine) {
        std::cout << "Введите номер паспорта:\n";
        std::getline(std::cin, input);

        if (input.size() == 6) {
            int nums_count = 0;
            for (int i = 0; i < input.size(); ++i) {
                if (std::isdigit(input[i]))
                    ++nums_count;
                else {
                    std::cout << "Только цифры\n";
                    break;
                }

                if (nums_count == input.size())
                    input_is_fine = true;
            }
        }
        else {
            std::cout << "Допустимо только 6 символов. Повторите ввод.\n";
        }
    }

    id += input;

    return id;
}

std::string EnterFio() {
    std::string input;
    bool input_is_fine = false;
    while (!input_is_fine) {
        std::cout << "Введите ФИО:\n";
        std::getline(std::cin, input);

        if (input.size() < 50) {
            input_is_fine = true;
        }
        else {
            std::cout << "Допустимо менее 50 символов. Повторите ввод.\n";
        }
    }

    return input;
}

int EnterYearOfBirth() {
    std::string input;
    bool input_is_fine = false;
    while (!input_is_fine) {
        std::cout << "Введите год рождения\n";
        std::getline(std::cin, input);

        if (input.size() == 4) {
            int nums_count = 0;
            for (int i = 0; i < input.size(); ++i) {
                if (std::isdigit(input[i]))
                    ++nums_count;
                else {
                    std::cout << "Только цифры\n";
                    break;
                }

                if (nums_count == input.size())
                    input_is_fine = true;
            }
        }
        else {
            std::cout << "Допустимо только 4 символа. Повторите ввод.\n";
        }
    }

    int year;
    year = std::stoi(input);
    return year;
}

std::string EnterAddress() {
    std::cout << "Введите адрес:\n";
    std::string address;
    std::getline(std::cin, address);
    return address;
}

std::string EnterPurposeOfArrival() {
    std::cout << "Введите цель прибытия:\n";
    std::string purpose;
    std::getline(std::cin, purpose);
    return purpose;
}

void PrintGuestData(Guest_data* guest) {
    std::cout << "Номер паспорта: " << guest->id << "\n";
    std::cout << "ФИО: " << guest->fio << "\n";
    std::cout << "Год рождения: " << guest->year_of_birth << "\n";
    std::cout << "Адрес: " << guest->address << "\n";
    std::cout << "Цель прибытия: " << guest->purpose_of_arrival << "\n";
}

void PrintFioAndId(Guest_data* guest){
    std::cout << "ФИО: " << guest->fio << "     " <<
                 "Номер паспорта: " << guest->id;
}
