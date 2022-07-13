#include <iostream>
#include <vector>
#include <fstream>

void mostrar(std::vector<std::string> floresta){
    for(auto x:floresta){
        std::cout << x << "\n";
    }
    getchar();
}

int queimar(std::vector<std::string>& floresta, int linha, int coluna){
    int nlinha = floresta.size();
    int ncoluna = floresta[0].size();
    if (linha < 0 || linha >= nlinha || coluna < 0 || coluna >= ncoluna) return 0;
    if (floresta[linha][coluna] != '#') {
        return 0;
    }
    floresta[linha][coluna] = '*';


    mostrar(floresta);

    int total = queimar(floresta, linha, coluna - 1) +
    queimar(floresta, linha - 1, coluna) +
    queimar(floresta, linha, coluna + 1) +
    queimar(floresta, linha + 1, coluna);
    
    floresta[linha][coluna] = '$';
    mostrar(floresta);

    return total + 1;
}


int main(){
    std::vector<std::string> floresta;
    int nl{}, nc{}, li{}, ci{};
    std::ifstream copy("copy.txt");
    copy >> nl >> nc >> li >> ci;
    for(int i{0}; i < nl; i++){
        std::string x;
        copy >> x;
        floresta.push_back(x);
    }

    std::cout << queimar(floresta, li, ci) << "\n";
}