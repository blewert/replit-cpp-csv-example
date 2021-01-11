#include <iostream>
#include <fstream>
#include <vector>
//---
#include "Item.h"
#include "main.h"


//The lines for the file, the items
std::vector<std::string>* lines = new std::vector<std::string>();
std::vector<Item>* items = new std::vector<Item>();

int main() 
{
	//Open the file
	std::ifstream csvFile;
  csvFile.open("data/items.csv", std::ios::in); 

	//Read into lines
	ReadAllLinesInto(lines, csvFile);

	//Parse lines
	ParseAllLines(lines, items);

	//Print Items
	for(const auto& item : *items)
		printf("%s, £%.2f, %c\n", item.name.c_str(), item.price, item.category);

	//Close it
	csvFile.close();
}