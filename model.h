#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

struct Command {
    string command;
    vector<string> parameters;
};

struct Action {
    vector<string> args;
    function<void(vector<string>)> execute;
    string help;
};

vector<Action> actions = {
    {{ "criar-pasta" }, [](vector<string> parameters) { criarPasta(parameters); }, "Cria uma pasta no diretório escolhido."},
    {{ "listar", "list" }, [](vector<string> parameters) { listarPastas(parameters); }, "Lista as pastas do diretório.\nlistar [caminho da pasta]\nOutros: list\n[Exemplo] listar ../\nIrá listar tudo o que tem na pasta anterior." }
};

vector<string> exitWorlds = { "sair", "exit" };
vector<string> clearWorlds = { "limpar", "clear" };
vector<string> helpWorlds = { "ajuda", "help" };

#endif // MODEL_H_INCLUDED
