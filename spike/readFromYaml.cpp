#include <iostream>
#include "yaml-cpp/yaml.h"

// g++ -o read spike/readFromYaml.cpp -I./include -L./lib -lyaml-cpp

int main(int argc, char** argv) {
	// Load config file
	YAML::Node config = YAML::LoadFile("spike/.overlord.yaml");

	// Convert keys to native data types (from YAML::Node type)
	const std::string localRunCmd = config["run"].as<std::string>();

	// Testing sending string to output 
	std::cout << localRunCmd << "\n";

	// Testing running command as a system call
	system(localRunCmd.c_str());

	return 0;
}