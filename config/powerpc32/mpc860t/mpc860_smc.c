/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 *  @(#) $Id: mpc860_smc.c,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *   MPC860��¢���ꥢ�롦�ޥ͡������ȥ���ȥ���SMC1�� �ʰץɥ饤��
 *��������
 *��������SMC1�Τߤ򥵥ݡ��Ȥ��Ƥ���
 *
 *��������smc.{c,h}��hw_serial.h��ʬ��δ��
 *��������������smc.{c,h}�����ꥢ��ǥХ����˰�¸������ʬ�Τߵ���
 *��������������hw_serial.h������ߥ���ȥ����¸
 *������������
 *������������������å����ȿ���¸�ˤĤ���
 *�������������������ǥХ�����¸�Υѥ�᡼����mpc860_smc.c����Ѱդ��롣
 *�������������������縵�Υ���å����ȿ��ϥ���ѥ��륪�ץ����Ȥ���Ϳ����
 */

#include <s_services.h>
#include <mpc860_smc.h>

/*
 *  ����ȥ���쥸���������
 */

/*  SMC�⡼�ɥ쥸����  */
#define SMCMR1          (VH *)(IMMR_BASE + 0xa82)
#define SMCMR_SM_UART   BIT10_16    /*  SMC�⡼�ɡ�UART  */
#define SMCMR_TEN       BIT14_16    /*  SMC�������͡��֥�  */
#define SMCMR_REN       BIT15_16    /*  SMC�������͡��֥�  */


/*
 *  30.2.3 �ѥ�᡼��RAM
 */
/*  �Хåե����ǥ�������ץ�BD����Ƭ���ɥ쥹  */
#define BD1_BASE    (IMMR_BASE + 0x3e80)
#define RBASE1      (VH *)BD1_BASE          /*  RxBD�١������ɥ쥹  */
#define TBASE1      (VH *)(BD1_BASE+2)      /*  TxBD�١������ɥ쥹  */
#define RFCR1       (VB *)(BD1_BASE+4)      /*  �����ե��󥯥���󥳡���  */
					    /*  �Х��Ƚ�ʼ�����  */
#if SIL_ENDIAN == SIL_ENDIAN_BIG	    /* �ӥå�����ǥ����� */
#define RFCR_BO     0x10
#else /* SIL_ENDIAN == SIL_ENDIAN_BIG */    /* ��ȥ륨��ǥ����� */
#define RFCR_BO	    0x08
#endif /* SIL_ENDIAN == SIL_ENDIAN_BIG */

#define TFCR1       (VB *)(BD1_BASE+5)      /*  �����ե��󥯥���󥳡���  */
					    /*  �Х��Ƚ��������  */
#if SIL_ENDIAN == SIL_ENDIAN_BIG	    /* �ӥå�����ǥ����� */
#define TFCR_BO     0x10
#else /* SIL_ENDIAN == SIL_ENDIAN_BIG */    /* ��ȥ륨��ǥ����� */
#define TFCR_BO	    0x08
#endif /* SIL_ENDIAN == SIL_ENDIAN_BIG */

/*
 *  30.3.2 UART�ξ��Υѥ�᡼��RAM
 */
#define MRBLR1      (VH *)(BD1_BASE+6)      /*  ��������Хåե�Ĺ  */
#define RBPTR1      (VH *)(BD1_BASE+0x10)   /*  RxBD�ݥ���  */
#define TBPTR1      (VH *)(BD1_BASE+0x20)   /*  TxBD�ݥ���  */
                                            /*  ���祢���ɥ륭��饯����  */
#define MAX_IDL1    (VH *)(BD1_BASE+0x28)
#define IDLC1       (VH *)(BD1_BASE+0x2a)   /*  ��������ɥ롦������  */
#define BRKLN1      (VH *)(BD1_BASE+0x2c)   /*  �ǽ������֥졼��Ĺ  */
                                            /*  �����֥졼����參����  */
#define BRKEC1      (VH *)(BD1_BASE+0x2e)
                                    /*  �֥졼��������ȥ쥸������������  */
#define BRKCR1      (VH *)(BD1_BASE+0x30)
#define R_MASK1     (VH *)(BD1_BASE+0x32)   /*  ����ӥåȡ��ޥ���  */


/*
 *  �ǥ奢��ݡ��ȡ������˳��ݤ����ΰ�
 */

/*
 *  �Хåե����ǥ�������ץ�BD�Υ١������ɥ쥹
 */
#define RxBD_BASE_ADDRESS   0x0     /*  RxBD�١������ɥ쥹  */
#define TxBD_BASE_ADDRESS   0x8     /*  TxBD�١������ɥ쥹  */

/*  30.3.10 �����ѥХåե��ǥ�������ץ�RxBD  */
#define RxBD        (DUAL_PORT_RAM + RxBD_BASE_ADDRESS)
#define RxBD_STATUS (VH *)RxBD     	/*  ���ơ�����������  */
#define RxBD_LENGTH (VH *)(RxBD+2) 	/*  �ǡ���Ĺ  */
#define RxBD_BUFFP  (VW *)(RxBD+4) 	/*  �����Хåե��ݥ���  */

/*  30.3.11 �����ѥХåե��ǥ�������ץ�TxBD  */
#define TxBD        (DUAL_PORT_RAM + TxBD_BASE_ADDRESS)
#define TxBD_STATUS (VH *)TxBD     	/*  ���ơ�����������  */
#define TxBD_LENGTH (VH *)(TxBD+2) 	/*  �ǡ���Ĺ  */
#define TxBD_BUFFP  (VW *)(TxBD+4) 	/*  �����Хåե��ݥ���  */

/*  �����ѥХåե��ǥ�������ץ�RxBD  */
/*  ���֥��ơ�����������ץե�����ɤ����  */
#define RxBD_STATUS_E       BIT0_16     /*  ����  */
#define RxBD_STATUS_W       BIT2_16     /*  ��å�  */
#define RxBD_STATUS_I       BIT3_16     /*  �����  */
#define RxBD_STATUS_CM      BIT6_16     /*  ��³�⡼��  */
#define RxBD_STATUS_ID      BIT7_16     /*  �����ɥ����  */
#define RxBD_STATUS_BR      BIT10_16    /*  �֥졼������  */
#define RxBD_STATUS_FR      BIT11_16    /*  �ե졼�ߥ󥰡����顼  */
#define RxBD_STATUS_PR      BIT12_16    /*  �ѥ�ƥ������顼  */
#define RxBD_STATUS_OV      BIT14_16    /*  �����С����  */

/* �����ѥХåե��ǥ�������ץ�TxBD  */
/*  ���֥��ơ�����������ץե�����ɤ����  */
#define TxBD_STATUS_R       BIT0_16     /*  ��ǥ�  */
#define TxBD_STATUS_W       BIT2_16     /*  ��å�  */
#define TxBD_STATUS_I       BIT3_16     /*  �����  */
#define TxBD_STATUS_CM      BIT6_16     /*  ��³�⡼��  */
#define TxBD_STATUS_P       BIT7_16     /*  �ץꥢ��֥�  */

/*  30.3.12 SMC UART���٥�ȥ쥸����  */
#define SMCE1           (VB *)(IMMR_BASE + 0xa86)
#define SMCE_BRKE       BIT1_8      /*  �֥졼���ǽ�  */
#define SMCE_BRK        BIT3_8      /*  �֥졼������饯������  */
#define SMCE_BSY        BIT5_8      /*  �ӥ������  */
#define SMCE_TX         BIT6_8      /*  �����Хåե�  */
#define SMCE_RX         BIT7_8      /*  �����Хåե�  */

/*  SMC UART�ޥ����쥸����  */
#define SMCM1           (VB *)(IMMR_BASE + 0xa8a)
#define SMCM_BRKE       BIT1_8      /*  �֥졼���ǽ�  */
#define SMCM_BRK        BIT3_8      /*  �֥졼������饯������  */
#define SMCM_BSY        BIT5_8      /*  �ӥ������  */
#define SMCM_TX         BIT6_8      /*  �����Хåե�  */
#define SMCM_RX         BIT7_8      /*  �����Хåե�  */

#define PIC_BUFFER_SIZE     1      		/*  �Хåե�������  */

volatile static UB Rx_buffer[PIC_BUFFER_SIZE];	/*  �����Хåե�  */
volatile static UB Tx_buffer[PIC_BUFFER_SIZE];	/*  �����Хåե�  */


/*
 *  �ܡ��졼�����������
 *  
 *  ����Ʊ���ξ��ϡ�16����å����Ѥ���Τ�16�ǳ�äƤ���
 *  �ʥ桼�����������16ʬ�����Ƥ���櫓�ǤϤʤ���
 *  
 */
#define MHZ		1000000

#define BRGC1_CD_VAL		\
	(((SYSTEM_CLOCK * MHZ * 10 + 10) / (16 * BAUD_RATE * 10)) - 1) 

/*  BRGC1�쥸������CD�ե�����ɤ�20�ӥåȤ����¤���Ƥ���  */
#if (BRGC1_CD_VAL & ~0xfffff) != 0
�������ǥ���ѥ��륨�顼
#endif


/*
 *  ʬ����ȥӥåȥ졼�Ȥ�����
 *
 */


/*
 *  �ܡ��졼������塢����å������ꤹ��ޤǤ��Ԥ�����
 *  ���ʺǽ��1�ӥå�ʬ�ˡ�
 *  BPS=9600bps�ξ��
 *  ��t = 1 / BPS = 104,167 = 105,000[nsec]
 */
#define SMC_1BIT_TIME 	105000


/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 *  ��2ch���ݡ��Ȥ˳�ĥ������Ͻ�����ѤΥǡ�����ޤ��
 */
struct sio_port_control_block {
	VP_INT		exinf;		/* ��ĥ���� */
	BOOL		openflag;	/* �����ץ�Ѥߥե饰 */
};

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��Υ��ꥢ
 *  ����ID = 1 ��SMC1���б������Ƥ��롥
 */
static SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  ���ꥢ��I/O�ݡ���ID��������֥�å�����Ф�����Υޥ���
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))


