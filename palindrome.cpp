
#include <iostream>
#include <stack>

using namespace std;

/**
 * Given a string, determine if it is a palindrome.
 *
 * USAGE:
 *
 * ./palindrome <word>
 */

string reverse(string);
bool isPalindrome(string);
bool isPalindrome2(string);

int main(int argc, char** argv)
{
	if (argc <= 1) {
		cout << "USAGE: ./a.out <some string>\n";
		return 1;
	}

	string word;  	   // without spaces
	string word_orig;  // with spaces

	// build word and word_orig from **argv
	for (int i = 1; i < argc; i++) {

		// include spaces in original
		if (i >= 2)
	    	word_orig += " ";

		word += argv[i];
		word_orig += argv[i];
	}

	cout << "'" << word_orig << "' is ";

	//if (! isPalindrome(word))
	if (! isPalindrome2(word))
		cout << "NOT";

	cout << " a palindrome\n";

	return 0;
}

// {{{ isPalindrome()
/**
 * Test wheter a string is or is not a palindrome.
 *
 * @arg string to test
 *
 * @returns true if it is a palindrome, false otherwise
 *
 * This version simply reverses the string and tests whether
 * it is equal to the original string.
 */
bool isPalindrome(string s) {
	string sr = reverse(s);

	if (sr == s)
		return true;
	// else
	return false;
}
// }}}

// {{{ isPalindrome2()
/**
 * Test wheter a string is or is not a palindrome.
 *
 * @arg string to test
 *
 * @returns true if it is a palindrome, false otherwise
 *
 * This version does not have to scan through the entire
 * string to detect if it is not a palindrome.
 * If the first character past the half way point is different
 * it would only have to perform length/2 + 1 steps.
 * If it is a palindrome it still has to scan the entire string.
 */
bool isPalindrome2(string s) {
	int len = s.length();
	int mid = len / 2;
	bool oddp = (0 != (len % 2));

	stack<int> q;

	int i = 0;
	for (; i < mid; i++) {
		q.push(s[i]);
	}

	if (oddp)
		i += 1;  // skip the odd middle

	for (; i < len; i++) {
		char c = q.top();

		if (c != s[i])
			return false;

		q.pop();
	}

	return true;
}
// }}}

// {{{ reverse(string)
/**
 * Reverse all the characters in a string.
 *
 * @arg string to reverse
 *
 * @returns reversed string
 *
 * Uses a stack to accomplish reversion.
 */
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
// }}}

