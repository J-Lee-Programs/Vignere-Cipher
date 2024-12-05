#include <iostream>
#include <string>
using namespace std;
string cryptKey(string key) {
	int keysize = key.size();
	for (int i = 0; i < keysize; ++i) { //for loop counts the key's string size
		if (key[i] >= 'A' && key[i] <= 'Z')
			key += key[i]; //adds to the index of the key index
	}
	return key;
}
string Encryption(string input, string key) {
	string output;
	string newKey = cryptKey(key);
	for (int i = 0, j = 0; i < input.length(); ++i) {
		char c = input[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a'; //shifter
		output += (c + newKey[j] - 2 * 'A') % 26 + 'A'; //this is the equation
		j = (j + 1) % newKey.length(); //key correction for alphabet values
	}
	return output;
}
string Decryption(string input, string key) {
	string output;
	string newKey = cryptKey(key);
	for (int i = 0, j = 0; i < input.length(); ++i) {
		char c = input[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a'; //deshifter
		output += (c - newKey[j] + 26) % 26 + 'A'; //this is the equation
		j = (j + 1) % newKey.length(); //key correction for alphabet values
	}
	return output;
}

//driver code
int main() {
	string input, key;

	cout << "Input Message (All caps, no spaces): ";
	getline(cin, input);

	cout << "Input word key (All caps, one word): ";
	cin >> key;

	cout << "Encrypted: " << Encryption(input, key) << endl;
	cout << "Decrypted: " << Decryption(Encryption(input, key), key) << endl;
	return 0;
}