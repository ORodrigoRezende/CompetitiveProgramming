#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> pilha;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == '(') pilha.push('(');
        if(s[i] == ')' && !pilha.empty()) pilha.pop();
    }
    if(pilha.empty()) cout << "Partiu RU!"<<endl;
    else cout << "Ainda temos "<< pilha.size() <<" assunto(s) pendente(s)!" << endl;
}