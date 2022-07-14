#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<char> toStart() {
    string line {};
    getline(cin, line);

    list<char> text {};
    int counter {};

    auto i = line.begin();
    while( i != line.end()) {
        if(counter == 0) {
            if (*i == '<' || *i == '>' || *i == 'B' || *i == 'D') {
                text.push_back('|');
                counter++;
            }
        }
         
        text.push_back(*i);

        if ((i + 1) == line.end()) {
            if (counter == 0) 
                text.push_back('|');
            break;
        }
        i++;
    }

    return text;
}

void toShow(list<char>& text) {
    for(auto& element : text)
        cout << element;
}

void loopEdit(list<char>& text, list<char>::iterator cursor) {
    auto i = text.begin();
    while( i != text.end()) {
        if(*i == '|')
            cursor = i;
        i++;
    }
}

void toEdit(list<char>& text) {
    auto cursor = text.begin();
    int counter {};
    list<char> characters {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'y', 'w', 'z', '-'};

    auto i = text.begin();
    while( i != text.end()) {
        loopEdit(text, cursor);
        
        if(*i == 'R')
            *i = '\n';
        else if(*i == 'B') {
            if (*cursor != text.front()) {
                cursor = text.erase(--cursor);
                i = text.erase(i);
                --i;
            } else {
                i = text.erase(i);
                --i;
            }
        } else if (*i == 'D') {
            if (*cursor != text.back()) {
                text.erase(++cursor);
                i = text.erase(i);
                --i;
            } else {
                i = text.erase(i);
                --i;
            }
        } else if (*i == '>') {
            if(*cursor != text.back()) {
                if(*(next(cursor)) == '>') {
                    while (i != prev(text.end()))
                        i = text.erase(i);
                    break;
                }
                
                auto element = ++cursor;
                cursor = text.erase(cursor);
                text.insert(--cursor, *element);
                i = text.erase(i);
                --i;
                ++counter; 
            } else {
                i = text.erase(i);
                --i;
            }
        } else if (*i == '<') {
            if(*cursor != text.front()) {
                auto element = --cursor;
                cursor = text.erase(cursor);
                text.insert(++cursor, *element);
                i = text.erase(i);
                --i;
                ++counter;
            } else {
                i = text.erase(i);
                --i;
            }
        } else if (counter >= 1) {
            if (find(characters.begin(), characters.end(), *i) != characters.end()) {
                text.insert(cursor, *i);
                i = text.erase(i);
                --i;
            }
        }

        i++;
    }

    toShow(text);
}

int main() {
    auto text = toStart();
    toEdit(text);
}