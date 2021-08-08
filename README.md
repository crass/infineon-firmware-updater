# Infineon firmware updater
Infineon TPM firmware updater for Linux with Chrome OS patches

The [Readme.txt](Readme.txt) is the official one from Infineon for this
software. See the [user manual](Doc/TPMFactoryUpd_UserManual.pdf) for detailed
instrcutions on using the firmware update tool. Additionally there is official
[source code documentation](Doc/TPMFactoryUpdLinuxDoc).

## Build
Requirements: 
* openssl-1.1
```sh
make -C Source/TPMFactoryUpd
```

## HowTo

Thanks to [Krystian Hebel](https://github.com/krystian-hebel) for nice howto

https://blog.3mdeb.com/2019/2019-04-17-roca/

## Firmware

Firmware can be difficul to find because Infineon does not distribute firmware
updates itself and leaves it up to its customers (eg. HP, Dell, SuperMicro,
etc). Some OEMs package the updates in Windows binaries from which there may be
no known method to extract the firmware. Here is a list of some firmware
packages:

* [SLB 965x](https://www.supermicro.com/wdl/driver/TPM/9655FW%20update%20package_1.4.zip)
* [SLB 966x](https://www.supermicro.com/wdl/driver/TPM/9665FW%20update%20package_1.5.zip)
* [SLB 9670](https://www.supermicro.com/wdl/driver/TPM/AOM-TPM-9670VH_7.62.3126.0.zip)

## Usage
```
$ ./Source/TPMFactoryUpd/TPMFactoryUpd
  **********************************************************************
  *    Infineon Technologies AG   TPMFactoryUpd   Ver 01.01.2529.00    *
  **********************************************************************

Call: TPMFactoryUpd [parameter] [parameter] ...

Parameters:

-? or -help
  Displays a short help page for the operation of TPMFactoryUpd (this screen).
  Cannot be used with any other parameter.

-info
  Displays TPM information related to TPM Firmware Update.
  Cannot be used with -update, -firmware, -config or -tpm12-clearownership parameter.

-update <update-type>
  Updates a TPM with <update-type>.
  Possible values for <update-type> are:
   tpm12-PP - TPM1.2 with Physical Presence or Deferred Physical Presence.
   tpm12-takeownership - TPM1.2 with TPM Ownership taken by TPMFactoryUpd.
   tpm20-emptyplatformauth - TPM2.0 with platformAuth set to Empty Buffer.
   config-file - Updates either a TPM1.2 or TPM2.0 to the firmware version
                 configured in the configuration file. Requires the -config parameter.
  Cannot be used with -info or -tpm12-clearownership parameter.

-firmware <firmware-file>
  Specifies the path to the firmware image to be used for TPM Firmware Update.
  Required if -update parameter is given with values tpm*.
  Cannot be used with -info, -config or -tpm12-clearownership parameter.

-config <config-file>
  Specifies the path to the configuration file to be used for TPM Firmware Update.
  Required if -update parameter is given with value config-file.
  Cannot be used with -info, -firmware or -tpm12-clearownership parameter.

-log [<log-file>]
  Optional parameter. Activates logging for TPMFactoryUpd to the log file
  specified by <log-file>. Default value .\TPMFactoryUpd.log is used if
  <log-file> is not given.
  Note: total path and file name length must not exceed 260 characters

-tpm12-clearownership
  Clears the TPM Ownership taken by TPMFactoryUpd.
  Cannot be used with -info, -update, -firmware or -config parameter.

-access-mode <mode> <path>
  Optional parameter. Sets the mode the tool should use to connect to
  the TPM device.
  Possible values for <mode> are:
  1 - Memory based access (default value, only supported on x86 based systems
      with PCH TPM support)
  3 - Linux TPM driver. The <path> option can be set to define a device path
      (default value: /dev/tpm0)

-dry-run
  Optional parameter. Do everything except actually updating the image.

-ignore-error-on-complete
  Optional parameter. Ignores TPM_FAIL errors from FieldUpgradeComplete.
```

## Sources
Main archive:
https://www.supermicro.com/wdl/driver/TPM/TPM_FU_v1.01.2529.00_ToolsOnly_Linux_SourceCode.tar.gz

Patches:
* https://chromium.googlesource.com/chromiumos/overlays/chromiumos-overlay/+/master/chromeos-base/infineon-firmware-updater/

## Credits
The impetus for this repo was partially inspired by:
  https://github.com/iavael/infineon-firmware-updater
