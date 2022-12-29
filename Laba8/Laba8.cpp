#include <iostream>
#include <fstream>
//#include "Laba8.h"

using namespace std;

const int sentenceSize = BUFSIZ;

void CreateFile(ofstream& firstFile, char fileName[]);
void CompareFiles(ifstream& readFirstFile, ifstream& readSecondFile);
void drawLine(int n = 50, char c = '=');

int main()
{
    drawLine();
    cout << "Creating first file: " << endl;
    ofstream firstFile;
    cout << "Please,enter file name: ";
    char firstFileName[sentenceSize + 1];
    cin.getline(firstFileName, sentenceSize);
    char extension[] = ".txt";
    strcat(firstFileName, extension);
    CreateFile(firstFile, firstFileName);
    drawLine();


    cout << "Creating second file: " << endl;
    ofstream secondFile;
    cout << "Please,enter second file name: ";
    char secondFileName[sentenceSize + 1];
    cin.getline(secondFileName, sentenceSize);
    strcat(secondFileName, extension);
    CreateFile(secondFile, secondFileName);
    drawLine();


    ifstream readFirstFile(firstFileName);
    ifstream readSecondFile(secondFileName);
    drawLine();
    CompareFiles(readFirstFile, readSecondFile);
   
}

void CompareFiles(std::ifstream& readFirstFile, std::ifstream& readSecondFile)
{
    char c;
    int counter = 0;
    if (readFirstFile.is_open() && readSecondFile.is_open())
    {
        while (readFirstFile.good() && readSecondFile.good())
        {
            if (readFirstFile.get() != readSecondFile.get())
            {
                cout << "Position where is the first difference = " << counter << endl;
                break;
            }
            counter++;
        }
    }
}

void CreateFile(ofstream& file, char fileName[])
{
    file.open(fileName);
    if (!file.is_open())
    {
        cout << "Couldn`t open " << fileName << " file" << endl;
        return;
    }
    cout << "Please,enter a text to write in "<< fileName << " file: " << endl;
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
