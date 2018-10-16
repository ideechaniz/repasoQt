#include <QCoreApplication>
#include <midll.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MiDLL mDll;
    mDll.saluda();
    return a.exec();
}

/*
    ldd AplicacionUsaDLL
    linux-vdso.so.1 (0x00007ffc5a9a2000)
    libMiDLL.so.1 => not found <------------------------------
    libQt5Core.so.5 => /home/noise/Qt/5.11.1/gcc_64/lib/libQt5Core.so.5 (0x00007f114be4f000)
    libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f114bc32000)
    libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f114b8b0000)
    libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f114b5ac000)
    libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f114b395000)
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f114aff6000)
    libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007f114addc000)
    libicui18n.so.56 => /home/noise/Qt/5.11.1/gcc_64/lib/libicui18n.so.56 (0x00007f114a943000)
    libicuuc.so.56 => /home/noise/Qt/5.11.1/gcc_64/lib/libicuuc.so.56 (0x00007f114a58b000)
    libicudata.so.56 => /home/noise/Qt/5.11.1/gcc_64/lib/libicudata.so.56 (0x00007f1148ba8000)
    libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007f11489a4000)
    libgthread-2.0.so.0 => /usr/lib/x86_64-linux-gnu/libgthread-2.0.so.0 (0x00007f11487a2000)
    libglib-2.0.so.0 => /lib/x86_64-linux-gnu/libglib-2.0.so.0 (0x00007f114848e000)
    /lib64/ld-linux-x86-64.so.2 (0x00007f114c7ac000)
    libpcre.so.3 => /lib/x86_64-linux-gnu/libpcre.so.3 (0x00007f114821b000)

    // Se la metes despues del :
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./
*/
