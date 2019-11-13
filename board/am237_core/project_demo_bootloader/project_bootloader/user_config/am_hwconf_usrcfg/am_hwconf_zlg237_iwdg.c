/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ZLG237 IWDG �û������ļ�
 * \sa am_hwconf_zlg237_iwdg.c
 *
 * \internal
 * \par Modification history
 * - 1.00 17-08-24  zcb, first implementation
 * \endinternal
 */

#include "am_zlg237.h"
#include "am_zlg_iwdg.h"
#include "amhw_zlg237_rcc.h"

/**
 * \addtogroup am_if_src_hwconf_zlg237_iwdg
 * \copydoc am_hwconf_zlg237_iwdg.c
 * @{
 */

/** \brief IDWG ƽ̨��ʼ�� */
static void __zlg237_iwdg_plfm_init (void)
{

    /* ��鸴λ�Ƿ��ɿ��Ź���ɵ� */
    if (amhw_zlg237_rcc_reset_flag() & AMHW_ZLG237_RCC_CSR_IWDGRSTF) {
        amhw_zlg237_rcc_reset_flag_clear();
    }

    amhw_zlg237_rcc_lsi_enable();

    while (amhw_zlg237_rcc_lsirdy_read() == AM_FALSE);
}

/** \brief ��� IWDG ƽ̨��ʼ�� */
static void __zlg237_iwdg_plfm_deinit (void)
{
}

/** \brief IWDG �豸��Ϣ */
static const am_zlg_iwdg_devinfo_t __g_iwdg_devinfo = {
    ZLG237_IWDG_BASE,          /**< \brief IWDG �Ĵ�����ַ */
    __zlg237_iwdg_plfm_init,    /**< \brief IWDG ƽ̨��ʼ�� */
    __zlg237_iwdg_plfm_deinit,  /**< \brief ���IWDG ƽ̨��ʼ�� */
};

/** \brief IWDG�豸ʵ�� */
static am_zlg_iwdg_dev_t __g_iwdg_dev;

/**
 * \brief IWDG ʵ����ʼ�������IWDG��׼������
 */
am_wdt_handle_t am_zlg237_iwdg_inst_init (void)
{
    return am_zlg_iwdg_init(&__g_iwdg_dev, &__g_iwdg_devinfo);
}

/**
 * \brief IWDG ʵ�����ʼ��
 */
void am_zlg237_iwdg_inst_deinit (am_wdt_handle_t handle)
{
    am_zlg_iwdg_deinit(handle);
}

/**
 * @}
 */

/* end of file */