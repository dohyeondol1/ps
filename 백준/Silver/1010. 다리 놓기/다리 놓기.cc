#include <iostream>

int main(){
    int t = 0;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        long ans = 1;
        int n = 0;
        int m = 0;
        
        std::cin >> n >> m;
        
        int r = 1;
        for(int j = m; j > m-n; j--){
            ans = ans * j;
            ans = ans / r;
            r++;
        }
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}
