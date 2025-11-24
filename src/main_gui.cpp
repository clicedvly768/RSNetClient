#include <QApplication>
#include "gui/main_window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    app.setStyle("Fusion");

    MainWindow w;
    w.show();

    return app.exec();
}