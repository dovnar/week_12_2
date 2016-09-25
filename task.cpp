#include <iostream>
#include <locale.h>

using namespace std;

int scanArray(int arr[3][3], int i);
void printArray(int arr[3][3]);
// Название функции не отражает того, что она делает
void test(int arr[3][3], int i);

// Не понятно о чем вообще программа
int main()
{
	setlocale(LC_ALL, "rus");
	int arr[3][3]{ {0,0,0}, {0,0,0} };
	for (int i = 0; i < 9; i++)
	{
		printArray(arr);
		test(arr, i-1);
		arr[3][3] = scanArray(arr, i);
		
	}
	printArray(arr);
}
void printArray(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (arr[i][j])
			{
			case 0: cout << "   ";
				break;
			case 1: cout << " X ";
				break;
			case 2: cout << " O ";
				break;
			default:
				break;
			}
			if (i == 0 &&
				j == 2 || 
				i == 1 &&
				j == 2)
			{
				cout << endl << "___________" << endl;
			}
			else if (i == 2 &&
				j == 2)
			{
				cout << endl;
			}
			else
			{
				cout << "|";
			}
		}
	}
}
void test(int arr[3][3], int i)
{
	if (arr[0][0] == arr[0][1] &&
		arr[0][0] == arr[0][2] &&
		arr[0][0] != 0 ||
		arr[1][0] == arr[1][1] &&
		arr[1][0] == arr[1][2] &&
		arr[1][0] != 0 ||
		arr[2][0] == arr[2][1] &&
		arr[2][0] == arr[2][2] &&
		arr[2][0] != 0 ||
		arr[0][0] == arr[1][0] &&
		arr[0][0] == arr[2][0] &&
		arr[0][0] != 0 ||
		arr[0][1] == arr[1][1] &&
		arr[0][1] == arr[2][1] &&
		arr[0][1] != 0 ||
		arr[0][2] == arr[1][2] &&
		arr[0][2] == arr[2][2] &&
		arr[0][2] != 0 ||
		arr[0][0] == arr[1][1] &&
		arr[0][0] == arr[2][2] &&
		arr[0][0] != 0 ||
		arr[0][2] == arr[1][1] &&
		arr[0][2] == arr[2][0] &&
		arr[0][2] != 0)
	{
		if (i % 2 == 0)
		{
			cout << "game won user X" << endl;
			exit(1);
		}
		else if(i % 2 == 1)
		{
			cout << "game won user O" << endl;
			exit(1);
		}
	}
}
int scanArray(int arr[3][3], int i)
{
	int n, m, to;
	do
	{
		cout << "enter diagonal: ";
		cin >> n;
		cout << "enter vertical: ";
		cin >> m;
		if (n < 0 ||
			n > 2 ||
			m < 0 ||
			m > 3)
		{
			cout << "error enter!!!\n";
			to = 0;
		}
		else
		{
			to = 1;
		}
	} while (to != 1);
	if (i % 2 == 0)
	{
		arr[n][m] = 1;
	}
	else
	{
		arr[n][m] = 2;
	}
	return arr[3][3];
}
