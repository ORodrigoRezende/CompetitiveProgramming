#include <bits/stdc++.h>
using namespace std;
#define INF 10000000

//  1 5 10 15 25 50
//  0 1 2 3 4 5 6

// 0 INF INF INF INF 1 INF INF INF INF 2 1

//  0 1 2 3 4 5 6 7 8 9 10 11 12


int main(){
    int n;
    cin >> n;
    while(n--){
        int x,M;
        cin >> x;
        cin >> M;
        vector<int> vetor(x);
        for(int i=0;i<x;i++){
            cin >> vetor[i];
        }
        vector<int> dp(M+1,INF);
        dp[0] = 0;
        for (int i = 0; i <= M; i++){
            for(int j=0; j<x;j++){
                if(vetor[j]<= i){
                    if(dp[i- vetor[j]]!= INF){
                        dp[i] = min(dp[i],1+dp[i - vetor[j]]);
                    }
                }
                
            }
            // for(int t=0;t < dp.size();t++)
            //     if(dp[t] == INF) cout << "INF ";
            //     else
            //         cout << dp[t] << " ";
            // cout << endl;
        }
        cout << dp[M] << endl;
    }

}