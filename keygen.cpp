#include <iostream>
#include <fstream>
#include <set>
#include <string> 
#include <time.h>

using namespace std;

string generator(const string alphabet, int length) {
    int pos;
    string key;
    set<int> posSet;
    for (int i = 0; i < length; i++) {
        pos = 0 + rand() % 16;
        key += alphabet.at(pos);
        posSet.insert(pos);
    }

    if (posSet.size() != 16) {
        key = generator(alphabet, length);
    }
    return key;
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    string alphabet = "0123456789abcdef";
    string c;

    cout << "Введите положение файла ключа: " << endl;
    getline(cin, c);

    int pos;
    string key, iv;
    set<int> posSet;
    key = generator(alphabet, 64);
    iv = generator(alphabet, 32);
 
    ofstream file(c);
    file << key << endl << iv;
}
