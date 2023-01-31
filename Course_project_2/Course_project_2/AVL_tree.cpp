#include "AVL_tree.h"

Tree_node* CreateTree() {
    return NULL;
}

int Height(Tree_node* root)
{
    if (!root)
        return 0;
    return root->height;
}

int Max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

Tree_node* NewNode(Suite_data new_suite)
{
    Tree_node* new_node = new Tree_node;
    new_node->data = new_suite;
    new_node->height = 1;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

Tree_node* RightRotate(Tree_node* y)
{
    Tree_node* x = y->left;
    Tree_node* tmp = x->right;
    x->right = y;
    y->left = tmp;

    y->height = Max(Height(y->left), Height(y->right)) + 1;
    x->height = Max(Height(x->left), Height(x->right)) + 1;
    
    return x;
}

Tree_node* LeftRotate(Tree_node* x)
{
    Tree_node* y = x->right;
    Tree_node* tmp = y->left;

    y->left = x;
    x->right = tmp;

    x->height = Max(Height(x->left), Height(x->right));
    y->height = Max(Height(y->left), Height(y->right));

    return y;
}

int BalanceFactor(Tree_node* tree) {
    if (tree == NULL)
        return 0;
    return Height(tree->left) - Height(tree->right);
}

void InOrder(Tree_node* root) {
    if (root) {
        InOrder(root->left);
        InOrder(root->right);
    }
}

Tree_node* AddNode(Tree_node* tree)
{
    Suite_data new_suite = AddSuite();
    return InsertNode(tree, new_suite);
}

Tree_node* InsertNode(Tree_node* tree, Suite_data new_suite)
{
    if (tree == NULL) {
        return NewNode(new_suite);
    }
    std::string num = new_suite.suite_number.substr(1);

    if (IsSuitNumberBigger(tree->data.suite_number, new_suite.suite_number))
        tree->left = InsertNode(tree->left, new_suite);
    else if (IsSuitNumberBigger(new_suite.suite_number, tree->data.suite_number))
        tree->right = InsertNode(tree->right, new_suite);
    else {
        std::cout << "Такой номер уже есть.\n";
        return tree;
    }

    tree->height = 1 + Max(Height(tree->left), Height(tree->right));

    if (BalanceFactor(tree) > 1) {
        if (IsSuitNumberBigger(tree->left->data.suite_number, new_suite.suite_number))
            return RightRotate(tree);
        else if (IsSuitNumberBigger(new_suite.suite_number, tree->left->data.suite_number)) {
            tree->left = LeftRotate(tree->left);
            return RightRotate(tree);
        }
    }

    if (BalanceFactor(tree) < -1) {
        if (IsSuitNumberBigger(new_suite.suite_number, tree->right->data.suite_number))
            return LeftRotate(tree);
        else if (IsSuitNumberBigger(tree->right->data.suite_number, new_suite.suite_number)) {
            tree->left = LeftRotate(tree->left);
            return LeftRotate(tree);
        }
    }

    return tree;
}

Tree_node* MinNode(Tree_node* tree)
{
    Tree_node* curr = tree;

    while (curr->left != NULL)
        curr = curr->left;

    return curr;
}

bool IsSuitNumberBigger(std::string s_num1, std::string s_num2) {
    int num1 = std::stoi(s_num1.substr(1));
    int num2 = std::stoi(s_num2.substr(1));

    if (num1 > num2)
        return true;
    else
        return false;
}

Tree_node* DeleteNode(Tree_node* tree) {
    std::string suite_num = EnterSuiteNumber();
    return FindNodeToDelete(tree, suite_num);
}

Tree_node* FindNodeToDelete(Tree_node* tree, std::string suite_num) { 
    if (tree == NULL)
        return tree;
    
    if (IsSuitNumberBigger(tree->data.suite_number, suite_num))
        tree->left = FindNodeToDelete(tree->left, suite_num);
    else if (IsSuitNumberBigger(suite_num, tree->data.suite_number))
        tree->right = FindNodeToDelete(tree->right, suite_num);
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
            tree->right = FindNodeToDelete(tree->right, tmp->data.suite_number);
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

void PrintTree(Tree_node* tree) {
    if (tree == NULL)
        return;

    PrintTree(tree->left);
    std::cout << "Номер: " << tree->data.suite_number << "\n"
        << "Количество мест: " << tree->data.number_of_beds << "\n\n";
    PrintTree(tree->right);
}

void DeleteTree(Tree_node* tree)
{
    if (tree != NULL)
    {
        DeleteTree(tree->left);
        DeleteTree(tree->right);
        delete tree;
        tree = NULL;
    }
}

void TreeSearchSuiteNumber(Tree_node* tree) {
    std::string suite_num = EnterSuiteNumber();
    Tree_node* tmp = tree;
    while (tmp) {
        if (tmp->data.suite_number == suite_num) {
            std::cout << "Номер найден.\n";
            PrintSuiteData(&tmp->data);
            return;
        }
        else if (IsSuitNumberBigger(tmp->data.suite_number, suite_num))
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    std::cout << "Такого номера нет.\n";
    return;
}

void BMSearch(Tree_node* tree, std::string equipment) {
    if (tree == NULL)
        return;

    if (tree != NULL) {
        int eq_length = equipment.length();
        int text_length = tree->data.equipment.length();

        int badchar[124];

        BadChar(equipment, eq_length, badchar);

        int s = 0;
        while (s <= (text_length - eq_length)) {
            int j = eq_length - 1;

            while (j >= 0 && equipment[j] == tree->data.equipment[s + j])
                j--;

            if (j < 0) {
                PrintSuiteData(&tree->data);
            }
        }
    }
    BMSearch(tree->left, equipment);
    BMSearch(tree->right, equipment);
}

bool IsSameSuitNumber(Tree_node* tree, std::string suite_num) {
    Tree_node* tmp = tree;
    while (tmp) {
        if (tmp->data.suite_number == suite_num) {
            return true;
        }
        else if (IsSuitNumberBigger(tmp->data.suite_number, suite_num))
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return false;
}

void BadChar(std::string str, int size, int bad_chars[124]) {
    for (int i = 0; i < 124; i++)
        bad_chars[i] = -1;

    for (int i = 0; i < size; i++)
        bad_chars[(int)str[i]] = i;
}

void TreeSearchEquipment(Tree_node* tree) {
    std::string eq = EnterEquipment();
    BMSearch(tree, eq);
}

int GetNumOfBeds(Tree_node* tree, std::string suite_number) {
    Tree_node* tmp = tree;
    while (tmp) {
        if (tmp->data.suite_number == suite_number) {
            return tmp->data.number_of_beds;
        }
        else if (IsSuitNumberBigger(tmp->data.suite_number, suite_number))
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return 0;
}
