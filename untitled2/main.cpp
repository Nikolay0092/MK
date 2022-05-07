#include <stdio.h>
#include "windows.h"

VOID ErrorExit(LPCSTR);

int main(VOID) {
    HANDLE hStdin;
    const short bufferSize = 128;
    INPUT_RECORD irInBuf[bufferSize];

    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hStdin == INVALID_HANDLE_VALUE) {
        ErrorExit("GetStdHandle");
    }

    int index = 0;
    int eventsCount = 0;
    int x = 10;
    int y = 10;

    while (index < 10000000) {
        DWORD cNumRead = 0;
        BOOL peekSuccessful = PeekConsoleInput(
                hStdin,
                irInBuf,
                bufferSize,
                &cNumRead
                );

        if (!peekSuccessful) {
            ErrorExit("PeekConsoleInput");
        }
        if (!FlushConsoleInputBuffer(hStdin)) {
            ErrorExit("FlushConsoleInputBuffer");
        }

        eventsCount += cNumRead;
        printf("iteration %d total %d current %d\n", index, eventsCount, cNumRead);

        for (DWORD i = 0; i < cNumRead; i++) {
            if (irInBuf[i].EventType == KEY_EVENT) {
                KEY_EVENT_RECORD ker = irInBuf[i].Event.KeyEvent;
                if (ker.bKeyDown) {
                    if (ker.wVirtualKeyCode == 38) {
                        y--;
                    }
                    else if (ker.wVirtualKeyCode == 40) {
                        y++;
                    }
                    else if (ker.wVirtualKeyCode == 39) {
                        x++;
                    }
                    else if (ker.wVirtualKeyCode == 37) {
                        x--;
                    }
                    printf("key %d pressed\n", ker.wVirtualKeyCode);
                } else {
                    printf("key released\n");
                }
            }
        }
        index++;
    }
    return 0;
}

VOID ErrorExit(LPCSTR lpszMessage) {
    fprintf(stderr, "%s\n", lpszMessage);
    ExitProcess(0);
}