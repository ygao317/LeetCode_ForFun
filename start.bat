set JAVA=java
if exist "jre\bin\java.exe" (
    set JAVA=jre\bin\java.exe
)
%JAVA% -Xms256m -Xmx1024m -Djava.library.path=. -jar bulk-action-tool.jar %*

:: Note: Comment above line and use the below locale on Java to en-GB for BAT, so that the English csv formatted input is not converted to system locale
:: %JAVA% -Duser.language=en -Duser.country=GB -Djava.library.path=. -jar bulk-action-tool.jar %*

pause
