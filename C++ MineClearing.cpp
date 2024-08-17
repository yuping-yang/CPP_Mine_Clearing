#include<iostream>  
#include<time.h>  
#include<stdio.h>  
#include<graphics.h>
#include<mmsystem.h>  
#include <windows.h>
#define N 9  // Number of grids  
#define M 64  // Image size
#define P 16  // Number of grids  
#define Q 40  // Number of grids  
#define W1 30  // Number of grids  
#define W2 16  // Number of grids  
#define H 30  // Number of grids  
using namespace std;  

IMAGE image[90]; //set image
int boom=0;
int booom=0;
int map[N][N]; // Store thunder -1 means thunder
int map2[P][P];
int map3[W1][W2];
int gametype;  
int winner=N*N-10;
int winflag=0;
void start();    
void normalModel(); //10 thunders 
void highModel(); //40 thunders  
void superhighModel(); //99 thunders 
void draw(); 
void draw2();
void draw3();
void draw4();
void num(int n);
int play();
int play2();
int play3();
void fullempty(int x,int y); // Recursive Operations 
void fullempty2(int x,int y);
void fullempty3(int x,int y);

void  main() {  
    
    start();  
    if (gametype== 0) {  
        normalModel();  
    }  

	else if (gametype== 1) {  
        highModel();  
    } 

    else {  
        superhighModel();  
    }  

    closegraph();  
}  
void start() {
	initgraph(N*M, N*M);
	loadimage(&image[79], L"resource/left.jpg",160,60); // Icon for the number of remaining mines
   	loadimage(&image[0], L"resource/0.jpg",M,M);  
  	loadimage(&image[1], L"resource/1.jpg", M, M);  
   	loadimage(&image[2], L"resource/2.jpg", M, M);  
  	loadimage(&image[3], L"resource/3.jpg", M, M);  
 	loadimage(&image[4], L"resource/4.jpg", M, M);  
  	loadimage(&image[5], L"resource/5.jpg", M, M);  
   	loadimage(&image[6], L"resource/6.jpg", M, M);  
   	loadimage(&image[7], L"resource/7.jpg", M, M);  
    	loadimage(&image[8], L"resource/8.jpg", M, M);    
	loadimage(&image[9], L"resource/boom.jpg", M, M); 
    	loadimage(&image[10], L"resource/flag.jpg", M, M);  
    	loadimage(&image[11], L"resource/back.jpg", N*M, N*M);  
    	loadimage(&image[12], L"resource/empty.jpg", M, M);  
	
	loadimage(&image[13], L"resource/type1.jpg",200,50);
	loadimage(&image[14], L"resource/type2.jpg",200,50);
	loadimage(&image[15], L"resource/exit.jpg",160,60);
	loadimage(&image[16], L"resource/type3.jpg",200,50);	
	loadimage(&image[17], L"resource/help.jpg",160,60); 
	loadimage(&image[18], L"resource/tip.jpg",N*M,N*M);
	loadimage(&image[19], L"resource/goback.jpg",200,50); 
	loadimage(&image[20], L"resource/0.jpg",Q,Q);  
    	loadimage(&image[21], L"resource/1.jpg",Q, Q);  
    	loadimage(&image[22], L"resource/2.jpg",Q, Q);  
    	loadimage(&image[23], L"resource/3.jpg",Q,Q);  
	loadimage(&image[24], L"resource/4.jpg",Q, Q);  
	loadimage(&image[25], L"resource/5.jpg",Q, Q);  
	loadimage(&image[26], L"resource/6.jpg",Q, Q);  
	loadimage(&image[27], L"resource/7.jpg",Q, Q);  
	loadimage(&image[28], L"resource/8.jpg", Q, Q);  
	loadimage(&image[29], L"resource/boom.jpg", Q, Q);  
	loadimage(&image[30], L"resource/flag.jpg", Q, Q);   
    	loadimage(&image[32], L"resource/empty.jpg", Q, Q); 

	loadimage(&image[40], L"resource/0.jpg",H,H);  
    	loadimage(&image[41], L"resource/1.jpg",H,H);  
    	loadimage(&image[42], L"resource/2.jpg",H,H);  
    	loadimage(&image[43], L"resource/3.jpg",H,H);  
	loadimage(&image[44], L"resource/4.jpg",H,H);   
	loadimage(&image[45], L"resource/5.jpg",H,H);  
	loadimage(&image[46], L"resource/6.jpg",H,H); 
	loadimage(&image[47], L"resource/7.jpg",H,H);   
	loadimage(&image[48], L"resource/8.jpg", H,H); 
	loadimage(&image[49], L"resource/boom.jpg", H,H); 
	loadimage(&image[50], L"resource/flag.jpg",H,H);   
    	loadimage(&image[52], L"resource/empty.jpg", H, H);     
	loadimage(&image[60], L"resource/ban.jpg",5*M,P*M); 
	loadimage(&image[61], L"resource/9.jpg", M, M);
	     
	loadimage(&image[80], L"resource/b0.jpg",M,M);  
    	loadimage(&image[81], L"resource/b1.jpg", M, M);  
    	loadimage(&image[82], L"resource/b2.jpg", M, M);  
    	loadimage(&image[83], L"resource/b3.jpg", M, M);  
    	loadimage(&image[84], L"resource/b4.jpg", M, M);  
    	loadimage(&image[85], L"resource/b5.jpg", M, M);  
    	loadimage(&image[86], L"resource/b6.jpg", M, M);  
    	loadimage(&image[87], L"resource/b7.jpg", M, M);  
    	loadimage(&image[88], L"resource/b8.jpg", M, M);  
    	loadimage(&image[89], L"resource/b9.jpg",M,M);

	putimage(0, 0, &image[11]); 
	putimage(180,200,&image[13]);
	putimage(180,280,&image[14]);	
	putimage(180,360,&image[16]); 
	putimage(360,430,&image[15]);
	putimage(80,430,&image[17]); 

    MOUSEMSG msg = { 0 };  
	 while (1) { 
		 msg = GetMouseMsg();  
        switch (msg.uMsg) {  
        case WM_LBUTTONDOWN:  
            if (msg.x > 180 && msg.x < 380 && msg.y >200 && msg.y < 250){  
                gametype = 0;
				normalModel();
                return;  
            }  
            else if (msg.x > 180 && msg.x < 380 && msg.y >280 && msg.y < 330) {  
                gametype = 1;
				highModel();
                return;  
            }  
		    else if (msg.x > 180 && msg.x < 380 && msg.y >360 && msg.y < 410) {  
                gametype = 2; 
				superhighModel();
                return;  
            }  
			 else if (msg.x > 80 && msg.x < 240 && msg.y >430 && msg.y < 490) {  
                 draw4();
            } 
            else if (msg.x > 360 && msg.x < 520 && msg.y >430 && msg.y <490) {  
                exit(0);  
            }  
        }  
    }  
}  
void normalModel() {  
	initgraph((N+5)*M, N*M); 
    while (1) {  
        cleardevice();         
		int tag = 0;  
		winner=N*N-10;
        HWND hWnd = GetHWnd();  
        int x, y;  
        srand((unsigned)time(NULL));  
        for(int i = 0; i < N ; i++) {  
           for(int j = 0; j < N; j++) {  
                map[i][j] = 0;  
           }  
       }  
		for(int i=0;i<10;)
		{
			x=rand()%10;
	        y=rand()%10;
			x=x*8/9;
			y=y*8/9;
			if(map[x][y]==0)
			{
				map[x][y]=-1;
				i++;
		    }
		}
        for (int i = 0; i <N; i++) {   
            for (int j = 0; j <N; j++) {  
                if (map[i][j] == -1) {  
                    for (int m = i - 1; m <= i + 1; m++) {
       			for (int n = j - 1; n <= j + 1; n++) {  
                           if(m>=0&&m<N&&n>=0&&n<N&&map[m][n]!=-1)
				{
					map[m][n]++;
				}   
                        }  
                    }  
                }  
            }  
        }    
		while(1)
		{
			num(booom);
			draw(); 
			
            tag = play();  
            if (tag == -1) {  
                draw();
				boom=0;
				int idlose=MessageBox(hWnd, L"Restart", L"Fail", MB_OKCANCEL);
                if (idlose == IDOK){}
				else if(idlose==IDCANCEL)  exit(0);
					break;  
            }  
            if (winner==0) {  
                draw();
				boom=0;
				int idwin=MessageBox(hWnd, L"Play again£¿", L"Win!!",  MB_OKCANCEL);
				if(idwin==IDOK)
				{
					start();
				}
				else if(idwin==IDCANCEL)  exit(0);
					break;    
            }  
		}       
    }  
}  

