#include<iostream>
using namespace std;

#define MAX_N 10

pair<int, int> Exit; // 출구좌표
pair<int, int> man[11]; // 참가자 좌표

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M, K; // N : 미로의 크기, M : 참가자 수, K : 게임시간
int board[MAX_N + 1][MAX_N + 1]; // 미로
int map[MAX_N + 1][MAX_N + 1]; // 사람 좌표
int Dist[MAX_N + 1];
int escape[MAX_N + 1];

void debug() {
	cout << "\n";
	cout << "This is board" << " \n";
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "This is 출구 좌표" << " \n";
	cout << "\n";
	cout << "(" << Exit.first << "," << Exit.second << ")" << "\n";
	cout << "\n";
	cout << "This is 참가자 좌표" << " \n";
	cout << "\n";
	for (int i = 1; i <= M; i++) {
		cout << i << "번 참가자 : " << "(" << man[i].first << "," << man[i].second << ")" << "\n";
	}
	cout << "\n";
}

bool in_range(int x, int y) {
	return 1 <= x && x <= N && 1 <= y && y <= N;
}

void rotate(int x, int y, int length) {
	int rotated[MAX_N + 1][MAX_N + 1];
	for (int i = 0; i < length+1; i++) {
		for (int j = 0; j < length+1; j++) {
			rotated[j][length+1 - 1 - i] = board[x + i][y + j];
		}
	}
	for (int i = 0; i < length+1; i++) {
		for (int j = 0; j < length+1; j++) {
			board[x + i][y + j] = rotated[i][j];
		}
	}
	// 참여자 좌표 확인 및 회전
	for (int i = 1; i <= M; i++) {
		if (x <= man[i].first && man[i].first < x + length+1 && 0 <= man[i].second && man[i].second < y + length+1) {
			int m = man[i].first - x;
			int n = man[i].second - y;
			man[i].first = x+n;
			man[i].second = y + length+1 - m - 1;
		}
	}
	// exit 좌표 회전
	int m = Exit.first - x;
	int n = Exit.second - y;
	Exit.first = x + n;
	Exit.second = y + length+1 - m - 1;

	for (int i = x; i < x + length+1; i++) {
		for (int j = y; j < y + length+1; j++) {
			if (board[i][j] != 0) board[i][j]--;
		}
	}
}

bool out(int num) {
	return escape[num] == 1;
}

int main() {
	// 입력
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> man[i].first >> man[i].second;
	}
	cin >> Exit.first >> Exit.second;

	// 게임 시작
	// 가장 가까운 곳으로 이동
	for (int z = 1; z <= K; z++) {
		pair<int, pair<int, int>> closet;
		int Distance = 10000;
		for (int i = 1; i <= M; i++) {
			if (out(i) == 1) continue; //출구밖으로 나갔으면 넘기기
			int prevx = man[i].first, prevy = man[i].second;
			int MIN = abs(Exit.first - man[i].first) + abs(Exit.second - man[i].second);
			for (int j = 0; j < 4; j++) {
				int newx = prevx + dx[j];
				int newy = prevy + dy[j];
				int dist = abs(Exit.first - newx) + abs(Exit.second - newy);
				if (!in_range(newx, newy)) continue;
				if (board[newx][newy] != 0 || dist > MIN) continue;
				if (dist < MIN) {
					MIN = dist;
					man[i].first = newx, man[i].second = newy;
				}
				else if (dist == MIN && (j==0 || j ==2)) {
					man[i].first = newx, man[i].second = newy;
				}
			}
			if (MIN == 0) {
				escape[i] = true;
			}
			else if (MIN < Distance) {
				closet.second.first = man[i].first;
				closet.second.second = man[i].second;
				closet.first = i;
				Distance = MIN;
			}
			if (prevx != man[i].first || prevy != man[i].second) Dist[i]++;
		}
		bool break_flag = 1;
		for (int i = 1; i <= M; i++) {
			if (escape[i] != 1) break_flag = 0;
		}
		if (break_flag == 1) break;
		//cout << closet.first << " " << closet.second.first << " " << closet.second.second << " " << endl;
		// 회전 좌측 상단 점 찾기
		int length = max(abs(Exit.first - closet.second.first), abs(Exit.second - closet.second.second));
		bool exitflag = false;
		for (int i = max(Exit.first, closet.second.first) - length; i <= max(Exit.first, closet.second.first); i++) {
			for (int j = max(Exit.second, closet.second.second) - length; j <= max(Exit.second, closet.second.second); j++) {
				if (in_range(i, j)) {
					//cout << i << " " << j << " " << length << endl;
					rotate(i, j,length);
					exitflag = true;
					break;
				}
			}
			if (exitflag) break;
		}
		
	}
	int sum = 0;
	for (int i = 1; i <= M; i++) {
		//cout << Dist[i] << " ";
		sum += Dist[i];
	}
	cout << sum << "\n";
	cout << Exit.first << " " << Exit.second;
}