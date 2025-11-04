#include <bits/stdc++.h>
using namespace std;

/*
    1   2   3
    5   4   2
    500 300 30


    0   1   2   3    4   5   6   7   8   9   10
0   0   0   0   0    0    0   0   0   0   0   0
1   0   0   0   0    0    500 500 500 500 500 500
2   0   0   0   0    300  500 500 500 500 800 800  
3   0   0   30  30   300  500 500 530 530 800 800



*/


int main(){
    int r;
    cin >> r;
    while(r--){
        int n,k,total;
        cin >> n;
        vector<pair<int,int>> vetor(n);
        for(int i=0;i<n;i++)
            cin >> vetor[i].first >> vetor[i].second;
        // first  = valor   second = peso
        cin >> k;
        cin >> total;
        vector<vector<int>> matriz(n+1,vector<int>(k+1,0));
        for(int i = 1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(vetor[i-1].second<=j)
                matriz[i][j] = max(matriz[i-1][j],matriz[i-1][j-vetor[i-1].second]+vetor[i-1].first);
                else matriz[i][j] = matriz[i - 1][j];
            }
        }

        // for(int i = 0;i<=n;i++){
        //     for(int j=0;j<=k;j++){
        //         cout << matriz[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if(matriz[n][k]>=total){
            cout << "Missao completada com sucesso" << endl;
        }else{
            cout << "Falha na missao" << endl;
        }
    }
    return 0;
}