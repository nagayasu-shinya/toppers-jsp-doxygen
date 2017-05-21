/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2010 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Katsuhiro Amano
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
 *  @(#) $Id: cpu_config.c,v 1.18 2007/03/23 07:22:15 honda Exp $
 */

#include "jsp_kernel.h"
#include "check.h"
#include "task.h"

#include <hw_serial.h>

/*
 *  �ץ��å���¸�⥸�塼���H8�ѡ�
 */

#ifdef SUPPORT_CHG_IPM
/*
 *  ����������ƥ����ȤǤγ���ߥޥ���
 */
volatile UB task_intmask = 0;
#endif /* SUPPORT_CHG_IPM */

/*
 *  �󥿥�������ƥ����ȤǤγ���ߥޥ���
 */

volatile UB int_intmask = 0;

/*
 *  ����ߥͥ��ȥ�����
 */

volatile UB intnest = 0;

/*
 *  CPU��å����֤�ɽ���ե饰
 *����TRUE ��CPU��å�����
 *����FALSE��CPU��å��������
 */
volatile BOOL iscpulocked = TRUE;

/*
 *  �����ޤΥץ饤����ƥ���٥������ѤΥǡ���
 *      �����hw_timer.h�˵��Ҥ���٤����������������
 *      hw_timer.h�򥤥󥯥롼�ɤ����ե�����Ǥ��٤Ƽ��β������
 *�����������ΰ����ͭ���Ƥ��ޤ����ᡢ���ΤϤ����˵��Ҥ��롣
 */
const IRC TIMER_IRC = {(UB*)SYSTEM_TIMER_IPR,
                        SYSTEM_TIMER_IP_BIT,
                        SYSTEM_TIMER_IPM
                      };

/*
 *  �٥����ơ��֥�ν������for RedBoot��
 */
#ifdef REDBOOT

/*  VECTOR_TABLE_ADDR��sys_config.h���������  */
extern void	vector(void);

static void
copy_vector_table(void)
{
	UW n;
	UW *dst = (UW *)VECTOR_TABLE_ADDR;	/* �٥����ơ��֥륳�ԡ��� */
	UW *src = (UW *)vector;			/* �٥����ơ��֥륳�ԡ��� */
	TMP_VECTOR tmp_vector;

	load_vector(&tmp_vector);
	for (n = 0; n < VECTOR_SIZE; n++) {
		*dst = JMP_OPECODE | (*src);	/* jmp̿����ղ� */
		++dst;
		++src;
	}
	save_vector(&tmp_vector);
}
#endif	/* of #ifdef REDBOOT */

/*
 *  �ץ��å���¸�ν����
 */

#ifndef H8IPRA_INI
#define H8IPRA_INI	0
#endif  /*  H8IPRA_INI  */

#ifndef H8IPRB_INI
#define H8IPRB_INI	0
#endif  /*  H8IPRB_INI  */

void
cpu_initialize(void)
{
	/* 
	 *��CCR ��UI�ӥåȤ�����ߥޥ����ӥåȤȤ��ƻ��Ѥ��롣
	 *����SYSCR.UE��0
	 */
	bitclr((UB*)H8SYSCR, H8SYSCR_UE_BIT);
	
	/* 
	 *�����٤Ƥγ���ߥץ饤����ƥ����٥룰�ˤ���
	 *
	 *��������˥��䥹���֤�����ߤ���Ѥ�����
	 *��������H8IPRA_INI��H8IPRB_INI��������ơ��������Ƥ��ݻ����롣
	 *��������IER�쥸�����ϥ����ͥ�¦���ѹ����Ƥ��ʤ��Τǡ����Τޤޤ�
	 *���������褤��
	 */
	sil_wrb_mem((VP)H8IPRA, H8IPRA_INI);
	sil_wrb_mem((VP)H8IPRB, H8IPRB_INI);
	
	SCI_initialize(SYSTEM_PORTID);

#ifdef REDBOOT
	copy_vector_table();
#endif	/* of #ifdef REDBOOT */
}

/*
 *  �ץ��å���¸�ν�λ����
 */

void
cpu_terminate(void)
{
}

#ifdef SUPPORT_CHG_IPM
/*
 *  ����ߥޥ������ѹ�
 *
 *��IPM������Ǥ����ͤȤ���IPM_LEVEL0��IPM_LEVEL1��IPM_LEVEL2���ޥ���
 *���������Ƥ��롣
 *
 *
 *��IPM_LEVEL0����٥룰�����٤Ƥγ���ߤ�����դ���
 *��IPM_LEVEL1����٥룱��NMI����ӥץ饤����ƥ���٥룱�γ���ߤΤߤ�
 *�����������������������������դ���
 *��IPM_LEVEL2����٥룲��NMI�ʳ��γ���ߤ�����դ��ʤ�
 *
 *  IPM ����٥�0�ʳ��λ��ˤ⡤�������ǥ����ѥå�����α����ʤ���IPM �ϡ�
 *  �������ǥ����ѥå��ˤ�äơ��������¹Ծ��֤ˤʤä��������ذ����Ѥ�
 *  ��롥���Τ��ᡤ���������¹���ˡ��̤Υ������ˤ�ä� IPM ���ѹ���
 *  ����礬���롥JSP�����ͥ�Ǥϡ�IPM ���ѹ��ϥ������㳰�����롼��
 *  ��ˤ�äƤⵯ����Τǡ��̤Υ������ˤ�ä� IPM ���ѹ�����뤳�Ȥ�
 *  ��äơ��������񤷤��ʤ�����Ͼ��ʤ��Ȼפ��롥IPM ���ͤˤ�äƥ�
 *  �����ǥ����ѥå���ػߤ��������ˤϡ�dis_dsp ��ʻ�Ѥ���Ф褤��
 */
SYSCALL ER
chg_ipm(IPM ipm)
{
        ER      ercd = E_OK;

        LOG_CHG_IPM_ENTER(ipm);
        CHECK_TSKCTX_UNL();
        CHECK_PAR( (ipm == IPM_LEVEL0) || (ipm == IPM_LEVEL1) || (ipm == IPM_LEVEL2) );

        t_lock_cpu();
        task_intmask = ipm;
        t_unlock_cpu();
        
    exit:
        LOG_CHG_IPM_LEAVE(ercd)
        return(ercd);
}

/*
 *  ����ߥޥ����λ���
 */
SYSCALL ER
get_ipm(IPM *p_ipm)
{
        ER      ercd = E_OK;

        LOG_GET_IPM_ENTER(p_ipm);
        CHECK_TSKCTX_UNL();

        t_lock_cpu();
        *p_ipm = task_intmask;
        t_unlock_cpu();

    exit:
        LOG_GET_IPM_LEAVE(ercd, *p_ipm);
        return(ercd);
}

#endif /* SUPPORT_CHG_IPM */

/*****�ʲ����������ȤΥ��󥿡��ե������˴ޤޤ�ʤ���ʬ*********/

/*
 * ̤��������ȯ�����Υ��顼����
 * ������Ͽ����Ƥ��ʤ�����ߤ�ȯ������ȸƤӽФ����
 * 
 * �������å���¤
 *���� +0:er0
 *���� +4:er1
 *���� +8:er2
 *����+12:er3
 *����+16:er4
 *����+20:er5
 *����+24:er6
 *����+28:crr
 *����+29:pc
 *����+32��:��������˻��Ѥ���Ƥ��������å��ΰ�
 */

/*
 * �����ȯ��ľ���Υ����å��ݥ��󥿤ޤǤΥ��ե��å�
 */
#define OFFSET_SP	32u

void cpu_experr(EXCSTACK *sp)
{
    UW sp2, pc, ccr, tmp;
    
    sp2 = (UW)sp + OFFSET_SP;
    tmp = sp->pc;
    ccr = (tmp >> 24u) & 0xffu;	/*  ���1�Х���  */
    pc = tmp & 0x00ffffffu;	/*  ����3�Х���  */
    
    syslog(LOG_EMERG, "Unexpected interrupt.");
    syslog(LOG_EMERG, "PC  = 0x%08x SP  = 0x%08x CCR  = 0x%02x",
                       pc, sp2, ccr);
    syslog(LOG_EMERG, "ER0 = 0x%08x ER1 = 0x%08x ER2 = 0x%08x ER3 = 0x%08x",
                       sp->er0, sp->er1, sp->er2, sp->er3);
    syslog(LOG_EMERG, "ER4 = 0x%08x ER5 = 0x%08x ER6 = 0x%08x",
                       sp->er4, sp->er5, sp->er6);
    while(1)
    	;
}


/*
 *   HEW��I/O���ߥ�졼�����
 *   ���׸�Ƥ�����ɥ쥹���˰�¸��������24�ӥåȥ��ɥ쥹�����ꤷ�Ƽ���
 */
#ifdef HEW_SIMULATOR

/*  ��ǽ�����ɡ�2�Х��ȡ�  */
#define GETC	0x0111
#define PUTC	0x0112

/*  HEW��I/O���ߥ�졼�����ǽ�ƤӽФ�  */
void hew_io_sim(UH code, void *adr);

void hew_io_sim_putc(char c)
{
	UB buf = (UB)c;			/*  �Хåե�  */
	UB *parmblk = &buf;		/*  �ѥ�᡼���֥�å�  */
	UB **p = &parmblk;		/*  ������������Ƭ���ɥ쥹  */
	UH code = PUTC;			/*  ��ǽ������  */
	
	hew_io_sim(code, p);
}

extern BOOL hew_io_sim_snd_chr(char c);

BOOL hew_io_sim_snd_chr(char c)
{
	hew_io_sim_putc(c);
	return TRUE;
}

extern INT hew_io_sim_rcv_chr(void);

INT hew_io_sim_rcv_chr(void) {
	UB buf;					/*  �Хåե�  */
	UB *parmblk = &buf;		/*  �ѥ�᡼���֥�å�  */
	UB **p = &parmblk;		/*  ������������Ƭ���ɥ쥹  */
	UH code = GETC;			/*  ��ǽ������  */
	
	hew_io_sim(code, p);
	return(buf);
}

#endif /* HEW_SIMULATOR */

/*
 *   �����ƥ�ʸ��������λ���
 */
#ifdef HEW_SIMULATOR
#define CPU_PUT_CHAR(c) hew_io_sim_putc(c)

#else	/* HEW_SIMULATOR */
#define CPU_PUT_CHAR(c) SCI_wait_putchar(SYSTEM_SCI, c)

#endif	/* HEW_SIMULATOR */

void
cpu_putc(char c)
{
    if (c == '\n') {
        CPU_PUT_CHAR('\r');
    }
    CPU_PUT_CHAR(c);
}

/*
 *  local_memcpy
 *
 *    ɸ�� C �饤�֥��� memcpy ��Ʊ�������ॳ�ԡ��ؿ�
 *    ��󥯻��˥��顼��ȯ�����뤿�ᡢ̾�����Ѥ��Ƥ��롣
 *    �ޤ�����󥯥�����ץȤκǸ�ιԤ�
 *
 *       PROVIDE(_memcpy = _local_memcpy);
 *
 *    ���ɲä�����
 *
 *    eepmov.w̿���Ȥ�������ΨŪ�������ǡ���ž����ϡ�Ĺ�����֡�
 *    ����߶ػߤˤʤäƤ��ޤ��Τǡ����Ѥ��Ƥ��ʤ���
 */

void *
local_memcpy (void *out, const void *in, size_t n)
{
    char *o = out;
    const char *i = in;

    while (n > 0) {
        *o = *i;
        ++o;
        ++i;
        --n;
    }
    return out;
}

