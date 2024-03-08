#include "Twitter.h"


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
void printTweets(vector<int> tweets) {
	for (auto x : tweets) {
		cout << x << " ";
	}
	cout << endl;
}

/*
int main() {
	Twitter twitter;
	twitter.follow(1, 2);
	twitter.postTweet(1, 500);
	twitter.postTweet(1, 501);
	twitter.postTweet(1, 502);
	twitter.postTweet(1, 503);
	twitter.postTweet(2, 600);
	twitter.postTweet(1, 504);
	twitter.postTweet(1, 505);
	twitter.postTweet(1, 506);
	twitter.postTweet(1, 507);
	twitter.postTweet(1, 508);
	twitter.postTweet(1, 509);
	twitter.postTweet(1, 510);
	twitter.postTweet(1, 511);
	twitter.postTweet(2, 601);
	vector<int> tweets = twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
	printTweets(tweets);

	twitter.unfollow(1, 2);

	tweets = twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
	printTweets(tweets);


	return 0;
}
*/

/*
int main() {
	Twitter twitter;
	twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
	vector<int> tweets = twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
	printTweets(tweets);
	twitter.follow(1, 2);    // User 1 follows user 2.
	twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
	tweets = twitter.getNewsFeed(1);
	printTweets(tweets);
	twitter.unfollow(1, 2);  // User 1 unfollows user 2.
	tweets = twitter.getNewsFeed(1);
	printTweets(tweets);
	return 0;
}
*/