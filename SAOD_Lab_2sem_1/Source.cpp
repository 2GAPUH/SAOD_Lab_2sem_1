#define _CRT_SECURE_NO_WARNINGS
#include "HashTable.h"


std::vector<std::string>* ReadFileInArray(std::string fileName)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cerr << "Error opening file: " << std::strerror(errno) << std::endl;
		return nullptr;
	}

	std::vector<std::string>* array = new std::vector<std::string>;

	for (std::string line; std::getline(file, line);)
		array->push_back(line);

	file.close();

	return array;
}


int main()
{
	system("chcp 1251");

	int size;

	do {
		std::cout << "Enter size: ";
		std::cin >> size;
	} while (size <= 1 || size >= 10000);

	auto array =  ReadFileInArray("Data.txt");
	if (array == nullptr)
		return -1;

	HashTable hashTable(size);
	for (auto n : *array)
		hashTable.Insert(n);



	//std::string input = "";
	//do {
	//	std::cout << "Enter key: ";
	//	std::getline(std::cin, input);

	//	int res = hashTable.Search(input);
	//	if (res == NOT_FOUND)
	//		std::cout << "Not found.\n";
	//	else if (res == INVALID_KEY)
	//		std::cout << "Invalid key!\n";
	//	else 
	//		std::cout << "Hash position: " << res << std::endl;

	//} while (input != "end");

	hashTable.Print();

	char simb;
	std::cout << "Enter char: ";
	std::cin >> simb;

	hashTable.DeleteChar(simb);
	hashTable.Print();

	array->clear();
	//delete array;

	return 0;
}


//Постройте хеш - таблицу из слов произвольного текстового
//файла, задав ее размерность с экрана.Выведите построенную таблицу
//слов на экран.Осуществите поиск введенного слова.Выполните
//программу для различных размерностей таблицы и сравните число
//сравнений.Удалите все слова, начинающиеся на указанную букву,
//выведите таблицу.