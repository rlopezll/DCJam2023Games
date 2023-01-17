TARGET = MAIN
TYPE = ps-exe

SRCS = main.c suitcase.c airport.c image.c \
		gamestate.c main_menu.c gameover.c intro.c \
		data/BombaRoja.tim \
		data/CamisetaRoja.tim \
		data/DrogasRoja.tim \
		data/AbuelaRoja.tim \
		data/BombaAzul.tim \
		data/CamisetaAzul.tim \
		data/DrogasAzul.tim \
		data/AbuelaAzul.tim \
		data/SocksRoja.tim \
		data/PistolaRoja.tim \
		data/JeringaRoja.tim \
		data/MermaidRoja.tim \
		data/SocksAzul.tim \
		data/PistolaAzul.tim \
		data/JeringaAzul.tim \
		data/MermaidAzul.tim \
		data/HeartEmpty.tim \
		data/HeartFull.tim \
		data/ButtonTriangle.tim \
		data/ButtonSquare.tim \
		data/ButtonCircle.tim \
		data/Path_Texture.tim \
		data/Path_Texture2.tim \
		data/DESCONTROL.tim \
		data/GameOver.tim \
		data/GameDev.tim \
		data/Game_Ground_P1.tim \
		data/Game_Ground_P2.tim \
		data/Scanners_Texture.tim \
		data/HeartLoose.vag \
		data/ItemOK.vag \
		data/PressStart.vag \
		../third_party/common/syscalls/printf.s \
		../third_party/common/crt0/crt0.s \
		dcLibPsx/src/dcMemory.c\
		dcLibPsx/src/dcCamera.c\
		dcLibPsx/src/dcMath.c\
		dcLibPsx/src/dcRender.c\
		dcLibPsx/src/dcInput.c\
		dcLibPsx/src/dcCollision.c\
		dcLibPsx/src/dcMisc.c\
		dcLibPsx/src/dcFont.c\
		dcLibPsx/src/dcAudio.c\
		dcLibPsx/src/dcPerformance.c\

CPPFLAGS += -I../third_party/common
CPPFLAGS += -I../third_party/psyq/include
CPPFLAGS += -I./dcLibPsx/include
CPPFLAGS += -Wno-unused-variable
LDFLAGS += -L../third_party/psyq/lib
LDFLAGS += -Wl,--start-group
LDFLAGS += -lapi
LDFLAGS += -lc
LDFLAGS += -lcd
LDFLAGS += -lc2
LDFLAGS += -lcard
LDFLAGS += -lcomb
LDFLAGS += -lds
LDFLAGS += -letc
LDFLAGS += -lgpu
LDFLAGS += -lgs
LDFLAGS += -lgte
LDFLAGS += -lgpu
LDFLAGS += -lgun
LDFLAGS += -lhmd
LDFLAGS += -lmath
LDFLAGS += -lmcrd
LDFLAGS += -lmcx
LDFLAGS += -lpad
LDFLAGS += -lpress
LDFLAGS += -lsio
LDFLAGS += -lsnd
LDFLAGS += -lspu
LDFLAGS += -ltap
LDFLAGS += -Wl,--end-group

include ../third_party/common.mk
