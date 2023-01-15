#include <iostream> // biblioteca para usar o cin e o cout
#include <algorithm> // biblioteca para usar a função sort
#include <deque> // biblioteca para usar o deque
#include <cmath> // biblioteca para usar a função abs
#include <vector> // biblioteca para usar o vetor

using namespace std;

int main(){
  // t = número de casos de teste  
  int t; cin >> t;

  for(int k=1; k <= t; k++){
    // n = número de elementos por caso de teste
    int n; cin >> n;

    // numbers = vetor de inteiros
    vector <int> numbers; numbers.resize(n);
    
    // leitura dos elementos
    for(int i = 0; i < n; i++){
      cin >> numbers[i];
    }

    // ordenação dos elementos 
    sort(numbers.begin(), numbers.end());

    // newNumbers = deque de inteiros
    deque <int> newNumbers;

    int sum = 0;

    // permutação dos elementos
    for(int i = 0; i < n/2; i++){

      // se o número de elementos for par
      if(i%2 == 0){
        newNumbers.push_front(numbers[i]); // insere o elemento na frente do deque
        newNumbers.push_back(numbers[n-i-1]); // insere o elemento no final do deque
      }
      // se o número de elementos for ímpar
      else{
        newNumbers.push_front(numbers[n-i-1]); // insere o elemento na frente do deque
        newNumbers.push_back(numbers[i]); // insere o elemento no final do deque
      }
    }

    // percorre o deque e soma as diferenças entre os elementos
    for(int i = 0; i < newNumbers.size() - 1; i++) {
      sum += abs(newNumbers[i] - newNumbers[i+1]); // soma das diferenças entre os elementos
    }
    // se o número de elementos for ímpar
    if(n % 2 == 1)
      // soma a diferença entre o elemento do meio e o elemento mais próximo dele
      sum += max(abs(newNumbers[0] - numbers[n/2]), abs(newNumbers[n-2] - numbers[n/2])); 
    
    // imprime o resultado
    cout << "Case " << k << ": " << sum << endl;

  }
  return 0;
}