#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    int bp =p, fpage =0, bpage=0, i=0, j=n;
    while(i!=p) {
        fpage++;
        i++;
    }
    fpage = fpage/2;

    while(j != bp) {
        bpage++;
        j--;
    }
    bpage = bpage/2;

    if(fpage<bpage){
        return fpage;
    } else {
        return bpage;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
