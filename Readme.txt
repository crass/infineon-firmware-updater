--------------------------------------------------------------------------------
                       Infineon TPM Firmware Update Tools
                           (Package with Tools Only)
                               For Use with Linux
                            Infineon Technologies AG

All information in this document is
Copyright 2014 - 2017 Infineon Technologies AG ( www.infineon.com ).
All rights reserved.

Ubuntu is a registered trademark of Canonical Ltd.
Debian is a registered trademark of Software in the Public Interest, Inc.
Raspberry Pi is a registered trademark of Raspberry Pi Foundation
Linux is a registered trademark of Linus Torvalds
--------------------------------------------------------------------------------

Contents:

1. Welcome
1.1 Prerequisites
1.2 Contents of the Package
1.3 Firmware Images

2. Compilation

3. Usage of TPMFactoryUpd

4. If You Have Questions

5. Release Info
5.1 About This Release
5.2 New Features, Fixes, and Improvements
5.3 Known Bugs and Limitations
5.4 Troubleshooting

================================================================================

1. Welcome

Welcome to Infineon TPM Firmware Update Tools.

The package contains the following tool:

- TPMFactoryUpd is a Linux command line application that enables a
  manufacturing/service facility to update the firmware of an Infineon TPM
  (Trusted Platform Module).

For further information about TPM and TCG (Trusted Computing Group) please visit
https://www.trustedcomputinggroup.org


1.1 Prerequisites

- Supported platforms
    * Linux 32-bit and 64-bit on x86 platforms
    * Linux 32-bit and 64-bit on ARM platforms, little endian

- Tested compilers
    * gcc 4.9
    * gcc 5.2

- Tested Linux distributions
    * Ubuntu Linux 15.10 (32-bit, kernel version 4.2) on x86 platforms
    * Ubuntu Linux 15.10 (64-bit, kernel version 4.2) on x86 platforms
    * RASPBIAN JESSIE ARM Linux (32-bit, kernel version 4.11) on Raspberry Pi 2
    * Linaro Debian JESSIE ARM Linux (64-bit, kernel version 4.4 patched) 
      on HiKey Board

- Rights to run the software
      Read/write access to /dev/tpm0
    or
      Root / su

- The package is prepared and intended for FW updates of Infineon Technologies
  TPM products of the following families:
    * SLB 9615 TPM1.2
    * SLB 9645 TPM1.2
    * SLB 965x TPM1.2
    * SLB 9660 TPM1.2
    * SLB 9665 TPM2.0
    * SLB 9670 TPM1.2
    * SLB 9670 TPM2.0

- The package has been tested with the following Infineon Technologies TPM
  products:
    * SLB 9645 TPM1.2
    * SLB 9660 TPM1.2
    * SLB 9665 TPM2.0
    * SLB 9670 TPM1.2
    * SLB 9670 TPM2.0

ATTENTION:

To avoid any interruption of the update process, it is necessary to suspend all
usage of the TPM during the update process.

Do not turn off or shut down the system during the update process.

In case TPM Firmware Update process has been interrupted, please follow the
steps in chapter "Troubleshooting".

It is recommended to always restart the system directly after the TPM Firmware
Update, since certain system hardware and software components might not be aware
of a TPM Firmware Update without a restart (especially in case the TPM family
has been changed with the update).


1.2 Contents of the Package

File name                             Description
=========                             ===========
Doc/TPMFactoryUpdLinuxDoc.tar.gz      Infineon TPM Factory Update Tool Linux
                                      source code documentation

Doc/TPMFactoryUpd_UserManual.pdf      Infineon TPM Factory Update Tool User's
                                      Manual

Kernel/tpm_tis-ignore-self-test-      Linux kernel patch for Linux version
failed.patch                          <= 4.9

Kernel/tpm-interface_ignore-self-     Linux kernel patch for Linux version
test-failed.patch                     >= 4.10

Source/**/*.*                         Linux source code for TPMFactoryUpd

Readme.txt                            This file


1.3 Firmware Images

