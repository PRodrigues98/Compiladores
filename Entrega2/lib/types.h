#ifndef __TYPES_H__ 
#define __TYPES_H__ 


#define INTTYPE 1
#define NUMTYPE 2
#define STRTYPE 3
#define VOIDTYPE 4

#define TYPESHIFT 0
#define CONSTSHIFT 3
#define RIGHTCONSTSHIFT 4
#define PTRSHIFT 5
#define FUNCSHIFT 6
#define ZEROSHIFT 7

#define TYPEFILTER (0b0111 << TYPESHIFT)
#define CONSTFILTER (1 << CONSTSHIFT)
#define RIGHTCONSTFILTER (1 << RIGHTCONSTSHIFT)
#define PTRFILTER (1 << PTRSHIFT)
#define FUNCFILTER (1 << FUNCSHIFT)
#define ZEROFILTER (1 << ZEROSHIFT)

#define cleanType(A) (A & ~TYPEFILTER)
#define cleanConst(A) (A & ~CONSTFILTER)
#define cleanRightConst(A) (A & ~RIGHTCONSTFILTER)
#define cleanPointer(A) (A & ~PTRFILTER)
#define cleanFunction(A) (A & ~FUNCFILTER)
#define cleanZero(A) (A & ~ZEROFILTER)

#define setInteger(A) (cleanType(A) | INTTYPE)
#define setNumber(A) (cleanType(A) | NUMTYPE)
#define setString(A) (cleanType(A) | STRTYPE)
#define setVoid(A) (cleanType(A) | VOIDTYPE)
#define setConst(A) (cleanConst(A) | CONSTFILTER)
#define setRightConst(A) (cleanRightConst(A) | RIGHTCONSTFILTER)
#define setPointer(A) (cleanPointer(A) | PTRFILTER)
#define setFunction(A) (cleanFunction(A) | FUNCFILTER)
#define setZero(A) (cleanZero(A) | ZEROFILTER)

#define getType(A) ((A & TYPEFILTER) >> TYPESHIFT)
#define isInteger(A) (getType(A) == INTTYPE)
#define isNumber(A) (getType(A) == NUMTYPE)
#define isString(A) (getType(A) == STRTYPE)
#define isVoid(A) (getType(A) == VOIDTYPE)
#define isConst(A) ((A & CONSTFILTER) >> CONSTSHIFT)
#define isRightConst(A) ((A & RIGHTCONSTFILTER) >> RIGHTCONSTSHIFT)
#define isPointer(A) ((A & PTRFILTER) >> PTRSHIFT)
#define isFunc(A) ((A & FUNCFILTER) >> FUNCSHIFT)
#define isZero(A) ((A & ZEROFILTER) >> ZEROSHIFT)

#define isIntegerOrNum(A) (isInteger(A) || isNumber(A))


#endif /* __TYPES_H__ */