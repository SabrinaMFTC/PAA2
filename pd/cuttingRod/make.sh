gcc cutRodRecursive.c -o cutRodRecursive.exe
gcc cutRodTopDown.c -o cutRodTopDown.exe
gcc cutRodBottomUp.c -o cutRodBottomUp.exe
./cutRodRecursive.exe
./cutRodTopDown.exe
./cutRodBottomUp.exe

rm -if *.exe
