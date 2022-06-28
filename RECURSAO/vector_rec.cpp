#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::string;

void print_elem(int * num, int tam){
    if(tam==0)
        return;
    std::cout << *num << " ";
    print_elem(num+1, tam-1);
}

void vet(int * num, int tam){
    std::cout << "[ ";
    print_elem(num, tam);
    std::cout << "]\n";
}

void print_elem_rvet(int * num, int tam){
    if(tam==0)
        return;
    print_elem_rvet(num+1, tam-1);
    std::cout << *num << " ";
}

void rvet(int * num, int tam){
    std::cout << "[ ";
    print_elem_rvet(num, tam);
    std::cout << "]\n";
}

int sum(int * num, int tam){
    if(tam == 0)
        return 0;
    return *num + sum(num+1, tam-1);
}
int mult(int * num, int tam){
    if(tam > 0)
    return *num + mult(num, tam-1);
    return 0;
}
// int min(int * num){

// }
// int inv(int * num){

// }

int main(){
    
    int num[] = {1,2,3,4,5};
    int tam = sizeof(num)/sizeof(int);

    vet(num, tam);
    rvet(num, tam);
    std::cout << sum(num, tam) << "\n";
    std::cout << mult(num, tam) << "\n";
    // min(num);
    // inv(num);
    
    return 0;
}

/*
vet: o vetor
rvet: o vetor impresso ao contrário
sum: a soma dos elementos
mult: a multiplicação dos elementos
min: o menor elemento
inv: inverte o vetor, depois imprime ele invertido
*/