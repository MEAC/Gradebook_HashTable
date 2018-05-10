#include <iostream>
#include "HashEntry.h"
using namespace std;
const int TABLE_SIZE = 128;

class HashMap {
private:
	HashEntry * *table;
public:
	HashMap() {
		table = new HashEntry *[TABLE_SIZE];
		for (int i = 0; i< TABLE_SIZE; i++) {
			table[i] = nullptr;
		}
	}

	int HashFunc(int key) {
		return key % TABLE_SIZE;
	}

	void Insert(int key, int value) {
		int hash = HashFunc(key);
		while (table[hash] != nullptr && table[hash]->key != key) {
			hash = HashFunc(hash + 1);
		}
		if (table[hash] != nullptr)
			delete table[hash];
		table[hash] = new HashEntry(key, value);
	}

	int Search(int key) {
		int  hash = HashFunc(key);
		while (table[hash] != nullptr && table[hash]->key != key) {
			hash = HashFunc(hash + 1);
		}
		if (table[hash] == nullptr)
			return -1;
		else
			return table[hash]->value;
	}

	void Remove(int key) {
		int hash = HashFunc(key);
		while (table[hash] != nullptr) {
			if (table[hash]->key == key)
				break;
			hash = HashFunc(hash + 1);
		}
		if (table[hash] == nullptr) {
			cout << "No Element found at key " << key << endl;
			return;
		}
		else {
			delete table[hash];
		}
		cout << "Element Deleted" << endl;
	}

	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (table[i] != nullptr)
				delete table[i];
			delete[] table;
		}
	}
};
