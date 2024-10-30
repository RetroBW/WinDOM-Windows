@echo off
REM -- First make map file from App Studio generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by windom.HPJ. >windom.hm
echo. >>windom.hm
echo // Commands (ID_* and IDM_*) >>windom.hm
c:\msvc\bin\makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>windom.hm
echo. >>windom.hm
echo // Prompts (IDP_*) >>windom.hm
c:\msvc\bin\makehm IDP_,HIDP_,0x30000 resource.h >>windom.hm
echo. >>windom.hm
echo // Resources (IDR_*) >>windom.hm
c:\msvc\bin\makehm IDR_,HIDR_,0x20000 resource.h >>windom.hm
echo. >>windom.hm
echo // Dialogs (IDD_*) >>windom.hm
c:\msvc\bin\makehm IDD_,HIDD_,0x20000 resource.h >>windom.hm
echo. >>windom.hm
echo // Frame Controls (IDW_*) >>windom.hm
c:\msvc\bin\makehm IDW_,HIDW_,0x50000 resource.h >>windom.hm
REM -- Make help for Project WINDOM
call hc31 windom.hpj
echo.
