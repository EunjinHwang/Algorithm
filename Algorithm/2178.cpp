#include <iostream>
#include <queue>
#define X first
#define Y second

std::string board[102];
int dist[102][102];
int dx[4] = { -1,0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> board[i];
	}

	std::queue<std::pair<int, int>> Q;
	Q.push({ 0, 0 });
	dist[0][0] = 1;
	while (!Q.empty()) {
		std::pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (dist[nx][ny] >= 1 || board[nx][ny] != '1') {
				continue;
			}
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
	std::cout << dist[n - 1][m - 1];
	


	return 0;
}