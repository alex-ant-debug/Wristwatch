#include "font.h"
#include "f64x2f.h"


const uint8_t f64x2f_table[f64x2f_NOFCHARS][192 + 2] = {
  // 0x30
  {
    23,
    f64x2_FLOAT_HEIGHT,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    _____XXX,XXXXXXXX,XX______,
    ___XXXXX,XXXXXXXX,XXXX____,
    ___XXXXX,XXXXXXXX,XXXX____,
    __XXXX__,________,_XXXX___,
    __XXXX__,________,_XXXX___,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    __XXXX__,________,_XXXX___,
    __XXXX__,________,_XXXX___,
    ___XXXXX,XXXXXXXX,XXXX____,
    ___XXXXX,XXXXXXXX,XXXX____,
    _____XXX,XXXXXXXX,XX______,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________}
  // 0x31
  ,{
    23,
    f64x2_FLOAT_HEIGHT,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,____XXXX,________,
	________,____XXXX,________,
	________,___XXXXX,________,
	________,__XXXXXX,________,
	________,_XXXXXXX,________,
    ________,XXXXXXXX,________,
    _______X,XXX_XXXX,________,
    ______XX,XX__XXXX,________,
    _____XXX,X___XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,____XXXX,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________}
  // 0x32
  ,{
    23,
    f64x2_FLOAT_HEIGHT,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    _____XXX,XXXXXXXX,XXX_____,
    ___XXXXX,XXXXXXXX,XXXX____,
    __XXXXXX,XXXXXXXX,XXXXX___,
    __XXXX__,________,_XXXXX__,
    _XXXX___,________,_XXXXX__,
    _XXXX___,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,_XXXX___,
    ________,________,XXXXX___,
	________,_______X,XXXX____,
	________,______XX,XXX_____,
	________,_____XXX,XX______,
	________,____XXXX,X_______,
	________,___XXXXX,________,
	________,__XXXXX_,________,
	________,_XXXXX__,________,
	________,XXXXX___,________,
	_______X,XXXX____,________,
	______XX,XXX_____,________,
	_____XXX,XX______,________,
	____XXXX,X_______,________,
	___XXXXX,________,________,
    __XXXX__,________,________,
    __XXXX__,________,________,
    __XXXX__,________,________,
    __XXXX__,________,________,
    __XXXX__,________,________,
    __XXXX__,________,________,
    __XXXX__,________,________,
    __XXXX__,________,________,
    __XXXX__,________,________,
    __XXXX__,________,________,
    __XXXX__,________,________,
    __XXXXXX,XXXXXXXX,XXXXXX__,
    _XXXXXXX,XXXXXXXX,XXXXXX__,
    _XXXXXXX,XXXXXXXX,XXXXXX__,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________}
  // 0x33
  ,{
    23,
    f64x2_FLOAT_HEIGHT,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    _____XXX,XXXXXXXX,XXX_____,
    ___XXXXX,XXXXXXXX,XXXX____,
    __XXXXXX,XXXXXXXX,XXXXX___,
    __XXXX__,________,_XXXX___,
    _XXXX___,________,_XXXX___,
    _XXXX___,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,XXXX____,
    ______XX,XXXXXXXX,XXXX____,
    ______XX,XXXXXXXX,XX______,
    ______XX,XXXXXXXX,XXXX____,
    ________,________,_XXXX___,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    __XXXX__,________,_XXXX___,
    __XXXXXX,XXXXXXXX,XXXXX___,
    ___XXXXX,XXXXXXXX,XXXX____,
    _____XXX,XXXXXXXX,XX______,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________}
  // 0x34
  ,{
    23,
    f64x2_FLOAT_HEIGHT,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,XXXXX___,
    ________,________,XXXXX___,
	________,_______X,XXXXX___,
	________,______XX,XXXXX___,
	________,______XX,XXXXX___,
	________,_____XXX,XXXXX___,
	________,_____XXX,XXXXX___,
	________,____XXX_,_XXXX___,
	________,____XXX_,_XXXX___,
	________,___XXX__,_XXXX___,
	________,___XXX__,_XXXX___,
	________,__XXX___,_XXXX___,
	________,__XXX___,_XXXX___,
	________,_XXX____,_XXXX___,
	________,_XXX____,_XXXX___,
	________,XXX_____,_XXXX___,
	________,XXX_____,_XXXX___,
	_______X,XX______,_XXXX___,
	_______X,XX______,_XXXX___,
	______XX,X_______,_XXXX___,
	______XX,X_______,_XXXX___,
	_____XXX,________,_XXXX___,
	_____XXX,________,_XXXX___,
	____XXX_,________,_XXXX___,
	____XXX_,________,_XXXX___,
	____XXX_,________,_XXXX___,
	___XXX__,________,_XXXX___,
	___XXX__,________,_XXXX___,
	__XXXX__,________,_XXXX___,
    __XXX___,________,_XXXX___,
    _XXX____,________,_XXXX___,
    _XXX____,________,_XXXX___,
    _XXX____,________,_XXXX___,
    _XXX____,________,_XXXX___,
    _XXX____,________,_XXXX___,
    _XXX____,________,_XXXX___,
    _XXXXXXX,XXXXXXXX,XXXXXXX_,
    _XXXXXXX,XXXXXXXX,XXXXXXX_,
    _XXXXXXX,XXXXXXXX,XXXXXXX_,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,_XXXX___,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________}
  // 0x35
  ,{
    23,
    f64x2_FLOAT_HEIGHT,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ___XXXXX,XXXXXXXX,XXXXX___,
    ___XXXXX,XXXXXXXX,XXXXX___,
    __XXXXXX,XXXXXXXX,XXXXX___,
    __XXXX__,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    __XXX___,________,________,
    _XXXX_XX,XXXXXXXX,XXX_____,
    _XXXXXXX,XXXXXXXX,XXXX____,
    _XXXXXXX,XXXXXXXX,XXXXX___,
    _XXXXX__,________,_XXXX___,
    _XXXX___,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXXX__,________,_XXXXX__,
    __XXXXXX,XXXXXXXX,XXXXX___,
    ___XXXXX,XXXXXXXX,XXXX____,
    _____XXX,XXXXXXXX,XX______,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________}
  // 0x36
  ,{
    23,
    f64x2_FLOAT_HEIGHT,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ______XX,XXXXXXXX,XXX_____,
    ____XXXX,XXXXXXXX,XXXX____,
    ___XXXXX,XXXXXXXX,XXXXX___,
    __XXXX__,________,_XXXXX__,
    __XXXX__,________,__XXXX__,
    __XXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX___,________,________,
    _XXXX_XX,XXXXXXXX,XXX_____,
    _XXXXXXX,XXXXXXXX,XXXX____,
    _XXXXXXX,XXXXXXXX,XXXXX___,
    _XXXXX__,________,_XXXX___,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXXX__,________,_XXXXX__,
    __XXXXXX,XXXXXXXX,XXXXX___,
    ___XXXXX,XXXXXXXX,XXXX____,
    _____XXX,XXXXXXXX,XX______,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________}
  // 0x37
  ,{
    23,
    f64x2_FLOAT_HEIGHT,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    _XXXXXXX,XXXXXXXX,XXXXXX__,
    _XXXXXXX,XXXXXXXX,XXXXXX__,
    _XXXXXXX,XXXXXXXX,XXXXXX__,
    ________,________,_XXXXX__,
    ________,________,_XXXXX__,
    ________,________,_XXXXX__,
    ________,________,_XXXXX__,
    ________,________,_XXXXX__,
    ________,________,_XXXXX__,
    ________,________,_XXXXX__,
    ________,________,_XXXXX__,
    ________,________,_XXXXX__,
    ________,________,_XXXXX__,
    ________,________,_XXXX___,
    ________,________,XXXX____,
    ________,_______X,XXX_____,
    ________,______XX,XX______,
	________,_____XXX,X_______,
	________,____XXXX,________,
	________,___XXXX_,________,
	________,__XXXX__,________,
	________,_XXXX___,________,
	________,XXXX____,________,
    _______X,XXX_____,________,
    ______XX,XX______,________,
    _____XXX,X_______,________,
    ____XXXX,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ___XXXX_,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________}
  // 0x38
  ,{
    23,
    f64x2_FLOAT_HEIGHT,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ____XXXX,XXXXXXXX,XXX_____,
    ___XXXXX,XXXXXXXX,XXXX____,
    __XXXXXX,XXXXXXXX,XXXXX___,
    _XXXXX__,________,_XXXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    __XXXX__,________,_XXXX___,
    ___XXXXX,XXXXXXXX,XXXX____,
    ____XXXX,XXXXXXXX,XXX_____,
    ___XXXXX,XXXXXXXX,XXXX____,
    __XXXX__,________,_XXXX___,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXXX__,________,_XXXXX__,
    __XXXXXX,XXXXXXXX,XXXXX___,
    ___XXXXX,XXXXXXXX,XXXX____,
    _____XXX,XXXXXXXX,XX______,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________}
  // 0x39
  ,{
    23,
    f64x2_FLOAT_HEIGHT,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ____XXXX,XXXXXXXX,XXX_____,
    ___XXXXX,XXXXXXXX,XXXX____,
    __XXXXXX,XXXXXXXX,XXXXX___,
    _XXXXX__,________,_XXXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    _XXXX___,________,__XXXX__,
    __XXXX__,________,_XXXXX__,
    ___XXXXX,XXXXXXXX,XXXXXX__,
    ____XXXX,XXXXXXXX,X_XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXXX__,
    ________,________,__XXX___,
    _XXXX___,________,_XXXX___,
    _XXXXX__,________,_XXXX___,
    __XXXXXX,XXXXXXXX,XXXX____,
    __XXXXXX,XXXXXXXX,XXX_____,
    ____XXXX,XXXXXXXX,X_______,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________}
};

