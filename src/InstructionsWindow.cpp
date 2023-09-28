//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
    KickBoxing Defense Exersise Player -
    Instructions Window Source File
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "include/InstructionsWindow.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

InstructionsWindow::InstructionsWindow(QWidget* parent)
    : QWidget(parent) {

    // Title, size, center on screen
    setWindowTitle("Instructions");
    setFixedSize(1200, 650);
    centerOnScreen();

    // Create Layout with go it! button
    createLayout();
    createGotItButton();
    addToLayout();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Function to calculate the center position on any screen
void InstructionsWindow::centerOnScreen() {
    QList<QScreen*> screens = QGuiApplication::screens();
    if (screens.isEmpty())
        return;

    QScreen* primaryScreen = screens.at(0);
    QRect screenGeometry = primaryScreen->availableGeometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();

    // Calculate the centered position
    int x = (screenWidth - width()) / 2;
    int y = (screenHeight - height()) / 2;

    // Move the main window to the new position
    move(x, y);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Create the layout
void InstructionsWindow::createLayout() {
    mainLayout = new QVBoxLayout(this);
    instructionsLabel = new QLabel(
        "<html>"
        "Welcome, <i>Random User</i>!<br><br>"
        "<hr><br>"
        "-The exercise options buttons are located at the bottom left-middle of the main window (yellow colored buttons).<br><br>"
        "-Each button specifies the number of consecutive random videos to be played before a 4-second delay.<br><br>"
        "-For example, pressing <b>'Play 2 Random Videos'</b> will initiate the sequence: <i>Random Video - Random Video - 4 seconds "
        "delay</i>, and so on.<br><br>"
        "-The <b>'Free Exercise'</b> button starts a sequence of random videos with random delays between 1 and 2.3 seconds.<br><br>"
        "-All yellow buttons can be pressed when there is no current video playback.<br><br>"
        "-You can stop the current video playback by pressing the <b>'Stop'</b> button (see below).<br><br>"
        "<hr><br>"
        "-The <b>'Stop'</b>, <b>'Exit</b>,' and <b>'Instructions'</b> buttons at the bottom right of the main window are "
        "self-explanatory.<br><br>"
        "-You can press <b>'Stop'</b> at any time to halt video playback and start a new set of videos by pressing one of the yellow "
        "buttons (see above).<br><br>"
        "-Press <b>'Exit'</b> at any time to close the media player.<br><br>"
        "-The <b>'Instructions'</b> button opens this window and can be pressed when there is no current video playback.<br><br>"
        "<hr><br>"
        "<i>Happy exercise and have fun</i>!"
        "<hr>"
        "</html>",
        this);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Got it! button
void InstructionsWindow::createGotItButton() {
    gotItButton = new QPushButton("Got It!", this);
    connect(gotItButton, &QPushButton::clicked, this, &InstructionsWindow::gotItButtonClicked);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Add to layout
void InstructionsWindow::addToLayout() {
    mainLayout->addWidget(instructionsLabel);
    mainLayout->addWidget(gotItButton);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void InstructionsWindow::gotItButtonClicked() {
    /*
      Once the button is pressed,
      close the instructions window
    */
    close();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
