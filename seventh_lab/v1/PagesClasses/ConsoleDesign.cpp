#include "ConsoleDesign.h"

void SetColor(const int &text, const int &background)
    {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, (WORD)((background << 4) | text));
    }
    void SetDefaultConsole()
    {
        system("cls");
        system("color 0F");
    }
    void SetDefaultColor()
    {
        system("color 0F");
    }
    void SetSize()
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получить консоль
        CONSOLE_FONT_INFOEX fontInfo;
        GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Получить текущий шрифт
        fontInfo.dwFontSize.X = 10; // Размер (в логических единицах)
        SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Установить новый
    }
    void SetCursor(const int &x, const int &y)
    {
        COORD position;										// Объявление необходимой структуры
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	// Получение дескриптора устройства стандартного вывода
        position.X = x;									// Установка координаты X
        position.Y = y;									// Установка координаты Y
        SetConsoleCursorPosition(hConsole, position);		// Перемещение каретки по заданным координатам
    }
    void SetTextSize(const int &size)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получить консоль
        CONSOLE_FONT_INFOEX fontInfo;
        GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Получить текущий шрифт
        // Поменять какие-то параметры
        fontInfo.dwFontSize.X = size; // Размер (в логических единицах)
        SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Установить новый
    }
    void HideCursor()
    {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
    }