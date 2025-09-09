#include <iostream>
#include <deque>

int main() {
	int num;
	std::cin >> num;

	std::deque<int> dq;

	for (int i = 0; i < num; i++) {
		std::string command;
		std::cin >> command;
		if (command == "push_front") {
			int n;
			std::cin >> n;

			dq.push_front(n);
		}
		else if (command == "push_back") {
			int n;
			std::cin >> n;

			dq.push_back(n);
		}
		else if (command == "pop_front") {
			if (dq.empty()) {
				std::cout << "-1\n";
				continue;
			}
			std::cout << dq.front() << "\n";
			dq.pop_front();
		}
		else if (command == "pop_back") {
			if (dq.empty()) {
				std::cout << "-1\n";
				continue;
			}
			std::cout << dq.back() << "\n";
			dq.pop_back();
		}
		else if (command == "size") {
			std::cout << dq.size() << "\n";
		}
		else if (command == "empty") {
			if (dq.empty()) {
				std::cout << "1\n";
			}
			else {
				std::cout << "0\n";
			}
		}
		else if (command == "front") {
			if (dq.empty()) {
				std::cout << "-1\n";
				continue;
			}
			std::cout << dq.front() << '\n';
		}
		else if (command == "back") {
			if (dq.empty()) {
				std::cout << "-1\n";
				continue;
			}
			std::cout << dq.back() << '\n';
		}
	}

	return 0;
}