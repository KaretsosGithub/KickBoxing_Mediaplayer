//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
    KickBoxing Defense Exersise Player -
    Main Window Source File
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "include/MainWindow.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent) {
    // Center main window
    centerOnScreen();

    /*
      Create all the necessary stuff
      (buttons, layouts etc)
    */
    createLayouts();
    createVideoPlayer();

    createPlayOneRandomButton();
    createPlayTwoRandomButton();
    createPlayThreeRandomButton();
    createPlayFourRandomButton();
    createFreeExerciseButton();
    createExitButton();
    createStopButton();
    createInstructionsButton();

    createSeparator();

    // Add stuff to layouts
    addToButtonsLayout();
    addToMainLayout();

    /*
      Set the video folder path.
      Update this according to your needs
    */
    setVideosFolderPath("path_to_your_video_folder");

    /*
      Initialize the flags
      of the videos
    */
    initializeFlags();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Function to center the Main Window on screen
void MainWindow::centerOnScreen() {
    QList<QScreen*> screens = QGuiApplication::screens();
    if (screens.isEmpty())
        return;

    // Get the primary screen
    QScreen* primaryScreen = screens.at(0);

    // Get the available geometry of the primary screen
    QRect screenGeometry = primaryScreen->availableGeometry();

    // Calculate the desired width and height based on a percentage of the screen's size
    int widthPercentage = 90;
    int heightPercentage = 90;
    int desiredWidth = screenGeometry.width() * widthPercentage / 100;
    int desiredHeight = screenGeometry.height() * heightPercentage / 100;

    // Set the calculated width and height as the size of the main window
    resize(desiredWidth, desiredHeight);

    // Center the main window on the screen
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(screenGeometry.x() + x, screenGeometry.y() + y);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Create the Layouts
void MainWindow::createLayouts() {
    mainLayout = new QVBoxLayout(this);
    buttonLayout = new QHBoxLayout();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Create the Video Player
void MainWindow::createVideoPlayer() {
    videoPlayer = new VideoPlayer(this);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Play 1 video button
void MainWindow::createPlayOneRandomButton() {
    playOneRandomButton = new QPushButton("Play 1 Random Video", this);
    playOneRandomButton->setToolTip("Click to start the 1-Video playback");
    playOneRandomButton->setStyleSheet("QPushButton {"
                                       "background-color: #FFA500;"
                                       "color: black;"
                                       "border: 2px solid #FF8C00;"
                                       "border-radius: 5px;"
                                       "font-size: 16px;"
                                       "}"
                                       "QPushButton:hover {"
                                       "background-color: #FF8C00;"
                                       "}"
                                       "QPushButton:pressed {"
                                       "background-color: #FF7700;"
                                       "}"
                                       "QPushButton:disabled {"
                                       "background-color: #ccc;"
                                       "color: #888;"
                                       "border: 2px solid #ccc;"
                                       "}");
    playOneRandomButton->setFixedSize(180, 50);
    connect(playOneRandomButton, &QPushButton::clicked, this, &MainWindow::playOneRandomButtonClicked);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Play 2 videos button
void MainWindow::createPlayTwoRandomButton() {
    playTwoRandomButton = new QPushButton("Play 2 Random Videos", this);
    playTwoRandomButton->setToolTip("Click to start the 2-Video playback");
    playTwoRandomButton->setStyleSheet("QPushButton {"
                                       "background-color: #FFA500;"
                                       "color: black;"
                                       "border: 2px solid #FF8C00;"
                                       "border-radius: 5px;"
                                       "font-size: 16px;"
                                       "}"
                                       "QPushButton:hover {"
                                       "background-color: #FF8C00;"
                                       "}"
                                       "QPushButton:pressed {"
                                       "background-color: #FF7700;"
                                       "}"
                                       "QPushButton:disabled {"
                                       "background-color: #ccc;"
                                       "color: #888;"
                                       "border: 2px solid #ccc;"
                                       "}");
    playTwoRandomButton->setFixedSize(180, 50);
    connect(playTwoRandomButton, &QPushButton::clicked, this, &MainWindow::playTwoRandomButtonClicked);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Play 3 videos button
void MainWindow::createPlayThreeRandomButton() {
    playThreeRandomButton = new QPushButton("Play 3 Random Videos", this);
    playThreeRandomButton->setToolTip("Click to start the 3-Video playback");
    playThreeRandomButton->setStyleSheet("QPushButton {"
                                         "background-color: #FFA500;"
                                         "color: black;"
                                         "border: 2px solid #FF8C00;"
                                         "border-radius: 5px;"
                                         "font-size: 16px;"
                                         "}"
                                         "QPushButton:hover {"
                                         "background-color: #FF8C00;"
                                         "}"
                                         "QPushButton:pressed {"
                                         "background-color: #FF7700;"
                                         "}"
                                         "QPushButton:disabled {"
                                         "background-color: #ccc;"
                                         "color: #888;"
                                         "border: 2px solid #ccc;"
                                         "}");
    playThreeRandomButton->setFixedSize(180, 50);
    connect(playThreeRandomButton, &QPushButton::clicked, this, &MainWindow::playThreeRandomButtonClicked);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Play 4 videos button
void MainWindow::createPlayFourRandomButton() {
    playFourRandomButton = new QPushButton("Play 4 Random Videos", this);
    playFourRandomButton->setToolTip("Click start to the 4-Video playback");
    playFourRandomButton->setStyleSheet("QPushButton {"
                                        "background-color: #FFA500;"
                                        "color: black;"
                                        "border: 2px solid #FF8C00;"
                                        "border-radius: 5px;"
                                        "font-size: 16px;"
                                        "}"
                                        "QPushButton:hover {"
                                        "background-color: #FF8C00;"
                                        "}"
                                        "QPushButton:pressed {"
                                        "background-color: #FF7700;"
                                        "}"
                                        "QPushButton:disabled {"
                                        "background-color: #ccc;"
                                        "color: #888;"
                                        "border: 2px solid #ccc;"
                                        "}");
    playFourRandomButton->setFixedSize(180, 50);
    connect(playFourRandomButton, &QPushButton::clicked, this, &MainWindow::playFourRandomButtonClicked);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Free exercise button
void MainWindow::createFreeExerciseButton() {
    freeExerciseButton = new QPushButton("Free Exercise", this);
    freeExerciseButton->setToolTip("Click to start the free exercise option");
    freeExerciseButton->setStyleSheet("QPushButton {"
                                      "background-color: #FFA500;"
                                      "color: black;"
                                      "border: 2px solid #FF8C00;"
                                      "border-radius: 5px;"
                                      "font-size: 16px;"
                                      "}"
                                      "QPushButton:hover {"
                                      "background-color: #FF8C00;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: #FF7700;"
                                      "}"
                                      "QPushButton:disabled {"
                                      "background-color: #ccc;"
                                      "color: #888;"
                                      "border: 2px solid #ccc;"
                                      "}");
    freeExerciseButton->setFixedSize(180, 50);
    connect(freeExerciseButton, &QPushButton::clicked, this, &MainWindow::playFreeExerciseButtonClicked);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Stop button
void MainWindow::createStopButton() {
    stopButton = new QPushButton("Stop", this);
    stopButton->setToolTip("Click to stop the Video playback");
    stopButton->setStyleSheet("QPushButton {"
                              "background-color: #A72118;"
                              "color: black;"
                              "border: 2px solid #800E0A;"
                              "border-radius: 5px;"
                              "font-size: 16px;"
                              "}"
                              "QPushButton:hover {"
                              "background-color: #800E0A;"
                              "}"
                              "QPushButton:pressed {"
                              "background-color: #570907;"
                              "}");
    stopButton->setFixedSize(100, 50);
    connect(stopButton, &QPushButton::clicked, this, &MainWindow::stopButtonClicked);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Exit button
void MainWindow::createExitButton() {
    exitButton = new QPushButton("Exit", this);
    exitButton->setToolTip("Click to exit");
    exitButton->setStyleSheet("QPushButton {"
                              "background-color: #1A8B37;"
                              "color: black;"
                              "border: 2px solid #0D6C29;"
                              "border-radius: 5px;"
                              "font-size: 16px;"
                              "}"
                              "QPushButton:hover {"
                              "background-color: #0D6C29;"
                              "}"
                              "QPushButton:pressed {"
                              "background-color: #075119;"
                              "}");
    exitButton->setFixedSize(100, 50);
    connect(exitButton, &QPushButton::clicked, qApp, &QApplication::quit);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Instructions button
void MainWindow::createInstructionsButton() {
    instructionsButton = new QPushButton("Instructions", this);
    instructionsButton->setToolTip("Click to show instructions");
    instructionsButton->setStyleSheet("QPushButton {"
                                      "background-color: #3498db;"
                                      "color: black;"
                                      "border: 2px solid #2980b9;"
                                      "border-radius: 5px;"
                                      "font-size: 16px;"
                                      "}"
                                      "QPushButton:hover {"
                                      "background-color: #2980b9;"
                                      "}"
                                      "QPushButton:pressed {"
                                      "background-color: #1f6697;"
                                      "}"
                                      "QPushButton:disabled {"
                                      "background-color: #ccc;"
                                      "color: #888;"
                                      "border: 2px solid #ccc;"
                                      "}");
    instructionsButton->setFixedSize(100, 50);
    connect(instructionsButton, &QPushButton::clicked, this, &MainWindow::instructionButtonClicked);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
  A vertical line to separate
  the play buttons
*/
void MainWindow::createSeparator() {
    separator = new QFrame;
    separator->setFrameShape(QFrame::VLine);
    separator->setFrameShadow(QFrame::Plain);
    separator->setLineWidth(2);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Add buttons to button layout
void MainWindow::addToButtonsLayout() {
    buttonLayout->addWidget(playOneRandomButton);
    buttonLayout->addWidget(playTwoRandomButton);
    buttonLayout->addWidget(playThreeRandomButton);
    buttonLayout->addWidget(playFourRandomButton);
    buttonLayout->addWidget(freeExerciseButton);
    buttonLayout->addWidget(separator);
    buttonLayout->addWidget(stopButton);
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(instructionsButton);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Add stuff to main layout
void MainWindow::addToMainLayout() {
    mainLayout->addWidget(videoPlayer);
    mainLayout->addLayout(buttonLayout);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Play 1 video button clicked
void MainWindow::playOneRandomButtonClicked() {
    oneRandomVideos = true;
    videoPlayer->handleVideoPlayback();
    disablePlayButtons();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Play 2 videos button clicked
void MainWindow::playTwoRandomButtonClicked() {
    twoRandomVideos = true;
    videoPlayer->handleVideoPlayback();
    disablePlayButtons();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Play 3 videos button clicked
void MainWindow::playThreeRandomButtonClicked() {
    threeRandomVideos = true;
    videoPlayer->handleVideoPlayback();
    disablePlayButtons();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Play 4 videos button clicked
void MainWindow::playFourRandomButtonClicked() {
    fourRandomVideos = true;
    videoPlayer->handleVideoPlayback();
    disablePlayButtons();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Free exercise button clicked
void MainWindow::playFreeExerciseButtonClicked() {
    freeExercise = true;
    videoPlayer->handleVideoPlayback();
    disablePlayButtons();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Stop button clicked
void MainWindow::stopButtonClicked() {
    stopped = true;
    videoPlayer->handleVideoPlayback();
    enablePlayButtons();
    initializeFlags();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Instructions button clicked
void MainWindow::instructionButtonClicked() {
    InstructionsWindow* instructionsWindow = new InstructionsWindow;
    instructionsWindow->show();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Set the video folder path
void MainWindow::setVideosFolderPath(const QString& folderPath) {
    videosFolderPath = folderPath;
    // Pass the folder path to the VideoPlayer
    videoPlayer->setVideoFolder(videosFolderPath);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Initialize the flags
void MainWindow::initializeFlags() {
    oneRandomVideos = false;
    twoRandomVideos = false;
    threeRandomVideos = false;
    fourRandomVideos = false;
    freeExercise = false;
    stopped = false;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
  Disable the buttons when
  the exercise has started
*/
void MainWindow::disablePlayButtons() {
    playOneRandomButton->setEnabled(false);
    playTwoRandomButton->setEnabled(false);
    playThreeRandomButton->setEnabled(false);
    playFourRandomButton->setEnabled(false);
    freeExerciseButton->setEnabled(false);
    instructionsButton->setEnabled(false);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Re-enable the buttons
void MainWindow::enablePlayButtons() {
    playOneRandomButton->setEnabled(true);
    playTwoRandomButton->setEnabled(true);
    playThreeRandomButton->setEnabled(true);
    playFourRandomButton->setEnabled(true);
    freeExerciseButton->setEnabled(true);
    instructionsButton->setEnabled(true);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
  Getter functions
  to retrieve the corresponing
  flag, of which button is pressed
*/
bool MainWindow::getOneRandomVideosVariable() {
    return oneRandomVideos;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool MainWindow::getTwoRandomVideosVariable() {
    return twoRandomVideos;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool MainWindow::getThreeRandomVideosVariable() {
    return threeRandomVideos;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool MainWindow::getfourRandomVideosVariable() {
    return fourRandomVideos;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool MainWindow::getFreeExerciseVariable() {
    return freeExercise;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool MainWindow::getStoppedVariable() {
    return stopped;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
