#include "HashEntry.h"
#include <iostream>
using namespace std;

const int TABLE_SIZE = 128;

class HashMap {
private:
	HashEntry * *table;
public:
	HashMap() {
		table = new HashEntry*[TABLE_SIZE];

		for (int i = 0; i < TABLE_SIZE; ++i) {
			table[i] = nullptr;
		}
	}

	int HashFunc(int key) {
		return key % TABLE_SIZE;
	}

	void Insert(int key, int value) {
		int hash = HashFunc(key);
		HashEntry* prev = nullptr;
		HashEntry* entry = table[hash];

		while (entry != nullptr) {
			prev = entry;
			entry = entry->next;
		}
		if (entry == nullptr) {
			entry = new HashEntry(key, value);
			if (prev == nullptr) {
				table[hash] = entry;
			}
			else {
				prev->next = entry;
			}
		}
		else {
			entry->value = value;
		}
	}

	int Search(int key) {
		bool flag = false;
		int hash = HashFunc(key);
		HashEntry* entry = table[hash];

		while (entry != nullptr) {
			if (entry->key == key) {
				cout << entry->value << "% ";
				flag = true;
			}
			entry = entry->next;
		}
		if (!flag) {
			return -1;
		}
	}

	void Remove(int key) {
		int hash = HashFunc(key);

		while (table[hash] != nullptr) {
			if (table[hash]->key == key) {
				break;
			}
			hash = HashFunc(hash + 1);
		}
		if (table[hash] == nullptr) {
			cout << "No Grade found at student ID " << key << endl;
			return;
		}
		else {
			delete table[hash];
		}
		cout << "Grade Deleted" << endl;
	}

	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; ++i) {
			if (table[i] != nullptr) {
				delete table[i];
			}
			delete[] table;
		}
	}
};
