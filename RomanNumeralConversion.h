//
// Created by travi on 4/2/2022.
//

#ifndef CODING_CHALLENGE_OIT_4_2_2022_ROMANNUMERALCONVERSION_H
#define CODING_CHALLENGE_OIT_4_2_2022_ROMANNUMERALCONVERSION_H

#include<iostream>
#include <string>
#include<cstring>
#include <vector>
#include<fstream>

using namespace std;


class RomanNumeralConversion {
private:
    string romanNumeralInput, integerInput, userInput;
    vector<char> romanNumeralSeperated;
    bool inputFileInUse;
public:
    /**
     *
     * @param romanInput
     * @param intInput
     */
    RomanNumeralConversion(string romanInput = "No input", string intInput = "No input") {
        romanNumeralInput = romanInput;
        integerInput = intInput;
    }

    bool checkToEndProgram(){
        cout << "Would you like to convert a value or roman numeral? Enter 'Y' to continue or any other value to quit" << endl;
        cin >> userInput;
        if(userInput == "Y" || userInput == "y" || userInput == "YES" || userInput == "yes"){
            return true;
        }
        else{
            return false;
        }

    }
    bool setInput(){
        cout << "Are you converting Roman Numerals to Decimal Numbers? Enter Y or N" << endl;
        cin>>  userInput;
        if(userInput == "Y" || userInput == "y" || userInput == "YES" || userInput == "yes"){
            cout << "Please enter the roman numeral you wish to convert now: " << endl;
            cin >> userInput;
            if(checkRomanNumeralInput()){
                return true;
            }
            else{
                return false;
            }
        }
        else if(userInput == "N" || userInput == "n" || userInput == "NO" || userInput == "no" ){
            cout << "Please enter the integer you wish to convert now: " << endl;
            cin >> userInput;
            if(checkIntegerInputFunction()){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }

    string convertDecimalToRomanNumerals() {
        integerInput;
    };

    string convertRomanNumeralsToDecimal() {
        romanNumeralSeperated;
    }

    bool checkRomanNumeralInput(){
        vector<char> userInputSeperated(userInput.begin(), userInput.end());
        for(int i = 0; i < userInputSeperated.size(); i++){
            if(userInputSeperated.at(i) == 'I' || userInputSeperated.at(i) == 'V' || userInputSeperated.at(i) == 'X' || userInputSeperated.at(i) == 'L' ||
               userInputSeperated.at(i) == 'C' || userInputSeperated.at(i) == 'D' || userInputSeperated.at(i) == 'M'){
                continue;
            }
            else{
                cout << "invalid input" << endl;
                return false;
            }
        }
        return true;
    }

    bool checkIntegerInputFunction() {
        vector<char> userInputSeperated(userInput.begin(), userInput.end());
        for(int i = 0; i < userInputSeperated.size(); i++){
            if(isdigit(userInputSeperated.at(i))){
                continue;
            }
            else{
                cout << "invalid input" << endl;
                return false;
            }
        }
        return true;
    }

    int openInputandOutputFiles(int argc, char *argv[]) {
        char userInput;
        cout<< "Do you have an input file to convert Roman Numerals to Decimal Numbers or Vice Versa? Enter 'Y' or 'N' now "<< endl;
        cin >> userInput;
        userInput = toupper(userInput);
        if (userInput == 'Y') {
            if (argc < 3) {
                cerr << "Please provide name of input and output files";
                return 1;
            }
            cout << "Input file: " << argv[1] << endl;
            ifstream input(argv[1]);
            if (!input) {
                cerr << "Unable to open " << argv[1] << " for input";
                return 2;
            }
            cout << "Output file: " << argv[2] << endl;
            ofstream output(argv[2]);
            if (!output) {
                input.close();
                cerr << "Unable to open " << argv[2] << " for output";
                return 3;
            }
            inputFileInUse = true;
        } else {
            inputFileInUse = false;
            return 0;
        }
    }

};


#endif //CODING_CHALLENGE_OIT_4_2_2022_ROMANNUMERALCONVERSION_H
