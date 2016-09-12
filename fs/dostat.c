/*************************************************************************//**
 *****************************************************************************
 * @file   read_write.c
 * @brief  
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
#include "keyboard.h"
#include "proto.h"


/*****************************************************************************
 *                                do_rdwt
 *****************************************************************************/
/**
 * Read/Write file and return byte count read/written.
 *
 * Sector map is not needed to update, since the sectors for the file have been
 * allocated and the bits are set when the file was created.
 * 
 * @return How many bytes have been read/written.
 *****************************************************************************/
PUBLIC int do_stat()
{
   stat* buf = (stat*)fs_msg.BUF;
   int fd = fs_msg.FD;
   struct inode * pin = pcaller->flip[fd]->fd_inode;
   buf->i_mode = pin->i_mode;
   buf->i_size = pin->i_size;
   buf->i_start_sect = pin->i_start_sect;
   buf->i_nr_sects = pin->i_nr_sects;
   return 0;
}
