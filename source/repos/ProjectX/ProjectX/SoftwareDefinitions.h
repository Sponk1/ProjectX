#pragma once

#define OnMenuClicked		1
#define OnButtonClicked		2
#define OnMenuClicked2		3
#define	OnMenuAction		4
#define OnReadField			5
#define OnSaveFile			7
#define	OnSaveFile			8

#define DlgIndexNumber		104


#define TextBufferSize		1000

char Buffer[TextBufferSize];
int ReadChars;
unsigned num;
unsigned str;

HWND hStaticControl;
HWND hEditControl;
HWND hNumberControl;
HWND hSymbolControl;

//вызов функций тк заданы после WinMain
LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

//Меню(плашки сверху)
void MainWndAddMenus(HWND hWnd);
void MainWndAddNotes(HWND hWnd);
void SaveData(LPCSTR path);
