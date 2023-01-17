include ./makeIncludes/textures
include ./makeIncludes/sfx
TARGET = MAIN
TYPE = ps-exe

SRCS = main.c \
		${TEXTURES_LIST} \
		${AUDIO_LIST} \
		../third_party/common/syscalls/printf.s \
		../third_party/common/crt0/crt0.s \
		dcLibPsx/src/dcMemory.c\
		dcLibPsx/src/dcCamera.c\
		dcLibPsx/src/dcMath.c\
		dcLibPsx/src/dcRender.c\
		dcLibPsx/src/dcCollision.c\
		dcLibPsx/src/dcMisc.c\
		dcLibPsx/src/tdGameplay.c\
		dcLibPsx/src/dcAudio.c\
		riverGameMode.c\
		titleGameMode.c\
		tdConfig.c\

CPPFLAGS += -I../third_party/common
CPPFLAGS += -I../third_party/psyq/include
CPPFLAGS += -I./dcLibPsx/include
CPPFLAGS += -I./assets
CPPFLAGS += -I./scenes
LDFLAGS += -L../third_party/psyq/lib
LDFLAGS += -Wl,--start-group
LDFLAGS += -lapi
LDFLAGS += -lc
LDFLAGS += -lc2
LDFLAGS += -lcard
LDFLAGS += -lcomb
LDFLAGS += -lds
LDFLAGS += -letc
LDFLAGS += -lgpu
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
LDFLAGS += -lcd
LDFLAGS += -Wl,--end-group

include ../third_party/common.mk
