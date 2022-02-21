//
// Created by Sean Grady on 2/8/2022.
//
//class that holds all the data on each tweet that is read in
#ifndef PA01_SENTIMENT_TWEET_H
#define PA01_SENTIMENT_TWEET_H

#include <iostream>
#include <fstream>
#include <iostream>
#include "DSString.h"
#include "Words.h"
using namespace std;
class Tweet {
private:

    DSString entireTweet;
    //default set to false for tweets that come in without sentiment
    int id;
    int sent;
    //used to analyze if a tweet is positive or negative
    int sentAnalysis;
    //used to depict if a tweet is a testing tweet or a training tweet;
    bool testing;
public:
    Tweet();
    bool checkSentiment();
    int getID(){return this->id;}
    int getSentAnalysis(){return this->sentAnalysis;}
    int getSent(){return this->sent;}
    DSString getTweet() {return entireTweet;}
    //setters for tweet dta
    void setID(int idin){this->id = idin;}
    void setSent(int sentin){this->sent = sentin;}
    void setTesting(bool testin){this->testing = testin;}

    void setTweet(DSString tweet) {this->entireTweet = tweet;}

    //creates all words from training data
    void createWords(words &);
    //converts tweets to uppercase
    void toUpper();
};


#endif //PA01_SENTIMENT_TWEET_H
