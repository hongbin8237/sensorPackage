#ifndef  grabframe_INC
#define  grabframe_INC
#include "ourerr.hpp"
#include <uEye.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <wchar.h>
#include <termios.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <string.h>

#define UNLOGALL "unlogall\r\n"            /*  */
#define ENABLE_EVENT_IN "EVENTINCONTROL MARK2 ENABLE\r\n"            /*  */
#define LOG_EVENT_IN "LOG MARK2TIMEA ONNEW\r\n"            /*  */
#define ENABLE_TRIGGER "EVENTOUTCONTROL MARK1 ENABLE POSITIVE 10000000 10000000\r\n"            /*  */

#define SEQSIZE 10            /*  */
#define MAXMSG 1024            /*  */
#define CRC32_POLYNOMIAL 0xEDB88320L

int set_interface_attribs(int fd, int speed, int parity);
void initGPS ( char* device, int *spanFD );
void err_ueye ( HIDS cam, int result );
HIDS initCam ();
unsigned long CRC32Value(int i);
unsigned long CalculateBlockCRC32( unsigned long ulCount, unsigned char *ucBuffer );
void extractMsg( char *buf, char **msg, char **crc );
int isValid( char *buf );
int getLatestTimestamp ( int gps, char *buf );
#endif   /* ----- #ifndef grabframe_INC  ----- */
