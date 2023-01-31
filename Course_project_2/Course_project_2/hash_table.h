#pragma once

#include "guest.h"

enum HashPosStatus { Empty, Occupied, Deleted };

struct Guest_hash {
    Guest_data data;
    HashPosStatus pos_status;
};

struct Hash_table {
    Guest_hash* table;
    int size;
};

Hash_table* CreateHashTable(int size);
void HashAdd(Hash_table* hash_table);
int HashFunction(const std::string id, const int size);
void HashInsert(Hash_table* hash_table, Guest_data* new_guest);
void HashSearchID(Hash_table* hash_table);
void HashSearchFio(Hash_table* hash_table);
void HashDelete(Hash_table* hash_table);
void PrintHashTable(Hash_table* hash_table);
void DeleteHashTable(Hash_table* hash_table);
Hash_table* ReHash(Hash_table* hash_table);
bool IsSameId(Hash_table* hash_table, std::string id);

