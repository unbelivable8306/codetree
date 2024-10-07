#include<iostream>
#include<queue>
#include<algorithm>

#define MAX_L 70

using namespace std;

int R, C, K;
int map[MAX_L + 3][MAX_L];
int dy[4] = { 0, 1, 0, -1 }, dx[4] = { -1, 0, 1, 0 };
bool Exit[MAX_L + 3][MAX_L];
int ans;

bool in_range(int x, int y) {
	return 3 <= x && x < R + 3 && 0 <= y && y < C;
}

bool cango(int x, int y) {
	bool flag = 0 <= y - 1 && y + 1 < C && x + 1 < R + 3;
	flag = flag && map[x - 1][y - 1] == 0;
	flag = flag && map[x - 1][y] == 0;
	flag = flag && map[x - 1][y + 1] == 0;
	flag = flag && map[x][y - 1] == 0;
	flag = flag && map[x][y] == 0;
	flag = flag && map[x][y + 1] == 0;
	flag = flag && map[x + 1][y] == 0;
	return flag;
}

void reset_map() {
	for (int i = 0; i < R + 3; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = 0;
			Exit[i][j] = false;
		}
	}
}

int bfs(int x, int y) {
	int result = x;
	queue<pair<int, int>> q;
	bool visited[MAX_L + 3][MAX_L];
	for (int i = 0; i < R + 3; i++) {
		for (int j = 0; j < C; j++) {
			visited[i][j] = false;
		}
	}
	q.push(make_pair(x,y)); // make_pair 쓸 때 조심하기
	visited[x][y] = true;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (in_range(nx, ny) && !visited[nx][ny] && (map[nx][ny] == map[cur.first][cur.second] || (map[nx][ny] != 0 && Exit[cur.first][cur.second]))) {
				q.push(make_pair(nx,ny));
				visited[nx][ny] = true;
				result = max(result, nx);
			}
		}
	}
	//cout << result << endl;
	return result;
}

void down(int x, int y, int d, int id) {
	if (cango(x + 1, y)) {
		down(x + 1, y, d, id);
	}
	else if (cango(x + 1, y - 1)) {
		down(x + 1, y - 1, (d+3)%4, id);
	}
	else if (cango(x + 1, y + 1)) {
		down(x + 1, y + 1, (d+1)%4, id);
	}
	else {
		if (x<3) {
			reset_map();
		}
		else {
			map[x][y] = id;
			for (int k = 0; k < 4; k++) {
				map[x + dx[k]][y + dy[k]] = id;
			}
			Exit[x + dx[d]][y + dy[d]] = true;
			ans += bfs(x, y) - 3 + 1;
		}
	}
}

int main() {
	cin >> R >> C >> K;
	for (int id = 1; id <= K; id++) {
		int y, d;
		cin >> y >> d;
		y--;
		down(0, y, d, id);
		/*
		for (int j = 0; j < R + 3; j++) {
			for (int k = 0; k < C; k++) {
				cout << map[j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
		
		/*
		for (int j = 0; j < R + 3; j++) {
			for (int k = 0; k < C; k++) {
				cout << Exit[j][k] << " ";
			}
			cout << endl;
		}
		*/
		
	}
	cout << ans << "\n";
}