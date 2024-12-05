#include "Audio.h"
#include "Window.h"
#pragma comment(lib, "winmm.lib")

Audio::Audio(const char* Filename) {
	std::thread SoundHandler(PlayAudio, Filename);
	SoundHandler.detach();
}

void PlayAudio(const char* Filename) {
    // This part is mostly AI Generated btw (Because i'm a little too dumb for this). 
    int size_needed = MultiByteToWideChar(CP_ACP, 0, Filename, -1, NULL, 0);
    wchar_t* wFilename = new wchar_t[size_needed];
    MultiByteToWideChar(CP_ACP, 0, Filename, -1, wFilename, size_needed);

    // Play the sound file
    while (true) {
        PlaySound(wFilename, NULL, SND_FILENAME | SND_ASYNC);
        std::this_thread::sleep_for(std::chrono::seconds(60));
    }
    
    // Clean up allocated memory
    delete[] wFilename;
}