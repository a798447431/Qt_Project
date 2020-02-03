#include "webengineview.h"
#include "webengineviewplugin.h"

#include <QtPlugin>
#include <QWebEngineView>

WebEngineViewPlugin::WebEngineViewPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
//        QWebEngineView * pv = new QWebEngineView();
//        pv->setUrl(QUrl("http://www.baidu.com"));
//        pv->show();
}

void WebEngineViewPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool WebEngineViewPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *WebEngineViewPlugin::createWidget(QWidget *parent)
{
    return new WebEngineView(parent);
}

QString WebEngineViewPlugin::name() const
{
    return QLatin1String("WebEngineView");
}

QString WebEngineViewPlugin::group() const
{
    return QLatin1String("");
}

QIcon WebEngineViewPlugin::icon() const
{
    return QIcon(QLatin1String(":/icon.jpg"));
}

QString WebEngineViewPlugin::toolTip() const
{
    return QLatin1String("");
}

QString WebEngineViewPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool WebEngineViewPlugin::isContainer() const
{
    return false;
}

QString WebEngineViewPlugin::domXml() const
{
    return QLatin1String("<widget class=\"WebEngineView\" name=\"webEngineView\">\n</widget>\n");
}

QString WebEngineViewPlugin::includeFile() const
{
    return QLatin1String("webengineview.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(webengineviewplugin, WebEngineViewPlugin)
#endif // QT_VERSION < 0x050000
