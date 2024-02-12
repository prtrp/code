#include <stdio.h>
#include <time.h>
#include <ncurses.h>

int main() {
    initscr(); // Inizializza lo schermo
    clear();   // Pulisce lo schermo
    noecho();  // Disabilita l'eco dell'input

    int seconds = 1800;
    int *ptr = &seconds;

    int pomodori = 1;
    int *pdr = &pomodori;

    int free = 0;
    int *fpr = &free;

    int long_ress = 0;
    int *lrpt = &long_ress;

    while (1) {
        int h = seconds / 3600; 
        int m = (seconds % 3600) / 60;
        int s = seconds % 60;
            
        *fpr = (*ptr >= 300) ? 0 : 1;

        if((*pdr % 4) == 0)
          *lrpt = 1;
        else
          *lrpt = 0;

        mvprintw(0, 0, "%02d:%02d:%02d  -[%d] count \n\t  -[%d] ress\n"
         "\t  -[%d] ress long\n\t", h, m, s, *pdr, *fpr, *lrpt); 

        refresh(); // Aggiorna lo schermo

        clock_t stop = clock() + CLOCKS_PER_SEC;
        while (clock() < stop) {}


        seconds--;
        
        if (seconds == 0)
        {
          *ptr = 1800;
          *pdr +=1;

        }
    }
    

    endwin(); // Chiude la finestra ncurses
    return 0;
}

