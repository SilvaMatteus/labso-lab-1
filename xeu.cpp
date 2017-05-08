#include "xeu_utils/StreamParser.h"

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <unistd.h>

using namespace xeu_utils;
using namespace std;

int main() {
    /* Getting username and hostname to show in shell indicator */
    char* username = getenv("USERNAME");
    char* hostname = (char*) malloc(sizeof(char)*15);
    gethostname(hostname, 15);
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
