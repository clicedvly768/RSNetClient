# RSNet Client

![C++](https://img.shields.io/badge/C++-17+-blue.svg)
![CMake](https://img.shields.io/badge/CMake-3.16+-red.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg)

**RSNet Client** — это кроссплатформенный P2P клиент для обмена сообщениями и файлами, написанный на C++17 с использованием Qt6/Qt5.

## 🚀 Возможности
* Децентрализованная архитектура (P2P).
* Обмен текстовыми сообщениями.
* Графический интерфейс (GUI) на Qt.
* Поддержка Linux, Windows, macOS и Android.

## 🛠 Требования
* **CMake** 3.16+
* **C++17** совместимый компилятор (GCC, Clang, MSVC, MinGW).
* **Qt 6** (Linux/macOS) или **Qt 5** (Windows MinGW).

---

## 📦 Сборка и запуск

### 🐧 Linux (Fedora/Ubuntu)
Стандартная сборка для текущей системы.

```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
./rsnet_gui
````

### 🪟 Windows (Cross-compile from Fedora)

Сборка `.exe` файла из-под Linux с использованием MinGW.
*Требуется:* `mingw64-gcc-c++`, `mingw64-qt5-qtbase`, `mingw64-nsis`.

```bash
mkdir build_win && cd build_win
mingw64-cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)

# Сборка переносной папки с DLL (используя скрипт pack_windows.sh)
chmod +x ../pack_windows.sh
../pack_windows.sh

# Сборка инсталлятора (Setup.exe)
makensis installer.nsi
```

### 🍎 macOS

Сборка на macOS (требуется Homebrew).

```bash
brew install qt cmake
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=$(brew --prefix qt)
make -j$(sysctl -n hw.ncpu)

# Создание .dmg пакета
$(brew --prefix qt)/bin/macdeployqt rsnet_gui.app -dmg
```

### 📦 Linux AppImage

Создание переносимого пакета для любого Linux дистрибутива.
*Требуется:* `linuxdeployqt`.

```bash
mkdir build_appimage && cd build_appimage
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
make
make install DESTDIR=AppDir
# Далее запуск linuxdeployqt...
```

-----

## 📂 Структура проекта

  * `src/core` — Логика P2P (чистый C++).
  * `src/gui` — Интерфейс на Qt.
  * `src/network` — Работа с сетью (TCP).
  * `src/main_gui.cpp` — Точка входа.

<!-- end list -->

```
```
