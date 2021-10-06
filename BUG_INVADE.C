#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <peekpoke.h>
#include <stdlib.h>
#include <string.h>		// For memset()
#include <atari.h>
#include <joystick.h> 
#include <errno.h>      
#include <atari_equates.h>

#pragma regvaraddr(on)  /* Allow taking the address
                        * of register variables
                        */
    
#define	NDX0									 0xCA
#define	NDX1									 0xCB
#define	NDX2									 0xCC
#define	NDX3									 0xCD
#define	HOLDX									 0xCE
#define	HOLDY									 0xCF
    
#define	screen_adr  				     		             0x4000

#define	PMBANK                                   0x1800
#define	VARBANK                                  0x0600

#define	SCREEN_ADDR                             0x0800
#define	GAME_SCREEN_ADDR                        0x0840 
#define TEXT_SCREEN ((unsigned char *)          (SCREEN_ADDR+0x0000))          
#define	GAME_SCREEN ((unsigned char *)          (GAME_SCREEN_ADDR+0x0000)


#define	LOCALVAR                                VARBANK + 0xE0   
#define	CHARSET_GAME                            0xA400           
#define	CHARSET_TITLE                           0xA800           
#define	TITLE_DATA                              0xAC00           
#define	SOUND_COMMANDER                         0xAE00           
#define	CHARSET_BASE                            0xA4             



#define	PLAY_SOUNDS ((unsigned char *)          (SOUND_COMMANDER + $0000))	    
#define	START_SOUND ((unsigned char *)          (SOUND_COMMANDER + $009F))      
#define	GET_NEXT_MUSIC_NOTE ((unsigned char *)  (SOUND_COMMANDER + $00F6))      
#define	STOP_SOUND ((unsigned char *)           (SOUND_COMMANDER + $0189))      
#define	SILENCE ((unsigned char *)              (SOUND_COMMANDER + $019E))      


#define pmg_memory		0x2800


#define	SPRITENUM	((unsigned char *)             (PMBANK+0x0180))
#define	SETSP0COLOR ((unsigned char *)           (PMBANK+0x0190))
#define	SETSP1COLOR ((unsigned char *)           (PMBANK+0x01A0))
#define	SETSPWIDTH ((unsigned char *)            (PMBANK+0x01B0))
#define	SPRITENHOZ ((unsigned char *)            (PMBANK+0x01C0))
#define	SPRITENVRT ((unsigned char *)            (PMBANK+0x01E0))
#define	SPHOZNEXT  ((unsigned char *)            (PMBANK+0x01F0))
#define	SCREEN_LINE_ADDR_LOW ((unsigned char *)	 (PMBANK+0x0000))
#define	SCREEN_LINE_ADDR_HIGH ((unsigned char *) (PMBANK+0x0020))
#define	CHARSET_ADDRESS ((unsigned char *)       0xA400

#define SPRHZ0	((unsigned char *)	            (PMBANK+0x0200)) 
#define SPRHZ1	((unsigned char *)	            (PMBANK+0x0210)) 
#define SPRHZ2	((unsigned char *)	            (PMBANK+0x0220)) 
#define SPRHZ3	((unsigned char *)	            (PMBANK+0x0230)) 
#define SPZONT  ((unsigned char *)              (PMBANK+0x0240))
#define SPZONB  ((unsigned char *)              (PMBANK+0x0250))
#define SPSRC0  ((unsigned char *)              (PMBANK+0x0260)) 
#define SPSRC1  ((unsigned char *)              (PMBANK+0x0278))
#define SPSRC2  ((unsigned char *)              (PMBANK+0x0290))
#define SPSRC3  ((unsigned char *)              (PMBANK+0x02A8))
#define SPSRC4  ((unsigned char *)              (PMBANK+0x02C0))
#define SPRITEUSE ((unsigned char *)           	(PMBANK+0x02D8))
                                            
#define MIBANK ((unsigned char *)              	(PMBANK+0x0300))
#define PMBNK0 ((unsigned char *)               (PMBANK+0x0400))
#define PMBNK1 ((unsigned char *)	              (PMBANK+0x0500))
#define PMBNK2 ((unsigned char *)               (PMBANK+0x0600))
#define PMBNK3 ((unsigned char *)	              (PMBANK+0x0700))


unsigned char DL_ADDR_SET;
unsigned char	SP;
unsigned char	STK;
unsigned char	SND;
unsigned char	QT;
unsigned char	A;
unsigned char B;
unsigned char	C;
unsigned char D;
unsigned char	E;
unsigned char	F;
unsigned char	CD;
unsigned char	ED;
unsigned char	PC;
unsigned char	SU;
unsigned char SCR_ADDR;
unsigned char	LV;
unsigned char	LOAD_AND_SET_UP();
unsigned char	H1;
unsigned char	H2;
unsigned char	H3;


