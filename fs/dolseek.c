/*************************************************************************//**
 *****************************************************************************
 * @file   fs/open.c
 * The file contains:
 *   - do_open()
 *   - do_close()
 *   - do_lseek()
 *   - create_file()
 * @author Forrest Yu
 * @date   2007
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
#include "keyboard.h"
#include "proto.h"

PUBLIC int do_lseek()
{
       if(off<0){
           if(whence != SEEK_END) return -1;
        }
 
	int fd = fs_msg.FD;
	int off = fs_msg.OFFSET;
	int whence = fs_msg.WHENCE;
	int pos = pcaller->filp[fd]->fd_pos;

       if(whence == SEEK_SET)  pos = off;
       else if(whence == SEEK_CUR) pos = pos+off;
       else if(whence == SEEK_END) pos = pcaller->filp[fd]->fd_inode->i_size + off;
       else return -1;        
	pcaller->filp[fd]->fd_pos = pos;
	return pos;
}


