#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> word = { "aya", "ye", "woo", "ma" };

    for(string str : babbling) {
        bool isSpeak = true;

        while(isSpeak) {
            isSpeak = false;

            for(int i = 0; i < word.size(); i++) {
                size_t index = str.find(word[i]);

                if(index == 0) {
                    str.erase(0, word[i].size());
                    isSpeak = true;         
                    break;                       
                }
            }
        }

        if (str.empty()) answer++;
    }
    
    return answer;
}