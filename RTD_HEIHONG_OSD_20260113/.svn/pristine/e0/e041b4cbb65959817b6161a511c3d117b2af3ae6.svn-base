@echo off
setlocal enabledelayedexpansion

:: 设置源文件路径和输出文件路径
set "HEADER_FILE=d:\Code\HAIQIN\RTD_HEIHONG_OSD\Project\Header\LuoGang_ProjectDefine.h"
set "OUTPUT_FILE=d:\Code\HAIQIN\RTD_HEIHONG_OSD\Tool\build\PRJ_ID.txt"

:: 检查头文件是否存在
if not exist "%HEADER_FILE%" (
    echo 错误：无法找到头文件 %HEADER_FILE%
    pause
    exit /b 1
)

:: 删除已存在的输出文件
if exist "%OUTPUT_FILE%" del "%OUTPUT_FILE%"

:: 提取Project_ID的值
for /f "tokens=3 delims= " %%a in ('findstr /c:"#define Project_ID" "%HEADER_FILE%"') do (
    set "PROJECT_ID=%%a"
    echo 找到Project_ID: !PROJECT_ID!
    echo !PROJECT_ID! > "%OUTPUT_FILE%"
)

:: 检查是否成功提取并保存
if not defined PROJECT_ID (
    echo 错误：无法在头文件中找到Project_ID定义
    pause
    exit /b 1
)

if exist "%OUTPUT_FILE%" (
    echo 成功：Project_ID值已保存到 %OUTPUT_FILE%
    echo 保存的值为: !PROJECT_ID!
) else (
    echo 错误：无法创建输出文件 %OUTPUT_FILE%
    pause
    exit /b 1
)

exit /b 0