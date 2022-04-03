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
    int sum =0;
    bool inputFileInUse, romanConversion;
public:

    /**
     * roman numeral conversion object that holds input parameters
     * @param romanInput
     * @param intInput
     */
    RomanNumeralConversion(string romanInput = "No input", string intInput = "No input") {
        romanNumeralInput = romanInput;
        integerInput = intInput;
    }

    /**
     * no return value but will print to console the values of the conversion performed
     */
    void checkForRomanOrIntConversion(){
        if(romanConversion){
            cout << "your roman numeral " << romanNumeralInput << " is " << convertRomanNumeralsToDecimal()
            << " in decimal form." << endl;
        }
        else{
            convertDecimalToRomanNumerals();
        }
    }
    /**
     * checks whether or not user wishes to end program
     * @return a bool to indicate whether or not program should end
     */

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

    /**
     * checks what operation needs to be done and takes input for either roman numeral or integer depending on user desire
     * @return a true or false depending on whether or not input is valid based on nested function checkRomanNumeralInput() or
     * checkIntegerInput()
     */
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
/**
 * this function will convert Decimal numbers to roman numerals
 * still need to implement
 * @return Roman Numeral representation of number in string form
 */
    string convertDecimalToRomanNumerals() {
        integerInput;
    };
    /**
     * function to convert romman numerals to decimal form
     * still needs to finish implementing correctly rules in order to find values
     * @return roman numeral sum in integer form
     */

    int convertRomanNumeralsToDecimal() {
        vector<char> romanNumeralSeperated(romanNumeralInput.begin(), romanNumeralInput.end());
        vector<int> romanNumeralValues =returnRomanNumsAsValues(romanNumeralSeperated);
        for(int i = 0; i < romanNumeralValues.size(); i++){
            if(romanNumeralValues.at(i) < romanNumeralValues.at(i+1)){
                sum += romanNumeralValues.at(i+1) - romanNumeralValues.at(i);
                i++;
            }
            else if(romanNumeralValues.at(i) > romanNumeralValues.at(i+1)){
                sum += romanNumeralValues.at(i) + romanNumeralValues.at(i+1);
            }
        }
        return sum;
    }
    /**
     * converts roman numerals to their numeric value each symbol
     * @param romanNums
     * @return a vector of ints with each rom numeral in order
     */

    vector<int> returnRomanNumsAsValues(vector<char> romanNums){
        vector<int> romNumValues(romanNums.size());
        for(int i = 0; i < romanNums.size(); i++){
            if(romanNums.at(i) == 'I') romNumValues.at(i) = 1;
            if(romanNums.at(i) == 'V') romNumValues.at(i) = 5;
            if(romanNums.at(i) == 'X') romNumValues.at(i) = 10;
            if(romanNums.at(i) == 'L') romNumValues.at(i) = 50;
            if(romanNums.at(i) == 'C') romNumValues.at(i) = 100;
            if(romanNums.at(i) == 'D') romNumValues.at(i) = 500;
            if(romanNums.at(i) == 'M') romNumValues.at(i) = 1000;
        }
        return romNumValues;
    }
/**
 * checks if roman numeral input from user is correct and converts input to capital letters
 * I still need to implement rule #4 from doc
 * @return bool if input is formated correctly
 */

    bool checkRomanNumeralInput(){
        vector<char> userInputSeperated(userInput.begin(), userInput.end());
        for(int i = 0; i < userInputSeperated.size(); i++){
            //if checks if value is a letter before using toUpper
            if(isalpha(userInputSeperated.at(i))) {
                userInputSeperated.at(i) = toupper(userInputSeperated.at(i));
            }
        }
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
        romanNumeralInput = userInput;
        romanConversion = true;
        return true;
    }
/**
 * check if integer input from user is an integer or not
 * @return bool value if true or false
 */
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
        integerInput = userInput;
        romanConversion = false;
        return true;
    }
/**
 * check if user has an input file that they would like to use to use for conversion
 * and then checks if input and output files are able to be opened.
 * @param argc
 * @param argv
 * @return
 */
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
