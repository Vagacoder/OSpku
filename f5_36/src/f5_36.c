/*
 ============================================================================
 Name        : f5_36.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Textbook Figure 5-36, P.408 A skeleton of Windows main program
 ============================================================================
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

// WINAPI
int WinMain(HINSTANCE h, HINSTANCE, hprev, char* szCmd, int iCmdShow){
	WNDCLASS wndclass;				// class object this window
	MSG msg;						// incoming messages are stored here
	HWND hwnd;						// handle to the window object

	// Initialize wndclass
	wndclass.lpfnWndProc = WndProc;		// tell which procedure to call
	wndclass.lpszClassName = "Program name";	// text for title bar
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// load program icon
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);		// load mouse cursor

	RegisterClass(&wndclass);			// tell windows about wndclass
	hwnd = CreateWindow();				// allocate storage for the window
	ShowWindow(hwnd, iCmdShow);			// display the window on the screen
	UpdateWindow(hwnd);					// tell the window to paint itself

	while(GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);			// translate the message
		DispatchMessage(&msg);			// send msg to the appropriate procedure
	}
	return (msg.wParam);
}

// CALLBACK
long WndProc(HWND hwnd, UINT message, UINT wParam, long lParam){
	// Declarations go here

	switch(message){
	case WM_CREATE:	return;				// create window
	case WM_PAINT:	return;				// repaint contents of window
	case WM_DESTROY:	return;			// destroy window
	}
	return(DefWindowProc(hwnd, message, wParam, lParam)); // default
}




int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
