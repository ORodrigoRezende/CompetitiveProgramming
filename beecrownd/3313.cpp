#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int testes=1;
    cin >> s;
    while(s[0]!='*'){
        int tam = s.size() -1;
        int v = tam;
        deque<string> palavras;
        palavras.push_back(s);
        while(v--){ 
            char ultima = s[tam];
            for (int i = tam; i >0; i--){
                s[i] = s[i-1];
            }
            s[0]=ultima;
            //cout << s << endl;
            palavras.push_back(s);
        }
        sort(palavras.begin(),palavras.end());
        cout << "Caso "<< testes << ": " << palavras.front() << " " << palavras.back() << endl;
        cin >> s;
        testes++;
    }

    


    return 0;
}