#include <iostream>
#include <stack>

const int MX = 1000005;
int stack[MX];
int position = -1;

void push(int num);
void pop();
void top();
int size();
void empty();

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int num;
	std::cin >> num;
	for (int i = 0; i < num; i++) {
	std::string command;
	std::cin >> command;
		if (command == "push") {
			int n;
			std::cin >> n;
			push(n);
		}
		else if (command == "pop") {
			pop();
		}
		else if (command == "top") {
			top();
		}
		else if (command == "size") {
			std::cout << size() << '\n';
		}
		else if (command == "empty") {
			empty();
		}
	}
	
	return 0;
}

void push(int num) {
	stack[++position] = num;
}

void pop() {
	if (position == -1) {
		std::cout << "-1\n";
		return;
	}
	std::cout << stack[position--] << '\n';
	
}

void top() {
	if (position == -1) {
		std::cout << "-1\n" ;
		return;
	}
	std::cout <<  stack[position] << '\n';
}

void empty() {
	if (position == -1) {
		std::cout << "1\n";
		return;
	}

	std::cout << "0\n";
}

int size() {
	return position + 1;
}
