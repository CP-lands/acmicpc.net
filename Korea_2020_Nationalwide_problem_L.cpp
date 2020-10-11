#include<bits/stdc++.h>

//https://www.acmicpc.net/problem/20047
using namespace std;

void Solve(){
	int n, x, y;
	string s, t;
	cin>>n>>s>>t>>x>>y;
	string k = "";
	for(int i = 0; i < n; i++)
		if(i != x && i != y) k += s[i];
	int i = 0;
	while(i < k.size()){
		if(k[i] == t[i]){
			i++;
			continue;
		}
		string tmp = "";
		for(int j = 0; j < i; j++)
			tmp += k[j];
		tmp += s[x];
		for(int j = i; j < k.size(); j++)
			tmp += k[j];
		int j = i;
		while(j < tmp.size()){
			if(tmp[j] == t[j]){
				j++;
				continue;
			}
			string res = "";
			for(int a = 0; a < j; a++)
				res += tmp[a];
			res += s[y];
			for(int a = j; a < tmp.size(); a++)
				res += tmp[a];
			if(res == t){
				cout<<"YES\n";
			}
			else cout<<"NO\n";
			return;
		}
		tmp += s[y];
		if(tmp == t) cout<<"YES\n";
		else cout<<"NO\n";
		return;
	}
	k += s[x];
	k += s[y];
	if(k == t) cout<<"YES\n";
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