#include <iostream>
#include <string>

using namespace std;

void swap(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}

void permutation(string str, int begin, int end) {
	int i;
	int range = end - begin;
	
	if(range == 1)
		cout << str << " ";
	
	for(i = 0; i < range; i++) {
		swap(str[begin], str[begin + i]);
		permutation(str, begin+1, end);
		swap(str[begin], str[begin + i]);
	}
}

int main() {
	string str;
	cin >> str;

	permutation(str, 0, str.length());
}		
