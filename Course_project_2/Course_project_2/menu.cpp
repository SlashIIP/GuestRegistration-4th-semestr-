#include "menu.h"

bool IsOqupied(List* list, std::string suite_num) {
    while (list) {
        if (list->data.suite_number == suite_num && list->data.checkout_date.length() != 10)
            return true;
        list = list->next;
    }
    return false;
}

Tree_node* DeleteNode_(Tree_node* tree, List* list) {
    std::string suite_num = EnterSuiteNumber();
    if (IsOqupied(list, suite_num)) {
        std::cout << "����� �����.\n";
        return tree;
    }
    return FindNodeToDelete_(tree, suite_num);
}

Tree_node* FindNodeToDelete_(Tree_node* tree, std::string suite_num) {
    if (tree == NULL)
        return tree;

    if (IsSuitNumberBigger(tree->data.suite_number, suite_num))
        tree->left = FindNodeToDelete_(tree->left, suite_num);
    else if (IsSuitNumberBigger(suite_num, tree->data.suite_number))
        tree->right = FindNodeToDelete_(tree->right, suite_num);
    else {
        if ((tree->left == NULL) || (tree->right == NULL)) {
            Tree_node* tmp = tree->left ? tree->left : tree->right;

            if (tmp == NULL) {
                tmp = tree;
                tree = NULL;
            }
            else
                *tree = *tmp;
            free(tmp);
        }
        else {
            Tree_node* tmp = MinNode(tree->right);
            tree->data = tmp->data;
            tree->right = FindNodeToDelete_(tree->right, tmp->data.suite_number);
        }
    }

    if (tree == NULL)
        return tree;

    tree->height = 1 + Max(Height(tree->left), Height(tree->right));
    int balance_factor = BalanceFactor(tree);

    if (balance_factor > 1) {
        if (BalanceFactor(tree->left) >= 0)
            return RightRotate(tree);
        else {
            tree->left = LeftRotate(tree->left);
            return RightRotate(tree);
        }
    }

    if (balance_factor < -1) {
        if (BalanceFactor(tree->right) <= 0)
            return LeftRotate(tree);
        else {
            tree->right = RightRotate(tree->right);
            return LeftRotate(tree);
        }
    }

    return tree;
}

void Menu()
{
    Hash_table* hash_table = CreateHashTable(50);
    Tree_node* tree = CreateTree();
    List* list = CreateLinkedList();

    std::cout << "1 - ����������� ������ ����������\n"
        << "2 - �������� ������ � ����������\n"
        << "3 - �������� ���� ������������������ �����������\n"
        << "4 - ������� ������ � �����������\n"
        << "5 - ����� ���������� �� ������ ��������\n"
        << "6 - ����� ���������� �� ���\n"
        << "7 - ���������� ������ ������������ ������\n"
        << "8 - �������� �������� � ����������� ������\n"
        << "9 - �������� ���� ��������� ����������� �������\n"
        << "10 - ������� ������ � ����������� �������\n"
        << "11 - ����� ������������ ������ �� ������� ������������ ������\n"
        << "12 - ����� ������������ ������ �� ���������� ��������������\n"
        << "13 - ����������� �������� ����������\n"
        << "14 - ����������� ��������� ����������\n"
        << "0 - �����\n";

    int menu_choice;
    int menu_check = 1;
    bool menu_cycle = true;

    while (menu_cycle)
    {
        std::string input;
        while (true) {
            std::getline(std::cin, input);
            if (input.find_first_not_of("0123456789") == std::string::npos) {
                menu_choice = std::stoi(input);
                if (menu_choice > 15) {
                    std::cout << "������ ������ ���.\n";
                }
                else {
                    break;
                }
            }
            std::cout << "�������� ����. ��������� �����.\n";
        }

        switch (menu_choice)
        {
        case 1:
            HashAdd(hash_table);
            break;
        case 2:
            HashDelete(hash_table);
            break;
        case 3:
            PrintHashTable(hash_table);
            break;
        case 4:
            DeleteHashTable(hash_table);
            break;
        case 5:
            HashSearchID(hash_table);
            break;
        case 6:
            HashSearchFio(hash_table);
            break;
        case 7:
            tree = AddNode(tree);
            break;
        case 8:
            tree = DeleteNode_(tree, list);
            break;
        case 9:
            PrintTree(tree);
            break;
        case 10:
            DeleteTree(tree);
            tree = CreateTree();
            break;
        case 11:
            TreeSearchSuiteNumber(tree);
            break;
        case 12:
            TreeSearchEquipment(tree);
            break;
        case 13:
            ListAdd(list, hash_table, tree);
            break;
        case 14:
            ListAddCheckOut(list);
            break;
        case 15:
            PrintList(list);
            break;
        case 0:
            menu_cycle = false;
            break;

        }
    }
}

