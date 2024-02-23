#include <iostream>
#include "./include/complex.h"
using namespace std;
bool isValidFloat(const std::string& str) {
    std::istringstream iss(str);
    float val;
    return (iss >> val) && (iss.eof()); // Check if the conversion was successful and there's no leftover data
}

bool isValidComplexFormat(const std::string& input) {
    // Validate the format of the complex number input
    // Assuming the format: (real imaginary)
    std::istringstream iss(input);
    char openBracket, closeBracket;
    std::string real, imaginary;

    // Check if the input starts with an opening bracket '('
    if (!(iss >> openBracket) || openBracket != '(') {
        return false;
    }

    // Read the real and imaginary parts as strings
    if (!(iss >> real >> imaginary)) {
        return false; // Real and imaginary parts are missing
    }

    // Check if the input contains a space between the real and imaginary parts
    char space;
    if (!(iss >> space) || space != ' ') {
        return false; // Space character is missing between the real and imaginary parts
    }

    // Check if real and imaginary parts are valid numbers (integers or floats)
    if (!isValidFloat(real) || !isValidFloat(imaginary)) {
        return false;
    }

    // Check if the input ends with a closing bracket ')'
    if (!(iss >> closeBracket) || closeBracket != ')') {
        return false;
    }

    // The input is valid
    return true;
}

int 
main(int argc, char* argv[]) {
    Complex obj1;
    /*taking the input file through command line argument*/
    if(argc<2){
        cout<<"Usage:<./program_name> <file_name.txt>"<<endl;
        return 1;
    }
    string fileName(argv[1]); 
    char openBracket, closeBracket;
    float real, imaginary;
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        exit(0);
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') {
            // Skip empty lines and lines starting with '#'
            continue;
        }
            std::istringstream iss(line);
             iss >> openBracket >> real >> imaginary >> closeBracket;
            // if((!(openBracket == '(') && !(closeBracket == ')') && !(isdigit(real)) && !(isdigit(imaginary)))){
            //     continue;
            // }
             if (isValidComplexFormat(line)) {
                continue;
             }
            // if((!(openBracket == '(') && !(closeBracket == ')') && !(floor(real)) && !(floor(imaginary)))){
            //     continue;
            // }
            // if((!(openBracket == '(') && !(closeBracket == ')') && !(static_cast<float>(real))) && !(static_cast<float>(imaginary))){
            //     continue;
            // }
            Complex num1(real,imaginary);
            std::string secondLine;
            std::getline(inputFile, secondLine);
            if (secondLine.empty() || secondLine[0] == '#') {
                // Skip empty lines and lines starting with '#'
                continue;
            }
                std::istringstream iss(secondLine);
                 iss >> openBracket >> real >> imaginary >> closeBracket;
                // // if(!((openBracket == '(') && (closeBracket == ')'))){
                // // continue;
                // // }
                // if((!(openBracket == '(') && !(closeBracket == ')') && !(floor(real)) && !(floor(imaginary)))){
                // continue;
                // }
                if(isValidComplexFormat(secondLine)){
                    continue;
                }
                Complex num2(real,imaginary);
                cout<<openBracket<<num1.real<<" "<<num1.imginary<<closeBracket<<" "<<openBracket<<num2.real<<" "<<num2.imginary<<closeBracket<<" = ";
                Complex result=multiply_complex(num1, num2);
                result.display_result();
    }
        //(3+i*2)(4+i*3) =  6 + i*17
    inputFile.close();
    return 0;
}