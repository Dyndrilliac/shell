/*
    Shell Class Header File
    Project: Shell-CPP
    Author:  Matthew Boyette (N00868808)
    Date:    9/27/2017
*/

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sys/dir.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

typedef const char* CString;

typedef enum shellCommand
{
    DOS_UNIX_PASSTHROUGH,
    DOS_CD_UNIX_CD,
    DOS_CD_UNIX_PWD,
    DOS_DIR_UNIX_LS,
    DOS_TYPE_UNIX_CAT,
    DOS_DEL_UNIX_RM,
    DOS_REN_UNIX_MV,
    DOS_COPY_UNIX_CP,
} ShellCommand;

typedef class shell
{
    public:

        static void execute(void);

    protected:

        static bool         translateDosToUnix(string* dosString);
        static ShellCommand resolveDosCommand(string dosCommand);

    private:

        // ...

} Shell;