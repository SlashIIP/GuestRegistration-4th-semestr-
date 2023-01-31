#pragma once

#include <iostream>
#include "check-in_check-out.h"
#include "hash_table.h"
#include "AVL_tree.h"

struct List {
    Check_info data;
    List* next;
};

List* CreateLinkedList();
void ListAdd(List* list, Hash_table* hash_table, Tree_node* tree);
void ListInsert(List* list, Check_info new_check);
void ListAddCheckOut(List* list);
List* FindMinList(List* list);
List* FindMaxList(List* list);
bool IsCheckedIn(List* list, std::string id, std::string suite_num);
int NumOfGuests(List* list, std::string suite_num); 
void PrintList(List* list);