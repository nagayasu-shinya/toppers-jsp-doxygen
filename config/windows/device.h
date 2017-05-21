/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ�狼��Free Software Foundation 
 *  �ˤ�äƸ�ɽ����Ƥ��� GNU General Public License �� Version 2 �˵�
 *  �Ҥ���Ƥ���������������˸¤ꡤ�ܥ��եȥ��������ܥ��եȥ�����
 *  ����Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ������ۡʰʲ���
 *  ���ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����Ŭ�Ѳ�ǽ����
 *  �ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ����������Ѥˤ��ľ
 *  ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ�����ʤ���
 * 
 *  @(#) $Id: device.h,v 1.9 2003/12/15 07:19:22 takayuki Exp $
 */

#ifndef __DEVICE_H
#define __DEVICE_H

#include <cpu_rename.h>
#include <s_services.h>

#ifdef DEVICE_ENABLE

#define MAX_MSGSIZE 256

#define DEVICE_TIMEOUT INFINITE

#define OnDevice

extern struct tagDeviceGlobalVariables
{
    CRITICAL_SECTION cs;
    HANDLE ManagerSlot;
    HANDLE ListenerThread;
    HANDLE Blocker;
    HANDLE ThreadBlocker;
    HANDLE ReplySlot;
    DWORD ListenerThreadID;
} DeviceVars;

void InitializeDeviceSupportModule(void);
void FinalizeDeviceSupportModule(void);

int DeviceRead(unsigned long address, unsigned long size, void * storage);
int DeviceWrite(unsigned long address, unsigned long size, void * storage);


#define SIL_ENDIAN SIL_ENDIAN_LITTLE

/*
 *  ����ǥ������ȿž
 */
#ifndef SIL_REV_ENDIAN_H
#define	SIL_REV_ENDIAN_H(data) \
    ((VH)((((UH)(data) & 0xff) << 8) | (((UH)(data) >> 8) & 0xff)))
#endif /* SIL_REV_ENDIAN_H */

#ifndef SIL_REV_ENDIAN_W
#define	SIL_REV_ENDIAN_W(data) \
    ((VW)((((UW)(data) & 0xff) << 24) | (((UW)(data) & 0xff00) << 8) \
    | (((UW)(data)>> 8) & 0xff00) | (((UW)(data) >> 24) & 0xff)))
#endif /* SIL_REV_ENDIAN_H */

/*
 *  �����ʥ���ǥ�����Ǥ��ɽФ�
 */
Inline VB
sil_reb_mem(VP mem)
{
    VB data;
    DeviceRead((unsigned long)mem, sizeof(data), &data);
    return data;
}

Inline VH
sil_reh_mem(VP mem)
{
    VH data;
    DeviceRead((unsigned long)mem, sizeof(data), &data);
    return data;
}

Inline VW
sil_rew_mem(VP mem)
{
    VW data;
    DeviceRead((unsigned long)mem, sizeof(data), &data);
    return data;
}

Inline void
sil_rek_mem(VP mem, VP data, UINT len)
{	DeviceRead((unsigned long)mem, len, data);   }

/*
 *  ��ȥ륨��ǥ�����Ǥ��ɽФ��ʥ�ȥ륨��ǥ�����ץ��å���
 */
#define	sil_reh_lem(mem)	sil_reh_mem(mem)
#define	sil_rew_lem(mem)	sil_rew_mem(mem)

/*
 *  �ӥå�����ǥ�����Ǥ��ɽФ��ʥ�ȥ륨��ǥ�����ץ��å���
 */
Inline VH
sil_reh_bem(VP mem)
{   return SIL_REV_ENDIAN_H(sil_reh_mem(mem));   }

Inline VW
sil_rew_bem(VP mem)
{   return SIL_REV_ENDIAN_W(sil_rew_mem(mem));   }

/*
 *  �����ʥ���ǥ�����Ǥν����
 */
Inline void
sil_wrb_mem(VP mem, VB data)
{   DeviceWrite((unsigned long)mem, sizeof(data), &data);   }

Inline void
sil_wrh_mem(VP mem, VH data)
{   DeviceWrite((unsigned long)mem, sizeof(data), &data);   }

Inline void
sil_wrw_mem(VP mem, VW data)
{   DeviceWrite((unsigned long)mem, sizeof(data), &data);   }

Inline void
sil_wrk_mem(VP mem, VP data, UINT len)
{	DeviceWrite((unsigned long)mem, len, data);   }

#define	sil_wrh_lem(mem, data)	sil_wrh_mem(mem, data)
#define	sil_wrw_lem(mem, data)	sil_wrw_mem(mem, data)

/*
 *  �ӥå�����ǥ�����Ǥν���ߡʥ�ȥ륨��ǥ�����ץ��å���
 */
Inline void
sil_wrh_bem(VP mem, VH data)
{
    data = SIL_REV_ENDIAN_H(data);
    DeviceWrite((unsigned long)mem, sizeof(data), &data);   		
}

Inline void
sil_wrw_bem(VP mem, VW data)
{
    data = SIL_REV_ENDIAN_W(data);
    DeviceWrite((unsigned long)mem, sizeof(data), &data);   		
}

#else // DEVICE_ENABLE

//�ǥХ��������Ѥ��ʤ�

#define OnDevice /##/
#define InitializeDeviceSupportModule /##/
#define FinalizeDeviceSupportModule /##/

/*
#define DeviceRead(address, size, storage) \
    memcpy(storage, (void *)address, size)

#define DeviceWrite(address, size, storage) \
    memcpy((void *)address, storage, size)
*/

#define DeviceRead /##/
#define DeviceWrite /##/

#endif

#endif

