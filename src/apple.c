#include <stdio.h>

int n;
int k;
int A[100000];


//pは単調非減少である
int p(int m) {            //mはバッグに入れることができるりんごの数とする.
    int i;
    int sum = 0;
    for (i = 0; i < n ; i++) {
        sum += (A[i] + m - 1) / m;
    }
    if (sum <= k) return 1;
    else return 0;
}

int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n ; i++) {
        scanf("%d", &A[i]);
    }
    // lbは最大値,ubは最小値を選ぶ.

    lb = 0;          // m=0のとき,入力制約より最低1つは収穫されているので必ずp=0となる.
                      // 一方,m=1のとき,全員がリンゴをちょうど1個収穫した場合を考えると,p=0とならない場合があると分かる.
                      // よって,最大値としてlb=0を選ぶ.

    ub = 1000000000;   // m=10^9のとき, 入力制約よりA[i]<=10^9であり.バッグは人数分以上あるので必ずp=1となる.
                       // 一方,m=10^9-1のとき,n=kかつa[i]=10^9の場合を考えれば,p=1とならない場合があると分かる.
                       // よって,最小値としてub=10^9を選ぶ.
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid) == 1)  ub = mid;
        else lb = mid;
    }
    printf("%d\n", ub);
    return 0;

}