void highModel() { 
   initgraph(P*Q+5*M,P*Q);
  // putimage(P*Q, 0, &image[60]); 
   while (1) {  
        cleardevice();         
		int tag = 0;  
		winner=P*P-40;
        HWND hWnd = GetHWnd();  
        int x, y;  
        srand((unsigned)time(NULL));  
        for(int i = 0; i < P ; i++) {  
           for(int j = 0; j < P; j++) {  
                map2[i][j] = 0;  
           }  
       }  
		for(int i=0;i<40;)
		{
			x=rand()%10;  
	        y=rand()%10;
			x=x*16/9;
			y=y*16/9;
			if(map2[x][y]==0)
			{
				map2[x][y]=-1;
				i++;
		    }
		}
        for (int i = 0; i <P; i++) {   
            for (int j = 0; j <P; j++) {  
                if (map2[i][j] == -1) {  
                    for (int m = i - 1; m <= i + 1; m++) {
for (int n = j - 1; n <= j + 1; n++) {  
                           if(m>=0&&m<P&&n>=0&&n<P&&map2[m][n]!=-1)
				{
					map2[m][n]++;
				}   
                        }  
                    }  
                }  
            }  
        }    
		while(1)
		{
			num(booom);
			draw2(); 
            tag = play2();  
            if (tag == -1) {  
                draw2();
				boom=0;
				int idlose=MessageBox(hWnd, L" Restart ", L"Fail", MB_OKCANCEL);
                if (idlose == IDOK){}
				else if(idlose==IDCANCEL)  exit(0);
					break;  
            }  
            if (winner==0) {  
                draw2();
				boom=0;
				int idwin=MessageBox(hWnd, L"Play again?", L"Win!!",  MB_OKCANCEL);
				if(idwin==IDOK){
				start();
				}
				else if(idwin==IDCANCEL)  exit(0);
					break;    
            }  
		}       
    }  
}  



