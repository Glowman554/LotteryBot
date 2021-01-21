#pragma once

#include <iostream>
#include <Windows.h>
#include <thread>

#include <config.h>

void StartBot(int maxTickets, int klickPerSeconds);
void ShutdownHook();
