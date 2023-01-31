#pragma once

#include "hash_table.h"
#include "AVL_tree.h"
#include "linked_list.h"

bool IsOqupied(List* list, std::string suite_num);
Tree_node* DeleteNode_(Tree_node* tree, List* list);
Tree_node* FindNodeToDelete_(Tree_node* tree, std::string suite_num);
void Menu();