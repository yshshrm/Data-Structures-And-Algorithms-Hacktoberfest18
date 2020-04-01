#include <stdio.h>

int main() {
    char s[100];
    char p;
    int shift = 0;
    
    printf("Enter plaintext: ");
    gets(s);
    printf("Enter shift position: ");
    scanf("%d", &shift);
    
    shift = shift % 26;
    
    for(int i = 0; s[i] != '\0'; ++i){
        p = s[i];
        
        if(p >= 'a' && p <= 'z'){
            p = p + shift;
            
            if(p > 'z'){
                p = p - 'z' + 'a' - 1;
            }
            p = (p + shift) % 26;
            s[i] = p;
        }
        else if(p >= 'A' && p <= 'Z'){
            p = p + shift;
            
            if(p > 'Z'){
                p = p - 'Z' + 'A' - 1;
            }
            
            s[i] = p;
        }
    }
    
    printf("Ciphertext: %s", s);
}
