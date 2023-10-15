#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <functional>

#include "action.h"
#include "helper.h"
#include "model.h"

using namespace std;

void executeCommand(Command cmd);

Action findAction(string command);

int main()
{
    while(true) {
        string command;
        cout << "$ ";
        getline(cin, command);

        if(contemValor(exitWorlds, command)) {
            cout << "Até breve!" << endl;
            break;
        } else if (contemValor(clearWorlds, command)) {
            system("clear");
            continue;
        } else {
            vector<string> allTyped = getAllTyped(command);
            string command = allTyped[0];
            removePositionVect(&allTyped, 0);
            executeCommand({command, allTyped});
        }
    }

    return 0;
}

Action findAction(string command) {
    for(Action act : actions) {
        if (contemValor(act.args, command)) {
            return act;
        }
    }
    return Action();
}

void executeCommand(Command cmd) {
    Action act = findAction(cmd.command);
    if (act.args.empty()) {
        cout << "O comando não existe: " << cmd.command << endl;
        return;
    }

    if (contemValor(helpWorlds, cmd.parameters[0])) {
        cout << act.help << endl;
        return;
    }

    act.execute(cmd.parameters);
}

