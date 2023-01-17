
SET FILE_NAME=
SET ORG= 1
SET CULT= 0,0
SET BITS = 8

GOTO :loop

:usage
  
cd ../../tools/BMP2TIM 
BMP2TIM ../../source/textures/%FILE_NAME%.bmp ../../source/textures/TIM/%FILE_NAME%.tim %BITS% -org=%ORG% -cult=%CULT%

cd ../../source/textures/

  exit /b 1



:loop
IF NOT "%1"=="" (
    IF "%1"=="-file" (
      SET FILE_NAME=%2
	  
    ) ELSE ( IF "%1"=="-org" (
      SET ORG=%2
	  SHIFT
    )ELSE(
      echo "Unknown argument '%1'"
      goto :usage

    ) )

    SHIFT /1
    GOTO :loop
)