#include <iostream>
#include <list>
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::list<char> editor;

	std::string s;
	std::cin >> s;

	for (char i : s) {
		editor.push_back(i);
	}
	std::list<char>::iterator cursor = editor.end();



	int num;
	std::cin >> num;

	for (int i = 0; i < num; i++) {
		char command;
		std::cin >> command;

		switch (command) {
		case 'L':
			if (cursor != editor.begin()) {
				cursor--;
			}
			break;
		case 'D':
			if (cursor != editor.end()) {
				cursor++;
			}
			break;
		case 'B':
			if (cursor != editor.begin()) {
				cursor--;
				cursor = editor.erase(cursor);
			}
			break;
		case 'P':
			char add;
			std::cin >> add;
			editor.insert(cursor, add);
			break;
		}
	}

	for (char i : editor) {
		std::cout << i;
	}

	return 0;
}