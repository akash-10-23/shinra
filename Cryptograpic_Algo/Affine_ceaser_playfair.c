#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define MX 5    //size of Key matrix

void removeDuplicates(char str[]){
    int hash[256] = {0};      //hash table to store the ascii values
    int currIndex = 0;
    int lastUniqueIndex = 0;       //last unique index
    while(*(str+currIndex)){
    	//storing the current element
        char temp = *(str+currIndex);      
        if(0 == hash[temp]){
            hash[temp] = 1;
            
            //copy unique element to the array
            *(str+lastUniqueIndex) = temp;      
            lastUniqueIndex++;      
        }
        currIndex++;
    }
    *(str+lastUniqueIndex) = '\0';      //null character at end 
 
}

void insert_x(int pos,char a[],int size){   
    char temp[size+1];      //temp array to store the elements before the position
    for(int i=0;i<=size;i++){
      if(i<pos){           //copying the elements before the position
        temp[i]=a[i];
      }
      if(i>pos){
        temp[i]=a[i-1];    
      }
      if(i==pos)       //inserting the 'X' at the position
      {
        temp[i] = 'X';
      }
    }       
    for(int i=0;i<=size;i++){
          a[i]=temp[i];       //copying the elements back to the array
    }
}

void main() {
    int i, j, k = 0, l, m = 0, n;
    char key[MX][MX], keyminus[25], keystr[10], plain[25] = {0};      //key matrix
	char ciphertest[100];
    char alpa[26] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    };      
	fflush(stdin);
	printf("Enter the plaintext:");
    scanf("%s",&plain); 
   
    //all characters to uppercase
    for (i = 0; i < strlen(plain); i++) {
        if (plain[i] == 'j') plain[i] = 'i';
        else if (plain[i] == 'J') plain[i] = 'I';
        plain[i] = toupper(plain[i]);   
    }
    int length = strlen(plain);
    
    for(int i=0;i<length;i+=2)
   {
      if(plain[i]==plain[i+1])
      {
       insert_x(i+1,plain,length);    //insert 'X' at the position
       length++;
      }
   }
   if(length%2!=0)    //for odd length
   {
    insert_x(length,plain,length);    //insert 'X' at the end
    length++;
   }

       printf("%s\n",plain);
       printf("\n");
    printf("Enter key(K1) : ");   
   scanf("%s",&keystr);     //retriveing key
   printf("\n");
    
	removeDuplicates(keystr);     //removing the duplicates
    n = strlen(keystr);
    //convert the characters to uppertext
    for (i = 0; i < n; i++) {
        if (keystr[i] == 'j') keystr[i] = 'i';
        else if (keystr[i] == 'J') keystr[i] = 'I';
        keystr[i] = toupper(keystr[i]);       //convert the characters to uppercase
    }
  
    // store all characters except the key
    
    j = 0;
    for (i = 0; i < 26; i++) {
        for (k = 0; k < n; k++) {
            if (keystr[k] == alpa[i]) break;
            else if (alpa[i] == 'J') break;
        }
        if (k == n) {     
            keyminus[j] = alpa[i];      
            j++;
        }
    }
    
    //Key matrix construction
    k = 0;
    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (k < n)        
             {      
                key[i][j] = keystr[k];
                k++;
            } else {
                key[i][j] = keyminus[m];
                m++;
            }
            printf("%c ", key[i][j]);
        }
        printf("\n");
    }
    
    // construct diagram and convert to cipher text
  
  
  int w, x, y, z;
    for(k=0;k<length;k+=2){
      for (i = 0; i < 5; i++) {
         for (j = 0; j < 5; j++) {
            if (plain[k] == key[i][j]){//find the row
                w = i;
                x = j;
            } else if (plain[k+1] == key[i][j]) {   //find the column
                y = i;
                z = j;
           }
        }
      }
    
    if (w == y) {     
			x = (x + 1) % 5;
			z = (z + 1) % 5;
			ciphertest[k] = key[w][x];    //convert to cipher text
			ciphertest[k+1] = key[y][z];
			
    } 
    else if (x == z) {
        
			w = (w + 1) % 5;
			y = (y + 1) % 5;
			ciphertest[k] = key[w][x];
			ciphertest[k+1] = key[y][z];
        
    } 
	else {
        ciphertest[k] = key[w][z];    //if the row and column are different
		ciphertest[k+1] = key[y][x];
     }
  }
  printf("\nEncryted playfair ciphertext is: \n");
  for(int i=0;i<length;i++){
      printf("%c",ciphertest[i]);     //ciphertext
  }
  printf("\n");
 
      int Caesar_key=3;
      char Cc[100];
      for(int i=0;i<length;i++){
        Cc[i] = ciphertest[i]+3;
        if(Cc[i]>'Z') Cc[i] -=26;
      } 

      printf("\nEncryted Caesar Cipher Text: \n");
      for(int i=0;i<length;i++)
      {
          printf("%c",Cc[i]); 
      }
      printf("\n");
	 
	  int A_key_a = 7;
      int A_key_b = 5;
      char Affine[100];

      for(int i=0;i<length;i++){
        Affine[i] = (( (Cc[i]-'A')*A_key_a + A_key_b ) % 26 + 'A');
      }
      printf("\nEncryted Affline Cipher Text is: \n");

      for(int i=0;i<length;i++)
      {
          printf("%c",Affine[i]); 
      }
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\nDecrypted Affline Cipher Text is: \n");
      int inversion_A = 0;
      int f = 0;
        
        for (int i = 0; i < 26; i++)
        {
            f = (A_key_a * i) % 26;

            if (f == 1)
            {
                inversion_A = i;
            }
        }

        char Da[100];
        for(int i=0;i<length;i++){
          Da[i] = ((inversion_A * ((Affine[i]-'A') - A_key_b)) % 26 + 'A');
          if(Da[i]<'A'){
            Da[i]=Da[i]+26;   //To avoid negative numbers
          }
        }
        puts(Da);
	
	  char Dc[100];

        for(int i=0;i<length;i++){
          Dc[i] = Da[i] - 3;
           if(Dc[i]<'A'){
              Dc[i] += 26;      //To avoid negative numbers
           }
        }
        printf("\nDecryted Caesar Cipher Text: \n");
         for(int i=0;i<length;i++){
            printf("%c",Dc[i]);
       }
       printf("\n");
        
        char Dct[100];
    for(k=0;k<length;k+=2){
      for (i = 0; i < 5; i++) {
         for (j = 0; j < 5; j++) {
            if (Dc[k] == key[i][j]){    //find the row
                w = i;
                x = j;
            } else if (Dc[k+1] == key[i][j]) {
                y = i;
                z = j;
           }
        }
      }

       if (w == y) {
			x = ((x - 1) % 5+5)%5;      //convert to cipher text
			z = ((z - 1) % 5+5)%5;
			Dct[k] = key[w][x];
			Dct[k+1] = key[y][z];       //convert to cipher text
			
       } 
       else if (x == z) {
        
			w = ((w - 1) % 5+5)%5;
			y = ((y - 1) % 5+5)%5;
			Dct[k] = key[w][x];
			Dct[k+1] = key[y][z];  //for different row and column 
        
        
       } 
	   else {
            Dct[k] = key[w][z];
		    Dct[k+1] = key[y][x];
      }
  }
  printf("\nDecrypted playfair Cipher Text: \n");
   puts(Dct);     //printing the ciphertext
   printf("\n");
}
