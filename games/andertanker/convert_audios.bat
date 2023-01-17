..\..\tools\ffmpeg\bin\ffmpeg -i music\BackgroundMusic.wav -y -acodec pcm_s16le -ac 2 -ar 44100 cdrom\audio\track01.wav

..\..\tools\wav2vag\wav2vag.exe sfx\Fire.wav data\Fire.vag
..\..\tools\wav2vag\wav2vag.exe sfx\Hit.wav data\Hit.vag
..\..\tools\wav2vag\wav2vag.exe sfx\Miss.wav data\Miss.vag