#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <time.h>
#include <unistd.h>

using namespace std;

struct Position {
    int line;
    int column;
    Position(int line, int column) : line(line), column(column) {};
};

void toShow(vector<string> forest) {
    for(auto elem : forest)
        cout << elem << endl;
}

vector<Position> nextElements(Position position) {
    return {{position.line, position.column - 1}, {position.line - 1, position.column}, {position.line, position.column + 1}, {position.line + 1, position.column}};
}

vector<Position> verify(vector<Position> nextElements, vector<string> forest) {
    vector<Position> canToBurn;
    int number_lines = forest.size();
    int number_columns = forest[0].size();

    for(int i = 0; i < (int) nextElements.size(); i++) {
        if(nextElements[i].line < 0 || nextElements[i].line >= number_lines || nextElements[i].column < 0 || nextElements[i].column >= number_columns)
            continue;

        if(forest[nextElements[i].line][nextElements[i].column] != '#')
            continue;

        canToBurn.push_back(nextElements[i]);
    }

    return canToBurn;
}

void toBurn(vector<string>& forest, Position position) {
    srand(time(NULL));

    if(forest[position.line][position.column] != '#')
        return;

    forest[position.line][position.column] = 'o';

    stack<Position> stack;
    stack.push(position);

    while(!stack.empty()) {
        vector<Position> canToBurn{verify(nextElements(stack.top()), forest)};

        if(canToBurn.empty())
            stack.pop();
        else {
            int next{rand() % canToBurn.size()};
            forest[canToBurn[next].line][canToBurn[next].column] = 'o';
            stack.push(canToBurn[next]);
        }
    }    
}

int main() {
    int number_lines {}, number_columns {}, first_line {}, first_column {};
    cin >> number_lines >> number_columns >> first_line >> first_column;

    vector<string> forest;

    for(int i = 0; i < number_lines; i++) {
        string line;
        cin >> line;
        forest.push_back(line);
    }

    toBurn(forest, Position(first_line, first_column));
    toShow(forest);
}