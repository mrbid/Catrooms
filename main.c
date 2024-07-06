/*
    James William Fletcher ( github.com/mrbid )
        July 2024
*/

//#pragma GCC diagnostic ignored "-Wunused-result"
//#pragma GCC diagnostic ignored "-Wtrigraphs"
//#pragma GCC diagnostic ignored "-Wpointer-sign"
const unsigned char icon_image[] = // 16x16 RGBA
  "\377\377\377\000\377\377\377\000a\027\062\001\224\061C\064\252<JO\377\247\232\001\377"
  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\237\312\001\233\064"
  "\070T\212'(=j\016\015\001\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
  "\000\211!:\007o\027,\243r\034*\363\300\063\071Q\377\"(\005T;<\004\060\061+\003\361!-\005\256"
  "\060CQ]\025%\362b\024\037\255\226,&\012\377\377\377\000\377\377\377\000\377\377\377"
  "\000\377\377\377\000\302:D\035_\017.\315\036\000!\377\\\017\034\360\351\063\065{\317?"
  "Dp\307<?n\327,\061|J\014\025\361!\000+\377c\021\065\327\255\062\060&\377\377\377\000"
  "\377\377\377\000\377\377\377\000\377\377\377\000\300'*\060Y\013$\343>\007,\377p%/\377"
  "\272;=\377\370?E\377\370?E\377\264\065\070\377[\033\034\377\061\004%\377W\017\064"
  "\355\252/\070\070\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\201"
  "\021\035&Y\014\032\324\313\064\070\377\377QZ\377\230=I\377\334?F\377\343@D\377"
  "\243BK\377\377FO\377\257\040$\377=\021\040\337y\060=,\377\377\377\000\377\377\377"
  "\000\377\377\377\000\377\377\377\000\303\020\020\011\267/\064\264\222?A\377\305DB\377"
  "\363<D\377\347BF\377\353BA\377\350EG\377\266>>\377\177%-\377\213\040&\274"
  "\264\"!\014\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\306#$"
  "\067\332AG\341!\066@\377\001#\021\377}\024\013\377\377?C\377\363/\062\377c\027\022"
  "\377\000.\035\377'\033'\377\264*\063\343k\023\024=\377\377\377\000\377\377\377\000\377"
  "\377\377\000\377\377\377\000b\035\037\211\202*,\377b\034\040\377+\013\016\377sLK\377"
  "\344L`\377\320;W\377i,\065\377,\007\007\377^\025\027\377l\040\"\377\062\016\021\216"
  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000I\035#\232@\015\023"
  "\377\202\005\007\377\270\066C\377\377\225\243\377\243]n\377\240Wp\377\377kz\377"
  "\242\026\037\377^\001\002\377L\020\021\377\063\020\021\243\377\377\377\000\377\377\377"
  "\000\377\377\377\000\377\377\377\000m\027\036V]\010\015\375\200an\377\223\203\221\377"
  "c\067A\377ODL\377J<>\377\\\061\063\377xcr\377Y<F\377Q\007\007\377>\015\015e\377\377"
  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\301\002\000\017s\021\020\307ds"
  "~\377Aox\377\000\000\000\377\000\010\007\377\000\007\004\377\000\000\000\377Iu\205\377]]h\377P\010"
  "\007\316S\001\000\022\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
  "\377\377\000\232)'ec'(\377\023\025\025\377\037\000\004\377+\006\023\377\040\007\023\377\017"
  "\000\001\377\040!%\377V#%\377l\025\025i\377\377\377\000\377\377\377\000\377\377\377"
  "\000\377\377\377\000\377\377\377\000\377\377\377\000\343MN\015n\031\030\231L\021\020\377"
  "o&\063\377u\062O\377f*M\377L\025%\377\062\004\002\377G\012\010\235\206''\016\377\377"
  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
  "\000\377\377\377\000t#\"\014~**t\206DN\364\216E_\377\212\062U\377h(\066\363L\024"
  "\017v\061\004\000\014\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\300TV"
  "\004t<Iw\221BS\377\206EU\377ZEHql\065*\004\377\377\377\000\377\377\377\000\377\377"
  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
  "\000\377\377\377\000\377\377\377\000\377\377\377\000O\027\"\023T\060\063\223P?>\214\067"
  "gY\017\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
  "\000\377\377\377\000";

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void timestamp(char* ts){const time_t tt=time(0);strftime(ts,16,"%H:%M:%S",localtime(&tt));}
#ifdef WEB
    #include <emscripten.h>
    #include <emscripten/html5.h>
    #define GL_GLEXT_PROTOTYPES
    #define EGL_EGLEXT_PROTOTYPES
#endif
#define GLAD_GL_IMPLEMENTATION
#include "inc/gl.h"
#define GLFW_INCLUDE_NONE
#include "inc/glfw3.h"
#define uint GLuint
#define sint GLint
#define MAX_MODELS 24 // hard limit, be aware and increase if needed
#include "inc/esLuma.h"
#include "assets/high/floor.h"//0
#include "assets/high/wall.h" //1
#include "assets/high/c1.h"   //2
#include "assets/high/c2.h"   //3
#include "assets/high/c3.h"   //4
#include "assets/high/c4.h"   //5
#include "assets/high/c5.h"   //6
#include "assets/high/c6.h"   //7
#include "assets/high/c7.h"   //8
#include "assets/high/c8.h"   //9
#include "assets/high/p1.h"   //10
#include "assets/high/p2.h"   //11
#include "assets/high/p3.h"   //12
#include "assets/high/p4.h"   //13
#include "assets/high/p5.h"   //14
#include "assets/high/p6.h"   //15
#include "assets/high/p7.h"   //16
#include "assets/high/p8.h"   //17
#include "assets/high/p9.h"   //18
#include "assets/high/p10.h"  //19
#include "assets/high/p11.h"  //20
#include "assets/high/p12.h"  //21
#include "assets/high/p13.h"  //22
#include "assets/high/p14.h"  //23

//*************************************
// globals
//*************************************
const char appTitle[]="The Catrooms";
GLFWwindow* wnd;
uint winw=1024, winh=768, ks[4]={0};
float t=0.f, dt=0.f, lt=0.f, fc=0.f, lfct=0.f, aspect;

// camera vars
#define FAR_DISTANCE 14.f
#define DRAW_DISTANCE 196.f // FAR_DISTANCE*FAR_DISTANCE
uint lock_mouse = 0;
uint free_look = 0;
double sens = 0.003;
double mx,my,lx,ly;
float xrot = 0.f;
float yrot = 1.3f;
vec lookx, lookz;

