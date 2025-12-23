#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> matriz(n,vector<char>(m));
    for(int i = 0 ;i<n;i++)
        for(int j=0 ;j<m;j++)
            cin >> matriz[i][j];
    
    int soma = 0;
    for(int i = 0 ;i<n;i++){
        for(int j=0 ;j<m;j++){
            if(i-1>=0 && i+1<m && j-1>=0 && j+1<n && matriz[i][j]=='#'){
            if(matriz[i-1][j] != '#' || matriz[i+1][j] != '#' || matriz[i][j-1] != '#' || matriz[i][j+1] != '#' ){
                soma++;
            }
            }else if(matriz[i][j]=='#'){
                soma++;
            }
        }
    }
    cout << soma << endl;

    return 0;
}