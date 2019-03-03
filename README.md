# WirelessHeadTracker

Пример работы трекера:

[![1](http://img.youtube.com/vi/9ARzG1uqMuE/0.jpg)](http://www.youtube.com/watch?v=9ARzG1uqMuE&t "")

# Состав проекта:
Статические библиотеки:
  1. Converter - шаблонные функции серелизации\десереализации;
  2. DataProvider - интерфейс поставщика данных и вариант его реализации - получение данных по сети (UDP);
  3. AHRS - содержит статик класс получения угла поворота по данным акселерометра и гироскопа. Для расчета используется фильтр Махоуни;
  4. DataTransmitter - простая реализация udp сокета для отправки данных по сети;
  5. SensorsDataGetter - класс для опроса гироскопа\акселерометра на Raspberry.
  
 Динамические библиотеки:
 1. UnityHeadTracker - инициирует работу поставщика данных (сервера UDP) в отдельном потоке 
 и предоставляет интерфейс(набор методов) для получения угла поворота трекера
 
 Тестовые приложения:
 1. Transmitter - тест передачи кватерниона по сети;
 2. Receiver - тест приема кватерниона по сети;
 3. TestUnityHeadTrackerLib - тест работы динамической библиотеки UnityHeadTracker;
 4. SensehatSensorsGrabber - тест опроса гироскопа и акселерометра на Raspberry 
 с последующей отправкой угла поворота по сети на приложение-приемник.
 
----------------------------------------------
 Hardware:
1. Raspberry Pi 3 (Raspberry Pi Zero W) 
2. Raspberry Pi Sense HAT (MPU 9150, MPU 6050)
3. Raspi UPS HAT

Raspberry Pi 3 + SenseHat
![p_20190303_215525](https://user-images.githubusercontent.com/32236311/53700155-81327300-3e00-11e9-9d79-d71c981df572.jpg)

Raspberry Pi Zero W + MPU6050
![p_20190303_215631](https://user-images.githubusercontent.com/32236311/53700162-868fbd80-3e00-11e9-9afe-20748e71d710.jpg)

Software:
1. Qt 5;
2. RTIMULib2 (включена в проект);
3. Unity 5 (опционально. Библиотеку UnityHeadTracker может использовать любое приложение имеющее возможность использовать библиотеки C++ ).
