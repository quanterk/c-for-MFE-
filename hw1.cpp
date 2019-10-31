#include <iostream>
#include<vector>
#include <algorithm>
#include<string>

using namespace std;

#include <math.h>

int  max_value = 1000;
class Solution {
public:
	void q1()

	{
		//int pro = 0;
		for (int i = 1; i <= 5; i++) 
		{
			for (int j = 1; j <= 1000; j *= 10)
			{
				int pro = (i * j);
				cout << pro << "\t" << ends;
			}
			cout << "\n";
		
		}

	}

	void q2(int k = 5)  //default is 5
	{  
		for (int i = 1; i <= k; i++) 
		{
			if (i == 1 || i == k)

			{
				string s(k, '*');
				cout << s << endl;
			}
			else 			
			{

				string temp(k - 2, ' ');
				cout << "*" + temp + "*" << endl;
	
			}
		
		}


	
	}



	void q3() 
	
	{
		for (int i = 1; i <= 497; i++) 
		
		{
			for (int j = i + 1; j <= 498; j++) 

			{
				int sum = i*i + j *j;
				//cout << sum << endl;
				//if ((typeid (sqrt(sum)).name() == typeid (sqrt(4)).name()) && int(sqrt(sum)) > j) 
				if ((double)(int)sqrt(sum) == sqrt(sum) && sqrt(sum) <= 500)
				{
					//cout << "yes";
					int s = i + j + int(sqrt(sum));
					cout << "three num is: " << i <<"\t"<< j <<"\t" << sqrt(sum)<<"\t"<<"the sum is " << s<<endl;
				
				}



			
			
			}
		
		}
	
	
	}

	void q4()
	{
		extern int max_value;  // fw declaration;
		for (int i = 1; i < max_value; i++)
		{
			if (isperfect(i))

			{
				cout << i << endl;
			}

		}

	}


	void q5(int x,int y)
	{
		int min = (x < y) ? x : y;
		int max = 1;
		for (int i = 1; i <= min; i++) 

		
		{
			
			if (x % i == 0 && y % i == 0) 
			{ 
				if (max < i) max = i;
			
			
			}
			


		
		}
		cout << "the greatst common divisor is :" << max << endl;
	
	
	}

	int q6_value(int k) 
	{
		int re = 1;
		while (k >= 1) {

			re *= k--;
			
		
		
		}
		cout << re << endl;
		return re;
	
	
	
	
	}

	void q6_ref(int &k) 
	{
		for (int i = k - 1; i >= 1; i--)
			k *= i;


		cout << k << endl;
	
	
	
	}

	void q6_ptr(int *temp)
	{
		for (int i = *temp - 1; i >= 1; i--)
			* temp *= i;


		cout << *temp << endl;



	}

	vector<int> q7(int n)


	{
		vector<int> v1{ 1,2,3,4,5,6,7,8,9,10 };

		for (auto p1 = v1.begin(); p1 != v1.end();)   //迭代器
		{
			if (*p1 == n)
			{
				p1 = v1.erase(p1);
				v1.push_back(0);
				break;
			}
			else
			{
				p1++;              //避免野指针
			}
		}

		for (auto num : v1) 
		{
			cout << num << '\t';
		}

		return v1;
	}




	void q8()


	{

		cout << "pls input the length of array you want";
		int len;
		cin >> len;
		int* array = new int[len]();  // intialize to be 0;
		for (int i = 0; i < len; i++) 
		{
			int num = 0;
			cout << "pls input the " << i << "th num:";
			cin >> num;
			array[i] = num;

		}

		int n;
		cout << "pls input the num you want to delete";
		cin >> n;

		int i = 0;
		while(i < len)
		{
			if (array[i] == n)
			{
				for (int j = i; j < len - 1; j++)
					array[j] = array[j + 1];
				array[len - 1] = 0;
			}
			else
				i++;

		}

		for (int i = 0; i < len; i++)
		{
			
			cout << array[i] << '\t';
		}

		delete[]  array;



	}


