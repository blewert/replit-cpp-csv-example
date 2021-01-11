/*!
 * \brief Reads all lines from a CSV file into a vec<str>* object.
 *
 * \param vec The dst vector to save into.
 * \param stream The src file stream to read from.
*/
void ReadAllLinesInto(std::vector<std::string>*& vec, std::ifstream& stream)
{
	if(stream.is_open())
	{
		//Is the file open? Ok. Make a temporary string:
		std::string str;
		
		while(stream.good())
		{
			//While the file has stuff, get the line, push it into 
			//the list of strings 
			std::getline(stream, str);
			vec->push_back(str);
		}
	}
}


/*!
 * \brief Parses an Item object from a list of words, and returns it.
 *
 * \param words The src words to pass in.
 * \return An Item value, parsed from the list of words.
*/
Item ParseItemFromWords(const std::vector<std::string>& words)
{
	//Just set all variables up
	std::string name = words[0];
	float price = std::stof(words[1]);
	char category = words[2][0];

	//Make a new item, return it (be aware this is not returning
	//a reference -- you could return a ref in the future)
	Item item(name, price, category);
	return item;
}


/*!
 * \brief Parses all lines within a vec<str>* object and builds a vec<Item>* value from them.
 *
 * \param lines The src lines read from the file.
 * \param items The dst items to save into.
 * \return An Item value, parsed from the list of words.
*/
void ParseAllLines(std::vector<std::string>*& lines, std::vector<Item>*& items)
{
	for(auto& line : *lines)
	{
		//The temporary build string, and the list of temporary
		//words for this line
		std::string buildString = "";
		std::vector<std::string> words = std::vector<std::string>();

		for(int i = 0; line[i] != 0; i++)
		{
			//Run to the end of the string
			//..

			if(line[i+1] == 0)
			{
				//Is the next character the zero-terminator? If so,
				//quickly push it and skip
				words.push_back(std::string(1, line[i]));
				continue;
			}

			if(line[i] == ',')
			{
				//It's a comma: push it
				words.push_back(buildString);
				buildString = "";
			}
			else
				buildString += line[i];
		}

		//Parse the item from the words
		Item item = ParseItemFromWords(words);
		
		//And add it to the list of items
		items->push_back(item);
	}
}
