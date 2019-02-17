TEMPLATE = subdirs

SUBDIRS += \
    Converter \
    DataProvider \
    AHRS \
    DataTransmitter
equals(QT_ARCH, arm) {
    message("raspbian")
SUBDIRS += \
    SensorsDataGetter
}
