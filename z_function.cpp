/* solucao do problema http://www.spoj.com/problems/DISUBSTR/ - conte o numero de substrings diferentes da 
	string de entrada - uso do algoritmo Z */

#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
 
char a[1005];
int z[1005];
 

/* algoritmo Z, complexidade O(N) tempo
	z[0] = 0;
	z[x] = tamanho do maior prefixo da string que comeca na posicao x */
int z_function(string s) {
    int zmax = 0;
 
    for (int i = 1, l = 0, r = 0; i < (int)s.size(); i++) {
        z[i] = 0;
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while(i + z[i] < (int)s.size() && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
        if (z[i] > zmax) {
            zmax = z[i];
        }
    }
    return (int)s.size() - zmax;
}
 
int main(void) {
    int t;
    int r;
    string s;
 
    scanf(" %d", &t);
 
    while(t--) {
        scanf(" %s", a);
        s = "";
        r = 0;
        for (int i = 0; a[i] != '\0'; i++) {
            s = a[i] + s;
            r += z_function(s);
        }
        printf("%d\n", r);
    }
    return 0;
}
