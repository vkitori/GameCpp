#include <windows.h>

bool running = true;

LRESULT CALLBACK WindowCallback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	LRESULT result = 0;
	switch (uMsg)
		{
		case WM_CLOSE:
		case WM_DESTROY: {
			running = false;
		} break;

		default:
			result = DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
		return result;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

	WNDCLASS windowClass = {};
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WindowCallback;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = "Game Window lass";


	RegisterClass(&windowClass);

	CreateWindow(
		windowClass.lpszClassName,
		"Cpp Game",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT,
		1280, 720,
		0, 0,
		hInstance,
		0);

	while (running) {

	}
}

