#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
  /*
    n = numero de digitos
    d = numero de digitos a serem removidos
  */ 
  int n, d;
  while(cin >> n >> d){
    
    // se n e d forem iguais a zero, o programa deve parar
    if(n+d == 0) return 0;

    string num; cin >> num; // leitura do numero
    stack <char> str; // pilha de digitos
    str.push(num[0]); // empilhamento do primeiro digito

    // empilhamento dos digitos restantes
    for(int i = 1; i < n; i++){
      
      // se o numero de digitos a serem removidos for igual ao numero de digitos restantes
      if(n-i == d && num[i] <= str.top()){
        d--;
        continue; 
      }
      
      // desempilhamento dos digitos maiores que o digito atual  
      while(!str.empty() && str.top() < num[i] && d>0){
        str.pop();
        d--;
      }
      
        // empilhamento do digito atual  
      str.push(num[i]);
    }

    // Enquanto a pilha não estiver vazia, a resposta é formada com os digitos da pilha
    string answer;
    do{
      answer += str.top();
      str.pop();
    }
    while(!str.empty());
    
    // inverte a resposta
    reverse(answer.begin(), answer.end());
    
    // imprime a resposta
    cout << answer << endl;

  }

  return 0;
}