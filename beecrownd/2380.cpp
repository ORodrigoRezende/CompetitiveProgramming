#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

void unir(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b) parent[b] = a;
}

int main(){
   int N,b;
   cin >> N >> b;
   parent.resize(N+1);

   for (int i = 1; i <= N; i++){
        parent[i] = i;
   }

   while (b--){
    char op;
    int b1,b2;
    cin >> op >> b1 >> b2;

    if(op == 'C'){
        if(find(b1) == find(b2)) cout << "S\n";
        else cout << "N\n";
    }else if(op == 'F'){
        unir(b1,b2);
    }
    // for(auto i : parent){
    //     cout << i << " ";
    // }
    // cout << endl;
   }

    return 0;
}