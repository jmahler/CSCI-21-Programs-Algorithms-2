
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * Count the number of words in the text piped to this program.
 * Specificially, a word is a contiguous group of characters without
 * white space.
 *
 * USAGE:
 *
 * cat textfile | ./wc
 *
 * To help imrove results the data has been normalized by converting
 * words to lower case and by removing non alpha numeric characters.
 * Also, words that are too short (< 4 characters) are not included in
 * the summary.
 */

/**
 * Convert a string to all lowercase.
 *
 * @arg string to convert.
 *
 * @returns converted string.
 */
string toLower(string s) {
	string::iterator it;
	string lowered;

	for (it = s.begin(); it != s.end(); it++) {
		lowered += tolower((*it));
	}

	return lowered;
}

/**
 * Remove any non-alhpanumeric characters (e.g. '!,.')
 * from a string.
 *
 * @arg string to process
 *
 * @returns string
 */
string toAlnum(string s) {
	string::iterator it;
	string alnum;

	for (it = s.begin(); it != s.end(); it++) {
		if (isalnum(*it))
			alnum += (*it);
	}

	return alnum;
}

/**
 * This comparison operation is used to sort the vector
 * of pairs of words and counts.
 */
bool cmp(pair<string, int> a, pair<string, int> b) {

	if (a.second > b.second)
		return true;

	return false;
}

int main(int argc, char** argv)
{
	map<string, int> words;
	int num_top_matches = 10;  // number of top matches to display
	unsigned int skip_word_len = 4;  // words shorter than this will
	                                 // be skipped in the top occurances summary

	string word;
	while (cin >> word) {

		// Normalize the data by making variations of
		// words (such as The the THE) the same.
		word = toLower(word);  // to lower case
		word = toAlnum(word);  // to alpha numeric only

		map<string, int>::iterator it;

		if (! words[word]++)
			words[word] = 1;
	}

	// display all the words
	map<string, int>::iterator it;
	int max_len = 60;  // max number of charcters per line
	string line;
	for (it=words.begin(); it != words.end(); it++) {
		stringstream ss;
		string adword;   // word to add

		ss << (*it).first << "-" << (*it).second;
		ss >> adword;

		if ((line.length() + adword.length()) > max_len) {
			cout << line << endl;
			line = "";
		} else {
			line += "  ";
			line += adword;
		}
	}
	if (line.length() > 0)
		cout << line << endl;


	// display the top most occurances

	vector< pair<string, int> > vwords;
	for (it=words.begin(); it != words.end(); it++) {
		pair<string, int> p1((*it).first, (*it).second);
		vwords.push_back(p1);
	}

	sort(vwords.begin(), vwords.end(), cmp);

	cout << "Top most occuring words:\n";
	int n = 0;
	for (unsigned int i = 0; n < num_top_matches && i < vwords.size(); i++) {
		pair<string, int> p;
		p = vwords[i];

		// skip displaying short words
		if ((p.first).length() < skip_word_len) {
			continue;
		}
		n++;

		cout << n << ": [" << p.second << "] " << p.first << endl;
	}
}
