#include "03_squares-with-three-sides.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

// Split a string based on a delimiter and push them into the provided vector
void splitAndRemoveEmpty(const std::string &input, const std::string &delim, std::vector<std::string> &elems) {
	size_t index = 0;
	size_t next_delim_index;
	while ((next_delim_index = input.find(delim, index)) != std::string::npos) {
		std::string element = input.substr(index, next_delim_index - index);
		if (!element.empty()) {
			elems.push_back(input.substr(index, next_delim_index - index));
		}
		index += next_delim_index - index + delim.size();
	}
	elems.push_back(input.substr(index));
}

void Day03::solve() {
	std::ifstream input("day_03/input.txt");

	if (input.is_open()) {
		std::string line;
		std::vector<std::string> sides;
		int numberOfValidTriangles = 0;

		while (getline(input, line)) {
			splitAndRemoveEmpty(line, "  ", sides);
			if (std::stoi(sides[0]) + std::stoi(sides[1]) > std::stoi(sides[2]) && 
				std::stoi(sides[1]) + std::stoi(sides[2]) > std::stoi(sides[0]) && 
				std::stoi(sides[0]) + std::stoi(sides[2]) > std::stoi(sides[1])) {
				numberOfValidTriangles++;
			}
			sides.clear();
		}

		std::cout << numberOfValidTriangles;
	}
}