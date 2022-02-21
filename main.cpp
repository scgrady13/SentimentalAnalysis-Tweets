#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "TweetSet.h"

//function to run catch
void runCatch();
using namespace std;
//main class that runs catch cases and the program through the tweetset class
int main(int argc, char* argv[]) {
//    runs catch tests
//
    if(argc == 0){
       runCatch();
    }

    //function called to run all tweets
    TweetSet allTweets(argc, argv);
    return 0;
}
//runs catch function
void runCatch(){
    Catch::Session().run();
}
