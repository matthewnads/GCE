/**
 * Authored by Shanker Nadarajah on Oct 04 2021
 * This .cpp contains the main function for the whole program 
 * Starts the application and opens the window 
 * 
 */
#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);
  Window window;
  window.show();  
  return app.exec();
}