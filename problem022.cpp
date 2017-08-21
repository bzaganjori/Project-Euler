#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static void populate_array(string file_name, vector <std::string> names) 
{
	std::string current;
	char c;
	
	std::ifstream input(file_name);
	
	while (input.get(c)) 
	{
		if (c == ',')
		{
			current = "";
			names.push_back(current);
		}
		else if (c == '"')
		{
			continue;
		}
		else
		{
			current.push_back(c);
		}
	}
	std::sort(names.begin(), names.end());
	
	for (std::vector<std::string>::const_iterator i = names.begin(); i != names.end(); ++i)
	{
		std:cout << *i << ' ';
	}
	
	input.close();
}

int main() 
{
	vector <string> names;
	std::cout << "Starting program...\n";
	
	populate_array("p022names.txt", names);
	
	std::cout << "Ending program.\n";
	return 0;
}
