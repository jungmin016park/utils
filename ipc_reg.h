#ifndef _COMMON_IPC_REG_H_
#define _COMMON_IPC_REG_H_
#include <stdint.h>

#define SHARED_A2D_ADDR        0x24000000
#define SHARED_A2D_SIZE        (26 * 1024)
#define SHARED_D2A_ADDR        (SHARED_A2D_ADDR + SHARED_A2D_SIZE)
#define SHARED_D2A_SIZE        (26 * 1024)
#define SHARED_A2D_VP_ADDR     (SHARED_D2A_ADDR + SHARED_D2A_SIZE)
#define SHARED_A2D_VP_SIZE     (12 * 1024)
#define MAX_DSP_MSG_NUM        0x80


typedef enum {
    IPC_A2D_CMD_INIT            = 0,
    IPC_A2D_CMD_SHUTDOWN        = 1,
    IPC_A2D_CMD_PLAY            = 2,    // wparam :  codec[3:0], resolution[5:4], sample_rate[9:6], channel[11:10]
    IPC_A2D_CMD_STOP            = 3,
    IPC_A2D_CMD_FLUSH           = 4,
    IPC_A2D_CMD_VOLUME_UP       = 5,    // to be deleted
    IPC_A2D_CMD_VOLUME_DOWN     = 6,    // to be deleted
    IPC_A2D_CMD_DATA            = 7,    // wparam : written data size, lparam : start address for written data
    IPC_A2D_CMD_READ_REG        = 8,    // wparam : address
    IPC_A2D_CMD_WRITE_REG       = 9,    // wparam : address, lparam : data
    IPC_A2D_CMD_VP_PLAY         = 10,   // wparam : size
    IPC_A2D_CMD_VOLUME_SET      = 11,   // wparam : volume[7:0], keytone index[15:8]
    IPC_A2D_CMD_RT_PLAY         = 12,   // wparam : ringtone type (0:T1 ringtone, 1:Phone ringtone)
    IPC_A2D_CMD_RT_STOP         = 13,   // wparam : none
    IPC_A2D_CMD_KT_PLAY         = 14,   // wparam : keytone type (TBD)
    IPC_A2D_CMD_NUM             = 15,
} IPC_A2D_CMD_TYPE_T;

typedef enum {
  IPC_CODEC_AAC = 0,
  IPC_CODEC_MP3,
  IPC_CODEC_OPUS,
  IPC_CODEC_SBC,
  IPC_CODEC_MSBC,
  IPC_CODEC_CVSD,
} IPC_A2D_CODEC_T;

typedef enum {
  IPC_RESOLUTION_16 = 0,
  IPC_RESOLUTION_18,
  IPC_RESOLUTION_20,
  IPC_RESOLUTION_24,
  IPC_RESOLUTION_NUM,
} IPC_A2D_RESOLUTION_T;

typedef enum {
  IPC_SAMPLE_FREQ_8K = 0,
  IPC_SAMPLE_FREQ_16K,
  IPC_SAMPLE_FREQ_32K,
  IPC_SAMPLE_FREQ_44_1K,
  IPC_SAMPLE_FREQ_48K,
  IPC_SAMPLE_FREQ_NUM,
} IPC_A2D_SAMPLE_FREQ_T;

typedef enum {
  IPC_CHANNEL_MONO = 0,
  IPC_CHANNEL_STEREO,
  IPC_CHANNEL_BI_LINGUAL,
  IPC_CHANNEL_JOINT_STEREO,
} IPC_A2D_CHANNEL_T;

