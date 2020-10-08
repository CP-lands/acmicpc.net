#include<bits/stdc++.h>

//https://www.acmicpc.net/problem/9466
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
bool vst[N];
int valid = 0;
int last = 1;
map<int, int> trace;

void dfs(int u, int v = -1){
	if(vst[u]) return;
	trace[u] = trace[v] + 1;
	vst[u] = true;
	for(auto x: g[u]){
		if(trace.count(x)){
			valid += (trace[u] - trace[x] + 1);
			return;
		}
		dfs(x, u);
	}
}
void Solve(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		int tmp;
		cin>>tmp;
		g[i].push_back(tmp);
	}
	memset(vst, 0, N);
	for(int i = 1; i <= n; i++){
		if(vst[i]) continue;
		trace.clear();
		trace[-1] = 0;
		dfs(i);
	}
	cout<<n - valid<<'\n';
	for(int i = 1; i <= n; i++)
		g[i].clear();
	valid = 0;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
}