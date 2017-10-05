/*
    StringSplitter Class Header File
    Project: splitString
    Author:  Matthew Boyette
    Date:    2/27/2016
*/

#pragma once

#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef class stringSplitter
{
    public:

        static const vector<string> splitString(const string &s, char delim, bool ignoreEmptyStrings = true);

    protected:

        // ...

    private:

        // ...

} StringSplitter;