int main()
    {
// TOP LOGIC LOOP'
		DL_ADDR_SET = 0;
		PMBASE = 0;
		SP = 0;
		STK = 0;
		SND = 1702;
		QT = 1741;
		C = 0;
		D = 0;
		E = 0;
		F = 0;
		CD = 0;
		ED = 0;
		PC = 0;
		SU = 0;
		SCR_ADDR = 0;
		LV = 0;
		LOAD_AND_SET_UP();
		H1 = 0;
		H2 = 0;
		H3 = 0;
  do
  {
  		DISPLAY_TITLE();
  
  		std::any BUG_TYPE Byte;
  		std::any BUG_XPOS WORD;
  		std::any BUG_YPOS WORD;
  		std::any BUG_XDIR WORD;
  		std::any BUG_YDIR WORD;
  		std::any BUG_DATA1 Byte;
  		std::any BUG_DATA2 Byte;
  		std::any BUG_STATUS Byte;
  		BUG_INDEX = 0;
  
  		DRAW_FIELD();
  		G1 = 0;
  		A = 19;
  		B = 22;
  		C1 = 0;
  		E1 = 0;
  		POKE(704,30);
  		Z = USR(1561); //Z=USR(1560) Plus 1 to bypass first pull from stack
  		DEG;
  		LV = 1;
  		POKE(PMBASE+512,3);
  		memmove( PMBASE+512,PMBASE+513,7);
  		POKE(PMBASE+520,0);
  		memmove( PMBASE+520,PMBASE+521,8);
  		O = 1;
  		EM = 1000;
  		SC = 0;
  		Lives = 7;
  		PRINT_SCORE();
  		CT = 1;
  		memmove( SP,PMBASE+8,8;
  
  		do
  		{
  
  				Z = USR(STK);
  				POKE(53248,PEEK(600));
  				memmove( PMBASE,PMBASE+1016 + PEEK(601),24);
  				O = !O;
  				if (C1 == 0)
  				{
  					BUG_1_0();
  				}
  				else if (C1 == 1)
  				{
  					BUG_1_1();
  				}
  				else if (C1 == 2)
  				{
  					BUG_1_2();
  				}
  				else if (C1 == 3)
  				{
  					BUG_1_3();
  				}
  				else if (C1 == 4)
  				{
  					BUG_1_4();
  				EndIf;
  				// ON C1 GOPUBLIC SUB 300,310,320,330,340                
  				// ON E1 GOPUBLIC SUB 400,410,420,430,350        
  				if (E1 == 0)
  				{
  					BUG_2_0();
  				}
  				else if (E1 == 1)
  				{
  					BUG_2_1();
  				}
  				else if (E1 == 2)
  				{
  					BUG_2_2();
  				}
  				else if (E1 == 3)
  				{
  					BUG_2_3();
  				}
  				else if (E1 == 4)
  				{
  					BUG_2_4();
  				EndIf;
  
  				if (G1 == 0)
  				{
  					if (STRIG(0) == 0)
  					{
  						G1 = 1;
  						G = ((PEEK(600) - 46) / 4);
  						H = ((PEEK(601) - 13) / 8);
  						Z = USR(PC,1,PMBASE+768);
  						//Z=USR(SND,1,SU+1536,56,1)
  						Z = USR(SND,1,56,SU + 1536,1);
  						POKE(53252,49 + G * 4);
  					EndIf;
  				}
  				else
  				{
  					//memmove( SU,PMBASE+789+8*H,16
  					H = H - 1;
  					if (H < 0)
  					{
  						G1 = 0;
  						Z = USR(PC,1,PMBASE+768);
  					}
  					else
  					{
  						POKE(53252,49 + G * 4);
  						memmove( PMBASE+512,PMBASE+789 + 8 * H,16);
  						if (PEEK(SCR_ADDR + G + 40 * H) > 0)
  						{
  							BULLET_PLAYFIELD;
  						}
  						if (PEEK(53256) + 6 > 0)
  						{
  							BULLET_HIT_BUG;
  						}
  					EndIf;
  				EndIf;
  		} while (!(Lives < 0));
  } while (true);
}
//'------------------------------

void BUG_1_0(void)
{
	memmove( SU,PMBASE+1292 + INT(8 * D),8);
	 C = C + CD / 2;
	 if (C < 0)
	 {
		C = 0.5;
		CD = 1;
		D = D + 0.5 + LV / 5;
	 EndIf;
	 if (C > 39)
	 {
		C = 39;
		CD = -1;
		D = D + 0.5 + LV / 5;
	 EndIf;
	 if (D >= 28)
	 {
		 BUG_GOT_PASSED();
	 }
	POKE(53249,46 + INT(C * 4));
	memmove( SP + 8 + 4 * O,PMBASE+1292 + INT(8 * D),4);

	//GOTOXY 15,0
	//PRINT C%


}

void BUG_1_1(void)
{
	memmove( SU,PMBASE+1292 + INT(8 * D),8);
	C = C + CD * O * INT(2 + LV / 5) * (RAND(8) * 6);
	if (C < 0)
	{
		C = 0.5;
		CD = 1;
		D = D + 1;
	 EndIf;
	 if (C > 39)
	 {
		C = 39;
		CD = -1;
		D = D + 1;
	 EndIf;

	if (D >= 28)
	{
		BUG_GOT_PASSED();
	}
	POKE(53250,46 + INT(C * 4));
	memmove( SP + 16 + 4 * (CD == 1),PMBASE+1548 + INT(8 * D),4);
}

void BUG_1_2(void)
{
	memmove( SU,PMBASE+1292 + INT(8 * D),8);
	C = C + CD / 4;
		if (C < 0 || C>39)
		{
			C = C - CD / 4;
			CD = -CD;
			D = D + 0.5 + LV / 10;
		EndIf;
	if (D >= 28)
	{
		BUG_GOT_PASSED();
	}
	P = PEEK(SCR_ADDR + INT(C + 0.25) + 40 * INT(D + 0.5));
	if (P > 0)
	{
		C = C - CD / 8;
		CD = -CD;
		D = D + 0.5 + LV / 20;
	EndIf;
	POKE(53250,46 + INT(C * 4));
	memmove( SP + 24 + 8 * (CD == -1) + 4 * O,PMBASE+1292 + INT(8 * D),4);
}

void BUG_1_3(void)
{
	memmove( SU,PMBASE+1292 + INT(8 * D),8);
	C = C + CD / 4;
	D = D + 0.125;
	if (C < 0 || C>39)
	{
		C = C - CD / 4;
		CD = -CD;
		D = D + LV / 10;
	EndIf;
	if (D >= 28)
	{
		BUG_GOT_PASSED();
	}
	P = PEEK(SCR_ADDR + INT(C + 0.25) + 40 * INT(D + 0.5));
	if (P > 0)
	{
		D = D - 0.25 + LV / 25;
		if (D >= 28)
		{
			BUG_GOT_PASSED();
		}
	EndIf;
	POKE(53250,46 + INT(C * 4));
	memmove( SP + 40 + 16 * (CD == 1) + 8 * O,PMBASE+1292 + INT(8 * D),8);
}

void BUG_1_4(void)
{
	C = C + CD / 3 - (LV / 5);
	if (C < 0 || C>39)
	{
		C1 = 0;
		POKE(53249,0);
		DEFINE_1ST_BUG();
	EndIf;
	POKE(53250,46 + INT(C * 4));
	memmove( SP + 264 + 16 * (CD == -1) + 8 * O,PMBASE+1292 + INT(8 * D),8);
}

void BUG_1_0(void)
{
	memmove( SU,PMBASE+1292 + INT(8 * D),8;
	 C = C + CD / 2;
	 if (C < 0)
	 {
		C = 0.5;
		CD = 1;
		D = D + 0.5 + LV / 5;
	 EndIf;
	 if (C > 39)
	 {
		C = 39;
		CD = -1;
		D = D + 0.5 + LV / 5;
	 EndIf;
	 if (D >= 28)
	 {
		 BUG_GOT_PASSED();
	 }
	POKE(53249,46 + INT(C * 4));
	memmove( SP + 8 + 4 * O,PMBASE+1292 + INT(8 * D),4);

	//GOTOXY 15,0
	//PRINT C%


}

void BUG_1_1(void)
{
	memmove( SU,PMBASE+1292 + INT(8 * D),8);
	C = C + CD * O * INT(2 + LV / 5) * (RAND(8) * 6);
	if (C < 0)
	{
		C = 0.5;
		CD = 1;
		D = D + 1;
	 EndIf;
	 if (C > 39)
	 {
		C = 39;
		CD = -1;
		D = D + 1;
	 EndIf;

	if (D >= 28)
	{
		BUG_GOT_PASSED();
	}
	POKE(53250,46 + INT(C * 4));
	memmove( SP + 16 + 4 * (CD == 1),PMBASE+1548 + INT(8 * D),4);
}

void BUG_1_2(void)
{
	memmove( SU,PMBASE+1292 + INT(8 * D),8);
	C = C + CD / 4;
		if (C < 0 || C>39)
		{
			C = C - CD / 4;
			CD = -CD;
			D = D + 0.5 + LV / 10;
		EndIf;
	if (D >= 28)
	{
		BUG_GOT_PASSED();
	}
	P = PEEK(SCR_ADDR + INT(C + 0.25) + 40 * INT(D + 0.5));
	if (P > 0)
	{
		C = C - CD / 8;
		CD = -CD;
		D = D + 0.5 + LV / 20;
	EndIf;
	POKE(53250,46 + INT(C * 4));
	memmove( SP + 24 + 8 * (CD == -1) + 4 * O,PMBASE+1292 + INT(8 * D),4);
}

void BUG_1_3(void)
{
	memmove( SU,PMBASE+1292 + INT(8 * D),8);
	C = C + CD / 4;
	D = D + 0.125;
	if (C < 0 || C>39)
	{
		C = C - CD / 4;
		CD = -CD;
		D = D + LV / 10;
	EndIf;
	if (D >= 28)
	{
		BUG_GOT_PASSED();
	}
	P = PEEK(SCR_ADDR + INT(C + 0.25) + 40 * INT(D + 0.5));
	if (P > 0)
	{
		D = D - 0.25 + LV / 25;
		if (D >= 28)
		{
			BUG_GOT_PASSED();
		}
	EndIf;
	POKE(53250,46 + INT(C * 4));
	memmove( SP + 40 + 16 * (CD == 1) + 8 * O,PMBASE+1292 + INT(8 * D),8);
}

void BUG_1_4(void)
{
	C = C + CD / 3 - (LV / 5);
	if (C < 0 || C>39)
	{
		C1 = 0;
		POKE(53249,0);
		DEFINE_1ST_BUG();
	EndIf;
	POKE(53250,46 + INT(C * 4));
	memmove( SP + 264 + 16 * (CD == -1) + 8 * O,PMBASE+1292 + INT(8 * D),8);
}

void BULLET_PLAYFIELD(void)
{
	memmove( PMBASE+512,PMBASE+789 + 8 * H,16; //Z=USR(QT,1)'
	G1 = PEEK(SCR_ADDR + G + 40 * H);
	G2 = PEEK(SCR_ADDR + G + 40 * (H - 1));
	G3 = PEEK(SCR_ADDR + G + 40 * (H - 2));
	G4 = PEEK(SCR_ADDR + G + 1 + 40 * H);
	G5 = PEEK(SCR_ADDR + G + 1 + 40 * (H - 1));
	G6 = PEEK(SCR_ADDR + G - 1 + 40 * H);
	G7 = PEEK(SCR_ADDR + G - 1 + 40 * (H - 1));
	Z = USR(PC,1,PMBASE+768);
	Z = USR(SND,1,24,SU + 1592,1);
	if (G1 == 67 && (G2 == 65 || G2 == 194) && G3 != 65 && G3 != 194)
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G + 40 * (H - 1),0);
	EndIf;
	if (G1 == 67 && (G2 == 65 || G2 == 194) && (G3 == 65 || G3 == 194))
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G + 40 * (H - 1),67);
	EndIf;
	if (G1 == 68 && (G4 == 69 || G4 == 70))
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G + 1 + 40 * H,68);
	EndIf;
	if (G1 == 71 && (G6 == 69 || G6 == 70))
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G - 1 + 40 * H,71);
	EndIf;
	if (G1 == 68 && G4 == 71)
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G + 1 + 40 * H,0);
	EndIf;
	if (G1 == 71 && G6 == 68)
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G - 1 + 40 * H,0);
	EndIf;
	if (G1 == 67 && ((G4 > 68 && G4 < 72) || (G6>67 && G6 < 71)))
	{
		POKE(SCR_ADDR + G + 40 * H,69 + RAND(2));
	EndIf;
	if ((G2 == 65 || G2 == 194) && ((G5 > 68 && G5 < 72) || (G7>67 && G7 < 71)))
	{
		POKE(SCR_ADDR + G + 40 * (H - 1),69 + RAND(2));
	EndIf;
	if (G1 == 67 && G4 > 68 && G4 < 72 && G6 == 0)
	{
		POKE(SCR_ADDR + G + 40 * H,68;
	EndIf;
	if (G1 == 67 && G4 == 0 && G6 > 67 && G6 < 71)
	{
		POKE(SCR_ADDR + G + 40 * H,71;
	EndIf;
	if ((G2 == 65 || G2 == 194) && G5 > 68 && G5 < 72 && G7 == 0)
	{
		POKE(SCR_ADDR + G + 40 * (H - 1),68;
	}
	if ((G2 == 65 || G2 == 194) && G7 > 67 && G7 < 71 && G5 == 0)
	{
		POKE(SCR_ADDR + G + 40 * (H - 1),71;
	}
	if ((G1 == 69 || G1 == 70) && (G4 == 69 || G4 == 70) && (G6 == 69 || G6 == 70))
	{
	  POKE(SCR_ADDR + G + 40 * H,0);
	  POKE(SCR_ADDR + G - 1 + 40 * H,71);
	  POKE(SCR_ADDR + G + 1 + 40 * H,68);
	EndIf;
	if ((G1 == 69 || G1 == 70) && (G4 == 69 || G4 == 70) && G6 == 68)
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G - 1 + 40 * H,0);
		POKE(SCR_ADDR + G + 1 + 40 * H,68);
	EndIf;
	if ((G1 == 69 || G1 == 70) && G4 == 71 && (G6 == 69 || G6 == 70))
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G - 1 + 40 * H,71);
		POKE(SCR_ADDR + G + 1 + 40 * H,0);
	EndIf;
	if ((G1 == 69 || G1 == 70) && G4 == 71 && G6 == 68)
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G + 1 + 40 * H,0);
		POKE(SCR_ADDR + G - 1 + 40 * H,0);
	EndIf;
	if (G4 + 127 > 63 && G4 + 127 < 68 && G1>67)
	{
		POKE(SCR_ADDR + G + 40 * H,0);
	}
	if (G6 + 127 > 63 && G6 + 127 < 68 && G1>67)
	{
		POKE(SCR_ADDR + G + 40 * H,0);
	}
	if (G4 + 127 > 63 && G4 + 127 < 68 && G1>67 && (G6 == 68 || G6 == 71))
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G - 1 + 40 * H,0);
	EndIf;
	if (G6 + 127 > 63 && G6 + 127 < 68 && G1>67 && (G4 == 68 || G4 == 71))
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G + 1 + 40 * H,0);
	EndIf;
	if (G4 + 127 > 63 && G4 + 127 < 68 && G1>67 && (G6 == 69 || G6 == 70))
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G - 1 + 40 * H,71);
	EndIf;
	if (G6 + 127 > 63 && G6 + 127 < 68 && G1>67 && (G4 == 69 || G4 == 70))
	{
		POKE(SCR_ADDR + G + 40 * H,0);
		POKE(SCR_ADDR + G + 1 + 40 * H,68);
	EndIf;
	if ((G2 == 65 || G2 == 194) && G1 > 67)
	{
		POKE(SCR_ADDR + G + 40 * H,67);
	EndIf;
	POKE(53278,0;
	G1 = 0;
	memmove( SU,PMBASE+789 + 8 * H,8);
	memmove( SU,PMBASE+797 + 8 * H,8);
}
//------------------------------
void DRAW_PIECE_0(void);
	  POKE(706,15;
	  SOUND 3,0,0,0;
	  Z = USR(SND,2,18,SU + 1660,2);
	  if (E1 == 1)
	  {
		  SC = SC + 2;
	  }
	  if (E1 == 2)
	  {
		  SC = SC + 10;
	  }
	  if (E1 == 3)
	  {
		  SC = SC + 5;
	  }
	  if (E1 == 4)
	  {
		  SC = SC + 50;
	  }
	  DEFINE_2ND_BUG();
	EndIf;
	POKE(53278,0);
	POKE(PMBASE+768,0);
	memmove( PMBASE+768,PMBASE+769,255);
	POKE(53252,0);
	G1 = 0;
	CT = CT + 1;
	if (CT >= 10)
	{
		LV = LV + (LV < 10);
		CT = 1;
		DRAW_FIELD();
	EndIf;
	if (SC > EM)
	{
		EM = EM + 1000;
		Lives = Lives + 1;
		Z = USR(SND,3,48,SU + 1718,2);
	EndIf;
	PRINT_SCORE();
	POKE(53278,0);
	G1 = 0;
	memmove( SU,PMBASE+789 + 8 * H,8);
	memmove( SU,PMBASE+797 + 8 * H,8);
}
//------------------------------
void BULLET_HIT_BUG(void)
{
	if (PEEK(53256) + std::to_wstring(2) == L"2")
	{
	  POKE(705,15);
	  SOUND 3,0,0,0;
	  Z = USR(SND,2,18,SU + 1660,2);
	  if (C1 == 1)
	  {
		  SC = SC + 2;
	  }
	  if (C1 == 2)
	  {
		  SC = SC + 10;
	  }
	  if (C1 == 3)
	  {
		  SC = SC + 5;
	  }
	  if (C1 == 4)
	  {
		  SC = SC + 25;
	  }
	  if (C1 == 5)
	  {
		  SC = SC + 200;
	  }
	  if (E1 == 5)
	  {
		  SOUND 0,0,0,0;
		  Z = USR(SND,0,SU + 1616,48,2);
		  SC = SC + 100;
		  E1 = 0;
		  DEFINE_1ST_BUG();
		  DEFINE_2ND_BUG();
	  }
	  DEFINE_1ST_BUG();
	EndIf;
	if (PEEK(53256) + std::to_wstring(4) == L"4")
	{
Public Sub BULLET_HIT_BUG(void);
	if (PEEK(53256) + std::to_wstring(2) == L"2")
	{
	  POKE(705,15);
	  SOUND 3,0,0,0;
	  Z = USR(SND,2,18,SU + 1660,2);
	  if (C1 == 1)
	  {
		  SC = SC + 2;
	  }
	  if (C1 == 2)
	  {
		  SC = SC + 10;
	  }
	  if (C1 == 3)
	  {
		  SC = SC + 5;
	  }
	  if (C1 == 4)
	  {
		  SC = SC + 25;
	  }
	  if (C1 == 5)
	  {
		  SC = SC + 200;
	  }
	  if (E1 == 5)
	  {
		  SOUND 0,0,0,0;
		  Z = USR(SND,0,SU + 1616,48,2);
		  SC = SC + 100;
		  E1 = 0;
		  DEFINE_1ST_BUG();
		  DEFINE_2ND_BUG();
	  }
	  DEFINE_1ST_BUG();
	EndIf;
	if (PEEK(53256) + std::to_wstring(4) == L"4")
	{
	  POKE(706,15);
	  SOUND 3,0,0,0;
	  Z = USR(SND,2,18,SU + 1660,2);
	  if (E1 == 1)
	  {
		  SC = SC + 2;
	  }
	  if (E1 == 2)
	  {
		  SC = SC + 10;
	  }
	  if (E1 == 3)
	  {
		  SC = SC + 5;
	  }
	  if (E1 == 4)
	  {
		  SC = SC + 50;
	  }
	  DEFINE_2ND_BUG();
	EndIf;
	POKE(53278,0);
	POKE(PMBASE+768,0);
	memmove( PMBASE+768,PMBASE+769,255);
	POKE(53252,0);
	G1 = 0;
	CT = CT + 1;
	if (CT >= 10)
	{
		LV = LV + (LV < 10);
		CT = 1;
		DRAW_FIELD();
	EndIf;
	if (SC > EM)
	{
		EM = EM + 1000;
		Lives = Lives + 1;
		Z = USR(SND,3,48,SU + 1718,2);
	EndIf;
	PRINT_SCORE();
	POKE(53278,0);
	G1 = 0;
	memmove( SU,PMBASE+789 + 8 * H,8);
	memmove( SU,PMBASE+797 + 8 * H,8);
}

void BUG_GOT_PASSED(void)
{
	Z = USR(SND,1,40,SU + 1678,0);
	Lives = Lives - 1;
	if (Lives < 0)
	{
		DISPLAY_GAME_OVER();
	}
	else
	{
		PRINT_SCORE;
		if (D > 25)
		{
			DEFINE_1ST_BUG();
		}
		if (F > 25)
		{
			DEFINE_2ND_BUG();
		}
	EndIf;
}
//.h file code:

//------------------------------
void PRINT_SCORE(void);
//------------------------------
void DRAW_FIELD(void);

//.cpp file code:

#include "snippet.h"

void PRINT_SCORE(void)
{
	GOTOXY 0,0;
	PRINT L"SCORE:";SC;
	GOTOXY 20,0;
	PRINT L"PASS:";Lives;
	GOTOXY 30,0;
	PRINT L"LEVEL:";LV;
}

void DRAW_FIELD(void)
{
	POKE(711,12 + 16 * (5 + RAND(5)));
	CLS #6;
	for (auto N = 3; N <= 22; N++)
	{
		for (auto M = 0; M <= 2; M++)
		{
			X = RAND(40);
			Y = RAND(2 + P) + 1;
				if (Y == 0)
				{
					DRAW_PIECE_0();
				}
				else if (Y == 1)
				{
					DRAW_PIECE_1();
				}
				else if (Y == 2)
				{
					DRAW_PIECE_2();
				EndIf;
				P = 1;
		}
	}
	DEFINE_1ST_BUG();
	DEFINE_2ND_BUG;()
}
//------------------------------
void DRAW_PIECE_0(void)
{
	POKE(SCR_ADDR + X + 40 * N,67);
	POKE(SCR_ADDR + X + 40 * (N - 1),65);
}

void DRAW_PIECE_1(void)
{
	POKE(SCR_ADDR + X + 40 * N,67);
	POKE(SCR_ADDR + X + 40 * (N - 1),194);
}

void DRAW_PIECE_2(void)
{
	X = INT(X * 0.75);
	Y = RAND(8) + 2;
	if (PEEK(SCR_ADDR + X + 40 * N) != 67)
	{
		POKE(SCR_ADDR + X + 40 * N,68);
	}
	if (PEEK(SCR_ADDR + X + Y + 40 * N) != 67)
	{
		POKE(SCR_ADDR + X + Y + 40 * N,71);
	}
	for (auto O = 1; O < Y; O++)
	{
	if (PEEK(SCR_ADDR + X + O + 40 * N) != 67)
	{
		POKE(SCR_ADDR + X + O + 40 * N,69 + RAND(2));
	}
	}
	P = 0;
	O = 0;
}

void DEFINE_1ST_BUG(void)
{
	 C1 = RAND(6) + 1;
	 POKE(PMBASE+1280,0);
	 memmove( PMBASE+1280,PMBASE+1281,255);
	 if (E1 == 5 || C1 == 6)
	 {
		 C1 = 6;
	 }
	 if (C1 == 1)
	 {
		 C = RAND(40);
		 D = 2;
		 CD = -1 + RAND(2) * 2;
		 POKE(705,48);
	 }
	 if (C1 == 2)
	 {
		 C = RAND(40);
		 D = 2;
		 CD = -1 + RAND(2) * 2;
		 POKE(705,240);
	 }
	 if (C1 == 3)
	 {
		 C = RAND(40);
		 D = 2;
		 CD = -1 + RAND(2) * 2;
		 POKE(705,70);
	 }
	 if (C1 == 4)
	 {
		 C = RAND(20) * 2;
		 D = 2;
		 CD = -1 + RAND(2) * 2;
		 POKE(705,104);
	 }
	 if (C1 == 5)
	 {
		 CD = -1 + RAND(2) * 2;
		 POKE(705,40);
		 C = 19.5 - 19.5 * CD;
		 D = 3 + RAND(12);
	 }
}

void DEFINE_2ND_BUG(void)
{
  E1 = RAND(4) + 1;
  POKE(PMBASE+1536,0);
  memmove(PMBASE+1536,PMBASE+1537,255);
  if (C1 == 6)
  {
	  E1 = 5;
	  C1 = 0;
  }
  if (E1 == 1)
  {
	  E = RAND(40);
	  F = 2;
	  ED = -1 + RAND(2) * 2;
	  POKE(706,48);
  }
  if (E1 == 2)
  {
	  E = RAND(40);
	  F = 2;
	  ED = -1 + RAND(2) * 2;
	  POKE(706,240);
  }
  if (E1 == 3)
  {
	  E = RAND(40);
	  F = 2;
	  ED = -1 + RAND(2) * 2;
	  POKE(706,70);
  }
  if (E1 == 4)
  {
	  E = 1 + RAND(18) * 2;
	  F = 0;
	  ED = -1 + RAND(2) * 2;
	  POKE(706,18);
  }
  if (E1 == 5)
  {
	  E = 10 + RAND(20);
	  F = -1;
	  ED = 4;
	  D = 2 + RAND(5);
	  POKE(705,202);
  }
}

void DISPLAY_GAME_OVER(void)
{
	for (auto N = 0; N <= 9; N++)
	{
	GOTOXY 12,12;
	PRINT L"                    ";
	PAUSE 10;
		GOTOXY 12,12;
		PRINT L"G A M E      O V E R";
		PAUSE 10;
	}
	if (SC > H1)
	{
		H3 = H2;
		H2 = H1;
		H1 = SC;
	}
	else if (SC > H2)
	{
		H3 = H2;
		H2 = SC;
	}
	else if (SC > H3)
	{
		H3 = SC;
	EndIf;
}
//------------------------------
void DISPLAY_TITLE(void)
{
	GM = 28;
	PM = 1;
	GRAPHICS();
	POKE(712,128);
	POKE(710,140);
	POKE(709,68);
	POKE(711,218);
	GOTOXY 12,3;
	PRINT #6,L"B U G   I N V A D E";
	GOTOXY 22,4;
	PRINT #6,L"By Peter J. Meyer";
	POKE(PEEKW(560) + 8,5);
	GOTOXY 3,8;
	PRINT #6,L"Your score:";SC;
	GOTOXY 0,10;
	PRINT #6,L"High scores:";
	GOTOXY 12,10;
	PRINT #6,H1;
	GOTOXY 9,11;
	PRINT #6,L"2nd:";H2;
	GOTOXY 10,12;
	PRINT #6,L"3rd:";H3;
	GOTOXY 0,20;
	PRINT #6,L" Press START or FIRE to play begin game";
	POKE(PEEKW(560) + 25,2);
	do
	{
	} while (!(PEEK(53279) == 6 || STRIG(0) == 0));
	GM = 128;
	PM = 1;
	GRAPHICS();
}

//.h file code:

public:
void LOAD_AND_SET_UP();

//.cpp file code:

#include "snippet.h"

void LOAD_AND_SET_UP(void)
{
//****************************************************************************
//***
//*** Load and Set Up SUBesses. "BUGINVDE.DAT" to be replaced with internal Data
//***
//***
//****************************************************************************   
  POKE(106,PEEK(106) - 16);
  GRAPHICS 0;
  OPEN #1,4,0,L"D:BUGINVDE.DAT";
  SU = PEEK(106) * 256;
  BGET #1,SU,4095;
  if (PEEK(SU + 3842) + std::to_wstring(64) == L"64")
  {
	  BGET #1,1536,255;
  }
  SND = 1703; //1702 Plus 1 to bypass PLA instruction
  QT = 1742; //1741 Plus 1 to bypass PLA instruction
  Z = USR(1565); // Plus 1 to bypass PLA instruction
  CLOSE #1;
  POKEW(SU + 4074,PEEKW(SU + 4074) + SU);
  POKEW(SU + 4083,PEEKW(SU + 4083) + SU);
  SP = SU + 1024;
  PMV = SU + 3639; //SU+3638 Plus 1 to bypass PLA instruction
  RMV = SU + 3885; //SU+3884 Plus 1 to bypass PLA instruction
  PC = SU + 3861; //SU+3860 Plus 1 to bypass PLA instruction
  GM = PEEK(SU + 3840);
  PM = 1;
  GRAPHICS();
  STK = SU + 3189; //SU+3188 Plus 1 to bypass PLA instruction
  POKE(600,122);
  POKE(601,197);
  POKE(602,4);
  POKE(603,8);
  POKE(604,46);
  POKE(605,202);
  POKE(606,197);
  POKE(607,229);
}
//------------------------------
void CUSTOM_DISPLAY_LIST(void)
{
  POKEW(88,(PEEK(106) * 256) - (PEEK(SU + 3848) * 256));
  SCR_ADDR = PEEKW(88);
  DL = SU + 3328;
  N = DL;
  L = SU + 2048;
  M = 0;
  if (DL_ADDR_SET == 0)
  {
	  do
	  {
		P = PEEK(N);
		if ((P 64) == 64 && (P 15) > 1)
		{
			POINT_TO_LINE();
		}
		else if (P == 65)
		{
			POKEW(N + 1,DL);
		EndIf;
		if (P + std::to_wstring(128) == L"128")
		{
			SET_DLI_POINTERS();
		}
		N = N + 1;
		} while (!(N > DL + 310 || P == 65));
		DL_ADDR_SET = 1;
  EndIf;
  POKE(SU + 3309,(SU + 2048) % 256);
  POKE(SU + 3314,(SU + 2048) / 256);
  POKEW(560,DL);
  if (PEEK(SU + 3842) + std::to_wstring(16) == L"16")
  {
	POKEW(546,SU + 3308);
	PAUSE 1;
	POKE(54286,192);
  EndIf;
}

void POINT_TO_LINE()
{
  if (M == 0)
  {
	  M = 1;
  }
  LM_ADDR = PEEKW(N + 1);
  LM_ADDR = SCR_ADDR + LM_ADDR;
  POKEW(N + 1,INT(LM_ADDR));
  N = N + 2;
}

void SET_DLI_POINTERS(void)
{
  if (L == SU + 2048)
  {
	POKE(L + 49,L / 256);
	POKE(L + 47,L % 256);
  }
  else
  {
	L = L - 60;
	POKE(L + 49,(L + 60) / 256);
	POKE(L + 47,(L + 60) % 256);
	L = L + 60;
	POKE(L + 49,(SU + 2048) / 256);
	POKE(L + 47,(SU + 2048) % 256);
  }
  L = L + 60;
}

void INITIALIZE(void)
{
  SC = 0;
  Lives = 3;
  A = 0;
  B = 0;
  LV = 0;
  GM = 128;
  PM = 1;
  GRAPHICS();
}

