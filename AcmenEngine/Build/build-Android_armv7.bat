path=E:\android\android-ndk-r10e;%path%

REM type Include\macros.h

cd ..\Project\NDK
call ndk-build clean
call ndk-build

pause