/*
You are given an integer numberOfUsers representing the total number of users and an array events of size n x 3.

Each events[i] can be either of the following two types:

Message Event: ["MESSAGE", "timestampi", "mentions_stringi"]
This event indicates that a set of users was mentioned in a message at timestampi.
The mentions_stringi string can contain one of the following tokens:
id<number>: where <number> is an integer in range [0,numberOfUsers - 1]. There can be multiple ids separated by a single whitespace and may contain duplicates. This can mention even the offline users.
ALL: mentions all users.
HERE: mentions all online users.
Offline Event: ["OFFLINE", "timestampi", "idi"]
This event indicates that the user idi had become offline at timestampi for 60 time units. The user will automatically be online again at time timestampi + 60.
Return an array mentions where mentions[i] represents the number of mentions the user with id i has across all MESSAGE events.

All users are initially online, and if a user goes offline or comes back online, their status change is processed before handling any message event that occurs at the same timestamp.

Note that a user can be mentioned multiple times in a single message event, and each mention should be counted separately.

 

Example 1:

Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]]

Output: [2,2]

Explanation:

Initially, all users are online.

At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]

At timestamp 11, id0 goes offline.

At timestamp 71, id0 comes back online and "HERE" is mentioned. mentions = [2,2]

Example 2:

Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","12","ALL"]]

Output: [2,2]

Explanation:

Initially, all users are online.

At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]

At timestamp 11, id0 goes offline.

At timestamp 12, "ALL" is mentioned. This includes offline users, so both id0 and id1 are mentioned. mentions = [2,2]

Example 3:

Input: numberOfUsers = 2, events = [["OFFLINE","10","0"],["MESSAGE","12","HERE"]]

Output: [0,1]

Explanation:

Initially, all users are online.

At timestamp 10, id0 goes offline.

At timestamp 12, "HERE" is mentioned. Because id0 is still offline, they will not be mentioned. mentions = [0,1]

 

Constraints:

1 <= numberOfUsers <= 100
1 <= events.length <= 100
events[i].length == 3
events[i][0] will be one of MESSAGE or OFFLINE.
1 <= int(events[i][1]) <= 105
The number of id<number> mentions in any "MESSAGE" event is between 1 and 100.
0 <= <number> <= numberOfUsers - 1
It is guaranteed that the user id referenced in the OFFLINE event is online at the time the event occurs.

*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        struct EV{int t;int order; vector<string> e;};
        //Order offline=0 and message=1 so that for the sametimestamp , offline gets processed first 
        // We convert to struct so that we can sort
        // t s timestamp
        // e is the entire vector<string> event as is ;
        vector<EV> evs;

        for(auto &e:events){
            int t=stoi(e[1]); //stoi ignores id and only converts the numerical part
            int order=(e[0]=="OFFLINE")? 0:1;
            evs.push_back({t,order,e});
        }

        sort(evs.begin(),evs.end(),[](const EV &a , const EV &b){
            if(a.t!=b.t) return a.t < b.t;
            //If same timestamp
            return a.order < b.order;
        });

        vector<int> mentions(numberOfUsers,0);

        vector<int> offline_until(numberOfUsers,0);

        //Now process each event
        for(auto &ev:evs){
            string type=ev.e[0];
            int t=ev.t;

            if(type=="OFFLINE"){
                int uid = stoi(ev.e[2]);
                offline_until[uid]=t + 60; // t+60 it will be online again
            }else{ //MESSAGE
                string s=ev.e[2];

                if(s=="ALL"){
                    for(int i=0;i<numberOfUsers;i++) mentions[i] +=1;
                }else if (s == "HERE"){
                    for (int i = 0; i < numberOfUsers; ++i)
                        if (t >= offline_until[i]) mentions[i] += 1;
                }else{
                    stringstream ss(s); // s can be like "id1 id0  id2"

                    string tok; // each word will be extracted until space so tok will be id1 then id1 then id2

                    while(ss >> tok){ // >> is the operator that does that , check comments after the code 
                        if (tok.rfind("id", 0) == 0) {
                            /*
                            rfind("id", 0) checks if the substring "id" starts at index 0.

                            So the condition is:

                            true if tok begins with "id"

                            false for "ALL" or "HERE"*/
                            int uid = stoi(tok.substr(2));
                            mentions[uid] += 1;
                    }
                    }
                }
            }
        }

        return mentions ;

        /*
        TC = O(E log E + E × (K + U))
        E = number of events (≤ 100)

        U = number of users (≤ 100)

        K = number of tokens inside a message (≤ 100)

        SC:O(U + E + K)
        */
    }
};

/*
1.   std::string str1 = "12345";
    std::string str2 = "45 chickens";
    std::string str3 = "  -987";

        try{
        int num1 = std::stoi(str1); // Converts entire string
        int num2 = std::stoi(str2); // Stops at 'c', converts "45"
        int num3 = std::stoi(str3); // Handles leading whitespace and sign

        std::cout << "num1: " << num1 << std::endl;
        std::cout << "num2: " << num2 << std::endl;
        std::cout << "num3: " << num3 << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }

    return 0;

2.   A stringstream is a class in C++ that allows you to treat a string object as a stream, similar to how std::cin and std::cout work with the console. This makes it useful for tasks like parsing strings, formatting data, and converting between strings and numerical types. 
To use stringstream, you must include the <sstream> header file. 

    int main() {
    std::string sentence = "C++ stringstream is very useful";
    std::stringstream ss(sentence); // Initialize stringstream with the sentence
    std::string word;
    std::vector<std::string> words;

    // Use the extraction operator in a loop to read word by word
    while (ss >> word) {
        words.push_back(word);
    }

    // Print the extracted words
    for (const std::string& w : words) {
        std::cout << w << std::endl;
    }

    return 0;
}


}
*/

