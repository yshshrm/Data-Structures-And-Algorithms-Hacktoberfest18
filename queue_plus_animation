/*
Ditulis oleh
Nama      : Ahmad Mufid


untuk dicompile di: Borland C++ 5.0.2

*/

#include <iostream> // cin cout
#include <conio.h> // getch
#include <windows.h> // gotoxy
// #include <stdlib.h> // system (cls)

/* void gotoxy (int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD c = {x, y};
    SetConsoleCursorPosition (h, c);
} */

// using namespace std;

int i, j, k = 0, QL[5], pdxa = 0, QS[5], depan = 0, belakang = 0, after_belakang = 1, terhapus; // menu_u: menu utama // j: prosentase // k: kelipatan 5
char menu, ulangi = 't', yakin_keluar = 't'; // yakin_keluar: agar muncul notiv salah entri

loading()
{
    gotoxy (32, 7); cout << "Loading...   0%";
    Sleep (800);

	for (i = 1; i <= 20; i++)
	{
		if (i == (1 + k))
		{
			for (j = ((k * 5) + 1); j <= (5 * i); j++)
			{
				gotoxy (45, 7); cout << j << "%";
				Sleep (20);
			}
		}
		k++;

		gotoxy ((29 + i), 8);
		cout << "\333";
	}

	Sleep (700);
	// system ("cls");
	clrscr ();
	Sleep (500);
}

q_linear();
q_sirkular();

main ()
{
	system ("COLOR 03");

    loading();

    for (i = 0; i <= 4; i++)
	{
		QL[i] = NULL;
	}
    
    for (i = 0; i <= 4; i++)
	{
		QS[i] = NULL;
	}
    
    do
	{
		cout << "Aplikasi Queue\n";
		cout << "**************\n";
		cout << "1. Sub Aplikasi Queue Linear\n";
		cout << "2. Sub Aplikasi Queue Sirkular\n";
		cout << "3. Exit\n";
		cout << "Masukkan pilihan Anda: ";
		cin >> menu;

		switch (menu)
		{
			case '1':
                cout << endl << endl;
                q_linear();
                
                ulangi = 'y';
                
                Sleep (500);
                break;
            case '2':
                cout << endl << endl;
                q_sirkular();
                
                ulangi = 'y';

                Sleep (500);
                break;
            case '3':
                cout << "Apakah Anda yakin ingin keluar? (y/t) ";
                cin >> yakin_keluar;
                if (yakin_keluar == 'y' || yakin_keluar == 'Y')
                {
                    ulangi = 't';
                }
                else if (yakin_keluar == 't' || yakin_keluar == 'T')
                {
                    ulangi = 'y';
                }
                else
                {
                    cout << "Salah entri!\n";
                    system ("pause");
                    
                    ulangi = 'y';
                }

                Sleep (500);
                break;
            default:
                cout << "Salah entri!\n";
                system ("pause");

                ulangi = 'y';
        }
        
        // cout << endl << endl;
    } while (ulangi == 'y' || ulangi == 'Y');

    clrscr ();
    gotoxy (32, 7); cout << "Sampai jumpa!";
    getch ();
}

