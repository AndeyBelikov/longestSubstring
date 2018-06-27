
#include <iostream>
#include <string>
#include <unordered_set>

using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

string subString(string input, int& maxLengthOver)
{
	unordered_set<char> uniqueCharSet;

	string longestStrOverAll = "";
	string longestStrTillNow = "";

	int maxLengthTill = 0;

	for (size_t i = 0; i < input.length(); i++) {

		char letter = input.at(i);
		unordered_set<char>::const_iterator it = uniqueCharSet.find(letter);

		// if uniqueCharSet doesnt contains the letter, it will be equals to end
		if (it != uniqueCharSet.end()) {

			longestStrTillNow = "";
			maxLengthTill = 0;
			uniqueCharSet.clear();

		}

		longestStrTillNow += letter;
		++maxLengthTill;
		uniqueCharSet.emplace(letter);

		if (longestStrTillNow.length() > longestStrOverAll.length()) {

			longestStrOverAll = longestStrTillNow;
			maxLengthOver = maxLengthTill;

		}
	}

	return longestStrOverAll;
}

int main()
{
	string text = "pwwkew"; // "abcabcbb", "bbbbbb"
	int max_length = 0;
	string sub = subString(text, max_length);
	cout << "max substring is \"" << sub << "\" with length: " << max_length << "\n";
	getchar();
}


