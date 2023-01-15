/*

Esse exercício foi resolvido usando greedy (guloso).
Sendo assim, o algoritmo consiste em percorrer o vetor de pedras,
e sempre que uma pedra for branca ou uma pedra pequena que está em uma posição par, o sapo pula para a pedra.

*/

#include <iostream>
#include <cmath>

using namespace std;

// estrutura que representa uma pedra
struct pedra{
  char tipo;
  int distMargem;
};

// vetor de bool que representa se uma pedra já foi usada (correspondente ao indice da pedra no vetor de pedras mais a diante)
bool foiusada[105];
int d;


int main(){

  /*
    n = numero de casos de teste
  */
  int n; cin >> n;
  for(int k = 0; k < n; k++){
    int numPedras; cin >> numPedras; cin >> d;

    // vetor de pedras
    pedra pedras[105];

    // leitura das pedras
    for(int i = 1; i <= numPedras; i++){

      string p; cin >> p; // recebe a pedra como string 

      int tipo = p[0]; // tipo da pedra      
      int distMargem = stoi(p.substr(2, p.size() - 2)); // calculando a distancia da pedra até a margem
      
      pedras[i].tipo = tipo; // atribui o tipo da pedra
      pedras[i].distMargem = distMargem; // atribui a distancia da pedra até a margem
    }

    int max_pulo = 0;
    int dist_percorrida = 0;
    int countPequenas = -1;

    /*
        B = Big
        S = Small
    */
    pedras[0].tipo = 'B';
    pedras[0].distMargem = 0;

    pedras[numPedras+1].tipo = 'B';
    pedras[numPedras+1].distMargem = d;



    // percorre o vetor de pedras
    for(int i = 0; i <= numPedras+1; i++){
      
      // se a pedra for pequena, incrementa o contador de pedras pequenas
      if(pedras[i].tipo == 'S') countPequenas++; 

      // se a pedra for branca ou uma pedra pequena que está em uma posição par, o sapo pula para a pedra
      if(pedras[i].tipo == 'B' || (countPequenas % 2 == 0 && pedras[i].tipo == 'S')){
        max_pulo = max(max_pulo, pedras[i].distMargem - dist_percorrida);
        dist_percorrida = pedras[i].distMargem;
      }
    }

    countPequenas++; // incrementa o contador de pedras pequenas

    // percorre o vetor de pedras de trás para frente  
    for(int i = numPedras; i >= 0; i--){
      // se a pedra for pequena, decrementa o contador de pedras pequenas
      if(pedras[i].tipo == 'S') countPequenas--;
      // se a pedra for grande ou uma pedra pequena que está em uma posição ímpar, o sapo pula para a pedra  
      if(pedras[i].tipo == 'B' || countPequenas % 2 == 1 && pedras[i].tipo == 'S'){
        max_pulo = max(max_pulo, dist_percorrida - pedras[i].distMargem); // calcula a distancia percorrida
        dist_percorrida = pedras[i].distMargem; // atualiza a distancia percorrida
      }
    }

    cout << "Case " << k+1 << ": " << max_pulo << endl; // imprime o resultado
     
  }
}