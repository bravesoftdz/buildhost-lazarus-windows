from suchja/wine
RUN sudo apt-get update && apt-get install wget && \
    cd /tmp && \
    wget "http://sourceforge.net/projects/lazarus/files/Lazarus%20Windows%2032%20bits/Lazarus%201.6.4/lazarus-1.6.4-fpc-3.0.2-win32.exe/download" --no-check-certificate -O lazarus-inst.exe
#RUN exec wine "lazarus-inst.exe" "/silent /nocancel /suppressmsgboxes=no"