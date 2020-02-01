#include <iostream>
#include <conio.h>

using namespace std;
int main() {
	bool H[18][18], G[10][10];
	int c, l, size, a, Q[5] = { 0,0,0,0,0 }, S[5] = { 0,4,3,2,1 };
	char dn;
	char overlap[] = "Unable to set a warship here due to overlapping, please select another spot";
	char cntinue[] = "Press any key to continue";
	char mxamount[] = "You already have maximum amount this type of warships, set all the rest PLEASE";

	for (c = 0; c < 3; c++) {
		for (l = 0; l < 18; l++) {
			H[c][l] = 1;
		}
	}
	for (c = 15; c < 18; c++) {
		for (l = 0; l < 18; l++) {
			H[c][l] = 1;
		}
	}
	for (c = 0; c < 18; c++) {
		for (l = 0; l < 3; l++) {
			H[c][l] = 1;
		}
	}
	for (c = 0; c < 18; c++) {
		for (l = 15; l < 18; l++) {
			H[c][l] = 1;
		}
	}

	cout << "Sea Battle v 1.0 by Merciless" << '\n' << "Press any key to start";
	_getch(); system("cls");

	while (Q[0] < 10) {
		cout << "Warships on desk: " << Q[0] << '\n' << "Size 1 warships: " << Q[1] << '\t' << "Size 2 warships: " << Q[2] << '\t' << "Size 3 warships: " << Q[3] << '\t' << "Size 4 warships: " << Q[4] << '\n';
		cout << "Choose a spot to set a warship (enter COLUMN and LINE)" << '\n';
		cin >> c >> l;
		if (c > 10 || c < 1 || l>10 || l < 1) {
			cout << "Please select a proper spot";
			_getch(); system("cls");
		}
		else {
			c += 3; l += 3;
			if ((H[c][l] != 1) && (H[c - 1][l - 1] != 1) && (H[c - 1][l] != 1) && (H[c - 1][l + 1] != 1) && (H[c][l + 1] != 1) && (H[c + 1][l + 1] != 1) && (H[c + 1][l] != 1) && (H[c + 1][l - 1] != 1) && (H[c][l - 1] != 1)) {
				cout << "Set a warship to (" << c - 3 << ";" << l - 3 << ")? (type 1 if yes) " << '\n';
				cin >> a;
				if (a == 1) {
					cout << "Pick ship size (1-4): ";
					cin >> size, '\n';
					if (size <= 4 && size >= 1) {
						if (size == 1) {
							if (Q[1] < 4) {
								H[c][l] = 1; Q[0]++; Q[1]++;
								cout << "A size 1 ship has been set to (" << c - 3 << ";" << l - 3 << ")" << '\n' << cntinue; _getch(); system("cls");
							}
							else {
								cout << mxamount; _getch(); system("cls");
							}
						}
						else{
							if (Q[size] < S[size]) {
								cout << "Pick direction (l, r, t, b): ";
								cin >> dn, '\n';
								if (dn != 'l' && dn != 'r' && dn != 't' && dn != 'b') {
									cout << "Please select a proper direction ('l' for left, 'r' for right, 't' for top, 'b' for bottom)";  _getch(); system("cls");
								}
								else {
									if (size == 2) {
										if ((dn == 'l')) {
											if ((H[c - 2][l] != 1) && (H[c - 2][l - 1] != 1) && (H[c - 2][l + 1] != 1)) {
												H[c][l] = 1; H[c - 1][l] = 1; Q[2]++; Q[0]++;
												cout << "A size 2 ship has been set to (" << c - 3 << ";" << l - 3 << ") directed left" << '\n' << cntinue; _getch(); system("cls");
											}
											else {
												cout << overlap << '\n' << cntinue; _getch(); system("cls");
											}

										}
										if ((dn == 'r')) {
											if ((H[c + 2][l] != 1) && (H[c + 2][l - 1] != 1) && (H[c + 2][l + 1] != 1)) {
												H[c][l] = 1; H[c + 1][l] = 1; Q[2]++; Q[0]++;
												cout << "A size 2 ship has been set to (" << c - 3 << ";" << l - 3 << ") directed right" << '\n' << cntinue; _getch(); system("cls");
											}
											else {
												cout << overlap << '\n' << cntinue; _getch(); system("cls");
											}
										}
										if ((dn == 't')) {
											if ((H[c - 1][l - 2] != 1) && (H[c][l - 2] != 1) && (H[c + 1][l - 2] != 1)) {
												H[c][l] = 1; H[c][l - 1] = 1; Q[2]++; Q[0]++;
												cout << "A size 2 ship has been set to (" << c - 3 << ";" << l - 3 << ") directed upward" << '\n' << cntinue; _getch(); system("cls");
											}
											else {
												cout << overlap << '\n' << cntinue; _getch(); system("cls");
											}
										}
										if ((dn == 'b')) {
											if ((H[c - 1][l + 2] != 1) && (H[c][l + 2] != 1) && (H[c + 1][l + 2] != 1)) {
												H[c][l] = 1; H[c][l + 1] = 1; Q[2]++; Q[0]++;
												cout << "A size 2 ship has been set to (" << c - 3 << ";" << l - 3 << ") directed downward" << '\n' << cntinue; _getch(); system("cls");
											}
											else {
												cout << overlap << '\n' << cntinue; _getch(); system("cls");
											}
										}
									}
									if (size == 3) {
										if ((dn == 'l')) {
											if ((H[c - 2][l] != 1) && (H[c - 2][l - 1] != 1) && (H[c - 2][l + 1] != 1) && (H[c - 3][l + 1] != 1) && (H[c - 3][l] != 1) && (H[c - 3][l - 1] != 1)) {
												H[c][l] = 1; H[c - 1][l] = 1; H[c - 2][l] = 1; Q[3]++; Q[0]++;
												cout << "A size 3 ship has been set to (" << c - 3 << ";" << l - 3 << ") directed left" << '\n' << cntinue; _getch(); system("cls");
											}
											else {
												cout << overlap << '\n' << cntinue; _getch(); system("cls");
											}
										}
										if ((dn == 'r')) {
											if ((H[c + 2][l] != 1) && (H[c + 2][l - 1] != 1) && (H[c + 2][l + 1] != 1) && (H[c + 3][l + 1] != 1) && (H[c + 3][l] != 1) && (H[c + 3][l - 1] != 1)) {
												H[c][l] = 1; H[c + 1][l] = 1; H[c + 2][l] = 1; Q[3]++; Q[0]++;
												cout << "A size 3 ship has been set to (" << c - 3 << ";" << l - 3 << ") directed right" << '\n' << cntinue; _getch(); system("cls");
											}
											else {
												cout << overlap << '\n' << cntinue; _getch(); system("cls");
											}
										}
										if ((dn == 't')) {
											if ((H[c - 1][l - 2] != 1) && (H[c][l - 2] != 1) && (H[c + 1][l - 2] != 1) && (H[c + 1][l - 3] != 1) && (H[c][l - 3] != 1) && (H[c - 1][l - 3] != 1)) {
												H[c][l] = 1; H[c][l - 1] = 1; H[c][l - 2] = 1; Q[3]++; Q[0]++;
												cout << "A size 3 ship has been set to (" << c - 3 << ";" << l - 3 << ") directed upward" << '\n' << cntinue; _getch(); system("cls");
											}
											else {
												cout << overlap << '\n' << cntinue; _getch(); system("cls");
											}
										}
										if ((dn == 'b')) {
											if ((H[c - 1][l + 2] != 1) && (H[c][l + 2] != 1) && (H[c + 1][l + 2] != 1) && (H[c + 1][l + 3] != 1) && (H[c][l + 3] != 1) && (H[c - 1][l + 3] != 1)) {
												H[c][l] = 1; H[c][l + 1] = 1; H[c][l + 2]; Q[3]++; Q[0]++;
												cout << "A size 3 ship has been set to (" << c - 3 << ";" << l - 3 << ") directed downward" << '\n' << cntinue; _getch(); system("cls");
											}
											else {
												cout << overlap << '\n' << cntinue; _getch(); system("cls");
											}
										}
									}
									if (size == 4) {
										if ((dn == 'l')) {
											if ((H[c - 2][l] != 1) && (H[c - 2][l - 1] != 1) && (H[c - 2][l + 1] != 1) && (H[c - 3][l + 1] != 1) && (H[c - 3][l] != 1) && (H[c - 3][l - 1] != 1) && (H[c - 4][l - 1] != 1) && (H[c - 4][l] != 1) && (H[c - 4][l + 1] != 1)) {
												H[c][l] = 1; H[c - 1][l] = 1; H[c - 2][l] = 1; H[c - 3][l] = 1; Q[4]++; Q[0]++;
												cout << "A size 4 ship has been set to (" << c - 3 << ";" << l - 3 << ") directed left" << '\n' << cntinue; _getch(); system("cls");
											}
											else {
												cout << overlap << '\n' << cntinue; _getch(); system("cls");
											}
										}
										if ((dn == 'r')) {
											if ((H[c + 2][l] != 1) && (H[c + 2][l - 1] != 1) && (H[c + 2][l + 1] != 1) && (H[c + 3][l + 1] != 1) && (H[c + 3][l] != 1) && (H[c + 3][l - 1] != 1) && (H[c + 4][l - 1] != 1) && (H[c + 4][l] != 1) && (H[c + 4][l + 1] != 1)) {
												H[c][l] = 1; H[c + 1][l] = 1; H[c + 2][l] = 1; H[c + 3][l] = 1; Q[4]++; Q[0]++;
												cout << "A size 4 ship has been set to (" << c - 3 << ";" << l - 3 << ") directed right" << '\n' << cntinue; _getch(); system("cls");
											}
											else {
												cout << overlap << '\n' << cntinue; _getch(); system("cls");
											}
										}
										if ((dn == 't')) {
											if ((H[c - 1][l - 2] != 1) && (H[c][l - 2] != 1) && (H[c + 1][l - 2] != 1) && (H[c + 1][l - 3] != 1) && (H[c][l - 3] != 1) && (H[c - 1][l - 3] != 1) && (H[c - 1][l - 4] != 1) && (H[c][l - 4] != 1) && (H[c + 1][l - 4] != 1)) {
												H[c][l] = 1; H[c][l - 1] = 1; H[c][l - 2] = 1; H[c][l - 3] = 1; Q[4]++; Q[0]++;
												cout << "A size 4 ship has been set to (" << c - 3 << ";" << l - 3 << ") directed upward" << '\n' << cntinue; _getch(); system("cls");
											}
											else {
												cout << overlap << '\n' << cntinue; _getch(); system("cls");
											}
										}
										if ((dn == 'b')) {
											if ((H[c - 1][l + 2] != 1) && (H[c][l + 2] != 1) && (H[c + 1][l + 2] != 1) && (H[c + 1][l + 3] != 1) && (H[c][l + 3] != 1) && (H[c - 1][l + 3] != 1) && (H[c - 1][l + 4] != 1) && (H[c][l + 4] != 1) && (H[c + 1][l + 4] != 1)) {
												H[c][l] = 1; H[c][l + 1] = 1; H[c][l + 2]; H[c][l + 3] = 1; Q[4]++; Q[0]++;
												cout << "A size 4 ship has been set to (" << c - 3 << ";" << l - 3 << ") directed downward" << '\n' << cntinue; _getch(); system("cls");
											}
											else {
												cout << overlap << '\n' << cntinue; _getch(); system("cls");
											}
										}
									}
								}
							}
							else {
								cout << mxamount; _getch(); system("cls");
							}
							
						}
					}
					else {
						cout << "Please select a proper ship size (1-4)"; _getch(); system("cls");
					}
				}
				else {
					system("cls");
				}
			}
			else {
				cout << overlap << '\n' << cntinue; _getch(); system("cls");
			}
		}
	}
	cout << "All ships are set, prepare for battle" << '\n' << cntinue;  _getch(); system("cls");


	
	
	return 0;
}