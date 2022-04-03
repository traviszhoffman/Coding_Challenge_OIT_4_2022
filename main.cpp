#include <iostream>
#include"RomanNumeralConversion.h"

int main(int argc, char *argv[]) {
RomanNumeralConversion inital;
if(inital.openInputandOutputFiles(argc, argv)){
    //call functions to do operations and parse text else
    //have if else to make sure file was parsed and functioned correct
    cout << "All conversions have been executed if possible. Thank you for using this program." << endl;
}
else{
    //runs until user decides to end program;
        while (inital.checkToEndProgram()) {
            if(inital.setInput()){
                inital.checkForRomanOrIntConversion();
            }
        }
    }
    return 0;
}
