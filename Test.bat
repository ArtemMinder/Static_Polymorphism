@echo off
REM Запускаем сервер
echo Starting server...
start "" /B "..\Debug\Static_Polymorphism.exe" server 12345

REM Ждем пару секунд, чтобы сервер успел запуститься
timeout /t 2 /nobreak >nul

REM Запускаем клиента, который отправит файлы на сервер
echo Starting client...
start "" /B "..\Debug\Static_Polymorphism.exe" client 127.0.0.1 12345 file1.txt file2.txt file3.txt

REM Ждем завершения работы клиента
timeout /t 5 /nobreak >nul

echo Test completed.
pause
