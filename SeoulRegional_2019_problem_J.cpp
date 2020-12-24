#include<bits/stdc++.h>

//https://www.acmicpc.net/problem/17977
using namespace std;

int sol(int n){
	if(n <= 3) return 0;
	if(n == 4) return 1;
	if(n == 5) return 2;
	return 2 + sol(n - n / 2);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	int res = sol(n);
	cout<<res<<'\n';
}