#include <bits/stdc++.h>

int r, c, pr, pc, fr, fc;

int proman(int qr, int qc) {
	return abs(qr-pr)+abs(qc-pc);
}

int fisman(int qr, int qc) {
	return abs(qr-fr)+abs(qc-fc);
}

int special(int qr, int qc) {
	int a = abs(qr-fr);
	int b = abs(qc-fc);
	int a2 = abs(qr-pr);
	int b2 = abs(qc-pc);
	return a*a+b*b==a2*a2+b2*b2;
}

int fissioncloser(int qr, int qc) {
	int a = abs(qr-fr);
	int b = abs(qc-fc);
	int a2 = abs(qr-pr);
	int b2 = abs(qc-pc);
	return a*a+b*b<a2*a2+b2*b2;
}


using namespace std;
int main() {
	cin >> r >> c >> pr >> pc >> fr >> fc;

	int q;
	cin >> q;

	int qr, qc;
	if(abs(pr-fr)==abs(pc-fc)) {
		for(int i = 0; i < q; i++) {
			cin >> qr >> qc;
			if(special(qr,qc))
				cout << "MOUNTAINS" << endl;
			else if(fissioncloser(qr,qc))
				cout << "LAVA" << endl;
			else
				cout << "WATER" << endl;
		}
	}
	else 
	{
		for(int i = 0; i < q; i++) {
			cin >> qr >> qc;
			if(proman(qr, qc) == fisman(qr, qc))
				cout << "MOUTAINS" << endl;
			else if(proman(qr, qc) < fisman(qr, qc))
				cout << "WATER" << endl;
			else
				cout << "LAVA" << endl;
		}
	}


	return 0;
}
	

