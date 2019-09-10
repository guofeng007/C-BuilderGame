rem @echo off
set /p param=«Î ‰»Îgitµÿ÷∑
echo "%param%"
if "%param%"=="" pause
git init 
git remote add origin %param%
git pull origin master
git merge origin/master
git add *
git add *.*
git commit -m "init"
git push origin master
pause
