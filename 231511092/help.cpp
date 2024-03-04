#include <iostream>

using namespace std;

int main()
{
	int help, no;
	
	cout<<"Help/More info?"<<endl<<"Ketik: 1 for Yes/ 2 for No"<<endl;
	cin>>help;
	
	if (help==1)
	{
		cout<<"1. Bagaimana cara melihat list password?"<<endl<<"2. Ingin merubah password?"<<endl<<"3. Ingin menghapus password?"<<endl;
		cin>>no;
		
		cout<<endl;
		
		if (no==1)
		{
			cout<<endl<<"ketik menu saat awal masuk aplikasi dan input nomor 3 saat memilih password library"<<endl;
		}
		else
		{
			if (no==2)
			{
				cout<<"pilih menu untuk merubah password";
			}
			else
			{
				cout<<"Pilih menu untuk menghapus password";
			}
		}
	}
	else
	{
		if (help==2)
		{
			return 0;
		}
	}
}