	void q9() 
	{

		int n, sum = 0;
		cout << "Pls input the order n .. \n:";
		cin >> n;
		int** a;
		a = new int* [n];
		for (int i = 0; i < n; i++)
			a[i] = new int[n]();
		OddMagic(a, n);

		cout << endl << "The magic matrix is:" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0)
					sum += a[i][j];
				cout << a[i][j] << '\t';
			}

			cout << endl;
		}
		cout << endl << "The magic sum constant is:" << sum << endl;
		for (int i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
	}

		

	int q10()
	{
		int n, sum = 0, number, count = 0;
		cout << "Please input n(better less than 4 ,otherwise it will be slow):";
		cin >> n;
		vector<int> array;
		for (int i = 1; i <= n * n; i++)
		{
			array.push_back(i);
		}
		cout << endl << "The magic square is:" << endl;
		do
		{
			if (Check(n, array))
			{
				count++;
				for (int i = 0; i < array.size(); i++)
				{
					if (i >= 0 && i <= n - 1 && count == 1)
						sum += array[i];
					cout << array[i] << '\t';
					if ((i + 1) % 3 == 0)
						cout << endl;
				}
				cout << endl;
			}
		} while (next_permutation(array.begin(), array.end()));

		cout << endl << "The magic constant is:" << sum << endl;
		return 0;
	}
	












private:
	bool isperfect(int n)
	{
		vector<int> result = fac(n);
		int sum = 0;
		for (int num : result)
		{
			sum += num;

		}
		
		if (sum == n)
			return true;
		else
			return false;

	}


	vector<int> fac(int k)
	{
		vector<int> result;
		for (int i = 1; i < k; i++)
		{
			if (k % i == 0) result.push_back(i);

		}

		return result;



	}

	void OddMagic(int** a, int n)
	{
		int x = n / 2, y = n - 1;
		for (int i = 1; i <= n * n; i++)

		{
			a[x][y] = i;
			x--;
			y++;
			if (x == -1 && y == n) { x = 0; y = n - 2; }
			else if (x == -1)	x = n - 1;
			else if (y == n)	y = 0;
			else if (a[x][y] != 0) {
				x = x + 1;
				y = y - 2; 
				if (x == -1 && y == n) { x = 0; y = n - 2; }
				else if (x == -1)	x = n - 1;
				else if (y == n)	y = 0;

			}
		

		}
	}


	bool Check(int n, vector<int> m)
	{
		int cnt = n * (n * n + 1) / 2;
		for (int i = 0; i < n; i++)
		{
			int sum_row = 0, sum_line = 0;
			for (int j = 0; j < n; j++)
			{
				sum_row += m[i * n + j];
				sum_line += m[j * n + i];
			}
			if (sum_row != cnt || sum_line != cnt)
				return false;
		}

		int sum_left = 0, sum_right = 0;
		for (int i = 0; i < n; i++)
		{
			sum_left += m[i * n + i];
			sum_right += m[(n - i - 1) * n + i];
		}
		if (sum_left != cnt || sum_right != cnt)
			return false;
		return true;
	}


};






int main() 
{
	Solution so;

	while (true) 
	{
		cout << "Dear: which question u want to check? pls input num 1-10 ,and exit with 0...\n";

		int num = 0;
		cin >> num;
		if (num == 0) break;
		if (num == 1)
			so.q1();
		if (num == 2)
			so.q2(10);
		if (num == 3)
			so.q3();
		if (num == 4)
			so.q4();


		if (num == 5) 
		{
			cout << "pls input two numbers for q5 and press enter... \n";
			int x;
			cin >> x;
			int y;
			cin >> y;
			so.q5(x, y);
		
		}

		if (num == 6)
		{
			cout << "pls input which method u want to use(1->value, 2->ref,3->pointer)";
			int method;
			cin>> method;

			cout << "pls input number u wang to compute";
			int n;
			
			cin >> n;
			if (method == 1) so.q6_value(n);
			if (method == 2) so.q6_ref(n);
			if (method == 3) so.q6_ptr(&n);
		
		}
		if (num == 7)
			so.q7(5);  // 可以自定义值

		if (num == 8)
			so.q8();
		if (num == 9)
			so.q9();
		if (num == 10)
			so.q10();
	}


	return 0;
}



