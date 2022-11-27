#include <Windows.h>
#include "SoftwareDefinitions.h"
#include "resource.h"
#include <string>

// Вроде просто APIка...
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)), L"MainWndClass", SoftwareMainProcedure);

	//регистрация класса
	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	//пустое сообщение ?
	MSG SoftwareMainMessage = { 0 };

	//Создание окна, ура ?
	CreateWindow(L"MainWndClass", L"*Project X*", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 505, 600, NULL, NULL, NULL, NULL);
	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}
	return 0;
}

//Классы
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure)
{
	WNDCLASS NWC = { 0 };

	NWC.hIcon = Icon;
	NWC.hCursor = Cursor;
	NWC.hInstance = hInst;
	NWC.lpszClassName = Name;
	NWC.hbrBackground = BGColor;
	NWC.lpfnWndProc = Procedure;

	return NWC;
}

//Процедура
LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	//обРаБотКа пРоцеДуРЫ
	switch (msg){
	case WM_COMMAND:
		switch (wp) {
			//menu
		case OnButtonClicked:			//отчистка текста
			SetWindowTextA(hEditControl, "");
			break;

		case OnMenuClicked:				//прикол
			MessageBoxA(hWnd, "Да?", "Зачет ?", MB_OK);
			break;

		case OnReadField:				//копировние/счет символов
			//GetWindowTextA(hEditControl, Buffer, TextBufferSize);
			//num = GetDlgItemInt(hWnd, DlgIndexNumber, FALSE, false);
			//SetWindowTextA(hStaticControl, std::to_string(num).c_str());
			ReadChars = GetWindowTextA(hEditControl, Buffer, TextBufferSize);
			SetWindowTextA(hStaticControl, Buffer);
			SetWindowTextA(hStaticControl, (" " + std::to_string(ReadChars)).c_str());
			break;

		case OnSaveFile:				//сохранялка в файл
			SaveData("\\C:\\output.txt");

			break;
		default: break;
		}
		break;

	case WM_CREATE:
		MainWndAddMenus(hWnd); 
		MainWndAddNotes(hWnd);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default: return DefWindowProc(hWnd, msg, wp, lp);
	}
}

//Меню
void MainWndAddMenus(HWND hWnd)
{
	HMENU RootMenu = CreateMenu();
	HMENU SubMenu = CreateMenu();
	
	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenu, L"File");
	AppendMenu(RootMenu, MF_STRING, OnMenuClicked, L"Click here");
	AppendMenu(SubMenu, MF_STRING,OnMenuClicked,L"save");
	
	SetMenu(hWnd, RootMenu);
}

//заметки
void MainWndAddNotes(HWND hWnd) {

	CreateWindowA("static", "Your notes", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 490, 20, hWnd, NULL, NULL, NULL);

	hStaticControl =  CreateWindowA("static", " Write down your note: ", WS_VISIBLE | WS_CHILD, 5, 30, 490, 20, hWnd, NULL, NULL, NULL);
	hEditControl = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL, 0, 45, 505, 600, hWnd, (HMENU)DlgIndexNumber, NULL, NULL);

	CreateWindowA("button", "Clear", WS_VISIBLE | WS_CHILD | ES_CENTER, 400, 15, 70, 25, hWnd, (HMENU)OnButtonClicked, NULL, NULL);

	CreateWindowA("button", "Copy", WS_VISIBLE | WS_CHILD | ES_CENTER, 325, 15, 70, 25, hWnd, (HMENU)OnReadField, NULL, NULL);

	hSymbolControl = CreateWindowA("static", "Symbols: ", WS_VISIBLE | WS_CHILD | ES_CENTER, 1, 10, 82, 20, hWnd, NULL, NULL, NULL);


}

//сохранялка
void SaveData(LPCSTR path) {
	HANDLE FileToSave = CreateFileA(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	int saveLenth = GetWindowTextLength(hEditControl);
	char* data = new char[saveLenth];
	saveLenth = GetWindowTextA(hEditControl, data, saveLenth);
	
	DWORD bytesIteraded;
	WriteFile(FileToSave, data, saveLenth, &bytesIteraded, NULL);

	CloseHandle(FileToSave);
	delete[] data;


}