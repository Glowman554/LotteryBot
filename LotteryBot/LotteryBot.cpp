#include <iostream>
#include <windows.h>
#include <thread>

using namespace std;

int claim = 1;
int maxTickets = 0;
int totalTickets = 0;
int klickPerSeconds = 1;

void StartBot() {
    Sleep(50);
    for (int i = 1; i <= maxTickets; i++) {
        SetCursorPos(375, 275);
        Sleep(1000 / klickPerSeconds);
        mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
        totalTickets++;
        cout << "Round: " << claim << ", Total Tickets: " << totalTickets << ", Ticket: " << i << endl;

    }
    Sleep(50);
    SetCursorPos(500, 275);
    Sleep(100);
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
    Sleep(100);
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
    Sleep(100);
    claim++;
    StartBot();
}

void ShutdownHook() {
    while (true) {
        if (GetAsyncKeyState(VK_RCONTROL) != 0) {
            exit(0);
        }
    }
}

int main() {
    HWND hWnd = FindWindowW(nullptr, L"Minecraft 1.16.4 - Multiplayer (3rd-party Server)");
    if (hWnd) {
        cout << "Maximal Tickets pro Runde >>>";
        cin >> maxTickets;
        cout << "Klicks in Sekunde >>>";
        cin >> klickPerSeconds;
        SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE);

        MoveWindow(hWnd, 0, 0, 745, 520, true);

        Sleep(100);
        std::thread bot_thread([] { return StartBot(); });
        std::thread shutdown_thread([] { return ShutdownHook(); });

        bot_thread.join();
        shutdown_thread.join();

        return 0;
    }
    cout << "Window not found!" << endl;
    Sleep(5000);
    return -1;
}