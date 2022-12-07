#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100100];
char key[100100];
char solution[100100];
long long int str_length, key_length;
void encryption(long long int s, long long int k)
{ // s:str_length k:key_length
    for (int i = 0; i < s; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (key[i % k] >= 'A' && key[i % k] <= 'Z')
            {
                solution[i] = (str[i] - 'a' + (key[i % k] + 32) - 'a') % 26 + 'a'; //轉換大->小(+32)
                // solution[i]=(str[i]-'a'+tolower(key[i%k])-'a')%26+'a'; //函式tolower轉換
            }
            else
            {
                solution[i] = (str[i] - 'a' + key[i % k] - 'a') % 26 + 'a';
            }
        }
        else
        {
            if (key[i % k] >= 'a' && key[i % k] <= 'z')
            {
                solution[i] = (str[i] - 'A' + (key[i % k] - 32) - 'A') % 26 + 'A'; //轉換小->大(-32)
                // solution[i]=(str[i]-'A'+ toupper(key[i%k])-'A')%26+'A'; //函式toupper轉換
            }
            else
            {
                solution[i] = (str[i] - 'A' + key[i % k] - 'A') % 26 + 'A';
            }
        }
    }
}
int main()
{
    scanf("%s", str);
    scanf("%s", key);
    str_length = strlen(str);
    key_length = strlen(key);
    encryption(str_length, key_length);
    printf("%s\n", solution);
    return 0;
}