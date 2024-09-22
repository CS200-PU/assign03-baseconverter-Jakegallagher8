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
#include "functions.cpp"

using namespace std;

int main () {
  char base;
  string inputString;
  const string QUIT = "q";

  printTitle("a");
  inputString = getNumber("a");

  while(inputString != QUIT){
     base = getBase(inputString);

     switch(base){
      case 'D':

        break;

      case 'H':

        break;

      case 'B':

        break;
     }
  }
  
  return EXIT_SUCCESS;
}