..\tools\ffmpeg\bin\ffmpeg -i music\MainMenu_Song.mp3 -y -acodec pcm_s16le -ac 2 -ar 44100 cdrom\audio\track01.wav
..\tools\ffmpeg\bin\ffmpeg -i music\GameplayTheme.mp3 -y -acodec pcm_s16le -ac 2 -ar 44100 cdrom\audio\track02.wav

..\tools\wav2vag\wav2vag.exe audio\HeartLoose.wav data\HeartLoose.vag
..\tools\wav2vag\wav2vag.exe audio\ItemIlegal.wav data\ItemIlegal.vag
..\tools\wav2vag\wav2vag.exe audio\ItemOK.wav data\ItemOK.vag
..\tools\wav2vag\wav2vag.exe audio\PressStart.wav data\PressStart.vag