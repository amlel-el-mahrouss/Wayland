/*
 *	========================================================
 *
 *	Wayland
 * 	Copyright PlayXPlicit, all rights reserved.
 *
 * 	========================================================
 */

#pragma once

#define kHardwareSataPort ":sata"
#define kHardwareAhciPort ":ahci"
#define kHardwareCdPort ":cdrom"

#define mfkit_probe_ahci() Wayland::mfkit_probe_port(kHardwareAhciPort)
#define mfkit_probe_cd() Wayland::mfkit_probe_port(kHardwareCdPort)
#define mfkit_probe_sata() Wayland::mfkit_probe_port(kHardwareSataPort)

#define kHardwarePortBase 0x100000

namespace Wayland
{
    enum
    {
        kKindGraphicsProcessor = 0xC1,
        kKindCoProcessor = 0xC2,
        kKindNetworkController = 0xC3,
        kKindMassStorageController = 0xC4,
    };

    struct HWPortDescriptor final
    {
        char fName[16];
        int fType;

        void(*fProcedure)();

        struct HWPortDescriptor* fNext;
    };

    struct HWPort final
    {
        char fName[16];
        int fKind;

        HWPortDescriptor* fLinkedList;
        long long int fLinkedListCount;
    };

    HWPort* mfkit_probe_port(const char* name); 
}
    