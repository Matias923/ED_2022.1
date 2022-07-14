#include <iostream>
#include <vector>
#include <list>

using namespace std;

void toShow(list<int>& list, int ax) {
    cout << "[ ";

    for(auto i = list.begin(); i != list.end(); i++) {
        if (*i == ax)
            cout << *i << "> ";
        else
            cout << *i << " ";
    }

    cout << "]" << endl;
}

void toKill(list<int>& list, int ax) {
    auto i = list.begin();

    while(*i != ax)
        i++;

    if(i == list.end())
        list.front();
    else
        list.remove(*next(i));
}

int main() {
    int size {}, ax {};

    cout << "Digite o número de pessoas que irão participar: ";
    cin >> size;

    cout << "Digite quem irá comecar com o machado: ";
    cin >> ax;

    list<int> list;

    for(int i = 0; i < size; i++)
        list.push_back(i + 1);

    int aux = list.size();

    while(aux > 1) {
        toShow(list, ax);
        toKill(list, ax);
        ax = (ax + 1) % size;
        aux--;
    }

    toShow(list, ax);
}