#!/bin/sh

LIB_PATH=`pwd`
MRUBYC_SRC=./mrubyc/src

git submodule update -i

rm -rf $MRUBYC_SRC/hal_posix $MRUBYC_SRC/hal_psoc5lp
mv $MRUBYC_SRC/hal_esp32 $MRUBYC_SRC/hal
cd $MRUBYC_SRC
ln -s ../../ext/* ./
cd $LIB_PATH
ln -s $MRUBYC_SRC ./src