void superhighModel() { 
   initgraph(W1*H+5*M,W2*H);
  // putimage(W1*H, 0, &image[60]); 
   while (1) {  
        cleardevice();         
		int tag = 0;  
		winner=W1*W2-99;
        HWND hWnd = GetHWnd();  
        int x, y;  
        srand((unsigned)time(NULL));  
        for(int i = 0; i < W1 ; i++) {  
           for(int j = 0; j < W2; j++) {  
                map3[i][j] = 0;  
           }  
       }  
		for(int i=0;i<99;)
		{
			x=rand()%30;    
	        y=rand()%16;
			if(map3[x][y]==0)
			{
				map3[x][y]=-1;
				i++;
		    }
		}

        for (int i = 0; i <W1; i++) {   

		for (int j = 0; j <W2; j++) {  
                if (map3[i][j] == -1) {  
                    for (int m = i - 1; m <= i + 1; m++) {  
                        for (int n = j - 1; n <= j + 1; n++) {  
                           if(m>=0&&m<W1&&n>=0&&n<W2&&map3[m][n]!=-1)
				{
					map3[m][n]++;
				}   
                        }  
                    }  
                }  
            }  
        }    
		while(1)
		{
			num(booom);
			draw3(); 
			
            tag = play3();

            if (tag == -1) {  
                draw3();
				boom=0;
				int idlose=MessageBox(hWnd, L"Restart", L"Fail", MB_OKCANCEL);
                if (idlose == IDOK){}
				else if(idlose==IDCANCEL)  exit(0);
					break;  
            }  
            if (winner==0) {  
                draw3();
				boom=0;
				int idwin=MessageBox(hWnd, L"Play again?", L"Win!!",  MB_OKCANCEL);
				if(idwin==IDOK){}
				else if(idwin==IDCANCEL)  exit(0);
					break;    
            }  
		}       
    }  
}  




