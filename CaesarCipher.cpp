#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void enkripsi()
{
	string plaintext, ciphertext;
	int i, k;
	char c;
	
	cout <<"\t\t\t\t\t\t KETIK PESAN : ";
	cin.ignore(); getline(cin, plaintext);
	cout <<"\t\t\t\t\t\t Masukkan Jumlah Pergeseran (0-25) : ";cin>>k;
	ciphertext = " ";
	
	for (i=0; i<plaintext.length();i++)
	{
		c = plaintext[i];
		if(isalpha(c))
		{
			c = toupper(c);
			c = c - 65;
			c = (c + k) % 26;
			c = c + 65;
		}
		ciphertext = ciphertext + c;
	}
	cout <<"\t\t\t\t\t\t Ciphertext = "<<ciphertext<<endl;
}

void dekripsi()
{
	string plaintext, ciphertext;
	int i, k;
	char c;
	
	cout <<"\t\t\t\t\t\t Ketik Ciphertext : ";
	cin.ignore(); getline(cin, ciphertext);
	cout <<"\t\t\t\t\t\t Masukkan Jumlah Pergeseran (0-25) : ";cin>>k;
	plaintext = " ";
	
	for (i=0; i<ciphertext.length(); i++)
	{
		c = ciphertext[i];
		if(isalpha(c))
		{
			c = toupper(c);
			c = c - 65;
			
			if(c - k < 0)
			{c= 26 + (c-k);}
			
			else
			{
				c = (c - k) % 26 ;
				c = c + 65 ;
				c = tolower(c);
			}
		}
		plaintext = plaintext + c;	
	}
	cout <<"\t\t\t\t\t\t Plaintext = "<<plaintext<<endl;
}


int main()
{
	int pil, ulang;
	bool stop;
	stop = false;
	
	system("color F0 ");
	int a;
	for(a=1; a<=49; a++)
	{gotoxy(a,3); cout<<" K R I P T O G R A F I"; Sleep(60);}
	
	for(a=1; a<=52; a++) 
	{gotoxy(a,4); cout<<" KELAS 17.6C.25";}
	
	for(a=1; a<=49; a++)
	{gotoxy(a,5); cout<<" 1. M Abizar F (17190979)";}
	
	for(a=1; a<=49; a++)
	{gotoxy(a,6); cout<<" 2. Arip Budiman ()";}
	
	for(a=1; a<=49; a++)
	{gotoxy(a,7); cout<<" 3. M Ihsan ()";}
	
	for(a=1; a<=49; a++)
	{gotoxy(a,8); cout<<" 4. Dwi Nurmala S ()";;}
	
	for(a=1; a<=49; a++)
	{gotoxy(a,9); cout<<" 5. Trianggi S ()"<<endl;}
	
	ulang:
	while (!stop)
	{
		system("color F0 ");
		cout<<endl;
		cout<<"\t\t\t\t\t\t\t Menu : "<<endl;
		cout<<"\t\t\t\t\t\t 1. Enkripsi"<<endl;
		cout<<"\t\t\t\t\t\t 2. Dekripsi"<<endl;
		cout<<"\t\t\t\t\t\t 3. Selesai"<<endl;
		cout<<"\t\t\t\t\t\t Pilih Menu : "; cin>>pil;
		
		switch(pil)
		{
			case 1: 
			enkripsi();
			break;
			
			case 2: 
			dekripsi();
			break;
			
			case 3:
			system("color DF");
			cout<<endl<<"\t\t\t\t\t :) TERIMA KASIH TELAH MENGGUNAKAN PROGRAM KAMI :)"; 
			stop=true;  
			break;
			
			default:
			system("color CF");
			cout<<"\n\t\t\t\t\t\t Pilihan Anda Tidak Ada  \n\t\t\t\t\t  Silahkan Masukkan Pilihan Kembali";
			getch();
			system("cls");
		}
		goto ulang;
	}
}


















