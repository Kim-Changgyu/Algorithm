#include <iostream>
#include <string>

using namespace std;

bool palindrome(string str, int first, int last) {
	if(last <= first)
		return true;
	else if(str[first] != str[last])
		return false;
	else
		palindrome(str, first+1, last-1);
}

int main() {
	string word = "";
	cin >> word;

	cout << word << endl;
	if(palindrome(word, 0, word.length()-1) == true)
		cout << "True" << endl;
	else
		cout << "False" << endl;
}