#define	CODE_LF		0x0a		/*  ���ԥ�����  */

/*  ����饯����������Ԥ�����  */
#ifdef DOWNLOAD_TO_RAM      /*  �ǥХå���  */

#define	DELAY_CH	      0		/*  �̾�Υ���饯��  */
#define	DELAY_LF	5000000		/*  ���ԥ�����  */

#else /* DOWNLOAD_TO_RAM */ /*  ROM��  */

#define	DELAY_CH	4000000		/*  �̾�Υ���饯��  */
#define	DELAY_LF	1000000		/*  ���ԥ�����  */

#endif /* DOWNLOAD_TO_RAM */



/*
 *  ʸ��������Ǥ��뤫��
 */
Inline BOOL
smc_getready(SIOPCB *siopcb)
{
	VH status;
	
	status = mpc860_reh_mem(RxBD_STATUS);
	return(!(status & RxBD_STATUS_E));
}

/*
 *  ʸ���������Ǥ��뤫��
 */
Inline BOOL
smc_putready(SIOPCB *siopcb)
{
	VH status;

	status = mpc860_reh_mem(TxBD_STATUS);
	return(!(status & TxBD_STATUS_R));
}

/*
 *  ��������ʸ���μ�Ф�
 */
Inline char
smc_getchar(SIOPCB *siopcb)
{
	char c;
	SIL_PRE_LOC;
	
	SIL_LOC_INT();		/*  ����߶ػ�  */
    	c = Rx_buffer[0];
    	
    	/*  ��ա������Хåե������������ξ��Τ�ͭ��  */
    	mpc860_orh_mem(RxBD_STATUS, RxBD_STATUS_E);
    	SIL_UNL_INT();		/*  ����ߵ���  */
    	return(c);
}