q_linear()
{
	do
	{
		cout << "Queue Linear\n";
		cout << "************\n";
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Tampil\n";
		cout << "4. Keluar\n";
		cout << "Masukkan pilihan Anda: ";
		cin >> menu;

		switch (menu)
		{
			case '1':
				if (pdxa < 5)
				{
					cout << "Masukkan elemen ke-" << (pdxa + 1) << ": ";
					cin >> QL[pdxa];
					pdxa++;
				}
				else
				{
					cout << "Antrian sudah penuh!\n";
					system ("pause");
				}
				
				ulangi = 'y';
				break;
			case '2':
				if (pdxa > 0)
				{
					terhapus = QL[0];
					for (i = 0; i <= 3; i++)
					{
						QL[i] = QL[i+1];
					}
					QL[4] = NULL;
					cout << "Elemen pertama dengan nilai " << terhapus << " telah dihapus.\n";
					pdxa--;
					Sleep (500);
				}
				else
				{
					cout << "Antrian sudah kosong!\n";
					system ("pause");
				}
				
				ulangi = 'y';
				break;
			case '3':
				for (i = 0; i <= 4; i++)
				{
					if (QL[i] != NULL)
					{
						cout << "Elemen ke-" << (i + 1) << ": " << QL[i] << endl;
					}
					else
					{
						cout << "Elemen ke-" << (i + 1) << ": kosong\n";
					}
				}
				system ("pause");
				
				ulangi = 'y';
				break;
			case '4':
                cout << "Apakah Anda yakin ingin keluar dari Queue Linear? (y/t) ";
                cin >> yakin_keluar;

                if (yakin_keluar == 'y' || yakin_keluar == 'Y')
                {
                    ulangi = 't';
                }
                else if (yakin_keluar == 't' || yakin_keluar == 'T')
                {
                    ulangi = 'y';
                }
                else
                {
                    cout << "Salah entri!\n";
                    system ("pause");
                    
                    ulangi = 'y';
                }
                break;
			default:
				cout << "Salah entri!\n";
				system ("pause");
				
				ulangi = 'y';
		}

		cout << endl << endl;
	} while (ulangi == 'y' || ulangi == 'Y');
}

q_sirkular()
{
	do
	{
		cout << "Queue Sirkular\n";
		cout << "**************\n";
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Tampil\n";
		cout << "4. Keluar\n";
		cout << "Masukkan pilihan Anda: ";
		cin >> menu;

		switch (menu)
		{
			case '1':
				if (after_belakang != depan)
				{
					cout << "Masukkan elemen ke-" << after_belakang << ": ";
					cin >> QS[after_belakang - 1];
					
					if (depan == 0)
					{
                        belakang = depan = after_belakang;
                    }
                    else if (belakang < 5) // numpang
					{
				        belakang++;
                    }
                    else
                    {
                        belakang = 1;
                    }
					
					if (after_belakang < 5)
					{
				        after_belakang++;
                    }
                    else
                    {
                        after_belakang = 1;
                    }
				}
				else
				{
					cout << "Antrian sudah penuh!\n";
					system ("pause");
				}
				
				ulangi = 'y';
				break;
			case '2':
				if (depan != 0)
				{
					terhapus = QS[depan - 1];
					
					QS[depan - 1] = NULL;
					
					cout << "Elemen ke-" << depan << " dengan nilai " << terhapus << " telah dihapus.\n";
					
					if (depan != belakang)
					{
    					if (depan < 5)
    					{
                            depan++;
                        }
                        else
                        {
                            depan = 1;
                        }
                    }
                    else
                    {
                        depan = 0;
                        belakang = 0;
                    }

                    Sleep (500);
				}
				else
				{
					cout << "Antrian sudah kosong!\n";
					system ("pause");
				}
				
				ulangi = 'y';
				break;
			case '3':
				for (i = 0; i <= 4; i++)
				{
					if (QS[i] != NULL)
					{
						cout << "Elemen ke-" << (i + 1) << ": " << QS[i] << endl;
					}
					else
					{
						cout << "Elemen ke-" << (i + 1) << ": kosong\n";
					}
				}
				
				cout << " Depan: " << depan << endl;
				cout << " Belakang: " << belakang << endl;
				cout << " After Belakang: " << after_belakang << endl;
				
				system ("pause");
				
				ulangi = 'y';
				break;
			case '4':
                cout << "Apakah Anda yakin ingin keluar dari Queue Sirkular? (y/t) ";
                cin >> yakin_keluar;
                if (yakin_keluar == 'y' || yakin_keluar == 'Y')
                {
                    ulangi = 't';
                }
                else if (yakin_keluar == 't' || yakin_keluar == 'T')
                {
                    ulangi = 'y';
                }
                else
                {
                    cout << "Salah entri!\n";
                    system ("pause");
                    
                    ulangi = 'y';
                }
                break;
			default:
				cout << "Salah entri!\n";
				system ("pause");
				
				ulangi = 'y';
		}

		cout << endl << endl;
	} while (ulangi == 'y' || ulangi == 'Y');
}
