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

/*
  ~~ TaskList ~~

  GGNORE:
  get input 
  pass input to PigP
  output PigP
  process user input (in wordSeperator)
  TODO:
  user input validation (main? or wordhandler?)
    make sure there's no illegal characters
  update wordseperator to handle comma and period
  move functions to their own documents??
  FIXME:
  doesn't seem to work with just one word
  not processing last word in vector
  space between words as they are translated 
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

// eventually expand this function out to wordSep.cpp??
vector<string> wordSeperator(const string wordString) {
  // first defining our output vector
  vector<string> wordList;
  // defining the length so no comparison crap
  int stringLength = wordString.size();
  // setting last space location
  int lastSpace = 0;

  // iterating through string to pull out all spaces and seperate the word from the big spaghetti
  for (int i = 0; i < stringLength; i++) {
    // setting character to compare to space
    char spaceMaybe = wordString.at(i);
    // comparing each character to space and then doing work
    if (spaceMaybe == ' ') {
      // grab word from the string
      wordList.push_back(wordString.substr(lastSpace,i - lastSpace));
      // setting the last space position for the next word
      lastSpace = i + 1;
    // last word catch
    } else if (i == stringLength - 1) {
      //push last word to the vector
      wordList.push_back(wordString.substr(lastSpace,i + 1 - lastSpace));
      // lol
      lastSpace = 0;
    }
  }

  return wordList;
}

// func to take the vector from wordSeperator and run each word through the pigProcessor
string inputToPig(const string wordString) {
  // first defining our output string
  string finishedPiggy;
  // defining vector of the wordies 
  vector<string> wordList = wordSeperator(wordString);
  // define length so no comparison probs
  int vectorLength = wordList.size();

  // fixedOtter's first iterator loop (for iterating through the vector of words from wordSeperator, and running PigProcessor on each word)
  for (auto word : wordList) {
    finishedPiggy.append(PigProcessor(word) + " ");
  }
  // seems like this loop is acting the same way in that somehow the last word still isn't being output to the console. 

/*
  // loop to end all loops (going throu string and running pigProcessor and pushing to finishedPiggy)
  for(int i = 0; i < vectorLength; i++) {
    // adds each word to finished piggy after running it through the 'lator
    finishedPiggy.append(PigProcessor(wordList.at(i)) + " ");
    cout << PigProcessor(wordList.at(i)) << endl;
  }
*/
  
  return finishedPiggy;
}

int main() {
  string userInput = "";
  // would be cool if this was a normal string that was first converted with the PigProcessor
  cout << inputToPig("welcome to the pig latin translator") << endl;
  cout << "Please give me a phrase for me to translate to piglatin :)" << endl;
  getline(cin, userInput);


  cout << inputToPig(userInput) << endl;
  return 0;
}