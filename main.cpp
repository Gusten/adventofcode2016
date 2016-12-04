#include <iostream>
#include "utilities\problem.h"
#include "day_01\01_no-time-for-a-taxicab.h"
#include "day_02\02_bathroom-security.h"
#include "day_03\03_squares-with-three-sides.h"

int main() {
	/*
	//Day 01
	Problem *day01 = new Day01();
	day01->solve();
	delete day01;

	//Day 02
	Problem *day02 = new Day02();
	day02->solve();
	delete day02;
	*/

	Problem *day03 = new Day03();
	day03->solve();
	delete day03;

	for (;;) {}
}