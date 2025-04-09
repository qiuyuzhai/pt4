"C:/Program Files (x86)/Embarcadero/Dev-Cpp/TDM-GCC-64/bin/g++.exe" ^
-std=c++14 -m32 -fdata-sections -ffunction-sections -s -oS -Og -O2 ^
-shared pt4taskmaker.cpp pt4taskmakerX.cpp ^
TimD_en.cpp ^
-o PT4TimD_en.dll ^
pt4taskmaker.def ^
-Wl,--enable-stdcall-fixup,--gc-sections