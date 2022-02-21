//
// Created by Sean Grady on 2/10/2022.
//
//class that holds data for each word in each tweet as well is used to do the sentimental analysis on the test tweets
#ifndef PA01_SENTIMENT_WORDS_H
#define PA01_SENTIMENT_WORDS_H
#include "DSString.h"

#include <vector>
#include <algorithm>
using namespace std;
class words {
private:
//    map<DSString, int> positive;
//    map<DSString, int> negative;
//vectors for postive and negative tweets with a counter for each type
    vector<DSString> positiveW;
    vector<int> positiveC;

    vector<DSString> negativeW;
    vector<int> negativeC;



public:
    //default constructore
    words(){};
    //adds words to postive/negative tweet vectors
    void addWord(DSString, int);
    //used for debugging
    void checkVectors();

    //analyzes tweets against training data
    int sentAnalysis(DSString);
};


#endif //PA01_SENTIMENT_WORDS_H
