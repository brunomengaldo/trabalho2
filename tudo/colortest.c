
#include <stdio.h> 
#include <windows.h> 

int main ( void )
{
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
  
  printf ( "teste1" );

  SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

  printf ( "teste2" );


  SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY);
  printf ( "teste3" );

  /*
   * Restore the original colors
   */
  SetConsoleTextAttribute ( h, wOldColorAttrs);
  return 0;
}
