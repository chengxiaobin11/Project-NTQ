@echo off
setlocal enabledelayedexpansion
::chcp 65001

:: 定义路径
set PROJECT_ROOT=%cd%
set SRC_DIR=%PROJECT_ROOT%\Output\RL6449_Project
set DST_DIR=%PROJECT_ROOT%\CustomerBin
set SRC_FILE=RL6449_Project_WithChkSum.bin
set BUILD_TOOL=%PROJECT_ROOT%\Tool\build

:: 创建目标文件夹（如果不存在）
if not exist "%DST_DIR%" (
    echo Create folder：%DST_DIR%
    mkdir "%DST_DIR%"
)

:: 定义Bin name
set sw_info=%DST_DIR%\sw_info.txt
%BUILD_TOOL%\customertools\gcc_customer\tcc.exe -E -dM %BUILD_TOOL%\customertools\gcc_customer\gcc_customer.c | findstr /c:"define CUSTOMER_BIN_NAME " > %sw_info%

for /f "tokens=3" %%i in ('findstr "CUSTOMER_BIN_NAME" %sw_info%') do (
    set CUSTOMER_BIN_NAME=%%i
    set CUSTOMER_BIN_NAME=!CUSTOMER_BIN_NAME:"=!
)

:: 获取当前日期
for /f "tokens=2 delims==" %%a in ('wmic os get LocalDateTime /value 2^>nul') do set datetime=%%a
for /f "tokens=1-3 delims=/- " %%a in ('echo %date%') do (
	set year=%%a
	set month=%%b
	set day=%%c
)
set _DATE=!year!!month!!day!

:: 获取checksum
echo Get Bin file checksum ...
echo ************************************************************
set binName=%SRC_DIR%\%SRC_FILE%
%BUILD_TOOL%\customertools\GetVersion.exe %binName% bin
echo ***********************Get Checksum*************************
for /f "delims=[" %%i in (getversion.txt) do echo %%i
for /f "delims=" %%i in ('find "R_" ^< getversion.txt') do (set tempStr=%%i)
for %%i in (%tempStr%) do (set tempStr=%%i)
set CHECKSUM=%tempStr:"=%
echo ************************************************************
echo Get Bin file checksum and...
set CHECKSUM=%CHECKSUM:~-6%

:: 默认后缀
set _SUFFIX=HQ

:: 拼接最终文件名（不含扩展名）
set FINAL_NAME=%CUSTOMER_BIN_NAME%_%_DATE%_%CHECKSUM%_%_SUFFIX%
set DST_FILE=%FINAL_NAME%.bin

:: 检查源文件是否存在
if not exist "%SRC_DIR%\%SRC_FILE%" (
    echo Error: Source file does not exist - "%SRC_DIR%\%SRC_FILE%"
    pause
    exit /b 1
)

:: 检查 CustomerBin 文件夹下是否有任何 .bin 文件，如果有则全部删除
if exist "%DST_DIR%\*.bin" (
    echo bin file has been detected
    del "%DST_DIR%\*.bin"
    echo All bin files have been deleted
) else (
    echo No bin file in the CustomerBin directory, there is no need to delete it
)

:: 复制并重命名文件
echo Copying file ..
copy "%SRC_DIR%\%SRC_FILE%" "%DST_DIR%\%DST_FILE%"

:: 检查是否复制成功
if exist "%DST_DIR%\%DST_FILE%" (
    echo File generated: %DST_FILE%
) else (
    echo File copy failed!
    pause
    exit /b 1
)
