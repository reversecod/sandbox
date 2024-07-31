#include <iostream>

bool is_palindrome(const std::string& word){

std::string reversed_word = "";

for(int i = word.size() - 1; i >= 0; i--){
  reversed_word += word[i];
}
  if (reversed_word == word)
  {
    std::cout << "This word is a palindrome.\n";
    return true;
  }
    std::cout << "This word is not a palindrome.\n";
    return false;   
}

int main(){
  std::string word;
  std::cout << "Enter the word that you want to see if it is a palindrome or not: ";
  std::cin >> word;
  is_palindrome(word);

  return 0;
}