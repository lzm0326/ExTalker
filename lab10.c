// Lab 10 ExTalker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 0  // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) ;

void draw_character(int x, int y, char use);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int i,j,q,row,col_l,stlen,index;
	int time,b_up,b_down,b_left,b_right,j_down,j_up,j_left,j_right,jb,n1,n2,n3,pre_j,pre_b;
	char* arr[20][4];
	char inf[1000];
	int len_arr[50];
	
	
	
	wordCount = readWords(wordlist, argv[1]);

      if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		for (i = 0; i< wordCount; i++) {
			printf("%s,", wordlist[i]);

			}
		printf("\n");
		}
	  //store
	  
	  //initialize window
	  initscr();
	refresh();
	  
	  
	for(i=0;i<wordCount;i++){
		arr[j][q]=wordlist[i];
		q++;
		if(q%5==0){
			j++;
			q=0;
		}
	}	
	row=j;
	col_l=wordCount%5;
	j=0;
	q=0;
	


printf("row=%d,col_l=%d",row,col_l);
// most of your code goes here. Don't forget to include the ncurses library 


	//scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, ",&time, &b_down, &b_up, &b_left, &b_right, &j_down, &j_up, &j_left, &j_right);
  
	//display
	for(i=0;i<wordCount;i++){
		
		mvprintw(j,1+15*q,"%s",wordlist[i]);
		refresh();
		q++;
		if(q%5==0){
			j++;
			q=0;
		}
	}
	
	j=0;
	q=0;
	i=0;
	mvprintw(j,q,"%c",'>');
	refresh();

	mvprintw(row+2,0,"Move joystick to select words, up botton will add space followed by selecting word");
	refresh();
	mvprintw(row+3,0,"left button will add without space,down button to delete.");
	refresh();
	
	
	while(true){
	  scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d,%d,%d,%d,%d, %d, ",&time, &b_down, &b_up, &b_left, &b_right,&jb,&n1, &j_down, &j_up, &j_left, &j_right,&n2,&n3);

	if(j_up==1&&pre_j!=1){
			mvprintw(j,15*q,"%c",' ');
			refresh();
		if(j==0){		
				mvprintw(j,15*q,"%c",'>');
				refresh();
		}
		else{	
			j--;
			i-=5;
			pre_j=1;
			mvprintw(j,15*q,"%c",'>');
			refresh();
		}	
			
	}
	else if(j_down==1&&pre_j!=2){	
			mvprintw(j,15*q,"%c",' ');
			refresh();
		if(q<=col_l&&j==row){	
			mvprintw(j,15*q,"%c",'>');
			refresh();}	
		else if(q>col_l&&j==row-1){
			mvprintw(j,15*q,"%c",'>');
			refresh();
		}	
		else{	
			j++;
			i+=5;
			pre_j=2;
			mvprintw(j,15*q,"%c",'>');
			refresh();
		}	
			
	}
	else if(j_left==1&&pre_j!=3){
			mvprintw(j,15*q,"%c",' ');
			refresh();
		if(q==0){
			mvprintw(j,15*q,"%c",'>');
			refresh();}
		else{
			q--;
			i--;
			pre_j=3;
			mvprintw(j,15*q,"%c",'>');
			refresh();
		}
			
	}
	else if(j_right==1&&pre_j!=4){
			mvprintw(j,15*q,"%c",' ');
			refresh();
		if(j<=row-1&&q==4){
			mvprintw(j,15*q,"%c",'>');
			refresh();
		}
		else if(j==row&&q==col_l-1){
			mvprintw(j,15*q,"%c",'>');
			refresh();
		}
		else{
			q++;
			i++;
			pre_j=4;
			mvprintw(j,15*q,"%c",'>');
			refresh();
		}
		
	}
	//delay of joystick
	else if(j_down!=1&&j_left!=1&&j_right!=1&&j_up!=1){pre_j=0;}	
	
	
	
	//write 		
	if(b_up==1&&pre_b!=1){
		
		int leng=strlen(wordlist[i]);
		len_arr[stlen]=leng+1;
		inf[index]=' ';
		index+=1;
		stlen++;
		
		pre_b=1;
		
		strcat(inf,wordlist[i]);
		index+=leng;
	}
	
	
	else if(b_left==1&&pre_b!=2){
		
	   int leng=strlen(wordlist[i]);
		len_arr[stlen]=leng;
		stlen++;
		
		pre_b=2;

		strcat(inf,wordlist[i]);
		index+=leng;


	
	}
	//delete
	else if(b_down==1&&pre_b!=3){
		 stlen-=1;
		// char ins[100];
		 int m;
		 //char space[50]="                  ";
		// char sp[20];
		
		 
		 int leng=len_arr[stlen];
		
		//strncpy(sp,space,leng);
			index-=leng;
			
		 pre_b=3;
		 
		// strncpy(ins,inf,index);
		// strcpy(inf,ins);
		 
		 
		 for(m=0;m<leng;m++){
			 draw_character(index+m,row+5,' ');	 
		 }
		// for(m=index+1;m<index+leng+1;m++){
		//	 inf[m]=' ';
	    // }
		// strcat(inf,space);
		
		//inf[index+leng+1]='\0';
	

	
	//mvprintw(row+5,0,"%s",inf);
	//refresh();
	

	}
	else if(jb==1){
		char empty[0]="";
		stpcpy(inf,empty);
		index=0;
		len_arr[stlen]=0;
		stlen++;
		
		
	 mvprintw(row+5,0,"%s",inf);
	 refresh();
	
	}
	
	
	else if(b_down!=1&&b_left!=1&&b_right!=1&&b_up!=1){pre_b=0;}
	

	 char ins[100];
	 strncpy(ins,inf,index);
	 stpcpy(inf,ins);
	
	
	mvprintw(row+5,0,"%s",inf);
	refresh();
}


   // endwin();
    return 0;
	}

// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) {
        int len = strlen(s) ;
        int x;
        if (len ==0) return;
        x = len-1;
        while (isspace(s[x]) && (x>=0)) {
                s[x] = '\0';
                x--;
                }
        }


// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename) {
	int numread =0;
	char line[WORDLEN];
	char *p;
	FILE* fp = fopen(filename,"r");
	while (!feof(fp)) {
		p  =fgets(line, WORDLEN, fp);
		if (!feof(fp) && p !=NULL) {
			trimws(line);
			wl[numread] = (char *)  malloc(strlen(line)+1);
			strcpy(wl[numread], line);
			numread++;
			}
		} 
	fclose(fp);
	return numread;	
	}
	void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}
