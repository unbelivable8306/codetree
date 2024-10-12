#define MAX_N 15 // 격자 크기
#define MAX_C 195 // 베이스 캠프 갯수
#define MAX_S 30 // 사람 수 최대

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

bool check_s[MAX_S + 1]; // 사람이 편의점 도착했으면 1로, 아니면 0으로
bool in_board[MAX_S + 1]; // 사람이 보드위에 있는지 없는지
int board[MAX_N + 1][MAX_N + 1]; // 사람이 도착할 때 마다 1하나씩 심어서 못가게 만들기
pair<int, int> board_people[MAX_S + 1]; //보드위에 들어온 사람들 위치 저장 -> 계속 갱신해줘야함
pair<int, int> store[MAX_S + 1]; // 상점 위치 저장 
vector<pair<int, pair<int, int>>> camp; // 캠프 (편의점과의 거리, x좌표, y좌표)

int Time = 1; // 시간의 경과
int ans; // 답 저장 공간
int n, m;

bool check(); // check 배열 탐색하면서, 다 도착했는지 안도착했는지 확인
bool board_check(int num); // 보드에 들어왔는지 안들어왔는지 확인
bool r_check(int num); // 이 번호 사람이 도착했는지 안했는지 확인
void bfs(int r, int c, int num); // 이동하기
void find_camp(int r, int c);
bool in_range(int x, int y);
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b);

bool check() { // 통과하지 못한 사람 한 사람이라도 있으면 0
	bool flag = true;
	for (int i = 1; i <= m; i++) {
		if (check_s[i] == 0) {
			flag = false;
		}
	}
	return flag;
}

bool board_check(int num) {
	return in_board[num] == 1;
}

bool r_check(int num) {
	return check_s[num] == 1;
}

bool in_range(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void bfs(int r, int c, int num) {
	int MIN = 100000;
	pair<int, int> MIN_XY;
	for (int i = 0; i < 4; i++) {
		int newr = r + dx[i];
		int newc = c + dy[i];
		int dist = abs(newr - store[num].first) + abs(newc - store[num].second);
		if (!in_range(newr, newc)) continue;
		if (board[newr][newc] != 0) continue;
		if (dist < MIN) {
			MIN = dist;
			MIN_XY = make_pair(newr, newc);
		}
	}
	board_people[num] = MIN_XY;
	if (MIN_XY == store[num]) {
		check_s[num] = 1;
		board[MIN_XY.first][MIN_XY.second] = 1;
	}
}

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	if (a.second.first != b.second.first) {
		return a.second.first < b.second.first;
	}
	if (a.second.second != b.second.second) {
		return a.second.second < b.second.second;
	}
}

void find_camp(int r, int c) {
	int decide_x=0;
	int decide_y=0;
	for (int i = 0; i < camp.size(); i++) {
		camp[i].first = abs(r - camp[i].second.first) + abs(c - camp[i].second.second);
	}
	sort(camp.begin(), camp.end(), cmp);
	for (int i = 0; i < camp.size(); i++) {
		int x = camp[i].second.first;
		int y = camp[i].second.second;
		if (board[x][y] == 0) {
			decide_x = x;
			decide_y = y;
			break;
		}
	}
	board[decide_x][decide_y] = 1;
	board_people[Time].first = decide_x;
	board_people[Time].second = decide_y;

}

void print_people() {
	for (int i = 1; i <= m; i++) {
		cout << i << "번 사람" << endl;
		cout << "(" << board_people[i].first << "," << board_people[i].second << ")" << endl;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> store[i].first >> store[i].second;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == 1) {
				camp.push_back({ 0,{i,j} });
				board[i][j] = 0;
			}
		}
	}
	while (!check()) {
		for (int i = 1; i <= m; i++) {
			if (!board_check(i) || r_check(i)) continue; // 
			bfs(board_people[i].first, board_people[i].second,i);
		}
		pair<int, int> m = store[Time];
		in_board[Time] = true;
		find_camp(store[Time].first, store[Time].second);
		
		//cout << Time << "초 경과" << endl;
		//print_people();
		Time++;
	}
	cout << Time-1;
}