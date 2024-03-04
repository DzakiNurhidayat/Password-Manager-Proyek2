

#include <iostream>
#include <string.h>
// #include <iostream>
// #include <fstream>
// #include <string>


using namespace std;


typedef struct {
        char username[30];
        char password[30];
    } User;
        

    void registerUser() {
        User user;
        FILE *fp = fopen("users.dat", "ab"); // Buka file dalam mode append binary

        if (fp == NULL) {
            perror("Error opening file");
            exit(1);
        }

        cout << "masukan username: ";
        cin >> user.username;
        cout << "masukan password: ";
        cin >> user.password;


        fwrite(&user, sizeof(User), 1, fp); // Tulis data pengguna ke file

        fclose(fp);
        printf("Registration successful!\n");
    }

void loginUser() {
        User user, inputUser;
        FILE *fp = fopen("users.dat", "rb"); // Buka file dalam mode read binary

        if (fp == NULL) {
            perror("Error opening file");
            exit(1);
        }

          cout << "masukan username: ";
        cin >> inputUser.username;
        cout << "masukan password: ";
        cin >> inputUser.password;


        while(fread(&user, sizeof(User), 1, fp)) {
            if(strcmp(user.username, inputUser.username) == 0 && strcmp(user.password, inputUser.password) == 0) {
                printf("Login successful!\n");
                fclose(fp);
                return;
            }
        }

        fclose(fp);
        printf("Invalid username or password!\n");
    }


int main()
{
      int option;

        printf("1. Register\n");
        printf("2. Login\n");
        printf("Enter your choic1e: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            default:
                printf("Invalid option!\n");
        }

        return 0;
    return 0;
} 

