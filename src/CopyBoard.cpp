/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstring>
#include <Parser.hpp>

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
           else
    		std::cout << "Undefined argument.";
    }

    std::cout << "\n";
    return 0;
}
