/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <unistd.h>

#include <Parser.hpp>

/* Library */
#include <FileSystemPlusPlus.h>
#include <StringTools.hpp>

std::string Path() {
	std::string pth(getenv("HOME"));
	pth.append("/");
	pth.append(".copyboard_data");
	return pth;
}

/*
	Example:
		tag =:  worldhello; data = hello world
		tag =:  copyboardhello; data = hello copyboard
		tag =:  fegeyahello; data = hello fegeya
		tag =:  cpphello; data = hello c++
*/
void
FCopyboardParser::ListAll() {
	std::string data = fsplusplus::ReadFileWithReturn(Path());
	if(data != "null") {
		std::string line_by_line, number, list_data;
		std::istringstream all_data(data);
		while(std::getline(all_data, line_by_line)) {
			if(strstr(line_by_line.c_str(), "tag =:")) {
				number = stringtools::GetBetweenString(line_by_line, "tag =:", "; ");
				number = stringtools::EraseAllSubString(number, " ");
				list_data = stringtools::EraseAllSubString(line_by_line, "tag =:  " + number + "; data = ");
				std::cout << "------------\n|| Tag = " + number + "\n|| Data = " + list_data << "\n";
			}
		} 
	} else {
		fsplusplus::CreateFileWithoutAppend(Path());
	}
}

void
FCopyboardParser::Add(std::string tag, std::string data) {
	std::ofstream outfile;

  	outfile.open(Path(), std::ios_base::app); // append instead of overwrite
  	outfile << "tag =:  " + tag + "; data = " + data + "\n";
	
	outfile.close();
}
