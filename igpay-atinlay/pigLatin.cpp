#include <iostream>
#include <vector>
#include <string>
using namespace std;

// made by fixedOtter

/*
  this program takes english input and gives you pig latin
  Copyright (C) 2023  fixedOtter

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

string PigProcessor(const string userWords) {
  // first creating the vowel database so i can pull the first one or multiple characters
  vector<char> englishVowels{'a', 'e', 'i', 'o', 'u'};
  // initializing to be an empty string so I can push to it
  string pigOut = "";
  // creating a userWords int so i don't get the unsigned int comparison annoyance
  int wordLength = userWords.size();

  // creating the for loop to go until there is a vowel found
  for (int i = 0; i < wordLength; i++) {

    // iterating through the vowel vector to check if it matches
    for (int j = 0; j < 5; j++) {
      
      // first if the word starts with a vowel
      if (userWords.at(0) == englishVowels.at(j)) {

        // setting output to just input word + yay
        pigOut = userWords + "yay";

        // breaking out of the loops & function so it doesn't keep running
        return pigOut;

      // otherwise going until the first vowel
      } else if (userWords.at(i) == englishVowels.at(j)) {

        // creating the length of the string without first consonant(s)
        int firstStrLength = wordLength - i; 

        // pushing back beginning characters to end
        pigOut = userWords.substr(i,firstStrLength) + userWords.substr(0,i) + "ay";

        // breaking out of the loops & function so it doesn't keep running
        return pigOut;
      }
    }
  }

  // ruh roh just incase
  return pigOut;
}

/*
  GGNORE:
  get input 
  pass input to PigP
  output PigP
  TODO:
  user input validation (main? or wordhandler?)
    make sure there's no illegal characters
  process user input (in PigP or wordhandler?)
    break down string into vector of words?
    find word enders? (space, comma, period)
*/
int main() {
  string userInput = "";
  // would be cool if this was a normal string that was first converted with the PigProcessor
  cout << "elcomeway otay ethay igpay atinlay anslatortray" << endl;
  cout << "gib to me ur word pls" << endl;
  getline(cin, userInput);


  cout << PigProcessor(userInput) << endl;
  return 0;
}