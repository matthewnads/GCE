/**
 * Authored by Shanker Nadarajah on Oct 04 2021
 * This .h contains the interface the Window class, which inherits from the QDialog class 
 * Also implements several another QT classes, as shown in the namespace declaration
 * 
 */
#ifndef mainwindow_h
#define mainwindow_h
#include <QDialog> 
#include <vector>
#include "command.h"

QT_BEGIN_NAMESPACE


class QGroupBox;
class QLabel;
class QLineEdit;
class QDialog;
class QPushButton;
class QTextEdit;
class QListWidget;
QT_END_NAMESPACE

class Window : public QDialog {
  Q_OBJECT 
  public:
    Window(); 
  private: 

    std::vector<Command> commands; 
    QGroupBox *OutputBox;
    QGroupBox *InputBox; 
    QGroupBox *formGroupBox;
    QTextEdit *smallEditor;
    QTextEdit *output;
    QLineEdit *input;
    QPushButton *button;
    QListWidget *history;
    QLabel *exitStatus;

    void executeButton();  
    void fromHistory(); 
};

#endif
