@echo off
title Building
%SYSTEMROOT%\Microsoft.NET\Framework\v4.0.30319\msbuild.exe /t:Build /p:Configuration=Debug smart_house.sln
title Done
echo  
pause 
