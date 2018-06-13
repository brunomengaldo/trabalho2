#include <stdio.h>
#include <windows.h>   // WinApi header

int main(){
    
    HANDLE  hConsole;
    
    int i;
    
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // you can loop i higher to see more color choices
    for(i = 1; i < 255; i++){
      SetConsoleTextAttribute(hConsole, i);
      printf("%d  %s\n", i, "I want to be nice today!");
    }

    SetConsoleTextAttribute(hConsole, 7);
    printf("test\n");

    getchar();  // wait
    return 0;
}