const uint8_t f64x2f_table2[192 + 2] =
// 0x20
{
  8,
  f64x2_FLOAT_HEIGHT,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________
};

const uint8_t f64x2f_table3[192 + 2] =
// 0x2E
{
  8,
  f64x2_FLOAT_HEIGHT,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  __XXXX__,________,
  _XXXXXX_,________,
  _XXXXXX_,________,
  _XXXXXX_,________,
  _XXXXXX_,________,
  __XXXX__,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________
};

const uint8_t f64x2f_table4[192 + 2] =
// 0xB0
{
  15,
  f64x2_FLOAT_HEIGHT,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  _____XXX,XX______,
  ___XXXXX,XXXX____,
  __XXXXXX,XXXXX___,
  __XXXX__,_XXXX___,
  _XXXX___,__XXXX__,
  _XXXX___,__XXXX__,
  _XXXX___,__XXXX__,
  _XXXX___,__XXXX__,
  __XXXX__,_XXXX___,
  __XXXXXX,XXXXX___,
  ___XXXXX,XXXX____,
  _____XXX,XXX_____,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  _____XXX,XX______,
  ___XXXXX,XXXX____,
  __XXXXXX,XXXXX___,
  __XXXX__,_XXXX___,
  _XXXX___,__XXXX__,
  _XXXX___,__XXXX__,
  _XXXX___,__XXXX__,
  _XXXX___,__XXXX__,
  __XXXX__,_XXXX___,
  __XXXXXX,XXXXX___,
  ___XXXXX,XXXX____,
  _____XXX,XXX_____,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________,
  ________,________
};

const uint8_t f64x2f_table5[192 + 2] =
// 0x3A
{
    23,
    f64x2_FLOAT_HEIGHT-2,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
	________,__XXXX__,________,
	________,_XXXXXX_,________,
	________,_XXXXXX_,________,
	________,_XXXXXX_,________,
	________,_XXXXXX_,________,
	________,__XXXX__,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
	________,__XXXX__,________,
	________,_XXXXXX_,________,
	________,_XXXXXX_,________,
	________,_XXXXXX_,________,
	________,_XXXXXX_,________,
	________,__XXXX__,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________,
    ________,________,________
};


uint8_t *f64x2f_GetCharTable(char Char)
{
  if ((Char >= 0x30) && (Char <= 0x39))
  {
    return (uint8_t *)(&f64x2f_table[Char - 0x30][0]);
  }
  if (Char == 0x20)
  {
      return (uint8_t *) f64x2f_table2;
  }
  if (Char == 0x2E)
  {
      return (uint8_t *) f64x2f_table3;
  }
  if (Char == 0xB0)
  {
      return (uint8_t *) f64x2f_table4;
  }
  if (Char == 0x3A)
  {
      return (uint8_t *) f64x2f_table5;
  }

  return 0;
}
