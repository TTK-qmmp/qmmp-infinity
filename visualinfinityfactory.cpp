#include "visualinfinityfactory.h"
#include "infinitywidget.h"

#include <QMessageBox>

VisualProperties VisualInfinityFactory::properties() const
{
    VisualProperties properties;
    properties.name = tr("Infinity Plugin");
    properties.shortName = "infinity";
    properties.hasAbout = true;
    return properties;
}

Visual *VisualInfinityFactory::create(QWidget *parent)
{
    return new InfinityWidget(parent);
}

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
QDialog *VisualInfinityFactory::createConfigDialog(QWidget *parent)
#else
QDialog *VisualInfinityFactory::createSettings(QWidget *parent)
#endif
{
    Q_UNUSED(parent);
    return nullptr;
}

void VisualInfinityFactory::showAbout(QWidget *parent)
{
    QMessageBox::about(parent, tr("About Infinity Visual Plugin"),
                       tr("Qmmp Infinity Visual Plugin") + "\n" +
                       tr("This plugin adds Infinity visualization") + "\n" +
                       tr("Written by: Greedysky <greedysky@163.com>"));
}

QString VisualInfinityFactory::translation() const
{
    return QString();
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QtPlugin>
Q_EXPORT_PLUGIN2(infinity, VisualInfinityFactory)
#endif
