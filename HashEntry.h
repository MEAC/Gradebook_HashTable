class HashEntry {
public:
	int key;
	int value;
	//HashNode* next;
	HashEntry(int key, int value) {
		this->key = key;
		this->value = value;
		//this->next = NULL;
	}
};