void draw() {  
   for (int i = 0; i <N;i++) {  
       for (int j =0; j < N; j++) {  
		    if (map[i][j]<9) putimage(i*M,j*M, &image[12]);
			else
            switch (map[i][j]-10)  
            {  
            case -1:putimage(i*M, j*M, &image[9]); break;  //boom
            case 0:putimage(i*M, j*M, &image[0]); break;  
            case 1:putimage(i*M, j*M, &image[1]); break;  
            case 2:putimage(i*M, j*M, &image[2]); break;  
            case 3:putimage(i*M, j*M, &image[3]); break;   
            case 4:putimage(i*M, j*M, &image[4]); break;  
            case 5:putimage(i*M, j*M, &image[5]); break;  
            case 6:putimage(i*M, j*M, &image[6]); break;  
            case 7:putimage(i*M, j*M, &image[7]); break;  
            case 8:putimage(i*M, j*M, &image[8]); break; 

            case 19:putimage(i*M, j*M, &image[10]); break;  
            case 20:putimage(i*M, j*M, &image[10]); break;  
            case 21:putimage(i*M, j*M, &image[10]); break;  
            case 22:putimage(i*M, j*M, &image[10]); break;  
            case 23:putimage(i*M, j*M, &image[10]); break;  
            case 24:putimage(i*M, j*M, &image[10]); break;  
            case 25:putimage(i*M, j*M, &image[10]); break;  
            case 26:putimage(i*M, j*M, &image[10]); break;  
            case 27:putimage(i*M, j*M, &image[10]); break;  
            case 28:putimage(i*M, j*M, &image[10]); break;  
            }  
        }  
    }  

				
}  

void draw2() {  
   for (int i = 0; i <P;i++) {  
       for (int j =0; j < P; j++) {  
		   if (map2[i][j]<9) putimage(i*Q,j*Q, &image[32]);//empty
			else
            switch (map2[i][j]-10)  
            {  
            case -1:putimage(i*Q, j*Q, &image[29]); break;  //boom
            case 0:putimage(i*Q, j*Q, &image[20]); break;  
            case 1:putimage(i*Q, j*Q, &image[21]); break;  
            case 2:putimage(i*Q, j*Q, &image[22]); break;  
            case 3:putimage(i*Q, j*Q, &image[23]); break;   
            case 4:putimage(i*Q, j*Q, &image[24]); break;  
            case 5:putimage(i*Q, j*Q, &image[25]); break;  
            case 6:putimage(i*Q, j*Q, &image[26]); break;  
            case 7:putimage(i*Q, j*Q, &image[27]); break;  
            case 8:putimage(i*Q, j*Q, &image[28]); break; 

            case 19:putimage(i*Q, j*Q, &image[30]); break;  //flag
            case 20:putimage(i*Q, j*Q, &image[30]); break;  
            case 21:putimage(i*Q, j*Q, &image[30]); break;  
            case 22:putimage(i*Q, j*Q, &image[30]); break;  
            case 23:putimage(i*Q, j*Q, &image[30]); break;  
            case 24:putimage(i*Q, j*Q, &image[30]); break;  
            case 25:putimage(i*Q, j*Q, &image[30]); break;  
            case 26:putimage(i*Q, j*Q, &image[30]); break;  
            case 27:putimage(i*Q, j*Q, &image[30]); break;  
            case 28:putimage(i*Q, j*Q, &image[30]); break;  
            }  
        }  
    }  

}  



void draw3() {  
   for (int i = 0; i <W1;i++) {  
       for (int j =0; j < W2; j++) {  
		   if (map3[i][j]<9) putimage(i*H,j*H, &image[52]);//empty
			else
            switch (map3[i][j]-10)  
            {  
            case -1:putimage(i*H, j*H, &image[49]); break;  //boom
            case 0:putimage(i*H, j*H, &image[40]); break;  
            case 1:putimage(i*H, j*H, &image[41]); break;  
            case 2:putimage(i*H, j*H, &image[42]); break;  
            case 3:putimage(i*H, j*H, &image[43]); break;   
            case 4:putimage(i*H, j*H, &image[44]); break;  
            case 5:putimage(i*H, j*H, &image[45]); break;  
            case 6:putimage(i*H, j*H, &image[46]); break;  
            case 7:putimage(i*H, j*H, &image[47]); break;  
            case 8:putimage(i*H, j*H, &image[48]); break; 

            case 19:putimage(i*H, j*H, &image[50]); break;  //flag
            case 20:putimage(i*H, j*H, &image[50]); break;  
            case 21:putimage(i*H, j*H, &image[50]); break;  
            case 22:putimage(i*H, j*H, &image[50]); break;  
            case 23:putimage(i*H, j*H, &image[50]); break;  
            case 24:putimage(i*H, j*H, &image[50]); break;  
            case 25:putimage(i*H, j*H, &image[50]); break;  
            case 26:putimage(i*H, j*H, &image[50]); break;  
            case 27:putimage(i*H, j*H, &image[50]); break;  
            case 28:putimage(i*H, j*H, &image[50]); break;  
            }  
        }  
    }  

}  

