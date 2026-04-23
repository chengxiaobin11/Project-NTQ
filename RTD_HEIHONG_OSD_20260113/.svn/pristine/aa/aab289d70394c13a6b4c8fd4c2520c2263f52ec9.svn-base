@echo off
setlocal enabledelayedexpansion

REM 设置脚本根目录
set "ROOT_DIR=%~dp0"

REM 1. 执行Project\Header下的GetPrjName.bat
echo 正在执行GetPrjName.bat...
call "%ROOT_DIR%Project\Header\GetPrjName.bat"

REM 2. 读取Tool\build\PRJ_ID.txt第一行内容到变量PRJ_NAME
echo 正在读取项目名称...
if exist "%ROOT_DIR%Tool\build\PRJ_ID.txt" (
    set /p "PRJ_NAME=" < "%ROOT_DIR%Tool\build\PRJ_ID.txt"
    echo 项目名称: !PRJ_NAME!
) else (
    echo 错误: 找不到PRJ_ID.txt文件
    pause
    exit /b 1
)

REM 3.获取当前日期（格式依赖于系统区域设置）
echo 系统默认日期格式: %date%

REM 从日期字符串中提取年、月、日（假设格式为 yyyy/MM/dd 或类似）
set year=%date:~0,4%
set month=%date:~5,2%
set day=%date:~8,2%

echo 提取的年月日: %year%%month%%day%

REM 4. 复制并重命名文件到Bin目录
echo 正在复制并重命名文件到Bin目录...
set "SOURCE_FILE=%ROOT_DIR%Output\RL6449_Project\RL6449_Project_WithChkSum.bin"
set "TARGET_FILE=%ROOT_DIR%Bin\!PRJ_NAME!_!year!!month!!day!.bin"

if exist "!SOURCE_FILE!" (
    copy "!SOURCE_FILE!" "!TARGET_FILE!" >nul
    echo 文件已成功复制并重命名为: !TARGET_FILE!
) else (
    echo 错误: 找不到源文件 !SOURCE_FILE!
    pause
    exit /b 1
)

echo 所有操作完成！
pause