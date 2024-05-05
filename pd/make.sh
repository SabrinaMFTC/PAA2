gcc changeTopDown.c -o changeTopDown.exe
gcc changeBottomUp.c -o changeBottomUp.exe
./changeTopDown.exe
./changeBottomUp.exe

rm -if *.exe
