#include "PropmtConstructor.h"
#include <iostream>
#include <fstream>

Promter::Promter(std::filesystem::path configpath, std::string configfilename) {
	this->SettingsPtr = new settings();
	this->foundconfig = this->SettingsPtr->setconfig(configpath, configfilename);
}


void Promter::file_info_in(std::string& var_to_fill, std::string bounds_on, std::string bounds_off) {

	std::string filter;
	std::string* var_to_fillptr = &var_to_fill;
	bool saving = false;
	std::fstream cf_file;
	cf_file.open(this->SettingsPtr->configpath_string(), std::ios::in); // this is not working this->SettingsPtr->get_string() needs fix
	if (cf_file.is_open()) {
		while (std::getline(cf_file, filter))
		{
			if (filter.find(bounds_off) != std::string::npos) { saving = false; }
			if (saving == true) { var_to_fillptr->append(filter + "\n"); }
			if (filter.find(bounds_on) != std::string::npos) { saving = true; }
		}
	}
	cf_file.close();
}
void Promter::outputdoc() {
	std::fstream outfile;
	outfile.open(this->SettingsPtr->get_string(), std::ios::out);
	if (outfile.is_open()) {
		outfile << at_start << std::endl;
		outfile << promt << std::endl;
		outfile << info_contex << std::endl;
		outfile << skillset << std::endl;
		outfile << skills_highlight << std::endl;
		outfile << jobquilfcation << std::endl;
		outfile << coretraits << std::endl;
		outfile << traits_highlight << std::endl;
		outfile << projects << std::endl;
		outfile << over_tone << std::endl;
		outfile << at_end << std::endl;
	}
	outfile.close();
}


Promter::~Promter() { 
	delete(SettingsPtr);
}

