#include <iostream>
#include <queue>
#define X first
#define Y second

int board[502][502];
bool vis[502][502]{ false };
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> board[i][j];
		}
	}

	std::queue<std::pair<int, int>> Q;
	int pics = 0;
	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || board[i][j] != 1) {
				continue;
			}
			Q.push({ i, j });
			vis[i][j] = true;
			pics++;
			int area = 1;

			while (!Q.empty()) {
				std::pair<int, int> cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
						continue;
					}
					if (vis[nx][ny] || board[nx][ny] != 1) {
						continue;
					}
					vis[nx][ny] = true;
					Q.push({ nx, ny });
					area++;
				}

			}
			
			if (max < area) {
				max = area;
			}
		}
	}

	std::cout << pics << '\n' << max;

}