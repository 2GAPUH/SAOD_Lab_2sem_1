#include "HashTable.h"

int HashTable::HashFunction(std::string& key)
{
	int sum = 0;
	for (auto n : key)
		sum += n;

	return sum % TABLE_SIZE;
}

HashTable::HashTable()
{
	table = new Node[TABLE_SIZE];
}

HashTable::~HashTable()
{
	delete table;
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
			pos++;
			pos %= TABLE_SIZE;
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
			pos %= TABLE_SIZE;
		}
	} while (pos != posCopy);
	return NOT_FOUND;
}

