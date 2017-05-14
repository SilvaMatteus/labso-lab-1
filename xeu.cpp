#include "xeu_utils/StreamParser.h"

#include <limits.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <pwd.h>

using namespace xeu_utils;
using namespace std;

#ifndef HOST_NAME_MAX
    #define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
#endif

int main()
{
    passwd* user = getpwuid(getuid());

    /* Getting username and hostname to show in shell indicator */
    char* username = (char*) malloc(sizeof(char) * strlen(user->pw_name) + 1);
    char* hostname = (char*) malloc(sizeof(char) * HOST_NAME_MAX);

    strcpy(username, user->pw_name);
    gethostname(hostname, sizeof(char) * HOST_NAME_MAX);

    vector<Command> commands;
    ParsingState p;
    Command c;

    int statval = 0;
    pid_t pid, wpid;
    
    while (true)
    {
        printf("%s@%s => ", username, hostname);
      
        p = StreamParser().parse();
        commands = p.commands();

        if (commands.size() == 1 && !strcmp(commands[0].filename(), "exit")) break;

        #ifdef DEBUG
            cout << p.dump() << endl;
        #endif

        for (size_t i = 0; i < commands.size(); i++)
        {
            c = commands[i];
            int code;
            pid = fork();

            if (pid == 0)
            {
                code = execvp(c.filename(), c.argv());

                if (code == -1)
                {
                    printf("%s\n", strerror(errno));
                    exit(1);
                }

            }
            else
            {
                #ifdef DEBUG
                    printf("PID %d: waiting for child\n", getpid());

                    if(WIFEXITED(statval))
                        printf("Child's exit code %d\n", WEXITSTATUS(statval));
                    else
                        printf("Child did not terminate with exit\n");
                #endif
            }
        }

        while ((wpid = wait(&statval)) > 0);
    }

    return 0;
}
