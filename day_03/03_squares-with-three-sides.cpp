#include "03_squares-with-three-sides.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

// Split a string based on a delimiter and push them into the provided vector
void split_by_and_remove_empty(const std::string &input, const std::string &delim, std::vector<std::string> &elems) {
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

void parse_list_to_int(const std::vector<std::string> &input, std::vector<int> &output) {
	for each (std::string element in input)	{
		output.push_back(std::stoi(element));
	}
}

void Day03::solve() {
	std::ifstream input("day_03/input.txt");

	if (input.is_open()) {
		std::string line;
		std::vector<std::string> sides;
		std::vector<int> sides_int;
		int valid_triangles_part1 = 0;
		int valid_triangles_part2 = 0;

		while (getline(input, line)) {
			split_by_and_remove_empty(line, "  ", sides);
		}
		parse_list_to_int(sides, sides_int);

		// Part 1
		for (size_t i = 0; i < sides_int.size(); i += 3)	{
			if (sides_int[i] + sides_int[i + 1] > sides_int[i + 2] &&
				sides_int[i + 1] + sides_int[i + 2] > sides_int[i] &&
				sides_int[i] + sides_int[i + 2] > sides_int[i + 1]) {
				valid_triangles_part1++;
			}
		}

		// Part 2
		for (size_t i = 0; i < sides_int.size(); i += 9) {
			for (size_t j = 0; j < 3; j++) {
				int index = i + j;
				if (sides_int[index] + sides_int[index + 1 * 3] > sides_int[index + 2 * 3] &&
					sides_int[index + 1 * 3] + sides_int[index + 2 * 3] > sides_int[index] &&
					sides_int[index] + sides_int[index + 2 * 3] > sides_int[index + 1 * 3]) {
					valid_triangles_part2++;
				}
			}
		}

		std::cout << "Part 1: " << valid_triangles_part1;
		std::cout << "\nPart 2: " << valid_triangles_part2;
	}
}