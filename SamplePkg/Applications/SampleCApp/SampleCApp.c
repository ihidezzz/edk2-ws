/** @file
    A simple, basic, application showing how the Sample application could be
    built using the "Standard C Libraries" from StdLib.

    Copyright (c) 2010 - 2011, Intel Corporation. All rights reserved.<BR>
    This program and the accompanying materials
    are licensed and made available under the terms and conditions of the BSD License
    which accompanies this distribution. The full text of the license may be found at
    http://opensource.org/licenses/bsd-license.

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
**/
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/ShellCEntryLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>

#include <stdio.h>
#include <stdlib.h>

/***
  Demonstrates basic workings of the main() function

  Note that the UEFI command line is composed of 16-bit UCS2 wide characters.
  The easiest way to access the command line parameters is to cast Argv as:
      wchar_t **wArgv = (wchar_t **)Argv;

  @param[in]  Argc    Number of argument tokens pointed to by Argv.
  @param[in]  Argv    Array of Argc pointers to command line tokens.

  @retval  0         The application exited normally.
  @retval  Other     An error occurred.
***/
int main (IN int Argc, IN char **Argv)
{
  EFI_TIME curTime;
  printf("Hello, this is Entry of main!\n");
  gBS->Stall(2000);
  gRT->GetTime(&curTime, NULL);
  printf("Gurrent Time: %d-%d-%d %02d:%02d:%02d\n", \
          curTime.Year, curTime.Month, curTime.Day, \
          curTime.Hour, curTime.Minute, curTime.Second);
  gST->ConOut->OutputString(gST->ConOut, L"Test SystemTable...\n\r");
  return 0;
}
