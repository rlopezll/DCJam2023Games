rm myimage.iso
rm myimage.cue
copy ..\source_andertanker\MAIN.ps-exe cdrom\andertanker.exe
copy ..\source_blacksmith\MAIN.ps-exe cdrom\blacksmith.exe
copy ..\source_captain\MAIN.ps-exe cdrom\captain.exe
copy ..\source_descontrol\MAIN.ps-exe cdrom\descontrol.exe
copy MAIN.ps-exe cdrom\MAIN.exe
..\tools\mkpsxiso\mkpsxiso-2.02-win64\bin\mkpsxiso.exe -lba cdrom\cd.lba -y cdrom\makeiso.xml