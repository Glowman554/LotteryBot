#include <core.h>

using namespace std;


int main() {
    HWND hWnd = FindWindowW(nullptr, MINECRAFT_VER);
    if (hWnd) {
        SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE);

        MoveWindow(hWnd, 0, 0, WINDOW_X, WINDOW_Y, true);

        Sleep(100);
        std::thread bot_thread([] { return StartBot(10, 20); });
        std::thread shutdown_thread([] { return ShutdownHook(); });

        bot_thread.join();
        shutdown_thread.join();

        return 0;
    }
    cout << "Window not found!" << endl;
    Sleep(5000);
    return -1;
}