#ifndef _MAP_H
#define _MAP_H
struct reg
{
  int num;     //rd���
  int val;     //rd�ڲ���ֵ
};
struct mem
{
  int address;            //�ڴ��ַ
  unsigned char val;      //�ڴ��Ӧ��ֵ
};
#endif // _MAP_H
