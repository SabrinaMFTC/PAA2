gcc lcsRecursive.c -o lcsRecursive.exe
gcc lcsBottomUp.c -o lcsBottomUp.exe
gcc lcsTopDown.c -o lcsTopDown.exe
./lcsRecursive.exe
./lcsBottomUp.exe
./lcsTopDown.exe

rm -if *.exe
