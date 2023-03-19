#include <bits/stdc++.h>
#define int long long
using namespace std;
#define nl "\n"
const int m = 1e9 + 7;
#include <algorithm>

// commonly used functions

int gcd(int a, int b)
{
   if (a == 0)
      return b;
   return gcd(b % a, a);
}

int power(int a, int b)
{
   int res = 1;
   while (b > 0)
   {
      if (b & 1)
         res = res * a;
      a = a * a;
      b >>= 1;
   }
   return res;
}
int power_mod(int a, int b)
{
   int res = 1;
   while (b > 0)
   {
      if (b & 1)
      {
         res = ((res % m) * (a % m)) % m;
      }
      a = ((a % m) * (a % m)) % m;
      b >>= 1;
   }
   return res;
}
bool ispowerof2(int n)
{
   if (n & (n - 1))
      return false;
   else
      return true;
}

// I have been always wrong about something...

void solve()
{
   int n;
   cin >> n;
   vector<int> a;
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      a.push_back(x);
   }
   while (a.size() != 0 && a.back() != 0)
      a.pop_back();

   int i = a.size() - 1;
   int powr = 0;
   priority_queue<int> pq;
   int zer_cnt = 0;
   while (i >= 0)
   {

      while (i >= 0 && a[i] == 0)
      {
         zer_cnt++;
         i--;
      }
      while (i >= 0 && a[i] != 0)
      {
         pq.push(a[i]);
         i--;
      }
      while (zer_cnt > 0 && (!pq.empty()))
      {
         powr += pq.top();
         pq.pop();
         zer_cnt--;
      }
      while ((!pq.empty()) != 0)
      {
         pq.pop();
      }
   }

   cout << powr << nl;
}

int32_t main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   int t = 1;
   cin >> t;
   while (t--)
   {
      solve();
   }
}