// level
const float level_floor[] = {-4,0,-4,1,-4,2,-4,-1,-4,-2,-4,-3,-2,-3,-2,-2,-2,-1,-2,2,-2,1,-2,0,0,0,0,1,0,-1,0,-2,1,-1,1,0,-4,-4,-4,3,-3,3,-3,-4,4,3,4,-4,4,-3,4,-2,4,-1,4,2,4,1,4,0,-2,-4,-2,3,2,3,2,-4,2,0,2,1,2,2,2,-1,2,-2,2,-3,3,-4,3,3,-1,-4,1,-4,0,-4,1,3,-1,3,0,3,-1,-1,-1,0,-1,-2,1,-2,1,1,-1,1,-2,-5,0,-5,0,-6,2,-5,2,-6,-2,-6,-3,-6,-4,-6,3,-6,4,-6,4,-7,4,-8,4,-9,-4,-7,-4,-8,-4,-9,-3,-9,-2,-9,-1,-9,0,-9,1,-9,2,-9,3,-9,-2,-7,-1,-7,0,-7,1,-7,2,-7,0,-8,-2,4,-2,5,-2,6,0,5,0,4,0,6,0,7,0,8,2,4,2,5,2,6,2,8,1,6,-1,6,-3,5,-4,5,3,5,4,5,4,6,4,7,4,8,3,8,1,8,-1,8,-2,8,-3,8,-4,8,-4,7,-4,6,6,6,6,7,6,8,7,8,8,8,9,8,11,8,13,8,14,8,14,7,14,6,14,5,13,5,6,5,7,5,9,6,11,6,12,8,12,6,12,5,12,4,10,8,10,7,10,6,10,4,10,5,8,6,8,5,8,4,10,-8,12,-7,11,-7,10,-7,9,-7,8,-7,13,-9,12,-9,10,-9,9,-9,8,-9,7,-9,6,-9,6,-8,6,-7,14,-9,14,-8,14,-7,14,-6,13,-6,6,-6,7,-6,8,-6,12,-6,12,-5,10,-6,10,-5,8,-5,9,1,11,1,11,-2,9,-2,9,0,9,-1,10,3,9,3,11,3,10,-4,11,-4,9,-4,13,3,13,-4,12,-3,12,-2,12,-1,12,2,12,1,12,0,12,-4,12,3,8,3,8,-4,14,0,14,1,14,2,14,-1,14,-2,14,-3,14,-4,14,3,7,-4,7,3,6,3,6,-4,11,0,11,-1,10,-2,10,-1,10,1,10,0,8,0,8,1,8,2,8,-1,8,-2,8,-3,6,-3,6,-2,6,-1,6,2,6,1,6,0,5,0,5,-1,-14,6,-14,7,-14,8,-13,8,-12,8,-11,8,-9,8,-7,8,-6,8,-6,7,-6,6,-6,5,-7,5,-14,5,-13,5,-11,6,-9,6,-8,8,-8,6,-8,5,-8,4,-10,8,-10,7,-10,6,-10,4,-10,5,-12,6,-12,5,-12,4,-10,-8,-8,-7,-9,-7,-10,-7,-11,-7,-12,-7,-7,-9,-8,-9,-9,-9,-10,-9,-11,-9,-12,-9,-13,-9,-14,-9,-14,-8,-6,-9,-6,-8,-6,-7,-6,-6,-7,-6,-14,-6,-13,-6,-12,-6,-8,-6,-8,-5,-10,-6,-10,-5,-12,-5,-11,1,-9,1,-9,-2,-11,-2,-11,0,-11,-1,-10,3,-11,3,-9,3,-10,-4,-9,-4,-11,-4,-7,3,-7,-4,-8,-3,-8,-2,-8,-1,-8,2,-8,1,-8,0,-8,-4,-8,3,-12,3,-12,-4,-6,0,-6,1,-6,2,-6,-1,-6,-2,-6,-3,-6,-4,-6,3,-13,-4,-13,3,-14,3,-14,-4,-9,0,-9,-1,-10,-2,-10,-1,-10,1,-10,0,-12,0,-12,1,-12,2,-12,-1,-12,-2,-12,-3,-14,-3,-14,-2,-14,-1,-14,2,-14,1,-14,0,-5,-8,-5,-7,-5,12,-5,11,-14,19,-14,20,-14,21,-14,18,-14,17,-14,16,-12,16,-12,17,-12,18,-12,20,-12,19,-10,17,-9,18,-9,19,-14,15,-14,22,-13,22,-13,15,-6,22,-6,15,-6,16,-6,17,-6,18,-6,21,-6,20,-6,19,-12,15,-12,22,-8,22,-8,15,-8,19,-8,20,-8,18,-8,17,-8,16,-7,15,-7,22,-11,15,-9,15,-10,15,-9,22,-11,22,-10,22,-11,18,-11,19,-11,17,-9,17,-9,20,-11,20,-12,14,-10,14,-10,13,-8,14,-8,13,-12,13,-13,13,-14,13,-7,13,-6,13,-6,12,-6,11,-6,10,-14,12,-14,11,-14,10,-13,10,-12,10,-11,10,-10,10,-9,10,-8,10,-7,10,-12,12,-11,12,-10,12,-9,12,-8,12,-10,11,-12,23,-12,24,-12,25,-10,24,-10,23,-10,25,-10,26,-10,27,-8,23,-8,24,-8,25,-8,27,-9,25,-11,25,-13,24,-14,24,-7,24,-6,24,-6,25,-6,26,-6,27,-7,27,-9,27,-11,27,-12,27,-13,27,-14,27,-14,26,-14,25,5,18,5,19,6,19,6,20,6,21,6,18,6,17,6,16,8,16,8,17,8,18,8,21,8,20,8,19,10,19,10,20,10,18,10,17,11,19,6,15,6,22,7,15,14,22,14,15,14,16,14,17,14,18,14,21,14,20,14,19,8,15,8,22,12,22,12,15,12,19,12,20,12,21,12,18,12,17,12,16,13,15,9,15,11,15,10,15,10,22,9,19,9,17,11,17,8,14,10,14,10,13,12,14,12,13,8,13,7,13,6,13,13,13,14,13,14,12,14,11,14,10,6,12,6,11,6,10,7,10,8,10,9,10,10,10,11,10,12,10,13,10,8,12,9,12,10,12,11,12,12,12,10,11,8,23,8,24,8,25,10,24,10,23,10,25,10,26,10,27,12,23,12,24,12,25,12,27,11,25,9,25,6,24,14,24,14,25,14,26,14,27,13,27,11,27,9,27,8,27,7,27,6,27,6,26,6,25,-4,25,-4,26,-4,27,-3,27,-2,27,-1,27,1,27,3,27,4,27,4,26,4,25,4,24,3,24,-4,24,-3,24,-1,25,1,25,2,27,2,25,2,24,2,23,0,27,0,26,0,25,0,23,0,24,-2,25,-2,24,-2,23,0,11,2,12,1,12,0,12,-1,12,-2,12,3,10,2,10,1,10,0,10,-1,10,-2,10,-3,10,-4,10,-4,11,-4,12,4,10,4,11,4,12,4,13,3,13,-4,13,-3,13,-2,13,2,13,2,14,0,13,0,14,-2,14,-1,20,1,20,1,17,-1,17,-1,19,0,22,-1,22,1,22,0,15,1,15,-1,15,3,22,3,15,2,16,2,17,2,18,2,21,2,20,2,19,2,15,2,22,-2,22,-2,15,4,19,4,20,4,21,4,18,4,17,4,16,4,15,4,22,-3,15,-3,22,-4,22,-4,15,1,19,1,18,0,17,0,20,-2,19,-2,20,-2,21,-2,17,-2,16,-4,16,-4,17,-4,18,-4,21,-4,20,-4,19,-5,-26,-5,-27,-14,-19,-14,-18,-14,-17,-14,-20,-14,-21,-14,-22,-12,-22,-12,-21,-12,-20,-12,-17,-12,-18,-12,-19,-9,-20,-9,-19,-14,-23,-14,-16,-13,-16,-13,-23,-6,-16,-6,-23,-6,-22,-6,-21,-6,-20,-6,-17,-6,-18,-6,-19,-12,-23,-12,-16,-8,-16,-8,-23,-8,-19,-8,-18,-8,-17,-8,-20,-8,-21,-8,-22,-7,-23,-7,-16,-11,-23,-9,-23,-10,-23,-9,-16,-11,-16,-10,-16,-11,-20,-11,-19,-11,-21,-9,-21,-9,-18,-11,-18,-12,-24,-10,-24,-10,-25,-8,-24,-8,-25,-12,-25,-13,-25,-14,-25,-7,-25,-6,-25,-6,-26,-6,-27,-6,-28,-14,-26,-14,-27,-14,-28,-13,-28,-12,-28,-11,-28,-10,-28,-9,-28,-8,-28,-7,-28,-12,-26,-11,-26,-10,-26,-9,-26,-8,-26,-10,-27,-12,-15,-12,-14,-12,-13,-10,-14,-10,-15,-10,-13,-10,-12,-10,-11,-8,-15,-8,-14,-8,-13,-8,-11,-9,-13,-11,-13,-13,-14,-14,-14,-7,-14,-6,-14,-6,-13,-6,-12,-6,-11,-7,-11,-9,-11,-11,-11,-12,-11,-13,-11,-14,-11,-14,-12,-14,-13,5,-20,5,-19,6,-19,6,-18,6,-17,6,-20,6,-21,6,-22,8,-22,8,-21,8,-20,8,-17,8,-18,8,-19,10,-19,10,-18,10,-20,10,-21,11,-20,11,-19,6,-23,6,-16,7,-16,7,-23,14,-16,14,-23,14,-22,14,-21,14,-20,14,-17,14,-18,14,-19,8,-23,8,-16,12,-16,12,-23,12,-19,12,-18,12,-17,12,-20,12,-21,12,-22,13,-23,13,-16,9,-23,11,-23,10,-23,11,-16,10,-16,9,-20,9,-19,9,-21,11,-21,11,-18,9,-18,8,-24,10,-24,10,-25,12,-24,12,-25,8,-25,7,-25,6,-25,13,-25,14,-25,14,-26,14,-27,14,-28,6,-26,6,-27,6,-28,7,-28,8,-28,9,-28,10,-28,11,-28,12,-28,13,-28,8,-26,9,-26,10,-26,11,-26,12,-26,10,-27,8,-14,8,-13,10,-14,10,-15,10,-13,10,-12,10,-11,12,-15,12,-14,12,-13,12,-11,9,-13,7,-14,6,-14,13,-14,14,-14,14,-13,14,-12,14,-11,13,-11,11,-11,9,-11,8,-11,7,-11,6,-11,6,-12,6,-13,-4,-13,-4,-12,-4,-11,-3,-11,-2,-11,-1,-11,1,-11,3,-11,4,-11,4,-12,4,-13,4,-14,3,-14,-4,-14,-3,-14,-1,-13,1,-13,2,-11,2,-13,2,-14,2,-15,0,-11,0,-12,0,-13,0,-15,-2,-13,-2,-14,-2,-15,0,-27,2,-26,1,-26,0,-26,-1,-26,-2,-26,3,-28,2,-28,1,-28,0,-28,-1,-28,-2,-28,-3,-28,-4,-28,-4,-27,-4,-26,4,-28,4,-27,4,-26,4,-25,3,-25,-4,-25,-3,-25,-2,-25,2,-25,2,-24,0,-24,-2,-24,-1,-18,1,-18,1,-21,-1,-21,-1,-19,-1,-20,0,-16,-1,-16,1,-16,0,-23,1,-23,-1,-23,3,-23,2,-22,2,-21,2,-20,2,-17,2,-18,2,-19,2,-23,2,-16,-2,-16,-2,-23,4,-19,4,-18,4,-17,4,-20,4,-21,4,-22,4,-23,4,-16,-3,-23,-3,-16,-4,-16,-4,-23,1,-19,1,-20,0,-20,0,-19,-2,-19,-2,-18,-2,-17,-2,-20,-2,-21,-2,-22,-4,-22,-4,-21,-4,-20,-4,-17,-4,-18,-4,-19,27,-23,34,-16,34,-23,34,-22,34,-21,34,-20,34,-17,34,-18,34,-19,28,-23,28,-16,32,-16,32,-23,32,-19,32,-18,32,-17,32,-21,32,-22,33,-23,33,-16,29,-23,31,-23,30,-23,31,-16,30,-16,29,-20,29,-21,31,-21,31,-18,28,-24,30,-24,30,-25,32,-25,28,-25,27,-25,26,-25,33,-25,34,-25,34,-26,34,-27,34,-28,26,-26,26,-27,26,-28,27,-28,28,-28,30,-28,31,-28,32,-28,28,-26,29,-26,30,-26,31,-26,32,-26,30,-27,28,-14,28,-13,30,-14,30,-15,30,-13,30,-12,30,-11,32,-15,32,-14,32,-13,32,-11,31,-13,29,-13,27,-14,26,-14,33,-14,34,-14,34,-12,34,-11,33,-11,31,-11,29,-11,28,-11,27,-11,26,-11,26,-12,36,-13,36,-12,36,-11,37,-11,38,-11,39,-11,41,-11,43,-11,44,-11,44,-12,44,-13,44,-14,43,-14,36,-14,37,-14,39,-13,41,-13,42,-11,42,-13,42,-14,42,-15,40,-11,40,-12,40,-13,40,-15,40,-14,38,-13,38,-14,38,-15,40,-27,42,-26,41,-26,40,-26,39,-26,38,-26,43,-28,42,-28,41,-28,40,-28,39,-28,38,-28,37,-28,36,-28,36,-27,36,-26,44,-28,44,-27,44,-26,44,-25,43,-25,36,-25,37,-25,38,-25,42,-25,42,-24,40,-25,40,-24,38,-24,39,-18,41,-18,41,-21,39,-21,39,-19,39,-20,40,-16,39,-16,41,-16,40,-23,41,-23,39,-23,43,-16,43,-23,42,-22,42,-21,42,-20,42,-17,42,-18,42,-19,42,-23,42,-16,38,-16,38,-23,44,-19,44,-18,44,-17,44,-20,44,-21,44,-22,44,-23,44,-16,37,-23,37,-16,36,-16,36,-23,41,-19,41,-20,40,-21,40,-20,40,-18,40,-19,38,-19,38,-18,38,-17,38,-20,38,-21,38,-22,36,-22,36,-21,36,-20,36,-17,36,-18,36,-19,35,-19,35,-20,16,-13,16,-12,16,-11,17,-11,18,-11,19,-11,21,-11,23,-11,24,-11,24,-12,24,-13,24,-14,23,-14,16,-14,17,-14,19,-13,21,-13,22,-11,22,-13,22,-14,22,-15,20,-11,20,-12,20,-13,20,-15,20,-14,18,-13,18,-14,18,-15,20,-27,22,-26,21,-26,20,-26,19,-26,18,-26,23,-28,22,-28,21,-28,20,-28,19,-28,18,-28,17,-28,16,-28,16,-27,16,-26,24,-28,24,-27,24,-26,24,-25,23,-25,16,-25,17,-25,18,-25,22,-25,22,-24,20,-25,20,-24,18,-24,19,-18,21,-18,21,-21,19,-21,19,-19,19,-20,20,-16,19,-16,21,-16,20,-23,21,-23,19,-23,23,-16,23,-23,22,-22,22,-21,22,-20,22,-17,22,-18,22,-19,22,-23,22,-16,18,-16,18,-23,24,-19,24,-18,24,-17,24,-20,24,-21,24,-22,24,-23,24,-16,17,-23,17,-16,16,-16,16,-23,21,-19,21,-20,20,-21,20,-20,20,-18,20,-19,18,-19,18,-18,18,-17,18,-20,18,-21,18,-22,16,-22,16,-21,16,-20,16,-17,16,-18,16,-19,25,-27,25,-26,26,19,26,20,26,21,26,18,26,17,26,16,28,16,28,17,28,18,28,21,28,20,28,19,30,19,30,20,30,18,30,17,31,18,31,19,26,15,26,22,27,22,27,15,34,22,34,15,34,16,34,17,34,18,34,21,34,20,34,19,28,15,28,22,32,22,32,15,32,19,32,20,32,21,32,18,32,17,32,16,33,15,33,22,29,15,31,15,30,15,31,22,29,22,30,22,29,18,29,19,29,17,31,17,31,20,29,20,28,14,30,14,30,13,32,14,32,13,28,13,27,13,26,13,33,13,34,13,34,12,34,11,34,10,26,12,26,11,26,10,27,10,29,10,30,10,31,10,32,10,33,10,28,12,29,12,30,12,31,12,32,12,30,11,28,23,28,24,28,25,30,24,30,23,30,25,30,26,30,27,32,23,32,24,32,25,32,27,31,25,29,25,27,24,26,24,33,24,34,24,34,25,34,26,34,27,33,27,31,27,29,27,28,27,27,27,26,27,26,26,26,25,36,25,36,26,36,27,37,27,38,27,39,27,41,27,43,27,44,27,44,26,44,25,44,24,43,24,36,24,37,24,39,25,41,25,42,27,42,25,42,24,42,23,40,27,40,26,40,25,40,23,40,24,38,25,38,24,38,23,40,11,42,12,41,12,40,12,39,12,38,12,43,10,42,10,41,10,40,10,39,10,38,10,36,10,36,11,36,12,44,10,44,11,44,12,44,13,43,13,36,13,38,13,42,13,42,14,40,13,40,14,38,14,39,20,41,20,41,17,39,17,39,19,39,18,40,22,39,22,41,22,40,15,41,15,39,15,43,22,43,15,42,16,42,17,42,18,42,21,42,20,42,19,42,15,42,22,38,22,38,15,44,19,44,20,44,21,44,18,44,17,44,16,44,15,44,22,37,22,36,22,36,15,41,19,41,18,40,17,40,20,38,19,38,20,38,21,38,18,38,17,38,16,36,16,36,17,36,18,36,21,36,20,36,19,35,19,35,18,16,25,16,26,16,27,17,27,18,27,19,27,21,27,23,27,24,27,24,26,24,25,24,24,23,24,16,24,17,24,19,25,21,25,22,27,22,25,22,24,22,23,20,27,20,26,20,25,20,23,20,24,18,25,18,24,18,23,20,11,22,12,21,12,20,12,19,12,18,12,23,10,22,10,21,10,20,10,19,10,18,10,17,10,16,10,16,11,16,12,24,10,24,11,24,12,24,13,23,13,16,13,17,13,18,13,22,13,22,14,20,13,20,14,18,14,19,20,21,20,21,17,19,17,19,19,19,18,20,22,19,22,21,22,20,15,21,15,19,15,23,22,23,15,22,16,22,17,22,18,25,-7,25,-8,16,0,16,1,16,2,16,-1,16,-2,16,-3,18,-3,18,-2,18,-1,18,2,18,1,18,0,20,0,20,1,20,-1,20,-2,21,-1,21,0,16,-4,16,3,17,3,17,-4,24,3,24,-4,24,-3,24,-2,24,-1,24,2,24,1,24,0,18,-4,18,3,22,3,22,-4,22,0,22,1,22,2,22,-1,22,-2,22,-3,23,-4,23,3,19,-4,21,-4,20,-4,21,3,19,3,20,3,19,-1,19,0,19,-2,21,-2,21,1,19,1,18,-5,20,-5,20,-6,22,-5,22,-6,18,-6,17,-6,16,-6,23,-6,24,-6,24,-7,24,-8,24,-9,16,-7,16,-8,16,-9,17,-9,18,-9,19,-9,20,-9,21,-9,22,-9,23,-9,18,-7,19,-7,20,-7,21,-7,22,-7,20,-8,18,4,18,5,18,6,20,5,20,4,20,6,20,7,20,8,22,4,22,5,22,6,22,8,21,6,19,6,17,5,16,5,23,5,24,5,24,6,24,7,24,8,23,8,21,8,19,8,18,8,17,8,16,8,16,7,16,6,35,-1,35,0,36,0,36,1,36,2,36,-1,36,-2,36,-3,38,-3,38,-2,38,-1,38,2,38,1,38,0,40,0,40,1,40,-1,40,-2,41,-1,41,0,36,-4,36,3,37,3,37,-4,44,3,44,-4,44,-3,44,-2,44,-1,44,2,44,1,44,0,38,-4,38,3,42,3,42,-4,42,0,42,1,42,-1,42,-2,43,-4,43,3,39,-4,41,-4,40,-4,41,3,39,3,40,3,39,-2,39,1,38,-5,40,-5,40,-6,42,-5,42,-6,38,-6,37,-6,36,-6,43,-6,44,-6,44,-7,44,-8,44,-9,36,-7,36,-8,36,-9,37,-9,38,-9,39,-9,40,-9,41,-9,42,-9,43,-9,38,-7,39,-7,40,-7,41,-7,42,-7,40,-8,38,4,38,5,38,6,40,6,40,7,40,8,42,4,42,5,42,6,41,6,39,6,36,5,44,5,44,6,44,7,44,8,43,8,37,8,36,8,36,7,36,6,26,6,26,7,26,8,27,8,29,8,31,8,33,8,34,8,34,7,34,6,34,5,33,5,26,5,27,5,29,6,31,6,32,8,32,6,32,5,32,4,30,8,30,7,30,6,30,4,30,5,28,6,28,5,28,4,30,-8,32,-7,31,-7,30,-7,29,-7,28,-7,33,-9,32,-9,31,-9,30,-9,29,-9,28,-9,27,-9,26,-9,26,-8,26,-7,34,-9,34,-8,34,-7,34,-6,26,-19,33,-6,26,-18,26,-17,26,-20,26,-21,26,-22,28,-22,28,-21,28,-20,28,-17,28,-18,26,-6,28,-19,30,-19,30,-18,30,-20,30,-21,31,-19,26,-23,26,-16,27,-16,27,-6,28,-6,32,-6,32,-5,30,-6,30,-5,28,-5,29,1,31,1,31,-2,29,-2,29,0,29,-1,30,3,29,3,31,3,30,-4,31,-4,29,-4,33,3,33,-4,32,-3,32,-2,32,-1,32,2,32,1,32,0,32,-4,32,3,28,3,28,-4,34,0,34,1,34,2,34,-1,34,-2,34,-3,34,-4,34,3,27,-4,27,3,26,3,26,-4,31,0,31,-1,30,-2,30,-1,30,1,30,0,28,0,28,1,28,2,28,-1,28,-2,28,-3,26,-3,26,-2,26,-1,26,2,26,1,22,20,22,19,22,15,26,0,22,22,18,22,18,15,24,19,24,20,24,21,24,18,24,17,24,16,24,15,24,22,17,15,17,22,16,22,16,15,21,19,21,18,20,17,20,18,20,20,20,19,18,19,18,20,18,18,18,17,18,16,16,16,16,17,16,18,16,21,16,20,16,19,25,11,25,12,43,19,43,18,12,-12,13,-12,13,-13,13,-10,0,-10,-6,-10,-14,9,0,9,-3,-20,-3,-19,3,19,3,18,-3,16,-3,21,2,11,-2,11,-5,16,-5,21,5,27,-8,26,7,23,6,23,10,21,9,21,11,21,7,21,13,17,13,21,13,19,10,16,7,19,7,17,9,23,11,23,13,23,14,23,12,26,8,26,7,25,13,25,5,-16,7,-15,-14,4,-13,-10,28,-10,35,-27,39,2,41,2,40,-3,41,-3,39,-3,40,2,37,0,37,-1,41,-5,39,-5,44,4,36,4,38,8,38,9,42,8,25,24,20,21,11,9,27,9,36,14,37,10,21,-10,23,-10,22,-12,18,-12,17,-10,19,-10,18,-8,22,-8,-13,21,-13,20,15,24,15,12};
const uint floor_size = 4108;

