qmake Src.pro -o build/makefile
cd build
mingw32-make
cd ..
mkdir bin
move build\release\Src.exe bin\Src.exe
cd bin
windeployqt Src.exe
copy ..\src\database\Scoreboard.db .\
cd ..