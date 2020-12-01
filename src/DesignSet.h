/**
 * File Name: DesignSet.h
 *
 * Description:
 * �������� ���� ���� ���� �� �Լ� ����
 **/
#include <Windows.h>
#include <string>

enum color {
	black, blue, green, skyblue, red,
	purple, yellow, white, grey, lightBlue,
	lightGreen, lightSkyblue, lightRed,
	lightPurple, lightYellow, darkWhite
};

// Adornment
void changeColor(int);
void printLogo();
void printContent(std::string);
void printAccontMenu(int);
void printSuspension(int);

// system("cls");