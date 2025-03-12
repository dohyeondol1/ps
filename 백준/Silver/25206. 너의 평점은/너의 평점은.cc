#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    string major_subject, grade; 
    double credit, major_rating, grade_point;
    double sum = 0;
    double credit_sum = 0;
    
    for(int i = 0; i < 20; i++) {
        cin >> major_subject >> credit >> grade;
        if(grade == "P") {
            continue;
        }
        else {
            if(grade == "A+") grade_point = 4.5;
            if(grade == "A0") grade_point = 4.0;
            if(grade == "B+") grade_point = 3.5;
            if(grade == "B0") grade_point = 3.0;
            if(grade == "C+") grade_point = 2.5;
            if(grade == "C0") grade_point = 2.0;
            if(grade == "D+") grade_point = 1.5;
            if(grade == "D0") grade_point = 1.0;
            if(grade == "F") grade_point = 0.0;
        }
        
        sum += credit * grade_point;
        credit_sum += credit;
    }
    
    major_rating = sum / credit_sum;
    cout << major_rating;
    
    return 0;
}