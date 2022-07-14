#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void whoWhasLeftWrong(vector<int>& row, int giveUp) {
    for(int i = 0; i < (int) row.size(); i++) {
        if(row[i] == giveUp){
            row.erase(row.begin() + i);
            return;
        }
    }
}

vector<int> whoWhasLeftCorrectly(vector<int> row, vector<int> gotOut) {
    vector<int> left;
    unordered_set<int> gotOut_set(begin(gotOut), end(gotOut));

    for(auto i : row) {
        if(gotOut_set.find(i) == gotOut_set.end()) {
            left.push_back(i);
        }
    }

    return gotOut;
}

void toQueue(vector<int>& fila, int tam) {
    for(int i = 0; i < tam; i++){
        int linha;
        cout << "Digite o elemento " << i << " : ";
        cin >> linha;
        fila.push_back(linha);
    }
}

int main() {
    int group {};
    cout << "Digite quantos elementos tera o grupo: ";
    cin >> group;

    vector<int> row;
    row.reserve(group);
    toQueue(row, group);

    int gaveUp {};
    cout << "Digite quantos elementos ira desistir do grupo: ";
    cin >> gaveUp;

    vector<int> dropouts;
    dropouts.reserve(gaveUp);
    toQueue(dropouts, gaveUp);
    
    cout << "Maneira correta: " << endl;
    cout <<  whoWhasLeftCorrectly(row, dropouts) << endl;

    cout << "Maneira errada: " << endl;
    for(int i = 0; i < gaveUp; i++) {
        whoWhasLeftWrong(row, dropouts[i]);
    }

    cout << "[";    

    for(int i = 0; i < (int) row.size(); i++) {
        cout << row[i];
        if (i != (int) row.size() -1)
            cout << ", ";
    }

    cout  << "]";

    return 0;
}