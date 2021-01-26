# CMakeList.txt: CMake-Projekt für "LotteryBot". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)

include_directories("include")

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (LotteryBot "LotteryBot.cpp"  "include/core.h" "core.cpp" "include/config.h"    "include/langsys/english.h" "include/langsys/german.h")

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
