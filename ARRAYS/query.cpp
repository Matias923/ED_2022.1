#include <iostream>
#include <vector>

using namespace std;

int toCount_elements(vector<string> input, string order) {
    int counter {};
    for(auto elem : input) {
        if(order == elem)
            counter++;
    }
    return counter;
}

vector<int> toVerify(vector<string> vetor, vector<string> consultation) {
    vector<int> vet;

    for(auto elem : consultation) {
        vet.push_back(toCount_elements(vetor, elem));
    }
    return vet;
}

void toStart(vector<string>& vetor, int sizeVet) {
    for(int i = 0; i < sizeVet; i++){
        string line;
        cout << "Digite o elemento " << i << ": ";
        cin >> line;
        vetor.push_back(line);
    }
}

int main()
{
    int sizeVetor {};
    cout << "Digite o tamanho do vetor: ";
    cin >> sizeVetor;

    vector<string> vetor;
    vetor.reserve(sizeVetor);
    toStart(vetor, sizeVetor);

    int sizeConsultation {};
    cout << "Digite o tamanho do vetor de consulta: ";
    cin >> sizeConsultation;

    vector<string> consultation;
    consultation.reserve(sizeConsultation);
    toStart(consultation, sizeConsultation);

    vector<int> outcome {toVerify(vetor, consultation)};

    cout << "[ ";
    for(int i = 0; i < (int) vetor.size(); i++) {
        cout << vetor[i];
        if(i != (int) vetor.size() - 1) {
            cout << ", ";
        }
    }  
    cout << " ]";

    return 0;
}