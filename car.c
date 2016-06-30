#include<AT89x51.H>
#define uchar unsigned char

uchar command=0;


sbit IN1=P1^0;
sbit IN2=P1^1;
sbit ENA=P2^3;
			
sbit IN3=P1^2;
sbit IN4=P1^3;
sbit ENB=P2^2;

sbit IN5=P1^4;
sbit IN6=P1^5;
sbit ENA1=P2^1;

sbit IN7=P1^6;
sbit IN8=P1^7;
sbit ENB1=P2^0;

void Com_Init()
{
   	//IE	= 0x00;			//??????
	TMOD= 0x22;			//?????0???1(16?);???1???2(8?????)
	SCON= 0x50;			//?????????,????1,10?uart,?????;????
	TH1	= TL1 = 0xfd;	//????1???,???11.0592MHz?????9600bps
	IE	= 0x92;			//????0??,????,???0????
	//EA,_ _ ES,ET1,EX1,ET0,EX0
	TR1	= 1;	
}

void main()
{
	Com_Init();
	 
	while(1);
}

void ser() interrupt 4
{
	if(RI==0) return;
	ES=0;	  //?????
	RI=0;	//????????
	command=SBUF;	//????		
	switch(command)
	{
		
	case 'a':{					   //??
			  IN1=1;IN2=0;IN3=1;IN4=0;ENA=1;ENB=1;
		    IN5=1;IN6=0;IN7=1;IN8=0;ENA1=1;ENB1=1;
              break;
		    }	
	case 'b':{					   //?? 		    

			 IN1=0;IN2=1;IN3=0;IN4=1;ENA=1;ENB=1;
		    IN5=0;IN6=1;IN7=0;IN8=1;ENA1=1;ENB1=1;
			  break;
		    }		
  case 'c':{	

		IN1=1;IN2=0;IN3=1;IN4=0;ENA=1;ENB=1;
		    IN5=0;IN6=1;IN7=0;IN8=1;ENA1=1;ENB1=1;
		    break;
	}
  case 'd':{	
		
		IN1=0;IN2=1;IN3=0;IN4=1;ENA=1;ENB=1;
		   IN5=1;IN6=0;IN7=1;IN8=0;ENA1=1;ENB1=1;
		   break;
	 }
  case 'e':{	
		
		ENA=0;ENB=0;
		   ENA1=0;ENB1=0;
		break;
  }	
	
   default:
            {ENA=0;ENB=0;
		   ENA1=0;ENB1=0;

			break;
			}
	}
			
	ES=1;	//??????				
    }
