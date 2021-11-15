// Question
// Ternary Search
// https://www.geeksforgeeks.org/optimum-location-point-minimize-total-distance/

//------------Code-------------
#include <string.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
#define show(v) for(auto &x: v) cout << x << ' '; cout << endl;

vector<int> coeff(3);
vector<vector<int>> points;

ld dist(ld x1, ld y1, ld x2, ld y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

ld dist_line(ll x){
    ll y = (-1*coeff[0]*x - coeff[2])/coeff[1];
    ld d = 0;

    for(auto p: points){
        d += dist(x, y, p[0], p[1]);
    }
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    points = {{-3,-2}, {-1,0}, {-1,2}, {1,2}, {3,4}};
    coeff = {1, -1, -3};

    ll lo = -1000, hi = 1000;
    ll m1=0, m2=1;

    while(m1!=m2){
        m1 = lo + (hi-lo)/3;
        m2 = m1 + (hi-lo)/3;
        if(dist_line(m1)<dist_line(m2)) hi = m2;
        else lo = m1;
    }

    ll x=0; ld md=INT_MAX;
    int temp = lo;
    if(dist_line(temp) < md){
        md = dist_line(temp);
        x = temp;
    }
    temp = m1;
    if(dist_line(temp) < md){
        md = dist_line(temp);
        x = temp;
    }
    temp = m2+1;
    if(dist_line(temp) < md){
        md = dist_line(temp);
        x = temp;
    }
    temp = hi;
    if(dist_line(temp) < md){
        md = dist_line(temp);
        x = temp;
    }

    //cout << lo << " " << m1 << " " << m2 << " " << hi << endl;
    cout << "Mininmum distance is " << md << " at x = " << x << endl;

    return 0;
}
