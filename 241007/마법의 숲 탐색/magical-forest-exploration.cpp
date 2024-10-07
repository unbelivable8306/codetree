#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<queue>

using namespace std;

int map[75][72];
vector<tuple<int, int>> unit;
queue<tuple<int,int>> q;
int visited[75][72];
vector<tuple<int, int>> exit_set;
int R, C, K;
int num = 2;
int ans = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void init_map() {
	for (int i = 0; i <= R + 3; i++) {
		for (int j = 0; j <= C + 1; j++) {
			if (j == 0 || j == C + 1 || i == R + 3) {
				map[i][j] = 1;
			}
			else map[i][j] = 0;
		}
	}
}

void init_visited() {
	for (int i = 0; i <= R + 3; i++) {
		for (int j = 0; j <= C + 1; j++) {
			if (j == 0 || j == C + 1 || i == R + 3) {
				visited[i][j] = 1;
			}
			else visited[i][j] = 0;
		}
	}
}

void check_map() {
	for (int i = 0; i <= R + 3; i++) {
		for (int j = 0; j <= C + 1; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void check_tuple() {
	for (auto i : unit) {
		int x = get<0>(i);
		int y = get<1>(i);
		cout << "x : " << x << " " << "y : " << y << " " << "\n";
	}
}

void check_exit_set() {
	for (auto i : exit_set) {
		int x = get<0>(i);
		int y = get<1>(i);
		cout << "x : " << x << " " << "y : " << y << " " << "\n";
	}
}

bool contain(vector<tuple<int, int>> v, tuple<int, int> m) {
	for (auto i : v) {
		if (i == m) return true;
	}
	return false;
}



int bfs(int ri, int rj) {
	visited[ri][rj] = 1;
	q.push({ ri,rj });
	int mx_i = 0;
	while (!q.empty()) {
		tuple<int, int> v = q.front();
		q.pop();
		int ci = get<0>(v);
		int cj = get<1>(v);
		mx_i = max(mx_i, ci);
		for (int i = 0; i < 4; i++) {
			int nx = ci + dx[i];
			int ny = cj + dy[i];
			if (visited[nx][ny] == 0 && (map[ci][cj] == map[nx][ny] || (contain(exit_set, { ci,cj }) && map[nx][ny] > 1))) {
				q.push({ nx,ny });
				visited[nx][ny] = 1;
			}
		}
	}
	return mx_i - 2;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> K;
	for (int i = 0; i < K; i++) {
		int c, d;
		cin >> c >> d;
		tuple<int, int> m = make_tuple(c, d);
		unit.push_back(m);
	}
	init_map();
	//check_map();
	//check_tuple();
	for (auto i : unit) {
		int c = get<0>(i);
		int d = get<1>(i);
		int r = 1;
		while (1) {
			if (map[r + 1][c - 1] + map[r + 2][c] + map[r + 1][c + 1] == 0) {
				r++;
			}
			else if (map[r - 1][c - 1] + map[r][c - 2] + map[r + 1][c - 1] + map[r + 1][c - 2] + map[r + 2][c-1] == 0) {
				d = (d -1) % 4;
				r += 1;
				c -= 1;
			}
			else if (map[r - 1][c + 1] + map[r][c + 2] + map[r + 1][c + 1] + map[r + 1][c + 2] + map[r + 2][c + 1] == 0) {
				d = (d + 1) % 4;
				r += 1;
				c += 1;
			}
			else break;
		}
		if (r < 3) {
			init_map();
			exit_set.clear();
		}
		else {
			map[r][c] = num;
			map[r + 1][c] = num;
			map[r - 1][c] = num;
			map[r][c + 1] = num;
			map[r][c - 1] = num;
			num++;
			exit_set.push_back({ r + dx[d],c + dy[d] });
			ans += bfs(r, c);
		}
		//check_map();
		//check_exit_set();
		//cout << endl;
		init_visited();
		//cout << ans << " ";
	}
	cout << ans;
}