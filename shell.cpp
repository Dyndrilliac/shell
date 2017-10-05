/*
    Shell Class Source File
    Project: Shell-CPP
    Author:  Matthew Boyette (N00868808)
    Date:    9/27/2017
*/

#include "main.hpp"

void Shell::execute(void)
{
    string input;

    cout << "Type Ctrl-C to exit." << endl << endl;

    do
    {
        cout << "> ";

        getline(cin, input);

        if (!input.empty())
        {
            transform(input.begin(), input.end(), input.begin(), ::tolower);
            system(Shell::translateDosToUnix(input));
        }
    }
    while (true);
}

CString Shell::translateDosToUnix(string dosString)
{
    string          retVal  = dosString;
    vector<string>  args    = StringSplitter::splitString(retVal, ' ');

    if (!args.empty())
    {
        string          command = args.front();
        ShellCommand    sc      = Shell::resolveDosCommand(command);

        switch (sc)
        {
            case DOS_CD_UNIX_CD:
                if (args.size() > 1)
                {
                    chdir(retVal.substr(3).c_str());
                    break;
                }
                else if (args.size() == 1)
                {
                    sc = DOS_CD_UNIX_PWD;
                    char* s;
                    getwd(s);
                    return (const char*)s;
                }

            case DOS_DIR_UNIX_LS:
                retVal.replace(0, 3, "ls");
                break;

            case DOS_TYPE_UNIX_CAT:
                retVal.replace(0, 4, "cat");
                break;

            case DOS_DEL_UNIX_RM:
                retVal.replace(0, 3, "rm");
                break;

            case DOS_REN_UNIX_MV:
                retVal.replace(0, 3, "mv");
                break;

            case DOS_COPY_UNIX_CP:
                retVal.replace(0, 4, "cp");
                break;

            default:
                break;
        }
    }

    return retVal.c_str();
}

ShellCommand Shell::resolveDosCommand(string dosCommand)
{
    if (dosCommand.compare("cd") == 0)
    {
        return DOS_CD_UNIX_CD;
    }

    if (dosCommand.compare("dir") == 0)
    {
        return DOS_DIR_UNIX_LS;
    }

    if (dosCommand.compare("type") == 0)
    {
        return DOS_TYPE_UNIX_CAT;
    }

    if (dosCommand.compare("del") == 0)
    {
        return DOS_DEL_UNIX_RM;
    }

    if (dosCommand.compare("ren") == 0)
    {
        return DOS_REN_UNIX_MV;
    }

    if (dosCommand.compare("copy") == 0)
    {
        return DOS_COPY_UNIX_CP;
    }

    return DOS_UNKNOWN_UNIX_UNKNOWN;
}