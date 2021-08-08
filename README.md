# Infineon firmware updater
Infineon TPM firmware updater for Linux

## Build
Requirements: 
* openssl-1.0
```sh
make -C Source/TPMFactoryUpd
```

## HowTo

Thanks to [Krystian Hebel](https://github.com/krystian-hebel) for nice howto

https://blog.3mdeb.com/2019/2019-04-17-roca/

## Usage
```
$ ./Source/TPMFactoryUpd/TPMFactoryUpd
  **********************************************************************
  *    Infineon Technologies AG   TPMFactoryUpd   Ver 01.01.2459.00    *
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
```

## Sources
Main archive:
https://gsdview.appspot.com/chromeos-localmirror/distfiles/infineon-firmware-updater-1.1.2459.0.tar.gz

Patches:
* https://chromium.googlesource.com/chromiumos/overlays/chromiumos-overlay/+/master/chromeos-base/infineon-firmware-updater/files/openssl-1.1.patch

## Credits
The impetus for this repo was partially inspired by:
  https://github.com/iavael/infineon-firmware-updater
