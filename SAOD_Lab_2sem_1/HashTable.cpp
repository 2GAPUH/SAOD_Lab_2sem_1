#include "HashTable.h"

int HashTable::HashFunction(std::string& key)
{
	int sum = 0;
	for (auto n : key)
		sum += n;

	return sum % size;
}

void HashTable::Print()
{
	for (int i = 0; i < size; i++)
		std::cout << "table[" << i << "]: " << table[i].key << std::endl;
}

void HashTable::DeleteChar(char simb)
{
	for (int i = 0; i < size; i++)
		if (table[i].key[0] == simb)
			table[i].key = "";

}

HashTable::HashTable()
{
	size = TABLE_SIZE;
	table = new Node[TABLE_SIZE];
}

HashTable::HashTable(int size)
{
	this->size = size;
	table = new Node[size];
}

HashTable::~HashTable()
{
	//delete table;
	table = nullptr;
}

void HashTable::Insert(std::string& key)
{
	int pos = HashFunction(key);
	int posCopy = pos;
	do	{
		if (table[pos].key == "")
		{
			table[pos].key = key;
			return;
		}
		else
		{
			std::cout << "collision " << key << " on pos: " << pos << std::endl;
			pos++;
			pos %= size;
		}
	} while (pos != posCopy);
}

int HashTable::Search(std::string& key)
{
	if (key == "")
		return INVALID_KEY;
	int pos = HashFunction(key);
	int posCopy = pos;
	do {
		if (table[pos].key == key)
			return pos;
		else if (table[pos].key == "")
			return NOT_FOUND;
		else
		{
			pos++;
			pos %= size;
		}
	} while (pos != posCopy);
	return NOT_FOUND;
}

