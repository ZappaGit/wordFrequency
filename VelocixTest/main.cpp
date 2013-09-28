//Diego Izquierdo Fernandez 
//      26/09/2013

#include <iostream>
#include "wordFrequency.h"

using namespace std;

int main(int argc, char *argv[])
{
    //cout << "Word frecuency" << endl;

    if (argv[1]==NULL) 
    {
	cout << "Usage: ./wordFrequency <text_file>" << endl;
	return -1;
    }
    
    wordFrequency word(argv[1]);

    //Declare variables
    int length;
    int counter;

    //num words
    length = word.countFile(counter);

    //Declare arrays
    string wordsM[length];			
    struct wordCount wordFreq[length]; 

    //Declare stream variables
    ifstream inFile;
    ofstream outFile;

    word.openFile(inFile);

    while (!inFile.eof()) //while not at end of file
    {
          for(int i=0; i < length; i++)
          {
             inFile >> wordsM[i];  //read words 
             word.normalize(wordsM, length); //filtering
             wordFreq[i].word = wordsM[i]; //place words
             wordFreq[i].count = 0;
          }
    }

    //Word frequency algorithm
    for (int i = 0; i < length;i++)
    {
        for (int j = 0; j < length; j++)
        {	
            if (wordsM[i] == wordFreq[j].word)
            {
               // cout << " *";
               wordFreq[i].count++;
            }
        }
    //cout <<endl;

    }

    //alphabetic order
    word.bubbleSort(wordFreq , length,false); //function to order
    //by frequency
    word.bubbleSort(wordFreq , length,true); //function to order

    //show the 20 words more frequency
    int i = 0;
    int j = i;
    int cont =20;
    while ( i < length-1)
    {
	cout << setw(4) << wordFreq[j].count << setw(10) << wordFreq[j].word << endl;
        cont--;
	while ((wordFreq[i].word == wordFreq[j].word) && (wordFreq[i].count == wordFreq[j].count))
        {
		j++;
	}
	i=j;
 	if (cont < 1) break;
    }

    inFile.close();
    outFile.close();

    return 0;
}

