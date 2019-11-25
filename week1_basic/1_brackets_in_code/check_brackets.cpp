// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Bracket {
	Bracket(char type, int position) :
		type(type),
		position(position)
	{}

	bool Matchc(char c) {
		if (type == '[' && c == ']')
			return true;
		if (type == '{' && c == '}')
			return true;
		if (type == '(' && c == ')')
			return true;
		return false;
	}

	char type;
	int position;
};

int main() {
	std::string text;
	getline(std::cin, text);

	std::stack <Bracket> opening_brackets_stack;
	for (int position = 0; position < text.length(); ++position) {
		char next = text[position];
		Bracket currentBracket(next, position);

		if (next == '(' || next == '[' || next == '{') {
			// Process opening bracket, write your code here

			opening_brackets_stack.push(currentBracket);
		}

		if (next == ')' || next == ']' || next == '}') {
			// Process closing bracket, write your code here

			if (opening_brackets_stack.empty()) {
				opening_brackets_stack.push(currentBracket);
				break;
			}

			Bracket topBracket = opening_brackets_stack.top();
			if (topBracket.Matchc(next)) {
				opening_brackets_stack.pop();
			}
			else {
				opening_brackets_stack.push(currentBracket);
				break;
			}
		}
	}

	if (opening_brackets_stack.empty()) {
		printf("Success");
	}
	else {
		Bracket topBracket = opening_brackets_stack.top();
		printf("%d\n", topBracket.position + 1);
	}
	// Printing answer, write your code here

	return 0;
}