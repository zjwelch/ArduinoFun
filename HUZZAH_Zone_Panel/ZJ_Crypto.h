/*************************************************** 

  Copyright (C) 2017, Zachary J Welch, USA. All rights reserved.

  Written by:   Zachary J Welch
  Contributors: Jeremy Schiefer
  
  This build is for the HUZZAH FEATHER ESP8266 adafruit board (HFE)

////////////////////////////////////////////////////////////////////////////

  These specific functions are related to cryptographic operations
  base on "AES Library for Arduino" written by "MarkT" and based on
  Brian Gladman's AES implementation for byte-oriented processors.

 ---------------------------------------------------------------------------
 Copyright (c) 1998-2008, Brian Gladman, Worcester, UK. All rights reserved.

 LICENSE TERMS

 The redistribution and use of this software (with or without changes)
 is allowed without the payment of fees or royalties provided that:

  1. source code distributions include the above copyright notice, this
     list of conditions and the following disclaimer;

  2. binary distributions include the above copyright notice, this list
     of conditions and the following disclaimer in their documentation;

  3. the name of the copyright holder is not used to endorse products
     built using this software without specific written permission.

 DISCLAIMER

 This software is provided 'as is' with no explicit or implied warranties
 in respect of its properties, including, but not limited to, correctness
 and/or fitness for purpose.
 ---------------------------------------------------------------------------
 Issue 09/09/2006

 This is an AES implementation that uses only 8-bit byte operations on the
 cipher state (there are options to use 32-bit types if available).

 The combination of mix columns and byte substitution used here is based on
 that developed by Karl Malbrain. His contribution is acknowledged.
 

   This version derived by Mark Tillotson 2012-01-23, tidied up, slimmed down
   and tailored to 8-bit microcontroller abilities and Arduino datatypes.

   The s-box and inverse s-box were retained as tables (0.5kB PROGMEM) but all 
   the other transformations are coded to save table space.  Many efficiency 
   improvments to the routines mix_sub_columns() and inv_mix_sub_columns()
   (mainly common sub-expression elimination).

   Only the routines with precalculated subkey schedule are retained (together
   with set_key() - this does however mean each AES object takes 240 bytes of 
   RAM, alas)

   The CBC routines side-effect the iv argument (so that successive calls work
   together correctly).

   All the encryption and decryption routines work with plain == cipher for
   in-place encryption, note.

//////////////////////////////////////////////////////////////////////////////////
 

 ****************** Description ********************

  + completed  - pending  ! acknowledged bug  * self note

  Core Sketchfile to accomplish the following:

  vA0.1.0 - Test/Demo

  -Write wrapper classes for the included licensed code
  -Compile and test a simple cyrpto demo 
  -Replace all sensative data with encrypted data based on
   private keyfile.
  
 ****************************************************/

#include <AES.h>


