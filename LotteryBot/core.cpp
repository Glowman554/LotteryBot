#include <core.h>

void StartBot(int maxTickets, int klickPerSeconds) {
    int claim = 0;
    int totalTickets = 0;

    while (true) {
        Sleep(50);
        for (int i = 1; i <= maxTickets; i++) {
            SetCursorPos(NEWTICKET_X, NEWTICKET_Y);
            Sleep(1000 / klickPerSeconds);
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
            totalTickets++;
            std::cout << "Round: " << claim << ", Total Tickets: " << totalTickets << ", Ticket: " << i << "\r";

        }
        Sleep(50);
        SetCursorPos(OPEN_ALL_X, OPEN_ALL_Y);
        Sleep(100);
        mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
        Sleep(100);
        mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
        Sleep(100);
        claim++;
        std::cout << std::endl;
    }
}

void ShutdownHook() {
    while (true) {
        if (GetAsyncKeyState(VK_ESCAPE) != 0) {
            exit(0);
        }
    }
}