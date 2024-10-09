#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_L 41
#define MAX_N 31

using namespace std;

int L, N, Q; // L : 체스판의 크기. N : 기사의 수, Q : 명령의 수
int board[MAX_L][MAX_L]; // 보드(장애물, 함정)
int map[MAX_L][MAX_L]; // 맵(기사)
bool live[MAX_N];
int hp[MAX_N];
int damage[MAX_N];
vector<pair<int, int>> knight[MAX_N]; // 기사들 좌표

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void debug() {
	cout << "This is board" << "\n";
	cout << "\n";
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= L; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "This is map" << "\n";
	cout << "\n";
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= L; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "This is 기사 좌표" << "\n";
	for (int i = 1; i <= N; i++) {
		cout << i << "번 기사";
		for (int j = 0; j < knight[i].size(); j++) {
			cout << "(" << knight[i][j].first << "," << knight[i][j].second << ")" << " ";
		}
	}
	cout << "This is hp" << "\n";
	for (int i = 1; i <= N; i++) {
		cout << live[i] << " ";
	}
	cout << "\n";
}

bool in_range(int x, int y) {
	return 1 <= x && x <= L && 1 <= y && y <= L;
}
bool is_alive(int num) {
	return live[num] == 1;
}
void del_map(int num) {
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= L; j++) {
			if (map[i][j] == num) map[i][j] = 0;
		}
	}
}
void init_map() {
	for (int m = 1; m <= L; m++) {
		for (int n = 1; n <= L; n++) {
			map[m][n] = 0;
		}
	}
}

bool in_vec(int n, vector<int> vec) {
	bool ch = false;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == n) ch = true;
	}
	return ch;
}

int main() {
	cin >> L >> N >> Q;
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= L; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		int r, c, h, w, k; // 기사의 처음 위치 : (r,c), 세로 길이 : h, 가로 길이 : w, 초기체력 : k
		cin >> r >> c >> h >> w >> k;
		for (int j = r; j < r + h; j++) {
			for (int z = c; z < c + w; z++) {
				map[j][z] = i;
				pair<int, int> m = { j,z };
				knight[i].push_back(m);
				hp[i] = k;
			}
		}
	}
	for (int i = 0; i < MAX_N; i++) { // 생명 불어넣기
		live[i] = true;
	}
	
	for (int i = 1; i <= Q; i++) {
		int num, dir; // num : 기사 번호, dir : 기사 방향
		cin >> num >> dir;
		// 기사 번호와 방향을 참고하여 민다
		vector<int> v_num; // 미는 기사 번호 삽입
		vector<pair<int, int>> v; // 기사 번호 좌표들 삽입
		for (int j = 0; j < knight[num].size(); j++) { // 좌표에서 이동방향에 붙어서 밀리는 애들 번호 추가
			int r = knight[num][j].first;
			int c = knight[num][j].second;
			while (map[r][c] != 0) {
				v_num.push_back(map[r][c]);
				int newr = r + dx[dir];
				int newc = c + dy[dir];
				r = newr;
				c = newc;
			}
		}
		sort(v_num.begin(), v_num.end());
		v_num.erase(unique(v_num.begin(), v_num.end()), v_num.end());
		for (int j = 0; j <v_num.size(); j++) { // 좌표를 v에 다 넣기
			int number = v_num[j];
			for (int k = 0; k < knight[number].size(); k++) {
				v.push_back({ knight[number][k].first,knight[number][k].second });
			}
		}
		// 여기까지는 괜찮

		bool check = true;
		for (auto i : v) { //기사 좌표 경계 밖에거나 벾에 막히지 않는지 체크
			int newr = i.first + dx[dir];
			int newc = i.second + dy[dir];
			if (!in_range(newr, newc) || board[newr][newc] == 2) {
				check = false;
			}
		}
		if (check == false) continue; // 만약 막히면 아무것도 안하고 다음턴
		for (int j = 0; j < v_num.size(); j++) { // 안 막히면 기사들 좌표 최신화
			int number = v_num[j];
			for (int k = 0; k < knight[number].size(); k++) {
				knight[number][k].first += dx[dir];
				knight[number][k].second += dy[dir];
			}
		}
		//여기까지도 괜찮
		init_map();
		for (int j = 1; j <= N; j++) { // map에다가 이제 맞게 옮겨주기
			if (hp[j]==0) continue; // 살아있다면
			for (int k = 0; k < knight[j].size(); k++) {
				int r = knight[j][k].first;
				int c = knight[j][k].second;
				map[r][c] = j;
			}
			
		}
		//여기까지도 괜찮
		for (int j = 1; j <= L; j++) { // 돌면서 
			for (int k = 1; k <= L; k++) {
				if (board[j][k] == 0 || map[j][k] == 0) continue; // 보드에 장애물도 없고 암것도 없거나 맵에 아무도 없으면 패스
				if (board[j][k] == 1 && map[j][k] != 0 && map[j][k] != num && in_vec(map[j][k],v_num)) { // 당사자 아니고, 보드에 1이 있고 맵에 누군가 있다면
					hp[map[j][k]]--; // 생명까고
					damage[map[j][k]]++; // 데미지 올라가고
					if (hp[map[j][k]] == 0) { //만약 생명 0됐으면
						del_map(map[j][k]); //체스판에서 지우고
						live[map[j][k]] = false; //생명 끄기
					}
				}
			}
		}
		//debug();
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (hp[i]==0) continue;
		sum += damage[i];
	}
	cout << sum;
	
}