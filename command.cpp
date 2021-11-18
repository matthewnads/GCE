/**
 * Authored by Shanker Nadarajah on Oct 04 2021
 * This .cpp contains the Command class, which is used to implement the logic of the program
 * This class is used by the Window class allow interaction with the user
 * 
 */
#include <boost/process.hpp> 
#include "command.h"

using namespace boost::process;

/****************************************************
 *Constructor
    ****************************************************/
Command::Command(std::string user_input) {
    command = user_input; 
    result = ""; 
    return_value =0; 
}

/****************************************************
 *Getters and Setters
    ****************************************************/
std::string Command::getCommand(){
    return command; 
}

std::string Command::getResult(){
    return result;
}

int Command::getReturn(){
    return return_value; 
}
void Command::setCommand(std::string user_input) {
    command = user_input; 
}

/****************************************************
 *Execute Method
    ****************************************************/
int Command::execute(){
    //using try catch so we can output an error message to the user
    try {
        //using child process to run a command (which will be entered by the user) and then sending to the stream
        ipstream pipe_stream;
        child c(command, (std_out & std_err) > pipe_stream);

        std::string line;
        //reading in the stream and adding to the result member variable 
        while (pipe_stream && std::getline(pipe_stream, line) && !line.empty())
            result = result +line+" " ; 

        c.wait();
        return_value=0;
    }
    catch(...) {
        result = result + "An error has occured" ;
        return_value=-1;
    }
    return return_value; 
        
}

/****************************************************
 *Destructor
    ****************************************************/
Command::~Command(){
//do nothing
} ;
