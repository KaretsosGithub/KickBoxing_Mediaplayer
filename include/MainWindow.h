//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
    KickBoxing Defense Exersise Player -
    Main Window Header File
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "include/InstructionsWindow.h"
#include "include/VideoPlayer.h"
#include <QApplication>
#include <QFileDialog>
#include <QFrame>
#include <QGuiApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScreen>
#include <QVBoxLayout>
#include <QWidget>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class MainWindow : public QWidget {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);

    /*
      Check which button is pressed
      in order to retrieve the information
      from the VideoPlayer class
    */
    bool getOneRandomVideosVariable();
    bool getTwoRandomVideosVariable();
    bool getThreeRandomVideosVariable();
    bool getfourRandomVideosVariable();
    bool getFreeExerciseVariable();
    bool getStoppedVariable();

    bool oneRandomVideos;
    bool twoRandomVideos;
    bool threeRandomVideos;
    bool fourRandomVideos;
    bool freeExercise;
    bool stopped;

private:
    /*
      --Center Main Window on screen
      --Create the Layouts
      --Create the buttons
      --Add stuff to Layouts
      --Set the Path of the videos
      --Initialize the flags to check which button is pressed
      --Disable and Enable buttons
      --A simple vertical line to separate the play buttons
        from stop, exit and instructions buttons
    */
    void centerOnScreen();

    void createLayouts();
    void createVideoPlayer();

    void createPlayOneRandomButton();
    void createPlayTwoRandomButton();
    void createPlayThreeRandomButton();
    void createPlayFourRandomButton();
    void createFreeExerciseButton();
    void createExitButton();
    void createStopButton();
    void createInstructionsButton();

    void addToButtonsLayout();
    void addToMainLayout();

    void setVideosFolderPath(const QString& folderPath);

    void initializeFlags();

    void disablePlayButtons();
    void enablePlayButtons();

    void createSeparator();

    QVBoxLayout* mainLayout;
    QHBoxLayout* buttonLayout;
    VideoPlayer* videoPlayer;

    QPushButton* playOneRandomButton;
    QPushButton* playTwoRandomButton;
    QPushButton* playThreeRandomButton;
    QPushButton* playFourRandomButton;
    QPushButton* freeExerciseButton;
    QPushButton* exitButton;
    QPushButton* stopButton;
    QPushButton* instructionsButton;

    QString videosFolderPath;

    QFrame* separator;

private slots:
    /*
      Private slots for the buttons
      created above
    */
    void playOneRandomButtonClicked();
    void playTwoRandomButtonClicked();
    void playThreeRandomButtonClicked();
    void playFourRandomButtonClicked();
    void playFreeExerciseButtonClicked();
    void stopButtonClicked();
    void instructionButtonClicked();
};

#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
