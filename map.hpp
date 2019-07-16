#ifndef _MAP_H
#define _MAP_H
struct reg
{
  int num;     //rd编号
  int val;     //rd内部的值
};
struct mem
{
  int address;            //内存地址
  unsigned char val;      //内存对应的值
};
#endif // _MAP_H
