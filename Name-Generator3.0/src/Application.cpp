#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;


struct LetterData
{
    // Data curtousy of https://www3.nd.edu/~busiforc/handouts/cryptography/Letter%20Frequencies.html

public:
    // Sorted alphabetically
    float frequencies[26] =
    {
        0.08167,    // A
        0.01492,    // B
        0.02782,    // C
        0.04253,    // D
        0.12702,    // E
        0.02228,    // F
        0.02015,    // G
        0.06094,    // H
        0.06966,    // I
        0.00153,    // J
        0.00772,    // K
        0.04025,    // L
        0.02406,    // M
        0.06749,    // N
        0.07507,    // O
        0.01929,    // P
        0.00095,    // Q
        0.05987,    // R
        0.06327,    // S
        0.09056,    // T
        0.02758,    // U
        0.00978,    // V
        0.02360,    // W
        0.00150,    // X
        0.01974,    // Y
        0.00074     // Z
    };
};

enum LetterType : unsigned char
{
    A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14, P = 15, Q = 16, R = 17, S = 18, T = 19, U = 20, V = 21, W = 22, X = 23, Y = 24, Z = 25
};

// Returns a number from min (inclusive) to max (exclusive). srand() must be set manually
int Random(int min, int max);

// Returns a lower-case letter with probabilities of how they appear in the English language
char LetterByProbability(const LetterData& let);

int main()
{
    LetterData letters;
    srand(time(NULL));

    unsigned int genAmt = 0;
    unsigned int minLength, maxLength;
    cout << "Amount to generate: ";
    cin >> genAmt;
    cout << "Name minimum length: ";
    cin >> minLength;
    cout << "Name maximum length: ";
    cin >> maxLength;
    cout << endl;

    // Pure random
    //for (int i = 0; i < genAmt; i++)
    //{
    //    cout << char(Random('A', 'A' + 25));
    //    for (int j = 0; j < Random(minLength, maxLength) - 1; j++)
    //        cout << char(Random('a', 'a' + 25));
    //    cout << endl;
    //}

    // Probability test
    for (int i = 0; i < genAmt; i++)
    {
        cout << char(LetterByProbability(letters) - 'a' + 'A');
        for (int j = 0; j < Random(minLength, maxLength) - 1; j++)
            cout << LetterByProbability(letters);
        cout << endl;
    }

    while (true);
}

int Random(int min, int max)
{
    return rand() % (max - min) + min;
}

char LetterByProbability(const LetterData& let)
{
    double probability = double(rand()) / RAND_MAX;
    float compound = 0;

    for (int i = 0; i < 26; i++)
    {
        compound += let.frequencies[i];
        if (compound >= probability)
            return 'a' + i;
    }
}