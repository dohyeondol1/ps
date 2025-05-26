#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len은 배열 bandage의 길이입니다.
// attacks_rows는 2차원 배열 attacks의 행 길이, attacks_cols는 2차원 배열 attacks의 열 길이입니다.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int answer = 0;
    
    int time = 1, healCount = 0, currentHealth = health;
    for(int i = 0; i < attacks_rows; i++) {
        while(time < attacks[i][0]) {
            healCount++;
            if(healCount == bandage[0]) {
                if((currentHealth+bandage[2]) > health) currentHealth = health;
                else currentHealth += bandage[2];
                healCount = 0;
            }
            currentHealth += bandage[1];
            if (currentHealth > health) currentHealth = health;
            time++;
        }
        
        currentHealth -= attacks[i][1];
        healCount = 0;
        if(currentHealth <= 0) return -1;
        time++;
    }
    
    answer = currentHealth;
    return answer;
}