class HashEntry {
public:
	int key;
	int value;
	HashEntry* next;
	
	HashEntry(int key, int value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};
