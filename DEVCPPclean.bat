@echo off
chcp 65001 >nul
echo 🧹 正在清理 Dev-C++ 生成的可执行文件...

:: 删除当前目录及子目录下所有 .exe 文件
del /q /s *.exe 2>nul

:: 删除 Dev-C++ 生成的临时文件和编译目录
del /q /s *.o 2>nul
del /q /s *.obj 2>nul
del /q /s *.bak 2>nul
rd /s /q obj 2>nul
rd /s /q bin 2>nul

echo ✅ 清理完成！已删除所有 .exe 及临时文件。
pause