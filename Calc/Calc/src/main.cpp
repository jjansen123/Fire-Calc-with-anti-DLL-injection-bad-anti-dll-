#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <windows.h>
#include <psapi.h>
#include <tchar.h>
#include <vector>
#include <string>

const std::vector<std::wstring> suspiciousDLLs = {
    L"injected.dll"
};

bool CheckForSuspiciousModules() {
    HMODULE hMods[1024];
    HANDLE hProcess = GetCurrentProcess();
    DWORD cbNeeded;

    if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded)) {
        for (unsigned int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
            TCHAR szModName[MAX_PATH];
            if (GetModuleFileNameEx(hProcess, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR))) {
                std::wstring fullPath = szModName;
                std::wstring fileName = fullPath.substr(fullPath.find_last_of(L"\\") + 1);

                for (const auto& dll : suspiciousDLLs) {
                    if (_wcsicmp(fileName.c_str(), dll.c_str()) == 0) {
                        std::wcout << L"? Unknown dll found: " << fileName << std::endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void StartAntiInjectionMonitor() {
    std::thread([] {
        while (true) {
            if (CheckForSuspiciousModules()) {
                std::cout << "\nWhy are you injecting dll's NIGGER\n";
                std::this_thread::sleep_for(std::chrono::seconds(10));
                exit(0);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        }).detach();
}

int main() {
    StartAntiInjectionMonitor();

    int optioncalc;

    std::cout << "Welcome to Calc! \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "What option would you like to perform? (1: +, 2: -, 3: x, 4: /) \n";
    std::cout << "> ";
    std::cin >> optioncalc;

    if (optioncalc == 1) {
        int nr1plus, nr2plus;
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
        system("cls");
        std::cout << "You chose: '+'. \n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("cls");
        std::cout << "Number 1: \n> ";
        std::cin >> nr1plus;
        std::cout << "Number 2: \n> ";
        std::cin >> nr2plus;
        int resultplus = nr1plus + nr2plus;
        system("cls");
        std::cout << "The answer of " << nr1plus << " + " << nr2plus << " is: " << resultplus;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        return 0;
    }
    else if (optioncalc == 2) {
        int nr1min, nr2min;
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
        system("cls");
        std::cout << "You chose: '-'. \n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("cls");
        std::cout << "Number 1: \n> ";
        std::cin >> nr1min;
        std::cout << "Number 2: \n> ";
        std::cin >> nr2min;
        int resultmin = nr1min - nr2min;
        system("cls");
        std::cout << "The answer of " << nr1min << " - " << nr2min << " is: " << resultmin;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        return 0;
    }
    else if (optioncalc == 3) {
        int nr1multi, nr2multi;
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
        system("cls");
        std::cout << "You chose: 'x'. \n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("cls");
        std::cout << "Number 1: \n> ";
        std::cin >> nr1multi;
        std::cout << "Number 2: \n> ";
        std::cin >> nr2multi;
        int resultmulti = nr1multi * nr2multi;
        system("cls");
        std::cout << "The answer of " << nr1multi << " x " << nr2multi << " is: " << resultmulti;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        return 0;
    }
    else if (optioncalc == 4) {
        int nr1div, nr2div;
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
        system("cls");
        std::cout << "You chose: '/'. \n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("cls");
        std::cout << "Number 1: \n> ";
        std::cin >> nr1div;
        std::cout << "Number 2: \n> ";
        std::cin >> nr2div;
        if (nr2div == 0) {
            std::cout << "Cannot divide by 0!\n";
        }
        else {
            int resultdiv = nr1div / nr2div;
            system("cls");
            std::cout << "The answer of " << nr1div << " / " << nr2div << " is: " << resultdiv;
            std::this_thread::sleep_for(std::chrono::seconds(10));
            return 0;
        }
    }
    else {
        std::cout << "This is not a valid option.";
        return 0;
    }
}
