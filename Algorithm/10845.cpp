#include <iostream>
#include <queue>

int main() {
	int num;
	std::cin >> num;
	std::queue<int> Q;

	for (int i = 0; i < num; i++) {
		std::string command;
		std::cin >> command;

		if (command == "push") {
			int n;
			std::cin >> n;
			Q.push(n);
		}
		else if (command == "front") {
			if (Q.empty()) {
				std::cout << "-1\n";
				continue;
			}
			std::cout << Q.front()<< "\n";
		}
		else if (command == "back") {
			if (Q.empty()) {
				std::cout << "-1\n";
				continue;
			}
			std::cout << Q.back() << "\n";
		}
		else if (command == "size") {
			std::cout << Q.size() << "\n";
		}
		else if (command == "empty") {
			if (Q.empty()) {
				std::cout << "1\n";
			}
			else {
				std::cout << "0\n";
			}
		}
		else if (command == "pop") {
			if (Q.empty()) {
				std::cout << "-1\n";
				continue;
			}
			std::cout << Q.front() << "\n";
			Q.pop();
		}
	}
	return 0;
}