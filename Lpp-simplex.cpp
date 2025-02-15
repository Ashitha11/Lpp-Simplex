//***************************************************************
// HEADER FILE USED IN PROJECT
//***************************************************************
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
//***************************************************************
// CLASS USED IN PROJECT
//***************************************************************
class LPP
{
public:
	float solution(float a, float b, float X, float c, float d, float Y, float x1, float x2);
	//function which makes up all row transformations
	float filecopy(float ANSWER);
	//function copies solution to text file
	void Text_file();
	//function reads solution from text file
	void binary_file();
	//function copies solution to a binary file
};
//***************************************************************
// STRUCTURE USED FOR STACK
//***************************************************************
struct NODE
{
	float JK;
	void display()
	{
		cout << JK << "<---";
	}
	NODE* next;
};
//***************************************************************
// PUSH AND DISPLAY FUNCTIONS
//***************************************************************
NODE *newptr, *top = NULL;
void push(float SOL)
//pushes the solution to stack
{
	newptr = new NODE;
	if (!newptr)
	{
		cout << "stack overflow";
		return;
	}
	newptr->next = NULL;
	newptr->JK = SOL;
	if (top == NULL)
		top = newptr;
	else
	{
		newptr->next = top;
		top = newptr;
	}
}
void disp()
//displays the solutions which stack holds
{
	NODE *temp;
	if (top == NULL)
	{
		cout << "stack underflow";
		return;
	}
	temp = top;
	cout << "THE SOLUTIONS TO THE QUERIES POSED BY USER" << endl;
	while (temp)
	{
		temp->display();
		temp = temp->next;
	}
	cout << endl;
}
//***************************************************************
// FUNCTION COPIES SOLUTION TO A FILE
//***************************************************************
float LPP::filecopy(float ANSWER)
{
	ofstream fout;
	fout.open("LPPSOLUTION.TXT");
	//opens the text file
	fout << "The solution to given Problem is.." << endl;
	fout << ANSWER;
	//solution copied to text file
	fout.close();
	//file closed
}

