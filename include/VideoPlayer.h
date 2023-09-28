//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
    KickBoxing Defense Exersise Player -
    Video Player Header File
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <QDir>
#include <QMediaPlayer>
#include <QRandomGenerator>
#include <QStringList>
#include <QTime>
#include <QTimer>
#include <QVideoWidget>

class MainWindow;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class VideoPlayer : public QVideoWidget {
    Q_OBJECT
public:
    VideoPlayer(MainWindow* mainWindow, QWidget* parent = nullptr);

    /*
      --Set the video folder
      --Play and stop the video playback
    */
    void setVideoFolder(const QString& folderPath);
    void playVideo();
    void stopVideo();

private:
    /*
      --Media Player and delay timer
      --Also, reset the videos played counter!
    */
    void createMediaPlayer();
    void createDealyTimer();
    void resetVideosPlayed();

    QMediaPlayer* mediaPlayer;
    QStringList videoFiles;
    QString videosFolderPath;
    QTimer* delayTimer;

    MainWindow* mainWindow;

    // Videos played counter
    int videosPlayed;

public slots:
    void handleVideoPlayback();

private slots:
    void handleMediaStateChanged(QMediaPlayer::State newState);
    void handleNextRandomVideoPlayback();
    void startNextVideoAfterDelay();
};

#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
