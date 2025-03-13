#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fizzbuzz;
    int answer;
    
    for(int i = 0; i < 3; i++){
        cin >> fizzbuzz;
        
        if(fizzbuzz == "FizzBuzz") continue; 
        else if(fizzbuzz == "Fizz") continue;
        else if(fizzbuzz == "Buzz") continue;
        else {
            answer = stoi(fizzbuzz);
            answer += (3-i);
        }
    }
    
    if(answer%15 == 0) cout << "FizzBuzz";
    else if(answer%3 == 0) cout << "Fizz";
    else if(answer%5 == 0) cout << "Buzz";
    else cout << answer;
    
    return 0;
}