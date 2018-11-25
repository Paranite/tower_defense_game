// TwGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
//#include <iostream>
#include "Library.h"

int main()
{
	lib::clearscreen(15);	//istrina spalva ir nuspalvina ekrana i nurodyta spalva
	lib::remove_scrollbar(); //nuima is console scroll bar	
	lib::setFontSize(10, 20);	//fonto dydis
	//lib::goFullscreen();	//fullscreen
	//lib::printText(30, 20, "nibba", 2+16*4); //x,y,string,color
	//COORD a = lib::getMousePosition();	//get mouse position
	lib::setConsoleResolution(1280, 720); // set resolution
//	lib::setCursorPosition(a.X,a.Y);
	lib::setCursorVisibility(false);


	/*----------------------------------
	-------------------------------------
	-----SKIRTINGI BUDAI KAIP GALIMA SUKURTI LANGA, TABLE AR MENIU*/

	langas a;	//paprastas langas,   x,y,width,height,color,bordertype
/*	a.x = 20;
	a.y = 20;
	a.width = 10;
	a.height = 10;
	a.color = 15;
	a.borderType = 2;
	a.create();
	//a.remove();
	a.set(10, 12, 10, 10, 18, 2);	//arba galima sukurti su set*/





	//c.set(60, 20, 20, 2, 1 + 16 * 15, 3, 1);//x,y,width,height,color,rows,bordertype

	//lib::goFullscreen();	//fullscreen


	/*clickableObject A[100];
	A[0].funkcija = bind(&lib::printText,50,10,"cat",15);	//kad ivesti parametra reikia bind
	A[0].funkcija();
	cin.get();*/

	lib::fileTypeInFolder("C:/", "bmp");
	//cout << a[0];

	menu b;	//menu,   x,y,width,height,color,rows,text,bordertype, object
	b.text[0] = "langas";
	b.text[1] = "langas remove";
	b.text[2] = "fullscreen";
	b.text[3] = "resolution 1280x720";
	b.text[4] = "resolution 800x600";

	table c;	//table,   x,y,width,height,color,rows,text,bordertype
	c.x = 60;
	c.y = 1;
	c.width = 20;
	c.height = 2;
	c.color = 1 + 16 * 15;
	c.rows = 3;
	c.borderType = 1;
	c.text[0] = "start";
	c.text[1] = "quit game";
	c.text[2] = "options";
	c.create();

	b.set(0, 1, 20, 2, 15, 5, 2);	//arba su set
	b.object[0].funkcija = bind(&langas::set, a, 30, 1, 10, 10, 18, 2);	//objecktui priskiriama funkcija print text
	b.object[1].funkcija = bind(&langas::remove, a);
	b.object[2].funkcija = bind(&lib::goFullscreen);
	b.object[3].funkcija = bind(&lib::setConsoleResolution, 1280, 720);
	b.object[4].funkcija = bind(&lib::setConsoleResolution, 800, 600);
	while (1) {

		if (lib::mouseEvent()) {
			//	lib::cursorDraw();
			b.check();
		}
	}
	return 0;
}
