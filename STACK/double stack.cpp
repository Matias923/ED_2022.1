#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Fila {
    stack<int> tank;
    stack<int> shelf;
};

int main() {
    int size, num;

    cin >> size >> num;
    vector<Fila>rows(size);

    int index1 = 0;
    while(index1 < num) {
        int f, c;
        cin >> f >> c;
        rows[f].tank.push(c);
        index1++;
    }

    int n;
    cin >> n;

    int index2 = 0; 
    while(index2 < n) {
        int f, c;
        cin >> f >> c;
        rows[f].shelf.push(c);
        index2++;
    }

    int j;
    cin >> j;
    
    int counter{};

    int index3 = 0;
    while( index3 < j) {
        int f, c;
        cin >> f >> c;

        while(!rows[f].tank.empty()) {
            if(rows[f].tank.top() == c) {
                rows[f].tank.pop();
                counter++;
                break;
            } else
                rows[f].tank.pop();
        }
        index3++;
    }

    cout << counter;
}