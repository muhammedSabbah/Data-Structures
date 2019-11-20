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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
