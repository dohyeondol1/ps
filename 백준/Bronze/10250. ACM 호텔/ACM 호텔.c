#include <stdio.h>

int main()
{
    int T, H, W, N;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %d %d", &H, &W, &N);
        int num = N/H+1;
        int flr = N%H;
        if(flr == 0){
            flr = H;
            num -= 1;
        }
        int room = (flr*100)+num;
        
        printf("%d \n", room);
    }
    
    return 0;
}
