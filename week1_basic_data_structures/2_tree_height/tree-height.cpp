#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
using namespace std;

class Node;

class Node {
public:
	int key;
	Node *parent;
	std::vector<Node *> children;

	Node() {
		this->parent = NULL;
	}

	void setParent(Node *theParent) {
		parent = theParent;
		parent->children.push_back(this);
	}
};

int height(Node *root)
{
	int len = root->children.size();
	if (len == 0)
		return 1;
	int maxHeight = 1;
	for (int i = 0; i < len; i++)
	{
		int number = height(root->children[i]) + 1;
		maxHeight = max(maxHeight, number);
	}
	return maxHeight;
}
int main_with_large_stack_space() {
	std::ios_base::sync_with_stdio(0);
	int n;
	std::cin >> n;

	std::vector<Node> nodes;
	nodes.resize(n);
	int index = 0;
	for (int child_index = 0; child_index < n; child_index++) {
		int parent_index;
		std::cin >> parent_index;
		if (parent_index == -1)
			index = child_index;
		if (parent_index >= 0)
			nodes[child_index].setParent(&nodes[parent_index]);
		nodes[child_index].key = child_index;
	}

	// Replace this code with a faster implementation
	int maxHeight = 0;
	maxHeight = height(&nodes[index]);

	std::cout << maxHeight << std::endl;
	return 0;
}

int main(int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
	// Allow larger stack space
	const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
		if (rl.rlim_cur < kStackSize)
		{
			rl.rlim_cur = kStackSize;
			result = setrlimit(RLIMIT_STACK, &rl);
			if (result != 0)
			{
				std::cerr << "setrlimit returned result = " << result << std::endl;
			}
		}
	}

#endif
	return main_with_large_stack_space();
}
