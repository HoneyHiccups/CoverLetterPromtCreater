
//Prompt Connstroctor

#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>


class settings {
public:

	std::string configbounds[14] = {
	"[{#Output dir#}]",                                   // 0
	"[{#Output file Name#}]",                             // 1
	"[{#Info about you and general context#}]",           // 2
	"[{#Your skill set#}]",                               // 3
	"[{#Skills that you think should be highlighted#}]",  // 4
	"[{#Core traits about you#}]",                        // 5
	"[{#Traits about you that should be highlighted#}]",  // 6
	"[{#Job qualifications#}]",                           // 7
	"[{#Projects that you are working on#}]",             // 8
	"[{#Prompt template thesis#}]",                       // 9
	"[{#Overall Tone#}]",                                 // 10
	"[{#Added to the start of prompt#}]",                 // 11
	"[{#Added to the end of prompt#}]",                   // 12
	"[{#End Config#}]"                                    // 13

	};

	std::filesystem::path configpath;
	std::filesystem::path* outputpathptr;
	bool setconfig(std::filesystem::path configbasepath, std::string configfilename);
	std::string configpath_string();
	std::string get_string();
	void makeconfig(std::string filename);
};

class Promter { // needs to have a constructed settings to be constructed
public:
	
	bool foundconfig = false;
	std::string skillset;
	std::string coretraits;
	std::string jobquilfcation;
	std::string over_tone;
	std::string info_contex;
	std::string projects;
	std::string promt;
	std::string at_start;
	std::string at_end;
	std::string traits_highlight;
	std::string skills_highlight;
	


	settings* SettingsPtr;

	void file_info_in(std::string& var_to_fill, std::string bounds_on, std::string bounds_off);

	
	void outputdoc();

	Promter(std::filesystem::path configpath, std::string configfilename );
	~Promter();


};


