#ifndef AUDIO_H
#define AUDIO_H
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <thread>
#include <atomic>
#include <ctime>

class Audio
{
public:
	Audio(const char* Filename);
};

void PlayAudio(const char* Filename);

#endif