#include <stdio.h>

int main()
{
    int T;
    char str[51];

    scanf("%d", &T);

    while (T--)
    {
        int count = 0;
        scanf("%s", str);

        for (int j = 0; str[j]; j++)
        {
            count += (str[j] == '(') ? 1 : -1;
            if (count < 0) break; 
        }

        printf(count == 0 ? "YES\n" : "NO\n");
    }

    return 0;
}
