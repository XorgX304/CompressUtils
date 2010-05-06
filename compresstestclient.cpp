#include <stdio.h>
#include "stringutils.h"
#include "win32compress_client.h"
#include "util/HiresTimer.h"
struct compresstest {
    uint32_t dectype;
    uint32_t clen;
    uint8_t cdata[0x2000];
    uint32_t ulen;
    uint8_t udata[0x2000];
};
compresstest tests[]= {
  { ITSCOMP_ROM3_DECODE, 
  67, {0x50,0x00,0x00,0x43,0x00,0x00,0xa0,0xde,0xaa,0x00,0x00,0x02,0x11,0x01,0x03,0x00,0x00,0x01,0x00,0x73,0x79,0x6e,0x63,0x2e,0x61,0x00,0x76,0x61,0x6e,0x74,0x67,0x6f,0x2e,0x63,0x40,0x6f,0x6d,0x00,0x50,0x00,0x00,0x01,0x00,0x7a,0x41,0x43,0x01,0x47,0x95,0x01,0x56,0x02,0x04,0x02,0x01,0x02,0x78,0x1e,0x1e,0xf0,0xa3,0x00,0xb3,0x03,0x01,0x01,0x00},
  80, {0xde,0xaa,0x00,0x00,0x02,0x00,0x00,0x01,0xde,0xaa,0x00,0x00,0x01,0x00,0x73,0x79,0x6e,0x63,0x2e,0x61,0x76,0x61,0x6e,0x74,0x67,0x6f,0x2e,0x63,0x6f,0x6d,0x00,0x50,0x00,0x00,0x00,0x00,0x00,0x41,0x76,0x61,0x6e,0x74,0x47,0x6f,0x2e,0x63,0x6f,0x6d,0x00,0x41,0x76,0x61,0x6e,0x74,0x47,0x6f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x1e,0x1e,0xf0,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  },
  { ITSCOMP_ROM3_DECODE, 
  62, {0x48,0x00,0x00,0x3e,0x00,0x00,0x00,0x30,0x10,0xc3,0x00,0x01,0x14,0x00,0x40,0xd2,0x80,0x12,0x00,0x02,0x1c,0x61,0xf0,0x92,0x00,0xf1,0xa9,0x61,0x18,0x11,0x22,0x00,0x28,0x61,0xb8,0x93,0x01,0x4a,0x0c,0x61,0xe8,0x16,0x02,0x18,0x12,0xa2,0x02,0x35,0xa5,0x61,0xec,0x12,0x03,0x00,0x04,0x61,0xfc,0x93,0x03,0x02,0x02,0x61},
  72, {0x30,0x10,0xC3,0x00,0x01,0x14,0x00,0x40,0x80,0x10,0xC3,0x00,0x02,0x1C,0x00,0x40,0xF0,0x10,0xC3,0x00,0x00,0x01,0x00,0x40,0x18,0x11,0xC3,0x00,0x01,0x28,0x00,0x40,0xB8,0x11,0xC3,0x00,0x01,0x0C,0x00,0x40,0xE8,0x11,0xC3,0x00,0x01,0x0C,0x00,0x40,0x18,0x12,0xC3,0x00,0x01,0x35,0x00,0x40,0xEC,0x12,0xC3,0x00,0x00,0x04,0x00,0x40,0xFC,0x12,0xC3,0x00,0x00,0x02,0x00,0x40},
  },
  { ITSCOMP_ROM4_DECODE, 
 186, {0xf1,0x00,0x00,0xba,0x00,0x00,0x10,0x00,0x00,0x00,0xf1,0x00,0x00,0x00,0xa4,0x00,0x00,0x00,0xf1,0x00,0x00,0x00,0x5b,0x80,0x80,0x8d,0x00,0x10,0x12,0x0f,0x00,0x00,0x00,0x00,0x23,0x03,0x00,0x40,0x0f,0x43,0x40,0x42,0x44,0x7f,0xa2,0xbe,0x18,0xb4,0x05,0xaa,0x2c,0x93,0x39,0x84,0x51,0xe5,0xda,0xe6,0xb2,0x75,0x6f,0x12,0xe5,0xef,0x00,0x84,0x00,0x00,0x04,0x00,0x00,0x88,0x46,0x00,0x20,0x08,0x10,0x2e,0x1d,0xe1,0xc0,0x58,0x10,0x73,0x7d,0xc2,0x54,0x47,0xfb,0x3b,0xa1,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x01,0x03,0x19,0xcf,0xcc,0xd7,0x21,0xdf,0xef,0x10,0xbf,0x9f,0x53,0xee,0x82,0x90,0x13,0xb7,0x18,0x09,0x9b,0x96,0xbc,0x25,0x25,0x0e,0x8c,0x6d,0x11,0xa0,0xd8,0x77,0x6e,0x79,0xd2,0x66,0x0c,0xde,0x2e,0xd2,0x89,0xc9,0x9d,0xda,0x44,0xbf,0x14,0x31,0x6e,0xea,0xdf,0xee,0xde,0xb0,0xec,0xe0,0xe2,0x6c,0xbc,0x43,0xe6,0xcf,0x2f,0x5c,0x2f,0x10,0x89,0x7a,0x26,0xcd,0xbc,0x27,0x08,0xbd,0x4e,0x7d,0x42,0xe1,0x3d,0x8a,0x9e,0x2a,0xfc,0xf2,0x6f,0x00,0xe0},
 241, {0x3c,0x73,0x74,0x69,0x6e,0x67,0x65,0x72,0x2d,0x63,0x6f,0x6e,0x74,0x72,0x6f,0x6c,0x70,0x61,0x6e,0x65,0x6c,0x2d,0x64,0x6f,0x63,0x3e,0x0d,0x0a,0x09,0x3c,0x63,0x70,0x6c,0x2d,0x74,0x69,0x74,0x6c,0x65,0x20,0x72,0x65,0x73,0x3d,0x22,0x33,0x30,0x30,0x34,0x30,0x22,0x2f,0x3e,0x0d,0x0a,0x09,0x3c,0x63,0x70,0x6c,0x2d,0x6c,0x69,0x6e,0x6b,0x20,0x68,0x72,0x65,0x66,0x3d,0x22,0x73,0x79,0x6e,0x63,0x5f,0x73,0x63,0x68,0x65,0x64,0x75,0x6c,0x65,0x2e,0x63,0x70,0x6c,0x2e,0x78,0x6d,0x6c,0x22,0x20,0x72,0x65,0x73,0x3d,0x22,0x33,0x30,0x30,0x33,0x37,0x22,0x2f,0x3e,0x0d,0x0a,0x09,0x3c,0x63,0x70,0x6c,0x2d,0x6c,0x69,0x6e,0x6b,0x20,0x68,0x72,0x65,0x66,0x3d,0x22,0x73,0x79,0x6e,0x63,0x5f,0x70,0x63,0x2e,0x63,0x70,0x6c,0x2e,0x78,0x6d,0x6c,0x22,0x20,0x72,0x65,0x73,0x3d,0x22,0x33,0x30,0x30,0x33,0x36,0x22,0x2f,0x3e,0x0d,0x0a,0x09,0x3c,0x63,0x70,0x6c,0x2d,0x6c,0x69,0x6e,0x6b,0x20,0x68,0x72,0x65,0x66,0x3d,0x22,0x73,0x79,0x6e,0x63,0x5f,0x73,0x65,0x72,0x76,0x65,0x72,0x2e,0x63,0x70,0x6c,0x2e,0x78,0x6d,0x6c,0x22,0x20,0x72,0x65,0x73,0x3d,0x22,0x33,0x30,0x30,0x35,0x38,0x22,0x2f,0x3e,0x0d,0x0a,0x3c,0x2f,0x73,0x74,0x69,0x6e,0x67,0x65,0x72,0x2d,0x63,0x6f,0x6e,0x74,0x72,0x6f,0x6c,0x70,0x61,0x6e,0x65,0x6c,0x2d,0x64,0x6f,0x63,0x3e,0x0d,0x0a},
  },
  { ITSCOMP_XPR_DECODE, 
  84, {0x00,0x86,0xa2,0x0a,0x42,0x4d,0x86,0x00,0x03,0x00,0x46,0x18,0x00,0x28,0x18,0x00,0x10,0x1c,0x00,0x01,0x00,0x02,0xc3,0x00,0x03,0xb8,0x00,0x0f,0x00,0x00,0xae,0xa1,0x00,0x07,0x00,0x61,0x80,0x80,0x80,0x00,0xc0,0xc0,0xc0,0x00,0xff,0xff,0x01,0x00,0x08,0xff,0xff,0x00,0xaa,0x07,0x00,0x2a,0xa8,0xaa,0xaa,0x0a,0xa0,0xaa,0xaa,0x82,0x82,0xaa,0xaa,0xa0,0x0a,0xaa,0xaa,0xa8,0x2a,0x3b,0x00,0x79,0x00,0xb9,0x00,0xf9,0x00,0x07,0x00,0x01},
 134, {0x42,0x4d,0x86,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x46,0x00,0x00,0x00,0x28,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x28,0x0f,0x00,0x00,0xae,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x00,0xc0,0xc0,0xc0,0x00,0xff,0xff,0xff,0x00,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x2a,0xa8,0xaa,0xaa,0x0a,0xa0,0xaa,0xaa,0x82,0x82,0xaa,0xaa,0xa0,0x0a,0xaa,0xaa,0xa8,0x2a,0xaa,0xaa,0xa0,0x0a,0xaa,0xaa,0x82,0x82,0xaa,0xaa,0x0a,0xa0,0xaa,0xaa,0x2a,0xa8,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa},
  },
  { ITSCOMP_LZX_DECODE, 
 176, {0xa8,0x00,0x00,0x00,0xe5,0x00,0x00,0x00,0x5b,0x80,0x80,0x8d,0x00,0x10,0x51,0x0e,0x00,0x00,0x00,0x00,0x33,0x03,0x00,0x50,0x0e,0x45,0x27,0x54,0xdc,0x6b,0x2e,0xc8,0x02,0xa1,0x67,0x4a,0x65,0x9b,0xa4,0x37,0xed,0xab,0xaa,0xca,0x70,0xb7,0x08,0xaa,0xff,0xa9,0xff,0xff,0x40,0x70,0x00,0x00,0x00,0x00,0x00,0xcd,0x0d,0x00,0x30,0x01,0x71,0x21,0x81,0x27,0x26,0x32,0x98,0x85,0xcc,0x96,0x4e,0x49,0x15,0xaa,0xff,0x3f,0xfe,0xff,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x10,0x42,0x00,0xff,0x42,0xff,0xff,0x22,0xfd,0x41,0x29,0x59,0x36,0x63,0xb7,0x48,0xa7,0x5a,0xa8,0x30,0x93,0xef,0x5a,0x2f,0x38,0x6c,0x5f,0xc7,0x30,0xe6,0xb2,0xc2,0xb7,0x84,0xcc,0x5b,0x47,0x37,0xb1,0x1c,0x19,0xfa,0x20,0xfc,0xbc,0xec,0x0a,0x96,0xfe,0x28,0xc0,0xef,0xa3,0x5a,0xf8,0x3b,0x80,0x07,0x6b,0xa6,0x75,0xff,0xa7,0x3e,0xa7,0x95,0x4b,0x7f,0x81,0x64,0xa2,0x04,0xe6,0x78,0x7c,0xb9,0x45,0xef,0x11,0x08,0x93,0xd0,0x6e,0x00,0x40},
 229, {0x4d,0x4d,0x49,0x20,0x41,0x6c,0x6c,0x0d,0x0a,0x54,0x52,0x41,0x43,0x45,0x43,0x4c,0x41,0x53,0x53,0x20,0x46,0x46,0x0d,0x0a,0x4d,0x4d,0x49,0x0d,0x0a,0x0d,0x0a,0x4d,0x4d,0x20,0x41,0x6c,0x6c,0x0d,0x0a,0x54,0x52,0x41,0x43,0x45,0x43,0x4c,0x41,0x53,0x53,0x20,0x46,0x46,0x0d,0x0a,0x4d,0x4d,0x0d,0x0a,0x0d,0x0a,0x47,0x4d,0x4d,0x20,0x41,0x4c,0x4c,0x0d,0x0a,0x54,0x52,0x41,0x43,0x45,0x43,0x4c,0x41,0x53,0x53,0x20,0x46,0x46,0x0d,0x0a,0x47,0x4d,0x4d,0x0d,0x0a,0x0d,0x0a,0x43,0x43,0x20,0x41,0x6c,0x6c,0x0d,0x0a,0x54,0x52,0x41,0x43,0x45,0x43,0x4c,0x41,0x53,0x53,0x20,0x46,0x46,0x0d,0x0a,0x43,0x43,0x0d,0x0a,0x0d,0x0a,0x53,0x4d,0x53,0x20,0x41,0x6c,0x6c,0x0d,0x0a,0x54,0x52,0x41,0x43,0x45,0x43,0x4c,0x41,0x53,0x53,0x20,0x46,0x46,0x0d,0x0a,0x53,0x4d,0x53,0x0d,0x0a,0x0d,0x0a,0x53,0x53,0x20,0x45,0x76,0x65,0x6e,0x74,0x0d,0x0a,0x54,0x52,0x41,0x43,0x45,0x43,0x4c,0x41,0x53,0x53,0x20,0x30,0x32,0x0d,0x0a,0x53,0x53,0x0d,0x0a,0x0d,0x0a,0x4c,0x31,0x20,0x53,0x74,0x64,0x20,0x54,0x72,0x61,0x63,0x65,0x0d,0x0a,0x43,0x4f,0x4e,0x46,0x49,0x47,0x20,0x4c,0x31,0x5f,0x50,0x41,0x52,0x41,0x4d,0x53,0x3d,0x3c,0x30,0x2c,0x31,0x32,0x37,0x3e,0x0d,0x0a,0x43,0x53,0x54,0x0d,0x0a,0x0d,0x0a},
  },
  { ITSCOMP_LZX_DECODE, 
 352, {0x58,0x01,0x00,0x00,0x80,0x02,0x00,0x00,0x5b,0x80,0x80,0x8d,0x00,0x20,0x00,0x28,0x08,0x10,0x00,0x81,0x00,0x00,0x23,0x00,0x00,0x50,0x40,0x00,0x6f,0x5f,0xde,0x7b,0x13,0xb4,0xca,0xea,0xa2,0x61,0x15,0x5a,0xb8,0x44,0x48,0x50,0x08,0x85,0xd5,0xa8,0x12,0x45,0xc0,0x8d,0x17,0xb9,0x27,0x0a,0x11,0xb8,0x28,0x70,0x25,0x8d,0x6a,0x4b,0x52,0xb5,0x17,0x84,0x21,0x12,0xe5,0x55,0xa2,0x6a,0x81,0x8b,0xa1,0x2b,0x91,0x4b,0x40,0x24,0x00,0x00,0x06,0x00,0xa8,0x68,0x04,0xa0,0xef,0x81,0x4d,0xa2,0x92,0x00,0x04,0x6a,0x24,0x23,0x8a,0xc4,0x52,0x91,0x91,0x3c,0x18,0x89,0x88,0x91,0xa4,0x92,0x19,0x5e,0xfd,0x3b,0x10,0xfe,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0x66,0xcf,0xf6,0x67,0x93,0x66,0xdf,0x7c,0xea,0x30,0xa3,0xfd,0xd4,0x3f,0x5e,0xe8,0x45,0x36,0x69,0x08,0x43,0x55,0xa2,0x65,0x14,0xe3,0xc2,0xad,0x88,0x7a,0x05,0xc7,0xe8,0x15,0x59,0x8f,0x0e,0x41,0x89,0x97,0x5a,0xf7,0x81,0xb7,0x0d,0x83,0x94,0x29,0xb9,0xb0,0xf0,0x42,0x54,0x14,0x2c,0x4b,0xb1,0x62,0x0c,0xa1,0x08,0x6e,0x87,0x64,0x72,0xe6,0xf2,0x06,0xb4,0xc5,0xda,0xa1,0x1c,0xf4,0x96,0x60,0xbb,0x0d,0xe4,0xa8,0xa1,0x88,0x24,0x38,0x0e,0xc8,0xc6,0x19,0xd7,0x6b,0xef,0x84,0x03,0x04,0xe5,0xa7,0xbc,0x91,0x55,0x30,0xe5,0x03,0x8a,0x1a,0x7e,0xca,0x4d,0xc2,0x7c,0x88,0x50,0x76,0xfe,0x60,0x77,0x02,0x17,0x95,0xa6,0x6f,0x0a,0x75,0x49,0x5f,0x39,0x7a,0x39,0xa9,0xcc,0x0b,0x4a,0xc9,0x68,0x0b,0xb3,0x34,0xac,0x0e,0x25,0x48,0xc1,0xda,0xed,0x9e,0x19,0x71,0x46,0x95,0xe6,0x50,0x5a,0x3a,0x1e,0x45,0x17,0xca,0x74,0x56,0xd4,0xab,0x1e,0xc4,0xa5,0xbd,0xcb,0x74,0x84,0x56,0xce,0x09,0x63,0x7f,0xe5,0xf1,0x2e,0x51,0xff,0xd9,0x30,0xb0,0x70,0x4a,0xf3,0x68,0xda,0x3d,0xb7,0xa5,0x29,0x52,0xa6,0xe3,0x42,0x54,0x44,0x51,0x95,0x3e,0x47,0xa6,0x42,0x58,0x77,0x53,0xb6,0x26,0xf3,0xbe,0x27,0xf8,0x30,0xbb,0xdc,0xfe,0xdf,0x97,0xbf,0xd0,0xb0,0xfa,0xba,0xba,0x8b,0xdc,0xa7},
 640, {0xd0,0x01,0x00,0x80,0x24,0x00,0x00,0x80,0x54,0x07,0x00,0x80,0x55,0x07,0x00,0x80,0xc8,0x01,0x00,0x80,0x7e,0x05,0x00,0x80,0x10,0x02,0x00,0x80,0x11,0x02,0x00,0x80,0xc4,0x00,0x00,0x80,0xc5,0x00,0x00,0x80,0x3f,0x00,0x00,0x80,0x2c,0x04,0x00,0x80,0x7b,0x03,0x00,0x80,0x1e,0x01,0x00,0x80,0x01,0x01,0x00,0x80,0x00,0x01,0x00,0x80,0x2a,0x04,0x00,0x80,0xe0,0x00,0x00,0x80,0xdd,0x00,0x00,0x80,0xab,0x02,0x00,0x80,0xa1,0x02,0x00,0x80,0x4e,0x03,0x00,0x80,0x08,0x01,0x00,0x80,0x03,0x01,0x00,0x80,0x02,0x01,0x00,0x80,0x1d,0x01,0x00,0x80,0x5b,0x03,0x00,0x80,0x6a,0x03,0x00,0x80,0x60,0x03,0x00,0x80,0x61,0x03,0x00,0x80,0x64,0x03,0x00,0x80,0x05,0x02,0x00,0x80,0xcd,0x02,0x00,0x80,0x80,0x03,0x00,0x80,0x8f,0x04,0x00,0x80,0x14,0x04,0x00,0x80,0xa4,0x00,0x00,0x80,0xa0,0x00,0x00,0x80,0x24,0x02,0x00,0x80,0xb5,0x00,0x00,0x80,0xa7,0x00,0x00,0x80,0xa1,0x00,0x00,0x80,0xa9,0x00,0x00,0x80,0xa2,0x00,0x00,0x80,0xa5,0x00,0x00,0x80,0x14,0x02,0x00,0x80,0xc6,0x00,0x00,0x80,0xa8,0x00,0x00,0x80,0xa6,0x00,0x00,0x80,0x99,0x04,0x00,0x80,0x2f,0x04,0x00,0x80,0x1d,0x02,0x00,0x80,0x19,0x02,0x00,0x80,0xef,0x01,0x00,0x80,0x38,0x00,0x00,0x80,0x89,0x05,0x00,0x80,0x0d,0x03,0x00,0x80,0x07,0x03,0x00,0x80,0xc8,0x00,0x00,0x80,0xca,0x00,0x00,0x80,0xcb,0x00,0x00,0x80,0xcc,0x00,0x00,0x80,0x53,0x07,0x00,0x80,0xcd,0x01,0x00,0x80,0x5a,0x03,0x00,0x80,0xc0,0x02,0x00,0x80,0xc0,0x00,0x00,0x80,0x0f,0x01,0x00,0x80,0xfb,0x00,0x00,0x80,0x17,0x02,0x00,0x80,0x56,0x03,0x00,0x80,0xfd,0x00,0x00,0x80,0x13,0x00,0x00,0x80,0x19,0x00,0x00,0x80,0x96,0x03,0x00,0x80,0x90,0x03,0x00,0x80,0xd3,0x03,0x00,0x80,0xc8,0x03,0x00,0x80,0xcc,0x03,0x00,0x80,0xd4,0x03,0x00,0x80,0x12,0x02,0x00,0x80,0xd7,0x03,0x00,0x80,0x80,0x06,0x00,0x80,0x97,0x03,0x00,0x80,0x93,0x03,0x00,0x80,0x25,0x02,0x00,0x80,0x14,0x00,0x00,0x80,0xce,0x04,0x00,0x80,0x2b,0x02,0x00,0x80,0x42,0x00,0x00,0x80,0x29,0x02,0x00,0x80,0xa3,0x06,0x00,0x80,0x4b,0x00,0x00,0x80,0xdf,0x05,0x00,0x80,0xcf,0x01,0x00,0x80,0x3d,0x00,0x00,0x80,0x5e,0x03,0x00,0x80,0x57,0x00,0x00,0x80,0xee,0x01,0x00,0x80,0x02,0x00,0x00,0x80,0x05,0x00,0x00,0x80,0x04,0x00,0x00,0x80,0x03,0x00,0x00,0x80,0xf1,0x01,0x00,0x80,0x46,0x04,0x00,0x80,0x47,0x04,0x00,0x80,0x9d,0x02,0x00,0x80,0x9f,0x02,0x00,0x80,0xa5,0x02,0x00,0x80,0x04,0x02,0x00,0x80,0x9c,0x02,0x00,0x80,0x21,0x00,0x00,0x80,0x23,0x00,0x00,0x80,0xa0,0x02,0x00,0x80,0xc7,0x01,0x00,0x80,0x16,0x04,0x00,0x80,0x31,0x04,0x00,0x80,0x00,0x00,0x00,0x00,0x86,0x53,0x00,0x00,0x74,0x53,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xac,0x50,0xbd,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0x9b,0x4f,0xff,0xff,0x64,0xb0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  },

};

int main(int,char**)
{
    try {
    win32compress_client svr;

    for (unsigned i=0 ; i<sizeof(tests)/sizeof(compresstest) ; i++)
    {
        fprintf(stderr, "test %d\n", i);
        compresstest& t= tests[i];
        uint8_t out[0x2000]; memset(out, 0, 0x2000);
        DWORD ures= svr.DoCompressConvert(t.dectype, out, 0x2000, t.cdata, t.clen);
        if (ures!=t.ulen) {
            fprintf(stderr,"ulen mismatch: %d iso %d\n", ures, t.ulen);
            fprintf(stderr,"svr:%s\nreal:%s\n", hexdump(out, t.ulen).c_str(), hexdump(t.udata, t.ulen).c_str());
        }
        else if (memcmp(out, t.udata, ures)) {
            fprintf(stderr,"cdata mismatch\n");
            fprintf(stderr,"svr:%s\nreal:%s\n", hexdump(out, t.ulen).c_str(), hexdump(t.udata, t.ulen).c_str());
        }

        memset(out, 0, 0x2000);
        DWORD cres= svr.DoCompressConvert(t.dectype+1, out, 0x2000, t.udata, t.ulen);
        if (cres!=t.clen) {
            fprintf(stderr,"clen mismatch: %d iso %d\n", cres, t.clen);
            fprintf(stderr,"svr:%s\nreal:%s\n", hexdump(out, t.clen).c_str(), hexdump(t.cdata, t.clen).c_str());
        }
        else if (memcmp(out, t.cdata, cres)) {
            fprintf(stderr,"cdata mismatch\n");
            fprintf(stderr,"svr:%s\nreal:%s\n", hexdump(out, t.clen).c_str(), hexdump(t.cdata, t.clen).c_str());
        }
    }

    ByteVector v(0x1000);
    for (unsigned i=0 ; i<v.size() ; i++)
        v[i]= i*i+13;
    for (int tp=1 ; tp< 8 ; tp++)
    {
        HiresTimer t;
        for (unsigned i=0 ; i<100 ; i++)
        {
            ByteVector cv(0x1000);
            svr.DoCompressConvert(tp, &cv[0], cv.size(), &v[0], v.size());
        }
        fprintf(stderr, "%d : %6d\n", tp, t.msecelapsed());
    }

    }
    catch(...)
    {
        fprintf(stderr, "EXCEPTION\n");
    }

    return 0;
}

