//Diego Izquierdo Fernandez 
//      26/09/2013
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <fstream>


using namespace std;
    
/*
* Define a par: word/frequency
*/
struct wordCount
{	
    string word;	
    int count;	
};

/*
* Define some operations in the list of wordCount
*/
class wordFrequency
{
    public:
    //contruct
    wordFrequency(char* fileIn);
    //return number of words
    int countFile(int counter);
    void openFile(ifstream &inFile);
    //filter special characters
    void normalize(string arr[], int n);
    //flag true: num frequencies order ; flag false: alphabetic order 
    void bubbleSort(wordCount arr[], int n, bool flag);
    char* fileIn;
};
