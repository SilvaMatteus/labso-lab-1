#include "xeu_utils/StreamParser.h"

#include <limits.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>

using namespace xeu_utils;
using namespace std;

int main()
{
    passwd* user = getpwuid(getuid());

    /* Getting username and hostname to show in shell indicator */
    char* username = (char*) malloc(sizeof(char) * strlen(user->pw_name) + 1);
    char* hostname = (char*) malloc(sizeof(char) * HOST_NAME_MAX);

    strcpy(username, user->pw_name);
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
