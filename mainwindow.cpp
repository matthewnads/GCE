/**
 * Authored by Shanker Nadarajah on Oct 04 2021
 * This .cpp contains the class description and methods for the Window class.
 * Window class contains all the GUI components along with implementing methods in relation to the Command class.  
 * 
 */
#include <QtWidgets> 
#include "mainwindow.h"

/****************************************************
 Constructor : 
 setting up the window 
 and the layout with initial contents
    ****************************************************/
Window::Window() {
  //Setting up the UI 
  
  QVBoxLayout *mainLayout = new QVBoxLayout;
  //creating the widget where we enter the commands
  input = new QLineEdit(this); 
  button = new QPushButton(tr("Execute"));
  InputBox = new QGroupBox(tr("Enter your command here:"));
  QGridLayout *inputLayout = new QGridLayout; 
  connect(button, &QPushButton::released, this, &Window::executeButton); //this is what we use to handle events
  inputLayout->addWidget(button,1,1);
  inputLayout->addWidget(input,1,0); 
  InputBox->setLayout(inputLayout); 

  //this is where the command history will be populated 
  history = new QListWidget(this); 
  QLabel *label = new QLabel(tr("History"));
  connect(history, &QListWidget::itemPressed, this, &Window::fromHistory);

  //output box will be where the command output is populated 
  OutputBox = new QGroupBox(tr("Output")); 
  QGridLayout *outLayout = new QGridLayout; 
  output = new QTextEdit; 
  output->setReadOnly(true); 
  outLayout->addWidget(output, 2,0,-1,-1);
  OutputBox->setLayout(outLayout); 

  //label showing the exit status of the command, starting off empty
  exitStatus = new QLabel(tr(""));

  //adding everything to the main window 
  mainLayout->addWidget(InputBox); 
  mainLayout->addWidget(OutputBox);
  mainLayout->addWidget(label); 
  mainLayout->addWidget(history); 
  mainLayout->addWidget(exitStatus); 
  setLayout(mainLayout); 
  setWindowTitle(tr("3307: Assignment 1 by Shanker Nadarajah"));

};



/****************************************************
 Execute Button handler:
 Outputs the command, adds to the history list and updates exit status
    ****************************************************/
void Window::executeButton(){
  
  std::string userInput = input->text().toStdString();
  //if user doesn't enter anything but presses the button then nothing happens 
  if(userInput!=""){
    Command *command = new Command(userInput); 
    command->execute();

    //adding to output screen
    output->setPlaceholderText(QString::fromStdString(command->getResult()));

    //adding to command vectors
    commands.push_back(*command); 

    //adding to history 
    history->addItem(QString::fromStdString(command->getCommand()));

    //updating exit status
    int code = command->getReturn(); 
    std::string exitMessage = "Exit status ("+ std::to_string(code)+")";
    exitStatus->setText(QString::fromStdString(exitMessage));
     
  }

}

/****************************************************
 History List handler:
 This method updates the output and exit status based on what item in the history is selected 
    ****************************************************/
void Window::fromHistory() {
  //getting index of the selected item
  int currentIndex = history->currentRow();
  //getting the command item from the vector using the index 
  Command current = commands.at(currentIndex);
  //set the output as the selected command result 
  output->setPlaceholderText(QString::fromStdString(current.getResult()));
  //update the exit status 
  int code = current.getReturn(); 
  std::string exitMessage = "Exit status ("+ std::to_string(code)+")";
  exitStatus->setText(QString::fromStdString(exitMessage));
}
