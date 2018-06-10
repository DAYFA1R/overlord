#include <iostream>

// g++ -o argloop spike/loopThruArgs.cpp

int main(int argc, char** argv) {
	// Loop through arguments
	for (int argument = 0; argument < argc; ++argument) {
		std::cout << argv[argument] << "\n";
	}

	return 0;
}