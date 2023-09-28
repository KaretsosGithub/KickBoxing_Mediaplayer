//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
    KickBoxing Defense Exersise Player -
    Video Player Source File
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "include/VideoPlayer.h"
#include "include/MainWindow.h"

/*  ------------For debugging purposes------------------------
#include <QDebug>
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

VideoPlayer::VideoPlayer(MainWindow* mainWindow, QWidget* parent)
    : QVideoWidget(parent)
    , mainWindow(mainWindow) {

    /*
      Create the media player,
      delay timer.
      Also, a function to reset
      the timer
      Set videos played counter to zero
    */
    createMediaPlayer();
    createDealyTimer();
    resetVideosPlayed();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Create the media player
void VideoPlayer::createMediaPlayer() {
    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setVideoOutput(this);
    connect(mediaPlayer, &QMediaPlayer::stateChanged, this, &VideoPlayer::handleMediaStateChanged);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Create the delay timer
void VideoPlayer::createDealyTimer() {
    delayTimer = new QTimer(this);
    // We want the timer to fire only once
    delayTimer->setSingleShot(true);
    connect(delayTimer, &QTimer::timeout, this, &VideoPlayer::startNextVideoAfterDelay);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Set video folder path
void VideoPlayer::setVideoFolder(const QString& folderPath) {
    QDir videoFolder(folderPath);
    videoFiles = videoFolder.entryList(QStringList() << "*.mp4", QDir::Files);
    videosFolderPath = folderPath;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Handle the video playback
void VideoPlayer::handleVideoPlayback() {
    if (mainWindow->getStoppedVariable() == true) {
        stopVideo();
        return;
    }
    if (!videoFiles.isEmpty()) {
        playVideo();
        return;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Play a random video from the folder
void VideoPlayer::playVideo() {
    // Generate a random index within the range of video files in the folder
    int randomIndex = QRandomGenerator::global()->bounded(videoFiles.size());

    QString fullPath = QDir(videosFolderPath).filePath(videoFiles[randomIndex]);

    /*  ------------For debugging purposes------------------------
    qDebug() << "--------------------------------------";
    qDebug() << "Playing video:" << fullPath;
    qDebug() << "Flag check : oneRandomVideos = " << mainWindow->getOneRandomVideosVariable();
    qDebug() << "Flag check : twoRandomVideos = " << mainWindow->getTwoRandomVideosVariable();
    qDebug() << "Flag check : threeRandomVideos = " << mainWindow->getThreeRandomVideosVariable();
    qDebug() << "Flag check : fourRandomVideos = " << mainWindow->getfourRandomVideosVariable();
    qDebug() << "Flag check : freeExercise = " << mainWindow->getFreeExerciseVariable();
    qDebug() << "Flag check : Stopped = " << mainWindow->getStoppedVariable();

    */

    // Play the video corresponing to the random index
    mediaPlayer->setMedia(QUrl::fromLocalFile(fullPath));
    mediaPlayer->play();

    // Videos played counter increased by 1
    videosPlayed++;

    /*  ------------For debugging purposes------------------------
    qDebug() << "videos Played = " << videosPlayed;
    */
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Stop the video
void VideoPlayer::stopVideo() {
    mediaPlayer->stop();
    delayTimer->stop();
    resetVideosPlayed();

    /*  ------------For debugging purposes------------------------

    qDebug() << "--------------------------------------";
    qDebug() << "Flag check : Stopped = " << mainWindow->getStoppedVariable();
    qDebug() << "Video Playback stopped by the user!";
    qDebug() << "--------------------------------------";
    */
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Handle the media player state
void VideoPlayer::handleMediaStateChanged(QMediaPlayer::State newState) {
    // If the video playback ends, play the next random video
    if (newState == QMediaPlayer::StoppedState) {
        if (mainWindow->getStoppedVariable() == true) {
            return;
        }
        if (mainWindow->getOneRandomVideosVariable() == true) {
            if (videosPlayed == 1) {

                /*  ------------For debugging purposes------------------------
                qDebug() << "--------------------------------------";
                qDebug() << "Played :" << videosPlayed << "videos";
                qDebug() << "Start delay timer for 4 seconds";
                */

                // Start the 4-second delay timer
                delayTimer->start(4000);
            }
            handleNextRandomVideoPlayback();
        } else if (mainWindow->getTwoRandomVideosVariable() == true) {
            if (videosPlayed == 2) {

                /*  ------------For debugging purposes------------------------
                qDebug() << "--------------------------------------";
                qDebug() << "Played :" << videosPlayed << "videos";
                qDebug() << "Start delay timer for 4 seconds";
                */

                // Start the 4-second delay timer
                delayTimer->start(4000);
            }
            handleNextRandomVideoPlayback();
        } else if (mainWindow->getThreeRandomVideosVariable() == true) {
            if (videosPlayed == 3) {

                /*  ------------For debugging purposes------------------------
                qDebug() << "--------------------------------------";
                qDebug() << "Played :" << videosPlayed << "videos";
                qDebug() << "Start delay timer for 4 seconds";
                */

                // Start the 4-second delay timer
                delayTimer->start(4000);
            }
            handleNextRandomVideoPlayback();
        } else if (mainWindow->getfourRandomVideosVariable() == true) {
            if (videosPlayed == 4) {

                /*  ------------For debugging purposes------------------------
                qDebug() << "--------------------------------------";
                qDebug() << "Played :" << videosPlayed << "videos";
                qDebug() << "Start delay timer for 4 seconds";
                */

                // Start the 4-second delay timer
                delayTimer->start(4000);
            }
            handleNextRandomVideoPlayback();
        } else if (mainWindow->getFreeExerciseVariable() == true) {
            if (videosPlayed == 1) {
                /*
                  Random double between 0 and 1
                  Scale to the range [1, 2.3]
                */
                double randomDelay = QRandomGenerator::global()->generateDouble();
                double scaledDelay = 1.0 + randomDelay * 1.3;
                // Convert the delay time to milliseconds
                int delayMilliseconds = static_cast<int>(scaledDelay * 1000);

                /*  ------------For debugging purposes------------------------
                qDebug() << "--------------------------------------";
                qDebug() << "Played :" << videosPlayed << "videos";
                qDebug() << "Start delay timer for " << delayMilliseconds << "milliseconds";
                */

                // Start the 4-second delay timer
                delayTimer->start(delayMilliseconds);
            }
            handleNextRandomVideoPlayback();
        }
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Handle the next video playback
void VideoPlayer::handleNextRandomVideoPlayback() {
    /*
      If a video is currently playing or the delay timer is active,
      skip calling this function until it's ready
    */
    if (mediaPlayer->state() == QMediaPlayer::PlayingState || delayTimer->isActive()) {
        return;
    }
    handleVideoPlayback();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Start the next video
void VideoPlayer::startNextVideoAfterDelay() {
    /*  ------------For debugging purposes------------------------
    qDebug() << "Delay is over. Starting next video...";
    */
    resetVideosPlayed();
    handleNextRandomVideoPlayback();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Reset the videosPlayed
void VideoPlayer::resetVideosPlayed() {
    videosPlayed = 0;
    /*  ------------For debugging purposes------------------------
    qDebug() << "Videos Played counter reset to: " << videosPlayed;
    */
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
