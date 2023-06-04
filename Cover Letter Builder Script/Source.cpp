#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include "PropmtConstructor.h"




//using namespace std;
//namespace fs = std::filesystem;
//using namespace fs;
void printcolormesg(std::string color, std::string mesg);
void printwelcomemesg();
int main()
{

    std::string configfilename;
    printwelcomemesg();
    std::getline(std::cin, configfilename);
    configfilename += ".ini";

     // promter is a object that wraps around settings
    Promter* Promtptr = new Promter(std::filesystem::current_path(), configfilename);
    if (Promtptr->foundconfig == true) {

        printcolormesg("cyan", "Cover letter build started.");
        printcolormesg("cyan", "Getting Info");
        //Promtptr->SettingsPtr->configbounds[]

        Promtptr->file_info_in(Promtptr->info_contex, Promtptr->SettingsPtr->configbounds[2], Promtptr->SettingsPtr->configbounds[3]);
        printcolormesg("cyan", "Getting skill set");
        Promtptr->file_info_in(Promtptr->skillset, Promtptr->SettingsPtr->configbounds[3],Promtptr->SettingsPtr->configbounds[4] );
        printcolormesg("cyan", "Highliting your skills");
        Promtptr->file_info_in(Promtptr->skills_highlight, Promtptr->SettingsPtr->configbounds[4], Promtptr->SettingsPtr->configbounds[5]);
        printcolormesg("cyan", "Getting your traits");
        Promtptr->file_info_in(Promtptr->coretraits, Promtptr->SettingsPtr->configbounds[5], Promtptr->SettingsPtr->configbounds[6]);
        printcolormesg("cyan", "Highliting your traits");
        Promtptr->file_info_in(Promtptr->traits_highlight, Promtptr->SettingsPtr->configbounds[6], Promtptr->SettingsPtr->configbounds[7]);
        printcolormesg("cyan", "Getting the job requirements");
        Promtptr->file_info_in(Promtptr->jobquilfcation, Promtptr->SettingsPtr->configbounds[7], Promtptr->SettingsPtr->configbounds[8]);
        printcolormesg("cyan", "Getting your projects");
        Promtptr->file_info_in(Promtptr->projects, Promtptr->SettingsPtr->configbounds[8], Promtptr->SettingsPtr->configbounds[9]);
        printcolormesg("cyan", "Getting the promt");
        Promtptr->file_info_in(Promtptr->promt, Promtptr->SettingsPtr->configbounds[9], Promtptr->SettingsPtr->configbounds[10]);
        printcolormesg("cyan", "Setting tone");
        Promtptr->file_info_in(Promtptr->over_tone, Promtptr->SettingsPtr->configbounds[10], Promtptr->SettingsPtr->configbounds[11]);
        printcolormesg("cyan", "Adding extras to start");
        Promtptr->file_info_in(Promtptr->at_start, Promtptr->SettingsPtr->configbounds[11], Promtptr->SettingsPtr->configbounds[12]);
        printcolormesg("cyan", "Adding extras to end");
        Promtptr->file_info_in(Promtptr->at_end, Promtptr->SettingsPtr->configbounds[12], Promtptr->SettingsPtr->configbounds[13]);
        printcolormesg("red", "Cover letter promt is done... saving!");

        Promtptr->outputdoc();
        std::string temp = "Saved at ";
        temp.append(Promtptr->SettingsPtr->outputpathptr->string());
        
        printcolormesg("mag", temp);

    }
    else {
        //only runs if we cant open the config
        //will insta termnate the program
        delete(Promtptr);
        char exit;
        printcolormesg("green", "Press any key to exit");
        std::cin >> exit;
        return 0;
    }
    
    return 0;
}

void printwelcomemesg() {
    printcolormesg("green", "Please enter the name of the template file you want to open");
    printcolormesg("green", "Note it should NOT include file extenstion the progam will only use .ini will be used.");
    printcolormesg("green", "Note the file needs to be in the root directory of the program if it is not there it will tell you.");

}


void printcolormesg(std::string color, std::string mesg) {

    std::string colormesh = "[35m";
    switch (color[0]) {
    case 'r':
        colormesh = "[31m";
        break;
    case 'g':
        colormesh = "[32m";
        break;
    case 'y':
        colormesh = "[33m";
        break;
    case 'm':
        colormesh = "[35m";
        break;
    case 'c':
        colormesh = "[36m";
        break;
    case 'b':
        colormesh = "[34m";
        break;
    }


    std::cout<<'\033'<<colormesh << mesg <<"\033[0m"<< std::endl;
}


