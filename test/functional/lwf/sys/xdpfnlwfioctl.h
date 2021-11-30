//
// Copyright (C) Microsoft Corporation. All rights reserved.
//

#pragma once

#include <xdpfnlwfapi.h>

#define XDPFNLWF_DEVICE_NAME L"\\Device\\xdpfnlwf"

#define XDPFNLWF_OPEN_PACKET_NAME "XdpFnOpenPacket0"

//
// Type of XDP functional test LWF object to create or open.
//
typedef enum _XDPFNLWF_FILE_TYPE {
    XDPFNLWF_FILE_TYPE_DEFAULT,
} XDPFNLWF_FILE_TYPE;

//
// Open packet, the common header for NtCreateFile extended attributes.
//
typedef struct _XDPFNLWF_OPEN_PACKET {
    XDPFNLWF_FILE_TYPE ObjectType;
} XDPFNLWF_OPEN_PACKET;

typedef struct _XDPFNLWF_OPEN_DEFAULT {
    UINT32 IfIndex;
} XDPFNLWF_OPEN_DEFAULT;

#define IOCTL_RX_FILTER \
    CTL_CODE(FILE_DEVICE_NETWORK, 1, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_RX_GET_FRAME \
    CTL_CODE(FILE_DEVICE_NETWORK, 2, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_RX_DEQUEUE_FRAME \
    CTL_CODE(FILE_DEVICE_NETWORK, 3, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_RX_FLUSH \
    CTL_CODE(FILE_DEVICE_NETWORK, 4, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_TX_ENQUEUE \
    CTL_CODE(FILE_DEVICE_NETWORK, 5, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_TX_FLUSH \
    CTL_CODE(FILE_DEVICE_NETWORK, 6, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_OID_SUBMIT_REQUEST \
    CTL_CODE(FILE_DEVICE_NETWORK, 7, METHOD_BUFFERED, FILE_WRITE_ACCESS)

//
// Parameters for IOCTL_OID_SUBMIT_REQUEST.
//

typedef struct _OID_SUBMIT_REQUEST_IN {
    OID_KEY Key;
    VOID *InformationBuffer;
    UINT32 InformationBufferLength;
} OID_SUBMIT_REQUEST_IN;
