#include <string>
#include <vector>
using namespace std;

int TimeTrans(string time) {
    return ((time[0]-'0')*600 + (time[1]-'0')*60 + (time[3]-'0')*10 + time[4]-'0');
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int video_length = TimeTrans(video_len);
    int current_pos = TimeTrans(pos);
    int op_st = TimeTrans(op_start);
    int op_ed = TimeTrans(op_end);
    
    for(auto &cmd : commands) {
        if(current_pos >= op_st && current_pos <= op_ed) 
            current_pos = op_ed;
        
        if(cmd == "prev") {
            current_pos -= 10;
            if(current_pos < 0) current_pos = 0;
        }
        else if(cmd == "next") {
            current_pos += 10;
            if(current_pos > video_length) current_pos = video_length;
        }
        
        if(current_pos >= op_st && current_pos <= op_ed) 
            current_pos = op_ed;
    }
    
    int m1, m2, s1, s2;
    if(current_pos/600 >= 1) {
        m1 = current_pos/600;
        current_pos -= m1*600;
    }
    if(current_pos/60 >= 1) {
        m2 = current_pos/60;
        current_pos -= m2*60;
    }
    if(current_pos/10 >= 1) {
        s1 = current_pos/10;
        current_pos -= s1*10;
    }
    if(current_pos/1 >= 1) {
        s2 = current_pos/1;
        current_pos -= s2;
    }
    
    answer += to_string(m1);
    answer += to_string(m2);
    answer += ':';
    answer += to_string(s1);
    answer += to_string(s2);

    
    return answer;
}