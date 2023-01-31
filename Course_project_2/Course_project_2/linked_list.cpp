#include "linked_list.h"
#include "hash_table.h"
#include "AVL_tree.h"

void ListAdd(List* list, Hash_table* hash_table, Tree_node* tree) {
    Check_info new_check = AddCheckInfo();

    if (IsSameId(hash_table, new_check.id) && IsSameSuitNumber(tree, new_check.suite_number)) {
        int num_of_guest = NumOfGuests(list, new_check.suite_number);
        int num_of_beds = GetNumOfBeds(tree, new_check.suite_number);

        if (num_of_guest == num_of_beds) {
            std::cout << "Комната переполнена.\n";
            return;
        }
        ListInsert(list, new_check);
    }
    else
    {
        std::cout << "Такой комнаты или гостя не существует.\n";
    }
}

List* CreateLinkedList() {
    List* linked_list = new List;
    linked_list->next = NULL;
    return linked_list;
}

void ListInsert(List* list, Check_info new_check) {
    List* new_node = new List;
    new_node->data = new_check;
    new_node->next = NULL;

    if (list == NULL)
        list = new_node;
    else {
        List* last = list;
        while (last->next)
            last = last->next;
        last->next = new_node;
    }
}

void ListAddCheckOut(List* list) {
    std::string id = EnterId();
    std::string suite_num = EnterSuiteNumber();
    if (IsCheckedIn(list, id, suite_num)) {
        list->data.checkout_date = EnterCheckoutDate();
    }
    else {
        std::cout << "Такой комнаты или гостя не существует.\n";
    }
}

List* FindMinList(List* list) {
    List* min_value = list;
    while (list->next) {
        if (IsSuitNumberBigger(min_value->data.suite_number, list->data.suite_number))
            min_value = list;
    }

    return min_value;
}

List* FindMaxList(List* list)
{
    List* max_value = list;
    while (list->next) {
        if (IsSuitNumberBigger(list->data.suite_number, max_value->data.suite_number))
            max_value = list;
    }

    return max_value;
}

bool IsCheckedIn(List* list, std::string id, std::string suite_num) {
    while (list) {
        if (list->data.id == id && list->data.suite_number == suite_num)
            return true;
        else
            list = list->next;
    }
    return false;
}

int NumOfGuests(List* list, std::string suite_num) {
    int num_of_guests = 0;
    while (list) {
        if (list->data.suite_number == suite_num && list->data.checkout_date.length() != 10) {
            ++num_of_guests;
        }
        list = list->next;
    }
    return num_of_guests;
}

void PrintList(List* list) {
    while (list) {
        std::cout << "Номер паспорта: " << list->data.id << "\n"
            << "Номер комнаты: " << list->data.suite_number << "\n";
        list = list->next;
    }
}