//***************************************************************
// FUNCTION FOR MATRIX CALCULATIONS
//***************************************************************
float LPP::solution(float a, float b, float X, float c, float d, float Y, float x1, float x2)
{
	int i, j;
	float arr[100][100];
	arr[0][0] = a;
	arr[0][1] = b;
	arr[0][2] = 1;
	arr[0][3] = 0;
	arr[0][4] = 0;
	arr[0][5] = X;
	arr[1][0] = c;
	arr[1][1] = d;
	arr[1][2] = 0;
	arr[1][3] = 1;
	arr[1][4] = 0;
	arr[1][5] = Y;
	arr[2][0] = -x1;
	arr[2][1] = -x2;
	arr[2][2] = 0;
	arr[2][3] = 0;
	arr[2][4] = 1;
	arr[2][5] = 0;
	int U = arr[0][0];
	int M = arr[2][0];
	int R = arr[1][0];
	int K = arr[0][1];
	int G = arr[2][1];
	int E = arr[1][1];
	//values given by user are assigned appropriate positions in the matrix for matrix transformations
	cout << "Y1" << "\t";
	cout << "Y2" << "\t";
	cout << "X1" << "\t";
	cout << "X2" << "\t";
	cout << "P" << "\t";
	cout << "\n\n\n";
	//***************************************************************
	// INITIAL MATRIX
	//***************************************************************
	for (i = 0;i<3;i++)
	{
		for (j = 0;j<6;j++)
		{
			cout << arr[i][j] << "\t";
			//Matrix Table is displayed on screen
		}
		cout << endl;
	}
	cout << "*******************************************************" << "\n\n";
	//***************************************************************
	// ROW TRANSFORMATIONS FOR COLUMN 1
	//***************************************************************
	float Q, W;
	Q = arr[0][5] / arr[0][0];
	// The minimum value would be made 1; while the other two values of the column are made 0.
	W = arr[1][5] / arr[1][0];
	float result;
	if (Q<W)
	{
		for (j = 0;j<6;j++)
		{
			arr[0][j] = arr[0][j] * 1 / U;
			//initial value of arr[0][j] is transformed to 1
		}
		cout << "R1 ----> R1 * 1/" << U << "\n\n";
		for (i = 0;i<3;i++)
		{
			for (j = 0;j<6;j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
		cout << "*******************************************************" << "\n\n";
		for (j = 0;j<6;j++)
		{
			arr[2][j] = arr[2][j] + arr[0][j] * (-M);
			// value of arr[2][j] is made 0
		}
		cout << "R3 ----> R3 + R1*" << -M << "\n\n";
		for (i = 0;i<3;i++)
		{
			for (j = 0;j<6;j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "*******************************************************" << "\n\n";
		for (j = 0;j<6;j++)
		{
			arr[1][j] = arr[1][j] - arr[0][j] * R;
			//value of arr[1][j] is made 0
		}
		cout << "R2 ----> R2 - R1*" << R << "\n\n";
		for (i = 0;i<3;i++)
		{
			for (j = 0;j<6;j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "*******************************************************" << "\n\n";
	}
	else
	{
		for (j = 0;j<6;j++)
		{
			arr[1][j] = arr[1][j] * 1 / c;
			//value of arr[1][j] is made 1
		}
		cout << "R2 -----> R2*1/" << c << "\n\n";
		for (i = 0;i<3;i++)
		{
			for (j = 0;j<6;j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "*******************************************************" << "\n\n";
		for (j = 0;j<6;j++)
		{
			arr[2][j] = arr[2][j] + arr[1][j] * (-M);
			//value of arr[2][j] is made 0
		}
		cout << "R3 -----> R3 + R2*" << -M << "\n\n";
		for (i = 0;i<3;i++)
		{
			for (j = 0;j<6;j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "*******************************************************" << "\n\n";
		for (j = 0;j<6;j++)
		{
			arr[0][j] = arr[0][j] - arr[1][j] * U;
			//value of arr[0][j] is made 0
		}
		cout << "R1 ----> R1 - R2*" << U << "\n\n";
		for (i = 0;i<3;i++)
		{
			for (j = 0;j<6;j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "*******************************************************" << "\n\n";
	}
	float T = arr[0][1];
	float A = arr[2][1];
	float
		F = arr[1][1];
	float V, B;
	V = arr[0][5] / arr[0][1];
	B = arr[1][5] / arr[1][1];
	//***************************************************************
	// ROW TRANSFORMATIONS FOR COLUMN 2
	//***************************************************************
	if (V<B)
	{
		for (j = 0;j<6;j++)
		{
			arr[0][j] = arr[0][j] * 1 / T;
			//value of arr[0][j] will be made 1
		}
		cout << "R1 ------> R1*1/" << T << "\n\n";
		for (i = 0;i<3;i++)
		{
			for (j = 0;j<6;j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "*******************************************************" << "\n\n";
		for (j = 0;j<6;j++)
		{
			arr[2][j] = arr[2][j] + arr[0][j] * (-A);
			//value of arr[2][j] will be made 0
		}
		cout << "R3 ------> R3 + R1*" << -A << "\n\n";
		for (i = 0;i<3;i++)
		{
			for (j = 0;j<6;j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "*******************************************************" << "\n\n";
		for (j = 0;j<6;j++)
		{
			arr[1][j] = arr[1][j] - arr[0][j] * F;
			//value of arr[1][j] will be made 0
		}
		cout << "R2 -------> R2 - R1*" << F << "\n\n";
		for (i = 0;i<3;i++)
		{
			for (j = 0;j<6;j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "*******************************************************" << "\n\n";
	}
	else
	{
		for (j = 0;j<6;j++)
		{
			arr[1][j] = arr[1][j] * 1 / F;
			//value of arr[1][j] will be made 1
		}
		cout << "R2 -------> R2*1/" << F << "\n\n";
		for (i = 0;i<3;i++)
		{
			for (j = 0;j<6;j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "*******************************************************" << "\n\n";
		for (j = 0;j<6;j++)
		{
			arr[2][j] = arr[2][j] + arr[1][j] * (-A);
			//value of arr[2][j] will be made 0
		}
		cout << "R3 ------> R3 + R2*" << -A << "\n\n";
		for (i = 0;i<3;i++)
		{
			for (j = 0;j<6;j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "*******************************************************" << "\n\n";
		for (j = 0;j<6;j++)
		{
			arr[0][j] = arr[0][j] - arr[1][j] * T;
			//value of arr[0][j] will be made 0
		}
		cout << "R1 -----> R1 - R2*" << T << "\n\n";
		for (i = 0;i<3;i++)
		{
			for (j = 0;j<6;j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "*******************************************************" << "\n\n";
	}
	cout << "\n\n";
	//***************************************************************
	// DISPLAYS FINAL MATRIX WITH SOLUTION OF LPP PROBLEM
	//***************************************************************
	cout << "\t FINAL MATRIX!!" << "\n\n";
	for (i = 0;i<3;i++)
	{
		for (j = 0;j<6;j++)
		{
			cout << setprecision(3) << arr[i][j] << "\t";
		}
		cout << endl;
	}
	//final matrix which holds the solution to given LPP problem
	cout << "n\n\n";
	cout << "SOLUTION: " << endl;
	cout << "Max Z= (" << arr[0][5] << "," << arr[1][5] << ") = " << arr[2][5];
	//Solution of given LPP Problem, solved using simplex method
	float SOL = arr[2][5];
	filecopy(SOL);
	// Solution copied to text file
	push(SOL);
	// Solution pushed to stack
}
//***************************************************************
// MAIN FUNCTION
//***************************************************************
int main()
{
	LPP l;
	int ch;
	cout << "\t ***********Program gives the user the solution of Linear programming problem using the SIMPLEX algorithm************" << endl;
	cout << "\t ONLY TWO SUBJECTIVE FUNCTIONS CAN BE INVOVLED" << "\n\n";
	while (1)
	{
		cout << "\n\t MENU: " << endl;
		cout << "1.maximizing Problem " << endl;
		cout << "2.minimizing problem " << endl;
		cout << "3.Show Stack" << endl;
		cout << "Please enter your choice.." << endl;
		cin >> ch;
		//Allows user to enter choice of problem
		cout << endl;
		switch (ch)
		{
		case 1:
			//***************************************************************
			// MAXIMIZING PROBLEM
			//***************************************************************
			cout << "The user is asked to input the coefficients of their LPP Maximizing problem.." << endl;
			float arr[100][100];
			int i, j;
			float x, y, a, b, c, d, x1, x2, X, Y;
			cout << "Enter values of coefficients of x1 and x2 (objective function)" << endl;
			cin >> x1 >> x2;
			//objective function
			cout << endl;
			cout << "Enter coefficients of x1,x2 and maximum value of first subjective function" << endl;
			cin >> a >> b >> X;
			//1st subjective function
			cout << "Enter coefficients of x1,x2 and maximum value of second subjective function:" << endl;
			cin >> c >> d >> Y;
			//2nd subjective function
			cout << endl;
			l.solution(a, b, X, c, d, Y, x1, x2);
			//Function call for maximization

			break;
		case 2:
			//***************************************************************
			// MINIMIZING PROBLEM
			//***************************************************************
			float XX, AA, YY, BB, MM, NN, PP, QQ;
			cout << endl;
			cout << "Enter values of coefficients of x1 and x2 (objective function)" << endl;
			cin >> MM >> NN;
			//objective function
			cout << endl;
			cout << "Enter coefficients of x1,x2 and maximum value of first subjective function" << endl;
			cin >> XX >> YY >> AA;
			//1st subjective function
			cout << "Enter coefficients of x1,x2 and maximum value of second subjective function:" << endl;
			cin >> PP >> QQ >> BB;
			//2nd subjective function
			cout << endl;
			l.solution(XX, PP, MM, YY, QQ, NN, AA, BB);
			//Function call for Minimization

			break;
		case 3:
			//***************************************************************
			// FUNCTION TO DISPLAY STACK THAT CONTAINS ALL SOLUTIONS
			//***************************************************************
			disp();
			//Function call for displaying the stack which contains solutions
			break;
		default:cout << "wrong code";
			return 0;
		}
	}
}

