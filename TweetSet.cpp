//
// Created by Sean Grady on 2/9/2022.
//

#include "TweetSet.h"
//function that runs the most of the program, opens all files read them in and runs analysis on files then prints output file
TweetSet::TweetSet(int argc, char* argv[]) {
        fstream trainingData;
        int sentInt;
        //opens first file
        trainingData.open(argv[1]);
        //buffer that holds characters being read in
        char buffer[500];
        trainingData.getline(buffer, 500);
        while(!trainingData.eof()){
            //creates new tweetobject to be used to fill vectors
            Tweet newTweet;
            trainingData.getline(buffer,500,',');
//            DSString sentiment(buffer);
//
            newTweet.setSent(abs(atoi(buffer)));
            trainingData.getline(buffer,500,',');
//            DSString id(buffer);
//            cout << buffer << " ";
            //sets ID of tweet
            newTweet.setID(abs(atoi(buffer)));
            trainingData.getline(buffer,500,',');
            trainingData.getline(buffer,500,',');
            trainingData.getline(buffer,500,',');
            trainingData.getline(buffer,500);
            DSString tweet(buffer);
            newTweet.setTweet(tweet);
//            cout << buffer << endl;
            trainingTweet.push_back(newTweet);
        }

        fstream testingData;
        testingData.open(argv[2]);
        if(!testingData.is_open()){
            cout << "Failed to open";
        }
        //reads in data for file of testing tweets
        testingData.getline(buffer, 500);
        while(!testingData.eof()) {
            Tweet newTweet;
            newTweet.setSent(0);
            testingData.getline(buffer, 500, ',');
            newTweet.setID(abs(atoi(buffer)));
            testingData.getline(buffer, 500, ',');
            testingData.getline(buffer, 500, ',');
            testingData.getline(buffer, 500, ',');
            testingData.getline(buffer, 500);
            DSString tweet(buffer);
            newTweet.setTweet(tweet);
            newTweet.setTesting(true);
            testingTweet.push_back(newTweet);
        }
        fstream checker;
        checker.open(argv[3]);

        if(!checker.is_open()) {
            cout << "Failed to open";
        }
        //reads in file for ID and Sentiment of tweets being tested
        checker.getline(buffer, 500);
        while(!checker.eof()) {
            Tweet analysis;
            checker.getline(buffer, 500, ',');
            analysis.setSent(abs(atoi(buffer)));
            checker.getline(buffer, 500);
            analysis.setID(abs(atoi(buffer)));
            finalTweet.push_back(analysis);
    }
        //creates all words from training data
    for(int i = 0; i < trainingTweet.size(); i++){
        trainingTweet[i].createWords(allWords);
    }
    //gets the sentiment using sentimental analysis of each word read in from the first file comapaired to new words from testing data
    for(int i = 0; i < testingTweet.size(); i++){
         sentInt = allWords.sentAnalysis(testingTweet.at(i).getTweet());
            if(sentInt > 0){
                testingTweet.at(i).setSent(4);
            }
            else{
                testingTweet.at(i).setSent(0);
            }
        }
    //gets accuracy of analysis then writes to the output file
    accuracy = analyze();
    ofstream output;
    //was not able to get output to write to it when I used this, i copied the direct file path for it and it worked while doing that
    //output.open(argv[4])

    output.open("C:\\Users\\12013\\Documents\\GitHub\\22s-2341-scgrady13\\data\\output.txt");
    if(!output.is_open()) cout << "failed to open" << endl;
    if(output.is_open()) cout << "file open" << endl;
    cout << fixed;
    cout << setprecision(3);
    cout << accuracy << endl;
    output << fixed;
    output << setprecision(3);
    output << accuracy << endl;
    //adds incorrect tweets to output file
    for(int i = 0; i < incorrect.size(); i++){
        output << incorrect.at(i).getID() << endl;
        cout << incorrect.at(i).getID() << endl;
    }

    output.close();
}

//function to find tweet by passing in the ID
bool TweetSet::findTweet(int id) {
    for(int i = 0; i < testingTweet.size(); i++){
        if(testingTweet[i].getID() == id){
            return testingTweet[i].getSent();
        }
    }
    return false;
}
//analyzes the accuracy of the analysis
double TweetSet::analyze(){
    double accuracyNum;
    double totalTweets = double(testingTweet.size());
    int tweetLocation = 0;
    //iterates over testingtweet vector and checks accuracy against the finalTweet vectors sentiment, incremenets if its correct
    for(int j = 0; j < testingTweet.size(); j++){
        for(int i = 0; i < testingTweet.size(); i++) {
            if (testingTweet[j].getID() == finalTweet[i].getID())
            {
                if(testingTweet[i].getSent() == finalTweet[i].getSent()){
                    totalCorrect++;
                }
                else {
                    //adds incorrect tweets to vector
                    incorrect.push_back(testingTweet[i]);
                }
            }
        }
    }
//    for(int i = 0; i < testingTweet.size(); i++){
//        if(testingTweet[i].getSent() == finalTweet[i].getSent()){
//            totalCorrect++;
//        }
//        else {
//            //adds incorrect tweets to vector
//            incorrect.push_back(testingTweet[i]);
//        }
//    }
    //calculates and returns accuracy
    accuracyNum = totalCorrect/totalTweets;
    return accuracyNum;
}



