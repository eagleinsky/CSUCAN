/*
This file is part of CanFestival, a library implementing CanOpen Stack. 

Copyright (C): Edouard TISSERANT and Francis DUPIN

See COPYING file for copyrights details.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __APPLICFG_NONE__
#define __APPLICFG_NONE__

#include <string.h>
//#include <sys/types.h>

/*  Define the architecture : little_endian or big_endian
 -----------------------------------------------------
 Test :
 UNS32 v = 0x1234ABCD;
 char *data = &v;

 Result for a little_endian architecture :
 data[0] = 0xCD;
 data[1] = 0xAB;
 data[2] = 0x34;
 data[3] = 0x12;

 Result for a big_endian architecture :
 data[0] = 0x12;
 data[1] = 0x34;
 data[2] = 0xAB;
 data[3] = 0xCD;
 */

/* Integers */
#define INTEGER8 signed char
#define INTEGER16 int
#define INTEGER24 
#define INTEGER32 long
#define INTEGER40 
#define INTEGER48 
#define INTEGER56 
#define INTEGER64 

/* Unsigned integers */
#define UNS8   unsigned char
#define UNS16  unsigned int
#define UNS32  unsigned long
#define UNS24   
#define UNS40  
#define UNS48    
#define UNS56  
#define UNS64  

/* Reals */
#define REAL32	float
#define REAL64  double

/* Definition of error and warning macros */
/* -------------------------------------- */
//#define MSG(...)

/* Definition of MSG_ERR */
/* --------------------- */
#define MSG_ERR(num, str, val)

/* Definition of MSG_WAR */
/* --------------------- */
#define MSG_WAR(num, str, val)

typedef void* CAN_HANDLE;

typedef UNS8 CAN_PORT;

#endif
