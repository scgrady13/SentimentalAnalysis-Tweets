//
// Created by Sean Grady on 2/8/2022.
//

#include "Tweet.h"

Tweet::Tweet(){
    sentAnalysis = -1;
    testing = false;
    entireTweet = " ";

}
//function to break down each tweet into seperate words
void Tweet::createWords(words &allWords) {

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
            allWords.addWord(newWord, sent);
            //resets the buffer array
            memset(buffer, 0, sizeof(buffer));
        }
    }
//    cout << endl;
//    cout << "New Tweet" << endl;
}