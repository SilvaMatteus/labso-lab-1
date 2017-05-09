#include "xeu_utils/StreamParser.h"

#include <limits.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <unistd.h>

using namespace xeu_utils;
using namespace std;

int main() {
    /* Getting username and hostname to show in shell indicator */
    char* username = (char*) malloc(sizeof(char) * LOGIN_NAME_MAX);
    char* hostname = (char*) malloc(sizeof(char) * HOST_NAME_MAX);

    getlogin_r(username, sizeof(char) * LOGIN_NAME_MAX);
    gethostname(hostname, sizeof(char) * HOST_NAME_MAX);
    // ParsingState p = StreamParser().parse();
    // cout << p.dump();
    // vector<Command> commands = p.commands();
    while (true)
    {
      printf("%s@%s => ", username, hostname);
      ParsingState p = StreamParser().parse();
    }
    return 0;
}
