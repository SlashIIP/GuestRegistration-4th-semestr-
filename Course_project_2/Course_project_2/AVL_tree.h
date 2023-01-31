#pragma once

#include <iostream>
#include "hotel_suite.h"

struct Tree_node {
    Suite_data data;
    int height;
    Tree_node* left;
    Tree_node* right;
};

Tree_node* CreateTree();
int Height(Tree_node* root);
int Max(int a, int b);
Tree_node* NewNode(Suite_data new_suite);
Tree_node* RightRotate(Tree_node* y);
Tree_node* LeftRotate(Tree_node* x);
int BalanceFactor(Tree_node* tree);
void InOrder(Tree_node* root);
Tree_node* AddNode(Tree_node* tree);
Tree_node* InsertNode(Tree_node* tree, Suite_data new_suite);
Tree_node* MinNode(Tree_node* tree);
Tree_node* DeleteNode(Tree_node* tree);
Tree_node* FindNodeToDelete(Tree_node* tree, std::string suite_num);
bool IsSuitNumberBigger(std::string s_num1, std::string s_num2);
void PrintTree(Tree_node* tree);
void DeleteTree(Tree_node* tree);
void TreeSearchSuiteNumber(Tree_node* tree);
void BMSearch(Tree_node* tree, std::string equipment);
bool IsSameSuitNumber(Tree_node* tree, std::string suite_num);
void BadChar(std::string str, int size, int bad_chars[124]);
void TreeSearchEquipment(Tree_node* tree);
int GetNumOfBeds(Tree_node* tree, std::string suite_number);