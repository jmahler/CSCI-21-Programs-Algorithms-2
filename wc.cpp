
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
 */

bool cmp( pair<string, int> a, pair<string, int> b) {

	if (a.second > b.second)
		return true;

	return false;
}

int main(int argc, char** argv)
{
	map<string, int> words;
	int num_top_matches = 50;  // number of top matches to display
	unsigned int skip_word_len = 4;  // words shorter than this will
	                                 // be skipped in the top occurances summary

	string word;
	while (cin >> word) {
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
