#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>

struct Point{
    int x,y;
};

double dist(Point a, Point b){
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
void uva10911(){


    int n;
    scanf("%d\n", &n);
    int twoN = n*2;
    Point pts[twoN];
    char nm[1000];
    int i=0,j;
    while(twoN--){
        scanf("%s %d %d", nm, &pts[i].x, &pts[i].y);
        i++;
    }

    double minD = 0;
    int minIdx = 0;
    double d[n];
    double dst;
    for(i=0;i<2*n;i=i+2){
        minD = (double)INT_MAX;
        minIdx = i+1;
        for(j=i+1;j<2*n;j++){
            if((dst = dist(pts[i], pts[j])) < minD){
                minD = dst;
                minIdx = j;
            }
        }
        printf("Closest of (%d, %d) is (%d, %d) = %lf\n", pts[i].x, pts[i].y, pts[minIdx].x, pts[minIdx].y, minD);
        Point t = pts[i+1];
        pts[i+1] = pts[minIdx];
        pts[minIdx] = t;
        d[i/2] = minD;
    }

    double sum = 0;
    for(i=0;i<n;i++)
        sum += d[i];

    printf("%.2lf\n", sum);
}
