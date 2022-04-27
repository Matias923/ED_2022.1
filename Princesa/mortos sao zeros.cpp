#include <iostream>


int main(void) {
    
    int fila = 0, es = 0;

    std::cin >> fila;

    int *v1 = new int[fila];

    std::cout << ("quem tem a espada?\n");
    std::cin >> es;
    es -= 1;

    for(int i = 0; i < fila; i++){ // inicializando vetor
        v1[i] = i+1;
    }

    for(int i = 1; i < fila; i++) { // Fila de morte
        for(int j = 0; j < fila; j++){ //Procura_pra_matar
            if(v1[j] == 0) continue;
            std::cout << v1[j];
            if(j == es){
                int pos = j+1;
                std::cout << ">";
                while(v1[++j] == 0){ //Procura_proximo_vivo_pra_matar
                    if(j == fila-1) j = -1;
                }
                std::cout << v1[j];
                v1[j] = 0; // morto
                while(v1[++es] == 0){ //Procura_proximo_vivo_pra_dar_espada
                    if(es == fila-1) es = -1;
                }
                for(int i = pos; i < fila; i++){
                    if(v1[i] == 0) continue;
                    std::cout << v1[i];
                }
                break;
            }
        }
        std::cout << "\n"; 
    }
    std::cout << v1[es];
    delete[] v1;
    return 0;
}