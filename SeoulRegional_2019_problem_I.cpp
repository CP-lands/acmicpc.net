#include<bits/stdc++.h>  

//https://www.acmicpc.net/problem/17976
using namespace std; 

#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;

bool isPossible(int k, int n, vector<pair<int, int>> &v){
	int start = v[0].first;
	for(int i = 1; i < n; i++){
		if(v[i].first + v[i].second - start < k) return false;
		start = max(start + k, v[i].first);
	}
	return true;
}
void Solve(){
	int n;
    cin>>n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
    	cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(), v.end());
    int low = 0;
    int high = INT_MAX;
    int exit = 0;
    int res = 0;
    while(low < high){
    	int mid = low + (high - low) / 2;
    	if(exit == 2) mid = high;
    	if(isPossible(mid, n, v)){
    		low = mid;
    		res = max(res, mid);
    	}
    	else high = mid;
    	if(high - low == 1) exit++;
    	if(exit == 3) break;
    }
    cout<<res<<nl;
    
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}