#include<bits/stdc++.h>

//https://www.acmicpc.net/problem/20046
using namespace std;
const int N = 1000;

int v[N][N];
bool vst[N][N];
 
int Move[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int main(){
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int n, m;
   cin>>n>>m;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++)
         cin>>v[i][j];
   }
   memset(vst, 0, N);
   set<pair<int, pair<int, int>>> s;
   s.insert({v[0][0], {0, 0}});
   vst[0][0] = true;
   int res = INT_MAX;
   while(!s.empty()){
      pair<int, pair<int, int>> p = *s.begin();
      s.erase(s.begin());
      int x = p.second.first;
      int y = p.second.second;
      int cost = p.first;
      for(int i = 0; i < 4; i++){
         int xx = x + Move[i][0];
         int yy = y + Move[i][1];
         if(xx >= 0 && xx < n && yy >= 0 && yy < m){
            if(!vst[xx][yy] && v[xx][yy] != -1){
               vst[xx][yy] = true;
               if(xx == n - 1 && yy == m - 1 && v[xx][yy] != -1){
                  res = min(res, cost + v[xx][yy]);
               }
               else
                  s.insert({cost + v[xx][yy], {xx, yy}});
            }
         }
      }
   }
   if(res == INT_MAX){
      cout<<-1<<endl;
   }
   else cout<<res<<endl;
}