#include <iostream>
#include <sstream>
using namespace std;

struct Vector {
    int capacity {4};
    int size {0};
    int * data {nullptr};

    Vector(int capacity) : capacity(capacity) {
        this->data = new int[capacity];
    }

    ~Vector() {
        delete[] this->data;
    }

    void operator = (const Vector& other){
        this->capacity = other.capacity;
        this->size = other.size;

        if(this->data != nullptr) {
            delete[] this->data;
        }

        this->data = new int[other.capacity];

        for(int i = 0; i < other.capacity; i++) {
            this->data[i] = other.data[i];
        }
    }

    Vector(Vector& other) {
        *this = other;
    }

    void toAdd(int value) {
        if(this->size < this->capacity) {
            this->data[this->size] = value;
            size++;
        }
    }

    friend ostream& operator<<(ostream &os, Vector vector){
        os << "[ ";

        for(int i = 0; i < vector.size; i++)
            os << vector.data[i] << " ";

        os << "]";
        
        return os;
    }
};

int main(){
    string row, control;
    int value{};
    Vector vetor(4);

    while(true){
        getline(cin, row);
        stringstream ss(row);
        cin >> control;

        if(control == "end") {
            break;
        } else if (control == "remover") {
            ss >> value;
            vetor = Vector(value);
        } else if (control == "status") {
            cout << "Tamanho: " << vetor.size << " || Capacidade: " << vetor.capacity << endl;
        } else if (control == "adicionar") {
            while(ss >> value)
                vetor.toAdd(value);
        } else if(control == "mostrar") {
            cout << vetor << endl;
        } else {
            cout << "Comando invalido!!!" << endl;
        }
    }
}