#define TXT 1024
#define WORD 30
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/////////////////////1////////////////////////
char* place(char ch[], int i , int j){
    char* str=(char*)malloc(TXT + 1);
    int g=0;
    for (int k = i; k <= j; k++){
        str[g] = ch[k];
        g++;
    }
    return str;
}

int culcSUM(char arr[], int len) {
    int sum= 0;
    for (int i=0; i < len; i++) {
        if(arr[i] <= 90 && arr[i] >= 65){
            sum += arr[i]-'A'+ 1;
        }
        else if (arr[i] <= 122 && arr[i] >= 97){
	        sum += arr[i]-'a'+1;
	    }
    }
    return sum;
}


void GematriaSequences(char *text, char *word){
    int x=0;
    for (int i = 0; i < strlen(text); i++){
        for (int j = 0; j < strlen(text); j++){
            int temp1= culcSUM(word , strlen(word));
            int temp2 = culcSUM(place(text, i ,j),strlen(place(text, i ,j)));
            if (temp1==temp2){ 
                char ans[strlen(place(text, i ,j))];
                strcpy(ans,place(text, i ,j));
                if(((ans[0] <= 90 && ans[0] >= 65) || (ans[0] <= 122&& ans[0] >= 97))&& ((ans[strlen(ans)-1] <= 90 && ans[strlen(ans)-1] >= 65) ||
                 (ans[strlen(ans)-1] <= 122&& ans[strlen(ans)-1] >= 97))){
                    x++;
                    if (x>1){
                        printf("~");
                    }
                    for (int i = 0; i <strlen(ans); i++){
                        printf("%c",ans[i]); 
                    }
                }
            }
        }
    }
}


/////////////////////////2///////////////////////////////
int helpAtbash (char *w, char *t){
    if(strlen(w) != strlen(t)){
       return 0;
   }

    int i = 0 ,j = 0;
    while(i < strlen(w) && j < strlen(t)){
        if(w[i] == ' '){
         i++;
        }
        else{
            if(t[j] != w[i]){
              return 0;
            }
            j++;
            i++;
      }
    }
    if (j < strlen(t)){
       return 0;
    }
    return 1;
}


 
 void AtbashSequences(char *text, char *word){
   
    for(int i = 0; i < strlen(word); i++){
       if (word[i] >= 'a' && word[i] <= 'z'){
            word[i] = 'z'- word[i] + 'a';
       }

        if (word[i] >= 'A' && word[i] <= 'Z'){
            word[i] = 'Z'- word[i] + 'A';
       }  
     }

    char word_c[strlen(word)];
    strcpy(word_c,word);
    int end=strlen(word_c)-1;
    char temp;
    for (int i=0; i <= end/2; ++i){
        temp= word_c[i];
        word_c[i]= word_c[end-i];
        word_c[end-i]=temp;
    }
     
     int x=0;
    for (int i = 0; i < strlen(text)-1; i++){
        for (int j = 0; j < strlen(text)-1; j++){
            int temp1 = helpAtbash(place(text, i ,j), word);
            int temp2 = helpAtbash(place(text, i ,j), word_c);
            if ((temp1 == 1 || temp2 == 1)){
                char ans[strlen(place(text, i ,j))];
                strcpy(ans,place(text, i ,j));
                if((ans[strlen(ans)-1] != ' ') && (ans[0]!=' ')){
                    x++;
                     if (x>1){
                        printf("~");
                    }
                    int k = 0;
                    while (k < strlen(ans)){
                        printf("%c",ans[k]);
                        k++; 
                    }
                   
                }
            }
        }
    }
}

///////////////////////////3/////////////////////////////
void swap(char *s1 ,char *s2){
    char temp= *s1;
    *s1  = *s2;
    *s2= temp;
}

int anagramHelp(char* t,char* w) {
    if(strlen(t)<strlen(w)){
        return 0;
    }
    
    //bubble sort
    for (int i = 0; i < strlen(t)-1; i++) {
        for (int j =0; j < strlen(t)-i-1; j++) { 
            if (t[j] > t[j+1]) {
                swap(&t[j], &t[j+1]);
            }
        }
    }
    
    //bubble sort
    for (int i = 0; i < strlen(w)-1; i++) {
        for (int j = 0; j < strlen(w)-i-1; j++) {
            if (w[j] > w[j+1]) {
                swap (&w[j], &w[j+1]);
            }
        }
    }

    int i = 0 ,j = 0; 
    while(i < strlen(t) && j < strlen(w)){
        if(t[i]==' '){
            i++;
        }
        else{
            if(w[j] != t[i]){
                return 0;
            }
            j++;
            i++;
        }
    }
    if (i < strlen(t)){
        return 0;
    }
    if (j < strlen(w)){
        return 0;
    }

    return 1;
}

void AnagramSequences(char *text, char *word){
    int x=0;
    for (int i = 0; i < strlen(text); i++){
        for (int j = 0; j < strlen(text); j++){
            int temp= anagramHelp(place(text, i ,j), word);
            if (temp==1){  
                char ans[strlen(place(text, i ,j))];
                strcpy(ans,place(text, i ,j));
                if((ans[strlen(ans)-1]!=' ') && (ans[0]!=' ') ){
                    x++;
                    if(x>1){
                        printf("~");  
                    }

                    for (int i = 0; i <strlen(ans); i++){
                        printf("%c", ans[i]);
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////
int main(){
    char text[TXT];
    char word[WORD];   

    char tempWord[WORD];
    char tempText[TXT];

    scanf("%s", tempWord);

    //Start checking if the word of the input is valid.
    for(int i = 0; i < strlen(tempWord) + 1; i++){
        if(tempWord[i] == '\\'){
            if(tempWord[i+1] == 't' || tempWord[i+1] == 'n'){
                break;
            }
            else{ 
                word[i] = tempWord[i];
            }
        }
        else{
            word[i] = tempWord[i];
        }
    }
 
    scanf("%[^~]s", tempText);

    //Start checking if the text of the input is valid.
    for(int i = 0; i < strlen(tempText) + 1; i++){
        if(tempText[i] == '~'){
            break;
        }else{
            text[i] = tempText[i];
        }
        text[i] = tempText[i];
    }

    char word_2[WORD];
    char text_2[TXT];
    strcpy(word_2,word);
    strcpy(text_2,text);
    printf("Gematria Sequences: ");
    GematriaSequences(text,word);
    printf("\n");
    printf("Atbash Sequences: ");
    AtbashSequences(text_2, word_2);
    printf("\n");
    printf("Anagram Sequences: ");
    AnagramSequences(text, word);
    return 0;
    }