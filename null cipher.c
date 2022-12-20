#include <stdio.h>
#include <string.h>
  
int main()
{
    char str[] = "President's embargo ruling should have immediate notice. Grave situation affecting international law, statement foreshadows ruin of many neutrals. Yellow journals unifying national excitement immensely";
    
    // This will give first word of String.
    char* ptr = strtok(str, " ");
    
    while (ptr != NULL) {
        
        // This will print first character of word.
        printf("%c ", ptr[0]);
        
        // To get next word.
        ptr = strtok(NULL, " ");
    }
}