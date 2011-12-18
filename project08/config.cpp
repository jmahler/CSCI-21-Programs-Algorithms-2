
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

/**
 * Read configuration values from the text piped to this program
 * and display them.
 *
 * FORMAT:
 *
 *   key:val
 *   key2:val
 *   ...
 *
 * Anything seperated by a space after the val is ignored.
 */

int main(int argc, char** argv)
{
	map<string, int> configs;

	/*
	 * For every line, get the key and the value
	 * and assign them to the map.
	 */
	string line;
	// key:val ; comment
	while (getline(cin, line)) {

		stringstream liness(line);

		string key;
		{
		string keystr;
		if (getline(liness, keystr, ':').eof())
			continue;  // skip this blank or invalid line

		// remove any remaining spaces
		// from the front and back
		stringstream keyss(keystr);
		keyss >> key;
		}

		int val;
		liness >> val;

		configs[key] = val;
		// will overwrite duplicates
	}

	// display all the values
	//cout << configs.size() << endl;
	map<string, int>::iterator it;
	for (it = configs.begin(); it != configs.end(); it++) {
		cout << (*it).first << ": " << (*it).second << endl;
	}
}
