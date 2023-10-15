#include "action.h"

#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void criarPasta(vector<string> parameters) {
    if (parameters.size() == 0) {
        cout << "Informe o nome da nova pasta."<< endl;
        return;
    }

    for(string param : parameters) {
        mkdir(param.c_str(), 0644);
    }
}

void listarPastas(vector<string> parameters) {
    if (parameters.size() == 0) {
        cout << "Informe o caminho da pasta que deseja listar" << endl;
        return;
    }

    string path = parameters[0];

    DIR *dir;
    struct dirent *dent;

    dir = opendir(path.c_str());
    if(dir == NULL) {
        cout << "A pasta não foi encontrada" << endl;
        return;
    }

    while((dent = readdir(dir)) != NULL) {
        cout << dent->d_name << endl;
    }
}
