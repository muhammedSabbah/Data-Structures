#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Query {
	string type, s;
	size_t ind;
};

class QueryProcessor {
	int bucket_count;
	// store all strings in one vector
	vector<vector<string>> table;
	size_t hash_func(const string& s) const {
		static const size_t multiplier = 263;
		static const size_t prime = 1000000007;
		unsigned long long hash = 0;
		for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
			hash = (hash * multiplier + s[i]) % prime;
		return hash % bucket_count;
	}

public:
	explicit QueryProcessor(int bucket_count) : bucket_count(bucket_count) { 
		for (int i = 0; i < bucket_count; i++){
			vector<string> v1;
			table.push_back(v1);
		}
	}

	Query readQuery() const {
		Query query;
		cin >> query.type;
		if (query.type != "check")
			cin >> query.s;
		else
			cin >> query.ind;
		return query;
	}

	void writeSearchResult(bool was_found) const {
		cout << (was_found ? "yes\n" : "no\n");
	}

	void processQuery(const Query& query) {
		if (query.type == "check") {
			// use reverse order, because we append strings to the end
			vector<string> ele = table.at(query.ind);
			for (auto it = ele.rbegin(); it != ele.rend(); ++it)
			{
				cout << *it << " ";
			}
			cout << "\n";
		}
		else {
			int index = hash_func(query.s);
			vector<string>::iterator it = find(table.at(index).begin(), table.at(index).end(), query.s);
			if (query.type == "find")
				writeSearchResult(it != table.at(index).end());
			else if (query.type == "add") {
				if (it == table.at(index).end())
					table.at(index).push_back(query.s);
			}
			else if (query.type == "del") {
				if (it != table.at(index).end())
					table.at(index).erase(it);
			}
		}
	}

	void processQueries() {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			processQuery(readQuery());
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int bucket_count;
	cin >> bucket_count;
	QueryProcessor proc(bucket_count);
	proc.processQueries();
	return 0;
}
