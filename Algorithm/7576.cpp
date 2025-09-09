#include <iostream>
#include <queue>

#define X first
#define Y second

int board[1002][1002];
int dx[4]{ -1, 0, 1, 0 };
int dy[4]{ 0, 1, 0, -1 };


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n, m;
	std::queue<std::pair<int, int>> Q;


	std::cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> board[i][j];
			if (board[i][j] == 1) {
				Q.push({ i, j });
			}
		}
	}

	while (!Q.empty()) {
		std::pair<int, int> cur = Q.front();
		Q.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (board[nx][ny] == 0) {
				board[nx][ny] = board[cur.X][cur.Y] + 1;
				Q.push({nx, ny});
				
			}
			
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {			
			if (board[i][j] == 0) {
				std::cout << "-1";
				return 0;
			}

			if (board[i][j] > max) {
				max = board[i][j];
			}
		}
	}

	std::cout << max - 1;
	

	return 0;
}