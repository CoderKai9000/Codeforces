#include <iostream>
using namespace std;

int solve(int n, int k) {
    if (k == 0) {
        return 0;
    }
    if (k <= n) {
        return 1;
    }
    else {
        int count = 0;
        k-=n;
        count++;
        int largest_existing_diag = n-1;
        while(k >= largest_existing_diag && largest_existing_diag > 0) {
            k-=largest_existing_diag;
            count++;
            if (k < largest_existing_diag) {
                break;
            }
            k-= largest_existing_diag;
            count++;
            largest_existing_diag--;
        }
        if(k==0) return count;
        else return count+1;
    }
}

int main() {
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << solve(n,k) << "\n";
    }
    return 0;
}