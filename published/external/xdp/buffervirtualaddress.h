//
// Copyright (C) Microsoft Corporation. All rights reserved.
//

#pragma once

EXTERN_C_START

#pragma warning(push)
#pragma warning(default:4820) // warn if the compiler inserted padding

//
// XDP buffer extension containing the virtual address of the buffer data.
//
typedef struct XDP_BUFFER_VIRTUAL_ADDRESS {
    //
    // Contains the virtual address of a buffer.
    //
    UCHAR *VirtualAddress;
} XDP_BUFFER_VIRTUAL_ADDRESS;

C_ASSERT(sizeof(XDP_BUFFER_VIRTUAL_ADDRESS) == sizeof(VOID *));

#pragma warning(pop)

#define XDP_BUFFER_EXTENSION_VIRTUAL_ADDRESS_NAME L"ms_buffer_virtual_address"
#define XDP_BUFFER_EXTENSION_VIRTUAL_ADDRESS_VERSION_1 1U

#include <xdp/datapath.h>
#include <xdp/extension.h>

//
// Returns the virtual address extension for the given XDP buffer.
//
inline
XDP_BUFFER_VIRTUAL_ADDRESS *
XdpGetVirtualAddressExtension(
    _In_ XDP_BUFFER *Buffer,
    _In_ XDP_EXTENSION *Extension
    )
{
    return (XDP_BUFFER_VIRTUAL_ADDRESS *)XdpGetExtensionData(Buffer, Extension);
}

EXTERN_C_END
