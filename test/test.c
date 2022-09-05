#include <locale.h>
#include <curses.h>
#include <stdlib.h>


int
main (int argc, char *argv[])
{
  setlocale(LC_ALL, "");

  initscr();

  printw("Euro\n");

  printw("€\n");              // literal Unicode
  printw("\u20ac\n");         // escaped Unicode (C99)

  printw("%lc\n", L'€');      // wint_t
  printw("%ls\n", L"€");      // wchar_t
  addwstr(L"\u20AC\n");       // wchar_t

  printw("\xe2\x82\xac\n");   // utf-8 encoded
  addstr("\xe2\x82\xac\n");   // utf-8 encoded

  for (int i = 0; i < 10; i++)
  {
    printw("%c %lc\n", '0' + i, L'０' + i);
  }

  getch();
  endwin();

  return EXIT_SUCCESS;
}
