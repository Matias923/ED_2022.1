#include <iostream>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

struct client {
    string id;
    int docs;
    int pac;

    client(string id, int docs, int pac) : id(id), docs(docs), pac(pac) {}

    string str() {
        return id + ":" + to_string(docs) + ":" + to_string(pac); 
    }
};

class Bank {
private:
    vector<client*> boxes {};
    list<client*> entry_queue {};
    list<client*> exit_queue {};
    int docs_reserved {};
    int docs_lost {};
    int docs_tics {};
    int amount {};
    
public:
    Bank(int boxes) : boxes(boxes) {}

    void toInsert(client* client) {
        this->entry_queue.push_back(client);
        ++amount;
    }

    bool toCheckEmpty() {
        if(this->amount == 0)
            return true;

        return false;
    }

    void toSpendTime() {
        if(!this->exit_queue.empty()) {
            for(auto i = exit_queue.begin(); i != exit_queue.end(); i++) {
                this->docs_lost += (*i)->docs;
                auto backup = i;
                i = this->exit_queue.erase(i);
                delete *backup;
            }
            --amount;
        }

        for(auto& elem : this->boxes) {
            if(elem != nullptr) {
                if (elem->docs > 0) {
                    --elem->docs;
                    this->docs_reserved++;
                } else {
                    auto person = elem;
                    this->exit_queue.push_back(person);
                    elem = nullptr;
                }
            } else {
                if (entry_queue.empty())
                    break;
                
                elem = this->entry_queue.front();
                this->entry_queue.pop_front();
            }
        }

        if(!entry_queue.empty()) {
            for(auto i = entry_queue.begin(); i != entry_queue.end(); i++) {
                if ((*i)->pac > 0)
                   (*i)->pac--;
                else {
                    auto person = (*i);
                    exit_queue.push_back(person);
                    i = entry_queue.erase(i);
                }
            }
        }
        ++docs_tics;
    }

    void toShow() {
        for(auto& client : this->boxes)
            cout << "[" << (client == nullptr ? "" : client->str()) << "]";
        
        cout << "Inseridos: { ";
        
        for(auto &client : this->entry_queue)
            cout << (client == nullptr ? " " : client->str()) << " ";
        
        cout << "}" << endl;
        
        cout <<  "nout:{ ";
        
        for(auto &client : this->exit_queue)
            cout << (client == nullptr ? " " : client->str()) << " ";
        
        cout << "}" << endl;
    }

    int get_received() {
        return this->docs_reserved;
    }

    int get_lost() {
        return this->docs_lost;
    }

    int get_tics() {
        return this->docs_tics;
    }
};

int main() {
    Bank* bank;
    
    while(true) {
        string line, command;
        
        getline(cin, line);
        stringstream ss(line);
        ss >> command;
        
        if(command == "end")
            break;
        else if (command == "iniciar") {
            int toShow;
            ss >> toShow;
            bank = new Bank(toShow);
        } else if (command == "mostrar")
            bank->toShow();
        else if (command == "inserir") {
            string name;
            int docs, pacience;
            ss >> name >> docs >> pacience;
            bank->toInsert(new client(name, docs, pacience));
        } else if (command == "tic")
            bank->toSpendTime();
        else if (command == "status") {
            while (!bank->toCheckEmpty())
                bank->toSpendTime();
            
            cout << "Documentos recebidos: " << bank->get_received() << endl;
            cout << "Documentos perdidos: " << bank->get_lost() << endl;
            cout << "Tics: " << bank->get_tics() << endl;
        } else
            cout << "Comando Invalido!" << endl;
    }
}