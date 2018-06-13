
#include <stdio.h> 
#include <windows.h> 
#include <string.h>


void trocaCor(char *p);



int main ( void ){
HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  WORD wOldColorAttrs;
  
  char a[1000]="oi ";
  trocaCor(&a);
  printf("%s\n", a);
  SetConsoleTextAttribute ( h, wOldColorAttrs);
  printf("Hahah");

  return 0;

}




void trocaCor(char *p){

  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  WORD wOldColorAttrs;
  CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
  

  /*
   * First save the current color information
   */
  GetConsoleScreenBufferInfo(h, &csbiInfo);
  wOldColorAttrs = csbiInfo.wAttributes; 
  
  /*
   * Set the new color information
   */
  SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
  
  strcat(p, "tudo ");

  SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

  strcat(p, "muito ");


  SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY);
  strcat(p, "bem?");

  /*
   * Restore the original colors
   */
  return;
}
