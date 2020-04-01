#include <iostream>
	using namespace std;
	
	int main()
	{
		int dinda,tiwi,din,tiw,nda;

		tiw=0, tiwi=1, nda=0;
		//Menghitung Indeks Prestasi Semester
		cout<<"Indeks Prestasi Semester"<<endl;
		cout<<"Masukkan Jumlah Mahasiswa = ";cin>>dinda;
		cout<<endl;
		do
			{	
			cout<<"Masukkan IPS Ke"<<tiwi<<" = ";cin>>din;
				cout<<endl;
			if (din > tiw){
				tiw = din;
				nda = 0;
			}
			

			if(din == tiw){
				nda++;
			}
			
			tiwi++;	
				
			}
		while (tiwi<=dinda);
		cout<<"IPS Tertinggi =  "<< tiw <<"  Berjumlah "<< nda <<" Orang. "<<endl;
	cin.get();
}
