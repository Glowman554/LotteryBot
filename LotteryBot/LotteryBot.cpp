#include <core.h>
#include <tclap/CmdLine.h>

int maxTickets;
int klickPerSeconds;

int main(int argc, char** argv) {
    TCLAP::CmdLine cmd("LotteryBot", ' ', "0.1", true);
    TCLAP::ValueArg<int> maxTicketsArg("m", "maxTickets", "maxTickets", false, 10, "int");
    TCLAP::ValueArg<int> klickPerSecondsArg("k", "klickPerSeconds", "klickPerSeconds", false, 20, "int");
    cmd.add(maxTicketsArg);
    cmd.add(klickPerSecondsArg);
    cmd.parse(argc, argv);


    maxTickets = maxTicketsArg.getValue();
    klickPerSeconds = klickPerSecondsArg.getValue();

    HWND hWnd = FindWindowW(nullptr, MINECRAFT_VER);
    if (hWnd) {
        SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE);

        MoveWindow(hWnd, 0, 0, WINDOW_X, WINDOW_Y, true);

        Sleep(100);
        std::thread bot_thread([] { return StartBot(maxTickets, klickPerSeconds); });
        std::thread shutdown_thread([] { return ShutdownHook(); });

        bot_thread.join();
        shutdown_thread.join();

        return 0;
    }
    std::cout << "Window not found!" << std::endl;
    Sleep(5000);
    return -1;
}