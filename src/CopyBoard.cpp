/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstring>

/* Copyboard Parser */
#include <Parser.hpp>

/* const char [] */
#define COPYBOARD_ALL_VERSION "0.1-beta-1"

/*
	TODO: Add Major, Minor, State of Copyboard version.
*/

static void Version() {
	std::cout << "Fegeya Copyboard " << COPYBOARD_ALL_VERSION << "\n" <<
	"Fegeya Copyboard licensed under the terms of MIT License.\n";
}

/*
	Fegeya Copyboard <version>
	./copyboard --list || --la || --list_all : List board
	./copyboard ....
*/
static void Help(char **arg) {
	std::cout << "Fegeya Copyboard " << COPYBOARD_ALL_VERSION << "\n" <<
	arg[0] << " --list || --la || --list_all : List board\n" <<
	arg[0] << " --add : Add new text in board\n" <<
	arg[0] << " --version || --v : Show version\n" <<
	arg[0] << " --help || --h : Show help (here)\n";
}

static void Add() {
	std::string tag, data;
	
	std::cout << "Tag: ";
	std::getline(std::cin, tag); /* Input tag. */
	
	std::cout << "Data: ";
	std::getline(std::cin, data); /* Input data. */
	
	FCopyboardParser add;
	add.Add(tag, data); /* Call function */
}

int main(int argc, char **argv) {
    FCopyboardParser cb;
    std::string copy_arg, reg;

    if(argc > 1) {
	for(int i = 1; i < argc; i++) {
		std::string arg(argv[i]);
		reg = argv[1];
		copy_arg = arg;
	}
    } 


    if(reg.substr(0, 2) == "--") {
	   if(reg == "--list" || reg == "--la" || reg == "--list_all")
		cb.ListAll();
     	   else if(reg == "--add")
		Add();
	   else if(reg == "--help" || reg == "--h")
	   	Help(argv);
	   else if(reg == "--version" || reg == "--v")
	   	Version();
           else
    		std::cout << "Undefined argument.";
    }

    std::cout << "\n";
    return 0;
}
