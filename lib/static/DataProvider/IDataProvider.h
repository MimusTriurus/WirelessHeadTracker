#ifndef IDATAPROVIDER_H
#define IDATAPROVIDER_H

#include <QByteArray>
#include <QObject>
/**
 * @brief описание интерфейса получения данных
 * от различных источников COM порт, Ethernet и т.д.
 */
class IDataProvider {
public:
    virtual ~IDataProvider( ){ }
    /**
    * @brief устанавливаем файл настроек
    * @param settingsDest - путь до файла настроек
    * описывает настройки интерфейса получения данных
    * и маску пакета
    */
    virtual void setSettings( const QString &settingsDest ) = 0;
    virtual bool isDataAvailable( ) const = 0;
    virtual QByteArray data( ) = 0;
    virtual void start( ) = 0;
    virtual void stop( ) = 0;
};

#endif // IDATAPROVIDER_H
