/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 */


/*
 *	�ץ��å���¸�⥸�塼��(S1C33��)
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"
#include "itron.h"
#include "s1c33.h"
#include "sys_config.h"

/*
 *  CPU��å����������������
 */
UINT	tps_OrgIntLevel;

/*
 *  ����ߥͥ��ȥ�����
 */
UINT	tps_IntNestCnt;

/*
 *  ���������쥸���� �����������
 */
ER	get_Offset(INTNO);
ER	get_BitFlag(INTNO);

/*
 *  �ץ��å���¸�ν����
 */
void
cpu_initialize()
{
	tps_IntNestCnt = 0;			/* ����ߥͥ��ȥ�����Ȥν���� */
	tps_OrgIntLevel = TPS_INIT_INTLEVEL;

	/*
	 *  �����ߵ��ĥե饰�����ꤷ��OS�������γ����ߤ�ޥ�������
	 */
	set_psr((TPS_CPULOCK_LEV << 8) | S1C33_PSR_FLAG_IE);

}

/*
 *  �ץ��å���¸�ν�λ����
 */
void
cpu_terminate()
{

}

/*
 *  ��������ư����
 */
void
activate_r(void)
{
	unlock_cpu();
	Asm("xld.w %r0, ext_tsk");		/* �����֤�ext_tsk������ */
	Asm("pushn %r0");
	Asm("ld.w %%r6, %0": : "r"(runtsk->tinib->exinf));
	set_pc(runtsk->tinib->task);
}

/*
 *  �������ǥ����ѥå���
 *
 *  dispatch�ϥ���������ƥ����ȡ�CPU��å����֤ǸƤӽФ���
 *  exit_and_dispatch��Ʊ�ͤ����������ͥ뵯ư�����б����뤿��
 *  �󥿥�������ƥ����ȡ�CPU��å�������֤θƤӽФ��ˤ��б�
 *  ���Ƥ��롣
 */
void
dispatch(void)
{
	TCB * task;

	Asm("pushn %r3");
	task = runtsk;
	task->tskctxb.sp = get_sp();
	task->tskctxb.pc = && dispatch_1;	/* gcc��ĥ��ǽ����Ѥ��� */
	Asm("xjp _kernel_exit_and_dispatch");
dispatch_1:
	Asm("popn %r3");
	task = (TCB * volatile) runtsk;
	if ((task->enatex != FALSE) && (task->texptn != 0)) {
		Asm("xjp _kernel_calltex");	/* �㳰�ϥ�ɥ鵯ư	*/
	}
}

void
exit_and_dispatch(void)
{
	register UW	ulPsr;

	lock_cpu();			/* CPU���å�����	*/
	runtsk = schedtsk;
	if (runtsk != NULL) {
		set_sp(runtsk->tskctxb.sp);
		set_pc(runtsk->tskctxb.pc);
	}

	set_sp(STACKTOP);			/* �¹Բ�ǽ�ʥ��������ʤ����	*/
	ulPsr = get_psr();			/* �����ߤ���Ĥ��ƥ��٥��	*/
	ulPsr |= S1C33_PSR_FLAG_IE;	/* ȯ�����Ԥ�					*/
	set_psr(ulPsr);
	unlock_cpu();

	while (1) {
		Asm("halt");
	}
}

/*
 *  ����ߥϥ�ɥ�/CPU�㳰�ϥ�ɥ�и�����
 */
void
ret_int(void)
{
	static	TCB * task;

	reqflg = FALSE;
	task = runtsk;

	if (task == NULL) {			/* �����ɥ�����إ����פ��� */
		Asm("xjp _kernel_exit_and_dispatch");
	}

	if ((enadsp != FALSE) && (task != schedtsk)) {
#ifndef	__c33adv
		Asm("pushn %r1");
#endif	/* __c33adv */
		task->tskctxb.sp = get_sp();
		task->tskctxb.pc = && ret_int_2;/* gcc��ĥ��ǽ����� */
						/* �ǥ����ѥå������إ����� */
		Asm("xjp _kernel_exit_and_dispatch");
ret_int_2:
#ifndef	__c33adv
		Asm("popn %r1");
#endif	/* __c33adv */
	}
	task = (TCB * volatile) runtsk;
	if ((task->enatex != FALSE) && (task->texptn != 0)) {
		call_texrtn();			/* �㳰�ϥ�ɥ鵯ư	*/
	}
#ifdef	__c33adv
	Asm("pops %sor");
#else	/* __c33adv */
	Asm("ld.w %alr, %r1");
	Asm("ld.w %ahr, %r0");
#endif	/* __c33adv */

#if TPS_DAREA_CNT == 4				/* �ǡ������ꥢ�ݥ��󥿿���	*/
	Asm("popn %r11");			/* ������pop������Ԥ�		*/
#elif TPS_DAREA_CNT == 3
	Asm("popn %r12");
#elif TPS_DAREA_CNT == 2
	Asm("popn %r13");
#elif TPS_DAREA_CNT == 1
	Asm("popn %r14");
#else
	Asm("popn %r15");
#endif /* TPS_DAREA */

	Asm("reti");				/* CPU��å����֤���������	*/
						/* �������Υ����ӥ������뤫��	*/
						/* �꥿���󤹤���˲�������	*/
}


