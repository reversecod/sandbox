#include <iostream>

// Define is_palindrome() here:
bool is_palindrome(const std::string &text)
{

  std::string reversed_text = "";

  for (int i = text.size() - 1; i >= 0; i--)
  {
    reversed_text += text[i];
  }

  if (reversed_text == text)
  {
    std::cout << "This word is a palindrome.\n";
    return 0;
  }

  std::cout << "This word is not a palindrome.\n";
  return 0;
}

int main()
{
  std::string word;

  std::cout << "Enter the word to check if it is a palindrome: ";
  std::cin >> word;
  std::cout << is_palindrome(word) << "\n";
}