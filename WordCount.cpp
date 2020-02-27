// WordCount.cpp

#include "WordCount.h"
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <array>

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
  // If a vector in the table contains at least one word, it adds to the total
  int numUniqueWords = 0;
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
  // Makes the word all-lowercase and removes invalid symbols
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
  cout << validWord << endl;
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
    else {
      word[0] = tolower(word[0]);
      return word;
    }
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

  //cout << "Test: all words in dumpWordsSortedByWord" << endl;
 // Initializes a vector that stores every word pair in the table
  vector<std::pair<std::string, int>> temp;
  // Reads through every element in the hash table
  for (int i = 0; i < 100; i++) {
    for (size_t j = 0; j < table[i].size(); j++) {
      // Adds every word to the array
      temp.push_back(table[i][j]);
      //cout << table[i][j].first << endl;
    }
  }

  cout << "Descending ASCII Values:" << endl;
  // Outputs every word in descending ASCII order
  for (size_t x = 0; x < temp.size(); x++) {
    // Variable representing the index of the word with the highest value
    int max = 0;
    if (temp.size() == 1)
      max = 0;
    if (temp.size() == 0)
      return;
    // Find the word with the highest ASCII value
    for (size_t y = 0; y < temp.size(); y++) {
      // If a word has a higher ASCII value, it becomes highest
      if ((temp[y].first).compare(temp[max].first) > 0)
	max = y;
    }
    
    // Writes word and occurrences to ostream
    out << temp[max].first << "," << temp[max].second << "\n";
    // Deletes the word from array temp
    temp.erase(temp.begin()+max);
    x = 0;
  }
  //for (size_t j = 0; j < temp.size(); j++)
  //  if (temp[j].first == "-")
  //    out << temp[j].first << "," << temp[j].second << "\n";
   out << temp[0].first << "," << temp[0].second << "\n";
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {

  // Initializes a vector that stores every word pair in the table
  vector<std::pair<std::string, int>> temp;
  // Reads through every element in the hash table
  for (int i = 0; i < 100; i++) {
    for (size_t j = 0; j < table[i].size(); j++) {
      // Adds every word to the array
      temp.push_back(table[i][j]);
      //cout << table[i][j].first << endl;
    }
  }
  //cout << "Ascending Occurence Values:" << endl;
  // Outputs every word in ascending order of occurrences
  for (size_t x = 0; x < temp.size(); x++) {
    // Variable representing the index of the word of least occurrences
    int min = 0;
    if (temp.size() == 1)
      min = 0;
    if (temp.size() == 0)
      return;
    // Finds the word with least occurrences
    for (size_t y = 0; y < temp.size(); y++) {
      // If a word has a lower occurrence, it becomes the lowest
      if (temp[y].second < temp[min].second)
	min = y;
      // If a word has the same occurrences, their ASCII values compare
      else if (temp[y].second == temp[min].second) {
	// If a word has a lower ASCII value, it becomes lowest
	if ((temp[y].first).compare(temp[min].first) < 0)
	  min = y;
      }
    }
    // Writes word and occurrences to ostream
    out << temp[min].first << "," << temp[min].second << "\n";
    // Deletes the word from array temp
    temp.erase(temp.begin()+min);
    x = 0;
  }
  out << temp[0].first << "," << temp[0].second << "\n";
}

void WordCount::addAllWords(std::string text) {

  // Reads through entire text string letter by letter
  for (size_t i = 0; i < text.length(); i++) {
    std::string word;
    // If the first character or few characters are white space, delete them
    while((text[0] == ' ') || (text[0] == '\n') || (text[0] == '\t')){
      text.erase(text.begin());
    }
    // Finds the end of a word and makes a substring containing that word
    if ((text[i] == ' ') || (text[i] == '\n') || (text[i] == '\t')) { 
      if (i == 0)
	word = text[i];
      else
	word = text.substr(0,i);
      // Adds the word and deletes it from the string
      incrWordCount(makeValidWord(word));
      text.erase(0,i);
      // Resets to the new start of the string
      i = 0;
    }
    if (text[i] == text[text.length()-1]) {
      word = makeValidWord(text);
	incrWordCount(word);
      }
  }         
}


