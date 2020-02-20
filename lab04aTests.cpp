#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>

using namespace std;

int main() {

  WordCount testTable;

    // Testing makeValidWord and isWordChar
  std::string test1 = "Apple3!";
  std::string test2 = "3456A";
  std::string test3 = "O'Brien";
  std::string test4 = "-A-A-";
  std::string test5 = "Rus'";
  std::string test6 = "-";
  std::string test7 = "$-s'-#";
  std::string x = WordCount::makeValidWord(test1);
  std::string y = WordCount::makeValidWord(test2);
  std::string z = WordCount::makeValidWord(test3);
  std::string a = WordCount::makeValidWord(test4);
  std::string b = WordCount::makeValidWord(test5);
  std::string c = WordCount::makeValidWord(test6);
  std::string d = WordCount::makeValidWord(test7);
  assertEquals('l', x[3], "Testing Apple3![3] = l", -1);
  assertEquals('a', y[0], "Testing 3456A[0] = a", -1);
  assertTrue((x == "apple"), "Testing Apple3! == apple", -1);
  assertTrue((y == "a"), "Testing 3456A == A", -1);
  assertTrue((y.length() == 1), "Length of 3456A is 1", -1);
  assertTrue((z == "o'brien"), "O'Brien is correct", -1);
  assertTrue((a == "a-a"), "-A-A- == a-a", -1);
  assertTrue((b == "rus"), "Rus' == rus", -1);
  assertTrue(WordCount::isWordChar('z'), "z is a char", -1);
  assertTrue(WordCount::isWordChar('C'), "C is a char", -1);
  assertTrue(!(WordCount::isWordChar('-')), "- is not a char", -1);
  assertTrue(!(WordCount::isWordChar('1')), "1 is not a char", -1);
  assertTrue(!(WordCount::isWordChar('@')), "@ is not a char", -1);
  assertTrue((c == "-"), "- is valid", -1);
  assertTrue((d == "s"), " $-s'-# == s", -1);

  // Testing testTable
  assertTrue((testTable.getTotalWords() == 0), "getTotalWords = 0 when empty", -1);
  assertTrue((testTable.getNumUniqueWords() == 0), "getNumUniqueWords = 0 when empty", -1);

  // Tests incrWordCount, decrWordCount, getWordCount, getNumUniqueWords,
  // getTotalWords
  testTable.incrWordCount("Hello");
  testTable.incrWordCount("Google");
  testTable.incrWordCount("Google");
  assertTrue((testTable.getNumUniqueWords() == 2), "2 unique words: Hello and Google", -1);
  assertTrue((testTable.getTotalWords() == 3), "3 total words: Hello, Google, and Google", -1);
  testTable.incrWordCount(x);
  testTable.incrWordCount(y);
  testTable.incrWordCount(z);
  testTable.incrWordCount(a);
  testTable.incrWordCount(b);
  assertTrue((testTable.getNumUniqueWords() == 7), "7 unique words, one with 2 instances", -1);
  assertTrue((testTable.getTotalWords() == 8), "8 total words, one with 2 instances", -1);
  testTable.decrWordCount(x);
  testTable.decrWordCount(y);
  testTable.decrWordCount(z);
  assertTrue((testTable.getNumUniqueWords() == 4), "Removed 3 words, now 4 unique words", -1);
  assertTrue((testTable.getTotalWords() == 5), "5 words in total after removing 3 words, 2 instances of one word", -1);
  assertTrue((testTable.getWordCount("Google") == 2), "Word Count of Google is 2", -1);
  assertTrue((testTable.getWordCount("Apple") == 0), "Word Count of Apple is 0", -1);
  assertTrue((testTable.getWordCount("Google") == 2), "Google appears twice", -1);
  testTable.decrWordCount("Google");
  assertTrue((testTable.getWordCount("Google") == 1), "Google appears once, 1 removed", -1);
  assertTrue((testTable.getTotalWords() == 4), "4 words in total", -1);
  assertTrue((testTable.getWordCount("A") == 0), "A does not appear (stripped version of 3456A", -1);
  assertTrue((testTable.getWordCount("UCSB") == 0), "UCSB does not appear", -1);
  assertTrue((testTable.getWordCount("-") == 0), "- does not appear in the list", -1);

  // Official Test Cases
  cout << "#########################################################################" << endl;
  cout << "Tests Part 2" << endl;

  WordCount table;

  std::string word1 = ".foo";
  std::string word2 = "bar?";
  std::string word3 = "...fum***";
  std::string word4 = "\"quote\"";
  std::string word5 = "isn't";
  std::string word6 = "mother-in-law";
  std::string word7 = "'aRT-*";
  std::string word8 = "$-s'-#";
  std::string word9 = "$$*-'-!";
  std::string word10 = "";
  std::string word11 = "-";

  std::string vw1 = WordCount::makeValidWord(word1);
  std::string vw2 = WordCount::makeValidWord(word2);
  std::string vw3 = WordCount::makeValidWord(word3);
  std::string vw4 = WordCount::makeValidWord(word4);
  std::string vw5 = WordCount::makeValidWord(word5);
  std::string vw6 = WordCount::makeValidWord(word6);
  std::string vw7 = WordCount::makeValidWord(word7);
  std::string vw8 = WordCount::makeValidWord(word8);
  std::string vw9 = WordCount::makeValidWord(word9);
  std::string vw10 = WordCount::makeValidWord(word10);
  std::string vw11 = WordCount::makeValidWord(word11);

  assertTrue( (table.incrWordCount("--$$--") == 0), "--$$-- appears 0 times", -1);
 
  
  
}
