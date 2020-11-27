#include "Level1.h"

#include "AudioFile.h"

void Level1::startLevel()
{
    player_.printState();

    AudioFile<double> audioFile;
    audioFile.load ("/path/to/my/audiofile.wav");
}