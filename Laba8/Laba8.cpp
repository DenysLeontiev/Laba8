#include <iostream>
#include <fstream>
//#include "Laba8.h"

using namespace std;

const int sentenceSize = BUFSIZ;

void CreateFile(ofstream& firstFile);
void drawLine(int n = 30, char c = '=');

int main()
{
    drawLine();
    cout << "Creating first file: " << endl;
    ofstream firstFile;
    CreateFile(firstFile);
    drawLine();
    cout << "Creating second file: " << endl;
    ofstream secondFile;
    CreateFile(secondFile);
    drawLine();
}

void CreateFile(ofstream& file)
{
    cout << "Please,enter file name: ";
    char fileName[sentenceSize + 1];
    cin.getline(fileName, sentenceSize);
    char extension[] = ".txt";
    strcat(fileName, extension);
    file.open(fileName);
    if (!file.is_open())
    {
        cout << "Couldn`t open " << fileName << " file" << endl;
        return;
    }
    cout << "Please,enter a text to write in "<< fileName << "file: " << endl;
    char firstFileText[sentenceSize + 1];
    cin.getline(firstFileText, sentenceSize);
    cout << "File " << fileName << " is successfully opened" << endl;
    file << firstFileText;
    file.close();
}

void drawLine(int n, char c)
{
    cout.fill(c);
    cout.width(n + 1);
    cout << "\n";
    cout.fill(' ');
    //cout << setfill(c) << setw(n + 1) << '\n' << setfill(' ');
}
