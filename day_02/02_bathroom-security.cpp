#include "02_bathroom-security.h"
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <tuple>

typedef std::tuple<int, int> position;

// Define a hasher that is capable of hashing our position typedef
struct PosHasher {
	std::size_t operator()(const position& k) const
	{
		using std::size_t;
		using std::hash;
		using std::string;

		int custom_hash = 17;
		custom_hash = custom_hash * 31 + std::hash<int>()(std::get<0>(k));
		custom_hash = custom_hash * 31 + std::hash<int>()(std::get<1>(k));
		return custom_hash;
	}
};

void Day02::solve() {
	std::ifstream input_file("day_02/input.txt");

	if (input_file.is_open()) {
		std::string line;

		// Part 1 variables
		int current_pos_part1 = 5;
		std::string keycode_part1;

		// Part 2 variables
		std::unordered_map<position, char, PosHasher> valid_positions;
		valid_positions[std::make_tuple<int, int>(0, 2)] = '1';
		valid_positions[std::make_tuple<int, int>(-1, 1)] = '2';
		valid_positions[std::make_tuple<int, int>(0, 1)] = '3';
		valid_positions[std::make_tuple<int, int>(1, 1)] = '4';
		valid_positions[std::make_tuple<int, int>(-2, 0)] = '5';
		valid_positions[std::make_tuple<int, int>(-1, 0)] = '6';
		valid_positions[std::make_tuple<int, int>(0, 0)] = '7';
		valid_positions[std::make_tuple<int, int>(1, 0)] = '8';
		valid_positions[std::make_tuple<int, int>(2, 0)] = '9';
		valid_positions[std::make_tuple<int, int>(-1, -1)] = 'A';
		valid_positions[std::make_tuple<int, int>(0, -1)] = 'B';
		valid_positions[std::make_tuple<int, int>(1, -1)] = 'C';
		valid_positions[std::make_tuple<int, int>(0, -2)] = 'D';
		int current_pos_part2[] = { 0, -2 };
		int column_index = 0;
		int row_index = 2;
		std::string keycode_part2;

		while (getline(input_file, line)) {
			// Part 1 solution:
			// Traverse the input line
			for (int i = 0; i < line.size(); i++) {
				switch (line[i]) {
				case 'U':
					current_pos_part1 = (current_pos_part1 - 3 >= 1) ? current_pos_part1 - 3 : current_pos_part1;
					break;
				case 'D':
					current_pos_part1 = (current_pos_part1 + 3 <= 9) ? current_pos_part1 + 3 : current_pos_part1;
					break;
				case 'R':
					current_pos_part1 = ((current_pos_part1 + 1) % 3 == 1) ? current_pos_part1 : current_pos_part1 + 1;
					break;
				case 'L':
					current_pos_part1 = ((current_pos_part1 - 1) % 3 == 0) ? current_pos_part1 : current_pos_part1 - 1;
					break;
				default:
					break;
				}
			}

			// Part 2 solution:
			// Traverse the input line
			for (int i = 0; i < line.size(); i++) {
				switch (line[i]) {
				case 'U':
					if (valid_positions[std::make_tuple(current_pos_part2[0], current_pos_part2[1] + 1)] != '\0') {
						current_pos_part2[1]++;
					}
					break;
				case 'D':
					if (valid_positions[std::make_tuple(current_pos_part2[0], current_pos_part2[1] - 1)] != '\0') {
						current_pos_part2[1]--;
					}
					break;
				case 'R':
					if (valid_positions[std::make_tuple(current_pos_part2[0] + 1, current_pos_part2[1])] != '\0') {
						current_pos_part2[0]++;
					}
					break;
				case 'L':
					if (valid_positions[std::make_tuple(current_pos_part2[0] - 1, current_pos_part2[1])] != '\0') {
						current_pos_part2[0]--;
					}
					break;
				default:
					break;
				}
			}

			// Store the correct key input
			keycode_part1.push_back(current_pos_part1 + '0');
			keycode_part2.push_back(valid_positions[std::make_tuple(current_pos_part2[0], current_pos_part2[1])]);
		}

		std::cout << "Part 1:\nKeycode: " << keycode_part1;
		std::cout << "\n\nPart 2:\nKeycode: " << keycode_part2;
	}
}