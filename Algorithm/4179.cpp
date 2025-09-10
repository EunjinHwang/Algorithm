#include <iostream>
#include <queue>
#include <cstring>
#define X first
#define Y second

int dx[4]{ -1, 0, 1, 0 };
int dy[4]{ 0, 1, 0, -1 };

std::string board[1002];
int F[1002][1002];
int J[1002][1002];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int R, C;
	std::cin >> R >> C;
	
	std::queue<std::pair<int, int>> JQ;
	std::queue<std::pair<int, int>> FQ;

	memset(F, -1, sizeof(F));
	memset(J, -1, sizeof(J));

	for (int i = 0; i < R; i++) {
		std::cin >> board[i];		
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'F') {
				F[i][j] = 0;
				FQ.push({ i,j });
			}

			if (board[i][j] == 'J') {
				J[i][j] = 0;
				JQ.push({ i,j });
			}
		}
	}

	while (!FQ.empty()) {
		std::pair<int, int> cur = FQ.front();
		FQ.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				continue;
			}
			if (board[nx][ny] == '#' || F[nx][ny] != -1) {
				continue;
			}

			F[nx][ny] = F[cur.X][cur.Y] + 1;
			FQ.push({ nx, ny });
		}
	}

	while (!JQ.empty()) {
		std::pair<int, int> cur = JQ.front();
		JQ.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				continue;
			}
			if (board[nx][ny] == '#' || J[nx][ny] != -1) {
				continue;
			}

			J[nx][ny] = J[cur.X][cur.Y] + 1;
			JQ.push({ nx, ny });
		}
	}

	int ans = 10000;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (i == 0 || i == R - 1 || j == 0 || j == C - 1) {
				if (J[i][j] != -1 && (F[i][j] == -1 || J[i][j] < F[i][j])) {
					ans = std::min(ans, J[i][j] + 1);
				}
			}
		}
	}

	if (ans == 10000) {
		std::cout << "IMPOSSIBLE"; 
	}
	else {
		std::cout << ans;
	}
	return 0;
}