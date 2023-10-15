#include "helper.h"


vector<string> getAllTyped(string command) {
    vector<string> typedCommand;
    string delimiter = " ";
    string token;
    size_t pos = 0;
    while ((pos = command.find(delimiter)) != string::npos) {
        token = command.substr(0, pos);
        typedCommand.push_back(token);
        command.erase(0, pos + delimiter.length());
    }

    if(command != "") {
        typedCommand.push_back(command);
    }

    return typedCommand;
}

void removePositionVect(vector<string> *vect, int pos) {
    vect->erase(next(vect->begin(), pos));
}

bool contemValor(vector<string> lista, string value) {
    if(value == "") {
        return false;
    }

    for (string v : lista) {
        if(v == value) {
            return true;
        }
    }
    return false;
}
