//******************************************************************************
// File name:   main.cpp
// Author:      Jake Gallagher
// Date:        09/18/2024 
// Class:       CS200-01 
// Assignment:  BaseConverter
// Purpose:     
// Hours:       
//******************************************************************************

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int hexCharToInt (char hexDigit);
char getBase(const string& strNumber);
string getNumber (const string& prompt);
void printTitle (const string& myTitle);
string binaryToDecimal (const string& strNumber);
string decimalToBinary (const string& strNumber);
string decimalToHex (const string& strNumber);
string hexToDecimal (const string& strNumber);
string hexToBinary (const string& strNumber);
string binaryToHex (const string& strNumber);

int main () {
  const string TITLE_STARS = "**************************************";
  const string TITLE = "*****HEX-DECIMAL-BINARY CONVERTER*****";
  const string PROMPT = "Enter your string to convert(q to quit): ";
  const string DECIMAL_OUTPUT = "The decimal conversion is: ";
  const string BINARY_OUTPUT = "The binary conversion is: ";
  const string HEX_OUTPUT = "The hexadecimal conversion is: ";
  char base;
  string inputString;
  string retval;
  const string QUIT = "q";

  printTitle(TITLE_STARS);
  printTitle(TITLE);
  printTitle(TITLE_STARS);

  inputString = getNumber(PROMPT);

  while(inputString != QUIT){
     base = getBase(inputString);

     switch(base){
      case 'D':
          retval = decimalToBinary(inputString);
          cout << BINARY_OUTPUT << retval << endl;
          retval = decimalToHex (inputString);
          cout << HEX_OUTPUT << retval << endl;
        break;

      case 'H':
          retval = hexToDecimal(inputString);
          cout << DECIMAL_OUTPUT << retval << endl;
          retval = hexToBinary(inputString);
          cout << BINARY_OUTPUT << retval << endl;
        break;

      case 'B':
          retval = binaryToDecimal(inputString);
          cout << DECIMAL_OUTPUT << retval << endl;
          retval = binaryToHex (inputString);
          cout << HEX_OUTPUT << retval << endl;
        break;
      
      default:
        break;
     }
     inputString = getNumber(PROMPT);
  }
  
  return EXIT_SUCCESS;
}

int hexCharToInt(char hexDigit){
  const int HEX_A = 10;
  const int HEX_B = 11;
  const int HEX_C = 12;
  const int HEX_D = 13;
  const int HEX_E = 14;
  const int HEX_F = 15;
  int retval = 0;

  if(hexDigit >= '0' && hexDigit <= '9'){
    retval = static_cast<int> (hexDigit - '0');
  }
  else{
    if (hexDigit == 'A'){
      retval = HEX_A;
    }
    else if (hexDigit == 'B'){
      retval = HEX_B;
    }
    else if (hexDigit == 'C'){
      retval = HEX_C;
    }
    else if (hexDigit == 'D'){
      retval = HEX_D;
    }
    else if (hexDigit == 'E'){
      retval = HEX_E;
    }
    else if (hexDigit == 'F'){
      retval = HEX_F;
    }
  }

  return retval;

}

char getBase(const string& strNumber){
  const char HEX = 'H';
  const char DECIMAL = 'D';
  const char BINARY = 'B';
  char retval;

  if(strNumber[0] == '0' && strNumber[1] == 'x'){
    retval = HEX;
  }
  else if (strNumber[0] == '0' && strNumber[1] == 'b'){
    retval = BINARY;
  }

  else{
    retval = DECIMAL;
  }

  return retval;
}

string getNumber (const string& prompt){
  string retval;
  cout << prompt;
  cin >> retval;

  return retval;
}

void printTitle (const string& myTitle){
  cout << myTitle<< endl;
}

string binaryToDecimal (const string& strNumber){
  const int length = strNumber.length();
  int counter = 0;
  int base = 2;
  int retval = 0;

  for (int i = length - 1; i >= 2; --i){
    if (strNumber[i] == '1'){
      retval += pow(base, counter);
    }
    counter++;
  }

  return to_string(retval);
}

string decimalToBinary(const string& strNumber){
  int length = 0;
  char* charArrayInital = new char[100];
  string retval = "0b";
  int decimal = stoi(strNumber);
  int initialVal = decimal;
  int remainder = 0;


  while (decimal != 0){
    remainder = decimal % 2;
    decimal /= 2;
    charArrayInital[length] = remainder + '0';
    ++length;
  }
  if (initialVal == 0){
    retval += to_string(0);
  }
  else{
    for (int i = length; i >= 0; --i){ 
      retval += charArrayInital[i];
    }
  }
  delete[] charArrayInital;
  return retval;
}

string decimalToHex (const string& strNumber){
  const int ASCII_TO_ZERO = 48;
  const int ASCII_TO_A = 55;
  int decimal = stoi(strNumber);
  int initialVal = decimal;
  int remainder = 0;
  char* charArrayInitial = new char[100];
  int arrayLength = 0;
  string retval = "0x";

  while (decimal != 0){
    remainder = decimal % 16;
    decimal /= 16;
    if (remainder < 10){
      charArrayInitial[arrayLength] = remainder + ASCII_TO_ZERO;
      ++arrayLength;
    }
    else{
      charArrayInitial[arrayLength] = remainder + ASCII_TO_A;
      ++arrayLength;
    }
  }

  if (initialVal == 0){
    retval += to_string(0);
  }
  else{
    for (int i = arrayLength - 1; i >= 0; --i){ 
      retval += charArrayInitial[i];
    }
  }
  return retval;
}

string hexToDecimal (const string& strNumber){
  const int length = strNumber.length();
  int counter = 0;
  int base = 16;
  int retval = 0;
  int hexToInt = 0;

  for (int i = length - 1; i >= 2; --i){
    hexToInt = hexCharToInt(strNumber[i]);
    retval += hexToInt * pow(base, counter);
    counter++;
  }

  return to_string(retval);
}

string hexToBinary (const string& strNumber){
  string retval;
  retval = hexToDecimal(strNumber);
  retval = decimalToBinary(retval);

  return retval;
}

string binaryToHex (const string& strNumber){
  string retval;
  retval = binaryToDecimal(strNumber);
  retval = decimalToHex(retval);

  return retval;
}