#include <iostream>
#include <fstream>

using namespace std;

#define MIN_N 1
#define MAX_N 19
#define MIN_H 1
#define MAX_H 10
#define Infinit 2000000000 // 2 miliarde 

int main()
{
	int n, i;
	float h[MAX_N+1], p[MAX_N+1], q[MAX_N+1], z[MAX_N+1];

	ifstream fin("melci.in");

	if (fin.is_open())
	{
		fin >> n;

		if (n < MIN_N || n > MAX_N)
		{
			cout << "Eroare valoare n\n";
			return 1;
		}

		for (i = 1; i <= n; i++)
		{
			fin >> h[i];

			if (h[i] < MIN_H || h[i] > MAX_H)
			{
				cout << "Eroare valoare h[i]\n";
				return 2;
			}
		}
		
		for (i = 1; i <= n; i++)
		{
			fin >> p[i] >> q[i];

			if (p[i] < q[i])
			{
				cout << "Eroare valoare (p, q); p[i] > q[i]\n";
				return 3;
			}

			if (p[i] > h[i])
			{
				cout << "Eroare valoare (p, q); p[i] > h[i]\n";
				return 4;
			}
			
			if (p[i] < 0 || q[i] < 0)
			{
				cout << "Eroare valoare (p, q); p[i] < 0 sau q[i] < 0\n";
				return 5;
			}

			if (p[i] == q[i])
			{
				z[i] = Infinit;
			}
			else
			{
				z[i] = h[i]/(p[i]-q[i]);
			}
		}
	}
	else
	{
		cout << "Nu am putut deschide fisierul melci.in\n";
		return 6;
	}

	fin.close();
	
	int m[MAX_N+2], k, st, dr, mij, j;

	m[1] = k = 1;

	for (i = 2; i <= n; i++)
	{
		st = 0, dr = k+1;

		while (dr-st > 1)
		{
			mij = st + (dr-st)/2;

			if (z[m[mij]] < z[i])
			{
				st = mij;
			}
			else
			{
				dr = mij;
			}
		}
		
		for (j = ++k; j > dr; j--)
		{
			m[j] = m[j-1];
		}

		m[dr] = i;
	}

	ofstream fout("melci.out");

	for (i = 1; i <= n; i++)
	{
		fout << m[i] << " ";
	}
	
	fout << "\n";

	fout.close();
		
	return 0;
}