/*
 *  ��������ʸ���ν����
 */
Inline void
smc_putchar(SIOPCB *siopcb, char c)
{
	SIL_PRE_LOC;

	SIL_LOC_INT();		/*  ����߶ػ�  */
    	Tx_buffer[0] = c;
    	
    	/*  ��ա������Хåե������������ξ��Τ�ͭ��  */
    	mpc860_orh_mem(TxBD_STATUS, TxBD_STATUS_R);
    	
    	SIL_UNL_INT();		/*  ����ߵ���  */

	/*
	 *  ʸ���������ɤ����ᡢ�Ԥ����֤������
	 */
	sil_dly_nse(DELAY_CH);

    	/*  ���ԥ����ɤξ��  */
    	if (c == CODE_LF) {
		sil_dly_nse(DELAY_LF);
	}
}

/*
 *  SIO�ɥ饤�Фν�����롼����
 */
void
smc_initialize()
{
	SIOPCB	*siopcb;
	UINT	i;

	/*
	 *  ���ꥢ��I/O�ݡ��ȴ����֥�å��ν����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
		siopcb->openflag = FALSE;
	}
}


/*
 *  �����ץ󤷤Ƥ���ݡ��Ȥ����뤫��
 */
BOOL
smc_openflag(void)
{
	return(siopcb_table[0].openflag);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
smc_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb;

	siopcb = get_siopcb(siopid);
	     					/*  ���������  */
	mpc860_andh_mem(SMCMR1, ~(SMCMR_TEN | SMCMR_REN));

	/*
	 *  �ԥ󡦥�������
	 *  �����ݡ���B������
	 *����������BP25�ԥ�SMTXD1
	 *����������BP24�ԥ�SMRXD1
	 */
         				/*  ���ѥڥ�ե���뵡ǽ����  */
     	mpc860_orw_mem(PBPAR, (PBPAR_DD24 | PBPAR_DD25));
        				/*  �ڥ�ե���뵡ǽ0����  */
     	mpc860_andw_mem(PBDIR, ~(PBDIR_DR24 | PBDIR_DR25));
        				/*  �����ƥ��֤˥ɥ饤��  */
     	mpc860_andw_mem(PBODR, ~(PBODR_OD24 | PBODR_OD25));

    	/*
    	 *  VCOUT����BRGCLK�ؤ�ʬ����������
    	 *      SCCR.DFBRG=00��ʬ���棱
    	 */
    	unlock_sccr();          		/*  SCCR�����å�  */
    	mpc860_andw_mem(SCCR, ~SCCR_DFBRG);    	/*  ʬ��������  */
    	lock_sccr();            		/*  SCCR��å�  */

    	/*
    	 *  �ܡ��졼�������BRG1��
    	 *  ����EN=1��BRG������ȥ��͡��֥�
    	 *  ����EXTC=00������å���������BRGCLK������
    	 *  ����ATB=0�������ȥܡ���ǽ�ǥ������֥�
    	 *  ����CD��ʬ����
    	 *  ����DIV16��16ʬ�����뤫�ݤ�
    	 */
    	mpc860_wrw_mem(BRGC1, BRGC1_EN | (BRGC1_CD_VAL<<1));
    
    	/*
    	 *  BRG1��SMC1����³
    	 *  ����SMC1=0��NMSI�⡼�ɡ�¿�Ų����ʤ���
    	 *  ����SMC1CS=000������å�������BRG1
    	 */
    	mpc860_andw_mem(SIMODE, ~(SIMODE_SMC1 | SIMODE_SMC1CS));
    
    	/*������å������ꤹ��ޤ��Ԥ� */
    	sil_dly_nse(SMC_1BIT_TIME);

    	/*
    	 *  �Хåե����ǥ�������ץ�BD������
    	 */
    					/*  RxBD�١������ɥ쥹  */
    	mpc860_wrh_mem(RBASE1, RxBD_BASE_ADDRESS);
         				/*  TxBD�١������ɥ쥹  */
    	mpc860_wrh_mem(TBASE1, TxBD_BASE_ADDRESS);

    	/*
    	 *  �̿��ץ��å�CP��INIT RX AND TX PARAMETERS���ޥ�ɤ�ȯ��
    	 */
    	mpc860_CP_command(CPCR_INIT_RX_TX_PARAMETERS, CPCR_CH_NUM_SMC1);
    
    	/*  SDMA��U�Х�Ĵ��ͥ���٤�����  */
    	mpc860_wrw_mem(SDCR, SDCR_RAID_RB5);   /*  ͥ����5���̾����  */

    	/*  �Хåե����ǥ�������ץ�BD�Υ���ǥ���������  */
    	mpc860_wrb_mem(RFCR1, RFCR_BO);		/*  ����  */
    	mpc860_wrb_mem(TFCR1, TFCR_BO);		/*  ����  */
    	    			/*  ��������Хåե�Ĺ  */
    	mpc860_wrh_mem(MRBLR1, PIC_BUFFER_SIZE);
       		/*  �����ɥ륭��饯�������е�ǽ�ǥ������֥�  */
    	mpc860_wrh_mem(MAX_IDL1, 0);
    
    	/*  �����֥졼���˴ؤ��������ɬ�פʤ��Τǥ��ꥢ  */
    	mpc860_wrh_mem(BRKLN1, 0);
    	mpc860_wrh_mem(BRKEC1, 0);
    
    	/*  STOP TRANSMIT���ޥ�ɤ����������֥졼������饯���ο�������  */
    	mpc860_wrh_mem(BRKCR1, 1);

    	/*  �����Хåե����ǥ�������ץ�RxBD�ν����  */
    	mpc860_wrh_mem(RxBD_STATUS,
                 RxBD_STATUS_E | RxBD_STATUS_W | RxBD_STATUS_I);
                /*  E�ե饰���å�  */
                /*  W=1���ơ��֥���κǽ�BD  */
                /*  I=1�����������ȯ��  */

    	mpc860_wrh_mem(RxBD_LENGTH, PIC_BUFFER_SIZE);  /*  �ǡ���Ĺ  */
       					/*  �����Хåե��ݥ���  */
    	mpc860_wrw_mem(RxBD_BUFFP, (VW)Rx_buffer);

    	/*  �����Хåե����ǥ�������ץ�TxBD�ν����  */
    	mpc860_wrh_mem(TxBD_STATUS,
    		TxBD_STATUS_R | TxBD_STATUS_W | TxBD_STATUS_I);
                /*  R�ե饰���å�  */
                /*  W=1���ơ��֥���κǽ�BD  */
                /*  I=1�����������ȯ��  */

    	mpc860_wrh_mem(TxBD_LENGTH, PIC_BUFFER_SIZE);  /*  �ǡ���Ĺ  */
    					/*  �����Хåե��ݥ���  */
    	mpc860_wrw_mem(TxBD_BUFFP, (VW)Tx_buffer);
    
    	/*  �����Υ��٥�Ȥ򥯥ꥢ  */
    	mpc860_wrb_mem(SMCE1,
    		SMCE_BRKE | SMCE_BRK | SMCE_BSY | SMCE_TX | SMCE_RX);

    	/*  ���٤Ƥ�UART����ߤ����  */
    	mpc860_wrb_mem(SMCM1,
     		SMCM_BRKE | SMCM_BRK | SMCM_BSY | SMCM_TX | SMCM_RX);
    
    	/*  SMC�⡼������  */
    	mpc860_wrh_mem(SMCMR1, (VH)((0x9<<11) | SMCMR_SM_UART));
        	/*  
        	 *  CLEN=9������饯��Ĺ
        	 *  SL=0��1���ȥåץӥå�
        	 *  PEN=0���ѥ�ƥ��ʤ�
        	 *  SM=10��SMC�⡼�� UART
        	 *  DM=00�����ǥ⡼�� �̾�ư��
        	 *  TEN=0��SMC�����ǥ������֥�
        	 *  REN=0��SMC�����ǥ������֥�
        	 *   ���λ����ǤϤޤ�������������⥤�͡��֥�ǤϤʤ�
        	 */
    
    	mpc860_orh_mem(SMCMR1, (SMCMR_TEN | SMCMR_REN));
        	/*  
        	 *  �嵭�˲ä���
        	 *  ��TEN=1��SMC�������͡��֥�
        	 *  ��REN=1��SMC�������͡��֥�
        	 */

	siopcb->exinf = exinf;
	siopcb->openflag = TRUE;
	return(siopcb);
}

/*
 *  ���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
smc_cls_por(SIOPCB *siopcb)
{
         					/*  ���������  */
	mpc860_andh_mem(SMCMR1, ~(SMCMR_TEN | SMCMR_REN));
	siopcb->openflag = FALSE;
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
BOOL
smc_snd_chr(SIOPCB *siopcb, char c)
{
	if (smc_putready(siopcb)) {
		smc_putchar(siopcb, c);
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
INT
smc_rcv_chr(SIOPCB *siopcb)
{
	if (smc_getready(siopcb)) {
		return((INT)(UB) smc_getchar(siopcb));
	}
	return(-1);
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
smc_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	SIL_PRE_LOC;
	
	switch (cbrtn) {
	case SIO_ERDY_SND:	/* �����������׵����� */
		SIL_LOC_INT();
		mpc860_orh_mem(SMCMR1, SMCMR_TEN);
		SIL_UNL_INT();
		break;
	case SIO_ERDY_RCV:	/* �����������׵����� */
		SIL_LOC_INT();
		mpc860_orh_mem(SMCMR1, SMCMR_REN);
		SIL_UNL_INT();
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
smc_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	SIL_PRE_LOC;

	switch (cbrtn) {
	case SIO_ERDY_SND:	/* �����������׵��ػ� */
		SIL_LOC_INT();
		mpc860_andh_mem(SMCMR1, ~SMCMR_TEN);
		SIL_UNL_INT();
		break;
	case SIO_ERDY_RCV:	/* �����������׵��ػ� */
		SIL_LOC_INT();
		mpc860_andh_mem(SMCMR1, ~SMCMR_REN);
		SIL_UNL_INT();
		break;
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф�����������߽���
 */
Inline void
smc_isr_siop_out(SIOPCB *siopcb)
{
	/*  SMCE1�Ǥγ�����װ��Υ����å��ϺѤ�Ǥ���  */
	
	if (smc_putready(siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		smc_ierdy_snd(siopcb->exinf);
	}
}

/*
 *  ���ꥢ��I/O�ݡ��Ȥ��Ф����������߽���
 */
Inline void
smc_isr_siop_in(SIOPCB *siopcb)
{
	/*  SMCE1�Ǥγ�����װ��Υ����å��ϺѤ�Ǥ���  */

	if (smc_getready(siopcb)) {
		/*
		 *  �������Υ�����Хå��롼�����ƤӽФ���
		 */
		smc_ierdy_rcv(siopcb->exinf);
	}
}

/*
 *  SIL����Ѥ����Ȥ��Υ���ǽ
 */
#ifdef SIL_DEBUG
#define ENTER_SMC_ISR						\
	if (sil_debug_on) {					\
		syslog(LOG_EMERG, "Enter selial interrupt.");	\
	}

#else /* SIL_DEBUG */

#define ENTER_SMC_ISR

#endif /* SIL_DEBUG */


/*
 *  SIO��������ߥ����ӥ��롼����
 *  
 *  ������������
 *  
 */
void
smc_isr()
{
    	UB smce1, smcm1, event;
    	SIL_PRE_LOC;

	ENTER_SMC_ISR
	
    	if (!siopcb_table[0].openflag) goto exit_label;
    
    	smce1 = mpc860_reb_mem(SMCE1);
    	smcm1 = mpc860_reb_mem(SMCM1);
    	event = smce1 & smcm1;
    	
    	if (event & (SMCE_BRKE | SMCE_BRK | SMCE_BSY)) {
    		/*  ���顼������̤����  */
    		goto exit_label;
    	}
    	
    	if (event & SMCE_RX) {         /*  ���������  */
	        	/*  1�򥻥åȤ��뤳�Ȥˤ�ꡢ���٥�Ȥ򥯥ꥢ  */
        	mpc860_wrb_mem(SMCE1, SMCE_RX);
        	smc_isr_siop_in(&siopcb_table[0]);
    	}
    	if (event & SMCE_TX) {         /*  ���������  */
	        	/*  1�򥻥åȤ��뤳�Ȥˤ�ꡢ���٥�Ȥ򥯥ꥢ  */
        	mpc860_wrb_mem(SMCE1, SMCE_TX);
        	smc_isr_siop_out(&siopcb_table[0]);
    	}

exit_label:
    	/*
    	 * ��������׵�Υ��ꥢ
    	 *  ��������ߥ���ȥ����¸
    	 *  ������sys_config.h�������
    	 */
    	SIL_LOC_INT();
	CLEAR_IRQ_TO_ICU(SMC1);	
    	SIL_UNL_INT();
}

/*
 * �ݡ���󥰤ˤ��ʸ��������
 */
void
smc_putc_pol(char c)
{
	BOOL is_ten_ok;
	VH smcmr;
	if (smc_openflag()) {	/*  ���������Ƥ��뤫�����å�  */
		smcmr = mpc860_reh_mem(SMCMR1);
		is_ten_ok = smcmr & SMCMR_TEN;
		if (!is_ten_ok) {
						/*  ��������  */
			mpc860_orh_mem(SMCMR1, SMCMR_TEN);
		}
				/*  �Хåե������ˤʤ�Τ��Ԥ�  */
		while(!smc_putready(&siopcb_table[0]));	
		smc_putchar(&siopcb_table[0], c);	/*  1ʸ������  */

		if (!is_ten_ok) {
				/*  �Хåե������ˤʤ�Τ��Ԥ�  */
			while(!smc_putready(&siopcb_table[0]));
				/*  2����饯��ʬ�Ԥ�  */
			sil_dly_nse(SMC_1BIT_TIME*18*10);	
						/*  �����ػ�  */
			mpc860_andh_mem(SMCMR1, ~SMCMR_TEN);
		}
	}
}

/*  end of file  */
