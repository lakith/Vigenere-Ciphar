/**
 * vigenere.c
 * 
 * S. Lakith Muthugala
 * lakith1995@gmail.com
 * 
 * Encrypt the text using vigenere ciphar
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int genarate_Key(char character_Key);
void text_Encrypt_Upper(char character_Ori,int shift_Key);
void text_Encrypt_lower(char character_Ori,int shift_Key);

int main(int argc, string argv[])
{
    
    if(argc==1 || argc>2)
    {
        printf("Usage: %s <key>\n",argv[0]);
        return 1;
    }
    
    for(int i=0,n=strlen(argv[1]);i<n;i++)
    {
        
        if  ( isalpha(argv[1][i])==0)
        {
           printf("Keyword must only contain letters A-Z and a-z\n");
           return 1;
        }
        
    }
    // create some amount of memory location in heap segment of memory
    char*originalText=(char*)malloc(100*sizeof(char));
    originalText=GetString();
    
    int j=0;
    int n2=strlen(argv[1]);
    char character_Ori,character_Key;
    int shift_Key;
    
    for(int i = 0, n = strlen(originalText); i < n; i++)
    {
        // check and reset the encryption key
        if(j==n2)
        {
            j=0;
        }
        //storing string elements in character variables
        character_Ori = originalText[i];
        character_Key = argv[1][j];
        
        shift_Key = genarate_Key(character_Key);
        
        if(isalpha(character_Ori))
        {
            j++;
            if(isupper(character_Ori))
            {
                text_Encrypt_Upper(character_Ori,shift_Key);
            }
            if(islower(character_Ori))
            {
                text_Encrypt_lower(character_Ori,shift_Key);
            }
        }
        else
        {
            printf("%c", character_Ori);
        }
        
    }
    
    printf("\n");
    
    // relese that memory crated in heap segment
    free(originalText);
    return 0;
}

/**
 * geranarate the shifting key
 * and send it to the main method
 */
int genarate_Key(char character_Key)
{
    
    int character =(int)character_Key;
    
    if(character > 64 && character < 91)
    {
        character=character-65;
        return character;
    }
    if(character > 96 && character < 123)
    {
        character=character-97;
        return character;
    }
    return 0;
}

/**
 * Encrypt the upercase letters using original letters and shifting key
 * And print it
 */
 void text_Encrypt_Upper(char character_Ori,int shift_Key)
 {
  
  int alpha = (int)character_Ori;
  
  if(alpha > 90-shift_Key)
  {
      alpha= ((alpha+shift_Key) %90)+64;
  }
  
  else
  {
      alpha= alpha+shift_Key;
  }
  
  printf("%c", (char)alpha);
}

/**
 * Encrypt the lower letters using original letters and shifting key
 * And print it
 */

void text_Encrypt_lower(char character_Ori,int shift_Key)
{
  
  int alpha = (int)character_Ori;
  
  if(alpha > 122-shift_Key)
  {
      // check the encrypt letter using shifting ket,if it is exceed the the alphabatical limit ,this will reset the encrypt letter
      alpha= ((alpha+shift_Key) %122)+96;
  }
  else
  {
      // check the encrypt letter using shifting ket, if it is not exceed the limit, this will add the shifting key to original letter
      alpha= alpha+shift_Key;
  }
  
  printf("%c", (char)alpha);
}