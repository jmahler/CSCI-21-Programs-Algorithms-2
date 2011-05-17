
#include <iostream>
#include <stack>

using namespace std;

/**
 * Given a string, determine if it is a palindrome.
 *
 * USAGE:
 *
 * ./palindrom <word>
 */

string reverse(string);

int main(int argc, char** argv)
{
	if (argc <= 1) {
		cout << "USAGE: ./a.out <some string>\n";
		return 1;
	}

	string word;
	string word_orig;

	// join all the words in argv in to a single string separated by spaces
	for (int i = 1; i < argc; i++) {

		// include spaces
		if (i >= 2)
	    	word_orig += " ";

		word += argv[i];
		word_orig += argv[i];
	}

	string wordr;  // word in reverse stored here

	wordr = reverse(word);

	//cout << "The word '" << word << "' in reverse is '" << wordr << "'\n";

	cout << "'" << word_orig << "' is ";

	if (wordr != word)
		cout << "NOT";

	cout << " a palindrome\n";

	return 0;
}

string reverse(string word) {
	stack<char> sk;
	int size = word.size();
	string wordr;  // word in reverse stored here

	// put the word in the stack
	for (int i = 0; i < size; i++) {
		sk.push(word[i]);
	}

	for (int i = 0; i < size; i++) {
		wordr += sk.top();
		sk.pop();
	}

	return wordr;
}
