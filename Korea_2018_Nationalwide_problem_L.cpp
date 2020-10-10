#include<bits/stdc++.h>

//https://www.acmicpc.net/problem/16292
using namespace std;

vector<pair<int, int>> g[20005];
vector<long long> dis1(2e4 + 5, 1e15), dis2(2e4 + 5, 1e15), dis3(2e4 + 5, 1e15);
set<pair<long long, int>> setd;

void addEdge(int u, int v, int d){
	g[u].push_back({v, d});
	g[v].push_back({u, d});
}

void dijkstra(int source, vector<long long> &v){
	v[source] = 0;
	setd.insert({0, source});
	while(!setd.empty()){
		pair<long long, int> p = *setd.begin();
		setd.erase(setd.begin());
		int current = p.second;
		for(auto x: g[current]){
			if(v[x.first] > v[current] + x.second){
				if(setd.find({v[x.first], x.first}) != setd.end())
					setd.erase({v[x.first], x.first});
				v[x.first] = v[current] + x.second;
				setd.insert({v[x.first], x.first});
			}
		}
	}
}
long long maxx(long long a, long long b, long long c){
	vector<long long> tmp;
	tmp.push_back(a);
	tmp.push_back(b);
	tmp.push_back(c);
	sort(tmp.begin(), tmp.end());
	return tmp.back();
}
long long minn(long long a, long long b){
	if(a <= b) return a;
	else return b;
}
void Solve(){
	int n, m;
	cin>>n>>m;
	int one, two, three;
	while(m--){
		int u, v, d;
		cin>>u>>v>>d;
		addEdge(u, v, d);
	}
	cin>>one>>two>>three;
	dijkstra(one, dis1);
	dijkstra(two, dis2);
	dijkstra(three, dis3);
	long long res = 1e15;
	for(int i = 1; i <= n; i++){
		res = minn(res, maxx(dis1[i], dis2[i], dis3[i]));
	}
	cout<<res<<'\n';

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}