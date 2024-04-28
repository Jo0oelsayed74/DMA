#ifndef _Bit_MATH_H_
#define _Bit_MATH_H_


#define SET_BIT(Regi,Bit) (Regi |=(1<<Bit))
#define CLR_BIT(Regi,Bit) (Regi &=~(1<<Bit))
#define GET_BIT(Regi,Bit) ((Regi>>Bit)&1)
#define Toggle_Bit(Regi,Bit) (Regi^=(1<<Bit))
#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif

