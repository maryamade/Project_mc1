/*
 * bit_utils.h
 *
 *  Created on: ???/???/????
 *      Author: adel
 */

#ifndef BIT_UTILS_H_
#define BIT_UTILS_H_
/*pin*/
#define SET_BIT(REG,BIT_NO) (REG|=(1<<BIT_NO))//0101 0001//0000 1000 //0101 1001
#define CLR_BIT(REG,BIT_NO) (REG&=(~(1<<BIT_NO)))//0101 1001 //0000 1000 ! 1111 0111 && 0101 0001
#define TGL_BIT(REG,BIT_NO) (REG^=(1<<BIT_NO))//0^1=1^1=0
/*REG*/
#define SET_REG(REG) (REG|=~(0))//0000 0000/1111 1111
#define CLR_REG(REG) (REG&=(~(-1)))//1111 1111//0000 0000
#define TGL_REG(REG) (REG^=(-1))//1111 1111 0101 0101 //1010 1010

#define SET_H_NIB(REG) REG |= (-1<<((4)*(sizeof(REG)))//0000 1001 //1111 0000//1111 1001
#define SET_L_NIB(REG) REG |= (-1>>((4)*(sizeof(REG)))//0000 1111
#define CLR_H_NIB(REG) REG &= ~( -1 << ( (4) * ( sizeof(REG) ) ) )//1111 0000 ! 0000 1111//0000
#define CLR_L_NIB(REG) REG &= ~(-1>>((4)*(sizeof(REG)))

#define SWAP_NIB(REG) REG= ((REG<<4) | (REG>>(sizeof(REG)*8)-4))//1110 0011 / 0011 0000 /0000 1110/0011 1110
#define CSHR(REG,BIT) ( REG= (REG>>BIT) | (REG<<(8-BIT)) )
#define CSHL(REG,BIT) ( REG= (REG<<BIT) | (REG>>(8-BIT)) )

#define IS_SET(REG,BIT_NO) ( REG & (1<<BIT_NO) )
#define IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT_NO)) )
#define GET_BIT(REG,BIT_NO) ((( REG & (1<<BIT_NO) )>>BIT_NO))//0101 1000 && 0000 1000-->0000 1000>>3 --> 0000 0001

#define ASSIGN_REG(REG,VAL) REG=VAL

#endif /* BIT_UTILS_H_ */
