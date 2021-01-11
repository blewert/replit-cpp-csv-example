#pragma once
#include <iostream>

/*!
 * \brief Class to encapsulate an item within the CSV file.
*/
class Item
{
public:

	/*!
	* \brief Constructs a new item from a name, price and category.
	*/
	Item(const std::string& item, const float price, const char category) : name(item), price(price), category(category) { }

	/*!
	* \brief Destructor.
	*/
	~Item();

	//..
	std::string name;
	float price;
	char category;
};