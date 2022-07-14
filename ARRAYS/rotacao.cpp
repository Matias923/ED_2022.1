#include <iostream>
#include <vector>

using namespace std;

void show(vector<int> list) {
    cout << "[ ";
    for(int i : list)
        cout << i;
    cout << " ]" << endl;
}

void moveToRight(vector<int>& list, int spin) {
    if(spin <= 0)
        return;

    int size = list.size() - 1;
    int firtsElement = list[size];

    for(int i = size; i >= 0; i--)
        list[i] = list[i - 1];

    list[0] = firtsElement;
    moveToRight(list, spin - 1);
}

int main() {
    int size {};
    cout << "Digite quantos elementos tera o vetor: ";
    cin >> size;

    vector<int> list;
    for(int i = 0; i < size; i++) {
        int elem;
        cout << "Digite o elemento " << i << " do vetor: ";
        cin >> elem;
        list.push_back(elem);
    }

    int spin;
    cout << "Digite quantas vezes o vetor ira se mover a direita: ";
    cin >> spin;

    for(int i = 0; i < spin; i++) {
        moveToRight(list, spin);
        show(list);
    }
}