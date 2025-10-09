#include "../Inc/Init.h"

// bool flag0 = 1;
int flag0 = 1;
// bool flag1 = 1;
int cup = 1;
int delay = 50000;
int T1 = 4;
int T0 = 2;
int main(void)
{
    // OUTPUT
    *(uint32_t *)(0x40023800UL + 0x30UL) |= 0x04UL;    // RCC_PС ENABLE
    *(uint32_t *)(0x40020800UL + 0x00UL) |= 0x10000UL; // PС08_OP
    *(uint32_t *)(0x40020800UL + 0x00UL) |= 0x40000UL; // PС09_OP

    // OUTPUT
    GPIO_G_Init();

    // OUTPUT
    GPIO_D_Init();

    // INPUT
    *(uint32_t *)(0x40023800UL + 0x30UL) |= 0x10UL; // RCC_PE ENABLE

    uint32_t *PORT_C = (uint32_t *)(0x40020800UL + 0x18UL);
    uint32_t *PORT_G = (uint32_t *)(0x40021800UL + 0x18UL);
    uint32_t *PORT_D = (uint32_t *)(0x40020C00UL + 0x18UL);
    uint32_t *reg[] = {PORT_C, PORT_C, PORT_G, PORT_G, PORT_D, PORT_D};
    uint32_t mask[] = {0x100UL, 0x200UL, 0x4UL, 0x8UL, 0x40UL, 0x80UL, 0x1000000UL, 0x2000000UL, 0x40000UL, 0x80000UL, 0x400000UL, 0x800000UL};
    int size = sizeof(reg) / sizeof(reg[0]);
    // while (1)
    // {
    //     if ((*(uint32_t *)(0x40021000UL + 0x10UL) & 0x10UL) != 0)
    //     {
    //         if (++cup > 6)
    //         {
    //             for (int i = 0; i < size; i++)
    //             {
    //                 *(reg[i]) |= mask[i + 6];
    //             }
    //             cup = 1;
    //         }
    //         flag1 = !flag1;
    //     }

    //     if ((*(uint32_t *)(0x40021000UL + 0x10UL) & 0x20UL) != 0)
    //     {
    //         flag0 = !flag0;
    //         flag1 = !flag1;
    //     }

    //     if (flag1)
    //     {
    //         if (flag0)
    //         {
    //             for (int i = 0; i < cup; i++)
    //             {
    //                 *(reg[i]) |= mask[i];
    //             }
    //         }
    //         else
    //         {
    //             for (int i = 0; i < cup; i++)
    //             {
    //                 *(reg[i]) |= mask[i + 6];
    //             }
    //         }
    //         flag1 = !flag1;
    //     }
    //     for (int j = 0U; j < 500000U; j++)
    //     {
    //     }
    // }
    while (1)
    {
        if ((*(uint32_t *)(0x40021000UL + 0x10UL) & 0x10UL) != 0)
        {
            if (++cup > 6)
            {
                for (int i = 0; i < size; i++)
                {
                    *(reg[i]) |= mask[i + 6];
                }
                cup = 1;
            }
        }

        if ((*(uint32_t *)(0x40021000UL + 0x10UL) & 0x20UL) != 0)
        {
            if (++flag0 > 3)
            {
                for (int i = 0; i < size; i++)
                {
                    *(reg[i]) |= mask[i + 6];
                }
                flag0 = 1;
            }
        }

        for (int i = 0; i < cup; i++)
        {
            *(reg[i]) |= mask[i];
        }
        for (int i = 0; i < delay * flag0 * T1; i++)
        {
        }
        for (int i = 0; i < cup; i++)
        {
            *(reg[i]) |= mask[i + 6];
        }
        for (int i = 0; i < delay * flag0 * T0; i++)
        {
        }
    }
}