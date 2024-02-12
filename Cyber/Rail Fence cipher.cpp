#include <iostream>
#include <string>

using namespace std;

string encryptRailFence(string plaintext, int rails) {
    string ciphertext = "";
    int length = plaintext.length();

    for (int i = 0; i < rails; ++i) {
        for (int j = i; j < length; j += rails * 2 - 2) {
            ciphertext += plaintext[j];

            if (i > 0 && i < rails - 1 && j + (rails - i - 1) * 2 < length) {
                ciphertext += plaintext[j + (rails - i - 1) * 2];
            }
        }
    }

    return ciphertext;
}

string decryptRailFence(string ciphertext, int rails) {
    string decryptedText(ciphertext.length(), ' ');
    int length = ciphertext.length();
    int index = 0;

    for (int i = 0; i < rails; ++i) {
        for (int j = i; j < length; j += rails * 2 - 2) {
            decryptedText[j] = ciphertext[index++];

            if (i > 0 && i < rails - 1 && j + (rails - i - 1) * 2 < length) {
                decryptedText[j + (rails - i - 1) * 2] = ciphertext[index++];
            }
        }
    }

    return decryptedText;
}

int main() {
    string plaintext, encrypted, decrypted;
    int rails;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the number of rails: ";
    cin >> rails;

    encrypted = encryptRailFence(plaintext, rails);
    cout << "Encrypted Text: " << encrypted << endl;

    decrypted = decryptRailFence(encrypted, rails);
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}
