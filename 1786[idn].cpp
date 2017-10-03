#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include <vector>
#define MAX 1000001

using namespace std;

vector<int> ans;
char T[MAX], P[MAX];
int k_array[MAX];

void make_k_array()
{
  int m = strlen(P);
	int j = 0;
	int k = -1;
	k_array[0] = -1;
	while(j <= m){
		if( k == -1 || P[j] == P[k]){
			j++;
			k++;
			k_array[j] = k;
		} else {
			k = k_array[k];
		}
	}
}

void kmp()
{
  int i = 0, j = 0;
  int n = strlen(T);
  int m = strlen(P);
  while (i < n)
  {
    if (T[i] == P[j] || j == -1){
      j++;
      i++;
      if (j == m){
        ans.push_back(i-j+1);
        j = k_array[j];
      }
    } else {
      j = k_array[j];
    }
  }
}

int main()
{
  gets(T); // not safe??
  gets(P);
  
  make_k_array();

  kmp();

  printf("%lu\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d ", ans[i]);

}