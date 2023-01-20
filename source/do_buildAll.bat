make clean
make CFLAGS="-DWITH_CD=1 -DTRACKS_MUSIC_OFFSET=5"
cd ..\games\andertanker
make clean
make CFLAGS=-DTRACKS_MUSIC_OFFSET=0
cd ..\blacksmith
make clean
make CFLAGS=-DTRACKS_MUSIC_OFFSET=1
cd ..\captain
make clean
make CFLAGS=-DTRACKS_MUSIC_OFFSET=0
cd ..\descontrol
make clean
make CFLAGS=-DTRACKS_MUSIC_OFFSET=3
cd ..\..\source
