/* A minimal Windows 98 skeleton. */

#include <windows.h>

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);

const WCHAR szWinName[] = L"MyWin"; // name of window class

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wcl;

	// Define a window class.
	wcl.cbSize = sizeof(WNDCLASSEX);
	
	wcl.hInstance = hThisInst; // handle to this instance
	wcl.lpszClassName = szWinName; // window class name
	wcl.lpfnWndProc = WindowFunc; // window function
	wcl.style = 0; // default style

	wcl.hIcon = LoadIcon(nullptr, IDI_APPLICATION); // standard icon
	wcl.hIconSm = LoadIcon(nullptr, IDI_WINLOGO); // small icon
	wcl.hCursor = LoadCursor(nullptr, IDC_ARROW); // cursor style

	wcl.lpszMenuName = nullptr; // no menu
	wcl.cbClsExtra = 0; // no extra information needed
	wcl.cbWndExtra = 0; // no extra information needed

	// Make the window background white.
	wcl.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));

	// Register the window class.
	if (!RegisterClassEx(&wcl)) {
		return 0;
	}

	// Now that a window class has been registered, a window can be created.
	hwnd = CreateWindow(
		szWinName, // name of window class
		L"Windows 98 Skeleton", // title
		WS_OVERLAPPEDWINDOW, // window style - normal
		CW_USEDEFAULT, // X coordinate - let Windows decide
		CW_USEDEFAULT, // Y coordinate - let Windows decide
		CW_USEDEFAULT, // width - let Windows decide
		CW_USEDEFAULT, // height - let Windows decide
		HWND_DESKTOP, // no parent window
		nullptr, // no menu
		hThisInst, // handle of this instance of the process
		nullptr // no additional arguments
	);

	// Display the window.
	ShowWindow(hwnd, nWinMode);
	UpdateWindow(hwnd);

	// Create the message loop.
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg); // translate keyboard messages
		DispatchMessage(&msg); // return control to Windows 98
	}
	return msg.wParam;
}

// This function is called by Windows 98 and is passed messages from the message queue.
LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY: // terminate the program
		PostQuitMessage(0);
		break;
	default:
		// Let Windows 98 process any messages not specified in the preceding switch statement.
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}
