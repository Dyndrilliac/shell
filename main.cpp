/*
    Main Source File
    Project: Shell-CPP
    Author:  Matthew Boyette (N00868808)
    Date:    9/27/2017
*/

#include "main.hpp"

int main(int argc, char *argv[])
{
    // Call the Shell class' static execute method.
    Shell::execute();

    // Exit the program successfully.
    return EXIT_SUCCESS;
}