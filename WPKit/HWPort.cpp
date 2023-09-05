/*
 *	========================================================
 *
 *	Wayland
 * 	Copyright PlayXPlicit, all rights reserved.
 *
 * 	========================================================
 */

#include "HWPort.hpp"
#include <CRT0/StringCompare.hpp>

namespace Wayland
{
    HWPort* mfkit_probe_port(const char* name)
    {
        HWPort* port = (HWPort*)kHardwarePortBase;

        while (strcmp(port->fName, name) != 0)
        {
            port = (HWPort*)(port + sizeof(HWPort));
        }

        return port;
    }
}