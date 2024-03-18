#include "test.h"

using namespace std;

int main() {
  	const int MAX_CHARACTERS = 18; 
	char userArray[MAX_CHARACTERS]; 
	
  	ifstream inputFile("output.txt"); 

  // Vector untuk menyimpan semua input
  	vector<string> allInputs;

	if (inputFile.is_open()) 
	{
    	string input;
    	while (getline(inputFile, input)) 
		{
      		allInputs.push_back(input);
    	}

    	while (true) 
		{
    		cout <<endl<< "Masukkan password (maksimum " << MAX_CHARACTERS << " karakter): ";
      		cin.getline(userArray, MAX_CHARACTERS);

      		ofstream outputFile("output.txt", ios::app); 
     	 	if (outputFile.is_open()) 
			{
        		outputFile << userArray << endl; 
        		outputFile.close();
      		} 
			else 
			{
        		cout << "Gagal membuka file." << endl;
      		}

      		int count = 0;
            int i=1;
			for (i = 0; i < allInputs.size(); i++) 
			{
  				if (allInputs[i] == userArray) 
				{
    				count++;
  				}
			}

      		cout <<endl<< "Jumlah input yang sama dengan sebelumnya: " << count << endl;

      		char answer;
      		cout <<endl<< "Masih ingin menyimpan password lain? (y/n): ";
      		cin >> answer;
      		cin.ignore(); 

      		if (answer == 'n') 
			{
        		break;
      		}
    	}

    	inputFile.close(); 
  	} 
	else 
	{
    	cout << "Gagal membuka file." << endl;
  	}
  return 0;
}
