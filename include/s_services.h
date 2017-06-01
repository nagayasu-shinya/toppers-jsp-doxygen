#ifndef _S_SERVICES_H_
#define _S_SERVICES_H_

/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 *
 *  @(#) $Id: s_services.h,v 1.4 2003/06/18 12:46:54 hiro Exp $
 */

/**
 * @file
 * @brief デバイスドライバ用 標準インクルードファイル
 *
 * このインクルードファイルは，
 * 直接ハードウェアにアクセスするデバイスドライバのソースファイルで
 * インクルードするべき標準インクルードファイルである．
 * この中で，
 * sil.h（さらにここから，t_stddef.h，itron.h，tool_defs.h，sys_defs.h，cpu_defs.h，t_syslog.h）と
 * t_config.h（さらにここから，sys_config.h，cpu_config.h，tool_config.h）をインクルードしている．
 * @n
 * また，アプリケーションから呼ばれるデバイスドライバのインクルードファイルで，
 * インライン関数などでシステムインタフェースレイヤを用いている場合にも，
 * このファイルをインクルードする．
 * @n
 * アセンブリ言語のソースファイルやシステムコンフィギュレーションファ
 * イルからこのファイルをインクルードする時は，_MACRO_ONLY を定義して
 * おくことで，マクロ定義以外の記述を除くことができる．
 *
 * @copyright 2000-2003 by Embedded and Real-Time Systems Laboratory Toyohashi Univ. of Technology, JAPAN
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  SILを呼び出すために必要なインクルードファイル
 */
#include <sil.h>

/*
 *  ターゲット依存情報の定義
 */
#include <t_config.h>

#ifdef __cplusplus
}
#endif

#endif /* _S_SERVICES_H_ */
