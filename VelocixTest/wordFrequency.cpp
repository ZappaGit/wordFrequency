//Diego Izquierdo Fernandez 
//      26/09/2013
#include "wordFrequency.h"

wordFrequency::wordFrequency(char *fileIn)
{
    this->fileIn = fileIn;
}

int wordFrequency::countFile(int counter)
{
    ifstream inFile;
    int counts = 0;
    string str;

    inFile.open(this->fileIn);
    while (!inFile.eof())
    {
          inFile >> str;
          counts++;
    }
    
     return counts;
}

void wordFrequency::openFile(ifstream &inFile)
{
    //open input file
    inFile.open(this->fileIn);
    if (!inFile)
    {
         cout << "Cannot open input file. Program terminates!" << endl;
    }
   
}

void wordFrequency::normalize(string arr[], int n)
{
    int i,len;

    for ( i = 0; i < n; i++)
    {
        string str = arr[i];
        len=str.length();
        int j= 0;
        while(j<len)
            {
                char c=str[j];
                if(((c>='0')&&(c<='9'))||((c>='A')&&(c<='Z'))||((c>='a')&&(c<='z')))
                {
                    ++j;
                }
                else
                {
                    str.erase(j,1);
                    --len;
                }
            }
        arr[i] = str;
     }

}
 
void wordFrequency::bubbleSort(wordCount arr[], int n, bool flag)
{   
    int i, j;
    struct wordCount tempWC;

    if (flag)
    {
	for ( i = 1; i < n; i++)
	{
          for (j = 0; j < n - i; j++)
          {
            if (arr[j].count < arr[j+1].count)
            {
  		 tempWC = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = tempWC;

            }
          }
         }
     } else
     {
	for ( i = 1; i < n; i++)
	{
          for (j = 0; j < n - i; j++)
          {
            if (arr[j].word < arr[j+1].word)
            {
  		 tempWC = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = tempWC;
            }
          }
        } 
      }
}     
