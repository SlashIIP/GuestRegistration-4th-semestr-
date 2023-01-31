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
    std::cout << "������� ����� ������������ ������ � ������� ANNN,\n"
        << "��� A � �����, ������������ ��� ������(� � ����, � � ��������, � � �����������, � � ������������);\n"
        << "NNN � ���������� �����(�����)\n";
    while (true) {
        std::cout << "������� ����� ������������ ������\n";
        std::getline(std::cin, input);

        if (input.size() > 4) {
            std::cout << "�������� ����. ��������� �����.\n";
        }

        for (int i = 1; i < 4; ++i) {
            if (!isdigit(input[i])) {
                std::cout << "�������� ����. ��������� �����.\n";
                break;
            }
        }

        if (input[0] != '�' && input[0] != '�' && input[0] != '�' && input[0] != '�') {
            std::cout << "�������� ����. ��������� �����.\n";
        }
        else
            return input;
    }
}

int EnterNumOfBeds() {
    std::string input;
    while (true) {
        std::cout << "������� ���������� ���� � ������\n";
        std::getline(std::cin, input);
        for (int i = 0; i < input.size(); ++i) {
            if (!std::isdigit(input[i])) {
                std::cout << "������ �����.\n";
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
        std::cout << "������� ���������� ������ � ������\n";
        std::getline(std::cin, input);
        for (int i = 0; i < input.size(); ++i) {
            if (!std::isdigit(input[i])) {
                std::cout << "������ �����.\n";
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
        std::cout << "���� �� � ������ �������?   ��/���\n";
        std::getline(std::cin, input);
        if (input == "��" || input == "��") {
            return true;
        }
        else if (input == "���" || input == "���") {
            return false;
        }
        else {
            std::cout << "�������� ����. ��������� �����.\n";
        }
    }
}

std::string EnterEquipment()
{
    std::string input;
    while (true) {
        std::cout << "������� ������������ � ������\n";
        std::getline(std::cin, input);
        return input;
    }
}

void PrintSuiteData(Suite_data* suite)
{
    std::cout << "�����: " << suite->suite_number << "\n"
        << "���������� ����: " << suite->number_of_beds << "\n"
        << "���������� ������: " << suite->number_of_rooms << "\n"
        << "���� �� �������: " << suite->bathroom << "\n"
        << "������������: " << suite->equipment << "\n";
}