Firmware images are provided separately. Firmware images are required to update
the firmware to a newer version as well as updating back and forth between
TPM1.2 and TPM2.0 families. The total number of firmware updates allowed by the
TPM is limited (please refer to the corresponding TPM Databook for further
details). Once the limit has been reached, no further TPM Firmware Update will
be possible.
Each TPM firmware image file name indicates the source firmware version (to
which the update can be applied) and the resulting firmware version after the
update. An update must be initiated using the image with source firmware version
matching the current TPM firmware version.
TPM firmware versions 4.xx and 6.xx implement TPM1.2.
TPM firmware versions 5.xx and 7.xx implement TPM2.0.
All firmware images provided with Infineon TPM Firmware Update Tools release
version 01.00.1370.00 or later can be used.


2. Compilation

The ssl library libssl-dev must be installed

$ sudo apt-get update
$ sudo apt-get install libssl-dev

Unzip the package and change to the directory Source/TPMFactoryUpd.

$ cd Source/TPMFactoryUpd

Call "make" to compile TPMFactoryUpd. After calling "make" an executable named
"TPMFactoryUpd" will be created in the current directory.

$ make

Run TPMFactoryUpd with root rights

$ sudo ./TPMFactoryUpd


3. Usage of TPMFactoryUpd

Please refer to the Infineon TPM Factory Update Tool User's Manual.


4. If You Have Questions

If you have any questions or problems, please see chapter "Troubleshooting"
for further instructions or contact your local Infineon representative. 
Further information is available at https://www.infineon.com/tpm


5. Release Info


5.1 About This Release

TPMFactoryUpd Source code release version is 01.01.2529.00.

Please note that TPM Firmware Update between TPM1.2 and TPM2.0 families resets
the TPM to factory defaults. For further details about TPM factory defaults
please refer to TPMFactoryUpd User Manual.


5.2 New Features, Fixes, and Improvements

[N]ew Features, [R]emoved Features, [F]ixes, and [I]mprovements.

Changes since version 01.01.2459.00
- [F] Prevent update interruption in case TPM and or linux kernel returns device
      or resource busy.
- [I] Change source code license
- [I] Resolve scan-build warnings

Changes since version 01.01.2168.00
- [I] Changed default access mode to /dev/tpm0
- [I] Improved command line parsing
- [I] TPMFactoryUpd: Show test result if TPM2.0 is in failure mode.
- [I] TPMFactoryUpd: Improved user interface if TPM1.2 self-test failed


5.3 Known Bugs and Limitations

- The config option only supports the firmware update of the following TPM
  products: SLB 9660 TPM1.2, SLB 9665 TPM2.0, SLB 9670 TPM1.2, SLB 9670 TPM2.0
  All other TPM product families can only be updated without config option.


5.4 Troubleshooting

- In case TPM Firmware Update process has been interrupted:
  1. Reboot the system before retrying the update.
     In this case TPM Firmware Update must be resumed with the exact same
     firmware image that was used when the interruption occurred.
     The number of resume attempts is limited. For the exact number of resume
     attempts supported by a particular TPM model please consult TPM
     documentation or contact your local Infineon representative.
  2. Check if the device /dev/tpm0 is available, if yes, try the update again.
  3. Otherwise call dmesg | grep tpm and check if TPM self test failed.
     If TPM self test failed the following may help:
  3a. On x86 platforms TPMFactoryUpd can be called with commandline option
      "-access-mode 1".
  3b. On ARM platform the kernel needs to be patched, to ignore the result of
      TPM self test. A suitable patch can be found in the folder "Kernel" of
      this package, depending on your kernel version.
      To identify the kernel version call "uname -a" on your platform.
      If the specific patch does not apply, try the other 
      ignore-self-test-failed patch or find the right source code file by taking
      this patch as pattern and change the code manually.
      Run TPMFactoryUpd again and be sure the update completed successfully.

- TPMFactoryUpd will fail to connect to /dev/tpm0 if /dev/tpm0 is in use by
  another process. For example the TPM device could be already used by an
  installed TSS software. In this case find out which process uses /dev/tpm0
  (e.g. "sudo lsof | grep /dev/tpm0") and note the process ID (PID). Stop the
  process and verify that the /dev/tpm0 is no longer in
  use (e.g. "sudo lsof | grep /dev/tpm0").