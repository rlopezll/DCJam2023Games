..\tools\wav2vag\wav2vag.exe audios\sword_sfx.wav audios\sword.vag
..\tools\wav2vag\wav2vag.exe audios\monster_sfx.wav audios\monster.vag

..\tools\ffmpeg\bin\ffmpeg -i audios\BlackSmith_menus.wav -y -acodec pcm_s16le -ac 2 -ar 44100 music\track01.wav
..\tools\ffmpeg\bin\ffmpeg -i audios\BlackSmith_game.wav -y -acodec pcm_s16le -ac 2 -ar 44100 music\track02.wav