#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


int hexCharToInt(char hexDigit){
  const int HEX_A = 10;
  const int HEX_B = 11;
  const int HEX_C = 12;
  const int HEX_D = 13;
  const int HEX_E = 14;
  const int HEX_F = 15;
  int retval = 0;

  if(hexDigit >= 0 && hexDigit <= 9){
    retval = static_cast<int> (hexDigit);
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
  vector<char> stringVector(strNumber.begin(), strNumber.end());
  const char HEX = 'H';
  const char DECIMAL = 'D';
  const char BINARY = 'B';
  char retval;

  if(stringVector[1] == 0 && stringVector[2] == 'x'){
    retval = HEX;
  }
  else if (stringVector[1] == 0 && stringVector[2] == 'b'){
    retval = BINARY;
  }

  else{
    retval = DECIMAL;
  }

  return retval;
}

string getNumber (const string& prompt){
  cout << "Enter your string to convert (q to quit): " << endl;
    return "a";
}

void printTitle (const string& myTitle){
  cout << "**************************************\n"
  << "*****HEX-DECIMAL-BINARY CONVERTER*****\n"
  << "**************************************\n\n" << endl;
}

string binaryToDecimal (const string& strNumber){
  vector<char> stringVector(strNumber.end(), strNumber.begin());
  int base = 2;
  int retval = 0;
  for (int i = 0; i < stringVector.size(); ++i){
    if (stringVector[i] == '1'){
      retval = pow(base, i);
    }
  }
  return to_string(retval);
}

string decimalToBinary(const string& strNumber){
  vector<int> binaryVector;
  vector<int> reversedVector;
  string retval;
  int decimal = stoi(strNumber);
  int remainder = 0;

  while (decimal != 0){
    remainder = decimal % 2;
    decimal /= 2;
    binaryVector.push_back(remainder);
  }
  
  for (int i = binaryVector.size(); i >= 0; ++i){
    reversedVector.push_back(binaryVector[i]);
    retval += to_string(reversedVector[i]);
  }

  return retval;
}

string decimalToHex (const string& strNumber){
  int decimal = stoi(strNumber);
  int remainder = 0;
  vector<int> binaryVector;
  vector<char> reversedVector;
  string retval;

  while (decimal != 0){
    remainder = decimal % 16;
    decimal /= 16;
    binaryVector.push_back(remainder);
  }

  for (int i = binaryVector.size(); i >= 0; ++i){
    reversedVector.push_back(binaryVector[i]);
    retval += to_string(hexCharToInt((reversedVector[i])));
  }

  return retval;
}

string hexToDecimal (const string& strNumber){
  vector<char> stringVector(strNumber.begin(), strNumber.end());
    int base = 16;
    int retval = 0;
    for (int i = 0; i < stringVector.size(); ++i){
      if (stringVector[i] == '1'){
        retval = pow(base, i);
      }
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