const float level_wall[] = {-5,1,-5,0,-3,1,-3,0,5,1,3,0,3,2,3,1,-3,2,1,2,0,2,-1,2,-4,4,-3,4,4,4,3,4,1,4,-1,4,-1,5,1,5,5,4,5,5,-5,3,-5,4,-5,5,-5,2,5,3,5,2,5,6,5,7,-5,6,-5,9,-5,8,-5,7,-3,6,3,6,1,7,3,7,-4,9,-1,9,-2,9,-3,9,2,9,3,9,4,9,5,9,1,9,2,7,5,8,-3,7,-2,7,-1,7,-1,-8,-2,-8,-3,-8,5,-9,2,-8,1,-10,5,-10,4,-10,3,-10,2,-10,-3,-10,-2,-10,-1,-10,-4,-10,3,-8,1,-8,3,-7,-3,-7,-5,-9,-5,-10,5,-8,5,-7,5,-3,5,-4,-5,-3,-5,-6,-5,-5,-5,-4,5,-6,5,-5,1,-6,-1,-6,-1,-5,1,-5,3,-5,4,-5,-3,-5,-4,-5,-1,-3,0,-3,1,-3,-3,-3,3,-2,3,-3,3,-1,5,-2,-3,-1,-3,-2,-5,-1,-5,-2,7,-2,7,-1,15,-1,15,-2,13,-1,13,-3,13,-2,7,-3,11,-3,10,-3,9,-3,6,-5,7,-5,14,-5,13,-5,11,-5,9,-5,9,-6,11,-6,15,-5,15,-6,15,-4,15,-3,15,-7,15,-8,7,-7,13,-7,11,-8,13,-8,6,-10,10,-10,9,-10,8,-10,7,-10,12,-10,14,-10,15,-10,11,-10,12,-8,15,-9,7,-8,8,-8,9,-8,9,7,8,7,7,7,15,8,12,7,15,9,14,9,13,9,12,9,7,9,8,9,9,9,10,9,6,9,13,7,11,7,13,6,7,6,15,7,15,6,15,2,15,3,15,5,15,4,11,5,9,5,9,4,11,4,13,4,14,4,7,4,6,4,9,2,10,2,11,2,7,2,13,1,13,2,13,0,15,1,15,0,7,0,7,1,-15,-2,-15,-1,-13,-2,-13,-1,-7,-1,-7,-3,-7,-2,-13,-3,-9,-3,-10,-3,-11,-3,-14,-5,-13,-5,-6,-5,-7,-5,-9,-5,-11,-5,-11,-6,-9,-6,-15,-4,-15,-5,-15,-6,-15,-3,-15,-7,-15,-10,-15,-9,-15,-8,-13,-7,-7,-7,-9,-8,-7,-8,-14,-10,-10,-10,-11,-10,-12,-10,-8,-10,-7,-10,-9,-10,-8,-8,-13,-8,-12,-8,-11,-8,-11,7,-12,7,-13,7,-8,7,-9,9,-6,9,-7,9,-8,9,-13,9,-12,9,-11,9,-10,9,-7,7,-9,7,-7,6,-13,6,-15,7,-15,8,-15,9,-15,6,-15,2,-15,5,-15,4,-15,3,-9,5,-11,5,-11,4,-9,4,-7,4,-6,4,-13,4,-11,2,-10,2,-9,2,-13,2,-7,1,-7,2,-7,0,-13,0,-13,1,-15,0,-15,1,-15,20,-15,19,-13,19,-7,19,-7,21,-7,20,-9,21,-10,21,-11,21,-14,23,-13,23,-6,23,-7,23,-9,23,-11,23,-11,24,-9,24,-15,22,-15,23,-15,24,-15,21,-15,25,-15,28,-15,27,-15,26,-13,25,-7,25,-9,26,-7,26,-14,28,-10,28,-11,28,-12,28,-13,28,-8,28,-7,28,-6,28,-9,28,-13,26,-12,26,-11,26,-11,11,-12,11,-13,11,-8,11,-7,11,-9,11,-7,12,-13,12,-15,11,-15,10,-15,12,-15,16,-15,13,-15,14,15,19,15,20,15,23,-15,15,-9,13,-11,13,-11,14,15,22,15,21,15,25,15,26,-9,14,-7,14,-6,14,-13,14,6,28,10,28,9,28,8,28,-5,17,-5,18,-3,17,-3,18,-14,14,5,17,3,16,3,17,7,28,12,28,1,16,0,16,-1,16,13,28,-4,14,-3,14,4,14,3,14,1,14,-1,14,-1,13,1,13,5,14,5,13,-5,15,-5,14,-5,13,5,15,5,16,5,12,5,11,-5,10,-3,12,3,12,1,11,3,11,5,10,-3,11,-1,11,-1,26,-2,26,-3,26,2,26,1,28,5,28,4,28,3,28,2,28,-3,28,-2,28,-1,28,0,28,-4,28,3,26,1,26,3,25,-3,25,-5,26,-5,27,-5,28,-5,25,5,26,5,25,5,21,5,22,-5,24,-5,23,-5,22,5,24,5,23,1,24,-1,24,-1,23,1,23,3,23,4,23,-3,23,-4,23,14,28,-1,21,0,21,1,21,15,28,11,28,3,20,3,21,5,20,-11,16,-3,19,-3,20,-5,19,-5,20,15,27,9,11,8,11,7,11,15,10,12,11,13,11,11,11,13,12,7,12,-10,16,-9,16,-13,16,-7,17,15,11,15,16,15,15,-7,16,-7,18,-13,18,-13,17,15,13,15,14,11,13,9,13,9,14,11,14,13,14,14,14,7,14,6,14,15,17,15,18,-15,18,-15,17,-15,-18,-15,-19,-13,-18,-13,-19,-7,-19,-7,-17,-7,-18,-13,-17,-9,-17,-10,-17,-11,-17,-14,-15,-13,-15,-6,-15,-7,-15,-9,-15,-11,-15,-11,-14,-9,-14,-15,-16,-15,-15,-15,-14,-15,-17,-15,-13,-15,-11,-15,-12,-13,-13,-7,-13,-9,-12,-7,-12,-8,-12,-13,-12,-12,-12,-11,-12,-11,-27,-12,-27,-13,-27,-8,-27,-9,-29,-6,-29,-7,-29,-8,-29,-13,-29,-12,-29,-11,-29,-10,-29,-14,-29,-7,-27,-9,-27,-7,-26,-13,-26,-15,-27,-15,-28,-15,-29,-15,-26,-15,-22,-15,-25,-15,-24,7,-18,7,-19,15,-19,15,-18,13,-19,13,-17,13,-18,7,-17,11,-17,10,-17,9,-17,6,-15,8,-15,14,-15,13,-15,11,-15,9,-15,9,-14,11,-14,15,-15,15,-14,-15,-23,-9,-25,-11,-25,-11,-24,15,-16,15,-17,15,-13,15,-12,-9,-24,-7,-24,-6,-24,-13,-24,7,-13,11,-12,-5,-21,-5,-20,-3,-21,-14,-24,5,-21,3,-20,3,-22,3,-21,-3,-22,1,-22,0,-22,-1,-22,-4,-24,-3,-24,4,-24,3,-24,1,-24,-1,-24,-1,-25,1,-25,5,-24,5,-25,-5,-23,-5,-24,-5,-25,-5,-22,5,-23,5,-22,5,-26,5,-27,-5,-29,-5,-28,-3,-26,3,-26,1,-27,3,-27,-4,-29,0,-29,-1,-29,-2,-29,-3,-29,2,-29,3,-29,4,-29,5,-29,1,-29,2,-27,5,-28,-3,-27,-2,-27,-1,-27,-1,-12,-2,-12,-3,-12,5,-11,2,-12,3,-12,1,-12,3,-13,-3,-13,-5,-12,-5,-11,-5,-13,5,-12,5,-13,5,-17,-5,-17,-5,-14,-5,-15,-5,-16,5,-14,5,-15,1,-14,-1,-14,-1,-15,1,-15,3,-15,4,-15,-3,-15,-4,-15,-1,-17,0,-17,1,-17,-3,-17,3,-18,3,-17,3,-19,5,-18,-11,-22,-3,-18,-5,-19,-5,-18,15,-11,7,-12,8,-12,9,-12,9,-27,8,-27,7,-27,15,-28,12,-27,11,-29,15,-29,14,-29,13,-29,12,-29,7,-29,8,-29,9,-29,10,-29,6,-29,13,-27,11,-27,13,-26,7,-26,-10,-22,-9,-22,-13,-22,-7,-21,15,-27,15,-26,15,-22,15,-23,-7,-22,-7,-20,-13,-20,-13,-21,15,-25,15,-24,11,-25,9,-25,9,-24,11,-24,13,-24,14,-24,7,-24,6,-24,9,-22,10,-22,11,-22,7,-22,13,-21,13,-22,13,-20,15,-21,15,-20,7,-20,7,-21,-15,-20,-15,-21,37,-21,37,-20,45,-20,45,-21,43,-20,43,-22,43,-21,37,-22,41,-22,40,-22,39,-22,36,-24,37,-24,44,-24,43,-24,41,-24,39,-24,39,-25,41,-25,45,-24,45,-25,17,-21,17,-20,23,-20,23,-22,45,-23,45,-22,45,-26,45,-27,23,-21,17,-22,21,-22,20,-22,37,-26,43,-26,41,-27,43,-27,36,-29,40,-29,39,-29,38,-29,37,-29,42,-29,43,-29,44,-29,45,-29,41,-29,42,-27,45,-28,37,-27,38,-27,39,-27,39,-12,38,-12,37,-12,45,-11,42,-12,25,-18,25,-19,27,-18,27,-19,19,-22,35,-18,33,-19,33,-17,33,-18,27,-17,31,-17,30,-17,29,-17,26,-15,27,-15,34,-15,33,-15,31,-15,29,-15,29,-14,31,-14,35,-15,35,-14,25,-16,25,-15,25,-14,25,-17,35,-16,35,-17,35,-13,35,-12,25,-13,25,-11,25,-12,27,-13,33,-13,31,-12,33,-12,32,-12,35,-11,27,-12,28,-12,29,-12,29,-27,28,-27,27,-27,35,-28,32,-27,31,-29,35,-29,34,-29,33,-29,32,-29,27,-29,28,-29,29,-29,30,-29,26,-29,33,-27,31,-27,33,-26,27,-26,25,-28,25,-29,35,-26,35,-22,35,-23,25,-22,25,-25,25,-24,25,-23,35,-25,35,-24,31,-25,29,-25,29,-24,31,-24,33,-24,34,-24,27,-24,26,-24,29,-22,30,-22,31,-22,27,-22,33,-21,33,-22,33,-20,35,-21,16,-24,27,-20,27,-21,25,-20,25,-21,43,-12,41,-12,43,-13,37,-13,17,-24,24,-24,23,-24,21,-24,45,-12,45,-13,45,-17,45,-16,19,-24,19,-25,21,-25,45,-14,45,-15,41,-14,39,-14,39,-15,41,-15,43,-15,44,-15,37,-15,36,-15,39,-17,40,-17,41,-17,37,-17,43,-18,43,-17,43,-19,45,-18,45,-19,37,-19,37,-18,17,-26,23,-26,21,-27,23,-27,16,-29,20,-29,19,-29,18,-29,17,-29,22,-29,23,-29,24,-29,21,-29,22,-27,17,-27,18,-27,19,-27,19,-12,17,-12,23,-12,21,-12,23,-13,17,-13,21,-14,19,-14,19,-15,21,-15,23,-15,24,-15,17,-15,16,-15,19,-17,20,-17,21,-17,17,-17,23,-18,23,-17,23,-19,17,-19,17,-18,37,17,37,18,45,18,45,17,43,16,43,17,37,16,41,16,40,16,39,16,37,14,44,14,43,14,41,14,39,14,39,13,41,13,45,14,45,13,17,17,17,18,23,18,23,16,45,15,45,16,45,12,45,11,23,17,17,16,21,16,20,16,37,12,43,12,41,11,43,11,42,11,45,10,37,11,38,11,39,11,39,26,38,26,37,26,45,27,42,26,25,20,25,19,27,20,27,19,19,16,35,20,33,19,33,21,33,20,41,28,45,28,27,21,31,21,30,21,29,21,44,28,26,23,27,23,34,23,33,23,31,23,29,23,29,24,31,24,35,23,35,24,25,22,25,23,25,21,35,22,35,21,35,25,35,26,25,25,25,28,25,27,25,26,27,25,33,25,31,26,33,26,26,28,30,28,29,28,28,28,27,28,32,28,33,28,34,28,35,28,31,28,32,26,35,27,27,26,28,26,29,26,29,11,28,11,27,11,35,10,32,11,33,11,31,11,33,12,27,12,25,10,35,11,35,12,35,16,35,15,25,16,25,13,25,14,25,15,35,13,35,14,31,13,29,13,29,14,31,14,33,14,34,14,27,14,26,14,43,28,29,16,30,16,31,16,27,16,42,28,37,28,33,17,33,16,33,18,35,17,16,14,27,18,27,17,25,18,25,17,38,28,39,28,40,28,36,28,43,26,41,26,43,25,37,25,17,14,24,14,23,14,21,14,45,26,45,25,45,21,45,22,19,14,19,13,21,13,45,24,45,23,41,24,39,24,39,23,41,23,43,23,44,23,37,23,36,23,39,21,40,21,41,21,37,21,43,20,43,21,45,20,45,19,37,19,37,20,17,12,23,12,21,11,23,11,22,11,17,11,18,11,19,11,19,26,18,26,17,26,22,26,21,28,24,28,23,28,22,28,17,28,18,28,19,28,20,28,16,28,23,26,21,26,23,25,17,25,21,24,19,24,19,23,21,23,23,23,24,23,17,23,16,23,19,21,21,21,17,21,23,20,23,21,23,19,17,19,17,20,17,1,17,0,23,0,23,2,23,1,17,2,21,2,20,2,19,2,16,4,17,4,24,4,23,4,21,4,19,4,19,5,21,5,17,6,23,6,21,7,23,7,16,9,20,9,19,9,18,9,17,9,22,9,23,9,24,9,21,9,22,7,17,7,18,7,19,7,19,-8,17,-8,24,-10,22,-10,18,-10,20,-10,16,-10,23,-8,21,-8,23,-7,17,-7,37,1,45,0,45,1,43,0,43,2,43,1,37,2,37,4,43,4,41,4,39,4,39,5,41,5,45,4,45,5,21,-6,19,-6,19,-5,45,3,45,2,45,6,45,7,21,-5,23,-5,24,-5,17,-5,37,6,43,6,41,7,43,7,36,9,40,9,39,9,25,-2,25,-1,27,-2,27,-1,16,-5,35,-2,33,-1,33,-3,33,-2,37,9,42,9,27,-3,31,-3,30,-3,29,-3,43,9,26,-5,27,-5,34,-5,33,-5,31,-5,29,-5,29,-6,31,-6,35,-5,35,-6,25,-4,25,-5,25,-6,25,-3,35,-4,35,-3,35,-7,35,-8,25,-10,25,-9,27,-7,33,-7,31,-8,33,-8,26,-10,30,-10,29,-10,27,-10,32,-10,33,-10,34,-10,35,-10,31,-10,32,-8,35,-9,27,-8,28,-8,29,-8,29,7,28,7,27,7,35,8,32,7,31,9,35,9,34,9,33,9,32,9,28,9,29,9,30,9,26,9,33,7,31,7,33,6,27,6,25,7,25,8,25,9,25,6,35,7,35,6,35,2,35,3,25,2,25,5,25,4,25,3,35,5,35,4,31,5,29,5,29,4,31,4,33,4,34,4,27,4,26,4,44,9,29,2,30,2,31,2,27,2,45,9,41,9,33,1,33,2,33,0,35,1,19,-3,27,0,27,1,25,0,25,1,42,7,45,8,37,7,38,7,39,7,39,-8,38,-8,37,-8,45,-9,42,-8,41,-10,45,-10,44,-10,43,-10,42,-10,37,-10,38,-10,39,-10,40,-10,36,-10,43,-8,41,-8,43,-7,37,-7,20,-3,21,-3,17,-3,23,-2,45,-8,45,-7,45,-3,45,-4,23,-3,23,-1,17,-1,17,-2,45,-6,45,-5,41,-6,39,-6,43,-5,44,-5,37,-5,36,-5,37,-3,43,-2,43,-3,43,-1,45,-2,45,-1,37,-2,40,18,40,19,11,-13,7,16,13,16,11,16,9,16,9,18,11,18,13,18,7,18,7,20,13,20,11,20,9,20,9,22,11,22,13,22,7,22,7,24,13,24,11,24,9,24,9,26,11,26,13,26,7,26,0,-14,0,-25,0,-18,0,-17,0,-21,3,-16,9,-16,11,-9,-2,18,-1,18,0,19,0,18,-14,-7,34,-13,26,-13,33,-28,29,-28,28,-15,29,-16,29,-18,29,-19,32,-20,31,-20,32,-24,42,-3,42,2,41,-2,41,1,39,-1,39,0,40,5,40,4,41,8,39,8,43,5,37,5,22,21,18,21,-10,-21,-10,-20,-10,-19,-10,-18,28,8,28,10,37,15,37,13,-10,20,-10,19,-10,18,-12,21,-8,21};
const uint wall_size = 2970;

