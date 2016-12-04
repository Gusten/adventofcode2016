#include "04_security_through_obscurity.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

namespace {
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
}

void Day04::solve() {
	std::ifstream input("day_04/input.txt");

	if (input.is_open()) {
		std::string line;
		std::vector<std::string> line_elements;

		while (getline(input, line)) {
			split_by_and_remove_empty(line, "-", line_elements);
		}
	}
}