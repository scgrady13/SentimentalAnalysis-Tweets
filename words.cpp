//
// Created by Sean Grady on 2/10/2022.
//

#include "Words.h"
//function to add words to positive/negative vectors
void words::addWord(DSString word, int sent) {
    word.printWord();
    if(word == "") {
        return;
    }
    //keeps track if the word is found
    bool checker = false;
    //tracks location of where the word is in the vector
    int location = 0;
    //checks for the sentiment of each tweet then adds the word to the vector
    if(sent == 4) {
        //if first word passed in instantly adds to vector
        if (positiveW.size() == 0) {
            positiveW.push_back(word);
            positiveC.push_back(1);
        } else {
            for (int i = 0; i < positiveW.size(); i++) {
                //checks if the word already exists, if it does increments the occurance of it
                if (positiveW.at(i).equals(word)) {
                    checker = true;
                    location = i;
                    break;
                }
            }
            //if checker false adds new word
            if(checker == false) {
                positiveW.push_back(word);
                positiveC.push_back(1);
        }   //if not increments word occurance
            else{
                positiveC.at(location)++;
            }
        }
    }

//
//        auto it=positive.begin();
//        it = positive.find(word);
//        if(it == positive.end()){
//            positive.at(word)++;
//        }
//     positive.insert({word, 0});

    //same as positive tweets but for negative tweets
    if(sent == 0){
        if (negativeW.size() == 0) {
            negativeW.push_back(word);
            negativeC.push_back(1);
        } else {
            for (int i = 0; i < negativeW.size(); i++) {
                //checks if the word already exists, if it does increments the occurance of it
                if (negativeW.at(i).equals(word)) {
                    checker = true;
                    location = i;
                    break;
                }
            }
            if(checker == false) {
                negativeW.push_back(word);
                negativeC.push_back(1);
            }
            else{
                negativeC.at(location)++;
            }
        }
    }
}
//used for debugging checked values of tweet total word count
void words::checkVectors() {
        for(int i = 0; i < positiveC.size(); i++){
            cout << positiveC.at(i) << endl;
        }
}
//function used to analyze testing tweets against training tweets
int words::sentAnalysis(DSString entireTweet){
    int tracker = 0;
    int lastChar = 0;//tracks first character in word
    int firstChar = 0;//tracks second letter in a word
    for(int i = 0; i < entireTweet.getLength(); i++){
        if(ispunct(entireTweet.getChar(i))) continue;
        if(entireTweet.getChar(i) == 32) {
            firstChar = lastChar + 1;
            lastChar = i;

        }
        if(lastChar == i){
            //buffer to hold all characters in the tweet
            char buffer[500];
            //iterates through each word using trackers
            for(int j = firstChar, k = 0; j < lastChar; j++, k++){
                if(entireTweet.getChar(i) <= 'A' && entireTweet.getChar(i) >= 'Z') continue;
                buffer[k] = entireTweet.getChar(j);
//               cout << buffer[k];
            }
            //creates new DSString of the word
//            cout << buffer << " ";
            DSString newWord(buffer);
            //adds the word to the tweet set
            //resets the buffer array
            for(int l = 0; l < positiveW.size(); l++){
                if(positiveW.at(l).equals(newWord)){
                    tracker+=positiveC.at(l);
                }
            }
            for(int l = 0; l < negativeW.size(); l++){
                if(negativeW.at(l).equals(newWord)){
                    tracker-=negativeC.at(l);
                }
            }
            memset(buffer, 0, sizeof(buffer));
        }
    }
    return tracker;
}

