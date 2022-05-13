#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::string;

// Fila dos estressados

// BLOCO I
bool existe(const std::vector<int> fila, int x){ // ==
    for(auto i = fila.begin(); i != fila.end(); i++){
        if(*i == x) return 1;
    }
    return 0;
}
int contar(const std::vector<int> fila, int x){ // ==
    int cont = 0;
    for(auto i = fila.begin(); i != fila.end(); i++){
        if(*i == x) cont++;
    }
    return cont;
}
int procurar(const std::vector<int> fila, int x){ // ==
    int pos = 0, cont = 0;
    for(auto i = fila.begin(); i != fila.end(); i++){
        if(*i == x) cont = pos;
        pos++;
    }
    if(cont == 0) return -1;
    return cont;
    
}
int procurar_valor(const std::vector<int> fila, int x, int inicio){ // ==
    int cont = inicio;
    for(auto i = fila.begin()+inicio; i <= fila.end(); i++){
        if(*i == x) {
            return cont;
        }
        cont++;
    }
    return -1;
}
int procurar_menor(const std::vector<int> fila){ // ==
    int menor = 100;
    for(auto i = fila.begin(); i != fila.end(); i++){
        if(*i < menor) menor = *i;
    }
    return menor;
}
int procurar_pos_menor(vector<int> fila){ // ==
    int pos_menor = 0, menor = 100, cont =  0;
    for(auto i = fila.begin(); i != fila.end(); i++){
        if(menor > *i){
            menor = *i;
            pos_menor = cont;
        }
        cont++;
    }
    return pos_menor;
}
int procurar_pos_menor_apartir(vector<int> fila, int inicio){ // ==
    int pos_menor = 0, menor = 100, cont =  inicio;
    for(auto i = fila.begin()+inicio; i != fila.end(); i++){
        if(menor > *i){
            menor = *i;
            pos_menor = cont;
        }
        cont++;
    }
    return pos_menor;
}
int procurar_pos_melhor_se(vector<int> fila){ // ==
    int calmo = fila[0], cont = 0, pos = -1;
    for(auto i = fila.begin(); i != fila.end(); i++){
        if(*i > 0 && calmo > *i){
            calmo = *i;
            pos = cont;
        }
        cont++;
    }
    return pos;
}
float calcular_stress_medio(vector<int> fila){ // ==
    float soma = 0;
    if(fila.empty()) return 0;
    for(auto i = fila.begin(); i != fila.end(); i++){
        if(*i < 0) soma-=*i;
        else soma+=*i;
    }
    return soma/distance(fila.begin(), fila.end()); // media incorreta
}
string mais_homens_ou_mulheres(vector<int> fila){ // ==
    int homens = 0;
    int mulheres = 0;
    for(auto i = fila.begin(); i != fila.end(); i++){
        if(*i > 0) homens++;
        else mulheres++;
    }
    if(homens == mulheres) return "empate";
    if(homens > mulheres) return "homens";
    return "mulheres";
}
string qual_metade_eh_mais_estressada(vector<int> fila){ // !!
    int total = fila.size(); // tammanho da fila
    //int metade = total/2, atual = 0, met1 = 0, met2 = 0;
    vector<int> copia = fila;
    
    for(int i = 0; i < total; i++){
        if(copia[i] < 0) copia[i]-=copia; 
    }
    std::cout << copia;

    // std::cout << met1 << met2;
    // if(met1>met2) return "primeira";
    // if(met1==met2) return "empate";
    return "segunda";
}
// FIM DO BLOCO I
// BLOCO II
vector<int> clonar(vector<int> fila){ // ==
    vector<int> copia;
    for(auto i = fila.begin(); i != fila.end(); i++){
        copia.push_back(*i);
    }
    return copia;
}
vector<int> pegar_homens(const vector<int> fila){ // ==
    vector<int> copia;
    for(auto i = fila.begin(); i != fila.end(); i++){
        if(*i > 0) copia.push_back(*i);
    }
    return copia;
   
}
vector<int> pegar_calmos(const vector<int>& fila){ // ==
    vector<int> copia;
    for(auto i = fila.begin(); i != fila.end(); i++){
        if(*i > -10 && *i < 10) copia.push_back(*i);
    }
    return copia;
}
vector<int> pegar_mulheres_calmas(const vector<int> fila){ // ==
    vector<int> copia;
    for(auto i = fila.begin(); i != fila.end(); i++){
        if(*i > -10 && *i < 0) copia.push_back(*i);
    }
    return copia;
}
vector<int> inverter_com_copia(const vector<int>& fila){ // ==
    vector<int> copia;
    for(auto i = fila.rbegin(); i != fila.rend(); i--){
        copia.push_back(*i);
    }
    return copia;
}
void inverter_inplace(vector<int> fila){ // ==
    int j = distance(fila.begin(), fila.end()), cara = j, aux = 0;
    for(auto i = fila.begin(); i != fila.end(); i++, j--){
        aux = *i;
        *i = fila[j];
        fila[j] = aux;
        if(j<(cara/2)) break;
    }
}
int sortear(const vector<int>& v);
void embaralhar(vector<int>& fila){ // ==
    std::sort(fila.begin(), fila.end());
}
void ordenar(vector<int>& v);
vector<int> exclusivos(const vector<int> fila){ // !!
    vector<int> unicos;
    int  i = 0;
    for(auto elem : fila){
        if(existe(unicos, elem)==0) unicos[i] = elem;
        i++;
    }
    return unicos;
}
vector<int> diferentes(const vector<int>& fila){ // !!
    vector<int> repetidos;
    int i = 0;
    repetidos.size(fila);
    for(auto elem : fila){
        if(elem == repetidos[i])
    }
    return copia;
}
vector<int> abandonados(const vector<int>& v){
    
}
// FIM BLOCO II
// BLOCO III
vector<int> sozinhos(const vector<int>& fila);
int briga(const vector<int>& v);
vector<int> apaziguados(const vector<int>& v);
int quantos_times(const vector<int>& v);
vector<int> maior_time(const vector<int>& v);
int sem_time(vector<int> &vet);
int casais(const std::vector<int> &vet);
int trios(const std::vector<int> &vet);
std::vector<int> remove(const std::vector<int> &vet, int pessoa);
std::vector<int> insert(const std::vector<int> &vet, int pessoa, size_t pos);
std::vector<int> dance(const std::vector<int> &vet);

// int main(){
//     vector<int> fila;
//     int j = 0;
//     for(auto i = fila.begin(); i != fila.end(); i++, j++){
//         fila.push_back(j);
//         if(j==10) break;
//     }
//     std::cout << "aqui ";
//     inverter_inplace(fila);
//     std::cout << "la ";
//     for(auto i = fila.begin(); i != fila.end(); i++){
//         std::cout << *i;
//     }
//     std::cout << "la tambem ";
// }