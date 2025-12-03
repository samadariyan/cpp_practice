module;

#include <filesystem>
#include <fstream>
#include <fmt/format.h>

export module text_files;

namespace text_files
{

    export void write_file(const std::filesystem::path& file_path, const std::string& content) {

        //Open the file for writing and in append mode
        //Creating the stream object attempts to open the file
        std::ofstream file(file_path, std::ios::out | std::ios::app);
        if (!file.is_open()) {
            fmt::println("Failed to open file for writing: {}", file_path.filename().string());
            return;
        }
        
        //Write to the file using one of the write functions
        //Se comment above for a few other ways we could write to the file
        file << content;

        //It's good practice to close the file when done
        //The file is closed when the file object goes out of scope
        //The destructor of the file object closes the file
        file.close();
    }


    export void read_file(const std::filesystem::path& file_path) {
        std::ifstream file(file_path, std::ios::in); // Open for reading
        if (!file.is_open()) {
            fmt::println("Failed to open file for reading: {}", file_path.filename().string());
            return;
        }
        
        /*
            . The std::getline function reads a line from the file and stores it in
                the string line. This proces is repeated until there are no more lines to read.
        */
        std::string line;
        while (std::getline(file, line)) {
            fmt::println("{}", line);
        }
    }
    
} // namespace text_files
