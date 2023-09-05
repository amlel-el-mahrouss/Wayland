/*
 *	========================================================
 *
 *	Wayland
 * 	Copyright PlayXPlicit, all rights reserved.
 *
 * 	========================================================
 */

long long int __stack_chk_guard = 0UL;

extern "C" void __stack_chk_fail(void)
{
    while (1)
        ;
}