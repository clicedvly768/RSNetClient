rm -rf build_appimage
mkdir build_appimage
cd build_appimage
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
make

mkdir -p AppDir/usr/bin
mkdir -p AppDir/usr/share/applications
mkdir -p AppDir/usr/share/icons/hicolor/256x256/apps/

cp rsnet_gui AppDir/usr/bin/
cp ../rsnet.desktop AppDir/usr/share/applications/
cp ../rsnet.png AppDir/usr/share/icons/hicolor/256x256/apps/

export VERSION=1.0.0
linuxdeployqt AppDir/usr/share/applications/rsnet.desktop -appimage -unsupported-allow-new-glibc