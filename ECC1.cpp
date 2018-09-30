#include <iostream>
#include <math.h>
using namespace std;
struct pt {
double x, y;

};

pt zero(void) { return (pt){ INFINITY, INFINITY }; }

int is_zero(pt p) { return p.x > 1e20 || p.x < -1e20; }

pt neg(pt p) { return (pt){ p.x, -p.y }; }

pt dbl(pt p) {
	if (is_zero(p)) return p;

	pt r;
	double L = (3 * p.x * p.x) / (2 * p.y);
	r.x = L * L - 2 * p.x;
	r.y = L * (p.x - r.x) - p.y;
	return r;
}

pt add(pt p, pt q) {
	if (p.x == q.x && p.y == q.y) return dbl(p);
	if (is_zero(p)) return q;
	if (is_zero(q)) return p;

	pt r;
	double L = (q.y - p.y) / (q.x - p.x);
	r.x = L * L - p.x - q.x;
	r.y = L * (p.x - r.x) - p.y;
	return r;
}

pt mul(pt p, int n) {
	int i;
	pt r = zero();

	for (i = 1; i <= n; i <<= 1) {
		if (i & n) r = add(r, p);
		p = dbl(p);
	}
	return r;
}



int main() {
	pt a, b, c,e2,c1,c2,pl;

 cout<<"Bob choses a point on curve"<<endl;
 double x1,x2,y1,y2,d,r;
 cin>>a.x>>a.y;
 cout<<"Bob choses an integer d&r"<<endl;
 cin>>d>>r;
 e2=mul(a,d);

 cout<<"Encryption"<<endl;
 c1= mul(a,r);


 cout<<"Bob choses a point plain text"<<endl;
 cin>>b.x>>b.y;
 c2= add(b,mul(e2,r));

 cout<<"Decryption"<<endl;
 cout<<"plain text"<<endl;

 pl= add(c2,neg(mul(c1,d)));

 cout<<pl.x<<endl;
 cout<<pl.y<<endl;


	return 0;
}