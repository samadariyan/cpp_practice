/*
    . Reading and writing text files in modern C++.
        . Topics : 
            . Fundamental types: 
                . Reading and writing text files in modern C++
                . Reading and writing binary files in modern C++    
*/

#include <filesystem>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <iterator>

import utilities;

int main(){

    //Way #1
    /*
    std::filesystem::path file_path = R"(D:\sample_file.txt)"; // Windows
    //std::filesystem::path file_path = R"(/path/to/your/input_file.txt)"; // Linux

    std::string content = "\nHello, world! \nThis is a test.";

    std::ofstream file(R"(D:\sample_file.txt)", std::ios::out);

    file << content;

    file.close(); // Redundant
    */


    // Way #2
    /*
   	FILE* file = fopen(R"(D:\sample_file.txt)", "w");
	if (file) {
        std::string content = "Hello, world!";
        fprintf(file, "%s", content.c_str());
        fclose(file);
    } else {
        std::cerr << "Unable to open file";
    }
    */


    // Way #3
    /*
    std::ofstream file(R"(D:\sample_file.txt)");
    std::string content = "Hello, world!";
    std::copy(content.begin(), content.end(), std::ostream_iterator<char>(file));
    file.close();
    */

    //Going through proper functions
    //read_write_text_files();

    read_write_binary_files();


    
}