void draw4() {  
  putimage(0, 0, &image[18]);  
  putimage(190, 450, &image[19]); //200x50 size
   MOUSEMSG msg = { 0 };  
	 while (1) { 
        msg = GetMouseMsg();  
        switch (msg.uMsg) {  
        case WM_LBUTTONDOWN:  
            if (msg.x > 190 && msg.x < 390 && msg.y >450 && msg.y < 500) {  
                start();  
                return;  
            }  
		}
    }  
}

int play() {  
    MOUSEMSG msg = {0};  
    while (1) {  
        msg = GetMouseMsg();  
        switch (msg.uMsg)  
        {  
        case WM_LBUTTONDOWN:  
            if (map[msg.x / M][msg.y / M] == 0) {    // It is not a mine and there are no mines around it  
              fullempty(msg.x/M , msg.y/M );  
            }  
            else if (map[msg.x / M][msg.y / M] < 9) {    // It is not a mine but there are mines around it
                map[msg.x / M][msg.y / M] += 10;     // +10 based on the number of mine marks around you
				winner--;
            }  
            if (map[msg.x / M][msg.y / M] == 9) {  
                return -1;  
            }  
        break;  
        case WM_RBUTTONDOWN:  
            if (map[msg.x / M][msg.y / M] <9) {  
                map[msg.x / M][msg.y / M] += 30;  // Right click to mark
				boom++;
           }  
            else if (map[msg.x / M][msg.y / M] >28) {  
                map[msg.x / M ][msg.y / M] -= 30;  // Right click to unmark
				boom--;
            }  
            break;  
        }  
		booom=10-boom;
        return 0;  
    }  
}  

int play2() {  
    MOUSEMSG msg = {0};  
    while (1) {  
        msg = GetMouseMsg();  
        switch (msg.uMsg)  
        {  
        case WM_LBUTTONDOWN:  
            if (map2[msg.x /Q][msg.y /Q] == 0) {  
                fullempty2(msg.x/Q , msg.y/Q );  
            }  
            else if (map2[msg.x /Q][msg.y / Q]<9) {  
                map2[msg.x /Q][msg.y /Q] +=10;  
				winner--;
            }  
            if (map2[msg.x / Q][msg.y / Q] == 9) {  
                return -1;  
            }  
        break;  
        case WM_RBUTTONDOWN:  
            if (map2[msg.x /Q][msg.y /Q] <9) {  
                map2[msg.x /Q][msg.y /Q] +=30;  
				boom++;
           }  
            else if (map2[msg.x /Q][msg.y /Q] >28) {  
                map2[msg.x /Q][msg.y /Q] -= 30;  
				boom--;
            }  
            break;  
        }  
		booom=40-boom;
        return 0;  
    }  
}  




int play3() {  
    MOUSEMSG msg = {0};  
    while (1) {  
        msg = GetMouseMsg();  
        switch (msg.uMsg)  
        {  
        case WM_LBUTTONDOWN:  
            if (map3[msg.x /H][msg.y /H] == 0) {  
                fullempty3(msg.x/H , msg.y/H );  
            }  
            else if (map3[msg.x /H][msg.y / H]<9) {  
                map3[msg.x /H][msg.y /H] +=10;  
				winner--;
            }  
            if (map3[msg.x / H][msg.y / H] == 9) {  
                return -1;  
            }  
        break;  
        case WM_RBUTTONDOWN:  
            if (map3[msg.x /H][msg.y /H] <9) {  
                map3[msg.x /H][msg.y /H] +=30;  
				boom++;
           }  
            else if (map3[msg.x /H][msg.y /H] >28) {  
                map3[msg.x /H][msg.y /H] -= 30;  
				boom--;
            }  
            break;  
        }  
		booom=99-boom;
        return 0;  
    }  
}  



