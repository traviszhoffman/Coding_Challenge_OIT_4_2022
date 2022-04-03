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
        while (inital.checkToEndProgram()) {
            inital.setInput();
        }
    }
    return 0;
}
