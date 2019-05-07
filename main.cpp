#include<bits/stdc++.h>
#include "func.h"
#include "lz77.h"
#include "lz78.h"
#include "lzw1.h"
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
//string LZ77(string input, int option);
//string LZ78(string input, int option);
//string LZW(string input, int option);

int main()
{
    system("Color 0A");
	string input, result, method_text,line;
	ofstream file, file1;
	ifstream fin, fin1;
    file.open ("codebind.txt");
    fin.open("sample.txt");
	int method, option, option2;

	string intro = R"(
	Hi I'm Alpha  ^_^ , Algo Buddies assistant, I'm here to help you.
)";
	cout << intro;
main_menu:
	string main_menu = R"(
-------------------------------------------------------------------------------
 This tool generate compression and decompression using LZ-77, LZ-78 and LZW methods :

   1- LZ-77
   2- LZ-78
   3- LZW
   4- Exit
 Enter 1, 2 or 3 according to method.
  > )";
  	cout << main_menu;

	cin >> method;

	if (method == 1)
		method_text = "LZ-77";
	else if (method == 2)
		method_text = "LZ-78";
	else if (method == 3)
		method_text = "LZW";
    else if (method == 4)
        exit(0);
	else
	{
		printf("\033c");
		cout << intro;
		goto main_menu;
	}

method_menu:
	printf("\033c");
	cout << intro;

	string main_menu_2 = R"(
-------------------------------------------------------------------------------
 This tool generate compression and decompression using )" + method_text + R"( method :

   1- Compression
   2- Decompression

   0- Main menu

 Enter 1, 2 or 0 according to method.
  > )";
  	cout << main_menu_2;
	cin >> option;

	if (option == 1)
	{
		printf("\033c");
		cout << intro;

		string lz77_Compression = R"(
-------------------------------------------------------------------------------
 )" + method_text + R"( >  Compression :)";
		cout << lz77_Compression << endl;

		cout << "\t Enter your phrases : ";
		cin.ignore();
        while (fin) {

        getline(fin, line);
        input+=line;
        cout << line << endl;
    }
        //getline(cin, input);
		if (method == 1)
			result = LZ77(input, 1);
		else if (method == 2)
			result = LZ78(input, 1);
		else if (method == 3)
			result = LZW(input, 1);
		else
		{
			printf("\033c");
			cout << intro;
			goto main_menu;
		}

		cout << "\n\t Final result : " << result << endl;
		//cout << "\n\t Final result : " << result << endl;
        file << result;
        fin.close();
        file.close();

	back_1:
		cout << "\n Enter 0 to back to Main menu or 1 to back to Method menu. \n  > ";
		cin >> option2;

		if (option2 == 0)
		{
			printf("\033c");
			cout << intro;
			goto main_menu;
		}
		else if (option2 == 1)
			goto method_menu;
		else
			goto back_1;
	}
	else if (option == 2)
	{
		printf("\033c");
		cout << intro;

		string lz77_Compression = R"(
-------------------------------------------------------------------------------
 LZ-77 >  Decompression :)";
		cout << lz77_Compression << endl;
		cout << "Note : Enter 0 for NULL characters\n\n";
		cout << "\t Enter your code : ";
		fin1.open("codebind.txt");
		file1.open("sample.txt");
		cin.ignore();
		line="";
		input="";
		 while (fin1) {

        getline(fin1, line);
        input+=line;
        cout << line << endl;
    }
		//getline(cin, input);
		if (method == 1)
			result = LZ77(input, 2);
		else if (method == 2)
			result = LZ78(input, 2);
		else if (method == 3)
			result = LZW(input, 2);
		else
			main_menu;
        cout << "\n\t Final result : " << result << endl;
		//cout << "\n\t Final result : " << result << endl;
        file1 << result;
	back_2:
		cout << "\n Enter 0 to back to Main menu or 1 to back to Method menu. \n  > ";
		cin >> option2;

		if (option2 == 0)
		{
			printf("\033c");
			cout << intro;
			goto main_menu;
		}
		else if (option2 == 1)
			goto method_menu;
		else
			goto back_2;

	}
	else if (option == 0)
	{
		printf("\033c");
		cout << intro;
		goto main_menu;
	}
	else
		goto method_menu;


	cin.get();
	cin.ignore();
	file1.close();
	fin1.close();
	return 0;
}
