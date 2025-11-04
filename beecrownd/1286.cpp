#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main(){
    int n,k;
    cin >> n;
    while(n!=0){
        cin >> k;
        vector<pair<int,int>> pizzas(n);
        for(int i=0;i<n;i++)
            cin >> pizzas[i].f >> pizzas[i].s;

        vector<vector<int>> dp(n+1,vector<int>(k+1,0));

        // f = valor s = peso

        for(int i = 1; i <= n; i++){
            for (int j = 0; j <= k; j++){
                if(pizzas[i-1].s<=j){
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-pizzas[i-1].s]+pizzas[i-1].f);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        cout << dp[n][k] << " min." << endl;
        cin >> n;
     }


    return 0;
}