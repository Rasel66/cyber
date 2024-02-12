#include<iostream>
#include<string>
using namespace std;

string encrypt(string plaintext, int shift)
 {
     string ciphertext = "";

     for(char& ch: plaintext)
     {
         if(isalpha(ch))
         {
             char base = isupper(ch)? 'A':'a';
             ch = (ch - base + shift)%26 + base;
         }
         ciphertext += ch;
     }
     return ciphertext;
 }

 string decrypt(string ciphertext, int shift)
 {
     return encrypt(ciphertext, 26 - shift);
 }

 int main()
 {
     string plaintext, encrypted, decrypted;
     int shift;

     cout<<"Enter the plaintext: "<<endl;
     getline(cin, plaintext);

     cout<<"Enter the shift value: "<<endl;
     cin>> shift;

     encrypted = encrypt(plaintext, shift);
     cout<<"Encrypted text: "<< encrypted<<endl;

     decrypted = decrypt(encrypted, shift);
     cout<<"Decrypted text: "<< decrypted<<endl;

     return 0;
 }
