/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Ryosuke Takeuchi
 *              Platform Development Center RIOCH COMPANY,LTD. JAPAN
 *  Copyright (C) 2006-2010 by Witz Corporation, JAPAN
 * 
 *  The above copyright holders grant permission gratis to use,
 *  duplicate, modify, or redistribute (hereafter called use) this
 *  software (including the one made by modifying this software),
 *  provided that the following four conditions (1) through (4) are
 *  satisfied.
 * 
 *  (1) When this software is used in the form of source code, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be retained in the source code without modification.
 * 
 *  (2) When this software is redistributed in the forms usable for the
 *      development of other software, such as in library form, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be shown without modification in the document provided
 *      with the redistributed software, such as the user manual.
 * 
 *  (3) When this software is redistributed in the forms unusable for the
 *      development of other software, such as the case when the software
 *      is embedded in a piece of equipment, either of the following two
 *      conditions must be satisfied:
 * 
 *    (a) The above copyright notice, this use conditions, and the
 *           disclaimer shown below must be shown without modification in
 *        the document provided with the redistributed software, such as
 *        the user manual.
 * 
 *    (b) How the software is to be redistributed must be reported to the
 *        TOPPERS Project according to the procedure described
 *        separately.
 * 
 *  (4) The above copyright holders and the TOPPERS Project are exempt
 *      from responsibility for any type of damage directly or indirectly
 *      caused from the use of this software and are indemnified by any
 *      users or end users of this software from any and all causes of
 *      action whatsoever.
 * 
 *  THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 *  THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 *  PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 *  TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 *  INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 * 
 *  �嵭����Ԥϡ��ʲ��� (1)��(4) �ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ�������ѡ�
 *  �����ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭�����
 *      ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ�����
 *      ��������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ����Ѽԥ�
 *      �˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ�����̵��
 *      �ڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻���
 *      �Ǥ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ������������ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭������
 *        ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ���
 *        �𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»��
 *      ����⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ��ޤ���
 *      �ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���ͳ�˴��
 *      �����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ���
 *  ��TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū���Ф�
 *  ��Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ�����������
 *  �ˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤������Ǥ����
 *  ��ʤ���
 * 
 *  @(#) $Id: tlcs900offset.cpp,v 1.4 2007/04/17 05:08:07 honda Exp $
 */
// tlcs900offset.cpp : ���󥽡��� ���ץꥱ��������ѤΥ���ȥ� �ݥ���Ȥ����
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	BUF_SIZE		512
#define	STR_SIZE		128
#define BIT_SIZE		6

#define	NORMAL_STATE	0
#define	TEXPTN_STATE	1
#define	SP_STATE		2
#define	PC_STATE		3
#define	ENATEX_STATE	4


static char const default_input_file[] = "makeoffset.asm";
static char const default_output_file[] = "offset.inc";
static char const lf[] = "\n";

static char input_file[STR_SIZE];
static char output_file[STR_SIZE];

/*
���ϥե����뤬BEGIN, END�ζ�֤Ǥ������
offset_state = NORMAL_STATE;
*/
static int  offset_state = NORMAL_STATE;

static bool test_string(char** s, char const * t);
static bool skip_space(char** s);
static bool skip_char(char** s, char const c);

unsigned int atoh(char* s);
void get_num(char* s);
void get_num_undo(char* s);

int main(int argc, char* argv[]){
	FILE* pfo;
	FILE* pfi;
	int nCnt, address;
	int shift_bit = 1;
	int shift_cnt = 0;

	char* s;
	char  str[100];

	char  buf[BUF_SIZE];
	char  c;

	strcpy(input_file, default_input_file);
	strcpy(output_file, default_output_file);

	//���ޥ�ɥ饤�����Ϥ����
	for(nCnt = 1 ; nCnt < argc ; nCnt++){
		s = argv[nCnt];
		if(*s++ == '-'){
			c = *s;
			while(*s != 0){
				if(*s == ':')
					break;
				s++;
			}
			if(*s++ == ':'){
				switch(c){
				//output file name
				case 'O':		
				case 'o':
					strcpy(output_file, s);
					break;
				//input file name
				case 'R':
				case 'r':
					strcpy(input_file, s);
					break;
				default:
					printf("tlcs900offset -R:input_file -O:output_file\n");
					break;
				}
			}
		}
	}
	//input, output�ե�����̾��ɸ�����
	printf("input file   = %s\n", input_file);
	printf("output file  = %s\n", output_file);

	if((pfi = fopen(input_file, "r")) == NULL){
		fprintf(stderr, "can't open input file!");
		exit(1);
	}
	if((pfo = fopen(output_file, "w")) == NULL){
		fclose(pfi);
		fprintf(stderr, "can't open output file!");
		exit(1);
	}

	//input�ե�����μ�����
	for(;;){
		if((fgets(buf, BUF_SIZE, pfi)) == NULL)
			break;
		s = buf;
		switch(offset_state){
		//; BEGIN TCB_texptn���ϰϤβ���
		case TEXPTN_STATE:
			if(test_string(&s, "; END")){
				offset_state = NORMAL_STATE;
				continue;
			}

			if(test_string(&s, "line") || test_string(&s, "call"))
				continue;

			if(skip_char(&s, 'x')){
				continue;
			}

			get_num(s);
			address = atoh(s);
			printf("TCB_texptn\tequ\t%d\n",address);
			fputs("TCB_texptn\t\tequ\t", pfo);
			sprintf(str,"%d",address);
			fputs(str, pfo);
			fputs(lf, pfo);
			break;

		case SP_STATE:
		//; BEGIN TCB_sp���ϰϤβ���
			if(test_string(&s, "; END")){
				offset_state = NORMAL_STATE;
				continue;
			}

			if(test_string(&s, "line") || test_string(&s, "call") )
				continue;

			if(skip_space(&s))
				continue;

			if(skip_char(&s, '(')){
				continue;
			}

			if(skip_char(&s, 'x')){
				continue;
			}

			get_num(s);
			address = atoh(s);
			printf("TCB_sp\t\tequ\t%d\n",address);
			fputs("TCB_sp\t\t\tequ\t", pfo);
			sprintf(str,"%d",address);
			fputs(str, pfo);
			fputs(lf, pfo);

			break;

		case PC_STATE:
		//; BEGIN TCB_pc���ϰϤβ���
			if(test_string(&s, "; END")){
				offset_state = NORMAL_STATE;
				continue;
			}

			if(test_string(&s, "line") || test_string(&s, "call"))
				continue;

			if(skip_char(&s, 'x')){
				continue;
			}
			get_num(s);
			address = atoh(s);
			printf("TCB_pc\tequ\t%d\n",address);
			fputs("TCB_pc\t\t\tequ\t", pfo);
			sprintf(str,"%d",address);
			fputs(str, pfo);
			fputs(lf, pfo);
			break;

		case ENATEX_STATE:
		//; BEGIN TCB_pc���ϰϤβ���
			if(test_string(&s, "; END")){
				offset_state = NORMAL_STATE;
				continue;
			}

			if(test_string(&s, "line") || test_string(&s, "call"))
				continue;

			if(skip_char(&s, 'x')){
				continue;
			}
			get_num(s);
			address = atoh(s);
			printf("TCB_enatex\tequ\t%d\n",address);
			fputs("TCB_enatex\t\tequ\t", pfo);
			sprintf(str,"%d",address);
			fputs(str, pfo);
			fputs(lf, pfo);
			get_num_undo(s);
			if(skip_char(&s, ',')){
				continue;
			}

			*(s + BIT_SIZE) = '\0';
			printf("TCB_enatex_mask\tequ\t%s\n",s);
			fputs("TCB_enatex_mask\tequ\t", pfo);
			fputs(s, pfo);
			fputs(lf, pfo);

			if(skip_char(&s, 'x')){
				continue;
			}

			address = atoh(s);

			for(shift_cnt=0;shift_cnt<=16;shift_cnt++){
				if(address == shift_bit){
					printf("TCB_enatex_bit\tequ\t%d\n",shift_cnt);
					fputs("TCB_enatex_bit\tequ\t", pfo);
					sprintf(str,"%d",shift_cnt);
					fputs(str, pfo);
					fputs(lf, pfo);
				}
				shift_bit<<=1;
			}

			break;

		default:
			if(test_string(&s, "; BEGIN TCB_texptn")){
				offset_state = TEXPTN_STATE;
				continue;
			}else if(test_string(&s, "; BEGIN TCB_sp")){
				offset_state = SP_STATE;
				continue;
			}else if(test_string(&s, "; BEGIN TCB_pc")){
				offset_state = PC_STATE;
				continue;
			}else if(test_string(&s, "; BEGIN TCB_enatex")){
				offset_state = ENATEX_STATE;
				continue;
			}

			break;
		}
	}
	return 0;
}

/*
 * 16��ʸ�����int�����Ѵ�
 */
unsigned int atoh(char* s)
{
	int nCnt = 0;
	for(;;){
		if(*s >= '0' && *s <= '9')
			nCnt = (nCnt * 16) + (*s - '0');
		else if(*s >= 'A' && *s <= 'F')
			nCnt = (nCnt * 16) + (*s - 'A' + 10);
		else if(*s >= 'a' && *s <= 'f')
			nCnt = (nCnt * 16) + (*s - 'a' + 10);
		else
			break;
		s++;
	}
	return nCnt;
}
/*
 * ���ɥ쥹��ʬ�����
 */
void get_num(char* s)
{
	int nCnt;

	for(nCnt = 0 ; nCnt < 4 ; nCnt++){
		if(*(s+nCnt) == ')'){
			*(s+nCnt) = '\0';
		}
	}
}

/*
 * get_num�ǽ񤭴�������ʬ�򸵤��᤹
 */
void get_num_undo(char* s)
{
	int nCnt;

	for(nCnt = 0 ; nCnt < 4 ; nCnt++){
		if(*(s+nCnt) == '\0'){
			*(s+nCnt) = ')';
		}
	}
}


/*
 * ʸ�������Ӥ���Ʊ��ʤ��TURE
 */
static bool test_string(char** s, char const *t)
{
	char*  p;
	char   c;

	p = *s;
	while(*p <= ' '){
		if(*p == 0)
			return false;
		p++;
	}
	while((c = *p++) != 0){
		if(c != *t++)
			break;
		if(*t == 0){
			*s = p;
			return true;
		}
	}
	return false;
}

/*
 * ����Υ���饯���ޤǥ����å�
 */
static bool skip_char(char** s, char const c)
{
	char* p;

	p = *s;
	while(*p != c){
		if(*p == 0)
			break;
		p++;
	}
	if(*p){
		p++;
		*s = p;
		return false;
	}
	else{
		*s = p;
		return true;
	}
}

/*
 * ���ڡ����ޤ��ϥ��֤򥹥��åפ���
 */
static bool skip_space(char** s)
{
	char* p;

	p = *s;
	while(*p <= ' '){
		if(*p == 0)
			break;
		p++;
	}
	*s = p;
	if(*p)
		return false;
	else
		return true;
}
