#include <iostream>
#include <string>
using namespace std;

const string vowel = "aeiou";
bool is_vowel(char letter) {
   for(char c : vowel){
      if (letter == c){
         return true;
      }
   }
   return false;
} 
string consonants(string text) {
  string empty;
  for (int i = 0; i < text.length(); ++i) {
    if (!is_vowel(text[i])) {
      empty += text[i];
    } else {
    	break; }
  }
  return empty;
}
string translate(string word) { 
  string temp;
  string text = consonants(word);
  for (int i = text.length(); i < word.length(); ++i) {
    temp += word[i];
  } temp = temp + text + "ay";
  return temp;
}
int main(){
	int test_cases;
	cin >> test_cases;
	for(int i  = 0; i < test_cases; ++i){
		string words;
		cin >> words;
		cout << translate(words) << " " << endl;
	}
	return 0;
}
