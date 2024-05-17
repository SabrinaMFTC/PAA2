gcc mcmRecursive.c -o mcmRecursive.exe
gcc mcmBottomUp.c -o mcmBottomUp.exe
gcc mcmTopDown.c -o mcmTopDown.exe

./mcmRecursive.exe
./mcmBottomUp.exe
./mcmTopDown.exe

rm -if *.exe
