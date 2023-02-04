#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

bool compareFrequency(const pair<char, int>& a, const pair<char, int>& b)
{
    return a.second > b.second;
}

int main()
{
    const char testedString[] = "Hi! This is a code that will check this string and will count the frequency of every character presented in this string.";
    const int alphabetLength = 26;
    char alphabet[alphabetLength * 2];
    int counter[alphabetLength * 2] = { 0 };

    // 65 - A   90 - Z     97 - a   122 - z
    for (int i = 0; i < alphabetLength * 2; i++) {
        if (i < alphabetLength) {
            alphabet[i] = char(65 + i);
        }
        else {
            alphabet[i] = char(97 + i - alphabetLength);
        }
    }

    for (int i = 0; i < strlen(testedString); i++) {
        for (int j = 0; j < alphabetLength * 2; j++) {
            if (testedString[i] == alphabet[j]) {
                counter[j]++;
            }
        }
    }

    pair<char, int> letterFrequency[alphabetLength * 2];
    for (int i = 0; i < alphabetLength * 2; i++) {
        letterFrequency[i] = make_pair(alphabet[i], counter[i]);
    }

    sort(letterFrequency, letterFrequency + alphabetLength * 2, compareFrequency);

    for (int i = 0; i < alphabetLength * 2; i++) {
        if (letterFrequency[i].second == 0) {
            break;
        }
        cout << letterFrequency[i].first << ": " << (float)letterFrequency[i].second * 100 / strlen(testedString) << "%" << endl;
    }

    return 0;
}
