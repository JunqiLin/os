/*************************************************************************//**
 *****************************************************************************
 * @file   write.c
 * @brief  write()
 * @author Forrest Y. Yu
 * @date   2008
 *****************************************************************************
 *****************************************************************************/

#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"

/*****************************************************************************
 *                                write
 *****************************************************************************/
/**
 * Write to a file descriptor.
 * 
 * @param fd     File descriptor.
 * @param buf    Buffer including the bytes to write.
 * @param count  How many bytes to write.
 * 
 * @return  On success, the number of bytes written are returned.
 *          On error, -1 is returned.
 *****************************************************************************/

//PUBLIC int stat(const char *pathname,struct stat* buf)
PUBLIC int stat(int fd,struct stat* buf)
{
       MESSAGE msg;
       msg.type = STAT;
       //msg.PATHNAME = (void*)pathname;
       //msg.NAME_LEN = strlen(pathname);
    msg.FD = fd;

       msg.BUF = buf;
       send_recv(BOTH,TASK_FS,&msg);

       return 0;
}



