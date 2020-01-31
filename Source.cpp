#include <iostream>
#include <conio.h>

using namespace std;
int main() {
	bool H[16][16], G[16][16];
	// borders (0, 1, 14, 15) := 0
	int c, l, size, a, Q = 0, Q1 = 0, Q2 = 0, Q3 = 0, Q4 = 0;
	char dn;
	cout << "Sea Battle v 1.0 by Merciless" << '\n' << "Press any key to start";
	_getch(); system("cls");

	while (Q < 10) {
		cout << "Warships on desk: " << Q << '\n' << "Size 1 warships: " << Q1 << '\t' << "Size 2 warships: " << Q2 << '\t' << "Size 3 warships: " << Q3 << '\t' << "Size 4 warships: " << Q4 << '\n';
		cout << "Choose a spot to set a warship (enter COLUMN and LINE)" << '\n';
		cin >> c >> l;
		if (c > 10 || c < 1 || l>10 || l < 1) {
			cout << "Please select a proper spot";
			_getch(); system("cls");
		}
		else {
			c += 2; l += 2;
			if ((H[c][l] != 1) && (H[c - 1][l - 1] != 1) && (H[c - 1][l] != 1) && (H[c - 1][l + 1] != 1) && (H[c][l + 1] != 1) && (H[c + 1][l + 1] != 1) && (H[c + 1][l] != 1) && (H[c + 1][l - 1] != 1) && (H[c][l - 1] != 1)) {
				cout << "Set a warship to (" << c - 2 << ";" << l - 2 << ")? (type 1 if yes) " << '\n';
				cin >> a;
				if (a == 1) {
					cout << "Pick ship size (1-4): ";
					cin >> size, '\n';
					if (size <= 4 && size >= 1) {
						if (size == 1) {
							if (Q < 4) {
								H[c][l] = 1; Q++; Q1++;
								cout << "A size 1 ship has been set to (" << c - 2 << ";" << l - 2 << ")" << '\n' << "Press any key to continue"; _getch(); system("cls");
							}
							else {
								cout << "You already have maximum amount this type of warships, set all the rest PLEASE"; _getch(); system("cls");
							}
						}
						else{
							cout << "Pick direction (l, r, t, b): ";
							cin >> dn, '\n';
							if (dn != 'l' && dn != 'r' && dn != 't' && dn != 'b') {
								cout << "Please select a proper direction ('l' for left, 'r' for right, 't' for top, 'b' for bottom)";  _getch(); system("cls");
							}
							else {
								if (size == 2) {
									if ((dn == 'l') && (H[c - 2][l] != 1) && (H[c - 2][l - 1] != 1) && (H[c - 2][l + 1] != 1))
										H[c][l] = 1; H[c - 1][l] = 1;
									if ((dn == 'r') && (H[c + 2][l] != 1) && (H[c + 2][l - 1] != 1) && (H[c + 2][l + 1] != 1))
										H[c][l] = 1; H[c + 1][l] = 1;
									if ((dn == 't') && (H[c - 1][l - 2] != 1) && (H[c][l - 2] != 1) && (H[c + 1][l - 2] != 1))
										H[c][l] = 1; H[c][l - 1] = 1;
									if ((dn == 'b') && (H[c - 1][l + 2] != 1) && (H[c][l + 2] != 1) && (H[c + 1][l + 2] != 1))
										H[c][l] = 1; H[c][l + 1] = 1;
								}
							}
						}
					}
					else {
						cout << "Please select a proper ship size (1-4)"; _getch(); system("cls");
					}
				}
			}
			else {
				cout << "Unable to set a warship here due to overlapping, please select another spot" << '\n' << "Press any key to continue"; _getch(); system("cls");
			}
		}
	}

	for (l = 1; l < 12; l++) {
		for (c = 1; c < 12; c++) {
			if ((H[c][l] != 1) && (H[c - 1][l - 1] != 1) && (H[c - 1][l] != 1) && (H[c - 1][l + 1] != 1) && (H[c][l + 1] != 1) && (H[c + 1][l + 1] != 1) && (H[c + 1][l] != 1) && (H[c + 1][l - 1] != 1) && (H[c][l - 1] != 1)) {
				cout << "Set a ship to (" << l << ";" << c << ")? "; // !!!!! U STUPID OR SMTH	REDO THIS SHIT !!!!
				cin >> a; system("cls");
				if (a == 1) {
					cout << "Pick ship size and direction" << '\n' << "Size: "; // size 1-4, direction l (left), r (right), d (down), u (up)
					cin >> size, '\n';
					cout << "Direction: ";
					cin >> dn, '\n';
					if (size == 2) {
						if ((dn == 'l')&&(H[c-2][l] != 1)&& (H[c-2][l-1] != 1)&& (H[c-2][l+1] != 1)) {
							H[c][l] = 1; H[c - 1][l] = 1;
						}
						if ((dn == 'r') && (H[c + 2][l] != 1) && (H[c + 2][l - 1] != 1) && (H[c + 2][l + 1] != 1)) {
							H[c][l] = 1; H[c + 1][l] = 1;
						}
						if ((dn == 'u') && (H[c - 1][l-2] != 1) && (H[c][l - 2] != 1) && (H[c + 1][l -2] != 1)) {
							H[c][l] = 1; H[c][l-1] = 1;
						}
						if ((dn == 'd') && (H[c - 1][l + 2] != 1) && (H[c][l + 2] != 1) && (H[c + 1][l + 2] != 1)) {
							H[c][l] = 1; H[c][l + 1] = 1;
						}
					}
				}
			}
			else {
				cout << "Unable due to overlapping";
			}

		}
	}
	
	return 0;
}