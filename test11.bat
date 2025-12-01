@echo off
setlocal enabledelayedexpansion

if "%~1"=="" (
    set args=1 2 
) else (
    set args=%*
)

for %%i in (!args!) do (
    g++ main.cpp -o main > nul
    main %%i > Test\output%%i.txt
    fc Test\output%%i.txt Test\expected%%i.txt > nul
    if errorlevel 1 (
        echo Test %%i: FAIL
    ) else (
        echo Test %%i: PASS
    )
)