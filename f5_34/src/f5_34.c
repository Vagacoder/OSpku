/*
 ============================================================================
 Name        : f5_34.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : textbook P.404 Figure 5-34 A skeleton of an X Window application

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>


int main(void) {

	Display disp;			// server id
	Window win;				// window id
	GC gc;					// graphic context id
	XEvent event;			// graphic context identifier
	int running =1;			// storage for one event

	int vbuffer[];

	disp = XOpenDisplay("display_name");		// connect to the X server
	win = XCreateSimpleWindow(disp, &vbuffer);	// allocate memory for new window
	XsetStandarProperties(disp);				// announces window to window mgr
	gc = XCreateGC(disp, win, 0, 0);			// create graphic context
	XSelectInput(disp, win, ButtonPressMask | KeyPressMask | ExposureMask);
	XMapRaised(disp, win);						// display window; send Expose event

	while(running){
		XNextEvent(disp, &event);
		switch(event.type){
		case Expose: break;			// repaint window
		case ButtonPress: break;	// process mouse click
		case Keypress: break;		// process keyboard input
		}
	}

	XFreeGC(disp, gc);				// relase graphic context
	XDestroyWindow(disp, win);		// deallocate window's memory space
	XCloseDisplay(disp);			// tear down network connection



	return EXIT_SUCCESS;
}
