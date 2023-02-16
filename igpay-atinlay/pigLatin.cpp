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

string PigProcessor(string userWords) {
  // first creating the vowel database so i can pull the first one or multiple characters
  vector<char> englishVowels{'a', 'e', 'i', 'o', 'u'};
  // initializing to be an empty string so I can push to it
  string pigOut = "";

  // creating the for loop to go until there is a vowel found
  for (int i = 0; i < userWords.length(); i++) {

    // iterating through the vowel vector to check if it matches
    for (int j = 0; j < 5; j++) {
      
      // if it matches then
      if (userWords.at(i) == englishVowels.at(j)) {
        pigOut = userWords.substr(i,1) + userWords.substr(0,i) + "ay";
      }

    }

  }

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
  cout << "elcomeway otay ethay igpay atinlay anslatortray" << endl;
  cout << "gib to me ur word pls" << endl;
  getline(cin, userInput);


  cout << PigProcessor(userInput) << endl;
  return 0;
}