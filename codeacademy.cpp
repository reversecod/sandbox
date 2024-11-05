#include <iostream>
using namespace std;
bool is_palindrome(const string& word){
string reversed_word = "";
for(int i = word.size() - 1; i >= 0; i--){
  reversed_word += word[i];
}
  if (reversed_word == word)
  {
    cout << "This word is a palindrome.\n";
    return true;
  }
    cout << "This word is not a palindrome.\n";
    return false;   
}
int main(){
  string word;
  cout << "Enter the word that you want to see if it is a palindrome or not: ";
  cin >> word;
  is_palindrome(word);
  return 0;
}