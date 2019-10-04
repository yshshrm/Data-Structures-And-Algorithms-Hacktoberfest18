#include <cstring>
#include <cstdlib>
#include <iostream>

char polybius[5][5];
char cipher[30];
int ci=0;
int X[2], Y[2];

void start(char key[10]) {
	int x = 65, a = 0, p;
    char a_key[10];
    bool flag = true;
	a_key[0] = key[0];
	for(int i = 1, p = 1; i < 10; i++) {
        flag = true;
		for(int j = 0; j < p; j++) {
			if(key[i] == a_key[j]) {
                flag = false;
				break;
            }
		}

        if (flag)
            a_key[p++] = key[i];
	}

    // std::cout << "***" << a_key << "___" << key << "***\n";
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++, a++) {
			if(a < p)
				polybius[i][j] = a_key[a];
			else {
                i = 5;
                j = 5;
            }
		}
	}

	for(int letter = 0; letter < 26; letter++, x++) {
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				if(polybius[i][j] == x || x == 'J')
					goto b;
				else if(polybius[i][j] < 'A' || polybius[i][j] > 'Z') {
					polybius[i][j] = x;
					goto b;
				}
			}
		}

		b:;
	}

	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
            std::cout << polybius[i][j] << "\t";
		}

        std::cout << std::endl;
	}
}

void e_rule1() {
	for(int i = 0; i < 2; i++) {
		if(Y[i] == 4)
			cipher[ci++] = polybius[X[i]][0];
		else
			cipher[ci++] = polybius[X[i]][Y[i]+1];
	}
}

void e_rule2() {
	for(int i = 0; i < 2; i++) {
		if(X[i] == 4)
			cipher[ci++] = polybius[0][Y[i]];
		else
			cipher[ci++] = polybius[X[i]+1][Y[i]];
	}
}

void e_rule3() {
	cipher[ci++] = polybius[X[0]][Y[1]];
	cipher[ci++] = polybius[X[1]][Y[0]];
}

void encrypt(char sen[20], int x) {

	int p = 0;
	char en[20], encrypt[30];

	for(int i = 0; i < x; i++) {
		if(sen[i] != ' ')
			en[p++] = sen[i];
	}

    int length = p, limit = p;
	for(int i = 0, p = 0; i < limit; i++) {
		encrypt[p++] = en[i];
        std::cout << encrypt[p-1];
		if(en[i] == en[i+1]) {
			encrypt[p++] = 'X';
			length++;
		}
	}

	if(length % 2 != 0)
		encrypt[length++] = 'X';
    int q;
	for(int index = 0; index < length; index++) {
		if(index % 2 == 0)
			q = 0;
		else
			q = 1;
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				if(encrypt[index] == 'J') {
					if(polybius[i][j] == 'I') {
						X[q] = i;
						Y[q] = j;
						goto c;
					}
				}

				else if(polybius[i][j] == encrypt[index]) {
					X[q] = i;
					Y[q] = j;
					goto c;
				}
			}
		}

		c:
		if(q == 1) {
			if(X[0] == X[1])
				e_rule1();
			else if(Y[0] == Y[1])
				e_rule2();
			else
				e_rule3();
		}
	}
}

void d_rule1() {
	for(int i = 0; i < 2; i++) {
		if(Y[i] == 0)
			cipher[ci++] = polybius[X[i]][4];
		else
			cipher[ci++] = polybius[X[i]][Y[i]-1];
	}
}

void d_rule2() {
	for(int i = 0; i < 2; i++) {
		if(X[i] == 0)
			cipher[ci++] = polybius[4][Y[i]];
		else
			cipher[ci++] = polybius[X[i]-1][Y[i]];
	}
}

void d_rule3() {
	cipher[ci++] = polybius[X[0]][Y[1]];
	cipher[ci++] = polybius[X[1]][Y[0]];
}

void decrypt(char decrypt[], int length) {
	int q;
	for(int index = 0; index < length; index++) {
		if(index % 2 == 0)
			q = 0;
		else
			q = 1;
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				if(polybius[i][j] == decrypt[index]) {
					X[q] = i;
					Y[q] = j;
					goto c;
				}
			}
		}

		c:
		if(q == 1) {
			if(X[0] == X[1])
				d_rule1();
			else if(Y[0] == Y[1])
				d_rule2();
			else
				d_rule3();
		}
	}
}

int main() {
	char key[10], phrase[21];

	system("CLS");
	while(true) {
		std::cout << "Enter your Key ( less than 10 ):  ";
		std::cin >> key;
		if(strlen(key) > 10) {
			std::cout << "You exceeded key length, type again";
			std::cin.get();
		}

		else {
			start(key);
			break;
		}
	}

    int input;
    do {
        std::cout << "\nOptions:\n1.Encrypt\n2.Decrypt";
        std::cin >> input;
        if(input == 1) {
            do {
                std::cout << "\n\nEnter Phrase (less than 20):  ";
                std::cin >> phrase;
            } while (strlen(phrase) > 20);

            encrypt(phrase, strlen(phrase));
            std::cout << "Encryption Complete\n" << cipher << std::endl;
        }

        else if(input == 2) {
            do {
                std::cout << "\n\nEnter Phrase (less than 20):  ";
                std::cin >> phrase;
            } while (strlen(phrase) > 20);
            
            decrypt(phrase, strlen(phrase));
            std::cout << "Decryption Complete\n" << cipher << std::endl;
        }
    } while (input != 1 && input != 2);

	std::cout << "\nPress Any Key to Exit";
	std::cin.get();
    return 0;
}