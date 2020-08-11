/******************************************************************************

                  ��Ȩ���� (C), 2013-2023, ���ڲ�˼�߿Ƽ����޹�˾

 ******************************************************************************
  �� �� ��   : iap.h
  �� �� ��   : ����
  ��    ��   : �Ŷ�
  ��������   : 2019��6��4��
  ����޸�   :
  ��������   : ������������
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2019��6��4��
    ��    ��   : �Ŷ�
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __IAP_H
#define __IAP_H

/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/
#include "stm32f4xx.h"
/*----------------------------------------------*
 * �궨��                                       *
 *----------------------------------------------*/


#define QUEUE_MAX_LEN           1024*4 //�洢����Ԫ�ص�������
#define PAGE_SIZE   1024

#define READOVER -2//�������ݳ���
#define WRITEOVER  -3//����д����Խ��
#define OK  1



enum upSteps
{
    HTTP_CONNECT = 1,
    HTTP_CONNACK,
    HTTP_SAVE_DATA,
    HTTP_CLOSE
};


typedef struct {
    volatile char data[QUEUE_MAX_LEN];
    volatile int Pwrite; //дָ��
    volatile int Pread; //��ָ��
    volatile int Count; //����������
}ReceriveType, *BINQUEUE_T;


extern ReceriveType gBinQueue;

/*----------------------------------------------*
 * ��������                                     *
 *----------------------------------------------*/



/*----------------------------------------------*
 * ģ�鼶����                                   *
 *----------------------------------------------*/



/*----------------------------------------------*
 * �ڲ�����ԭ��˵��                             *
 *----------------------------------------------*/

uint8_t IAP_JumpToApplication(void);
//void IAP_JumpToApplication(void);

int32_t IAP_DownLoadToFlash(void);

int32_t IAP_DownLoadToSTMFlash(int32_t filesize);


void ClearBinQueue(BINQUEUE_T q);
int ReadBinQueue(BINQUEUE_T queue,uint8_t *buf,uint16_t length);
int WriteBinQueue(BINQUEUE_T queue,uint8_t *buf,uint16_t length);







#endif


