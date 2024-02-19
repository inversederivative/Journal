#include <MainWindow.hpp>
#include <QStyleFactory>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Does not work on Pinephone :(
    //app.setStyle(QStyleFactory::create("Fusion"));

    // Define custom palette colors
    QPalette customPalette;
    customPalette.setColor(QPalette::Window, QColor(30, 30, 30));
    customPalette.setColor(QPalette::WindowText, Qt::white);
    customPalette.setColor(QPalette::Base, QColor(45, 45, 45));
    customPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    customPalette.setColor(QPalette::ToolTipBase, Qt::white);
    customPalette.setColor(QPalette::ToolTipText, Qt::white);
    customPalette.setColor(QPalette::Text, Qt::white);
    customPalette.setColor(QPalette::Button, QColor(0, 120, 212));
    customPalette.setColor(QPalette::ButtonText, Qt::white);
    customPalette.setColor(QPalette::BrightText, Qt::red);
    customPalette.setColor(QPalette::Link, QColor(0, 120, 212));
    customPalette.setColor(QPalette::Highlight, QColor(0, 120, 212));
    customPalette.setColor(QPalette::HighlightedText, Qt::black);

    // Apply custom palette
    app.setPalette(customPalette);

    // Create the main window
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}