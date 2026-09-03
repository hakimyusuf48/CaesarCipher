#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * Author: Hakim Yusuf
 * Objective: Create a Caesar Cipher in C language
 * Features: Encrypt, Decrypt and Bruteforce attack
*/

// Prototypes
int menu();
void encrypt();
void decrypt();
void bruteForce();

int main(){
  // Program will not exit unless user wants to.
  int choose;
  do{
     choose = menu();
  } while (choose != 4);
  
  return 0; 
}

int menu(){
  // Menu to choose either to encrypt, decrpt or attack the message
  int choose;
  printf("Welcome to Caesar Cipher!\n");
  printf("Menu: \n\n1. Encrypt \n2. Decrypt \n3. Bruteforce Attack \n4. Exit\nChoose: ");
  scanf("%d", &choose);
  
  // The functions will be called here
  switch (choose){
    case 1:
      encrypt();
      break;
    case 2:
      decrypt();
      break;
    case 3:
      bruteForce();
      break;
    case 4:
      break;
    default:
      printf("Something went wrong! Try Again!");
      break;
  }

  return choose;
}

void encrypt(){
  // User Input
  char message[200];
  printf("Enter message: ");
  getchar();
  fgets(message, sizeof(message), stdin);
  message[strlen(message) - 1] = '\0';

  // Uppercase
  for (int i = 0; i < strlen(message); i++){
    message[i] = toupper(message[i]);
  }

  // Swap
  int shift = 7;
  int letters = 26;
  int messageSize = strlen(message);

  for (int index = 0;  index < letters; index++){
    if(isalpha(message[index])){
      message[index] = 'A' + (message[index] - 'A' + shift) % letters;
    }
  }
  
  // Encrpted Message Output
  printf("Encrypted message: %s \n", message);
}


void decrypt(){
  // User Input
  char code[200];
  printf("Enter encrypted message:");
  getchar();
  fgets(code,sizeof(code), stdin);
  code[strlen(code) - 1] = '\0';

  // Uppercase
  for (int i = 0; i < strlen(code); i++){
    code[i] = toupper(code[i]);
  }

  // Decrption Logic
  int shift = 7;
  int letters = 26;
  int messageSize = strlen(code);

  for (int index = 0;  index < letters; index++){
    if(isalpha(code[index])){
      code[index] = 'A' + (code[index] - 'A' - shift % letters + letters) % letters;
    }
  }

  // Decrypted Message Ouput
  printf("Decrypted message: %s \n", code);
}


void bruteForce(){
  // User Input
  char code[200];
  printf("Enter encrypted message:");
  getchar();
  fgets(code,sizeof(code), stdin);
  code[strlen(code) - 1] = '\0';

  // Uppercase
  for (int i = 0; i < strlen(code); i++){
    code[i] = toupper(code[i]);
  }

  // Bruteforce Crack Logic
  int shift = 0;
  int letters = 26;
  int messageSize = strlen(code);
  
  for (int shift = 1; shift < letters; shift++){
    char temp[200];
    strcpy(temp, code);
    for (int index = 0; index < messageSize; index++){
      if(isalpha(temp[index])){
        temp[index] = 'A' + (temp[index] - 'A' - shift + letters) % letters;
      }
    }
  printf("Shift By %d: %s\n", shift, temp);
}

  // Find the Correct Message
  printf("Check which attempt above for the cracked code. \n");
}