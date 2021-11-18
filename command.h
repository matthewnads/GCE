/**
 * Authored by Shanker Nadarajah on Oct 04 2021
 * This .h contains the interface the Command class
 * 
 */

#ifndef COMMAND_H
#define COMMAND_H 

#include <iostream>

class Command {

    private:
        std::string command;
        std::string result;
        int return_value;  

    public: 
        Command(std::string user_input);
        std::string getCommand();
        std::string getResult();
        int getReturn();
        void setCommand(std::string user_input);
        int execute(); 
        ~Command();
};

#endif