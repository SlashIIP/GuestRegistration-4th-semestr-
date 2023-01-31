#include "hash_table.h"

Hash_table* CreateHashTable(int size) {
    Hash_table* h_t = new Hash_table;
    h_t->size = size;
    h_t->table = new Guest_hash[size];

    for (int i = 0; i < size; ++i)
        h_t->table[i].pos_status = Empty;

    return h_t;
}

void HashAdd(Hash_table* hash_table) {
    Guest_data new_guest = AddGuest();
    if (IsSameId(hash_table, new_guest.id)) {
        std::cout << "Гость с таким номером паспорта уже есть.\n";
        return;
    }
    HashInsert(hash_table, &new_guest);
}

int HashFunction(const std::string id, const int size) {
    int pos = 0;

    for (int i = 0; i < id.size(); ++i) {
        pos += id[i];
    }

    return pos % 50;
}

void HashInsert(Hash_table* hash_table, Guest_data* new_guest) {
    int pos = HashFunction(new_guest->id, hash_table->size);
    int i = 1;
    while (true) {
        if (hash_table->table[pos].pos_status != Occupied) {
            hash_table->table[pos].data = *new_guest;
            hash_table->table[pos].pos_status = Occupied;
            break;
        }
        else {
            pos += (2 * i + 3 * i * i);
            ++i;
        }
        if (pos > hash_table->size) {
            std::cout << "Не удалось найти свободное место в хеш-таблице.\n";
            break;
        }
    }

}

void HashSearchID(Hash_table* hash_table) {
    std::string id = EnterId();
    int pos = HashFunction(id, hash_table->size);
    int i = 1;
    while (true) {
        if (hash_table->table[pos].pos_status == Empty) {
            std::cout << "Не удалось найти такого гостя.\n";
            break;
        }
        else if (hash_table->table[pos].data.id == id) {
            std::cout << "Гость найден.\n";
            PrintGuestData(&(hash_table->table[pos].data));
            break;
        }
        else {
            pos += (2 * i + 3 * i * i);
            ++i;
        }
        if (pos > hash_table->size) {
            std::cout << "Не удалось найти такого гостя.\n";
            break;
        }
    }
}

void HashSearchFio(Hash_table* hash_table) {
    std::string fio = EnterFio();
    int fio_length = fio.size();
    int size = hash_table->size;
    for (int i = 0; i < size; i++) {
        if (hash_table->table[i].pos_status == Occupied) {
            int text_length = hash_table->table[i].data.fio.size();

            if (fio_length == 0) {
                std::cout << "Гость не найден.\n";
                return;
            }

            if (text_length < fio_length) {
                std::cout << "Гость не найден.\n";
                return;
            }

            int* next = new int[fio_length + 1];

            for (int k = 1; k < fio_length + 1; k++) {
                next[k] = 0;
            }

            for (int k = 1; k < fio_length; ++k) {
                int j = next[k + 1];

                while (j > 0 && fio[j] != fio[i]) {
                    j = next[j];
                }

                if (j > 0 || fio[j] == fio[i]) {
                    next[i + 1] = j + 1;
                }
            }
            
            for (int k = 0, j = 0; k < text_length; k++) {
                if (hash_table->table[i].data.fio[k] == fio[j]) {
                    if (++j == fio_length) {
                        std::cout << "Номер паспорта: " << hash_table->table[i].data.id << "\n"
                            << "ФИО: " << hash_table->table[i].data.fio << "\n";
                        break;
                    }
                }
                else if (j > 0) {
                    j = next[j];
                    i--;
                }
            }
        }

    }
}

void HashDelete(Hash_table* hash_table) {
    std::string id = EnterId();
    int pos = HashFunction(id, hash_table->size);
    int i = 1;
    while (true) {
        if (hash_table->table[pos].pos_status == Empty) {
            std::cout << "Не удалось найти такого гостя.\n";
            break;
        }
        else if (hash_table->table[pos].data.id == id) {
            hash_table->table[pos].pos_status = Deleted;
            std::cout << "Данные гостя удалены.\n";
            break;
        }
        else {
            pos += (2 * i + 3 * i * i);
            ++i;
        }

        if (pos > hash_table->size) {
            std::cout << "Не удалось найти такого гостя.\n";
            break;
        }
    }
}

void PrintHashTable(Hash_table* hash_table) {
    for (int i = 0; i < hash_table->size; ++i) {
        if (hash_table->table[i].pos_status == Occupied) {
            std::cout << "Номер паспорта: " << hash_table->table[i].data.id << "\n"
                << "ФИО: " << hash_table->table[i].data.fio << "\n";
        }
    }
}

void DeleteHashTable(Hash_table* hash_table) {
    delete[] hash_table->table;
    hash_table->table = new Guest_hash[hash_table->size];

    for (int i = 0; i < hash_table->size; ++i)
        hash_table->table[i].pos_status = Empty;
}

Hash_table* ReHash(Hash_table* hash_table) {
    int old_size = hash_table->size;
    hash_table->size *= 2;

    Hash_table* tmp_hash = CreateHashTable(old_size);

    for (int i = 0; i < old_size; i++) {
        tmp_hash->table;
    }
    return nullptr;
}

bool IsSameId(Hash_table* hash_table, std::string id)
{
    int pos = HashFunction(id, hash_table->size);
    int i = 1;
    while (true) {
        if (hash_table->table[pos].pos_status == Empty) {
            break;
        }
        else if (hash_table->table[pos].data.id == id) {
            return true;
        }
        else {
            pos += (2 * i + 3 * i * i);
            ++i;
        }
        if (pos > hash_table->size) {
            break;
        }
    }
    return false;
}
