#include <iostream>
#include <vector>

using namespace std;

void toShow(vector<int> row, int cut) {
    cout << "[";
    bool verify = true;

    for(int i = 0; i < row.size(); i++) {
        if(verify)
            verify = false;
        else
            cout << " ";
        
        if(row[i] == cut)
            cout << row[i] << ">";
        else
            cout << row[i];
    }

    cout << "]" << endl;
}

void toKill(vector<int>& row, int cut) {
    row.erase(row.begin() + cut);
}

int nextCut(vector<int>& row, int live) {
    return *row.begin() + 1;
}

int main() {
    int size {};
    int cut {};

    cout << "Digite o tamanho: ";
    cin >> size;

    cout << "Digite com quem comeca o machado: ";
    cin >> cut;

    vector<int> row;

    for(int i = 0; i < size; i++)
        row.push_back(i + 1);

    toShow(row, cut);

    while(row.size() > 1) {
        toKill(row, cut);
        cut = (cut + 1) % row.size();
        toShow(row, cut);
    }
}