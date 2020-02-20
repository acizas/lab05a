// WordCount.cpp

#include "WordCount.h"
#include <vector>
#include <utility>
#include <iostream>
#include <string>

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {

  int totalWords = 0;
  // Reads through every vector in the hash table
  for (int i = 0; i < 100; i++) {
    // Checks to see if the spot in the table is occupied
    if (!(table[i].empty())){
      for (size_t j = 0; j < table[i].size(); j++) {
	if ((table[i][j]).second != 0)
	totalWords += table[i][j].second;
      }
    }
  }
  return totalWords;
}

int WordCount::getNumUniqueWords() const {
  
  int numUniqueWords = 0;
  // If a vector in the table contains at least one word, it adds to the total
  for (int i = 0; i < 100; i++) {
    if (!(table[i].empty())){
      for (size_t j = 0; j < table[i].size(); j++) {
	numUniqueWords += 1;
      }
    }
  }
  return numUniqueWords;
    
}

int WordCount::getWordCount(std::string word) const {

  int wordCount = 0;
  // Makes the word valid
  std::string validWord = makeValidWord(word);
  int hashKey = hash(validWord);
  // If the word is not present, returns 0 
  if (table[hashKey].empty()) {
    return 0;
  }
  else {
    // Counts through the elements in the vector at the word's hash table index
    for (size_t i = 0; i < table[hashKey].size(); i++) {
      if (table[hashKey][i].first == validWord)
	  wordCount = table[hashKey][i].second;
    }
  }
  return wordCount;
}	
int WordCount::incrWordCount(std::string word) {

  int wordCount = 0;
  // Makes the word valid
  std::string validWord = makeValidWord(word);
  // Returns 0 if inputting empty string
  if (validWord == "")
    return 0;
  //if (!(validWord.empty())){
  else {
    int hashKey = hash(validWord);
    // Checks to see if the word is in the table
    for (size_t i = 0; i < table[hashKey].size(); i++){
      if (table[hashKey][i].first == validWord) {
	// Increments and returns word count
	wordCount = table[hashKey][i].second + 1;
	table[hashKey][i].second += 1;
	return wordCount;
      }
    }  
    // If no word is found, creates an entry in the table for the word
    std::pair <std::string, int> newWord;
    newWord.first = validWord;
    newWord.second = 1;
    table[hashKey].push_back(newWord);
    wordCount = 1;  
    return wordCount;
  }
}

int WordCount::decrWordCount(std::string word) {

  int wordCount = 0;
  // Makes the word valid
  std::string validWord = makeValidWord(word);
  if (validWord == "")
    return 0;
  else {
  //if (!(validWord.empty())){
    int hashKey = hash(validWord);
    // Checks to see if the word is already in the table
    for (size_t i = 0; i < table[hashKey].size(); i++) {
      if (table[hashKey][i].first == validWord) {
	int number = table[hashKey][i].second;
	// If there is more than one word occurrence, decrements and returns
	// word count
	if (number > 1) {
	  table[hashKey][i].second -= 1;
	  wordCount = table[hashKey][i].second;
	  return wordCount;
	}
	// If there is only one occurrence, deletes from table and returns 0
	else {
	  table[hashKey][i].second = 0;
	  wordCount = 0;
	  table[hashKey].erase(table[hashKey].begin()+i);
	  return wordCount;
	}
      }
    }
  // If the word is not found, returns -1
  wordCount = -1;
  return wordCount;
  }
}

bool WordCount::isWordChar(char c) {

  int x = 0;
  // All usable chars (excluding "" (blank string)  and ' or - in the middle
  // of the word) 
  char a[] = {'a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K','l','L','m','M','n','N','o','O','p','P','q','Q','r','R','s','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z'};
  // Returns true if c is a lowercase or uppercase letter only
  for (int i = 0; i < 52; i++){
    if (c == a[i])
      x = 1;
  }
  return x;
}

std::string WordCount::makeValidWord(std::string word) {

  // Checks if the string is empty
  if (word == "")
    return std::string();
  // Checks if the string is -
  if (word == "-")
    return "-";
  // Checks if the string is a one-character invalid string
  if (word.length() == 1) {
    if (!(isWordChar(word[0])))
      return std::string();
    else
      return word;
  }
  
  // Checks if the first character in the string is a letter
  while(!(isWordChar(word[0]))){
    if (!(word == ""))
      word.erase(word.begin());
    else
      return "";
  }
  // Checks if the last letter of the string is a a letter
  while(!(isWordChar(word[word.length()-1]))){
    if (!(word == ""))
	word.pop_back();
    else
      return "";
  }
  // Checks every other character in the string
  for (size_t i = 0; i < word.length(); i++) {
    char x = word[i];
    // If a character is not a letter, "-", or "'", it is removed
    if ((!(isWordChar(x)))&&(x != '-') && (x != '\'')){
      word.erase(word.begin()+i);
      i--;
    }
  }
  for (size_t i = 0; i < word.length(); i++){
    if (isWordChar(word[i]))
      word[i] = tolower(word[i]);
  }
  if (word == "")
    return std::string();
  if (word == "-")
    return "-";
  return word;

}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {

  // Reads through every line in the hash table
  for (int i = 0; i < 100; i++) {
    for (size_t j = 0; j < table[i].size(); j++) {
      
      
  
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {

   // Reads through every line in the hash table
  for (int i = 0; i < 100; i++) {
    for (size_t j = 0; j < table[i].size(); j++) {
  
}

void WordCount::addAllWords(std::string text) {

  // Reads through entire text string letter by letter
  for (int i = 0; i < text.length(); i++) {
    std::string word;
    // If the first character or few characters are white space, delete them
    while((text[0] == ' ') || (text[0] == '\n') || (text[0] == '\t')){
      text.erase(text.begin());
    }
    // Finds the end of a word and makes a substring containing that word
    if ((text[i+1] == ' ') || (text[i+1] == '\n') || (text[i+1] == '\t')) {
      if (i == 0)
	word = text[i];
      else
	word = text.substr(0,i);
      // Adds the word and deletes it from the string
      incrWordCount(word);
      text.erase(0,i);
      // Resets to the new start of the string
      i = 0;
    }
  }         
}

