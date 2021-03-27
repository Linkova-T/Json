
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <istream>
#include <locale>
#include <ostream>
#include <iostream>

#include "./json.hpp"

using nlohmann::json;

int main(int argc, char** argv)
{
	//std::filesystem::path path_input = "input.txt";
	std::filesystem::path path_output = "output.txt";

	//std::fstream fin(path_input.string(), std::ios::in);

	json j;
	/*fin >> j;
	fin.close();*/
	std::string name, surname;
	int age;
	//std::cout << std::setw(3) << j << std::endl;
	std::cin >> name;
	std::cin >> surname;
	std::cin >> age;
	j["name"] = name;
	j["surname"] = surname;
	j["age"] = age;
	/*for (auto iterator = j.begin(); iterator != j.end(); ++iterator)
	{
		std::cout << iterator.key() << " : " << iterator.value() << "\n";
	}
	std::cout << "\n";

	for (auto& element : j.items())
	{
		std::cout << element.key() << " : " << element.value() << "\n";
	}
	std::cout << "\n";*/

	for (auto& [key, value] : j.items()) // C++17 bindings
	{
		std::cout << key << " : " << value << "\n";
	}
	std::cout << "\n";

	std::fstream fout(path_output.string(), std::ios::out);
	fout << std::setw(3) << j;
	fout.close();

	system("pause");

	return EXIT_SUCCESS;
}