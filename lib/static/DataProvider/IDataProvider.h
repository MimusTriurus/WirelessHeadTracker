#ifndef IDATAPROVIDER_H
#define IDATAPROVIDER_H

#include <QByteArray>
#include <QObject>
/**
 * @brief описание интерфейса получения данных
 * от различных источников COM порт, Ethernet и т.д.
 */
class IDataProvider : public QObject {
    Q_OBJECT
protected:
    IDataProvider( QObject *parent = nullptr ) : QObject{ parent } { }
public:
    virtual ~IDataProvider( ){ }
public:
    /**
    * @brief устанавливаем файл настроек
    * @param settingsDest - путь до файла настроек
    * описывает настройки интерфейса получения данных
    * и маску пакета
    */
    virtual void setSettings( const char* settingsDest ) = 0;
    virtual void run( ) = 0;
signals:
    /**
    * @brief событие отправки пакета с данными получателю
    */
    void getData( const QByteArray & );
};

#endif // IDATAPROVIDER_H
