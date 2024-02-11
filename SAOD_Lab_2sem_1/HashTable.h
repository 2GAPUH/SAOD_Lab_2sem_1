#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define TABLE_SIZE 100
#define NOT_FOUND -1231412
#define INVALID_KEY -123912

class HashTable
{
private:
	struct Node
	{
		std::string key;
		Node() : key("") {};
	};

	Node* table = nullptr;

	int HashFunction(std::string& key);

public:
	HashTable();
	~HashTable();
	void Insert(std::string& key);
	int Search(std::string& key);
};

