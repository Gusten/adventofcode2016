#pragma once

class Problem {
public:
	virtual ~Problem() {}
	virtual void solve() = 0;
};