// player
#define MOVE_SPEED 3.3f
float px=0.f, py=0.f;

//*************************************
// game functions
//*************************************
void resetGame(uint mode)
{
    //

    if(mode == 1){char strts[16];timestamp(&strts[0]);printf("[%s] Game Reset.\n", strts);}
    glfwSetWindowTitle(wnd, appTitle);
}

//*************************************
// update & render
//*************************************
void main_loop()
{
    // tick fps count, poll events, time, delta time, last time.
    fc++;glfwPollEvents();t=(float)glfwGetTime(),dt=t-lt,lt=t; 
#ifdef WEB
    EmscriptenPointerlockChangeEvent e;
    if(emscripten_get_pointerlock_status(&e) == EMSCRIPTEN_RESULT_SUCCESS)
    {
        if(lock_mouse == 0 && e.isActive == 1){glfwGetCursorPos(wnd, &lx, &ly);}
        lock_mouse = e.isActive;
    }
#endif

//*************************************
// game logic
//*************************************

    // player inputs
    mGetViewX(&lookx, view);
    float fms = MOVE_SPEED;
    /**/ if(ks[0]==1){px -= lookx.x * MOVE_SPEED * dt, py -= lookx.y * MOVE_SPEED * dt; fms=MOVE_SPEED*0.5f;} // A
    else if(ks[1]==1){px += lookx.x * MOVE_SPEED * dt, py += lookx.y * MOVE_SPEED * dt; fms=MOVE_SPEED*0.5f;} // D
    /**/ if(ks[2]==1){px -= lookz.x * MOVE_SPEED * dt, py -= lookz.y * fms * dt;} // W
    else if(ks[3]==1){px += lookz.x * MOVE_SPEED * dt, py += lookz.y * fms * dt;} // S

    // camera
    if(lock_mouse == 1)
    {
        glfwGetCursorPos(wnd, &mx, &my);
        static float sx=0.0,sy=0.0; // mouse smoothing
        sx = ((float)((lx-mx)*sens)+sx)*0.5f, xrot += sx, lx = mx;
        sy = ((float)((ly-my)*sens)+sy)*0.5f, yrot += sy, ly = my;
        if(free_look > 0){if(yrot > PI  ){yrot = PI;  }else if(yrot < 0.f ){yrot = 0.f; }}
        else/* regular */{if(yrot > d2PI){yrot = d2PI;}else if(yrot < 0.5f){yrot = 0.5f;}}
    }
    mIdent(&view);
    mRotate(&view, d2PI, 1.f, 0.f, 0.f);
    mRotate(&view, xrot, 0.f, 0.f, 1.f);
    mTranslate(&view, px, py, -0.5f);

    // get look dir/axes
    mGetViewZ(&lookz, view);
    mGetViewX(&lookx, view);

//*************************************
// render
//*************************************

    // clear buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    ///

    // render level
    esBindModel(1);
    for(uint i = 0; i < floor_size; i+=2)
    {
        // render view distance
        const float xm = px+level_floor[i];
        const float ym = py+level_floor[i+1];
        const float d = xm*xm + ym*ym;
        if(d < DRAW_DISTANCE)
        {
            mIdent(&model);
            mSetPos(&model, (vec){level_floor[i], level_floor[i+1], 0.f});
            updateModelView();
            esRenderModel();
        }
    }
    esBindModel(0);
    for(uint i = 0; i < wall_size; i+=2)
    {
        // lol brain melt time, yes this is mad!
        const float xd = px+level_wall[i], yd = py+level_wall[i+1];
        const float fxd = fabsf(xd), fyd = fabsf(yd);
        const uint xif = fxd < 0.6f, yif = fyd < 0.6f;
        if(xif && yif)
        {
            if(xif && fxd > fyd)
            {
                if(xd < 0.f){px -= 0.6f+xd;}
                        else{px += 0.6f-xd;}
            }
            if(yif && fyd > fxd)
            {
                if(yd < 0.f){py -= 0.6f+yd;}
                        else{py += 0.6f-yd;}
            }
        }

        // render view distance
        const float xm = px+level_wall[i];
        const float ym = py+level_wall[i+1];
        const float d = xm*xm + ym*ym;
        if(d < DRAW_DISTANCE)
        {
            mIdent(&model);
            mSetPos(&model, (vec){level_wall[i], level_wall[i+1], 0.f});
            updateModelView();
            esRenderModel();
        }
    }

    ///

    // display render
    glfwSwapBuffers(wnd);
}