void fullempty(int x, int y) { // It is not a mine and there are no mines around it  

    map[x][y] +=10;//  // Clicked, it is not a mine and there are no mines around it  
	winner--;   //successfully marked one, winner minus one
    for (int i = x - 1; i <= x + 1; i++) //check the mine around
	{  
        for (int j = y - 1; j <= y + 1; j++) 
		{  
			if(i>=0&&i<N&&j>=0&&j<N)
			{
			     if (map[i][j] <9) {  
                        if (map[i][j] == 0) {  // P is not a mine and there are no mines around it  

						fullempty(i, j);  //check around P 
}  
                        else if(map[i][j]!=-1) {  // P is not a mine but there are mines around it  
                        map[i][j] += 10;  // +10 based on the number of mine marks around P
					    winner--;        // successfully marked one, winner minus one 
                       }  
			     }
            } 
        }  
   }  
}

void fullempty2(int x, int y) {    
    map2[x][y] +=10;
	winner--;  
    for (int i =x-1;i<=x+1;i++) 
    {  
        for (int j =y-1; j <= y + 1; j++) 
	{  
		 if(i>=0&&i<P&&j>=0&&j<P)
		{
			if (map2[i][j] <9) {  
                       		if (map2[i][j] == 0) {  
					fullempty2(i, j);  
                   		}  
                   		else if(map2[i][j]!=-1) {  
                       			map2[i][j] += 10;  
					winner--;
                   		}  
			}
          	 } 
    	}  
    }  
}




void fullempty3(int x, int y) {    
    map3[x][y] +=10;
	winner--;  
    for (int i =x-1;i<=x+1;i++) 
    {  
        for (int j =y-1; j <= y + 1; j++) 
	{  
		if(i>=0&&i<W1&&j>=0&&j<W2)
		{
			if (map3[i][j] <9) {  
                       		if (map3[i][j] == 0) 
				{  
					fullempty3(i, j);  
                   		}  
                   		else if(map3[i][j]!=-1) 
				{  
                       		map3[i][j] += 10;  
				winner--;
                   		}  
			}
           	} 
    	}  
    }  
}
  

	
     void num(int n){
		 int a;
		 if(n<0)a=0;
		 if(n>=0&&n<10)a=0;
		 if(n>=10&&n<20)a=1;
         if(n>=20&&n<30)a=2;
		 if(n>=30&&n<40)a=3;
		 if(n>=40&&n<50)a=4;
		 if(n>=50&&n<60)a=5;
		 if(n>=60&&n<70)a=6;
		 if(n>=70&&n<80)a=7;
		 if(n>=80&&n<90)a=8;
		 if(n>=90&&n<100)a=9;

		if(gametype==0){
			putimage(N*M, 0, &image[60]); 
			putimage((N+2)*M,100,&image[79]);
			if(n>0)
			{
			putimage((N+2)*M,200,&image[80+a]);	
		        putimage((N+3)*M,200,&image[80+(n-a*10)]);
			}

			else
			putimage((N+2)*M,200,&image[80]);
			
		}	
		if(gametype==1){
			putimage(P*Q, 0, &image[60]);
			putimage((N+2)*M,100,&image[79]);
		
			if(n>0)
			{
			putimage((N+2)*M,200,&image[80+a]);
		        putimage((N+3)*M,200,&image[80+(n-a*10)]);
			}
			else
			putimage((N+2)*M,200,&image[80]);
			
			
		}
		if(gametype==2){
			putimage(W1*H, 0, &image[60]); 
			putimage((N+6)*M,100,&image[79]);
		
			if(n>0)
			{
			putimage((N+6)*M,200,&image[80+a]);
		         putimage((N+7)*M,200,&image[80+(n-a*10)]);
			}
			else
			putimage((N+2)*M,200,&image[80]);
		
		}		
	}	
