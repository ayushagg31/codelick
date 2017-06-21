#include <bits/stdc++.h>
using namespace std;
int main() {
	int l[5], s[5], r[5], p[5];
	for(int i = 1; i <= 4; i++)
		scanf("%d%d%d%d", &l[i], &s[i], &r[i], &p[i]);
	if(p[1] && (l[1] || s[1] || r[1] || l[2] || s[3] || r[4]))
		printf("YES\n");
	else if(p[2] && (l[2] || s[2] || r[2] || l[3] || s[4] || r[1]))
		printf("YES\n");
	else if(p[3] && (l[3] || s[3] || r[3] || l[4] || s[1] || r[2]))
		printf("YES\n");
	else if(p[4] && (l[4] || s[4] || r[4] || l[1] || s[2] || r[3]))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}