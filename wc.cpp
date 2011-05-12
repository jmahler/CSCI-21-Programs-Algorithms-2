
#include <iostream>
#include <map>

using namespace std;

/**
 * Count the number of words in the text piped to this program.
 * Specificially, a word is a contiguous group of characters without
 * white space.
 *
 * USAGE:
 *
 * cat textfile | ./wc
 */

int main(int argc, char** argv)
{
	map<string, int> words;

	string word;
	while (cin >> word) {
		map<string, int>::iterator it;

		if (! words[word]++)
			words[word] = 1;
	}

	map<string, int>::iterator it;
	for (it=words.begin(); it != words.end(); it++) {
		cout << (*it).first << ": " << (*it).second << endl;
	}
}
