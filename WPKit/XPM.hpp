/*
 *	========================================================
 *
 *	Wayland
 * 	Copyright PlayXPlicit, all rights reserved.
 *
 * 	========================================================
 */

#pragma once

#define kSystemPartBSD "bsd_sys"
#define kBootPartBSD "boot"

#define kSystemPartMe "SystemBlock"
#define kBootPartMe "BootBlock"

namespace Wayland
{
    struct BootBlock final
    {
        char fName[32];
        char fUUID[128];
        int fVer;
        long long int fNumBlocks;
        long long int fSectorSize;
        long long int fSectorStart;;
    };

    struct PartBlock final
    {
        char fName[32];
        int fMag;
        long long int fSectorEnd;
        long long int fSectorSize;
        long long int fSectorStart;
        short fPartType;
        int fVer;
        char fFS[16];
    };
}