/* Voice Prompt idx
*/
typedef enum {
  IPC_VP_IDX_NONE_                      = 0,
  IPC_VP_IDX_BT_READY_TO_PAIR           = 1,
  IPC_VP_IDX_BT_PAIRED                  = 2,
  IPC_VP_IDX_BT_CONNECTED               = 3,
  IPC_VP_IDX_BT_OUT_OF_RANGE            = 4,
  IPC_VP_IDX_BT_ANSWER_AND_IGNORE       = 5,
  IPC_VP_IDX_BT_CALL_REJECTED           = 6,
  IPC_VP_IDX_BT_CALL_ANSWERED           = 7,
  IPC_VP_IDX_BT_CALL_ENDED              = 8,
  IPC_VP_IDX_BT_TRANSFER_AUDIO          = 9,
  IPC_VP_IDX_BATT_HIGH                  = 10,
  IPC_VP_IDX_BATT_MEDIUM                = 11,
  IPC_VP_IDX_BATT_LOW                   = 12,
  IPC_VP_IDX_BATT_VERY_LOW_CHARGE       = 13,
  IPC_VP_IDX_VIBRATE_ON                 = 14,
  IPC_VP_IDX_VIBRATE_OFF                = 15,
  IPC_VP_IDX_POWER_TURNED_ON            = 16,
  IPC_VP_IDX_POWER_TURNING_OFF          = 17,
  IPC_VP_IDX_ALERT                      = 18,
  IPC_VP_IDX_NUM                        = 19,
} IPC_VP_IDX_T;

/* Ring tone index
*/
typedef enum {
  IPC_RT_IDX_OWN_RING           = 0,
  IPC_RT_IDX_PEER_RING          = 1,
  IPC_RT_IDX_NUM                = 2,
} IPC_RT_IDX_T;

/* Key tone index
*/
typedef enum {
  IPC_KT_IDX_NONE               = 0,
  IPC_KT_IDX_VOLUME_SET			    = 1,
  IPC_KT_IDX_VOLUME_UP          = 2,  // to be deleted
  IPC_KT_IDX_VOLUME_DOWN        = 3,  // to be deleted
  IPC_KT_IDX_VOLUME_MAX         = 4,
  IPC_KT_IDX_VOLUME_MIN         = 5,
  /*
        TBD
  */
  IPC_KT_IDX_NUM                = 6,
} IPC_KT_IDX_T;



typedef enum {
  IPC_D2A_CMD_READY             = 0,
  IPC_D2A_CMD_INIT              = 1,
  IPC_D2A_CMD_ACK               = 2,    // wparam : enum value of IPC_A2D_CMD_INIT/_SHUTDOWN/_VP_PLAY
  IPC_D2A_CMD_MSG               = 3,    // lparam : address
  IPC_D2A_CMD_DATA              = 4,
  IPC_D2A_CMD_REG               = 5,    // wparam : address, lparam : data
  IPC_D2A_CMD_NUM               = 6,
} IPC_D2A_CMD_TYPE_T;

/**********************************************************

**********************************************************/
typedef union {
  struct {
    uint32_t command                         : 4;
    uint32_t seq_num                         : 8;
    uint32_t reserved                        : 4;
    uint32_t wparam                          : 16;
  }f;
  uint32_t w;
} IPC_A2D_CMD_T;


/**********************************************************

**********************************************************/
typedef union {
  struct {
    uint32_t command                         : 4;
    uint32_t seq_num                         : 8;
    uint32_t reserved                        : 4;
    uint32_t wparam                          : 16;
  }f;
  uint32_t w;
} IPC_D2A_CMD_T;


/**********************************************************
  top
**********************************************************/
typedef struct {
  IPC_A2D_CMD_T a2d_cmd;                    // 0x0
  uint32_t a2d_lparam;                      // 0x4
  uint32_t a2d_wptr;                        // 0x8
  uint32_t a2d_rptr;                        // 0xc

  IPC_D2A_CMD_T d2a_cmd;                    // 0x10
  uint32_t d2a_lparam;                      // 0x14
  uint32_t d2a_wptr;                        // 0x18
  uint32_t d2a_rptr;                        // 0x1c

  uint8_t d2a_msg[MAX_DSP_MSG_NUM];
} IPC_REG_T;

#endif  // _COMMON_REG_IPC_H_
