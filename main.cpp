#include<iostream>
#include<ctime>
#include<string>
#include<conio.h>
#include<windows.h>
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
using namespace std;



void gotoxy(int x, int y){
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} 
void map(int xpos,int ypos,int round){ 

for(int i = 0; i< round; i++){
	gotoxy(xpos,ypos+i);
	for(int j = 0;j<36;j++){	
	cout << "XX";
	}

  }
}

void getup(){
    HANDLE hout; 
    CONSOLE_CURSOR_INFO cursor;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    cursor.dwSize=1;
    cursor.bVisible=false;
    SetConsoleCursorInfo(hout, &cursor);
    system("mode con:cols=80 lines=25");
    system("cls");
 //main frame   
//top framework 
    cout<<endl<<"  "<<char(218);
    int x;
    for(x=0;x<75;x++)
    	cout<<"-";
    cout<<char(191)<<" ";

    for(x=0;x<17;x++){
        gotoxy(2,x+2);
        cout<<"|";
        gotoxy(78,x+2);
        cout<<"|"<<" ";
        
    }
    cout<<"  "<<char(192);
    for(x=0;x<75;x++)
       cout<<"-";
    cout<<char(217)<<" "; 
	

//name of game
//top framework(name of game)
	cout<<" "<<"+"; 
    for(x=0;x<21;x++)
  	  cout<<"-";
    cout<<"+"<<endl;

    cout<<" |  FIND THE TREASURE  |"<<endl;
    cout<<" "<<"+";
//under framework(name of game)
  for(x=0;x<21;x++)
  		cout<<"-";
  	cout<<"+";

//score
//top framework(score)
    gotoxy(59,20);
    cout<<"+";
    for(x=0;x<18;x++)
        cout<<"-";
    cout<<"+";

    gotoxy(59,21);
    cout<<"|  SCORE :         |";
    gotoxy(59,22);
    cout<<"|  STATUS:         |";
    gotoxy(59,23);
    
  //under framework(score)    
	cout<<"+";
    for(x=0;x<18;x++)
        cout<<"-";;
    cout<<"+";
    
//setting text in  score
    gotoxy(28,21);
    cout<<"***condition :";
    gotoxy(28,22);
    cout<<"Press 'x' to Exit";
    gotoxy(28,23);
    cout<<"Press Space to Pause and Play";
    gotoxy(10,24);
   
}
void score(int sc){
    gotoxy(69,21);
    cout<<sc*10;

}
//STATUS RETURN
void status(char *s,int c=1){
    gotoxy(69,22);
    
    int x;
    for(x=0;x<strlen(s);x++)
    	cout<<s[x];
    for(;x<8;x++)
        cout<<" ";
    
}
int main(){
    getup();
    //map(5,2,17);
	int flow,size,i,xb,yb;
    int speed,restart=1,tmp,xpos[100],ypos[100],scr;
    //scr=score point
    srand(time(0));
    while(true){
        if(restart){
            status("PLAYING",10);
            for(int k=1;k<75;k+=2)
                for(int j=0;j<17;j++){
                    gotoxy(k+3,j+2);
                    cout<<" ";
                }
            
			size=1;  /////yeah
            speed=50;
            scr=0;
            score(scr);
            //flow=LEFT;                  //first direction
            xpos[0]=20;
            for(i=0;i<size;i++){
                xpos[i]=xpos[0]-i*2;
                ypos[i]=10;
            }
            for(i=0;i<size;i++){ //first
                gotoxy(xpos[i],ypos[i]);
                //cout<<"o";             //tail at first
            }
            
			//
            for(tmp=1;true;){  //rand money
                do{
                    xb=rand()%75+3;
                }while(xb%2!=0);
                yb=rand()%17+2;
                for(i=0;i<size;i++)
                    if(xb==xpos[i] && yb==ypos[i]){
                        tmp=0; break;
                    }
                if(tmp)
                    break;
            }
                               
			gotoxy(xb,yb);
            
           cout<<"$";
           //
            restart=0;
        }
        while(!kbhit() && !restart) {  //random + plus score
            if(xpos[0]==xb && ypos[0]==yb){
                for(tmp=1;true;){
                    do{
                        xb=rand()%75+3;
                    }while(xb%2!=0);
                    yb=rand()%17+2;
                    for(i=0;i<size;i++)
                        if(xb==xpos[i] && yb==ypos[i]){
                            tmp=0; break;
                        }
                    if(tmp)
                        break;
                }
                gotoxy(xb,yb);
           
               	cout<<"$";
            
                
                scr++;
                speed-=3;
                score(scr);
            }
            //
			gotoxy(xpos[size-1],ypos[size-1]);
            for(i=size-1;i>0;i--){               
                xpos[i]=xpos[i+1];
                ypos[i]=ypos[i+1];
            }
            
			switch(flow){
                case RIGHT :xpos[i]+=2; break;
                case LEFT : xpos[i]-=2; break;
                case UP :   ypos[i]-=1; break;
                case DOWN : ypos[i]+=1; 
            }
            tmp=1;
            for(i=1;i<size;i++)
                if(xpos[i]==xpos[0] && ypos[i]==ypos[0]){
                    tmp=0;
                    break;
                }
            if(xpos[0]>76 || xpos[0]<4 || ypos[0]<2 ||ypos[0]>18)
                tmp=0;
            if(tmp){
                cout<<" ";
                gotoxy(xpos[0],ypos[0]);
                cout<<"o";                    //head at first
                gotoxy(xpos[1],ypos[1]);
              	 cout<<"";                   // tail at first
            }
            else{
               // textcolor("LIGHTRED");
                cout<<"";                      //game over head
                gotoxy(xpos[1],ypos[1]);
                cout<<"";                      //game over tail
                for(i=2;i<size;i++){
                    gotoxy(xpos[i],ypos[i]);
                    cout<<"";                   //game over middle
                }
               
                status("GameOver",12);
                //gotoxy(35,10);
                //cout << "YOU ARE DEAD";
				restart=1;
                getch();
            }
            //delay(speed);
            Sleep(speed);
        }
        
//input from keybord 
        char ch=getch();
        switch(tolower(ch)){
            case 'x' :  system("cls");
                        return 0;
            case ' ' : status("Paused"); 
                        while(true){
                           char z=getch();//*****************instead of getch
                            if(z=='x')
                                return 0;
                            if(z==' ')
                                break;
                               
                        }
                        status("Playing",10);
                        break;
            case -32: {               // run condition 
                char arrow=getch();
                if(arrow==72)
                    flow=UP;
                else if(arrow==80)
                    flow=DOWN;
                else if(arrow==75)
                    flow=LEFT;
                else if(arrow==77)
                    flow=RIGHT;
                break;
            }
        
		}
    }

}
