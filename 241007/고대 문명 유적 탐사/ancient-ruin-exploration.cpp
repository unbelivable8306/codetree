#include<iostream>
#include<queue>

#define N_large 5
#define N_small 3

using namespace std;

class Board {
public :
	int arr[N_large][N_large];
private:
	bool in_range(int x, int y) {
		return 0 <= x && x < N_large && 0 <= y && y < N_large;
	}
public:
	Board() {
		for (int i = 0; i < N_large; i++) {
			for (int j = 0; j < N_large; j++) {
				arr[i][j] = 0;
			}
		}
	}
	Board* Rotate(int sx, int sy, int cnt) {
		Board* result = new Board();
		for (int i = 0; i < N_large; i++) {
			for (int j = 0; j < N_large; j++) {
				result->arr[i][j] = arr[i][j];
			}
		}
		for (int k = 0; k < cnt; k++) {
			int tmp = result->arr[sx + 0][sy + 2];
			result->arr[sx + 0][sy + 2] = result->arr[sx + 0][sy + 0];
			result->arr[sx + 0][sy + 0] = result->arr[sx + 2][sy + 0];
			result->arr[sx + 2][sy + 0] = result->arr[sx + 2][sy + 2];
			result->arr[sx + 2][sy + 2] = tmp;
			tmp = result->arr[sx + 1][sy + 2];
			result->arr[sx + 1][sy + 2] = result->arr[sx+0][sy + 1];
			result->arr[sx + 0][sy + 1] = result->arr[sx + 1][sy+0];
			result->arr[sx + 1][sy + 0] = result->arr[sx + 2][sy + 1];
			result->arr[sx + 2][sy + 1] = tmp;
		}
		return result;
	}
	int CalScore() {
		int score = 0;
		bool visited[N_large][N_large];
		int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
		for (int i = 0; i < N_large; i++) {
			for (int j = 0; j < N_large; j++) {
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < N_large; i++) {
			for (int j = 0; j < N_large; j++) {
				if (!visited[i][j]) {
					queue<pair<int, int>> q, trace;
					q.push(make_pair(i, j));
					trace.push(make_pair(i, j));
					visited[i][j] = true;
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						for (int k = 0; k < 4; k++) {
							int nx = cur.first + dx[k];
							int ny = cur.second + dy[k];
							if (in_range(nx, ny) && arr[nx][ny] == arr[cur.first][cur.second] && (!visited[nx][ny])) {
								q.push(make_pair(nx, ny));
								trace.push(make_pair(nx, ny));
								visited[nx][ny] = true;
							}
						}
					}
					if (trace.size() >= 3) { // 여기가 지려버렸다.
						score += trace.size();
						while (!trace.empty()) {
							pair<int, int> t = trace.front();
							trace.pop();
							arr[t.first][t.second] = 0;
						}
					}
				}
			}
		}
		return score;
	}
	void Fill(queue<int> *que) { // 왜 포인터로 안하면 터질까? 
		for (int i = 0; i < N_large; i++) {
			for (int j = N_large-1; j >= 0; j--) {
				if (arr[j][i] == 0) {
					arr[j][i] = que->front();
					que->pop();
				}
			}
		}
	}
};

int main() {
	int M, K;
	queue<int> q;
	Board* board = new Board();

	cin >> K >> M;
	for (int i = 0; i < N_large; i++) {
		for (int j = 0; j < N_large; j++) {
			cin >> board->arr[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		q.push(t);
	}
	while (K--) {
		int maxScore = 0;
		Board* maxScoreBoard = NULL;
		for (int cnt = 1; cnt <= 3; cnt++) {
			for (int sy = 0; sy <= N_large - N_small; sy++) {
				for (int sx = 0; sx <= N_large - N_small; sx++) {
					Board* rotated = board->Rotate(sx, sy, cnt);
					int score = rotated->CalScore();
					if (maxScore < score) { // 여기가 중요함, 우선순위대로 해야해서 같은게 나올 경우 우선권인게 선택되어야하기때매 등호가 안들어감
						maxScore = score;
						maxScoreBoard = rotated; 
					}
				}
			}
		}
		if (maxScoreBoard == NULL) break;
		board = maxScoreBoard;
		while (1) {
			board->Fill(&q);
			int newScore = 0;
			newScore = board->CalScore();
			if (newScore == 0) break;
			maxScore += newScore;
		}
		cout << maxScore << " ";
	}
}