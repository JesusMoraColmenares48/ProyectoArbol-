#ifndef READER_H
#define READER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
class Reader{

	public:
	vector<vector<string>> read(){
		std::ifstream inputFile("file.txt");
    
		vector<vector<string>> lines;
		if (!inputFile) {
			std::cerr << "Failed to open the file." << std::endl;
			return lines;
		}
		
		std::string line;
		
		// Read the file line by line
		while (std::getline(inputFile, line)) {
			// Create a stringstream to split the line into words
			std::stringstream ss(line);
			std::string word;
			std::vector<string> words;
			
			// Read and print each word in the line
			while (ss >> word) {
				words.push_back(word);
			}
			
			// Process the words in this line
			// std::cout << "Line: " << line << std::endl;
			// std::cout << "Words: ";
			// for (const std::string& w : words) {
			// 	std::cout << w << ", ";
			// }
			// std::cout << std::endl;
			lines.push_back(words);	
		}
		
		// Close the file
		inputFile.close();
		
		return lines;
	};

	bool isAlphabeticallySmaller(string str1, string str2){
		transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
		transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
		if (str1 < str2) {
			return true;
		}
		return false;
	}

};
#endif
