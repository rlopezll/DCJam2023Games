TARGET = MAIN
TYPE = ps-exe

SRCS = main.c \
		Resources.c \
		engine.c \
		ContractGameState.c \
		GameLoopGameState.c \
		GameOverGameState.c \
		MenuGameState.c \
		GameVictoryGameState.c \
		Contract.c \
		scene/scene.c \
		textures/fnt.tim \
		textures/tile1.tim \
		textures/tile2.tim \
		textures/tile3.tim \
		textures/tile4.tim \
		textures/tile5.tim \
		textures/tile6.tim \
		textures/HeroWalk.tim \
		textures/EnemyBlue.tim \
		textures/EnemyGreen.tim \
		textures/EnemyYellow.tim \
		textures/EnemyRed.tim \
		textures/blue_ball.tim \
		textures/red_ball.tim \
		textures/yellow_ball.tim \
		textures/green_ball.tim \
		textures/titlescreen.tim \
		audios/sword.vag \
		audios/monster.vag \
		characters/Enemy.c\
		characters/EnemyManager.c\
		player/player.c\
		../third_party/common/syscalls/printf.s \
		../third_party/common/crt0/crt0.s \
		dcLibPsx/src/dcMemory.c\
		dcLibPsx/src/dcMesh.c\
		dcLibPsx/src/dcCamera.c\
		dcLibPsx/src/dcMath.c\
		dcLibPsx/src/dcFont.c\
		dcLibPsx/src/dcRender.c\
		dcLibPsx/src/dcCollision.c\
		dcLibPsx/src/dcMisc.c\
		dcLibPsx/src/dcSprite.c\
		dcLibPsx/src/dcAudio.c\
		
CPPFLAGS += -I../third_party/common
CPPFLAGS += -I../third_party/psyq/include
CPPFLAGS += -I./dcLibPsx/include
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
