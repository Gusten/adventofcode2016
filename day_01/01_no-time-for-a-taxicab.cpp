#include "01_no-time-for-a-taxicab.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

void Day01::solve() {
	std::string input = "R3, L5, R2, L1, L2, R5, L2, R2, L2, L2, L1, R2, L2, R4, R4, R1, L2, L3, R3, L1, R2, L2, L4, R4, R5, L3, R3, L3, L3, R4, R5, L3, R3, L5, L1, L2, R2, L1, R3, R1, L1, R187, L1, R2, R47, L5, L1, L2, R4, R3, L3, R3, R4, R1, R3, L1, L4, L1, R2, L1, R4, R5, L1, R77, L5, L4, R3, L2, R4, R5, R5, L2, L2, R2, R5, L2, R194, R5, L2, R4, L5, L4, L2, R5, L3, L2, L5, R5, R2, L3, R3, R1, L4, R2, L1, R5, L1, R5, L1, L1, R3, L1, R5, R2, R5, R5, L4, L5, L5, L5, R3, L2, L5, L4, R3, R1, R1, R4, L2, L4, R5, R5, R4, L2, L2, R5, R5, L5, L2, R4, R4, L4, R1, L3, R1, L1, L1, L1, L4, R5, R4, L4, L4, R5, R3, L2, L2, R3, R1, R4, L3, R1, L4, R3, L3, L2, R2, R2, R2, L1, L4, R3, R2, R2, L3, R2, L3, L2, R4, L2, R3, L4, R5, R4, R1, R5, R3";
	
	unsigned int direction = 0;
	int pos[] = { 0, 0 };
	int axis;
	int steps;
	int steps_end_index;
	int steps_string_length;
	std::vector<std::tuple<int, int>> visited_positions;
	std::tuple<int, int> headquarters_pos;
	bool headquarters_found = false;

	for (int i = 0; i < input.size(); i) {
		// Find which axis to move along
		direction = (input[i] == 'R') ? direction + 1 : direction - 1;
		axis = direction % 2;

		// Find number of steps we are going to walk
		steps_end_index = input.find_first_of(',', ++i);
		steps_string_length = (steps_end_index > 0) ? steps_end_index - i : input.size() - i;
		steps = std::stoi(input.substr(i, steps_string_length));

		// Slow-step only if we haven't already found bunny HQ
		if (!headquarters_found) {
			// Add coordinates we pass to visited
			// We need to check each coordinate we pass, not only when we stop at an intersection
			for (int j = 0; j < steps; j++) {
				pos[axis] = (direction & 2) ? pos[axis] - 1 : pos[axis] + 1;
				std::tuple<int, int> current_location = std::make_tuple(pos[0], pos[1]);
				if (std::find(visited_positions.begin(), visited_positions.end(), current_location) != visited_positions.end()) {
					headquarters_pos = current_location;
					headquarters_found = true;
				}
				else {
					visited_positions.push_back(current_location);
				}
			}
		}
		// If headquarter is already found, go quick
		else {
			pos[axis] = (direction & 2) ? pos[axis] - steps : pos[axis] + steps;
		}

		i += steps_string_length + 2;
	}

	std::cout << "Part 1:\nX-coordinate: " << pos[0]
			  << "\nY-coordinate: " << pos[1]
		      << "\nTotal distance: " << abs(pos[0]) + abs(pos[1]);

	std::cout << "\n\nPart 2:\nX-coordinate: " << std::get<0>(headquarters_pos) 
			  << "\nY-coordinate: " << std::get<1>(headquarters_pos) 
			  << "\nTotal distance: " << abs(std::get<0>(headquarters_pos)) + abs(std::get<1>(headquarters_pos));
}

