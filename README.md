COMPRESSUTILS
============

this xs module is an interface to the wince rom compression library.

it needs nkcompr.lib from the platformbuilder to compile.
( take it from either the 'x86/debug' or 'x86/retail' directory. )

DEPENDENCIES
============

This code depends on:

 * [dllloader](https://github.com/nlitsme/dllloader)
 * [itsutils](http://nah6.com/~itsme/cvs-xdadevtools/itsutils/)

BUILD INSTRUCTIONS:
============

0) make sure the vc++ environment is setup correctly
    ( by running vcvars32.bat )
1) unzip cecompr-libs.zip [see 3] in this directory
2) type 'perl Makefile.PL'
3) type 'nmake'
4) optionally type 'nmake test'
5) type 'nmake install'  to install it in your perl\lib directory.
6) copy the .dll's to a convenient spot somewhere in your search PATH

USAGE:

       OS    |            --- perl functions ---         |  library         | library functions
     version | compress             | decompress         |                  |
    ---------+----------------------+--------------------+------------------+------------------------------------
      3.x    | romcompress_v3       | romuncompress_v3   | nkcompr.lib      | CECompress, CEDecompress          
             | rom3compress         | rom3uncompress     | CECompressv3.dll | CECompress, CEDecompress
    ---------+----------------------+--------------------+------------------+------------------------------------
      4.x    | rom4compress         | rom4uncompress     | CECompressv4.dll | CECompress, CEDecompress
             |                      | romuncompress_v4   | nkcompr.lib      | CEDecompressROM
             |                      | rom3uncompressRom  | CECompressv3.dll | CEDecompressROM
    ---------+----------------------+--------------------+------------------+------------------------------------
     5.x XPR | DoCeCompressEncode   | DoCeCompressDecode | cecompress.lib   | CeCompressEncode, CeCompressDecode
             | XPR_DecompressDecode | XPR_CompressEncode | cecompr_nt.dll   | same
    ---------+----------------------+--------------------+------------------+------------------------------------
     5.x LZX | LZX_DecompressDecode | LZX_CompressEncode | cecompr_nt.dll   | same
    ---------+----------------------+--------------------+------------------+------------------------------------

* the XpressXXX functions in cecompress.lib are used by the CeCompressXXX functions

DOWNLOAD

This package can be found on the web, as browsable source on [1],
or as PPM package, on [2].


REFERENCES

[1] http://nah6.com/~itsme/cvs-xdadevtools/perlutils/CompressUtils/
[2] http://www.xs4all.nl/~itsme/projects/perl/ppm 
[3] http://www.xs4all.nl/~itsme/projects/perl/ppm/cecompr-libs.zip


(C) 2005 XDA Developers  itsme@xs4all.nl
