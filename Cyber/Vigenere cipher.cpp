#include<iostream>
#include<string>
using namespace std;

string encrypt(string plaintext, string key)
{
    string ciphertext = "";
    int keyLength = key.length();

    for(int i=0, j=0; i< plaintext.length(); i++)
    {
        char currentChar = plaintext[i];

        if(isalpha(currentChar))
        {
            char base = isupper(currentChar)?'A':'a';
            char keyChar = key[j % keyLength];
            char encryptedChar;
            if(base =='A')
            {
                encryptedChar = ((currentChar - base + keyChar - 'A') % 26) + base;
            }
            else{
                encryptedChar = ((currentChar - base + keyChar - 'a') % 26) + base;
            }


            ciphertext += encryptedChar;
            j++;
        }
        else
        {
            ciphertext += currentChar;
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key)
{
    string plaintext = "";
    int keyLength = key.length();

    for(int i=0, j=0; i<ciphertext.length();i++)
    {
        char currentChar = ciphertext[i];

        if(isalpha(currentChar))
        {
            char base = isupper(currentChar)?'A':'a';
            char keyChar = key[j % keyLength];
            char decryptedChar;
            if(base == 'A')
            {
                decryptedChar = ((currentChar - base - (keyChar - 'A') + 26) % 26) + base;
            }
            else{
                decryptedChar = ((currentChar - base - (keyChar - 'a') + 26) % 26) + base;
            }

            plaintext += decryptedChar;
            j++;
        }
        else
        {
            plaintext += currentChar;
        }
    }
    return plaintext;
}

int main()
{
    string plaintext, key,encrypted,decrypted;

    cout<<"Enter the plaintext: ";
    getline(cin, plaintext);

    cout<<"Enter the key: ";
    getline(cin, key);

    encrypted = encrypt(plaintext, key);
    cout<<"Encrypted text: "<<encrypted<<endl;

    decrypted = decrypt(encrypted, key);
    cout<<"Decrypted text: "<<decrypted<<endl;

    return 0;
}
