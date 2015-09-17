#!/bin/bash
rm -frv build
make clean && make mrproper
mkdir -pv build/out/modules build/out/dt_image
export ARCH=arm
export CROSS_COMPILE=/kernel/arm-cortex_a9-linux-gnueabihf-linaro_4.9.4-2015.06/bin/arm-cortex_a9-linux-gnueabihf-
export STRIP=/kernel/arm-cortex_a9-linux-gnueabihf-linaro_4.9.4-2015.06/bin/arm-cortex_a9-linux-gnueabihf-strip
export SIZE=/kernel/arm-cortex_a9-linux-gnueabihf-linaro_4.9.4-2015.06/bin/arm-cortex_a9-linux-gnueabihf-size
make test_defconfig
make menuconfig && wait
#make -j12 CONFIG_DEBUG_SECTION_MISMATCH=y
make -j12 CONFIG_NO_ERROR_ON_MISMATCH=y && make -j12 modules
./tools/dtbTool -o build/out/dt_image/boot.img-dt -p ./scripts/dtc/ ./arch/arm/boot/dts/
cp arch/arm/boot/*zImage build/out/boot.img-zImage
find -type f -name *.ko -exec cp {} build/out/modules/ \;
ls -al build/out/modules/
cd build/out/modules/
$STRIP --strip-unneeded *.ko
cd ../../../
ls -al build/out/modules/ build/out/dt_image/ build/out/
echo Done !