//*************************************
// input
//*************************************
void key_callback(GLFWwindow* wnd, int key, int scancode, int action, int mods)
{
    if(lock_mouse == 0){return;}
    if(action == GLFW_PRESS)
    {
        if(     key == GLFW_KEY_LEFT  || key == GLFW_KEY_A){ks[0]=1;}
        else if(key == GLFW_KEY_RIGHT || key == GLFW_KEY_D){ks[1]=1;}
        else if(key == GLFW_KEY_UP    || key == GLFW_KEY_W){ks[2]=1;}
        else if(key == GLFW_KEY_DOWN  || key == GLFW_KEY_S){ks[3]=1;}
        else if(key == GLFW_KEY_F) // show average fps
        {
            if(t-lfct > 2.0)
            {
                char strts[16];timestamp(&strts[0]);
                printf("[%s] FPS: %g\n", strts, fc/(t-lfct));
                lfct = t; fc = 0;
            }
        }
        else if(key == GLFW_KEY_R){resetGame(1);} // reset game
        else if(key == GLFW_KEY_ESCAPE) // unlock mouse
        {
            lock_mouse = 0;
#ifndef WEB
            glfwSetInputMode(wnd, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            glfwGetCursorPos(wnd, &lx, &ly);
#endif
        }
    }
    else if(action == GLFW_RELEASE)
    {
        if(     key == GLFW_KEY_LEFT  || key == GLFW_KEY_A){ks[0]=0;}
        else if(key == GLFW_KEY_RIGHT || key == GLFW_KEY_D){ks[1]=0;}
        else if(key == GLFW_KEY_UP    || key == GLFW_KEY_W){ks[2]=0;}
        else if(key == GLFW_KEY_DOWN  || key == GLFW_KEY_S){ks[3]=0;}
    }
}
void mouse_button_callback(GLFWwindow* wnd, int button, int action, int mods)
{
    if(action != GLFW_PRESS)
    {
        if(lock_mouse == 1 && button == GLFW_MOUSE_BUTTON_RIGHT){free_look=0;}
        return;
    }
    if(button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if(lock_mouse == 0)
        {
            lock_mouse = 1;
#ifndef WEB
            glfwSetInputMode(wnd, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            glfwGetCursorPos(wnd, &lx, &ly);
#endif
        }
    }
    else if(button == GLFW_MOUSE_BUTTON_RIGHT){free_look = 1;}
}
void window_size_callback(GLFWwindow* wnd, int width, int height)
{
    winw = width, winh = height;
    glViewport(0, 0, winw, winh);
    aspect = (float)winw / (float)winh;
    mIdent(&projection);
    mPerspective(&projection, 60.f, aspect, 0.01f, FAR_DISTANCE);
    glUniformMatrix4fv(projection_id, 1, GL_FALSE, (float*)&projection.m[0][0]);
}
#ifdef WEB
EM_BOOL emscripten_resize_event(int eventType, const EmscriptenUiEvent *uiEvent, void *userData)
{
    winw = uiEvent->documentBodyClientWidth;
    winh = uiEvent->documentBodyClientHeight;
    window_size_callback(wnd, winw, winh);
    emscripten_set_canvas_element_size("canvas", winw, winh);
    return EM_FALSE;
}
#endif

//*************************************
// process entry point
//*************************************
int main(int argc, char** argv)
{
    // help
    printf("----\n");
    printf("James William Fletcher (github.com/mrbid)\n");
    printf("%s - Inspired by The Backrooms & Nextbots.\n", appTitle);
    printf("----\n");
    int msaa = 16;
#ifndef WEB
    if(argc >= 2){msaa = atoi(argv[1]);}
    printf("One command line argument, msaa 0-16.\n");
    printf("e.g; ./catrooms 16\n");
    printf("----\n");
#endif
    printf("Mouse Move to Look Around.\n");
    printf("Arrow Keys or WASD to Move Around.\n");
    printf("----\n");
    printf("All assets generated using LUMA GENIE (https://lumalabs.ai/genie) & TripoAI (https://www.tripo3d.ai).\n");
    printf("----\n");
    printf("%s\n", glfwGetVersionString());
    printf("----\n");

    // init glfw
    if(!glfwInit()){printf("glfwInit() failed.\n"); exit(EXIT_FAILURE);}
#ifdef WEB
    double width, height;
    emscripten_get_element_css_size("body", &width, &height);
    winw = (uint)width, winh = (uint)height;
#endif
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_SAMPLES, msaa);
    wnd = glfwCreateWindow(winw, winh, appTitle, NULL, NULL);
    if(!wnd){printf("glfwCreateWindow() failed.\n");glfwTerminate();exit(EXIT_FAILURE);}
    const GLFWvidmode* desktop = glfwGetVideoMode(glfwGetPrimaryMonitor());
#ifndef WEB
    glfwSetWindowPos(wnd, (desktop->width/2)-(winw/2), (desktop->height/2)-(winh/2)); // center window on desktop
#endif
    glfwSetWindowSizeCallback(wnd, window_size_callback);
    glfwSetKeyCallback(wnd, key_callback);
    glfwSetMouseButtonCallback(wnd, mouse_button_callback);
    glfwMakeContextCurrent(wnd);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1); // 0 for immediate updates, 1 for updates synchronized with the vertical retrace, -1 for adaptive vsync

    // set icon
    glfwSetWindowIcon(wnd, 1, &(GLFWimage){16, 16, (unsigned char*)icon_image});

//*************************************
// bind vertex and index buffers
//*************************************
    register_wall();register_floor();register_c1();register_c2();register_c3();register_c4();register_c5();
    register_c6();register_c7();register_c8();register_p1();register_p2();register_p3();register_p4();register_p5();
    register_p6();register_p7();register_p8();register_p9();register_p10();register_p11();register_p12();register_p14();
    
//*************************************
// configure render options
//*************************************
    makeLambert();

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    shadeLambert(&position_id, &projection_id, &modelview_id, &lightpos_id, &normal_id, &color_id, &ambient_id, &saturate_id, &opacity_id);
    glUniform1f(ambient_id, 0.26f);
    glUniform1f(saturate_id, 1.0f);
    window_size_callback(wnd, winw, winh);

#ifdef GL_DEBUG
    esDebug(1);
#endif

//*************************************
// execute update / render loop
//*************************************

    // init
    srand(time(0));
    srandf(time(0));
    glfwSetTime(0.0);

    // game init
    resetGame(0);

    // loop
#ifdef WEB
    emscripten_set_resize_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, EM_FALSE, emscripten_resize_event);
    emscripten_set_main_loop(main_loop, 0, 1);
#else
    while(!glfwWindowShouldClose(wnd)){main_loop();}
#endif

    // done
    glfwDestroyWindow(wnd);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}
