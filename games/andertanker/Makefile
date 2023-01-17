TARGET = MAIN
TYPE = ps-exe

SRCS = main.c\
		../../third_party/common/syscalls/printf.s \
		../../third_party/common/crt0/crt0.s \
		dcLibPsx/src/dcMemory.c\
		dcLibPsx/src/dcMesh.c\
		dcLibPsx/src/dcCamera.c\
		dcLibPsx/src/dcMath.c\
		dcLibPsx/src/dcRender.c\
		dcLibPsx/src/dcCollision.c\
		dcLibPsx/src/dcMisc.c\
		dcLibPsx/src/dcLevel.c\
		dcLibPsx/src/dcSprite.c\
		dcLibPsx/src/dcAudio.c\
		dcLibPsx/src/dcFont.c\
		character.c\
		textures/smile.tim\
		textures/colorpallete.tim\
		data/Fire.vag\
		data/Hit.vag\
		data/Miss.vag\
		data/accept.vag\
		data/beep.vag\
		data/bell.vag\
		projectile.c\
		explotion.c\
		textures/Letra_A.tim\
		textures/Pala.tim\
		textures/floor_texture.tim\
		textures/red_tank_texture.tim\
		textures/blue_tank_texture.tim\
		textures/white.tim\
		
CPPFLAGS += -I../../third_party/common
CPPFLAGS += -I../../third_party/psyq/include
CPPFLAGS += -I./dcLibPsx/include
CPPFLAGS += -I./
LDFLAGS += -L../../third_party/psyq/lib
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

include ../../third_party/common.mk
