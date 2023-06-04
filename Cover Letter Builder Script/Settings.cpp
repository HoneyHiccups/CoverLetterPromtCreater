//setings.cpp
#include "PropmtConstructor.h"

using namespace std;
namespace fs = std::filesystem;
using namespace fs;

bool settings::setconfig(std::filesystem::path configbasepath, std::string configfilename) {
    this->configpath = configbasepath / configfilename; // setiing the path to open config path

    outputpathptr = new std::filesystem::path();
    fstream config_file;
    config_file.open(this->configpath, ios::in); // openes config and gets config settings
    if (config_file.is_open()) {
        string line;
        int currentreadline = 1;
        while (getline(config_file, line)) {
            if (currentreadline == 2) {
                outputpathptr->assign(line); // creates outputpathptr a path pointer to where the new file will be created
            }
            if (currentreadline == 4) {
                outputpathptr->append(line);
            }
            currentreadline++;
        }
        config_file.close();   // end getting config setting
    }
    else {

        cout << "\033[31mFAILED TO OPEN TEMPLATE: CHECK FILE NAMES AND PATHS\033[0m" << endl 
            << "\033[31m Would user like to genreate a new empty template? (y/n) \033[0m" << endl;
        char tmep;
        cin >> tmep;

        if (tmep == 'y') {
            cout<< "\033[31mNew config will be created!\033[0m" <<endl;
            makeconfig(configfilename);
        }
        return false;
        
    }
    return true;
}

string settings::get_string() { // returns out file path in sting;
    string out;
    out = this->outputpathptr->string();
    return out;
}


string settings::configpath_string() {
    
    return this->configpath.string();
}


void settings::makeconfig(std::string filename) {

    std::fstream outfile;
    outfile.open(filename,ios::out);
    if (outfile.is_open()) {
        outfile<< this->configbounds[0] <<"# this needs to be on this line"<<endl;
        outfile << endl;
        outfile << this->configbounds[1] << "# this needs to be on this line" << endl;
        outfile << endl;
        outfile << this->configbounds[2] << endl;
        outfile << this->configbounds[3] << endl;
        outfile << this->configbounds[4] << endl;
        outfile << this->configbounds[5] << endl;
        outfile << this->configbounds[6] << endl;
        outfile << this->configbounds[7] << endl;
        outfile << this->configbounds[8] << endl;
        outfile << this->configbounds[9] << endl;
        outfile << this->configbounds[10] << endl;
        outfile << this->configbounds[11] << endl;
        outfile << this->configbounds[12] << endl;
        outfile << this->configbounds[13] << endl;
        outfile.close();
        cout << "\033[95mFile has been created and saved!\033[0m" << endl
            << "\033[95mSaved path is: " << std::filesystem::current_path() / filename << "\033[0m "<< endl;

        cout << "\033[95mA restart of the program is necessary\033[0m" << endl;
    }

}