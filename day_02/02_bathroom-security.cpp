#include "02_bathroom-security.h"
#include <string>
#include <iostream>
#include <fstream>

void Day02::solve() {
	std::ifstream input_file("day_02/input.txt");
	std::string line;
	std::string keycode;
	int current_pos = 5;

	if (input_file.is_open()) {
		while (getline(input_file, line)) {
			// Traverse the input line
			for (int i = 0; i < line.size(); i++) {
				switch (line[i]) {
				case 'U':
					current_pos = (current_pos - 3 >= 1) ? current_pos - 3 : current_pos;
					break;
				case 'D':
					current_pos = (current_pos + 3 <= 9) ? current_pos + 3 : current_pos;
					break;
				case 'R':
					current_pos = ((current_pos + 1) % 3 == 1) ? current_pos : current_pos + 1;
					break;
				case 'L':
					current_pos = ((current_pos - 1) % 3 == 0) ? current_pos : current_pos - 1;
					break;
				default:
					break;
				}
			}

			// Store the correct key input
			keycode.push_back(current_pos + '0');
		}
	}

	std::cout << keycode;
}