/*
 *  ����ߥ�٥��ѹ�����
 */
ER
chg_ilv(ILEVNO ilevno)
{
	UW	ulPsr;
	ER	ercd;

	LOG_CHG_ILV_ENTER(ilevno)
	CHECK_TSKCTX_UNL();
	if(ilevno > TPS_INTLEV_MAX){
		ercd = E_PAR;
	} else {
		ulPsr = get_psr();			/* ���ߤ�PSR�ͤ����	*/
		ulPsr = (ulPsr & ~S1C33_PSR_MASK_IL) | (ilevno << 8);
		set_psr(ulPsr);				/* PSR�ͤ򹹿�		*/
		ercd = E_OK;
	}
exit:
	LOG_CHG_ILV_LEAVE(ercd)				/* Set New IL		*/
	return(ercd);
}

/*
 *  ����ߥ�٥��������
 */
ER
get_ilv(ILEVNO *p_ilevno)
{
	UW	ulPsr;
	ER	ercd;

	LOG_GET_ILV_ENTER(p_ilevno)
	CHECK_TSKCTX_UNL();
	if(p_ilevno == NULL){
		ercd = E_PAR;
	} else {
		ulPsr = get_psr();			/* ���ߤγ���ߥ�٥����� */
		*p_ilevno = (ulPsr & S1C33_PSR_MASK_IL) >> 8;
		ercd = E_OK;
	}
exit:
	LOG_GET_ILV_LEAVE(ercd, piLevno)
	return(ercd);
}

#ifndef __c33pe
/*
 *  �����ȯ�����Ľ���
 */
ER
ena_int(INTNO intno)
{
	INT	iOffset, iBitFlag;

	iOffset = get_Offset(intno);			/* �쥸�������֤�������� */
	iBitFlag = get_BitFlag(intno);

	if(iOffset == E_PAR || iBitFlag == E_PAR){
		return (E_PAR);
	}
							/* �����ߤ���Ĥ��� */
	(*(s1c33Intc_t *) S1C33_INTC_BASE).bIntEnable[iOffset] |= (UB)iBitFlag;

	return (E_OK);
}

/*
 *  �����ȯ���ػ߽���
 */
ER
dis_int(INTNO intno)
{
	INT	iOffset, iBitFlag;

	iOffset = get_Offset(intno);			/* �쥸�������֤��������  */
	iBitFlag = get_BitFlag(intno);

	if(iOffset == E_PAR || iBitFlag == E_PAR){
		return (E_PAR);
	}
							/* �����ߤ�ػߤ��� */
	(*(s1c33Intc_t *) S1C33_INTC_BASE).bIntEnable[iOffset] &= ~((UB)iBitFlag);

	return (E_OK);
}

/*
 *  �����ȯ���װ����ꥢ
 */
ER
clr_int(INTNO intno)
{
	INT	iOffset, iBitFlag;

	iOffset = get_Offset(intno);			/* �쥸�������֤�������� */
	iBitFlag = get_BitFlag(intno);

	if(iOffset == E_PAR || iBitFlag == E_PAR){
		return (E_PAR);
	}
#ifdef	__c33adv
	if(intno > S1C33_INHNO_SERIAL3TX){		/* ����/�ػߥ쥸�������װ�    */
		iOffset -= 0x0d;			/* �ե饰�쥸�����Υ��ե��å� */
	}						/* ���֤����פ��ʤ�����       */
#endif /* __c33adv */
							/* �������װ��򥯥ꥢ���� */
	(*(s1c33Intc_t *) S1C33_INTC_BASE).bIntFactor[iOffset] = ((UB)iBitFlag);

	return (E_OK);
}
#else  /* __c33pe */
#error "*_int() are valid for C33 Standard/Advanced macro."
#endif /* __c33pe */
