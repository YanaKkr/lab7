#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int Find(int** a, const int k, const int n);

int main()
{
   srand((unsigned)time(NULL));
   int Low = -21;
   int High = 24;
   int k, n;

   cout << "k = ";
   cin >> k;
   cout << "n = ";
   cin >> n;

   int** a = new int* [k];
   for (int i = 0; i < k; i++)
      a[i] = new int[n];

   Create(a, k, n, Low, High);
   Print(a, k, n);

   int result = Find(a, k, n);
   cout << "Result: " << result << endl;
   for (int i = 0; i < k; i++)
       delete[] a[i];
   delete[] a;

   return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
   for (int i = 0; i < k; i++)
      for (int j = 0; j < n; j++)
         a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
   cout << endl;
   for (int i = 0; i < k; i++)
   {
       for (int j = 0; j < n; j++)
           cout << setw(4) << a[i][j];
       cout << endl;
    }
   cout << endl;
}

int Find(int** a, const int k, const int n)
{
   int minimum = INT_MAX;
   
   for (int j = 0; j < n; j += 2)
   {
      int max_j = a[0][j];
      for (int i = 1; i < k; i++)
      {
         if (a[i][j] > max_j)
            max_j = a[i][j];
      }
      if (max_j < minimum)
         minimum = max_j;
   }

   if (minimum == INT_MAX)
      return -1;

   return minimum;
}