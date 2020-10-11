#include<bits/stdc++.h>

//https://www.acmicpc.net/problem/20041
using namespace std;

void Solve(){
	int n;
	cin>>n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++){
		int a, b;
		cin>>a>>b;
		v[i] = {a, b};
	}
	int x, y;
	cin>>x>>y;
	bool left = true, right = true, top = true, bot = true;
	for(int i = 0; i < n; i++){
		if(v[i].first <= x && abs(v[i].second - y) <= abs(x - v[i].first)) left = false;
		if(v[i].first >= x && abs(v[i].second - y) <= abs(x - v[i].first)) right = false;
		if(v[i].second >= y && abs(v[i].first - x) <= abs(y - v[i].second)) top = false;
		if(v[i].second <= y && abs(v[i].first - x) <= abs(y - v[i].second)) bot = false;
	}
	if(top || bot || left || right) cout<<"YES\n";
	else cout<<"NO\n";

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}