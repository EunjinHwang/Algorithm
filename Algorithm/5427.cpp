#include <iostream>
#include <queue>

#define X first
#define Y second

std::string board[1002];
int S[1002][1002];
int F[1002][1002];

int dx[4]{ -1, 0, 1, 0 };
int dy[4]{ 0, 1, 0, -1 };

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);


	int r, h, w;
	std::cin >> r;



	for (int n = 0; n < r; n++) {

		std::queue<std::pair<int, int>> SQ;
		std::queue<std::pair<int, int>> FQ;
		bool escape = false;
		std::cin >> w >> h;
		for (int i = 0; i < h; i++) {
			std::cin >> board[i];
		}

		for (int i = 0; i < h; i++) {
			std::fill(S[i], S[i] + w, -1);
			std::fill(F[i], F[i] + w, -1);
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '*') {
					FQ.push({ i, j });
					F[i][j] = 0;
				}

				if (board[i][j] == '@') {
					SQ.push({ i, j });
					S[i][j] = 0;
				}
			}
		}

		while (!FQ.empty()) {
			std::pair<int, int> cur = FQ.front(); FQ.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					continue;
				}

				if (board[nx][ny] == '#') {
					continue;
				}

				if (F[nx][ny] != -1) {
					continue;
				}

				if (F[nx][ny] == -1) {
					F[nx][ny] = F[cur.X][cur.Y] + 1;
					FQ.push({ nx, ny });

				}
			}
		}

		while (!SQ.empty() && !escape) {
			std::pair<int, int> cur = SQ.front(); SQ.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					std::cout << S[cur.X][cur.Y] + 1 << '\n';
					escape = true;
					break;
				}

				if (board[nx][ny] == '#') {
					continue;
				}

				if (S[nx][ny] != -1) {
					continue;
				}

				if (F[nx][ny] != -1 && F[nx][ny] <= S[cur.X][cur.Y] + 1) {
					continue;
				}
				S[nx][ny] = S[cur.X][cur.Y] + 1;
				SQ.push({ nx, ny });
			}
		}

		if (!escape) std::cout << "IMPOSSIBLE\n";
	}

	return 0;
}