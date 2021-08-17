#include<bits/stdc++.h>

//https://www.acmicpc.net/problem/20046
using namespace std;
#define nl '\n'

int trans[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void Solve(){
	int n, m;
	cin>>n>>m;
	vector<vector<int>> v(n, vector<int> (m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>v[i][j];
		}
	}
	if(v[0][0] == -1 || v[n - 1][m - 1] == -1){
		cout<<-1<<nl;
		return;
	}
	int res = INT_MAX;
	vector<vector<bool>> vst(n, vector<bool> (m));
	vst[0][0] = true;
	set<pair<int, pair<int, int>>> s;
	s.insert({v[0][0], {0, 0}});
	bool found = false;
	while(!s.empty()){
		pair<int, pair<int, int>> current = *s.begin();
		s.erase(s.begin());
		pair<int, int> p = current.second;
		for(int i = 0; i < 4; i++){
			int x = p.first + trans[i][0];
			int y = p.second + trans[i][1];
			if(x >= 0 && x < n && y >= 0 && y < m && v[x][y] != -1 && !vst[x][y]){
				s.insert({current.first + v[x][y], {x, y}});
				vst[x][y] = true;
				if(x == n - 1 && y == m - 1){
					res = current.first + v[x][y];
					found = true;
					//cout<<p.first<<" "<<p.first<<" "<<p.second<<nl;
				}
			}
		}
		if(found) break;
	}
	if(res == INT_MAX) cout<<-1<<nl;
	else cout<<res<<nl;

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}
