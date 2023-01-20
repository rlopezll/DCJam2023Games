rm myimage.bin
rm myimage.cue
copy ..\games\andertanker\MAIN.ps-exe cdrom\andertanker.exe
copy ..\games\blacksmith\MAIN.ps-exe cdrom\blacksmith.exe
copy ..\games\captain\MAIN.ps-exe cdrom\captain.exe
copy ..\games\descontrol\MAIN.ps-exe cdrom\descontrol.exe
copy MAIN.ps-exe cdrom\MAIN.exe
..\tools\mkpsxiso\mkpsxiso-2.02-win64\bin\mkpsxiso.exe -lba cdrom\cd.lba -y cdrom\makeiso.xml