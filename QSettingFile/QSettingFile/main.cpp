#include <QCoreApplication>
#include <QDebug>

#include "QSettingFile.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QSettingFile setting;

    if (setting.load("test.ini")) {
        QList<QSettingSection> sections = setting.sections();

        for (auto it = sections.begin(); it != sections.end(); ++it) {
            QSettingSection section = *it;

            qDebug() << "Section Name:" << section.sectionName();

            QList<QPair<QString, QString>> pairs = section.toPairList();
            for (auto it2 = pairs.begin(); it2 != pairs.end(); ++it2) {
                qDebug() << "Pair: " << it2->first << it2->second;
            }

            qDebug() << "";
        }
    }

    return a.exec();
}
