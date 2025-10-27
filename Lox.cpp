#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cstdlib> 

class IOException : public std::runtime_error {
        public:
            explicit IOException(const std::string& message)
                : std::runtime_error(message) {}
};

class Lox{
    public:
        bool hadError;
        Lox(){
            hadError = false;
        }


        void run(const std::string& source) {
            //Scanner scanner = new Scanner(source);
            //std::vector<Token> tokens = scanner.scanTokens();

            //for(Token token: tokens){
            //    std::cout << token << std::endl;
            //}
        }

        void report(int line, std::string where, std::string message){
            std::cout << "[line " << line << "] Error" << where << ": " << message << std::endl;
        }

        void error(int line, std::string message){
            report(line, "", message);
        }


        void runFile(const std::string& path) {
            std::ifstream file(path);
            if (!file.is_open()) {
                throw IOException("Could not open file: " + path);
            }

            std::string content((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());

            if (hadError) exit(65);
            run(content);
        }

        void runPrompt() {
            std::string line;
            std::cout << "> ";
            while (std::getline(std::cin, line)) {
                run(line);
                hadError = false;
                std::cout << "> ";
            }
        }

        int loxmain(int argc, char* argv[]) {    
            try {
                if (argc > 2) {
                    std::cout << "Usage: clox [script]" << std::endl;
                    //UNIX Commandline Error
                    return 64;  
                } else if (argc == 2) {
                    runFile(argv[1]);
                } else {
                    runPrompt();
                }
            } catch (const IOException& e) {
                std::cerr << "IOException: " << e.what() << std::endl;
                //UNIX IO Error
                return 74; 
            }
        }

};

