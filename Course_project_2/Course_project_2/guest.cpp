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
        std::cout << "������� ����� ��������:\n";
        std::getline(std::cin, input);

        if (input.size() == 4) {
            int nums_count = 0;
            for (int i = 0; i < input.size(); ++i) {
                if (std::isdigit(input[i]))
                    ++nums_count;
                else {
                    std::cout << "������ �����\n";
                    break;
                }

                if (nums_count == input.size())
                    input_is_fine = true;
            }
        }
        else {
            std::cout << "��������� ������ 4 �������. ��������� ����.\n";
        }
    }

    std::string id;
    id = input + "-";

    std::string number;
    input_is_fine = false;
    while (!input_is_fine) {
        std::cout << "������� ����� ��������:\n";
        std::getline(std::cin, input);

        if (input.size() == 6) {
            int nums_count = 0;
            for (int i = 0; i < input.size(); ++i) {
                if (std::isdigit(input[i]))
                    ++nums_count;
                else {
                    std::cout << "������ �����\n";
                    break;
                }

                if (nums_count == input.size())
                    input_is_fine = true;
            }
        }
        else {
            std::cout << "��������� ������ 6 ��������. ��������� ����.\n";
        }
    }

    id += input;

    return id;
}

std::string EnterFio() {
    std::string input;
    bool input_is_fine = false;
    while (!input_is_fine) {
        std::cout << "������� ���:\n";
        std::getline(std::cin, input);

        if (input.size() < 50) {
            input_is_fine = true;
        }
        else {
            std::cout << "��������� ����� 50 ��������. ��������� ����.\n";
        }
    }

    return input;
}

int EnterYearOfBirth() {
    std::string input;
    bool input_is_fine = false;
    while (!input_is_fine) {
        std::cout << "������� ��� ��������\n";
        std::getline(std::cin, input);

        if (input.size() == 4) {
            int nums_count = 0;
            for (int i = 0; i < input.size(); ++i) {
                if (std::isdigit(input[i]))
                    ++nums_count;
                else {
                    std::cout << "������ �����\n";
                    break;
                }

                if (nums_count == input.size())
                    input_is_fine = true;
            }
        }
        else {
            std::cout << "��������� ������ 4 �������. ��������� ����.\n";
        }
    }

    int year;
    year = std::stoi(input);
    return year;
}

std::string EnterAddress() {
    std::cout << "������� �����:\n";
    std::string address;
    std::getline(std::cin, address);
    return address;
}

std::string EnterPurposeOfArrival() {
    std::cout << "������� ���� ��������:\n";
    std::string purpose;
    std::getline(std::cin, purpose);
    return purpose;
}

void PrintGuestData(Guest_data* guest) {
    std::cout << "����� ��������: " << guest->id << "\n";
    std::cout << "���: " << guest->fio << "\n";
    std::cout << "��� ��������: " << guest->year_of_birth << "\n";
    std::cout << "�����: " << guest->address << "\n";
    std::cout << "���� ��������: " << guest->purpose_of_arrival << "\n";
}

void PrintFioAndId(Guest_data* guest){
    std::cout << "���: " << guest->fio << "     " <<
                 "����� ��������: " << guest->id;
}
