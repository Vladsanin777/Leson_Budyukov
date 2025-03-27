#include <iostream>
#include <fstream>
#include <string>

std::string printfile(const char* file) {
	std::cout << file << std::endl;
	std::ifstream f(file);
	std::string temp, out;
	do {
		getline(f, temp);
		out += temp + '\n';
	} while (!f.eof());
	std::cout << out << std::endl;
	f.close();
	return out;
}

int main() {
	std::ofstream output("output.txt");
	std::string text1 = printfile("f.txt"), \
		text2 = printfile("g.txt");
	for (size_t i = 0; text1[i] == text2[i]; i++)
		output << text1[i];
	output.close();
	printfile("output.txt");
	return 0;

}